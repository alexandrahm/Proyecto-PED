#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <headers/Struct.hpp> 
#include <headers/ListaDeCanciones.hpp>
#include <headers/ColaDeCanciones.hpp>
#include <headers/PilaDeHistorial.hpp>
using namespace std;

int main(){
    string opcion;
    do{
        system("cls");
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                              Menu principal                               ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t1)Lista de canciones. \t\t2)Cola de reproduccion." << endl;
        cout << "\t3)Pila de historial. \t\t4)Salir.\n" << endl;
        cout << "\tIngrese una opci\242n: ";
        getline(cin, opcion, '\n');
        if(ValidacionDeEntero(opcion)){
            if(opcion[0]=='1'){
                ListaDeCanciones();
            }else if(opcion[0]=='2'){
                ColaDeCanciones();
            }else if(opcion[0]=='3'){
                PilaDeHistorial();
            }else if(opcion[0]=='4'){
                system("exit");
            }else{
                cout << "\n\t\41Opcion no valida\255" << endl;
                cout << "\n\t";
                system("pause");
            }
        }else{
            cout << "\n\tPorfavor ingrese un n\243mero" << endl;
            cout << flush;
            cout << "\n\t";
            system("pause");
        }
    }while(opcion[0]!='4');
    return 0;
}