#pragma once
#include "Node.h"
class SparseMatrix {
    private:
        Node* start;
    public:
        SparseMatrix();
        void add(int value, int xPos, int yPos);
        int get(int xPos, int yPos);
        int remover(int xPos, int yPos);
        void printStoredValues();
        int density();
        SparseMatrix* multiply(SparseMatrix* second);
        ~SparseMatrix();

    int obtenerFilas();
    int obtenerColumnas();
    bool existe(int fila,int columna);
    void generarRandom(int cant);
};
