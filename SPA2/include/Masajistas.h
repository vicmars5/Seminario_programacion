#ifndef MASAJISTAS_H
#define MASAJISTAS_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Masajistas
{
	public:
		//Atributos de clase
		int id_masajista, edad;
		string nombre, especialidad;

		//metodos de clases
	public:
		void Capturar();
		void Mostrar();
		void Buscar();
		void Menu();
};

void Masajistas::Buscar(){
	system("cls");
	int busqueda;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;
	if (id_masajista == busqueda){
		Mostrar();
	} else {
		cout << "No existe";
		getch();
	}
}

void Masajistas::Capturar(){

    fflush(stdin);
    cout << endl << "Codigo: " << endl;
    cin>>id_masajista;

    fflush(stdin);
    cout << endl << "Nombre: " << endl;
    getline(cin, nombre);

    fflush(stdin);
    cout << endl << "Edad: " << endl;
    cin >> edad;

    fflush(stdin);
    cout << endl << "Especialidad: " << endl;
    getline(cin, especialidad);

}

void Masajistas::Mostrar(){
    system("cls");

    cout << endl << "Codigo: " << id_masajista ;

    cout << endl << "Nombre: " << nombre;
    cout << endl << "Edad: " << edad;
    cout << endl << "Especialidad: " << especialidad;

    getch();
}

void Masajistas::Menu(){
    bool repetir=true;
    int opcion;

    do{
        system("cls");
        fflush(stdin);

        cout << "   Masajistas"
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
