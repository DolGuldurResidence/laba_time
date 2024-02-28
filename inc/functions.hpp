#pragma once
#include <string>

using namespace std;

namespace rufi
{
    string get_date();

    int write_file(int num, string date);

    string get_number(const string& filename);
}