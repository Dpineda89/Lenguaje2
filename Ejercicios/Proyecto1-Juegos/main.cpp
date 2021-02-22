#include <iostream>
#include "startShip.h"
#include "snake.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int opcion = 0;
    
    while(true) {
    system("cls");

        cout << "------------------------------------------------";
        cout << " ESTE PROYECTO ES PRESENTADO POR: ";
        cout << "Darwin Pineda. ";
        cout << "----------------------------------------------";
        cout << endl;
        cout << "------------------------------------------------------";
        cout << " PRESENTADO A: ";
        cout << " Lic. Billy Fernandez";
        cout << "-----------------------------------------------------";
        cout << endl;
        cout << "**********************************************************";
        cout << " BIENVENIDO AL MENU DE JUEGOS ";
        cout << "**********************************************************";
        cout << endl;
        cout << endl;
        cout << "Seleccione un juego"; 
        cout << endl << endl;
        cout << "1 - Starship" << endl << endl;
        cout << "2 - Snake" << endl << endl;
        cout << "0 - Salir" << endl << endl ;
        cout << "Ingrese un numero para seleccionar un juego:";
        cin >> opcion;

        switch (opcion)
        {
        case 1: 
            starShip();            
            break;
        case 2:
            snake();
            break;
                
        default:
            break;
        }

        system("pause");
        cout << endl;

        if (opcion == 0) {
            break;
        }
    
    return 0;
    }
}