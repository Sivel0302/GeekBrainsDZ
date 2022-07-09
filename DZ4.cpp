#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma region задание_1
class Container {
    int* data;
    int size;
    int capacity;
public:
    int& operator[] (int idx) {
        return data[idx];
    }
    Container() {
        size = 0;
        data = nullptr;
        capacity = 0;
    }
    Container(int _size) {
        size = _size;
        capacity = 0;
        if (_size == 0) {
            Container();
        }
        else if (_size < 0) {
            cout << "Bad things happined" << endl;
            Container();
        }
        else {
            this->data = new int[_size];
        }
    }
    virtual ~Container() {
        delete[] data;
    }
    int get_capacity() {
        return this->capacity;
    }
    int get(int idx) {
        return data[idx];
    }
    void set(int idx, int value) {
        data[idx] = value;
    }
    void push_back(int value) {
        if (capacity < size) {
            data[capacity] = value;
            capacity++;
        }
        else {
            cout << "Container is full!" << endl;
        }
    }
    void pop_back() {
        if (capacity > 0) {
            data[capacity-1] = 0;
            capacity--;
        }
        else {
            cout << "Container is empty" << endl;
        }
    }
    void pop_front() {
        capacity--;
        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = data[i + 1];
        }
    }
    void sort() {
        for (int i = 0; i < capacity; i++) {
            for (int j = 0; j < capacity-1; j++) {
                if (data[j] > data[j + 1]) {
                    int b = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = b;
                }
            }
        }
    }
    void print() {
        for (size_t i = 0; i < capacity; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
#pragma endregion

#pragma region задание_3
enum Mast {
    CERVI,
    BUBNI,
    KRESTI,
    PIKI
};
enum Value {
    SIX = 6,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    VALET = 10,
    QUENN = 10,
    KING = 10,
    TUZ = 11
};
class Card {
public:
    Mast mast;
    Value value;
    Card(Mast _mast, Value _value) {
        mast = _mast;
        value = _value;
    }
};
class Hand {
    vector<Card*> hand;
public:
    void Add(Card* card) {
        hand.push_back(card);
    }
    void Clear() {
        hand.clear();
    }
    int GetValue() {
        int value = 0;
        for (size_t i = 0; i < hand.size(); i++)
        {
            value += hand[i]->value;
        }
        return value;
    }
};
#pragma endregion



int main()
{
    #pragma region задание_1
    Container c{5};

    c.push_back(3);
    c.push_back(5);
    c.push_back(7);
    c.push_back(3);
    c.print();
    c.sort();
    c.print();
    cout << c[1] << endl;
    #pragma endregion

    #pragma region задание_2
    vector<int> arr = { 1,2,3,5,1,4,5,6,3,2,5,5 };

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());       //алгоритм сортировки из библиотеки algorithm

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    #pragma endregion

    #pragma region задание_3
    Card card{ PIKI, TUZ};

    Hand hand;
    hand.Add(&card);
    cout << hand.GetValue() << endl;
    #pragma endregion




    return 0;
}