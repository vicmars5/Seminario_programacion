#include <iostream>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Servicios.h"

using namespace std;

int main()
{
    Servicios servicios;
    Productos productos;
	int opcion;

	cout
	<< "\nProductos: 1"
	<< "\nServicios: 2"
	<< "\nSalir: 0"
	<< "\n"
	<< "\nEscribe el numero de la opcion que elijas";
    cin>>opcion;

	switch (opcion){
		case 1:
		    productos.Capturar();
		    productos.Mostrar();
		break;

		case 2:
			servicios.Capturar();
			servicios.Mostrar();
		break;
	}
		return 0;
}
