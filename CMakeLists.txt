cmake_minimum_required(VERSION 3.14)
project(expressions_differentiator)

set(CMAKE_CXX_STANDARD 17)
include_directories("headers" ".")
set(CMAKE_CXX_FLAGS "-Wall")

execute_process(COMMAND python3
                ${CMAKE_CURRENT_SOURCE_DIR}/derivatives_generator.py
                ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(expressions_differentiator
               main.cpp
               headers/Token.h
               sources/Token.cpp
               headers/ReversePolishNotationGenerator.h
               headers/Tokenizer.h
               sources/ReversePolishNotationGenerator.cpp
               sources/Tokenizer.cpp
               headers/ExpressionNode.hpp
               headers/ExpressionTree.h
               headers/StaticAllocator.hpp
               headers/NodesIdentifierSingleton.h
               sources/ExpressionTree.cpp
               headers/DotFileFromTreeGenerator.h
               sources/DotFileFromTreeGenerator.cpp
               sources/NodesIdentifierSingleton.cpp
        headers/DerivativesDefines.h
               headers/DifferentiateTree.h
               sources/DifferentiateTree.cpp headers/DerivativesUndefs.h)