#ifndef COUPLELIST_H
#define COUPLELIST_H

struct Couple {
    int x,y;

    Couple(int x, int y) : x(x), y(y) {}

    Couple operator+(const Couple& other) const {
        return Couple(x + other.x, y + other.y);
    }
};

struct Node {
    Couple data;
    Node* next;
};

class CoupleList {

    Node* head;

    public:
        CoupleList();

        void add(int x, int y);

        void add(Couple c);

        ~CoupleList();
};

#endif