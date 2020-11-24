#ifndef _STRUCT_HPP
#define _STRUCT_HPP
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cctype>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definicion del registro Cancion 
namespace st{
typedef struct cancion{
    int Id = 0;
    string Nombre;
    string NombreDelArtista;
    string Archivo;
}Cancion;}

//Creando la lista global
int volumen = 100;
sf::Music music;

vector<st::Cancion> Lista;

//Prototipo De Funciones De ListaDeCanciones
void ListaDeCanciones();
void AgregarLista();
void MostrarLista();
void EliminarCancion();
void BuscarCancion();
void AgregarCola();

//Creando variables de cola global
queue<st::Cancion> ColaReproducciones;
queue<st::Cancion> ColaTemporal;
st::Cancion CancionTemporal;

//Prototipo De Funciones De ColaDeCanciones
void ColaDeCanciones();
void Reproduccion();
void MostrarCola();
void EliminarSiguiente();
void BuscarCancionCola();

//Creando la pila global
stack<st::Cancion> Historial;
stack<st::Cancion> HistorialTemporal;

//Prototipo De Funciones De PilaDeHistorial
void PilaDeHistorial();
void MostrarPila();
void EliminarPila();
void BuscarUnoPila();
void EliminarUnoPila();

//Prototipo De Funcion De ColaDeCanciones Para Añadir El Proceso A Un Hilo
void HiloReproductor(){
    music.play();
    while (music.getStatus() == sf::Music::Playing){
        sf::sleep(sf::milliseconds(100));
        cout << "\r\t\tReproduciendo... " << music.getPlayingOffset().asSeconds() << " seg        ";
        cout << flush;
    }
    
}
sf::Thread Hilo(&HiloReproductor);

//Validacion De Una Entrada
bool ValidacionDeEntero(string cadena){
    int inicio = 0;
    if(cadena.length()==0){
        return false;
    }else if (cadena[0] == '+' || cadena[0] == '-' ){
        inicio = 1;
        if(cadena.length()==1){
            return false;
        }
    }
    for (int i=0;i<cadena.length();i++){
        if(!isdigit(cadena[i])){
            return false;
        }
    }
    return true;
}


#endif







