/* 
 * File:   LinkedList.h
 * Author: pedro
 *
 * Created on February 8, 2020, 7:11 AM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

class LinkedList {

    class Nodo {
    public:
        Nodo();

        Nodo(std::string nombreArchivo, std::string pathFile) {
            this->nombreArchivo = nombreArchivo;
            this->pathFile = pathFile;
        }

        Nodo * getNext() {
            return next;
        };

        void setNext(Nodo* next) {
            this->next = next;
        };

        std::string getNombreArchivo() {
            return nombreArchivo;
        };

        void setNombreArchivo(std::string nombreArchivo) {
            this->nombreArchivo = nombreArchivo;
        }

        std::string getPathFile() {
            return pathFile;
        }

        void setPathFile(std::string pathFile) {
            this->pathFile = pathFile;
        }

        ~Nodo() {
        }
        
    private:
        std::string nombreArchivo, pathFile;
        Nodo* next;
    };

public:
    LinkedList();
    void insertarListaSimpleInicio(std::string, std::string);
    void insertarListaSimpleFinal(std::string, std::string);
    void insertarListaCircularFinal(std::string, std::string);
    bool vacioListaSimple();
    bool vacioListaCircular();
    void borrar(Nodo*);
    Nodo* buscar();// metodo no implentado no tiene funcionalidad en proyecto
    void showSimple();
    void showCir();
    virtual ~LinkedList();
    
private:
    Nodo* primero;//variable para las lista simple
    Nodo* ultimo;//variable que lleva el puntero para la entrada a la lista circular
};

#endif /* LINKEDLIST_H */


