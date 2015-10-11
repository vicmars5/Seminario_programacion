#include <iostream>
#include <string>
#include <stdlib.h>
#include "Productos.h"
#include "Servicios.h"
#include "Masajistas.h"
#include "Clientes.h"
#include <Manejador.h>
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
Clientes clientes[2];
Manejador manejador;
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
            //productos.Menu();
            /*for (x=0 ; x<3; x++){
                system("cls");
                productos[x].Capturar();
            }
            system("cls");
            for (x=0 ; x<3; x++){
                productos[x].Mostrar();
            }*/
            productos.Menu();
            /*productos.Capturar();
            productos.Mostrar();
            productos.Buscar();*/
        }
        if (opcion==2){
            //servicios.Menu();
            /*for (x=0; x<3; x++){
                system("cls");
                servicios[x].Capturar();
            }
            for (x=0; x<3; x++){
                servicios[x].Mostrar();
            }
            cout << "Codigo del servicio que desea modificar: " << endl;
            cin >> busqueda;

            for (x=0; x<3; x++){
                if(servicios[x].codigo == busqueda){
                    servicios[x].Modificar();
                }
            }
            */
            servicios.Menu();
            /*servicios.Capturar();
            servicios.Buscar();
            servicios.Mostrar();*/
        }
        if (opcion==3){
            masajistas.Menu();
            /*
            for (x=0 ; x<3; x++){
                system("cls");
                masajistas[x].Capturar();
            }
            for (x=0 ; x<3; x++){
                masajistas[x].Mostrar();
            }*/
        }
        if (opcion==4){
            clientes[0].Mostrar();
            clientes[1].Mostrar();
            /*
            clientes[0].Menu();
            clientes[1].Menu();*/
        }
        if (opcion==5){
            manejador.clientes[0] = clientes[0];
            manejador.clientes[1] = clientes[1];
            manejador.GuardarClientes();
            //manejador.LeerClientes();
            /*
            manejador.Guardar();
            manejador.Leer();*/
        }
        if (opcion==6){

            manejador.LeerClientes();
            clientes[0] = manejador.clientes[0];
            clientes[1] = manejador.clientes[1];
            //manejador.LeerClientes();
            /*
            manejador.Guardar();
            manejador.Leer();*/
        }
        if(opcion==0){
            repetir=false;
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
	}
	return 0;
}

