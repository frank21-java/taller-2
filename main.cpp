#include <iostream>
#include "SparseMatrix.h"
using namespace std;

void menuPrincipal();

void AgregarDato();
void ObteneDatoCord();
void RemoverDato();
void MostrarDatos();
void DensidadMatriz();
void MultiplicarMatriz();


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
                void AgregarDato();
                break;
            case 2 :
                void ObteneDatoCord();
                break;
            case 3 :
                void RemoverDato();
                break;
            case 4 :
                void MostrarDatos();
                break;
            case 5 :
                void DensidadMatriz();
                break;
            case 6 :
                void MultiplicarMatriz();
                break;
            case 7 :
                cout<<"hasta luego"<<endl;
                break;
            default:
                cout << "Esa opcion es invalida"<< endl;
        }
    }while(opcion !=7);
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
void AgregarDato(){}
void ObteneDatoCord(){}
void RemoverDato(){}
void MostrarDatos(){}
void DensidadMatriz(){}
void MultiplicarMatriz(){}
