/* 
 * File:   LinkedDoubleList.cpp
 * Author: pedro
 * 
 * Created on February 7, 2020, 5:19 PM
 */
#include <iostream>
#include "LinkedDoubleList.h"

LinkedDoubleList::LinkedDoubleList() {
}


void LinkedDoubleList::insertarInicio(Nodo* n, char caracter) {
    Nodo* aux = new Nodo(caracter);
    
    if (primero == NULL) {
        primero = aux;
        ultimo =aux;
      
    }else if (n==primero) {
        aux->setSiguiente(primero);
        primero->setAntrior(aux);
        primero = aux;
      
    }else{
        n->getAnterior()->setSiguiente(aux);
        aux->setAntrior(n->getAnterior());
        n->setAntrior(aux);
        aux->setSiguiente(n);
    }
}

void LinkedDoubleList::insertarFinal(Nodo* n, char caracter) {
     Nodo* aux = new Nodo(caracter);
    if (ultimo==NULL) {
        ultimo=aux;
        primero=aux;
    }else if (ultimo == n) {
        aux->setAntrior(ultimo);
        ultimo->setSiguiente(aux);
        ultimo=aux;
    }else{
        n->getSiguiente()->setAntrior(aux);
        aux->setSiguiente(n->getSiguiente());
        n->setSiguiente(aux);
        aux->setAntrior(n);
    }
}

void LinkedDoubleList::insertarPrimero(char caracter) {
    insertarInicio(primero, caracter);
}

void LinkedDoubleList::insertarUltimo(char caracter) {
    insertarFinal(ultimo, caracter);
}

void LinkedDoubleList::borrarNodo(Nodo* n) {
    
    if (isEmpty()) {
        //list is empty
    }else if (primero==ultimo) {
        primero=NULL;
        ultimo=NULL;
    }else if (primero==n) {
        primero = primero->getSiguiente();
        primero->setAntrior(NULL);
    }else if (ultimo == n) {
        ultimo = ultimo->getAnterior();
        ultimo->setSiguiente(NULL);
    }else{
        n->getAnterior()->setSiguiente(n->getSiguiente());
        n->getSiguiente()->setAntrior(n->getAnterior());
    }
}

void LinkedDoubleList::borrarParametro(char caracter) {
    borrarNodo(buscar(caracter));
}

void LinkedDoubleList::borrarInicio() {
    borrarNodo(primero);
}

void LinkedDoubleList::borrarFinal() {
    borrarNodo(ultimo);
}


LinkedDoubleList::Nodo* LinkedDoubleList::buscar(char caracter) {
    if (isEmpty()) {
        std::cout<<"Lista vacia\n";
    }else{
        Nodo* aux= primero;
        while (aux!= NULL) {
            if (aux->getCaracter()==caracter) {
                return aux;
            }
            aux = aux->getSiguiente();
        }
        std::cout<<"\n";
    }
}

bool LinkedDoubleList::isEmpty() {
    if (primero==NULL) {
        return  true;
    }else if (ultimo ==NULL) {
        return true;
    }
    return false;
}

void LinkedDoubleList::show() {
    if (isEmpty()) {
        std::cout<<"Lista vacia\n";
    }else{
       
        Nodo* aux= primero;
        while (aux!=NULL) {
           std::cout<<aux->getCaracter()<<"->";
           aux = aux->getSiguiente(); 
        }
        std::cout<<"\n";
    }
}




LinkedDoubleList::~LinkedDoubleList() {
}



