#ifndef COUPLELIST_H
#define COUPLELIST_H

struct Couple {
    int x,y;
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