cmake_minimum_required(VERSION 3.21)
project(chessengine)

set(CMAKE_CXX_STANDARD 17)

add_executable(chessengine src/main.cpp src/FenParser.cpp src/FenParser.h src/Position.cpp src/Position.h src/MoveGenerator.cpp src/MoveGenerator.h src/Util.cpp src/Util.h src/Bitboard.cpp src/Bitboard.h src/Direction.cpp src/Direction.h)
