//
// Created by jack on 12/11/21.
//
#include<string>
#include <map>
#ifndef CHESSENGINE_POSITION_H
#define CHESSENGINE_POSITION_H

class Position {
    std::map<std::string, uint64_t> bitboards;
    bool w_k_eligible;
    bool w_q_eligible;
    bool b_k_eligible;
    bool b_q_eligible;
    bool white_to_move;
    int enpassant;
    int half_moves;
    int moves;
public:
    Position(const std::map<std::string, uint64_t> &bitboards, bool whiteToMove, bool wKEligible, bool wQEligible, bool bKEligible,
             bool bQEligible, int enpassant, int halfMoves, int moves);
    void print_metadata();
    void print_bitboards(bool graphical);
};


#endif //CHESSENGINE_POSITION_H
