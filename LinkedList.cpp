/* 
 * File:   LinkedList.cpp
 * Author: pedro
 * 
 * Created on February 8, 2020, 7:11 AM
 */
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    primero = NULL;
    ultimo = NULL;
}

void LinkedList::insertarListaSimpleInicio(std::string nombreArchivo, std::string pathFile) {
    Nodo* aux = new Nodo(nombreArchivo, pathFile);
    aux->setNext(primero);
    primero = aux;

}

void LinkedList::insertarListaSimpleFinal(std::string nombreArchivo, std::string pathFile) {
    Nodo* aux = new Nodo(nombreArchivo, pathFile);
    if (vacioListaSimple()) {
        primero = ultimo = aux;
    } else {
        ultimo->setNext(aux);
        ultimo = aux;
    }
}

void LinkedList::insertarListaCircularFinal(std::string nombreArchivo, std::string rutaArchivo) {
    Nodo* aux = new Nodo(nombreArchivo, rutaArchivo);
    if (ultimo == NULL) {
        ultimo = aux;
        ultimo->setNext(ultimo);
    } else {
        aux->setNext(ultimo->getNext());
        ultimo->setNext(aux);
        ultimo = aux;
    }
}

void LinkedList::insertarListaSimpleOrdenada(std::string palabraBuscar, std::string palabraReemplazar, bool busqueda) {
    Nodo* nuevo = new Nodo(palabraBuscar, palabraReemplazar);
    if (busqueda) {//ordenar por palabras buscadas
        if (vacioListaSimple() || palabraBuscar.compare(primero->getNombreArchivo()) < 0) {
            nuevo->setNext(primero);
            primero = nuevo;
          //  std::cout<<palabraBuscar<<"\n";
          //  std::cout << palabraBuscar.compare(primero->getNombreArchivo()) << "\t" << palabraBuscar << "\t<\t" << primero->getNombreArchivo() << "\n";
        } else {
            Nodo* aux = primero;
            while (aux->getNext() != NULL && aux->getNext()->getNombreArchivo().compare(palabraBuscar) < 0) {
            //    std::cout<<palabraBuscar<<"\n";
                aux = aux->getNext();
            }
            if (aux->getNext()!=NULL) {
                    nuevo->setNext(aux->getNext());
                }
            aux->setNext(nuevo);
        }

    } else {//ordenar por lapabras reemplazadas

    }

}

void LinkedList::showSimple() {
    Nodo* aux = primero;
    if (primero != NULL) {
        while (aux != NULL) {
            std::cout << aux->getNombreArchivo() << "\t" << aux->getPathFile() << "\n";
            aux = aux->getNext();
        }
    } else {
        std::cout << "Lista Vacia";
    }
}

void LinkedList::showCir() {
    Nodo* aux = ultimo->getNext();
    if (!vacioListaCircular()) {
        do {
            std::cout << aux->getNombreArchivo() << "\t" << aux->getPathFile() << "\n";
            aux = aux->getNext();
        } while (aux != ultimo->getNext());
    } else {
        std::cout << "Lista Vacia";
    }
}

LinkedList::Nodo* LinkedList::buscar() {
    /*No implementado*/
}

bool LinkedList::vacioListaSimple() { //metodo lista simple
    if (primero != NULL) {
        return false;
    } else {
        return true;
    }
}

bool LinkedList::vacioListaCircular() { //metodo para lista circular
    if (ultimo != NULL) {
        return false;
    } else {
        return true;
    }
}

LinkedList::~LinkedList() {
}

