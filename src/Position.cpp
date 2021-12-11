
#include <iostream>
#include <bitset>
#include "Position.h"
#include "FenParser.h"

Position::Position(std::string fen) {
    FenParser fp = FenParser();
    bitboards = fp.parse(fen);
}

Position::Position() {
    FenParser fp = FenParser();
    bitboards = fp.parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Position::print_bitboards(bool graphical) {

    if(graphical) {
        for (auto x: this->bitboards) {
            std::string board = std::bitset<64>(x.second).to_string();
            std::cout << "******  " << x.first << "  ******" << std::endl;
            for (int i = board.length() - 1; i >= 0; i--) {
                std::cout << board.at(i);
                if ((i) % 8 == 0) {
                    std::cout << "\n";
                }
            }
            std::cout << std::endl;
        }
    } else {
        for(auto x : this->bitboards){
            std::cout << x.first << " " << x.second << std::endl;
        }
    }
}

