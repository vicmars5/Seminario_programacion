#include <iostream>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Servicios.h"
#include "Masajistas.h"
#include "Clientes.h"
using namespace std;

/*
	*Arreglos
	*Manejo de archivos
		->Debras guardar los datos capturados en un archivo .txt y ahí sera donde captures los registros
*/
/* Si no esta definida la carpeta win 32
ifdef WIN32
	#define CLEAR() system('cls')
#else
	#define CLEAR() system('clear')
#endif

*/
const int CANTIDAD=2;
Servicios servicios;
Productos productos;
Masajistas masajistas;
Clientes clientes;

int main()
{
	system("cls");
    int opcion,x;
    string busqueda;
    bool repetir=true;

    system("color 3");
    while(repetir){
        system("cls");
        cout
        << endl <<"    SPA"
        << endl << "1.-Productos"
        << endl << "2.-Servicios"
        << endl << "3.-Masajistas"
        << endl << "4.-Clientes"
        << endl << "0.-Salir"
        << endl
        << endl << "Opcion:";
        cin>>opcion;

        if (opcion==1){
            productos.Menu();
        }
        if (opcion==2){
        }
        if (opcion==3){
        	masajistas.Menu();
        }
        if (opcion==4){
        }
        if (opcion==5){
        }
        if(opcion==0){
            repetir=false;
            system("exit");
        }
	}
	return 0;
}
