#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Clientes
{
	public:
		//Atributos de clase
		int id_cliente;
		string nombre, correo, tel[3];

		//metodos de clases
	public:
		void Capturar();
		void Mostrar();
		void Buscar();
		void Menu();
		void Modificar();
		void obtenerFila(string cadena);
		void ObtenerRegistro(int busqueda);
		int CantidadRegistros();
		string nombreCliente(string busqueda);
};

string Clientes::nombreCliente(string busqueda){
	int cont=1;
	string cadena;
	bool existe=false;

	ifstream archivo("clientes.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);

                if (id_cliente == atoi(busqueda.c_str())){
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
int Clientes::CantidadRegistros(){
	string linea;
	int cant_registros=0;
	ifstream archivo("clientes.txt");
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


void Clientes::Capturar(){
	int cant;
	cout << "\t Cuantos clientes desea ingresar?";
	cin >> cant;
	cin.ignore();

	if(cant <= (MAX_REGISTROS-CantidadRegistros())){
		ofstream archivo;
		archivo.open("clientes.txt", ios::app);
		if(archivo.is_open()){
			cout << "Registros en BD " << CantidadRegistros() << endl << endl;
			for (int x=0 ; x<cant ; x++){
				cout << endl << "Codigo: " << endl;
				cin>>id_cliente;
				cin.ignore();

				cout << endl << "Nombre: " << endl;
				getline(cin, nombre);

				cout << endl << "Telefono casa: " << endl;
				getline(cin, tel[0]);

				cout << endl << "Telefono celular: " << endl;
				getline(cin, tel[1]);

				cout << endl << "Telefono trabajo: " << endl;
				getline(cin, tel[2]);

				cout << endl << "Correo: " << endl;
				getline(cin, correo);

				cout << endl;
				archivo << id_cliente << "\t" << nombre << "\t" << tel[0] << "\t" << tel[1] << "\t" << tel[2] << "\t" << correo << endl;

			}
			archivo.close();
			cout << "Se guardo exitosamente";
		} else {
			cout << "ERROR 404, document not found :v";
            cin.get();
		}
	} else {
		cout << "La base datos esta llena, no caben los registros requeridos";
		cin.ignore();
		cin.get();
	}


}

void Clientes::Mostrar(){
	int cont=1;
	string cadena;
	ifstream archivo("clientes.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);
                cout << endl << "Codigo: " << id_cliente;
                cout << endl << "Nombre: " << nombre;
                cout << endl << "Telefono casa: " << tel[0];
                cout << endl << "Telefono celular: " << tel[1];
                cout << endl << "Telefono trabajo: " << tel[2];
                cout << endl << "Correo: " << correo;
                cout << endl;

                cont ++;
			}
	}
	if(cont==1) {
		cout << "Archivo vacio" << endl;
	}
	cin.get();
}

void Clientes::obtenerFila(string cadena){
    string texto;
    int posicion;
    posicion = cadena.find_last_of("\t");
	if (posicion != -1){
		texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
		cadena.erase(posicion, cadena.length()-posicion+1);
		correo=texto;
		posicion = cadena.find_last_of("\t");
	}

		if(posicion != -1){
			texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
			tel[2] = atoi(texto.c_str());
			cadena.erase(posicion, cadena.length()-posicion+1);
			posicion =  cadena.find_last_of("\t");

			if(posicion != -1){
				texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
				tel[1] = atoi(texto.c_str());
				cadena.erase(posicion, cadena.length()-posicion+1);
				posicion =  cadena.find_last_of("\t");

				if(posicion != -1){
					texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
					tel[0] = atoi(texto.c_str());
					cadena.erase(posicion, cadena.length()-posicion+1);
					posicion =  cadena.find_last_of("\t");

					if(posicion != -1){
						texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
						nombre = texto.c_str();
						cadena.erase(posicion, cadena.length()-posicion+1);
						id_cliente = atoi(cadena.c_str());
					}
				}
			}
		}
}
/*
void Clientes::Buscar(){
	system("clear");
	int busqueda;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;
	cin.ignore();
	if (id_cliente == busqueda){
		Mostrar();
	} else {
		cout << "No existe";
		cin.get();
	}
}*/
void Clientes::Buscar(){
	system("clear");
	int busqueda, cont=1;
	string cadena;
	bool existe=false;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;

	ifstream archivo("clientes.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);

                if (id_cliente == busqueda){
	                cout << endl << "Codigo: " << id_cliente;
	                cout << endl << "Nombre: " << nombre;
	                cout << endl << "Telefono casa: " << tel[0];
	                cout << endl << "Telefono celular: " << tel[1];
	                cout << endl << "Telefono trabajo: " << tel[2];
	                cout << endl << "Correo: " << correo;
	                cout << endl;
                    existe=true;
                }
                cont ++;
			}
			if(existe==false){
                cout << "NO SE ENCONTRO REGISTRO";
			}
			cin.ignore();
			cin.get();
	}
}
void Clientes::Modificar(){
	system("clear");
	int busqueda, cont=1;
	string cadena, info_archivo="";
	bool existe=false;
	cout << "Escriba el identificador del cliente que desea buscar: ";
	cin >> busqueda;
	cin.ignore();

	ifstream archivo("clientes.txt", ios::in);
	ofstream nuevoArchivo("clientes_new.txt", ios::app);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);
                if (id_cliente == busqueda){
                	int opcion;
                    cout << endl << "Codigo: " << id_cliente;
                    cout << endl << "1.-Nombre: " << nombre;
                    cout << endl << "2.-Telefono casa: " << tel[0];
                    cout << endl << "3.-Telefono celular: " << tel[1];
                    cout << endl << "4.-Telefono trabajo: " << tel[2];
                    cout << endl << "5.-Correo: " << correo;
                    cout << endl;
                    cout << "Seleccione la opcion que desea modificar";
                    cin >> opcion;
                    cin.ignore();
                    switch (opcion) {
                    	case 1:
							cout << endl << "Nombre: " << endl;
							getline(cin, nombre);
							break;
						case 2:
							cout << endl << "Telefono casa: " << endl;
							getline(cin, tel[0]);
							break;
						case 3:
							cout << endl << "Telefono celular: " << endl;
							getline(cin, tel[1]);
							break;
						case 4:
							cout << endl << "Telefono trabajo: " << endl;
							getline(cin, tel[2]);
							break;
						case 5:
							cout << endl << "Correo: " << endl;
							getline(cin, correo);
                    		break;
                    }
                    existe=true;
                }
				nuevoArchivo << id_cliente << "\t" << nombre << "\t" << tel[0] << "\t" << tel[1] << "\t" << tel[2] << "\t" << correo << endl;
                cont ++;
			}
            archivo.close();
            nuevoArchivo.close();
			if(existe){
                remove("clientes.txt");
                rename("clientes_new.txt","clientes.txt");
                ObtenerRegistro(busqueda);
			} else {
                cout << "NO SE ENCONTRO REGISTRO";
			}
	}
}
void Clientes::ObtenerRegistro(int busqueda){
    int cont=0;
    string cadena;
    ifstream archivo("clientes.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                obtenerFila(cadena);

                if (id_cliente== busqueda){
	                cout << endl << "Codigo: " << id_cliente;
	                cout << endl << "Nombre: " << nombre;
	                cout << endl << "Telefono casa: " << tel[0];
	                cout << endl << "Telefono celular: " << tel[1];
	                cout << endl << "Telefono trabajo: " << tel[2];
	                cout << endl << "Correo: " << correo;
	                cout << endl;
                    break;
                }
                cont ++;
			}
			cin.get();
	}
}
void Clientes::Menu(){
	bool repetir=true;
	int opcion;

	do{
		system("clear");

		cout << "   Clientes"
			<< endl << "1.-Capturar"
			<< endl << "2.-Mostrar"
			<< endl << "3.-Buscar"
			<< endl << "4.-Modificar"
			<< endl << "0.-Salir"
			<< endl << "Opcion: ";
		cin >> opcion;
		cin.ignore();

		if(opcion == 1){
			Capturar();
		}
		else{
            if(opcion == 2){
                Mostrar();
            }
            else{
                if(opcion == 3){
                    Buscar();
                }
                else{
                	if(opcion == 4){
                		Modificar();
                	}
                	else{
	                    if(opcion == 0){
	                        repetir=false;
	                    }
                	}
                }
            }
        }
	}while (repetir);
}
#endif
