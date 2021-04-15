#include <iostream>
#include <cmath>
#include <locale.h>
#include <Windows.h>

using namespace std;

class Triangle{
private:
    double a, b, c;
public: 
    Triangle() {
        a = 0;
        b = 0;
        c = 0;
    }
    
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
        cout << "Конструктор успешно сработал" << "(" << this << ")" << endl << endl;
    }

    ~Triangle() {
        cout << "Деструктор успешно сработал" << "(" << this << ")" << endl << endl;
    }

    Triangle(const Triangle& other) {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        cout << "Конструктор копирования успешно сработал" << "(" << this << ")" << endl << endl;
    }

    void vvod()
    {
        cout << " a = ? " << endl;
        cin >> a;
        cout << " b = ? " << endl;
        cin >> b;
        cout << " c = ? " << endl;
        cin >> c;
    }

    void square()
    {   
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "Площадь s = " << s << endl << endl;
    }

    void radius()
    {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        double rop = (a * b * c) / (4 * s);
        double rv = s / p;
        cout << "Описанный радиус rop = " << rop << "\nВписанный радиус rv = " << rv << endl << endl;
    }

    void tip()
    {  
        while (a < b || b < c || a < c)
        {
            if (c > b)
            {
                double count = b;
                b = c;
                c = count;
            }
            if (b > a)
            {
                double count = a;
                a = b;
                b = count;
            }
            if (c > a)
            {
                double count = a;
                a = c;
                c = count;
            }
        }
        if ((b *b + c * c) == a * a)
            cout << "Прямоугольный" << endl << endl;
        else if ((b * b + c * c) > a * a)
            cout<< "Остроугольный" <<endl << endl;
        else if ((b * b + c * c) < a * a)
            cout << "Тупоугольный" << endl << endl;

    }

    void print()
    {
        cout << "Сторона a = " << a << "\nСторона b = " << b << "\nСторона c = " << c << endl << endl;
    }

    bool operator == (Triangle& abc)
    {

        return ((a == abc.a) && (b == abc.b) && (c == abc.c))||((a == abc.b) && (b == abc.c) && (c == abc.a))|| ((a == abc.c) && (b == abc.a) && (c == abc.b));
    }
};


int main()
{

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Triangle first;
    int a = 1;
    system("cls");

    while (a) {
        system("cls");
        cout << "\tМеню" << endl;
        cout << "1. Ввод" << endl;
        cout << "2. Площадь" << endl;
        cout << "3. Радиус" << endl;
        cout << "4. Тип триугольника" << endl;
        cout << "5. Вывести значения сторон" << endl;
        cout << "6. Выход" << endl;
        cout << ">";
        cin >> a;
        cout << endl;

        switch (a) {
        case 1: system("cls"); first.vvod(); break;
        case 2: system("cls"); first.square(); system("pause"); break;
        case 3: system("cls"); first.radius(); system("pause"); break;
        case 4: system("cls"); first.tip(); system("pause"); break;
        case 5: system("cls"); first.print(); system("pause"); break;
        case 6: cout << "Работа завершена" << endl; return 0;
        }
    }
    return 0;
}






    

