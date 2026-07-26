cmake_minimum_required(VERSION 3.20)

project(e3sm_diags_parser LANGUAGES CXX)

add_library(e3sm_diags_parser 
src/lexer.cpp
src/ast.cpp
)

target_compile_features(e3sm_diags_parser PUBLIC cxx_std_20)
