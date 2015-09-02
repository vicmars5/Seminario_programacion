#include <iostream>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Servicios.h"

using namespace std;


Servicios servicios;
Productos productos;

int main()
{
	system("cls");
    int opcion;

	cout
	<< "    SPA"
	<< "\n1.-Productos"
	<< "\n2.-Servicios"
	<< "\n0.-Salir"
	<< "\n"
	<< "\nOpcion:";
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
