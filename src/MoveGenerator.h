//
// Created by jack on 12/12/21.
//
#include <map>
#include "Position.h"
#ifndef CHESSENGINE_MOVEGENERATOR_H
#define CHESSENGINE_MOVEGENERATOR_H


class MoveGenerator {
public:
    Position p;
    MoveGenerator(Position &p);
    int num_legal_moves;
    uint64_t white_pieces;
    uint64_t black_pieces;
    uint64_t all_pieces;
private:
    void generate_bitboards();

};


#endif //CHESSENGINE_MOVEGENERATOR_H
