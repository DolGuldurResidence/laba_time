#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "functions.hpp"

using namespace std;

namespace rufi
{
    //получение и форматирование файла
    string get_date()
    {
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        char formatted[24];
        strftime(formatted, sizeof(formatted), "-%Y-%m-%d-%H-%M-%S", timeinfo);
        string date = formatted;

        return date;
    }

    // запись файла
    int write_file(int num, string date)
    {
        ofstream text_file;
        text_file.open("time_lab.txt", ios::app);

        if (text_file.is_open())
        {
            text_file << num << date << endl;
        }
        else
            cout << "unable open file" << endl;

        return 0;
    }


    //получение числа с последней строки
    string get_number(const string& filename)
    {
        ifstream file(filename);
        string last_line;

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                last_line = line;
            }
            file.close();
        }

        string number = last_line.substr(0, last_line.find("-"));

        return number;
    }
}