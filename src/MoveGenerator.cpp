#include <iostream>
#include <bitset>
#include "MoveGenerator.h"

/*
 * A note on structure:
 *
 * A reference to the position object is passed to the move generator, so that the generator
 * can populate the legal_moves vector of the position object.
 * Logically, it makes sense that a list of legal moves would be stored in the position object
 */

MoveGenerator::MoveGenerator(Position &pos) : p{pos} {
    generate_bitboards();
}

void MoveGenerator::generate_bitboards() {
    white_pieces = p.bitboards["white_pawns"] ^ p.bitboards["white_rooks"] ^ p.bitboards["white_knights"] ^
                   p.bitboards["white_bishops"] ^ p.bitboards["white_queens"] ^ p.bitboards["white_king"];
    black_pieces = p.bitboards["black_pawns"] ^ p.bitboards["black_rooks"] ^ p.bitboards["black_knights"] ^
                   p.bitboards["black_bishops"] ^ p.bitboards["black_queens"] ^ p.bitboards["black_king"];
    all_pieces = white_pieces ^ black_pieces;

    std::string white_pieces_str = std::bitset<64>(white_pieces).to_string();
    std::string black_pieces_str = std::bitset<64>(black_pieces).to_string();
    std::string all_pieces_str = std::bitset<64>(all_pieces).to_string();

    std::cout << white_pieces_str << std::endl;
    std::cout << black_pieces_str << std::endl;
    std::cout << all_pieces_str << std::endl;
}