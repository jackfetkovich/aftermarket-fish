
#include <iostream>
#include <bitset>
#include "Position.h"
#include "FenParser.h"
#include "Util.h"


//Position::Position() {
//    FenParser fp = FenParser();
//    bitboards = fp.parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
//}

void Position::print_bitboards(bool graphical) {
    Util u = Util();
    if (graphical) {
        for (auto x: this->bitboards) {
            u.print_bitboard(x.second, x.first);
        }
    } else {
        for (auto x: this->bitboards) {
            std::cout << x.first << " " << x.second << std::endl;
        }
    }
}

Position::Position(const std::map<std::string, uint64_t> &bitboards, bool whiteToMove, bool wKEligible, bool wQEligible,
                   bool bKEligible,
                   bool bQEligible, int enpassant, int halfMoves, int moves) : bitboards(bitboards),
                                                                               white_to_move(whiteToMove),
                                                                               w_k_eligible(wKEligible),
                                                                               w_q_eligible(wQEligible),
                                                                               b_k_eligible(bKEligible),
                                                                               b_q_eligible(bQEligible),
                                                                               enpassant(enpassant),
                                                                               half_moves(halfMoves), moves(moves) {}

void Position::print_metadata() {
    std::cout << "White to move: "
    << white_to_move << "\n"
    << "White Castle Kingside: " << w_k_eligible << "\n"
    << "White Castle Queenside: " << w_q_eligible << "\n"
    << "Black Castle Kingside: " << b_k_eligible << "\n"
    << "Black Castle Queenside: " << b_q_eligible << "\n"
    << "Enpassant Square: " << enpassant << "\n"
    << "Half moves: " << std::to_string(half_moves) << "\n"
    << "Moves: " << std::to_string(moves)
    <<std::endl;
}
