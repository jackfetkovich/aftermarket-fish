
#include <vector>
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

/*
 * Who's turn is it?
 * If white, then delete moves that are blocked by white pieces, and allow black piece captures
 * If black, then delete moves that are blocked by black pieces, and allow white piece captures
 *
 * We know who's turn it is from position object boolean
 *      - Make a vector of with white and black piece sets,
 *        0th index is the color who is moving, 1st index is other color.
 *        Allow captures from the 1st index array, block piece with 0th index pieces
 *
 */
void MoveGenerator::generate_diagonal(int init_pos) {
    std::bitset<64> white_pieces_set = std::bitset<64>(white_pieces);
    std::bitset<64> black_pieces_set = std::bitset<64>(black_pieces);

    std::vector<std::bitset<64>> bitboards_by_color;

    // White to move
    if(p.white_to_move){
        bitboards_by_color.push_back(white_pieces_set);
        bitboards_by_color.push_back(black_pieces_set);

    // Black to move
    } else {
        bitboards_by_color.push_back(black_pieces_set);
        bitboards_by_color.push_back(white_pieces_set);
    }

    int temp_pos;
    // Northeast
    temp_pos = init_pos;
    std::vector<int> ne_squares;
    do {
        temp_pos -=7;
        ne_squares.push_back(temp_pos);
    } while(temp_pos >= 0);

    // Deleting moves that are blocked by same-color pieces
    for(int i = 0; i < ne_squares.size(); i++){
        if(bitboards_by_color.at(0)[ne_squares.at(i)]){
            ne_squares.erase(ne_squares.end()-i, ne_squares.end());
            break;
        }
    }

    /*
     * Capture logic
     * First iteration will not understand taking pieces, just putting your piece on that square
     */
    for(int i = 0; i < ne_squares.size(); i++){
        if(bitboards_by_color.at(1)[ne_squares.at(i)]){
            ne_squares.erase(ne_squares.end()-i+1, ne_squares.end());
            break;
        }
    }
}

