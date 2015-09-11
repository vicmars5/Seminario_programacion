#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Clientes
{
	public:
		//Atributos de clase
		int tel[3], id_cliente;
		string nombre, correo;

		//metodos de clases
	public:
		void Capturar();
		void Mostrar();
		void Buscar();
		void Menu();
};

void Clientes::Capturar(){

	fflush(stdin);
	cout << endl << "Codigo: " << endl;
	cin>>id_cliente;

	fflush(stdin);
	cout << endl << "Nombre: " << endl;
	getline(cin, nombre);

	fflush(stdin);
	cout << endl << "Telefono 1: " << endl;
	cin >> tel[0];

	fflush(stdin);
	cout << endl << "Telefono 2: " << endl;
	cin >> tel[1];

	fflush(stdin);
	cout << endl << "Telefono 3: " << endl;
	cin >> tel[2];

	fflush(stdin);
	cout << endl << "Correo: " << endl;
	getline(cin, correo);

}

void Clientes::Mostrar(){
	system("cls");

	cout << endl << "Codigo: " << id_cliente ;
	cout << endl << "identificador: " << nombre;
	cout << endl << "Telefono 1: " << tel[0];
	cout << endl << "Telefono 2: " << tel[1];
	cout << endl << "Telefono 3: " << tel[2];
	cout << endl << "Correo: " << correo;

	getch();
}

void Clientes::Buscar(){
	system("cls");
	int busqueda;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;
	if (id_cliente == busqueda){
		Mostrar();
	} else {
		cout << "No existe";
		getch();
	}
}
void Clientes::Menu(){
	bool repetir=true;
	int opcion;

	do{
		system("cls");
		fflush(stdin);

		cout << "   Clientes"
			<< endl << "1.-Capturar"
			<< endl << "2.-Mostrar"
			<< endl << "3.-Buscar"
			<< endl << "4.-Salir"
			<< endl << "Opcion: ";
		cin >> opcion;

		if(opcion == 1){
			Capturar();
		}
		if(opcion == 2){
			Mostrar();
		}
		if(opcion == 3){
			Buscar();
		}
		if(opcion == 4){
			repetir=false;
		}
	}while (repetir);
}
#endif
