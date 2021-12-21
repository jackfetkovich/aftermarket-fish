//
// Created by jack on 12/20/21.
//

#include "Bitboard.h"

Bitboard::Bitboard(uint64_t board, const std::vector<Direction> &dirs, bool limited, int maxMoves) : board(board),
                                                                                                     dirs(dirs),
                                                                                                     limited(limited),
                                                                                                     max_moves(
                                                                                                             maxMoves) {}
