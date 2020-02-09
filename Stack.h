/* 
 * File:   Stack.h
 * Author: pedro
 *
 * Created on February 9, 2020, 1:25 AM
 */

#ifndef STACK_H
#define STACK_H
#include <string>
#include "NodoPila.h"
class Stack {
        
public:
    Stack();
    void push(NodoPila*);
    NodoPila* pop();
    bool vacio();
    void show();
    int getSize();
    virtual ~Stack();
private:
    int sizeStack;
    NodoPila* cima;
    
};
#endif /* STACK_H */

