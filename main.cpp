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
                cout<<"hasta luego"<<endl;
                break;
            case 8:
                randomizar();
                break;
            default:
                cout << "Esa opcion es invalida"<< endl;
        }
    } while(opcion !=7);
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
    cout << "7: Salir"<< endl;
    cout << "Seleccione: ";
}
void AgregarDato(){
    clock_t inicio=clock();
    int X;
    int Y;
    int value;
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
    cout << "Ingrese Valor a insertar: " << endl; 
    getline(cin, input);
    try {
        value = stoi(input);
    } catch (...){
        value = 0;
    }
    if(value == 0){
        cout<<"Opcion invalida, se converitra en 0 automaticamente"<<endl;
    }
    
    Matrix.add(X,Y,value);
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
    cout<< "valor: " << Matrix.get(X,Y) << endl;
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
    std::cout<< "Dencidad de la matriz: "<< Matrix.density()<<"%"<<std::endl;
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}

void MultiplicarMatriz(){
    clock_t inicio=clock();
    
    //codigo aqui
    
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}

void randomizar(){
    int opcion;
    string input;
    cout<<"Cuantos generar?"<<endl;
    cout<<"1. 50 datos"<<endl;
    cout<<"2. 250 datos"<<endl;
    cout<<"3. 500 datos"<<endl;
    cout<<"4. 1000 datos"<<endl;
    cout<<"5. 5000 datos"<<endl;
    getline(cin, input);
    try {
        opcion = stoi(input);
    } catch (...){
        opcion = 0;
    }
    clock_t inicio=clock();
    switch(opcion){
        case 1:
            Matrix.generarRandom(50);
            break;
        case 2:
            Matrix.generarRandom(250);
            break;
        case 3:
            Matrix.generarRandom(500);
            break;
        case 4:
            Matrix.generarRandom(1000);
            break;
        case 5:
            Matrix.generarRandom(5000);
            break;
        default:
            cout<<"Opcion no valida"<<endl;
    }
    clock_t fin=clock();
    double tiempo=double(fin-inicio)/CLOCKS_PER_SEC;
    std::cout<<"tiempo de ejecucion "<<tiempo<<" segundos"<<std::endl;
}
