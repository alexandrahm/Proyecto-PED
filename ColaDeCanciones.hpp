#include <iostream>
#include <queue>

using namespace std;

//Variables Glb. COLA
queue<cancion> temporalbackup;

void mostrarCola();
void eliminarSiguiente();
void buscarCancionEnCola();
void reproducirSiguiente();

//Menu de la cola
void VerCola()
{
    int opcion = 0;
    do
    {
        cout << "\n\t\t\t\t--- Cola de Canciones Anadidas ---\n";
        cout << "\t1) Ver Canciones en Cola      \t\t\t2) Reproducir siguiente Canción" << endl;
        cout << "\t3) Eliminar Siguiente Cancion \t\t\t4) Buscar una cancion en la Cola" << endl;
        cout << "\t5) Volver al menu principal" << endl;
        cout << "\tIngrese una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
        {
            mostrarCola();
        }
        break;
        case 2:
        {
            reproducirSiguiente();
        }
        break;
        case 3:
        {
            eliminarSiguiente();
        }
        break;
        case 4:
        {
            buscarCancionEnCola();
        }
        break;
        case 5:
        {
        }
        break;

        default:
        {
            cout << "¡Opcion invalida!" << endl;
        }
        break;
        }
    } while (opcion != 5);
}

void mostrarCola()
{

    cout << "\n-----------------------------------------------------------------------\n";
    cout << "                            Canciones en la Cola                            ";
    cout << "\n-----------------------------------------------------------------------\n";

    //backup
    temporalbackup = coladecanciones;
    //ELIMINAR PRIMERA CANCION DE LA PLAYLIST

    while (!coladecanciones.empty())
    {
        cout << "\n-----------------------------------------------------------------------\n";
        // Ver la primera cancion de la playlist
        cancion cancioneliminada = coladecanciones.front();

        cout << "\nID: " << cancioneliminada.Id << "\t";
        cout << "Nombre canción : " << cancioneliminada.Nombre << "\t";
        cout << "Nombre del artista: " << cancioneliminada.NombreDelArtista << "\t";
        cout << "Duracion: " << cancioneliminada.Duracion << "\n";

        // Sacandola
        coladecanciones.pop();
    }

    cout << "\n-----------------------------------------------------------------------\n";

    //rebackup
    coladecanciones = temporalbackup;
}

void reproducirSiguiente()
{

    cout << "\n-----------------------------------------------------------------------\n";
    cout << "                              Reproduciendo                               ";
    cout << "\n-----------------------------------------------------------------------\n";
    // Ver la primera cancion de la playlist
    cancion cancioneliminada = coladecanciones.front();

    cout << "\nID: " << cancioneliminada.Id << "\t";
    cout << "Nombre canción : " << cancioneliminada.Nombre << "\t";
    cout << "Nombre del artista: " << cancioneliminada.NombreDelArtista << "\t";
    cout << "Duracion: " << cancioneliminada.Duracion << "\n";

    cout << "\n-----------------------------------------------------------------------\n";

    // Sacandola
    coladecanciones.pop();
}
void eliminarSiguiente()
{
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "            Se elimino la siguiente cancion de la cola                   ";
    cout << "\n-----------------------------------------------------------------------\n";
    // Ver la primera cancion de la playlist
    cancion cancioneliminada = coladecanciones.front();

    cout << "\nID: " << cancioneliminada.Id << "\t";
    cout << "Nombre canción : " << cancioneliminada.Nombre << "\t";
    cout << "Nombre del artista: " << cancioneliminada.NombreDelArtista << "\t";
    cout << "Duracion: " << cancioneliminada.Duracion << "\n";

    cout << "\n-----------------------------------------------------------------------\n";

    // Sacandola
    coladecanciones.pop();
}

void buscarCancionEnCola()
{
      //backup
    temporalbackup = coladecanciones;

    string unNombre;

    cout << "\nNombre de la cancion a buscar en la cola: ";
    getline(cin, unNombre);

  

    bool encontrado = false;
    while (!coladecanciones.empty())
    {
        cout << "\n-----------------------------------------------------------------------\n";
        // Ver la primera cancion de la cola
        cancion cancioneliminada = coladecanciones.front();

        if (cancioneliminada.Nombre == unNombre)
        {
            encontrado = true;

            break;
        }
        else
        {

            // Sacandola
            coladecanciones.pop();
        }
    }

    if (encontrado)
    {
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "                            Canción encontrada                           ";
        cout << "\n-----------------------------------------------------------------------\n";
        cancion cancionencontrada = coladecanciones.front();
        cout << "\nLa cancion ha sido encontrada en la Cola de Reproduccion." << endl;
        cout << "ID: " << cancionencontrada.Id << endl;
        cout << "Nombre canción : " << cancionencontrada.Nombre << endl;
        ;
        cout << "Nombre del artista: " << cancionencontrada.NombreDelArtista << endl;
        ;
        cout << "Duracion: " << cancionencontrada.Duracion << endl;
        ;
    }
    else
    {
        cout << "\nCancion no se encuentra en la Cola." << endl;
    }

    //rebackup
    coladecanciones = temporalbackup;
}

