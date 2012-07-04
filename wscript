#!/usr/bin/env python

from sys import platform

top = '.'
out = 'build'

APPNAME = 'csv'
LIBNAME = 'bluekyulib'
VERSION = '0.1.0'

def options(opt):
    opt.load('compiler_cxx')

    # Debugging mode on/off
    opt.add_option('-d', '--debug', dest='debug', default=False, 
            action='store_true', help='Project Debug mode')

def configure(conf):
    conf.check_waf_version(mini='1.6.11')
    conf.load('compiler_cxx')

    # Debug Mode
    if conf.options.debug:
        conf.msg('Build mode', 'debug', 'RED')
        conf.env['PREFIX'] = 'install_debug'        # Install Debug Directory
        conf.env.append_value('DEFINES', ['__DEBUG__'])
    else:
        conf.msg('Build mode', 'release', 'RED')
    conf.msg('Install Prefix', conf.env['PREFIX'], 'RED')

    ### Linux ###
    if platform.startswith('linux'):
        conf.env.append_value('DEFINES', ['__LINUX__'])
        conf.env.append_value('CXXFLAGS', ['-O2', '-Wall', '-std=c++0x'])
        if conf.options.debug:
            conf.env.append_value('CXXFLAGS', ['-g'])

    ### Windows ###
    elif platform.startswith('win32'):
        conf.env.append_value('DEFINES', ['__WINDOWS__'])

    ### Unknown ###
    else:
        pass

    conf.env.append_value('DEFINES', [])
    conf.env.append_value('LIBPATH', [])
    conf.env.append_value('LIB', [])
    conf.env.append_value('STLIBPATH', [])
    conf.env.append_value('STLIB', [])
    conf.env.append_value('INCLUDES', ['.', 'src'])

    # Config Header
    conf.define(APPNAME.upper() + '_NAME', APPNAME)
    conf.define(APPNAME.upper() + '_VERSION', VERSION)
    conf.define(APPNAME.upper() + '_PLATFORM', platform)
    conf.write_config_header('config.h')

def build(bld):
    # Install src/*.h
    includeDir = bld.path.find_dir('src')
    bld.install_files('${PREFIX}/include/' + LIBNAME + '/' + APPNAME, 
        includeDir.ant_glob(['**/*.h']), cwd=includeDir, relative_trick=True)

    # Install config.h
    bld.install_files(
        '${PREFIX}/include/' + LIBNAME + '/' + APPNAME, ['config.h'])

    source = bld.path.ant_glob('src/**/*.cpp')
    bld(
        features = 'cxx cxxstlib',
        source = source,
        target = APPNAME,
        install_path = '${PREFIX}/lib/' + LIBNAME + '/' + APPNAME,
    )
    bld(
        features = 'cxx cxxshlib',
        source = source,
        target = APPNAME,
        install_path = '${PREFIX}/lib/' + LIBNAME + '/' + APPNAME,
    )

from waflib.Build import BuildContext
class TestBuild(BuildContext):
    '''test library'''
    cmd = 'test'

    def excute(self):
        source = self.path.ant_glob('src/**/*.cpp') + ['test/main.cpp'] 
        self(
            features = 'cxx cxxprogram',
            source = source,
            target = 'test',
        )
