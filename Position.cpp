//
// Created by jack on 12/11/21.
//

#include "Position.h"
#include "FenParser.h"

Position::Position(std::string fen){
    FenParser fp = FenParser();
    bitboards = fp.parse(fen);


}

Position::Position(){
    FenParser fp = FenParser();
    bitboards = fp.parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}