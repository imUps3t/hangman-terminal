project(hangman)
cmake_minimum_required(VERSION 3.16)

aux_source_directory(. SRC_LIST)
aux_source_directory(./game SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})