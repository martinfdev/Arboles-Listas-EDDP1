/* 
 * File:   Stack.cpp
 * Author: pedro
 * 
 * Created on February 9, 2020, 1:25 AM
 */
#include <iostream>
#include "Stack.h"

Stack::Stack() {
    cima = NULL;
}

void Stack::push(NodoPila* nodoP) {
    NodoPila* aux = nodoP;
    aux->setSiguiente(cima);
    cima = aux; 
    sizeStack++;
}

NodoPila* Stack::pop() {
    NodoPila* aux;
    if (!vacio()) {
        aux = cima;
        cima = cima->getSiguiente();
        sizeStack--;
        return aux;
    }else{std::cout<<"Pila Vacia\n";}
}

void Stack::show() {
    if (cima != NULL) {
        NodoPila* aux = cima;
        while (aux!=NULL) {
            std::cout<<aux->getPalabraAbuscar()<<"\t"<<aux->getPalabraAreemplazar()<<"\n";
            aux=aux->getSiguiente();
        }
    }else{
        std::cout<<"Pila vacia\n";
    }
}

int Stack::getSize() {
    return sizeStack;
}

bool Stack::vacio() {
    if (cima==NULL) {
        return true;
    }
    return false;
}



Stack::~Stack() {
}

