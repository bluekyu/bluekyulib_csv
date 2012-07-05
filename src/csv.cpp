#include "csv.hpp"

/*** Start bluekyulib namespace **********************************************/
namespace bluekyulib
{

/*** Start csv namespace *****************************************************/
namespace csv
{

bool CSV::ReadFile(const std::string& fileName)
{
    return true;
}

bool CSV::WriteFile(const std::string& fileName)
{
    table_t::iterator tableIter;
    row_t::iterator rowIter;
    std::ofstream out;

    out.open(fileName);

    for (tableIter = table.begin(); tableIter != table.end(); tableIter++) {
        row_t &row = *tableIter;
        for (rowIter = row.begin(); rowIter != row.end(); rowIter++)
            out << *rowIter;
    }

    out.close();

    return true;
}

void CSV::InsertRow(const int& index, const row_t& row)
{
    table_t::iterator iter = table.begin();

    for (int i = 0; i < index; i++)
        iter++;

    table.insert(iter, row);
}

void CSV::AppendRow(const row_t& row)
{
    table.push_back(row);
}

void CSV::PopRow(void)
{
    table.pop_back();
}

void CSV::RemoveRow(const int& index)
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
