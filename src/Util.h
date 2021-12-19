//
// Created by jack on 12/13/21.
//

#ifndef CHESSENGINE_UTIL_H
#define CHESSENGINE_UTIL_H
#include <string>

class Util {
public:
    int notation_to_square(std::string notation);
    void print_bitboard(uint64_t board, std::string board_name);
};


#endif //CHESSENGINE_UTIL_H
