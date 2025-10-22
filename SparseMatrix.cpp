#include "SparseMatrix.h"
#include <iostream>
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
    Node* nuevo = new Node(fila,columna,valor);
    if(start==nullptr || fila< start->fila || (fila == start->fila && columna< start->columna)){
        nuevo->next = start;
        start=nuevo;
        return;
    }
    Node* actual=start;
    while(actual->next!=nullptr&&(actual->next->fila<fila||(actual->next->fila==fila&&actual->next->columna<columna))){
        actual=actual->next;
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
        cout << "(" << actual->fila << ", " << actual->columna << ") --> " << actual->valor << endl;
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
    delete actual;
    return 1;
}

int SparseMatrix::density(){
    if(start==nullptr){return 0;}
    int cantidad=0;
    int filas=obtenerFilas();
    int columnas=obtenerColumnas();
    Node* actual=start;
    while(actual!=nullptr){
        cantidad++;
        actual=actual->next;
    }
    int total=filas*columnas;
    double resultado = (double)cantidad/total;
    return resultado*100;
}

int SparseMatrix::obtenerFilas(){
    int filas=0;
    Node* actual=start;
    while(actual!=nullptr){
        filas=max(filas,actual->fila);
        actual=actual->next;
    }
    return filas;
}
int SparseMatrix::obtenerColumnas(){
    int columnas=0;
    Node* actual=start;
    while(actual!=nullptr){
        columnas=max(columnas,actual->columna);
        actual=actual->next;
    }
    return columnas;

}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    if(obtenerColumnas()==second->obtenerFilas()){
        SparseMatrix* matriz=new SparseMatrix();
        Node* actual=start;
        while(actual!=nullptr){
            Node* multi=second->start;
            while(multi!=nullptr){
                if(actual->fila==multi->columna){
                    int agregar=get(actual->fila,actual->columna) * second->get(multi->fila,multi->columna);
                    matriz->add(actual->fila,multi->columna,agregar);
                }
                multi=multi->next;
            }
            actual=actual->next;
        }
        return matriz;
    }
    return nullptr;
}
