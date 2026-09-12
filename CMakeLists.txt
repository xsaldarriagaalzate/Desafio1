cmake_minimum_required(VERSION 3.16)

project(Desafio1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Desafio1 main.cpp
    tablero.h
    tablero.cpp
    bits.h
    bits.cpp
    memoria.h
    memoria.cpp
    juego.cpp
    juego.h)

include(GNUInstallDirs)
install(TARGETS Desafio1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
