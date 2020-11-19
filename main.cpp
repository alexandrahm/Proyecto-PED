#include <iostream>

#include "ListaDeCanciones.hpp"
#include "ColaDeCanciones.hpp"
using namespace std;

int main(){
    int opcion = 0;
    do{
        cout << "\n\n\t\t\t--- Menu principal ---" << endl;
        cout << "\t1)Lista de canciones. \t2)Cola de reproduccion." << endl;
        cout << "\t3)Pila de historial. \t4)Salir.\n" << endl;
        cout << "\tIngrese una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion){
        case 1:{
            ListaDeCanciones();
        }break;
        case 2:{
           VerCola();
        }break;
        case 3:{
        
        int ophistorial = 0;
            
            cout<<endl;
            cout<< "1) Ver Historial"<<endl;
            cout<< "2) Eliminar Historial"<<endl;
            cin>>ophistorial;
            
            switch (ophistorial)
            {
            case 1:
                
                MostrarHistorial();
                break;
            
            case 2: 

               EliminarHistorial();
                break;
            }}
        
         break;
        case 4:{
            
        }break;
        default:{
            cout << "¡Opcion no valida!" << endl;
        }break;
        }

    }while (opcion!=4);
    

    return 0;
}