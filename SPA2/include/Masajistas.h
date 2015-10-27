#ifndef MASAJISTAS_H
#define MASAJISTAS_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//#include <Masajistas.h>
//#include <Manejador.h>

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
		int CantidadRegistros();
		int obtenerFila(string cadena);
};

//Masajistas masajistas[10];
//Manejador manejador;
const string NOMBRE_ARCHIVO="masajistas.txt";
const int MAX_REGISTROS=10;

void Masajistas::Buscar(){
	system("cls");
	int busqueda, cont=1;
	string cadena;
	bool existe=false;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;

	ifstream archivo("masajistas.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);

                if (id_masajista == busqueda){
                    cout << endl << "Codigo: " << id_masajista;
                    cout << endl << "Nombre: " << nombre;
                    cout << endl << "Edad: " << edad;
                    cout << endl << "Especialidad: " << especialidad;
                    cout << endl;
                    existe=true;
                }
                cont ++;
			}
			if(existe==false){
                cout << "NO SE ENCONTRO REGISTRO";
			}
			getch();
	}
}

void Masajistas::Capturar(){
	int cant;
	cout << "\t Cuantos masajistas desea ingresar?";
	cin >> cant;

	if(cant <= (MAX_REGISTROS-CantidadRegistros())){
		ofstream archivo;
		archivo.open("masajistas.txt", ios::app);
		if(archivo.is_open()){
			cout << "Registros en BD " << CantidadRegistros() << endl;
			for (int x=0 ; x<cant ; x++){
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

				archivo << id_masajista << "\t" << nombre << "\t" << edad << "\t" << especialidad << endl;

			}
			archivo.close();
			cout << "Se guardo exitosamente";
		} else {
			cout << "ERROR 404, document not found :v";
		}
	} else {
		cout << "La bade datos esta llena, no caben los registros requeridos";
	}


}

void Masajistas::Mostrar(){
	int cont=1;
	string cadena;
	ifstream archivo("masajistas.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);
                cout << endl << "Codigo: " << id_masajista;
                cout << endl << "Nombre: " << nombre;
                cout << endl << "Edad: " << edad;
                cout << endl << "Especialidad: " << especialidad;
                cout << endl;

                cont ++;
			}
			getch();
	}
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
			<< endl << "0.-Salir"
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
		if(opcion == 0){
			repetir=false;
		}
	}while (repetir);
}

int Masajistas::CantidadRegistros(){
	string linea;
	int cant_registros=0;
	ifstream archivo("masajistas.txt");
	if(archivo.is_open()){
		//Mientras que no sea fin de archivo
		while (! archivo.eof()){
			getline(archivo, linea);
			cant_registros++;
		}
		archivo.close();
	}
	return cant_registros-1;
}

int Masajistas::obtenerFila(string cadena){
    string texto;
    int posicion;
    posicion = cadena.find_last_of("\t");
	if (posicion != -1){
		texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
		cadena.erase(posicion, cadena.length()-posicion+1);
		especialidad=texto;
		posicion = cadena.find_last_of("\t");

		if(posicion != -1){
			texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
			edad = atoi(texto.c_str());
			cadena.erase(posicion, cadena.length()-posicion+1);
			posicion =  cadena.find_last_of("\t");

			if(posicion != -1){
				texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
				nombre = texto.c_str();
				cadena.erase(posicion, cadena.length()-posicion+1);
				id_masajista = atoi(cadena.c_str());
			}
		}
	}
	//archivo << id_masajista << "\t" << nombre << "\t" << edad << "\t" << especialidad << endl;

}
#endif
