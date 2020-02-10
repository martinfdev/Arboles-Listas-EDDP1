/* 
 * File:   Fichero.cpp
 * Author: pedro
 * 
 * Created on February 9, 2020, 6:09 PM
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "Fichero.h"


Fichero::Fichero() {
}

void Fichero::abrirFichero(std::string pathArchivo) {
    
}

void Fichero::crearFichero(std::string nombreArchivo) {
   
    std::ofstream file;
    file.open(nombreArchivo+".txt", std::ios::out);
    if (!file.good()) {  
    }
    file.exceptions();
}




Fichero::~Fichero() {
}

