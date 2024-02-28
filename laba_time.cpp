//Русаков Филипп 3-пми(Б).
//WARNING!!! для корректной работы программы, следует пересохранить
//текстовый файл "timelab.txt" с заменой кодировки на  ANSII 


#include "functions.hpp"

using namespace std;
using namespace rufi;

int main()
{   
    if (get_number("time_lab.txt") == "")
    {
        int num = 1;
        write_file(num, get_date());
    }
    else
    {
        int num = stoi(get_number("time_lab.txt")) + 1;
        write_file(num, get_date());
    }

    return 0;
}
