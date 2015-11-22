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
		void Modificar();
		void Buscar();
		bool ObtenerRegistro(int busqueda);
		void Menu();
		int CantidadRegistros();
		int obtenerFila(string cadena);
};

//Masajistas masajistas[20];
//Manejador manejador;
const string NOMBRE_ARCHIVO="masajistas.txt";
const int MAX_REGISTROS=20;

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

bool Masajistas::ObtenerRegistro(int busqueda){
    int cont=0;
    string cadena;
    bool existe;
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
                    break;
                }
                cont ++;
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
			cout << "Registros en BD " << CantidadRegistros() << endl << endl;
			for (int x=0 ; x<cant ; x++){
				fflush(stdin);
				cout << "Codigo: ";
				cin>>id_masajista;

				fflush(stdin);
				cout << "Nombre: ";
				getline(cin, nombre);

				fflush(stdin);
				cout << "Edad: ";
				cin >> edad;

				fflush(stdin);
				cout << "Especialidad: ";
				getline(cin, especialidad);

				cout << endl;
				archivo << id_masajista << "\t" << nombre << "\t" << edad << "\t" << especialidad << endl;

			}
			archivo.close();
			cout << "Se guardo exitosamente";
		} else {
			cout << "ERROR 404, document not found :v";
            getch();
		}
	} else {
		cout << "La base datos esta llena, no caben los registros requeridos";
		getch();
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
	}
	if(cont==1) {
		cout << "Archivo vacio" << endl;
	}
	getch();
}

void Masajistas::Modificar(){
	system("cls");
	int busqueda, cont=1;
	string cadena, info_archivo="";
	bool existe=false;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;

	ifstream archivo("masajistas.txt", ios::in);
	ofstream nuevoArchivo("masajistas_new.txt", ios::app);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);
                if (id_masajista == busqueda){
                	int opcion;
                    cout << endl << "Codigo: " << id_masajista;
                    cout << endl << "1.-Nombre: " << nombre;
                    cout << endl << "2.-Edad: " << edad;
                    cout << endl << "3.-Especialidad: " << especialidad;
                    cout << endl;
                    cout << "Seleccione la opcion que desea modificar";
                    cin >> opcion;
                    fflush(stdin);
                    switch (opcion) {
                    	case 1:
                    		cout << endl << "Nombre: ";
                    		getline(cin, nombre);
                    		break;
                    	case 2:
                    		cout << endl << "Edad: ";
                    		cin >> edad;
                    		break;
                    	case 3:
                    		cout << endl << "Especialidad: ";
                    		getline(cin, especialidad);
                    		break;
                    }
                    existe=true;
                }
                nuevoArchivo << id_masajista << "\t" << nombre << "\t" << edad << "\t" << especialidad << "\n";
                cont ++;
			}
            archivo.close();
            nuevoArchivo.close();
			if(existe){
                remove("masajistas.txt");
                rename("masajistas_new.txt","masajistas.txt");
                ObtenerRegistro(busqueda);
			} else {
                cout << "NO SE ENCONTRO REGISTRO";
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
			<< endl << "4.-Modificar"
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
		if(opcion == 4){
            Modificar();
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
		return cant_registros-1;
	} else {
		return 0;
	}
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
