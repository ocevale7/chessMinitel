#include "../../include/tools/CoupleList.h"

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

bool CoupleList::isInside(Couple c) {
    Node* temp = head;
    while (temp) {
        if (temp->data.x == c.x && temp->data.y == c.y) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void CoupleList::afficher() {
    Node* tmp = this->head;
    while(tmp != nullptr) {
        cout << "( " << tmp->data.x << ", " << tmp->data.y << ") -> ";
        tmp = tmp->next;
    }
    cout << "nullptr" << endl;
}