#include <iostream>
using namespace std;

#pragma region задание_1
class Figure {
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure {
protected:
    double a;   //боковые стороны
    double b;   //верхняя и нижняя стороны
    double cornerAB_left_down;  //нижний левый угол между a и b
public:
    Parallelogram(double a, double b, double cornerAB_left_down) {
        this->a = a;
        this->b = b;
        this->cornerAB_left_down = cornerAB_left_down;
    }

    double area() override {
        double h = sqrt(pow(a, 2) - pow(b, 2));   //высота к b
        return b * h;
    }
};
class Circle : public Figure {
    double r;
    const double p = 3.14;
public:
    Circle(double r) {
        this->r = r;
    }
    double area() override {
        return p * pow(r, 2);
    }
};

class Rectanle : public Parallelogram {
public:
    Rectanle(double a, double b, double cornerAB_left_down = 90) : Parallelogram(a, b, cornerAB_left_down) { }

    double area() override {
        double h = a;   //высота к b = a
        return b * h;
    }
};
class Square : public Parallelogram {
public:
    Square(double a, double cornerAB_left_down = 90) : Parallelogram(a, b, cornerAB_left_down) { }

    double area() override {
        b = a;
        double h = a;   //высота к b = a
        return b * h;
    }
};
class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double cornerAB_left_down) : Parallelogram(a, b, cornerAB_left_down) { }

    double area() override {
        b = a;
        double h = sqrt(pow(a, 2) - pow(b, 2));   //высота к b
        return b * h;
    }
};
#pragma endregion

#pragma region задание_2
class Car {
protected:
    string company, model;
    Car(string company, string model) {
        this->company = company;
        this->model = model;
    }
public:
    virtual string info() {
        return company + " " + model;
    }
};

class PassengerCar : public Car {
public:
    PassengerCar(string company, string model) : Car(company, model) {}
};
class Bus : public Car {
public:
    Bus(string company, string model) : Car(company, model) {}
};

class Minivan : public PassengerCar, Bus {
public:
    Minivan(string company, string model) : PassengerCar(company, model), Bus(company, model) {}
};
#pragma endregion

#pragma region задание_3
class Fraction { 
public:
    double cislitel, znamenatel;
    Fraction(double cislitel, double znamenatel) {
        this->cislitel = cislitel;
        this->znamenatel = znamenatel;
    }
    void setCislitel(double value) {
        cislitel = value;
    }
    void setZnamenatel(double value) {
        if (value != 0) {
            znamenatel = value;
        }
        else {
            znamenatel = 1;
        }
    }
    ////перегрузка операторов
    //оператор <<
    friend ostream& operator << (ostream& s, const Fraction& f) {
        s << "cislitel: " << f.cislitel << ", znamenatel: " << f.znamenatel;
        return s;
    }
    //оператор +
    friend Fraction operator + (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c = f0.cislitel*f1.znamenatel + f1.cislitel*f0.znamenatel;
        return Fraction{ c, z };
    }
    //оператор -
    friend Fraction operator - (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c = f0.cislitel * f1.znamenatel - f1.cislitel * f0.znamenatel;
        return Fraction{ c, z };
    }
    //оператор ==
    friend bool operator == (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c0 = f0.cislitel * f1.znamenatel;
        double c1 = f1.cislitel * f0.znamenatel;
        if (c0 == c1) {
            return true;
        }
        else {
            return false;
        }
    }
    //оператор !=
    friend bool operator != (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c0 = f0.cislitel * f1.znamenatel;
        double c1 = f1.cislitel * f0.znamenatel;
        if (c0 != c1) {
            return true;
        }
        else {
            return false;
        }
    }
    //оператор <
    friend bool operator < (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c0 = f0.cislitel * f1.znamenatel;
        double c1 = f1.cislitel * f0.znamenatel;
        if (c0 < c1) {
            return true;
        }
        else {
            return false;
        }
    }
    //оператор >
    friend bool operator > (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c0 = f0.cislitel * f1.znamenatel;
        double c1 = f1.cislitel * f0.znamenatel;
        if (c0 > c1) {
            return true;
        }
        else {
            return false;
        }
    }
    //оператор <=
    friend bool operator <= (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c0 = f0.cislitel * f1.znamenatel;
        double c1 = f1.cislitel * f0.znamenatel;
        if (c0 <= c1) {
            return true;
        }
        else {
            return false;
        }
    }
    //оператор >=
    friend bool operator >= (const Fraction& f0, const Fraction& f1) {
        double z = f0.znamenatel * f1.znamenatel;
        double c0 = f0.cislitel * f1.znamenatel;
        double c1 = f1.cislitel * f0.znamenatel;
        if (c0 >= c1) {
            return true;
        }
        else {
            return false;
        }
    }
};
#pragma endregion

#pragma region задание_4
class Card {
    enum Mast {
        CERVI,
        BUBI,
        KRESTI,
        PIKI
    };
    enum Value {
        VALET = 4,
        QUEEN = 3,
        KING = 2,
        TUZ = 1
    };
    Mast mast;
    Value value;
    bool position;

public:
    Card(Mast mast, Value value, bool position) {
        this->mast = mast;
        this->value = value;
        this->position = position;
    }
    void Flip() {
        if (position) {
            position = false;
        }
        else {
            position = true;
        }
    }
    int GetValue() {
        return value;
    }

};
#pragma endregion


int main()
{
    #pragma region задание_1
    Parallelogram p0{ 12, 4, 40 };
    Circle c0{ 4 };
    Rectanle re0{ 12, 4 };
    Square sq0{ 12 };
    Rhombus rh0{ 6, 30 };

    cout << p0.area() << endl;
    cout << c0.area() << endl;

    Figure* arr[] = { &p0, &c0, &re0, &sq0, &rh0 };

    for (size_t i = 0; i < 5; i++)
    {
        cout << arr[i]->area() << endl;
    }
    cout << endl;
    #pragma endregion

    #pragma region задание_2
    PassengerCar pc0{ "Toyota", "GH74747" };
    Bus b0{ "Toyota", "HK878GJ" };
    Minivan m0{ "Toyota", "HDK7848HJ" };
    //Car* arr[] = { &pc0, &b0, &m0 };
    cout << pc0.info() << endl;
    cout << b0.info() << endl;
    //cout << m0.info() << endl;    //не работает из-за алмаза смерти

    cout << endl;
    #pragma endregion

    #pragma region задание_3
    Fraction f0{5,4}, f1{4,9};
    
    cout << (f0 + f1) << endl;
    cout << (f0 - f1) << endl;
    cout << (f0 == f1) << endl;
    //и т.д.
    #pragma endregion

    #pragma region задание_4

    #pragma endregion



    return 0;
}