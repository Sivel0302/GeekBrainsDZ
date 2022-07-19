#include <iostream>
#include <vector>
using namespace std;


#pragma region задание_2
ostream& endll(ostream& _Out)
{
    _Out.put('\n');
    _Out.put('\n');
    _Out.flush();
    return (_Out);
}
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
    bool face_on_table = true;
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
    bool IsFull() {
        if (hand.size() == hand.capacity()) {
            return true;
        }
        else {
            return false;
        }
    }
};
class GenericPlayer {
public:
    unsigned int point;
    string name;
    Hand selfHand;
    virtual bool IsHitting() const { };
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
class Player : public GenericPlayer {
public:
    bool IsHitting() {
        if (selfHand.IsFull()) {
            return false;
        }
        else {
            return true;
        }
    }
    void Win() const {
        cout << name << " is won :)" << endl;
    }
    void Lose() const {
        cout << name << " is loose :(" << endl;
    }
    void Push() const {
        cout << name << " is push :/" << endl;
    }
};
#pragma endregion

#pragma region задание_4
class House : public GenericPlayer {
    bool IsHitting() const {
        if (point > 16) {
            return false;
        }
        else {
            return true;
        }
    }
    void FlipFirstCard() {
        selfHand.hand[0]->face_on_table = false;
    }
};
#pragma endregion

#pragma region задание_5
ostream& operator << (ostream& s, const Card& card)
{
    if (card.face_on_table) {
        s << "XX" << endl;
    }
    else {
        s << "Mast: " << card.mast << ", value: " << card.value << endl;
    }
    return s;
}
ostream& operator << (ostream& s, const GenericPlayer& gp)
{
    s << "Name: " << gp.name << endl;
    //остальное не понял как сделать
    return s;
}
#pragma endregion



int main()
{
    #pragma region задание_1
    int i;
    cout << "Enter value: ";
    cin >> i;
    while (cin.fail()) {
        cout << "Error value!" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> i;
    }
    cout << i << endl;
    #pragma endregion

    #pragma region задание_2
    cout << "test1" << endll;
    cout << "test2" << endl;
    #pragma endregion

    #pragma region задание_5

    #pragma endregion


    return 0;
}