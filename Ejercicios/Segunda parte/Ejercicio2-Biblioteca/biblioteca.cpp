#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

string libros[25][3];

void cargarlibros() {
// Arreglo con categoria y descripcion
	libros [ 0 ] [ 0 ] = " Algoritmos " ; libros [ 0 ] [ 1 ] = " Algoritmos y Programacion (Guia para docentes) " ; libros[0][2]="Pearson";
	libros [ 1 ] [ 0 ] = " Algoritmos " ; libros [ 1 ] [ 1 ] = " Apuntes de Algoritmos y Estructuras de Datos " ;libros[1][2]="Coello, Joel";
	libros [ 2 ] [ 0 ] = " Algoritmos " ; libros [ 2 ] [ 1 ] = " Breves Notas sobre Análisis de Algoritmos " ;libros[2][2]="Coello";
	libros [ 3 ] [ 0 ] = " Algoritmos " ; libros [ 3 ] [ 1 ] = " Fundamentos de Informatica y Programacion " ;libros[3][2]="Blanca Olmedo";
	libros [ 4 ] [ 0 ] = " Algoritmos " ; libros [ 4 ] [ 1 ] = " Temas selectos de estructuras de datos " ;libros[4][2]="Teresa";
	libros [ 5 ] [ 0 ] = " Algoritmos " ; libros [ 5 ] [ 1 ] = " Teoria sintactico-gramatical de objetos " ;libros[5][2]="Bessy";
	libros [ 6 ] [ 0 ] = " Base de Datos " ; libros [ 6 ] [ 1 ] = " Apuntes de Base de Datos 1 " ;libros[6][2]="Teresa, Kenji";
	libros [ 7 ] [ 0 ] = " Base de Datos " ; libros [ 7 ] [ 1 ] = " Base de Datos (2005) " ;libros[7][2]="Alvaro Sosa";
	libros [ 8 ] [ 0 ] = " Base de Datos " ; libros [ 8 ] [ 1 ] = " Base de Datos (2011) " ;libros[8][2]="Maria auxiliadora";
	libros [ 9 ] [ 0 ] = " Base de Datos " ; libros [ 9 ] [ 1 ] = " Base de Datos Avanzadas (2013) " ;libros[9][2]="Isaac";
	libros [ 10 ] [ 0 ] = " Base de Datos " ; libros [ 10 ] [ 1 ] = " Diseño Conceptual de Bases de Datos " ;libros[10][2]="Pedro Sosa";
	libros [ 11 ] [ 0 ] = " Ciencia Computacional " ; libros [ 11 ] [ 1 ] = " Breves Notas sobre Automatas y Lenguajes " ;libros[11][2]="Marlon Padilla";
	libros [ 12 ] [ 0 ] = " Ciencia Computacional " ; libros [ 12 ] [ 1 ] = " Breves Notas sobre Teoria de la Computación " ;libros[12][2]="Blanca, Pearson";
	libros [ 13 ] [ 0 ] = " Metodologias de desarrollo de software " ; libros [ 13 ] [ 1 ] = " Compendio de Ingenieria del Software " ;libros[13][2]="Olmedo, Adolfo";
	libros [ 14 ] [ 0 ] = " Metodologias de desarrollo de software " ; libros [ 14 ] [ 1 ] = " Diseno agil con TDD " ;libros[14][2]="Samandra A.";
	libros [ 15 ] [ 0 ] = " Metodologias de desarrollo de software " ; libros [ 15 ] [ 1 ] = " Ingeniería de Software: Una Guía para Crear Sistemas de Información " ;libros[15][2]="Alberto Tinoco";
	libros [ 16 ] [ 0 ] = " Metodologias de desarrollo de software " ; libros [ 16 ] [ 1 ] = " Scrum & Extreme Programming (para programadores) " ;libros[16][2]="William Stark";
	libros [ 17 ] [ 0 ] = " Metodologias de desarrollo de software " ; libros [ 17 ] [ 1 ] = " Scrum y XP desde las trincheras " ;libros[17][2]="Andres de la Mancha";
	libros [ 18 ] [ 0 ] = " Miscelaneos " ; libros [ 18 ] [ 1 ] = " 97 cosas que todo programador deberia saber " ;libros[18][2]="Andrea Gutierrez";
	libros [ 19 ] [ 0 ] = " Miscelaneos " ; libros [ 19 ] [ 1 ] = " Docker " ;libros[19][2]="Almendares Sosa";
	libros [ 20 ] [ 0 ] = " Miscelaneos " ; libros [ 20 ] [ 1 ] = " El camino a un mejor programador " ;libros[20][2]="Alberta Moncada";
	libros [ 21 ] [ 0 ] = " Miscelaneos " ; libros [ 21 ] [ 1 ] = " Introduccion a Docker " ;libros[21][2]="Arturo Albergue";
	libros [ 22 ] [ 0 ] = " Miscelaneos " ; libros [ 22 ] [ 1 ] = " Programación de videojuegos SDL " ;libros[22][2]="Jacinto Bueso";
	libros [ 23 ] [ 0 ] = " PHP " ; libros [ 23 ] [ 1 ] = " Manual de estudio introductorio al lenguaje PHP procedimental " ;libros[23][2]="Xiomara Zelaya, Mel Zelaya";
	libros [ 24 ] [ 0 ] = " PHP " ; libros [ 24 ] [ 1 ] = " PHP y Programación orientada a objetos " ;libros[24][2]="Agustin Mejia, Andrea";
}


int main(int argc, char const *argv[])
{
    cargarlibros();
    
    srand (time(NULL));

    bool salir = false;

    while (salir == false) 
    {
      string buscar = "";
      system("cls");
      cout << "Ingrese la descripcion del libro que busca: ";
      cin >> buscar;

      // busqueda
      for (int i = 0; i < 25; i++)
      {
          string libro = libros[i][1];
          string libroEnminuscula = libro;
          string autor = libros [i][2];
          string autorEnminuscula = autor;
          //Tranformando a minuscula los string buscar y libro
          transform(libroEnminuscula.begin(),libroEnminuscula.end(),libroEnminuscula.begin(), ::tolower);
          transform(autorEnminuscula.begin(),autorEnminuscula.end(),autorEnminuscula.begin(), ::tolower);
          transform(buscar.begin(),buscar.end(),buscar.begin(), ::tolower);          


          if (libroEnminuscula.find(buscar) != string::npos || autorEnminuscula.find(buscar) != string::npos ) {
              cout << "Libro encontrado: " << libro << endl;
              cout << "Autor(es): " << autor << endl;

              cout << "Tambien te sugerimos estos libros: " << endl;

              int sugerencia1 = rand() % 38 + 1;
              int sugerencia2 = rand() % 38 + 1;
              int sugerencia3 = rand() % 38 + 1;

              cout << "Sugerencia 1: " << libros[sugerencia1][1] << endl;
              cout << "Sugerencia 2: " << libros[sugerencia2][1] << endl;
              cout << "Sugerencia 3: " << libros[sugerencia3][1] << endl;
              
              salir = true;  
              break;          
          }
      }
      
      if (salir == false){
          char continuar = 'n';
          while (true) {
              system ("cls");
              cout << "No se encontro ningun libro. Desea continuar? s/n ";
              cin >> continuar;

              if (continuar == 's' || continuar == 'S'){
                  break;
              } else if (continuar == 'n' || continuar == 'N' ) {
                  salir = true;
                  break;
              }
              
          }
          
      }

    }
    
    return 0;
}
