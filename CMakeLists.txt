cmake_minimum_required(VERSION 3.21)
project(chessengine)

set(CMAKE_CXX_STANDARD 17)

add_executable(chessengine main.cpp bitboard.cpp bitboard.h)
