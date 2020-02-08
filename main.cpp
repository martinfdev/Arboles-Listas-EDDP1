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
#include "LinkedDoubleList.h"

/*
 * 
 */
int main(int argc, char** argv) {
//    Menu* menu =new Menu();
//    menu->menu();   
    LinkedDoubleList* listadoble = new LinkedDoubleList();
    listadoble->insertarPrimero('0');
    listadoble->insertarPrimero('1');
    listadoble->insertarPrimero('2');
    listadoble->insertarPrimero('3');
    listadoble->insertarPrimero('4');
    listadoble->insertarPrimero('5');
    listadoble->insertarPrimero('6');
    listadoble->insertarPrimero('7');
    listadoble->insertarUltimo('8');
    listadoble->insertarUltimo('9');
    listadoble->insertarUltimo('a');
    listadoble->insertarUltimo('b');
    listadoble->insertarUltimo('c');
    listadoble->insertarUltimo('d');
    listadoble->insertarUltimo('f');
    listadoble->insertarUltimo('g');
    listadoble->insertarUltimo('h'); 
    listadoble->show();
    std::cout<<listadoble->buscar('9')->getCaracter()<<"\n";
    listadoble->borrarInicio();
    listadoble->borrarFinal();
    listadoble->borrarParametro('9');
    listadoble->show();
    
    std::cout<<"Fin de la aplicacion :) \n";
    return EXIT_SUCCESS;
}

