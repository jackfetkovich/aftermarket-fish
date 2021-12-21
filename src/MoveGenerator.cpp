
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

/*
 * TODO: Generalize this function so that logic does not have to be rewritten for each movement type
 * Probably should create an enum that is linked to change in square value
 */

/*
 * STEPS FOR MOVE GENERATION
 * 1. Iterate through each bitboard of the player whose turn it is, and repeat the following process for each piece
 *      - In order to make this happen smoothly, the bitboard it is on will have to be somehow linked to the piece's movement type
 * 2. Remove all moves that would land the piece on a square already occupied by its own color
 * 3. Remove all moves after the first in a direction that would occupy an enemy square
 * 4. If there is a capture find a way to remove that piece from the enemy's bitboard and update position eval
 *      - Since we are just adding moves, we will take care of this when generating positions from the vector of move bits
 *
 * * LATER *
 * - Before every move, make sure that you are not putting your own king in check
 * - Be able to check for check and limit moves accordingly
 * - Create logic for checkmate
 * - Create logic for en passant
 * - Castling
 * - Piece promotion
 * - 50 move rule
 * - Threefold repetition
 */


// From stockfish
// A move needs 16 bits to be stored
//
// bit  0- 5: destination square (from 0 to 63)
// bit  6-11: origin square (from 0 to 63)
// bit 12-13: promotion piece type - 2 (from KNIGHT-2 to QUEEN-2)
// bit 14-15: special move flag: promotion (1), en passant (2), castling (3)
// NOTE: EN-PASSANT bit is set only when a pawn can be captured
//


void MoveGenerator::generate_diagonal(int init_pos) {
    std::bitset<64> white_pieces_set = std::bitset<64>(white_pieces);
    std::bitset<64> black_pieces_set = std::bitset<64>(black_pieces);

    std::vector<std::bitset<64>> bitboards_by_color;

    // White to move
    if (p.white_to_move) {
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
        temp_pos -= 7;
        ne_squares.push_back(temp_pos);
    } while (temp_pos >= 0);

    // Deleting moves that are blocked by same-color pieces
    for (int i = 0; i < ne_squares.size(); i++) {
        if (bitboards_by_color.at(0)[ne_squares.at(i)]) {
            ne_squares.erase(ne_squares.end() - i, ne_squares.end());
            break;
        }
    }

    /*
     * Capture logic
     * First iteration will not understand taking pieces, just putting your piece on that square
     */
    for (int i = 0; i < ne_squares.size(); i++) {
        if (bitboards_by_color.at(1)[ne_squares.at(i)]) {
            ne_squares.erase(ne_squares.end() - i + 1, ne_squares.end());
            // Remove the piece from the bitboard
            bitboards_by_color.at(1)[ne_squares.at(i)] = 0;

            // TODO: Add logic for change in piece evaluation
            break;
        }
    }

// TODO: Implement logic that takes the move, updates the bitboard, and makes a new position object to be analyzed
    p.legal_moves.push_back(34958235902345);
//    vector moves .add (move)

}
