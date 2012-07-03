#include "csv.h"

/*** Start bluekyulib namespace **********************************************/
namespace bluekyulib
{

/*** Start csv namespace *****************************************************/
namespace csv
{

bool CSV::ReadFile(const std::string &fileName)
{
    return true;
}

bool CSV::WriteFile(const std::string &fileName)
{
    return true;
}

void CSV::InsertLine(const int &index, const row_t &line)
{
    table_t::iterator iter = table.begin();

    for (int i = 0; i < index; i++)
        iter++;

    table.insert(iter, line);
}

void CSV::AppendLine(const row_t &line)
{
    table.push_back(line);
}

void CSV::PopLine(void)
{
    table.pop_back();
}

void CSV::RemoveLine(const int &index)
{
    table_t::iterator iter = table.begin();

    for (int i = 0; i < index; i++)
        iter++;
    
    table.erase(iter);
}

}
/*** End csv namespace *******************************************************/

}
/*** End bluekyulib namespace ************************************************/
