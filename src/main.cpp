#include <iostream>
#include "Position.h"
#include "Util.h"

int main(int argc, char *argv[]){

    Util u = Util();
    std::cout << std::to_string(u.notation_to_square("e3"));

}