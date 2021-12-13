//
// Created by jack on 12/11/21.
//
#include <vector>
#include <string>
#include <map>
#include "Position.h"

#ifndef CHESSENGINE_FEN_PARSER_H
#define CHESSENGINE_FEN_PARSER_H


class FenParser {
public:
    Position parse(std::string fen);
private:
    void add_piece(uint64_t &bitboard, int pos);
};


#endif //CHESSENGINE_FEN_PARSER_H
