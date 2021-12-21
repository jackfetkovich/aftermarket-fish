//
// Created by jack on 12/20/21.
//

#ifndef CHESSENGINE_BITBOARD_H
#define CHESSENGINE_BITBOARD_H


#include <cstdint>
#include <vector>
#include "Direction.h"

class Bitboard {
public:
    uint64_t board;
    std::vector<Direction> dirs;
    bool limited;
    int max_moves;

    Bitboard(uint64_t board, const std::vector<Direction> &dirs, bool limited, int maxMoves);
};


#endif //CHESSENGINE_BITBOARD_H
