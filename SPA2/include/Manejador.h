#ifndef MANEJADOR_H
#define MANEJADOR_H

#include <fstream>
#include <stdio.h>

#include <Clientes.h>
#include <Servicios.h>
#include <Productos.h>
#include <Masajistas.h>

using namespace std;

class Manejador
{
	public:
	void Guardar();

	void GuardarClientes();
	void LeerClientes();

	void GuardarProductos();
	void LeerProductos();

	void GuardarServicios();
	void LeerServicios();

	void Leer();

    Masajistas masajistas;
    Clientes clientes[2];
    Servicios servicios[2];
    Productos productos[2];
};

void Manejador::Guardar(){
	ofstream archivo;
	string frase;

	fflush(stdin);
	cout << "Hola. Expresate :3";
	getline(cin, frase);

    archivo.open("datos.txt");
	if(archivo.is_open()){
		archivo << frase;
		archivo.close();
	} else {
		cout << "NO SE GUARDO EL ARCHIVO" << endl;
	}
}

void Manejador::GuardarClientes(){
    ofstream archivo;
    archivo.open("clientes.txt", ios::out);//app permite que se ñaada el registr despues
    for(int cont=0; cont < 2; cont++){
        if(archivo.is_open()){
            archivo << clientes[cont].id_cliente << " " << clientes[cont].nombre << " "
                << clientes[cont].tel[0] << " " << clientes[cont].tel[1] << " " << clientes[cont].tel[2]
                << " " << clientes[cont].correo << endl;
        } else {
            cout << "NO SE GUARDO EL ARCHIVO"  << endl;
        }
    }
    cout << clientes[0].id_cliente;

    getch();
}

void Manejador::LeerClientes(){

    int cont=0;

    ifstream archivo("clientes.txt", ios::in);
    if(archivo.is_open()){
            archivo>> clientes[cont].id_cliente;
            while(!archivo.eof()){
                archivo >> clientes[cont].nombre >> clientes[cont].tel[0] >> clientes[cont].tel[1] >> clientes[cont].tel[2] >> clientes[cont].correo;
                cont++;
                archivo>> clientes[cont].id_cliente;
            }
    }
}

void Manejador::GuardarProductos(){
    ofstream archivo;
    archivo.open("productos.txt", ios::out);//app permite que se ñaada el registr despues
    for(int cont=0; cont < 2; cont++){
        if(archivo.is_open()){
            archivo << productos[cont].id_producto << " " << productos[cont].nombre << " " << productos[cont].descripcion << " " << productos[cont].precio << endl;
        } else {
            cout << "NO SE GUARDO EL ARCHIVO"  << endl;
        }
    }
    cout << productos[0].id_producto;
    getch();
}

void Manejador::LeerProductos(){

    int cont=0;

    ifstream archivo("productos.txt", ios::in);
    if(archivo.is_open()){
            archivo>> productos[cont].id_producto;
            while(!archivo.eof()){
                archivo >> productos[cont].nombre >> productos[cont].descripcion >> productos[cont].precio;;
                cont++;
                archivo>> productos[cont].id_producto;
            }
    } else{
        cout << "NO SE PUDO LEER EL ARCHIVO";
    }
}

void Manejador::GuardarServicios(){
    ofstream archivo;
    archivo.open("servicios.txt", ios::out);//app permite que se ñaada el registr despues
    for(int cont=0; cont < 2; cont++){
        if(archivo.is_open()){
            archivo << servicios[cont].codigo << " " << servicios[cont].descripcion << " " << servicios[cont].precio_maximo << " " << servicios[cont].precio_minimo << endl;
        } else {
            cout << "NO SE GUARDO EL ARCHIVO"  << endl;
        }
    }
    cout << servicios[0].codigo;
}

void Manejador::LeerServicios(){

    int cont=0;

    ifstream archivo("servicios.txt", ios::in);
    if(archivo.is_open()){
            archivo>> servicios[cont].codigo;
            while(!archivo.eof()){
                archivo >> servicios[cont].descripcion >> servicios[cont].precio_maximo >> servicios[cont].precio_minimo;
                cont++;
                archivo>> servicios[cont].codigo;
            }
    } else{
        cout << "NO SE PUDO LEER EL ARCHIVO";
    }
}

void Manejador::Leer(){
	string linea;
	ifstream archivo("datos.txt");
    if(archivo.is_open()){
    	//Mientras que no sea fin de archivo
    	while (! archivo.eof()){
    		getline(archivo, linea);
    		cout << linea << endl;
    	}
    	archivo.close();
    }
}
#endif // MANEJADOR_H
