#include <iostream>
#include <ctime>
#include <cmath>
#include <locale>

using namespace std;

const double pi = 3.14159265;
//static - ключ. слово, которое применяется к методам, переменным и классам, делая их принадлежащими не объектам, а самому типу
//Абстрактный класс - базовый класс, который можно наследовать, но нельзя реализовывать.
class Figure
{
protected:
    int x, y;

private:
    static int totalObjects;
    static int existingObjects;

public:
    Figure()
    {
        x = rand() % 100;
        y = rand() % 100;
        ++totalObjects;
        ++existingObjects;
    }

    Figure(int x_, int y_) : x(x_), y(y_)
    {
        ++totalObjects;
        ++existingObjects;
    }

    virtual void Input() = 0;
    virtual void Output() const = 0;



    virtual ~Figure()
    {
        --existingObjects;
    }

    static int GetTotalObjects()
    {
        return totalObjects;
    }

    static int GetExistingObjects()
    {
        return existingObjects;
    }

};


class Line : public Figure
{
protected:
    int x2, y2;

private:
    static int totalObjects;
    static int existingObjects;

    float Length() const
    {
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    }

public:
    Line() : Figure(), x2(rand() % 100), y2(rand() % 100)
    {
        ++totalObjects;
        ++existingObjects;
    }

    Line(int x_, int y_, int x2_, int y2_) : Figure(x_, y_), x2(x2_), y2(y2_)
    {
        ++totalObjects;
        ++existingObjects;
    }


    void Input() override
    {
        cout << "Введите x и y для начальной точки (x, y): ";
        cin >> x >> y;
        cout << "Введите x и y для конечной точки (x, y): ";
        cin >> x2 >> y2;
    }

    void Output() const override
    {
        cout << "Ваша линия: (" << x << ", " << y << ") - (" << x2 << ", " << y2 << ")\n";
        cout << "Длина линии: " << Length() << endl << endl;
    }

    static int GetTotalObjects()
    {
        return totalObjects;
    }

    static int GetExistingObjects()
    {
        return existingObjects;
    }

    ~Line() override
    {
        --existingObjects;
    }


};

class Rectangle : public Figure
{
protected:
    int width, height;

private:
    static int totalObjects;
    static int existingObjects;

public:
    Rectangle() : Figure(), width(rand() % 50), height(rand() % 50)
    {
        ++totalObjects;
        ++existingObjects;
    }

    Rectangle(int x_, int y_, int width_, int height_) : Figure(x_, y_), width(width_), height(height_)
    {
        ++totalObjects;
        ++existingObjects;
    }

    int Perimeter() const
    {
        return 2 * (width + height);
    }

    int Area() const
    {
        return width * height;
    }

    void Input() override
    {
        cout << "Введите x и y для начальной точки прямоугольника (x, y): ";
        cin >> x >> y;
        cout << "Введите длину и ширину: ";
        cin >> width >> height;
    }

    void Output() const override
    {
        cout << "Начальная точка вашего прямоугольника: (" << x << ", " << y << ")\n";
        cout << "Размер прямоугольника: (" << width << "x" << height << ")\n";
        cout << "Периметр: " << Perimeter() << endl;
        cout << "Площадь: " << Area() << endl << endl;
    }

    static int GetTotalObjects()
    {
        return totalObjects;
    }

    static int GetExistingObjects()
    {
        return existingObjects;
    }

    ~Rectangle() override
    {
        --existingObjects;
    }
};


class Square : public Rectangle
{
private:
    static int totalObjects;
    static int existingObjects;

public:
    Square() : Rectangle()
    {
        width = height = rand() % 50;
        ++totalObjects;
        ++existingObjects;
    }
    Square(int x_, int y_, int side_) : Rectangle(x_, y_, side_, side_)
    {
        ++totalObjects;
        ++existingObjects;
    }

    void Input() override
    {
        cout << "Введите x и y для начальной точки квадрата (x, y): ";
        cin >> x >> y;
        cout << "Введите сторону квадрата: ";
        cin >> width;
        height = width;
    }

    void Output() const override
    {
        cout << "Начальная точка вашего квадрата: (" << x << ", " << y << ")\n";
        cout << "Размер квадрата: (" << width << "x" << height << ")\n";
        cout << "Периметр: " << Perimeter() << endl;
        cout << "Площадь: " << Area() << endl << endl;
    }

    static int GetTotalObjects()
    {
        return totalObjects;
    }

    static int GetExistingObjects()
    {
        return existingObjects;
    }

    ~Square() override
    {
        --existingObjects;
    }
};


class Circle : public Line
{
private:
    static int totalObjects;
    static int existingObjects;

public:
    Circle() : Line()
    {
        ++totalObjects;
        ++existingObjects;
    }

    Circle(int x1_, int y1_, int x2_, int y2_) : Line(x1_, y1_, x2_, y2_)
    {
        ++totalObjects;
        ++existingObjects;
    }

    float Raduis() const
    {
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    }

    double Area() const
    {
        return pi * (2 * pow(Raduis(), 2));
    }

    double LenthOfCircle() const
    {
        return pi * (2 * Raduis());
    }

    void Input() override
    {
        cout << "Введите x и y для начальной точки радиуса (x, y): ";
        cin >> x >> y;
        cout << "Введите x и y для конечной точки радиуса (x2, y2): ";
        cin >> x2 >> y2;
    }

    void Output() const override
    {
        cout << "Наачльная точка вашего круга: (" << x << ", " << y << ") - (" << x2 << ", " << y2 << ")\n";
        cout << "Длина радиуса: " << Raduis() << endl;
        cout << "Длина круга: " << LenthOfCircle() << endl;
        cout << "Площадь: " << Area() << endl << endl;
    }

    static int GetTotalObjects()
    {
        return totalObjects;
    }

    static int GetExistingObjects()
    {
        return existingObjects;
    }

    ~Circle() override
    {
        --existingObjects;
    }
};

class Ellipse : public Figure {
protected:
    double majorAxis;
    double minorAxis;

private:
    static int totalObjects;
    static int existingObjects;

public:
    Ellipse() : Figure()
    {
        majorAxis = rand() % 50 + 1;
        minorAxis = rand() % 50 + 1;
        ++totalObjects;
        ++existingObjects;
    }


    Ellipse(double x_, double y_, double major, double minor) : Figure(x_, y_), majorAxis(major), minorAxis(minor)
    {
        ++totalObjects;
        ++existingObjects;
    }

    double Area() const
    {
        return pi * majorAxis * minorAxis;
    }

    double Perimeter() const
    {
        return pi * (3 * (majorAxis + minorAxis) - sqrt((3 * majorAxis + minorAxis) * (majorAxis + 3 * minorAxis)));
    }

    void Input() override
    {
        cout << "Введите x и y для начальной точки эллипса (x, y): ";
        cin >> x >> y;
        cout << "Введите длину большей оси: ";
        cin >> majorAxis;
        cout << "Введите длину малой оси: ";
        cin >> minorAxis;
    }

    void Output() const override
    {
        cout << "Центр эллипса: (" << x << ", " << y << ")\n";
        cout << "Большая ось: " << majorAxis << "\n";
        cout << "Малая ось: " << minorAxis << "\n";
        cout << "Площадь: " << Area() << "\n";
        cout << "Периметр: " << Perimeter() << endl << endl;
    }

    static int GetTotalObjects()
    {
        return totalObjects;
    }

    static int GetExistingObjects()
    {
        return existingObjects;
    }

    ~Ellipse() override
    {
        --existingObjects;
    }
};
//инициализация статических переменных
int Figure::totalObjects = 0;
int Figure::existingObjects = 0;
int Line::totalObjects = 0;
int Line::existingObjects = 0;
int Square::totalObjects = 0;
int Square::existingObjects = 0;
int Rectangle::totalObjects = 0;
int Rectangle::existingObjects = 0;
int Circle::totalObjects = 0;
int Circle::existingObjects = 0;
int Ellipse::totalObjects = 0;
int Ellipse::existingObjects = 0;


int main(int argc, char const* argv[])
{
	setlocale(LC_ALL, "ru");
    srand(time(nullptr));

    // 1. Создание объектов всех классов кроме класса Фигура с разными конструкторами
    Rectangle rect1;
    Rectangle rect2(10, 20, 30, 40);

    Square square1;
    Square square2(5, 5, 15);

    Line line1;
    Line line2(0, 0, 10, 10);

    Circle circle1;
    Circle circle2(0, 0, 10, 10);

    Ellipse ellipse1;
    Ellipse ellipse2(5, 5, 20, 10);

    // 2. Вывод количества созданных и существующих объектов класса Rectangle
    cout << "Созданные прямоугольники: " << Rectangle::GetTotalObjects() << endl;
    cout << "Существующие прямоугольники: " << Rectangle::GetExistingObjects() << endl;

    // 3. Создание указателя на класс Rectangle
    Rectangle* rectPtr = &rect1;

    // 4. Вывод количества созданных и существующих объектов класса Rectangle
    cout << "Созданные прямоугольники (после создания указателя): " << Rectangle::GetTotalObjects() << endl;
    cout << "Существующие прямоугольники (после создания указателя): " << Rectangle::GetExistingObjects() << endl;

    // 5. Создание динамического объекта класса Rectangle
    Rectangle* rectDynamic = new Rectangle(15, 25, 35, 45);

    // 6. Вывод количества созданных и существующих объектов класса Rectangle
    cout << "Созданные прямоугольники (после создания динамического объекта): " << Rectangle::GetTotalObjects() << endl;
    cout << "Существующие прямоугольники (после создания динамического объекта): " << Rectangle::GetExistingObjects() << endl;

    // 7. Создание динамического массива из объектов Square, Rectangle, Circle, Ellipse
    Figure* figures[4];
    figures[0] = new Square(0, 0, 10);
    figures[1] = new Rectangle(10, 10, 20, 30);
    figures[2] = new Circle(0, 0, 15, 15);
    figures[3] = new Ellipse(5, 5, 25, 10);

    // 8. Вывод количества созданных и существующих объектов класса Rectangle
    cout << "Созданные прямоугольники (после создания динамического массива): " << Rectangle::GetTotalObjects() << endl;
    cout << "Существующие прямоугольники (после создания динамического массива): " << Rectangle::GetExistingObjects() << endl;

    // 9. Вычисление и вывод периметров всех фигур массива
    for (int i = 0; i < 4; ++i)
    {
        figures[i]->Output();  // У всех классов должны быть корректно реализованы Output() и методы для вычисления периметра
    }

    // 10. Удаление динамического массива
    for (int i = 0; i < 4; ++i)
    {
        delete figures[i];
    }

    // 11. Удаление динамического объекта Rectangle
    delete rectDynamic;
  

    // 12. Вывод количества созданных и существующих объектов класса Rectangle
    cout << "Созданные прямоугольники (после удалений): " << Rectangle::GetTotalObjects() << endl;
    cout << "Существующие прямоугольники (после удалений): " << Rectangle::GetExistingObjects() << endl;

    
	rect1.~Rectangle();
    cout << "Созданные прямоугольники (после удалений)-1: " << Rectangle::GetTotalObjects() << endl;
    cout << "Существующие прямоугольники (после удалений)-1: " << Rectangle::GetExistingObjects() << endl;
}
