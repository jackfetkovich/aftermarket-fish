
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

    // Number of squares that have been accounted for on the board, should reach 64
    int board_pos = 0;

    // Loops through every character of the FEN string
    for (size_t i = 0; i < fen.length(); i++) {

        // Only executed if all squares have not yet been accounted for
        if (board_pos < 64) {

            // If the character is a number, parse it and add to the board position
            // because those squares are empty
            if (isdigit(fen.at(i))) {
                int num = fen.at(i) - '0';
                board_pos += num;

                // Otherwise, figure out what kind of piece (if it is a piece) and add it to the right bitboard
            } else {
                // Used to determine if you should increment the board position
                bool isPiece = true;

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
                        std::cout << "WHITE QUEEN" << std::endl;
                        break;
                    case 'P':
                        this->add_piece(white_pawns, board_pos);
                        break;
                        // If the character is none of these letters, then it is most likely a slash,
                        // and should not be counted for anything
                    default:
                        isPiece = false;
                }
                // If you added a piece to a bitboard, then the board position should be incremented
                if (isPiece) {
                    board_pos++;
                }
            }
        }
    }
    // Create a map of bitboards
    std::map bitboards = std::map<std::string, uint64_t>();

    // Add all the bitboards to the map
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

    // Return the map containing all the bitboards
    return bitboards;
}

// Internal utility method to change the bit from 1 to 0 at the right position on the bitboard
void FenParser::add_piece(uint64_t &bitboard, int pos) {
    bitboard |= 1UL << pos;
}