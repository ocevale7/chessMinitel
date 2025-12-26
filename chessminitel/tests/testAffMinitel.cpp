#include "../include/pieces/Cavalier.h"

int main(){

    Cavalier* c = new Cavalier(NULL, Couple(0,0), 1);
    c->afficherMinitel();
    
    return 0;
}