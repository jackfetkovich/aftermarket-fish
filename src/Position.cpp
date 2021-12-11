//
// Created by jack on 12/11/21.
//
#include <iostream>
#include <bitset>
#include "Position.h"
#include "FenParser.h"

Position::Position(std::string fen){
    FenParser fp = FenParser();
    bitboards = fp.parse(fen);
}

Position::Position(){
    FenParser fp = FenParser();
    bitboards = fp.parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Position::print_bitboards(){
    for (auto x : this->bitboards) {
        std::cout << x.first << " " << std::bitset<64>(x.second) << std::endl;
    }
}

