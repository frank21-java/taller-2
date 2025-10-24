#include "SparseMatrix.h"
#include <iostream>
#include <cstdlib>
using namespace std;

SparseMatrix::SparseMatrix(){
    start=nullptr;
}
SparseMatrix::~SparseMatrix(){
    Node* actual = start;
    while (actual != nullptr) {
        Node* temp = actual;
        actual = actual->next;
        delete temp;
    }
}

void SparseMatrix::add(int fila,int columna,int valor){
    if(valor==0){return;}
    Node* nuevo = new Node(fila, columna, valor);

    if (start == nullptr || fila < start->fila ||(fila == start->fila && columna < start->columna)) {
        nuevo->next = start;
        start = nuevo;
        return;
    }
    
    Node* actual = start;
    while (actual->next != nullptr && (actual->next->fila < fila || (actual->next->fila == fila && actual->next->columna < columna))) {
        actual = actual->next;
    }
    nuevo->next = actual->next;
    actual->next = nuevo;
}

int SparseMatrix::get(int fila,int columna){
    Node* actual = start;
    while (actual != nullptr) {
        if (actual->fila == fila && actual->columna == columna) {
            return actual->valor;
        }
        actual = actual->next;
    }
    return 0;
}

void SparseMatrix::printStoredValues(){
    Node* actual = start;
    while (actual != nullptr) {
        cout << "(" << (actual->fila + 1) << ", " << (actual->columna + 1) << ") --> " << actual->valor << endl;
        actual = actual->next;
    }
}

int SparseMatrix::remover(int fila,int columna){
    if(start==nullptr){
        return 0;
        
    }
    Node* actual = start;
    Node* anterior = nullptr;
    while (actual != nullptr && (actual->fila != fila || actual->columna != columna)) {
        anterior = actual;
        actual = actual->next;
    }
    if(actual ==nullptr){
        return 0;
    } 
    if(anterior == nullptr){
        start = actual->next;
    } else {
        anterior->next = actual->next;
    }
    actual->valor = 0;
    return 1;
}

double SparseMatrix::density(){
    int filas = obtenerFilas();
    int columnas = obtenerColumnas();
    int cantidad = 0;
    Node* actual = start;
    while(actual != nullptr){
        cantidad++;
        actual = actual->next;
    }

    int total = filas * columnas;
    double resultado = static_cast<double>(cantidad) / total;

    cout << "Densidad: " << resultado << endl;
    return resultado;
}

int SparseMatrix::obtenerFilas(){
    int filas=0;
    Node* actual=start;
    while(actual!=nullptr){
        filas=max(filas,actual->fila);
        actual=actual->next;
    }
    return filas+1;
}
int SparseMatrix::obtenerColumnas(){
    int columnas=0;
    Node* actual=start;
    while(actual!=nullptr){
        columnas=max(columnas,actual->columna);
        actual=actual->next;
    }
    return columnas +1;

}




SparseMatrix SparseMatrix::multiply(SparseMatrix &second){
    int filas1 = obtenerFilas();
    int columnas1 = obtenerColumnas();
    int filas2 = second.obtenerFilas();
    int columnas2 = second.obtenerColumnas();

    SparseMatrix C;
    if(columnas2 != filas2){
        cout<<"No se pueden multiplicar las matrices"<<endl;
        return C;
    }
    for (int i = 0; i < filas1; i++){
        for(int j = 0; j < columnas2; j++){
            int suma = 0;
            for(int k = 0; k < columnas1; k++){
                int val1 = get(i, k);
                int val2 = second.get(k, j);
                if(val1 != 0 && val2 != 0){
                    suma += val1 * val2;
                }                
            }
            if(suma != 0){
                C.add(i, j, suma);
            }
        }
    }
    
    return C;
    
}



bool SparseMatrix::existe(int fila,int columna){
    Node* actual=start;
    while(actual!=nullptr){
        if (actual->fila == fila && actual->columna == columna) {
            return true;
        }
        actual=actual->next;
    }
    return false;
}

void SparseMatrix::generarRandom(int cant){
    int listos=0;
    int fila;
    int columna;
    while(listos<cant){
        fila=rand();
        columna=rand();
        if(existe(fila,columna)==false){
            add(fila,columna,rand());
            listos++;
        }
    }

}
