
/* 
 * File:   Init.cpp
 * Author: pedro
 * 
 * Created on February 17, 2020, 8:56 AM
 */

#include "Init.h"
#include "LinkedDoubleList.h"
#include "Ventana.h"

Init::Init() {  
}

void Init::iniciarPrograma(){

    listaText =  new LinkedDoubleList();
    Ventana* menu = new Ventana(listaText);
    menu->menu(); 
}

Init::~Init() {
}

