/* 
 * File:   main.cpp
 * Author: pedro
 *
 * Created on February 6, 2020, 10:46 PM
 */
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "Menu.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Menu* menu =new Menu();
    menu->menu();
    std::cout<<"Fin de la aplicacion :) \n";
    return EXIT_SUCCESS;
}

