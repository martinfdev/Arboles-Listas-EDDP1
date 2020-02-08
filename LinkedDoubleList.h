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

        Nodo(char caracter){
            this->caracter = caracter;
        }
        void setSiguiente(Nodo* siguiente){
            this->siguiente =siguiente;
        }

        Nodo* getSiguiente(){return siguiente;}
        
        void setAntrior(Nodo* anterior){
            this->anterior = anterior;
        }
        Nodo* getAnterior(){return anterior;}
        
        void setCaracter(char caracter){
            this->caracter = caracter;
        }
        
        char getCaracter(){return caracter;}
        
    private:
        char caracter;
        Nodo* siguiente;
        Nodo* anterior;
    };

public:
    LinkedDoubleList();
    void insertarPrimero(char);
   // void insertar(char);
    void insertarUltimo(char);
    //void insertarFinal(char);
    void borrarParametro(char);
    void borrarInicio();
    void borrarFinal();
    Nodo* buscar(char);
    void show();
    bool isEmpty();
    virtual ~LinkedDoubleList();
private:
    Nodo* primero;
    Nodo* ultimo;
    void insertarInicio(Nodo*, char);
    void insertarFinal(Nodo*, char);
    void borrarNodo(Nodo*);
};

#endif /* LINKEDDOUBLELIST_H */

