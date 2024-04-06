
#include <iostream>

using namespace std;

class MyString {
private:
    char* str;
    int length;
public:
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    // Конструктор копирования
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    // Оператор присваивания копированием
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    ~MyString() {
        delete[] str;
    }
    void print() {
        std::cout << str << std::endl;
    }
};
int main() {
    MyString str1("Hello");
    MyString str2 = str1; // Вызов конструктора копирования
    MyString str3("World");
    str2 = str3 = str1; // Вызов оператора присваивания копированием
    str1.print();
    str2.print();
    str3.print();

    return 0;
}

