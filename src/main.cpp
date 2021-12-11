#include <iostream>
#include "Position.h"

int main(int argc, char *argv[]){
//    Position p = Position();
//    p.print_bitboards();
    Position r = Position("2R2k2/p2n1ppp/3p4/8/8/2P2P2/P1P1K1PP/7R b - - 0 19");
    r.print_bitboards();
}