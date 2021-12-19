#include <iostream>
#include "Position.h"
#include "FenParser.h"
#include "MoveGenerator.h"
#include "Util.h"

int main(int argc, char *argv[]){

    FenParser fp = FenParser();
    Position p = fp.parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1" );
//    p.print_metadata();
//    p.print_bitboards(true);
    MoveGenerator gen = MoveGenerator(p);



}