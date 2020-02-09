
/* 
 * File:   NodoPila.cpp
 * Author: pedro
 * 
 * Created on February 9, 2020, 10:52 AM
 */

#include "NodoPila.h"

NodoPila::NodoPila() {
}

NodoPila::NodoPila(std::string palabraBuscar, std::string palabraReemplazar, std::string palabra, bool estadoRevertido, int posicion) {
    this->palabraBuscar = palabraBuscar;
    this->palabraReemplazar = palabraReemplazar;
    this->palabra = palabra;
    this->estadoRevertido = estadoRevertido;
    this->posicion = posicion;
    this->siguiente = NULL;
}

void NodoPila::setSiguiente(NodoPila* siguiente) {
    this->siguiente = siguiente;
}

NodoPila* NodoPila::getSiguiente() {
    return siguiente;
}

void NodoPila::setPalabra(std::string palabra) {
    this->palabra = palabra;
}

std::string NodoPila::getPlabra() {
    return palabra;
}

void NodoPila::setPalabraAbuscar(std::string palabraBuscar) {
    this->palabraBuscar = palabraBuscar;
}

std::string NodoPila::getPalabraAbuscar() {
    return palabraBuscar;
}

void NodoPila::setPalabraAreemplazar(std::string palabraReemplazar) {
    this->palabraReemplazar = palabraReemplazar;
}

std::string NodoPila::getPalabraAreemplazar() {
    return palabraReemplazar;
}

void NodoPila::setEstadoRevertido(bool estadoRevertido) {
    this->estadoRevertido = estadoRevertido;
}

bool NodoPila::getEstadoRevertido() {
    return estadoRevertido;
}

void NodoPila::setPosicion(int posicion) {
    this->posicion = posicion;
}

int NodoPila::getPosicion() {
    return posicion;
}

NodoPila::~NodoPila() {
}

