#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

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
		bool ObtenerRegistro(int busqueda);
		void Buscar();
		void Capturar();
		void ObtenerFila(string cadena);
		void Menu();
		void Mostrar();
		void MostrarProducto(int id);
		void Modificar();
		int CantidadRegistros();
		int Leer();
		string nombreProducto(string busqueda);
		float precioProducto(string busqueda);
};
Productos producto[20];
const int MAX_REGISTROS=20;

string Productos::nombreProducto(string busqueda){
	int cont=1;
	string cadena;
	bool existe=false;

	ifstream archivo("productos.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);

                if (atoi(id_producto.c_str()) == atoi(busqueda.c_str())){
                    existe=true;
                	return nombre;
                	break;
                }
                cont ++;
			}
			if(existe==false){
                return "No existe";
			}
	}
	return "No existe";
}

float Productos::precioProducto(string busqueda){
	int cont=1;
	string cadena;
	bool existe=false;

	ifstream archivo("productos.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);

                if (atoi(id_producto.c_str()) == atoi(busqueda.c_str())){
                    existe=true;
                	return precio;
                	break;
                }
                cont ++;
			}
			if(existe==false){
                return 0;
			}
	}
	return 0;
}

int Productos::CantidadRegistros(){
	string linea;
	int cant_registros=0;
	ifstream archivo("productos.txt");
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

void Productos::Capturar(){
	int cant;
	cout << "\t Cuantos preductos desea ingresar?";
	cin >> cant;
	cin.ignore();
	if(cant <= (MAX_REGISTROS-CantidadRegistros())){
		ofstream archivo;
		archivo.open("productos.txt", ios::app);
		if(archivo.is_open()){
			cout << "Registros en BD " << CantidadRegistros() << endl << endl;
			for (int x=0 ; x<cant ; x++){
				cout << "Introduce el identififcador del producto: ";
				getline(cin, id_producto);

				cout << "Nombre del producto: ";
				getline(cin, nombre);

				cout << "Descripcion del producto: ";
				getline(cin, descripcion);

				cout << "Precio del producto: ";
				cin >> precio;
				cin.ignore();
				cout << endl;

				archivo << id_producto << "\t" << nombre << "\t" << descripcion << "\t" << precio << endl;

			}
			archivo.close();
			cout << "Se guardo exitosamente";
		} else {
			cout << "ERROR 404, document not found :v";
			cin.get();
		}
	} else {
		cout << "La base datos esta llena, no caben los registros requeridos";
		cin.get();
	}
}
void Productos::Buscar(){
    system("clear");
    int busqueda, cont=1;
    string cadena;
    bool existe=false;
    cout << "Escriba el identificador del cliente que desea buscar: ";
    cin >> busqueda;
    cin.ignore();

    if(ObtenerRegistro(busqueda)==false){
        cout << "NO SE ENCONTRO REGISTRO";
    }
    cin.get();
}

void Productos::ObtenerFila(string cadena){
	string texto;
	int posicion;
	posicion = cadena.find_last_of("\t");
	if (posicion != -1){
		texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
		cadena.erase(posicion, cadena.length()-posicion+1);
		precio=atoi(texto.c_str());
		posicion = cadena.find_last_of("\t");

		if(posicion != -1){
			texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
			descripcion = texto;
			cadena.erase(posicion, cadena.length()-posicion+1);
			posicion =  cadena.find_last_of("\t");

			if(posicion != -1){
				texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
				nombre = texto.c_str();
				cadena.erase(posicion, cadena.length()-posicion+1);
				id_producto = cadena;
			}
		}
	}

}
bool Productos::ObtenerRegistro(int busqueda){
	int cont=0;
	string cadena;
	ifstream archivo("productos.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
				getline(archivo, cadena);
				ObtenerFila(cadena);

				if (atoi(id_producto.c_str()) == busqueda){
					cout << "\nIdentificador: " << id_producto;
					cout << "\nNombre: " << nombre;
					cout << "\nDescripcion: " << descripcion;
					cout << "\nPrecio: " << precio;
					return true;

				}
				cont ++;
			}
	}
	return false;
}

void Productos::Modificar(){
	system("clear");
	int busqueda, cont=1;
	string cadena, info_archivo="";
	bool existe=false;
	cout << "Escriba el identificador del producto que desea buscar: ";
	cin >> busqueda;
	cin.ignore();

	ifstream archivo("productos.txt", ios::in);
	ofstream nuevoArchivo("productos_new.txt", ios::app);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
				getline(archivo, cadena);
				ObtenerFila(cadena);
				if (atoi(id_producto.c_str()) == busqueda){
					int opcion;
					cout << endl << "Identificador: " << id_producto;
					cout << endl << "1.-Nombre: " << nombre;
					cout << endl << "2.-Descripcion: " << descripcion;
					cout << endl << "3.-Precio: " << precio;
					cout << endl;
					cout << "Seleccione la opcion que desea modificar";
					cin >> opcion;
					cin.ignore();
					switch (opcion) {
						case 1:
							cout << endl << "Nombre: ";
							getline(cin, nombre);
							break;
						case 2:
							cout << endl << "Descripcion: ";
							getline(cin, descripcion);
							break;
						case 3:
							cout << endl << "Precio: ";
							cin >> precio;
							cin.ignore();
							break;
					}
					existe=true;
				}
				nuevoArchivo << id_producto << "\t" << nombre << "\t" << descripcion << "\t" << precio << endl;
				cont ++;
			}
			archivo.close();
			nuevoArchivo.close();
			if(existe){
				remove("productos.txt");
				rename("productos_new.txt","productos.txt");
				ObtenerRegistro(busqueda);
			} else {
				cout << "NO SE ENCONTRO REGISTRO";
			}
	}
	cin.get();
}

void Productos::Mostrar(){
	int cont=1;
	string cadena;
	ifstream archivo("productos.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
				getline(archivo, cadena);
				ObtenerFila(cadena);
				cout << "\nIdentificador: " << id_producto;
				cout << "\nNombre: " << nombre;
				cout << "\nDescripcion: " << descripcion;
				cout << "\nPrecio: " << precio;
				cout << endl;

				cont ++;
			}
	}
	if(cont==1) {
		cout << "Archivo vacio" << endl;
	}
	cin.get();
}

void Productos::MostrarProducto(int id){
		cout << "\nIdentificador: " << producto[id].id_producto;
		cout << "\nNombre: " << producto[id].nombre;
		cout << "\nDescripcion: " << producto[id].descripcion;
		cout << "\nPrecio: " << producto[id].precio;
		cout << endl;
}

void Productos::Menu(){
	bool repetir=true;
	int opcion;
	while(repetir){
		system("clear");

		cout << "   Productos"
			<< endl << "1.-Capturar"
			<< endl << "2.-Mostrar"
			<< endl << "3.-Buscar"
			<< endl << "4.-Modificar"
			<< endl << "0.-Salir"
			<< endl << "Opcion: ";
		cin >> opcion;
		cin.ignore();
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
