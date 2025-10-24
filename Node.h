#pragma once
struct Node {
    int fila;
    int columna;
    int valor;
    Node* next;

    Node(int f, int c, int v);
};
