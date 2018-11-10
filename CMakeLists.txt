cmake_minimum_required(VERSION 3.10)
project(TuringMachineC__)

set(CMAKE_CXX_STANDARD 11)

add_executable(TuringMachineC__ main.cpp output.cpp output.h Cond.h step.cpp step.h checkArgs.cpp checkArgs.h conditions.cpp conditions.h tapes.cpp tapes.h header.h)