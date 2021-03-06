#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Productos
{
	public:
		//Atributos de clase
		string  id_producto, nombre, descripcion;
		float precio;
		int cont, registros=0;

		//metodos de clases
	public:
		void Capturar();
		void Mostrar();
		void MostrarProducto(int id);
		void Buscar();
		void Menu();
		void Modificar();
		int Leer();
};
Productos producto[20];
void Productos::Capturar()
{
	int cantIngresar;
	fflush(stdin);
	system("cls");
	cout << "\nCuantos productos deseas ingresar? ";
	cin >> cantIngresar;
    cout << endl;

	if((cantIngresar+registros)<=20){
	    for(cont=registros; cont<(cantIngresar+registros); cont++){
			fflush(stdin);
	        cout << "Introduce el identififcador del producto: ";
	        getline(cin, producto[cont].id_producto);
	        cout << "Nombre del producto: ";
	        getline(cin, producto[cont].nombre);
	        cout << "Descripcion del producto: ";
	        getline(cin, producto[cont].descripcion);
			fflush(stdin);
	        cout << "Precio del producto: ";
	        cin >> producto[cont].precio;
	        cout << endl;
	    }
	    registros=cont;
	    cout << "Registros en base de datos " << registros << endl;
	} else {
		cout << "Has registrado el maximo de productos" << endl;
	}
    getch();
}

void Productos::Modificar(){
	system("cls");
	string busqueda;
	int opcion;
	cout << "Escriba el identificador del producto que desea buscar: ";
	cin >> busqueda;
	for(cont=0; cont<registros; cont++){
        if (producto[cont].id_producto == busqueda){
            MostrarProducto(cont);

			cout << "Identificador: " << producto[cont].id_producto << endl;
            cout << "1.-Nombre: " << producto[cont].nombre << endl;
            cout << "2.-Descripcion: " << producto[cont].descripcion << endl;
            cout << "3.-Precio: " << producto[cont].precio << endl;
            cout << endl;
            cout << "Seleccione la opcion que desea modificar: ";
            cin >> opcion;
            cout << endl;
            fflush(stdin);
            switch (opcion) {
                case 1:
                    cout << "Nombre: ";
                    getline(cin, producto[cont].nombre);
                    break;
                case 2:
                    cout << "Descripcion: ";
                    getline(cin, producto[cont].descripcion);
                    break;
                case 3:
                    cout << "Precio: ";
                    cin >> producto[cont].precio;
                    break;
            }
            MostrarProducto(cont);
            break;
        }
	}
	if(cont==registros){
        cout << "No se encontro el producto" << endl;
	}
    getch();
}

void Productos::Mostrar(){
	system("cls");
	for(cont=0; cont<registros; cont++){
		MostrarProducto(cont);
	}
    getch();
}

void Productos::MostrarProducto(int id){
		cout << "\nIdentificador: " << producto[id].id_producto;
		cout << "\nNombre: " << producto[id].nombre;
		cout << "\nDescripcion: " << producto[id].descripcion;
		cout << "\nPrecio: " << producto[id].precio;
	    cout << endl;
}

void Productos::Buscar(){
	system("cls");
	string busqueda;
	cout << "Escriba el identificador del producto que desea buscar: ";
	cin >> busqueda;
	for(cont=0; cont<registros; cont++){
        if (producto[cont].id_producto == busqueda){
            MostrarProducto(cont);
            break;
        }
	}
	if(cont==registros){
        cout << "No se encontro" << endl;
	}
    getch();
}

void Productos::Menu(){
	bool repetir=true;
	int opcion;
	while(repetir){
		system("cls");
		fflush(stdin);

		cout << "   Productos"
			<< endl << "1.-Capturar"
			<< endl << "2.-Mostrar"
			<< endl << "3.-Buscar"
			<< endl << "4.-Modificar"
			<< endl << "0.-Salir"
			<< endl << "Opcion: ";
		cin >> opcion;

		switch(opcion){
			case 1:
				Capturar();
                break;
			case 2:
				Mostrar();
                break;
			case 3:
				Buscar();
                break;
			case 4:
                Modificar();
                break;
			case 0:
				repetir=false;
                break;

		}
	}
}


int Productos::Leer(){
	string linea;
	int cant_registros=0;
	ifstream archivo("datos.txt");
    if(archivo.is_open()){
    	//Mientras que no sea fin de archivo
    	while (! archivo.eof()){
    		getline(archivo, linea);
    		cant_registros++;
    	}
    	archivo.close();
    }
    return cant_registros;
}

#endif // PRODUCTOS_H
