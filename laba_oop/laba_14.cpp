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
    float distance(point fir, point sec)
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
        cout << "constr" << endl; 

        centre = c;
        set_a(a,c);
        set_b(b,c);
    }

    ~ellipse(){
        cout << "destr" << endl;
    }

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


    //
    double get_square()
    {
        float square = 3.14159 * distance(centre, m_a) * distance(centre, m_b);
        return square;
    }
    //
    /*float get_perimetr()
    {
        float perimetr = 2 * 3.14159 * sqrt((distance(centre, m_a) * distance(c, a) + distance(c, b) * distance(c, b)) / 2);
        return perimetr;
    }*/
};




int main()
{
    point cent = { 0,0 };
    point am = { 5, 3 };
    point bm = { 0, 0 };

    ellipse el1 = {cent, am, bm};

    //cout << el1.get_square() << endl;
    
    cout << el1.get_square() << "sq el" << endl;
    

}
