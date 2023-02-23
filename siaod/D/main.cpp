#include <iostream>

using namespace std;

typedef struct Item {
    int body = 0;
    Item *next = nullptr;
} Item;

typedef Item *List;

List myList;

void addOne(int body_data) {
    if (myList == nullptr) {
        myList = new Item;
        myList->body = body_data;
    } else {
        Item *p = myList;
        myList = new Item;
        myList->next = p;
        myList->body = body_data;
    }
}

void removeOne() {
    Item *p = myList;
    myList = p->next;
    delete p;
}

int main() {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= 48 && c <= 57) {
            addOne(c - '0');
        } else if (c == '+' || c == '-' || c == '*') {
            int r = myList->body;
            removeOne();
            int l = myList->body;
            removeOne();
            switch (c) {
                case '+':
                    addOne(l + r);
                    break;
                case '-':
                    addOne(l - r);
                    break;
                case '*':
                    addOne(l * r);
                    break;
            }
        }
    }

    cout << myList->body << endl;
    return 0;
}