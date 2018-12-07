cmake_minimum_required(VERSION 3.12)
project(BasicKnowledge)

set(CMAKE_CXX_STANDARD 11)

add_executable(BasicKnowledge main.cpp lib/coordin.h lib/function.cpp lib/namespace.h classes/stock.h classes/stock.cpp Domain/time.cpp Domain/time.h Domain/Date.cpp Domain/Date.h Domain/String.cpp Domain/String.h)