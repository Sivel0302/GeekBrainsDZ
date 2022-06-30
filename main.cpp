#include <iostream>
#include <cstdint>
using namespace std;

#pragma region задание_1
class Power {
    double a = 1.03, b = 5.28;
public:
    ////методы
    //изменение чисел
    void set_a(double a) {
        this->a = a;
    }
    void set_b(double b) {
        this->b = b;
    }
    //калькуляция
    double calculate() {
        return pow(a, b);
    }
};
#pragma endregion

#pragma region задание_2
class RGBA {
public:
    uint8_t m_red, m_green, m_blue, m_alpha;

    ////конструкторы
    //значения по умолчанию
    RGBA() {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
    }
    // ввод данных
    RGBA(uint8_t m_red, uint8_t m_green, uint8_t m_blue, uint8_t m_alpha) {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
    }

    //методы
    void print() {
        cout << (int)m_red << " " << (int)m_green << " " << (int)m_blue << " " << (int)m_alpha << endl;
    }
};
#pragma endregion

#pragma region задание_3
class Stack {
    int arr[10] = {0}, stackSize = 0;
public:
    void reset() {
        stackSize = 0;
        for (size_t i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
    }
    bool push(int value) {
        if (stackSize == 10) {
            return(false);
        }
        else {
            arr[stackSize] = value;
            stackSize++;
            return(true);
        }
    }
    int pop() {
        if (stackSize > 0) {
            stackSize--;
            return arr[stackSize];
        }
        else {
            cout << "empty!!!" << endl;
            return(0);
        }
    }
    void print() {
        for (size_t i = 0; i < stackSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#pragma endregion

int main()
{

    #pragma region задание_3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    #pragma endregion



    return 0;
}