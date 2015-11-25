#include <iostream>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Servicios.h"
#include "Masajistas.h"
#include "Clientes.h"
#include "NotaVenta.h"

using namespace std;

const int CANTIDAD=2;
Servicios servicios;
Productos productos;
Masajistas masajistas;
Clientes clientes;
NotaVenta notaVenta;

int main()
{
	system("clear");
    int opcion,x;
    string busqueda;
    bool repetir=true;

    while(repetir){
        system("clear");
        cout
        << endl <<"    SPA"
        << endl << "1.-Productos"
        << endl << "2.-Servicios"
        << endl << "3.-Masajistas"
        << endl << "4.-Clientes"
        << endl << "5.-Nota de venta"
        << endl << "0.-Salir"
        << endl
        << endl << "Opcion:";
        cin>>opcion;

        if (opcion==1){
            productos.Menu();
        }
        if (opcion==2){
            servicios.Menu();
        }
        if (opcion==3){
        	masajistas.Menu();
        }
        if (opcion==4){
            clientes.Menu();
        }
        if (opcion==5){
            notaVenta.Menu();
        }
        if(opcion==0){
            repetir=false;
            system("exit");
        }
	}
	return 0;
}
