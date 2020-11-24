#include <iostream>
#include <headers/Struct.hpp> 

using namespace std;

void PilaDeHistorial(){
    string opcion;
    do{
        system("cls");
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                          Pila Del Historial                               ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t1) Ver Historial. \t\t2) Buscar una canci\242n del historial." << endl;
        cout << "\t3) Eliminar Todo El Historial. \t4) Borrar Una Canci\242n Del Historial." << endl;
        cout << "\t5) Volver al men\243 principal." << endl;
        cout << "\n\tIngrese una opci\242n: ";
        getline(cin, opcion, '\n');
        if(ValidacionDeEntero(opcion)){
            if(opcion[0]=='1'){
                MostrarPila();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='2'){
                BuscarUnoPila();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='3'){
                EliminarPila();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='4'){
                EliminarUnoPila();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='5'){

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
    }while (opcion[0]!='5');
}

void MostrarPila(){
    HistorialTemporal = Historial;
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                              Historial                                    ";
    cout << "\n\t-----------------------------------------------------------------------\n";
    while (!HistorialTemporal.empty()){     
        cout << "\n\t\tID: " << HistorialTemporal.top().Id<< "\n";
        cout << "\t\tNombre canci\242n : " << HistorialTemporal.top().Nombre << "\n";
        cout << "\t\tNombre del artista: " << HistorialTemporal.top().NombreDelArtista << "\n";
        music.openFromFile(HistorialTemporal.top().Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << "\n";
        cout << "\t\tRuta: " << HistorialTemporal.top().Archivo << "\n";
        HistorialTemporal.pop();
        cout << "\n\t-----------------------------------------------------------------------\n";
    }
}

void BuscarUnoPila(){
    string unNombre;
    int indice = 0;
    HistorialTemporal = Historial;
    cout << "\n\tNombre de la canci\242n a buscar: ";
    getline(cin, unNombre);
    bool encontrado = false;
    for(int i = 0; i<Historial.size(); i++){
        CancionTemporal = HistorialTemporal.top();
        if(CancionTemporal.Nombre == unNombre){
            encontrado = true;
            break;
        }else{
            HistorialTemporal.pop();
        }
    }
    if(encontrado){
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t          La Canci\242n Ha Sido Encontrada En El Historial                 ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t\tID: " << CancionTemporal.Id << endl;
        cout << "\t\tNombre canci\242n : " << CancionTemporal.Nombre << endl;;
        cout << "\t\tNombre del artista: " << CancionTemporal.NombreDelArtista << endl;;
        music.openFromFile(CancionTemporal.Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << "\n";
        cout << "\t\tRuta: " << CancionTemporal.Archivo << "\n";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }else{
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t          La Canci\242n No Sido Encontrada En El Historial                 ";
        cout << "\n\t-----------------------------------------------------------------------\n"; 
    }
}

void EliminarPila(){
    while (!Historial.empty()){
        Historial.pop();
        
    } 
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                             Historial Vacio                               ";
    cout << "\n\t-----------------------------------------------------------------------\n";
}

void EliminarUnoPila(){
    string unNombre;
    int indice = 0;
    indice = Historial.size();
    cout << "\n\tNombre de la canci\242n a Eliminar: ";
    getline(cin, unNombre);
    bool encontrado = false;
    for(int i = 0; i<indice; i++){
        CancionTemporal = Historial.top();
        if(CancionTemporal.Nombre == unNombre){
            encontrado = true;
            Historial.pop();
            break;
        }else{
            HistorialTemporal.push(CancionTemporal);
            Historial.pop();
        }
        
    }
    if(encontrado){
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                     La Canci\242n Ha Sido Eliminada                       ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\n\t\tID: " << CancionTemporal.Id << endl;
        cout << "\t\tNombre canci\242n : " << CancionTemporal.Nombre << endl;
        cout << "\t\tNombre del artista: " << CancionTemporal.NombreDelArtista << endl;
        music.openFromFile(CancionTemporal.Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << " seg\n";
        cout << "\t\tRuta: " << CancionTemporal.Archivo << "\n";
        cout << "\n\t-----------------------------------------------------------------------\n";
        while (!HistorialTemporal.empty()){
            CancionTemporal = HistorialTemporal.top();
            Historial.push(CancionTemporal);
            HistorialTemporal.pop();
        }
    }else{
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                     La Canci\242n No Ha Sido Encontrada                   ";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }
}