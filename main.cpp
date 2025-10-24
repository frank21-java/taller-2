#include <iostream>
#include "SparseMatrix.h"
#include <ctime>
using namespace std;

SparseMatrix Matrix;

void menuPrincipal();

void AgregarDato();
void ObteneDatoCord();
void RemoverDato();
void MostrarDatos();
void DensidadMatriz();
void MultiplicarMatriz();
void randomizar();
void MultiplicarMatrizrandom();

int main()
{   
    int opcion;
    string input;
    do{
        menuPrincipal();
        getline(cin, input);
        
        try {
            opcion = stoi(input);
        } catch (...){
            opcion = 0;
        }
        switch(opcion){
            case 1 :
                AgregarDato();
                break;
            case 2 :
                ObteneDatoCord();
                break;
            case 3 :
                RemoverDato();
                break;
            case 4 :
                MostrarDatos();
                break;
            case 5 :
                DensidadMatriz();
                break;
            case 6 :
                MultiplicarMatriz();
                break;
            
            case 7 :
                MultiplicarMatrizrandom();
                break;
            case 8:
                randomizar();
                break;
            case 9 :
                cout<<"hasta luego"<<endl;
                break;
            default:
                cout << "Esa opcion es invalida"<< endl;
        }
    } while(opcion !=9);
    return 0;
}

void menuPrincipal(){
    cout << "--------MENU--------" << endl;
    cout << "1: agrega dato (X,Y)" << endl;
    cout << "2: Obtener dato de la cordenada(X,Y)" << endl;
    cout << "3: Remover dato de una cordenada(X,Y)" << endl;
    cout << "4: Mostrar los datos" << endl;
    cout << "5: Densidad de la matriz" << endl;
    cout << "6: Multiplicar matriz"<< endl;
    cout << "7: Multpiplicar matriz alatoriamente"<< endl;
    cout << "8: Generar datos aleatorios"<< endl;
    cout << "9: Salir"<< endl;
    cout << "Seleccione: ";
}
void AgregarDato(){
    clock_t inicio=clock();
    int X;
    int Y;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coredenada X" << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...){
        X = 0;
    }
    if(X == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    cout << "Ingrese Cordenada Y" << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...){
        Y = 0;
    }
    if(Y == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    if (X <= 0 || Y <= 0) {
        cout << "Tamaño inválido de matriz.\n";
        return;
    }

    cout << "\nIngrese los valores de la matriz (" << X << "x" << Y << "):\n"; 

    for(int i = 0; i < X; i++){
        int posision = i+1;
        cout << "Fila "<<posision<<": ";
        string XPos;
        getline(cin, XPos);
        for(int j = 0; j < Y; j++){
            int value = 0;
            if (j<(int)XPos.size()){
                string temp(1,XPos[j]);
                if (temp == ""){
                    value = 0;
                } else{
                    try {value = stoi(temp);} catch (...){value = 0;}
                }
            } 
            Matrix.add(i, j, value);
        }
    }
    cin.clear();
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
void ObteneDatoCord(){
    clock_t inicio=clock();
    int X;
    int Y;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coredenada X" << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...){
        X = 0;
    }
    if(X == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    cout << "Ingrese Cordenada Y" << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...){
        Y = 0;
    }
    if(Y == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    cout<< "valor: " << Matrix.get(X-1,Y-1) << endl;
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
void RemoverDato(){
    clock_t inicio=clock();
    int X;
    int Y;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coredenada X" << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...){
        X = 0;
    }
    if(X == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    cout << "Ingrese Cordenada Y" << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...){
        Y = 0;
    }
    if(Y == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    X--;
    Y--;
    int a = Matrix.remover(X,Y);
    if (a == 1){
        cout << "Se a eliminado el dato de la cordenada con exito"<<endl;
    } else{
        cout << "No existe dato en esa cordenada"<<endl;
    }
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
void MostrarDatos(){
    clock_t inicio=clock();
    cout<< "Datos en la matriz:"<<endl;
    Matrix.printStoredValues();
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
void DensidadMatriz(){
    clock_t inicio=clock();
    cout<< "Dencidad de la matriz: "<< Matrix.density()<<endl;
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}

void MultiplicarMatriz(){
    clock_t inicio=clock();
    cout<<"ingrese el numero de filas de la segunda matriz:" << endl;
    SparseMatrix B;
    int X;
    int Y;
    string input;
    cout << "----------------------" << endl;
    cout << "Ingrese Coredenada X" << endl;
    getline(cin, input);
    try {
        X = stoi(input);
    } catch (...){
        X = 0;
    }
    if(X == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    cout << "Ingrese Cordenada Y" << endl;
    getline(cin, input);
    try {
        Y = stoi(input);
    } catch (...){
        Y = 0;
    }
    if(Y == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    if (X <= 0 || Y <= 0) {
        cout << "Tamaño inválido de matriz.\n";
        return;
    }

    cout << "\nIngrese los valores de la matriz (" << X << "x" << Y << "):\n"; 

    for(int i = 0; i < X; i++){
        int posision = i+1;
        cout << "Fila "<<posision<<": ";
        string XPos;
        getline(cin, XPos);
        for(int j = 0; j < Y; j++){
            int value = 0;
            if (j<(int)XPos.size()){
                string temp(1,XPos[j]);
                if (temp == ""){
                    value = 0;
                } else{
                    try {value = stoi(temp);} catch (...){value = 0;}
                }
            } 
            B.add(i, j, value);
        }
    }
    cin.clear();
    SparseMatrix C = Matrix.multiply(B);
    cout<<"Resultado de la multiplicacion:"<<endl;
    C.printStoredValues();
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
void MultiplicarMatrizrandom(){
    SparseMatrix B ;
    string input;
    int filasb;
    int columnasb;
    cout << "Ingrese el numero de filas de la segunda matriz:" << endl;
    getline(cin, input);
    try {filasb = stoi(input);} catch (...){filasb = 0;}
    cout << "Ingrese el numero de columnas de la segunda matriz:" << endl;
    getline(cin, input);
    try {columnasb = stoi(input);} catch (...){columnasb = 0;}
    clock_t inicio=clock();
    B.generarRandom(filasb,columnasb);
    SparseMatrix C = Matrix.multiply(B);
    cout<<"Resultado de la multiplicacion:"<<endl;
    C.printStoredValues();
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
void randomizar(){
    string input;
    int filas;
    int columnas;
    cout << "Ingrese el numero de filas de la matriz: " << endl;
    getline(cin, input);
    try {filas = stoi(input);} catch (...){filas = 0;}
    cout << "Ingrese el numero de columnas de la matriz: " << endl;
    getline(cin, input);
    try {columnas = stoi(input);} catch (...){columnas = 0;}
    if(filas == 0 || columnas == 0){
        cout<<"Opcion invalida"<<endl;
        return;
    }
    int total = filas * columnas;
    cout<< "Se generara una matriz de " << filas << "x" << columnas << " con un total de " << total << " elementos." << endl;
    clock_t inicio=clock();
    Matrix.generarRandom(filas,columnas);
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
