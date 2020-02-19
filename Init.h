
/* 
 * File:   Init.h
 * Author: pedro
 *
 * Created on February 17, 2020, 8:55 AM
 */

#ifndef INIT_H
#define INIT_H
#include "LinkedDoubleList.h"

class Init {
public:
    Init();
    void iniciarPrograma();
    virtual ~Init();
private:
    LinkedDoubleList * listaText;
};

#endif /* INIT_H */

