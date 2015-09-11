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
Servicios servicios;
Productos productos;
Masajistas masajistas;
Clientes clientes;

int main()
{
	system("cls");
    int opcion;

    system("color 3");

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
    	/*productos.Capturar();
        productos.Mostrar();
        productos.Buscar();*/
    }
    if (opcion==2){
        servicios.Menu();


        /*servicios.Capturar();
        servicios.Buscar();
        servicios.Mostrar();*/
    }
    if (opcion==3){
    	masajistas.Menu();
    }
    if (opcion==4){
    	clientes.Menu();
    }
    if(opcion==0){
        system("exit");
    }
	/*switch (opcion){
		case 1:
		    productos.Capturar();
		    productos.Mostrar();
		break;

		case 2:
			servicios.Capturar();
			servicios.Mostrar();
			servicios.Buscar();
		break;
	}*/
	return 0;
}
