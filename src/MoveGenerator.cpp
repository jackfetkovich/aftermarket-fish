#include <iostream>
#include <bitset>
#include "MoveGenerator.h"
#include "Util.h"

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

    Util u = Util();
    u.print_bitboard(white_pieces, "White Pieces");
    u.print_bitboard(black_pieces, "Black Pieces");
    u.print_bitboard(all_pieces, "All Pieces");
}