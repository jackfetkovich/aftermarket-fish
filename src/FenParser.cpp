//
// Created by jack on 12/11/21.
//

#include "FenParser.h"
#include <iostream>

std::map<std::string, uint64_t> FenParser::parse(std::string fen) {

    uint64_t white_pawns = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t white_rooks = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t white_knights = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t white_bishops = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t white_queens = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t white_king = 0b0000000000000000000000000000000000000000000000000000000000000000;

    uint64_t black_pawns = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t black_rooks = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t black_knights = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t black_bishops = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t black_queens = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t black_king = 0b0000000000000000000000000000000000000000000000000000000000000000;

    int board_pos = 0;
    for (size_t i = 0; i < fen.length(); i++) {
        if (board_pos < 64) {
            if (isdigit(fen.at(i))) {
                int num = fen.at(i) - '0';
                std::cout << "INDEX: " << std::to_string(i) << ", DIGIT:" << std::to_string(num) << ", BOARD_POS:"
                          << std::to_string(board_pos) << std::endl;
                board_pos += num;
            } else {
                bool isPiece = true;
                while (isPiece) {
                    switch (fen.at(i)) {
                        case 'r':
                            this->add_piece(black_rooks, board_pos);
                            break;
                        case 'n':
                            this->add_piece(black_knights, board_pos);
                            break;
                        case 'b':
                            this->add_piece(black_bishops, board_pos);
                            break;
                        case 'k':
                            this->add_piece(black_king, board_pos);
                            break;
                        case 'q':
                            this->add_piece(black_queens, board_pos);
                            break;
                        case 'p':
                            this->add_piece(black_pawns, board_pos);
                            break;
                        case 'R':
                            this->add_piece(white_rooks, board_pos);
                            break;
                        case 'N':
                            this->add_piece(white_knights, board_pos);
                            break;
                        case 'B':
                            this->add_piece(white_bishops, board_pos);
                            break;
                        case 'K':
                            this->add_piece(white_king, board_pos);
                            break;
                        case 'Q':
                            this->add_piece(white_queens, board_pos);
                            break;
                        case 'P':
                            this->add_piece(white_pawns, board_pos);
                            break;
                        default:
                            isPiece = false;
                    }
                    board_pos++;
                    isPiece = false;
                }
            }
        }
    }

    std::map bitboards = std::map<std::string, uint64_t>();
    bitboards.insert({"white_pawns", white_pawns});
    bitboards.insert({"white_rooks", white_rooks});
    bitboards.insert({"white_knights", white_knights});
    bitboards.insert({"white_bishops", white_bishops});
    bitboards.insert({"white_queens", white_queens});
    bitboards.insert({"white_king", white_king});
    bitboards.insert({"black_pawns", black_pawns});
    bitboards.insert({"black_rooks", black_rooks});
    bitboards.insert({"black_knights", black_knights});
    bitboards.insert({"black_bishops", black_bishops});
    bitboards.insert({"black_queens", black_queens});
    bitboards.insert({"black_king", black_king});

    return bitboards;
}

void FenParser::add_piece(uint64_t &bitboard, int pos) {
    bitboard |= 1UL << pos;
}