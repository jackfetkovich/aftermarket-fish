//
// Created by jack on 12/11/21.
//
#include<string>
#include <map>
#ifndef CHESSENGINE_POSITION_H
#define CHESSENGINE_POSITION_H

class Position {
    std::map<std::string, uint64_t> bitboards;
public:
    Position();
    Position(std::string fen);
    void print_bitboards();
};


#endif //CHESSENGINE_POSITION_H
