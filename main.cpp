#include <iostream>
using namespace std;

#pragma region задание_1
unsigned int students = 0;

class Person {
protected:
    string name;
    unsigned int age;
    string sex;
    unsigned int weight;
public:
    Person (string name, unsigned int age, string sex, unsigned int weight) {
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->weight = weight;
        students++;
    }

    void setName(string name) {
        this->name = name;
    }
    void setAge(unsigned int age) {
        this->age = age;
    }
    void setWeight(unsigned int weight) {
        this->weight = weight;
    }
};

class Student : public Person {
    unsigned int study_year;
public:
    Student(string name, unsigned int age, string sex, unsigned int weight, unsigned int study_year) : Person(name, age, sex, weight) {
        this->study_year = study_year;
    }

    void setStudy_year(unsigned int study_year) {
        this->study_year = study_year;
    }
    void nextStudy_year() {
        study_year++;
    }
    void info() {
        cout << name << " " << age << " " << sex << " " << weight << " " << study_year << endl;
    }
};
#pragma endregion

#pragma region задание_2
class Fruit {
protected:
    string name;
    string color;
public:
    Fruit(string color, string name) {
        this->color = color;
        this->name = name;
    }
    Fruit() { }

    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple(string color, string name = "Apple") : Fruit(color, name) { }
    Apple(){
        name = "Apple";
        color = "red";
    }
};
class Banana : public Fruit {
public:
    Banana(string color, string name = "Banana") : Fruit(color, name) { }
    Banana() {
        name = "Banana";
        color = "yellow";
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith(string color, string name = "Granny Smith apple") : Apple(color, name) { }
    GrannySmith() {
        name = "Granny Smith apple";
        color = "green";
    }
};
#pragma endregion


int main()
{

    #pragma region задание_1
    Student s0{ "Nick", 18, "male", 75, 2018 }, s1{ "Dima", 21, "male", 80, 2020 };    

    Student stud[] = { s0, s1 };
    for (size_t i = 0; i < 2; i++)
    {
        stud[i].info();
    }
    cout << "Students: " << students << endl;
    #pragma endregion

    #pragma region задание_2
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    #pragma endregion

    #pragma region задание_3
    /*в игре блэк джек будет класс карта, которая будет иметь поля масть, номер
    от этого класса будут созданы объекты карт, которые будут уникальными как карты в колоде
    будет создана функция которая проверяет комбинации карт
    ещё будет создан родительский массив игроки, которые будут внедряться в массивы с объектами карт
    будет функция увеличения карт на столе, функция кто выиграл, и изменения ставок*/
    #pragma endregion
    return 0;
}