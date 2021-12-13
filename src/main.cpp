#include <iostream>
#include "Position.h"
#include "FenParser.h"
#include "Util.h"

int main(int argc, char *argv[]){

    FenParser fp = FenParser();
    Position p = fp.parse("rnbqkb2/pppp1pp1/5n1r/4p2p/4P2P/5N1R/PPPP1PP1/RNBQKB2 w Qq - 2 55" );
    p.print_metadata();


}