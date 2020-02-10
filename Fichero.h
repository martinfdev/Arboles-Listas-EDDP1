/* 
 * File:   Fichero.h
 * Author: pedro
 *
 * Created on February 9, 2020, 6:09 PM
 */

#ifndef FICHERO_H
#define FICHERO_H
#include <fstream>

class Fichero {
public:
    Fichero();
    void abrirFichero(std::string);
    void crearFichero(std::string);
    virtual ~Fichero();
private:

};

#endif /* FICHERO_H */

