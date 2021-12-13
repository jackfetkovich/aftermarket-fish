//
// Created by jack on 12/13/21.
//

#include "Util.h"
#include <iostream>

int Util::notation_to_square(std::string notation){
    std::string files = "abcdefgh";
    char file = notation.at(0);
    int rank = notation.at(1) - '0';
    int square = 63-(8*rank) + files.find(file) +1;

    return square;
}