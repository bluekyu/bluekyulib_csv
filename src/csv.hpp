#ifndef _CSV_HPP_
#define _CSV_HPP_

#include <vector>
#include <string>
#include <fstream>

namespace bluekyulib { namespace csv {

typedef std::string data_t;
typedef std::vector<data_t> row_t;
typedef std::vector<row_t> table_t;

class CSV
{
public:
    bool ReadFile(const std::string& fileName);
    bool WriteFile(const std::string& fileName);
    void InsertRow(const int& index, const row_t& row);
    void AppendRow(const row_t& row);
    void PopRow(void);
    void RemoveRow(const int& index);

private:
    table_t table;
};

}   // End csv namespace
}   // End bluekyulib namespace

#endif
