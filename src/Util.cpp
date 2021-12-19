//
// Created by jack on 12/13/21.
//

#include "Util.h"
#include <iostream>
#include <bitset>

int Util::notation_to_square(std::string notation){
    std::string files = "abcdefgh";
    char file = notation.at(0);
    int rank = notation.at(1) - '0';
    int square = 63-(8*rank) + files.find(file) +1;

    return square;
}

void Util::print_bitboard(uint64_t board, std::string board_name) {
    std::string board_str = std::bitset<64>(board).to_string();
    std::cout << "******  " << board_name << "  ******" << std::endl;
    for (int i = board_str.length() - 1; i >= 0; i--) {
        if (board_str.at(i) == '0') {
            std::cout << '.';
        } else {
            std::cout << board_str.at(i);
        }

        if ((i) % 8 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}