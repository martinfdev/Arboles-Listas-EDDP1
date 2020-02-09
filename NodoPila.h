/* 
 * File:   NodoPila.h
 * Author: pedro
 *
 * Created on February 9, 2020, 10:52 AM
 */

#ifndef NODOPILA_H
#define NODOPILA_H
#include <string>
class NodoPila {
public:
        NodoPila();
        NodoPila(std::string palabraBuscar, std::string palabraReemplazar, std::string palabra, bool estadoRevertido, int posicion);
        void setSiguiente(NodoPila * siguiente);
        NodoPila* getSiguiente();
        void setPalabraAbuscar(std::string palabraBuscar);
        void setPalabraAreemplazar(std::string palabraReemplazar);
        void setPalabra(std::string palabra);
        void setEstadoRevertido(bool estadoRevertido);
        void setPosicion(int posicion);
        std::string getPalabraAbuscar();
        std::string getPalabraAreemplazar();
        std::string getPlabra();
        bool getEstadoRevertido();
        int getPosicion();
        virtual ~NodoPila();
        
    private:
        NodoPila* siguiente;
        std::string palabraBuscar, palabraReemplazar, palabra;
        bool estadoRevertido;
        int posicion;
};

#endif /* NODOPILA_H */

