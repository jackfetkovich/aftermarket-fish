
#include <iostream>
#include <bitset>
#include "Position.h"
#include "FenParser.h"


//Position::Position() {
//    FenParser fp = FenParser();
//    bitboards = fp.parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
//}

void Position::print_bitboards(bool graphical) {

    if (graphical) {
        for (auto x: this->bitboards) {
            std::string board = std::bitset<64>(x.second).to_string();
            std::cout << "******  " << x.first << "  ******" << std::endl;
            for (int i = board.length() - 1; i >= 0; i--) {
                if (board.at(i) == '0') {
                    std::cout << '.';
                } else {
                    std::cout << board.at(i);
                }

                if ((i) % 8 == 0) {
                    std::cout << "\n";
                }
            }
            std::cout << std::endl;
        }
    } else {
        for (auto x: this->bitboards) {
            std::cout << x.first << " " << x.second << std::endl;
        }
    }
}

Position::Position(const std::map<std::string, uint64_t> &bitboards, bool wKEligible, bool wQEligible, bool bKEligible,
                   bool bQEligible, int enpassant, int halfMoves, int moves) : bitboards(bitboards),
                                                                               w_k_eligible(wKEligible),
                                                                               w_q_eligible(wQEligible),
                                                                               b_k_eligible(bKEligible),
                                                                               b_q_eligible(bQEligible),
                                                                               enpassant(enpassant),
                                                                               half_moves(halfMoves), moves(moves) {}


