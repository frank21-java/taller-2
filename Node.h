#pragma once

class Node{
    public:
    int fila,columna,valor;
    Node* next;
    Node(int fila,int columna,int valor);
    ~Node();
};