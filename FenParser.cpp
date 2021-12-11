//
// Created by jack on 12/11/21.
//

#include "FenParser.h"
#include <iostream>

std::map<std::string, int> FenParser::parse(std::string fen) {

    int white_pawns = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int white_rooks = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int white_knights = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int white_bishops = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int white_queens = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int white_king = 0b0000000000000000000000000000000000000000000000000000000000000000;

    int black_pawns = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int black_rooks = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int black_knights = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int black_bishops = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int black_queens = 0b0000000000000000000000000000000000000000000000000000000000000000;
    int black_king = 0b0000000000000000000000000000000000000000000000000000000000000000;

    for(size_t i = 0; i < fen.length(); i++){
        if(i < 64) {
            switch (fen.at(i)) {
                case 'r':
                    this->add_piece(black_rooks, i);
                    break;
                case 'n':
                    this->add_piece(black_knights, i);
                    break;
                case 'b':
                    this->add_piece(black_bishops, i);
                    break;
                case 'k':
                    this->add_piece(black_king, i);
                    break;
                case 'q':
                    this->add_piece(black_queens, i);
                    break;
                case 'p':
                    this->add_piece(black_pawns, i);
                    break;
                case 'R':
                    this->add_piece(white_rooks, i);
                    break;
                case 'N':
                    this->add_piece(white_knights, i);
                    break;
                case 'B':
                    this->add_piece(white_bishops, i);
                    break;
                case 'K':
                    this->add_piece(white_king, i);
                    break;
                case 'Q':
                    this->add_piece(white_queens, i);
                    break;
                case 'P':
                    this->add_piece(white_pawns, i);
                    break;
            }
        }
    }

    
    return std::map<std::string, int>();
}

void FenParser::add_piece(int &bitboard, int pos) {
    bitboard |= 1UL << pos;
}