/* 
 * File:   LinkedDoubleList.h
 * Author: pedro
 *
 * Created on February 7, 2020, 5:19 PM
 */
#ifndef LINKEDDOUBLELIST_H
#define LINKEDDOUBLELIST_H
#include <iostream>

class LinkedDoubleList {

    class Nodo {
    public:

        Nodo(char caracter) {
            this->caracter =caracter;
            siguiente = NULL;
            anterior = NULL;
        }
        void setSiguiente(Nodo* siguiente){
            this->siguiente =siguiente;
        }

        Nodo* getSiguiente(){return siguiente;}
        
        void setAntrioro(Nodo* anterior){
            this->anterior = anterior;
        }
        
        Nodo* getAnterior(){return anterior;}
    private:
        char caracter;
        Nodo* siguiente;
        Nodo* anterior;
    };

public:
    LinkedDoubleList();
    void insertarInicio(Nodo*, char);
    void isertarPrimero(char);
    void insertar(char);
    void insertarFinal(Nodo*, char);
    void insertarUltimo(char);
    void insertarFinal(char);
    virtual ~LinkedDoubleList();
private:
    Nodo* primero;
    Nodo* ultimo;
};

#endif /* LINKEDDOUBLELIST_H */

