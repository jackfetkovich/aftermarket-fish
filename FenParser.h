//
// Created by jack on 12/11/21.
//
#include <vector>
#include <string>
#include <map>

#ifndef CHESSENGINE_FEN_PARSER_H
#define CHESSENGINE_FEN_PARSER_H


class FenParser {
public:
    std::map<std::string, int> parse(std::string fen);
private:
    void add_piece(int &bitboard, int pos);
};


#endif //CHESSENGINE_FEN_PARSER_H
