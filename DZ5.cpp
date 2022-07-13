#include <iostream>
#include <vector>>
using namespace std;

#pragma region задание_1
template<typename T> class Pair1 {
    T a, b;
public:
    Pair1(T _a, T _b) {
        a = _a;
        b = _b;
    }
    T first() {
        return a;
    }
    T second() {
        return b;
    }
};
#pragma endregion

#pragma region задание_2
template<typename T1, typename T2> class Pair {
protected:
    T1 a;
    T2 b;
public:
    Pair(T1 _a, T2 _b) {
        a = _a;
        b = _b;
    }
    Pair() { }
    T1 first() {
        return a;
    }
    T2 second() {
        return b;
    }
};
#pragma endregion

#pragma region задание_3
template<typename T2>
class StringValuePair : public Pair<T2,T2> {
    string a;
    T2 b;
public:
    StringValuePair(string _a, T2 _b) {
        a = _a;
        b = _b;
    }
    string first() {
        return a;
    }
    T2 second() {
        return b;
    }
};
#pragma endregion

#pragma region задание_4
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
public:
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
class GenericPlayer {
    string name;
    Hand selfHand;
public:
    bool IsHitting() {
        //не понял как реализовать
    }
    bool IsBoosted() {
        if (selfHand.hand.capacity() == selfHand.hand.size()) {
            return true;
        }
        else {
            return false;
        }
    }
    void Bust() {
        if (IsBoosted()) {
            cout << name << " is boosted!" << endl;
        }
        else {
            cout << name << " not boosted" << endl;
        }
    }
};
#pragma endregion



int main()
{
    #pragma region задание_1
    Pair1<int> p11(6, 9);
    cout << "Pair: " << p11.first() << " " << p11.second() << endl;

    Pair1<double> p12(3.4, 7.8);
    cout << "Pair: " << p12.first() << " " << p12.second() << endl;
    #pragma endregion

    #pragma region задание_2
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    #pragma endregion

    #pragma region задание_3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    #pragma endregion

    #pragma region задание_4
    
    #pragma endregion


    return 0;
}