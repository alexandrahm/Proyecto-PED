#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Definicion del registro Cancion 
struct cancion{
    int Id = 0;
    string Nombre;
    string NombreDelArtista;
    int Duracion;
};


//Variables Glb. COLA
queue<cancion> coladecanciones;
stack<cancion>historial;

//Creando la lista global
vector<cancion> playlist;

//Prototipo De Funciones
void getSongAndAddToPlaylist();
void showAllThePlaylist();
void deleteSong();
void searchSong();
void addToPlayQueue();
void MostrarHistorial ();
void EliminarHistorial();
//Funcion Principal
void ListaDeCanciones(){
    int opcion = 0;
    do{
        cout << "\n\t\t\t\t--- Lista de canciones ---\n";
        cout << "\t1) Agregar una cancion a la lista \t\t\t2) Mostrar lista de canciones" << endl;
        cout << "\t3) Eliminar una cancion de la lista \t\t\t4) Buscar una cancion de la lista" << endl;
        cout << "\t5) Agregar una cancion a la cola de reproduccion \t6) Volver al menu principal" << endl;
        cout << "\tIngrese una opcion: ";
        cin >> opcion;
        cin.ignore();    
        switch (opcion){
            case 1:{
                getSongAndAddToPlaylist();
            }break;
            case 2:{
                showAllThePlaylist();
            }break;
            case 3:{
                deleteSong();
            }break;
            case 4:{
                searchSong();
            }break;
            case 5:{
                addToPlayQueue();
            }break;
            case 6:{
                
            }break;
            default:{
                cout << "¡Opcion invalida!" <<endl;
            }break;
        }
    }while(opcion!=6);

}

// Implementacion de funciones
void getSongAndAddToPlaylist(){
    bool alreadyExist = false;
    cancion cancion;
    cout << "\nIngresa el ID que la identificará" << endl;
    cin >> cancion.Id;
    cin.ignore();
    for(int i = 0; i < playlist.size(); i++){
       
        if (playlist[i].Id == cancion.Id){
            alreadyExist = true;
        }
    }
    
    if(alreadyExist){
        cout << "El ID de la canción ya existe, intenta con otro nuevo";
    }else{
        
    cin.ignore();
    cout << "Ingresa el nombre de la cancion" << endl;
    getline(cin, cancion.Nombre);
    cout << "Ingresa el nombre del artista" << endl;
    getline(cin, cancion.NombreDelArtista);
    cout << "¿Cuál es la duración?" << endl;
    cin >> cancion.Duracion;
    playlist.push_back(cancion);
    historial.push(cancion);
}
     
}

void showAllThePlaylist(){
    for (int i = 0; i < playlist.size(); i++){
        cout << "\nID: " << playlist[i].Id << "\t";
        cout << "Nombre canción : " << playlist[i].Nombre << "\t";
        cout << "Nombre del artista: " << playlist[i].NombreDelArtista << "\t";
        cout << "Duracion: " << playlist[i].Duracion << "\n";
    }
}

void deleteSong(){
    int id;
    cout << "\nIngresa el ID que deseas eliminar"<< endl;
    cin >> id;
    cin.ignore();
    for(int i = 0; i < playlist.size(); i++){
        if(playlist[i].Id==id){
            playlist.erase(playlist.begin() + i);
        }
    }
}

void searchSong(){
    string unNombre;
    int indice = 0;
    cout << "\nNombre de la cancion a buscar: ";
    getline(cin, unNombre);

    bool encontrado = false;
    for (int i = 0; i < playlist.size(); i++) {
        if(playlist[i].Nombre == unNombre){
            encontrado = true;
            indice = i;
            break;
        }
    }
    
    if(encontrado){
        cout << "\nLa cancion ha sido encontrada en la lista." << endl;
        cout << "ID: " << playlist[indice].Id << endl;
        cout << "Nombre canción : " << playlist[indice].Nombre << endl;;
        cout << "Nombre del artista: " << playlist[indice].NombreDelArtista << endl;;
        cout << "Duracion: " << playlist[indice].Duracion << endl;;
    }else{
        cout << "\nLa Cancion no se encuentra en la Lista." << endl;
    }

}

void addToPlayQueue(){
    string unNombre;
    cancion unaCancion;
    int indice = 0;
    cout << "\nNombre de la cancion a encolar: ";
    getline(cin, unNombre);

    bool encontrado = false;
    for (int i = 0; i < playlist.size(); i++) {
        if(playlist[i].Nombre == unNombre){
            encontrado = true;
            indice = i;
            break;
        }
    }
    unaCancion.Id=playlist[indice].Id;
    unaCancion.Nombre=playlist[indice].Nombre;
    unaCancion.NombreDelArtista=playlist[indice].NombreDelArtista;
    unaCancion.Duracion=playlist[indice].Duracion;
    if(encontrado){

        
        coladecanciones.push(unaCancion);
        cout << "\nLa cancion ha sido enviada a la cola." << endl;

        
    }else{
        cout << "\nLa cancion no ha sido enviada a la cola.\n No se han encontrado resultados" << endl;

    }
}

void MostrarHistorial (){

 while (!historial.empty()){
        
        cout << "\nID: " << historial.top().Id<< "\t";
        cout << "Nombre canción : " << historial.top().Nombre << "\t";
        cout << "Nombre del artista: " << historial.top().NombreDelArtista << "\t";
        cout << "Duracion: " << historial.top().Duracion << "\n";
        historial.pop();

    }

}

void EliminarHistorial (){

if (!historial.empty())
{
    historial.pop();

    cout<<"------ Se ha vaciado el historial------"<<endl;
}

else
{
    cout<<"-----Historial Vacio-----"<<endl;
}

}