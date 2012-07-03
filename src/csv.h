#include <vector>
#include <string>

/*** Start bluekyulib namespace **********************************************/
namespace bluekyulib
{

/*** Start csv namespace *****************************************************/
namespace csv
{
typedef std::string data_t;
typedef std::vector<data_t> row_t;
typedef std::vector<row_t> table_t;

class CSV
{
public:
    bool ReadFile(const std::string &fileName);
    bool WriteFile(const std::string &fileName);
    void InsertLine(const int &index, const row_t &line);
    void AppendLine(const row_t &line);
    void PopLine(void);
    void RemoveLine(const int &index);

private:
    table_t table;
};

}
/*** End csv namespace *******************************************************/

}
/*** End bluekyulib namespace ************************************************/
