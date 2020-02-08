/* 
 * File:   Menu.cpp
 * Author: pedro
 * 
 * Created on February 6, 2020, 10:48 PM
 */
#include <iostream>
#include "Menu.h"

Menu::Menu() {}

void Menu::menu(){
    std::string entrada;
    int option;
    do{
    
        std::cout<<"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA \n";
        std::cout<<"FACULTAD DE INGENIERIA\n";
        std::cout<<"ESTRUCTURA DE DATOS\n";
        std::cout<<"PRACTICA 1\n";
        std::cout<<"PEDRO MARTIN FRANCISCO\n";
        std::cout<<"201700656\n\n\n";
        std::cout<<"MENU\n";
        std::cout<<"1.\tCrear Archivo\n";
        std::cout<<"2.\tAbrir Archivo\n";
        std::cout<<"3.\tArchivos Recientes\n";
        std::cout<<"4.\tSalir\n";
        std::cin>>entrada;
        option = atoi(entrada.c_str());
        
        
    }while(option!=4);

}
Menu::~Menu() {}

