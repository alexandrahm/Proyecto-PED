#include <iostream>
#include <headers/Struct.hpp> 

using namespace std;

//Menu de la cola
void ColaDeCanciones(){
    string opcion;
    do{
        system("cls");
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                       Cola de Canciones A\244adidas                       ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t1) Reproducir Cola.      \t\t\t2) Ver canci\242n en cola." << endl;
        cout << "\t3) Eliminar Siguiente Canci\242n \t\t\t4) Buscar una canci\242n en la Cola" << endl;
        cout << "\t5) Volver al men\243 principal" << endl;
        cout << "\n\tIngrese una opci\242n: ";
        getline(cin, opcion, '\n');
        if(ValidacionDeEntero(opcion)){
            if(opcion[0]=='1'){
                Reproduccion();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='2'){
                MostrarCola();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='3'){
                EliminarSiguiente();
                cout << "\n\t";
                system("Pause");
            }else if(opcion[0]=='4'){
                BuscarCancionCola();
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
    }while(opcion[0]!='5');
}

void MostrarCola(){
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                            Canciones en la Cola                            ";
    cout << "\n\t-----------------------------------------------------------------------\n";
    ColaTemporal = ColaReproducciones;
    while (!ColaTemporal.empty()){
        // Ver la primera cancion de la playlist
        cout << "\n\t\tID: " << ColaTemporal.front().Id << "\n";
        cout << "\t\tNombre canci\242n : " << ColaTemporal.front().Nombre << "\n";
        cout << "\t\tNombre del artista: " << ColaTemporal.front().NombreDelArtista << "\n";
        music.openFromFile(ColaTemporal.front().Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << " seg \n";
        cout << "\t\tRuta: " << ColaTemporal.front().Archivo << "\n";
        // Sacandola
        ColaTemporal.pop();
        cout << "\n\t-----------------------------------------------------------------------\n";
    }
}

void Reproduccion(){
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                              Reproduciendo                                ";
    cout << "\n\t-----------------------------------------------------------------------\n";
    while(!ColaReproducciones.empty()){
        // Ver la primera cancion de la playlist
        CancionTemporal = ColaReproducciones.front();
        cout << "\n\t\tID: " << CancionTemporal.Id << "\n";
        cout << "\t\tNombre canci\242n : " << CancionTemporal.Nombre << "\n";
        cout << "\t\tNombre del artista: " << CancionTemporal.NombreDelArtista << "\n";
        music.openFromFile(CancionTemporal.Archivo);
        music.setVolume(volumen);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << " seg\n";
        cout << "\t\tRuta: " << CancionTemporal.Archivo << "\n";
        cout << "\t\tReproduciendo... oprime enter para detener\n";
        Hilo.launch();
        cin.ignore(10000, '\n');
        Hilo.terminate();
        music.pause();
        cout << "\n\t-----------------------------------------------------------------------\n";
        //Agregandola al historial
        Historial.push(CancionTemporal);
        // Sacandola
        ColaReproducciones.pop();
    }
}

void EliminarSiguiente(){
    while (!ColaReproducciones.empty())
    {
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "            Se elimino la siguiente canci\242n de la cola                  ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        // Ver la primera cancion de la playlist
        cout << "\n\t\tID: " << ColaReproducciones.front().Id << "\n";
        cout << "\t\tNombre canci\242n : " << ColaReproducciones.front().Nombre << "\n";
        cout << "\t\tNombre del artista: " << ColaReproducciones.front().NombreDelArtista << "\n";
        music.openFromFile(ColaReproducciones.front().Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << "seg \n";
        cout << "\t\tRuta: " << ColaReproducciones.front().Archivo << "\n";
        cout << "\n\t-----------------------------------------------------------------------\n";
        // Sacandola
        ColaReproducciones.pop();
    }
    cout << "\n\t-----------------------------------------------------------------------\n";
    cout << "\t                                 Cola vacia                                ";
    cout << "\n\t-----------------------------------------------------------------------\n";
    
}

void BuscarCancionCola(){
    bool Existe = false;
    string unNombre;
    cout << "\n\tNombre de la canci\242n a buscar en la cola: ";
    getline(cin, unNombre);
    ColaTemporal = ColaReproducciones;
    while (!ColaTemporal.empty()){
        // Ver la primera cancion de la cola
        if (ColaTemporal.front().Nombre == unNombre){
            Existe = true;
            break;
        }else{
            // Sacandola
            ColaTemporal.pop();
        }
    }
    if (Existe){
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                           Canci\242n encontrada                           ";
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\n\t\tID: " << ColaTemporal.front().Id << endl;
        cout << "\t\tNombre canci\242n : " << ColaTemporal.front().Nombre << endl;
        cout << "\t\tNombre del artista: " << ColaTemporal.front().NombreDelArtista << endl;
        music.openFromFile(ColaTemporal.front().Archivo);
        cout << "\t\tDuraci\242n: " << music.getDuration().asSeconds() << "\n";
        cout << "\t\tRuta: " << ColaTemporal.front().Archivo << "\n";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }else{
        cout << "\n\t-----------------------------------------------------------------------\n";
        cout << "\t                         Canci\242n no encontrada                          ";
        cout << "\n\t-----------------------------------------------------------------------\n";
    }
}

