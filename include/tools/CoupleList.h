#ifndef COUPLELIST_H
#define COUPLELIST_H

struct Couple {
    int x,y;

    Couple(int x, int y) : x(x), y(y) {}

    Couple() : x(0), y(0) {}

    Couple operator+(const Couple& other) const {
        return Couple(x + other.x, y + other.y);
    }
};

struct Node {
    Couple data;
    Node* next;
};

class CoupleList {

    public:
        Node* head;

        CoupleList();
        ~CoupleList();

        void add(int x, int y);
        bool isInside(Couple c);
        void add(Couple c);
};

#endif