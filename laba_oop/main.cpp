#include <iostream>
#include <cmath>

using namespace std;


struct point
{
    short x;
    short y;
    short get_x()
    {
        return x;
    }
    short get_y()
    {
        return y;
    }
};

class ellipse
{
    point centre;
    point m_a;
    point m_b;

    //поиск расстояния между двумя точками, необходим для реализации
    //методов из puclic секции
    float dist(point fir, point sec)
    {
        float square_x = pow(fir.get_x() - sec.get_x(), 2);
        float square_y = pow(fir.get_y() - sec.get_y(), 2);
        float dist = pow(square_x + square_y, 0.5);
        return dist;
    }

public:
    //Конструктор эллипса
    ellipse(point c, point a, point b) 
    {
        centre = c;
        set_a(a,c);
        set_b(b,c);
    }

    ~ellipse(){}

    //Поверка на валидность "a"
    void set_a(point a, point c)
    {
        if (c.get_y() != a.get_y())
        {
            cout << "You wrote unavaliable point a" << endl;
        }
        else
            m_a = a;
    }

    //Проверка на валидностть "b"
    void set_b(point b, point c)
    {
        if (c.get_x() != b.get_x())
        {
            cout << "You wrote unavaliable point b" << endl;
        }
        else
            m_b = b; 
    }


    //площадь
    double get_square()
    {
        float square = 3.14159 * dist(centre, m_a) * dist(centre, m_b);
        return square;
    }

    //периметр
    float get_perimetr()
    {
        float perimetr = 2 * 3.14159 * sqrt((dist(centre, m_a) * dist(centre, m_a) + dist(centre, m_b) * dist(centre, m_b)) / 2);
        return perimetr;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    int c_x, c_y, a_x, a_y, b_x, b_y;

    cout << "Введите натуральные х, а затем y для центра" << endl;
    cin >> c_x; cin >> c_y; 
    cout << "Введите натуральные х, а затем y для 'A' полуоси" << endl;
    cin >> a_x; cin >> a_y;
    cout << "Введите натуральные х, а затем y для 'B' полуоси" << endl;
    cin >> b_x; cin >> b_y;

    point cent = { c_x,c_y };
    point a = { a_x, a_y };
    point b = { b_x, b_y };

    ellipse e = {cent, a, b};
    
    cout << e.get_square() << " square of ellipse" << endl;
    cout << e.get_perimetr() << " perimetre of ellipse" << endl;
    
}
