#include <iostream>
#include "Position.h"
#include "FenParser.h"
#include "Util.h"

int main(int argc, char *argv[]){

    FenParser fp = FenParser();
    Position p = fp.parse("3qk1nr/pr1bp1bp/B5p1/3pPQ2/1Pp5/2P1KN2/P2P1PPP/RNB3R1 b k b3 0 13");
    p.print_metadata();


}