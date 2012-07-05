#include <iostream>
#include "csv.hpp"

using namespace bluekyulib::csv;

int main(void)
{
    CSV csv;

    csv.WriteFile("test.csv");

    return 0;
}
