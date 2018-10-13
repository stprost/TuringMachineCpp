cmake_minimum_required(VERSION 3.10)
project(TuringMachineC__)

set(CMAKE_CXX_STANDARD 11)

add_executable(TuringMachineC__ main.cpp output.cpp output.h Cond.h header.h in.cpp in.h step.cpp step.h)