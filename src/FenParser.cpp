
#include "FenParser.h"
#include "Util.h"
#include <iostream>

Position FenParser::parse(std::string fen) {
    Util u = Util();
    bool white_to_move;
    bool w_k_eligible = false;
    bool w_q_eligible = false;
    bool b_k_eligible = false;
    bool b_q_eligible = false;
    int enpassant;
    bool enpassant_passed = false;
    int half_moves;
    bool half_moves_passed = false;
    int moves;
    bool moves_passed = false;

    int post_board_space_count = 0;

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

    uint64_t white_pieces = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t black_pieces = 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t all_pieces = 0b0000000000000000000000000000000000000000000000000000000000000000;

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
        } else {
            if(fen.at(i) == ' '){
                post_board_space_count++;
            } else {
                if(post_board_space_count == 1 && isalpha(fen.at(i))) white_to_move = fen.at(i) == 'w'? true : false;
                if(post_board_space_count == 2){
                    if(fen.at(i) == '-'){
                        w_k_eligible = false;
                        w_q_eligible = false;
                        b_k_eligible = false;
                        b_q_eligible = false;
                    } else {
                        switch(fen.at(i)){
                            case 'K':
                                w_k_eligible = true;
                                break;
                            case 'Q':
                                w_q_eligible = true;
                                break;
                            case 'k':
                                b_k_eligible = true;
                                break;
                            case 'q':
                                b_q_eligible = true;
                                break;
                        }

                    }
                }
                if(post_board_space_count == 3){
                    if(fen.at(i) == '-'){
                        enpassant = -1;
                    } else {
                        if(!enpassant_passed){
                            enpassant = u.notation_to_square(fen.substr(i, 2));
                            enpassant_passed = true;
                        }
                    }
                }
                if(post_board_space_count == 4 && !half_moves_passed){
                    size_t x = i;
                    int num_digits = 0;
                    while(isdigit(fen.at(x))){
                        num_digits++;
                        x++;
                    }
                    half_moves = std::stoi(fen.substr(i, num_digits));
                    half_moves_passed = true;
                }
                // TODO: Figure out why this doesn't work
                if(post_board_space_count == 5 && !moves_passed){
                    size_t x = i;
                    int num_digits = 0;
                    while(x <= fen.length()){
                        if(isdigit(fen.at(x))){
                            num_digits++;
                            x++;
                        }
                    }
//                    while(isdigit(fen.at(x))){
//                        num_digits++;
//                        x++;
//                    }
                    moves = std::stoi(fen.substr(i, num_digits));
                    moves_passed = true;
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
//    return bitboards;

    return Position(bitboards, white_to_move, w_k_eligible, w_q_eligible, b_k_eligible, b_q_eligible, enpassant, half_moves, 5);
}

// Internal utility method to change the bit from 1 to 0 at the right position on the bitboard
void FenParser::add_piece(uint64_t &bitboard, int pos) {
    bitboard |= 1UL << pos;
}


