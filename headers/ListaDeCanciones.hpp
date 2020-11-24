#include <iostream>
#include <headers/Struct.hpp> 

using namespace std;

//Funcion Principal
void ListaDeCanciones(){
    string opcion;
    do{
        system("cls");
        cout << "\n\t--------------------------------------------------------------------------------------------\n";
        cout << "\t                                     Lista de Canciones                                         ";
        cout << "\n\t--------------------------------------------------------------------------------------------\n";   
        cout << "\t1) Agregar una Canci\242n a la lista \t\t\t2) Mostrar lista de Canciones" << endl;
        cout << "\t3) Eliminar una Canci\242n de la lista \t\t\t4) Buscar una Canci\242n de la lista" << endl;
        cout << "\t5) Agregar a la cola de reproducci\242n \t\t\t6) Volver al men\243 principal" << endl;
        cout << "\n\tIngrese una opci\242n: ";   
        getline(cin, opcion, '\n');
        if(ValidacionDeEntero(opcion)){
            if(opcion[0]=='1'){
                AgregarLista();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='2'){
                MostrarLista();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='3'){
                EliminarCancion();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='4'){
                BuscarCancion();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='5'){
                AgregarCola();
                cout << "\n\t";
                system("pause");
            }else if(opcion[0]=='6'){

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
    }while(opcion[0]!='6');

}

// Implementacion de funciones
void AgregarLista(){
    bool alreadyExist = false;
    cout << "\n\tIngresa el ID que la identificar\240: ";
    cin >> CancionTemporal.Id;
    cin.ignore();
    for(int i = 0; i < Lista.size(); i++){
       
        if (Lista[i].Id == CancionTemporal.Id){
            alreadyExist = true;
        }
    }
    if(alreadyExist){
        cout << "\tEl ID de la canci\242n ya existe, intenta con otro nuevo";
    }else{
        cout << "\tIngresa el nombre de la canci\242n: ";
        getline(cin, CancionTemporal.Nombre);
        cout << "\tIngresa el nombre del artista: ";
        getline(cin, CancionTemporal.NombreDelArtista);
        cout << "\tIngrese la ruta absoluta del archivo ogg: ";
        getline(cin, CancionTemporal.Archivo);
        if(!music.openFromFile(CancionTemporal.Archivo)){
            cout << "\tArchivo no encontrado" << endl;
            cout << "\tCanci\242n no agregada" << endl;
        }else
        {
           Lista.push_back(CancionTemporal); 
        }
    }
}

void MostrarLista(){
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                          Canciones En La Lista                            ";
    cout << "\n\t-----------------------------------------------------------------------\n";   
    for (int i = 0; i < Lista.size(); i++){
        cout << "\n\t\tID: " << Lista[i].Id << "\n";
        cout << "\t\tNombre canci\242n : " << Lista[i].Nombre << "\n";
        cout << "\t\tNombre del artista: " << Lista[i].NombreDelArtista << "\n";
        music.openFromFile(Lista[i].Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << " seg\n";
        cout << "\t\tRuta: " << Lista[i].Archivo << "\n";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }
}

void EliminarCancion(){
    while (!Lista.empty())
    {
        int id;
        cout << "\n\tIngresa el ID que deseas eliminar: ";
        cin >> id;
        cin.ignore();
        for(int i = 0; i < Lista.size(); i++){
            if(Lista[i].Id==id){
                cout << "\n\t-----------------------------------------------------------------------\n";
                cout << "\t                           Cancion Eliminada                               ";
                cout << "\n\t-----------------------------------------------------------------------\n";
                cout << "\n\t\tID: " << Lista[i].Id << endl;
                cout << "\t\tNombre canci\242n : " << Lista[i].Nombre << endl;
                cout << "\t\tNombre del artista: " << Lista[i].NombreDelArtista << endl;
                music.openFromFile(Lista[i].Archivo);
                cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << endl;
                cout << "\t\tRuta: " << Lista[i].Archivo << endl;
                cout << "\n\t-----------------------------------------------------------------------\n";
                Lista.erase(Lista.begin() + i);
                break;
            }
        }
    }
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                                 Lista vacia                               ";
    cout << "\n\t-----------------------------------------------------------------------\n";
    
    
}

void BuscarCancion(){
    string unNombre;
    int indice = 0;
    cout << "\n\tNombre de la canci\242n a buscar: ";
    getline(cin, unNombre);
    bool encontrado = false;
    for (int i = 0; i < Lista.size(); i++) {
        if(Lista[i].Nombre == unNombre){
            encontrado = true;
            indice = i;
            break;
        }
    }
    
    if(encontrado){
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                            Canci\242n encontrada                          ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\n\t\tID: " << Lista[indice].Id << endl;
        cout << "\t\tNombre canci\242n : " << Lista[indice].Nombre << endl;;
        cout << "\t\tNombre del artista: " << Lista[indice].NombreDelArtista << endl;;
        music.openFromFile(Lista[indice].Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << "\n";
        cout << "\t\tRuta: " << Lista[indice].Archivo << "\n";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }else{
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                         Canci\242n no encontrada                          ";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }

}

void AgregarCola(){
    string opcion;
    cout << "\n\t1) Agregar todas las canciones a la cola";
    cout << "\n\t2) Agregar una canci\242n a la cola" << endl;
    cout << "\n\tIngrese una opci\242n: ";
    getline(cin, opcion, '\n');
    if(ValidacionDeEntero(opcion)){
            if(opcion[0]=='1'){
                cout << "\n\t-----------------------------------------------------------------------\n";
                cout << "\t                          Canciones Enviadas                               ";
                cout << "\n\t-----------------------------------------------------------------------\n"; 
                for (int i=0;i<Lista.size();i++){
                    cout << "\n\t\tID: " << Lista[i].Id << "\n";
                    cout << "\t\tNombre canci\242n : " << Lista[i].Nombre << "\n";
                    cout << "\t\tNombre del artista: " << Lista[i].NombreDelArtista << "\n";
                    music.openFromFile(Lista[i].Archivo);
                    cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << " seg\n";
                    cout << "\t\tRuta: " << Lista[i].Archivo << "\n";
                    cout << "\n\t-----------------------------------------------------------------------\n";
                    ColaReproducciones.push(Lista[i]);
                }
            }else if(opcion[0]=='2'){
                string unNombre;
                int indice = 0;
                cout << "\n\tNombre de la Canci\242n a encolar: ";
                getline(cin, unNombre);
                bool encontrado = false;
                for (int i = 0; i < Lista.size(); i++) {
                    if(Lista[i].Nombre == unNombre){
                        encontrado = true;
                        indice = i;
                        break;
                    }
                }
                if(encontrado){
                    ColaReproducciones.push(Lista[indice]);
                    cout << "\n\t-----------------------------------------------------------------------\n";
                    cout << "\t                       La Canci\242n Ha Sido Enviada                       ";
                    cout << "\n\t-----------------------------------------------------------------------\n"; 
                    cout << "\n\t\tID: " << Lista[indice].Id << "\n";
                    cout << "\t\tNombre canci\242n : " << Lista[indice].Nombre << "\n";
                    cout << "\t\tNombre del artista: " << Lista[indice].NombreDelArtista << "\n";
                    music.openFromFile(Lista[indice].Archivo);
                    cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << " seg\n";
                    cout << "\t\tRuta: " << Lista[indice].Archivo << "\n";
                    cout << "\n\t-----------------------------------------------------------------------\n";
                }else{
                    cout << "\n\t-----------------------------------------------------------------------\n";
                    cout << "\t                       La Canci\242n No Encontrada                         ";
                    cout << "\n\t-----------------------------------------------------------------------\n"; 
                }
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
}