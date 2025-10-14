#include "Node.h"
#include <iostream>

Node::Node(int f, int c, int v){
    fila = f;
    columna = c;
    valor = v;
    next = nullptr;
}
Node::~Node(){}