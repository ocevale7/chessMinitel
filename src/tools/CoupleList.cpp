#include "../../include/tools/CoupleList.h"
#include <ostream>

CoupleList::CoupleList() {
    head = nullptr;
}


CoupleList::~CoupleList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void CoupleList::add(int x, int y) {
    Node* newNode = new Node{{x, y}, head};
    head = newNode;
}

void CoupleList::add(Couple c) {
    Node* newNode = new Node{c, head};
    head = newNode;
}

/*
std::ostream & operator<<(std::ostream &out, const Couple* c) {
    out<<"("<<c->x<<", "<<c->y<<")";
    return out;
}
*/