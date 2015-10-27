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

		//metodos de clases
	public:
		void Capturar();
		void Mostrar();
		void Buscar();
		void Menu();
		int Leer();
};

void Productos::Capturar()
{
	fflush(stdin);
	system("cls");

	cout << "\nIntroduce el identififcador del producto: " << endl;
	getline(cin, id_producto);

	cout << "\nNombre del producto: " << endl;
	getline(cin, nombre);

	cout << "\nDescripcion del producto: " << endl;
	getline(cin, descripcion);

	cout << "\nPrecio del producto: " << endl;
	cin >> precio;
}

void Productos::Mostrar(){
	cout << "\nIdentificador: " << id_producto;
	cout << "\nNombre: " << nombre;
	cout << "\nDescripcion: " << descripcion;
	cout << "\nPrecio: " << precio;
    cout << endl;
    getch();
}

void Productos::Buscar(){
	system("cls");
	string busqueda;
	cout << "Escriba el identificador del producto que desea buscar: ";
	cin >> busqueda;
	if (id_producto == busqueda){
		Mostrar();
	} else {
		cout << "No existe";
		getch();
	}
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
