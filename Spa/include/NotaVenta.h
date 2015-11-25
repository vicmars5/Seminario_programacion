#ifndef NOTAVENTA_H
#define NOTAVENTA_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "Clientes.h";
#include "Productos.h";
#include "Servicios.h";

class NotaVenta
{
	public:
		//Atributos de clase
		string id_nota, id_producto, id_cliente, id_servicio;
		string fecha;
        Clientes cli;
        Productos prod;
        Servicios serv;
		float total;
		//metodos de clases
	public:
		void Capturar();
		void Mostrar();
		void Modificar();
		void Buscar();
		bool ObtenerRegistro(int busqueda);
		void Menu();
		int CantidadRegistros();
		void ObtenerFila(string cadena);
};

void NotaVenta::Buscar(){
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

int NotaVenta::CantidadRegistros(){
	string linea;
	int cant_registros=0;
	ifstream archivo("nota_venta.txt");
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
void NotaVenta::Capturar(){
    int cant, eleccion;
	cout << "\t Cuantos notas de venta desea crear?";
	cin >> cant;
	cin.ignore();
	if(cant <= (MAX_REGISTROS-CantidadRegistros())){
		ofstream archivo;
		archivo.open("nota_venta.txt", ios::app);
		if(archivo.is_open()){
			cout << "Registros en BD " << CantidadRegistros() << endl << endl;
			for (int x=0 ; x<cant ; x++){
		        cout << "Introduce el identififcador de la nota: ";
		        getline(cin, id_nota);

		        cout << "Identificador del cliente: ";
		        getline(cin, id_cliente);

		        cout << "Ingresara un producto? 1.-si /0.-no";
		        cin >> eleccion;
		        cin.ignore();
		        if(eleccion==1){
		        	cout << "Identificador del producto: ";
		        	getline(cin, id_producto);
		        }else{
		        	id_producto='0';
		        }

		        cout << "Ingresara un servicio? 1.-si /0.-no";
		        cin >> eleccion;
		        cin.ignore();
		        if(eleccion==1){
		        	cout << "Identificador del servicio: ";
		        	getline(cin, id_servicio);
		        }else{
		        	id_servicio='0';
		        }

		        total=(serv.precioServicio(id_servicio)+prod.precioProducto(id_producto));
		        cout << endl;

				archivo << id_nota << "\t" << id_cliente << "\t" << id_producto << "\t" << id_servicio << "\t" << total << endl;

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

void NotaVenta::Mostrar(){
	int cont=1;
	string cadena;
	ifstream archivo("nota_venta.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
				getline(archivo, cadena);
				ObtenerFila(cadena);

				cout << endl << "Identificador: " << id_nota;
				cout << endl << "Cliente: " << id_cliente << "-" << cli.nombreCliente(id_cliente);
				cout << endl << "Producto: " << id_producto  << "-" << prod.nombreProducto(id_producto) << "-" << prod.precioProducto(id_producto);
				cout << endl << "Servicio: " << id_servicio << "-" << serv.nombreServicio(id_servicio) << "-" << serv.precioServicio(id_servicio);
				cout << endl << "Total: " << total;
				cout << endl;

				cont ++;
			}
	}
	if(cont==1) {
		cout << "Archivo vacio" << endl;
	}
	cin.get();
}

void NotaVenta::Menu(){
	bool repetir=true;
	int opcion;

	do{
		system("clear");

		cout << "   Nota de venta"
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

void NotaVenta::Modificar(){
	system("clear");
	int busqueda, cont=1;
	string cadena, info_archivo="";
	bool existe=false;
	cout << "Escriba el identificador de la nota de venta que desea buscar: ";
	cin >> busqueda;
	cin.ignore();

	ifstream archivo("nota_venta.txt", ios::in);
	ofstream nuevoArchivo("nota_venta_new.txt", ios::app);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
				getline(archivo, cadena);
				ObtenerFila(cadena);
				if (atoi(id_nota.c_str()) == busqueda){
					int opcion;
					cout << endl << "Identificador: " << id_nota;
					cout << endl << "1.-Cliente: " << id_cliente;
					cout << endl << "2.-Producto: " << id_producto;
					cout << endl << "3.-Servicio: " << id_servicio;
					cout << endl << "Total: " << total;
					cout << endl;
					cout << "Seleccione la opcion que desea modificar: ";
					cin >> opcion;
					cin.ignore();

					switch (opcion) {
						case 1:
							cout << endl << "Id. cliente: ";
							getline(cin, id_cliente);
							break;
						case 2:
							cout << endl << "Id. producto: ";
							getline(cin, id_producto);
                            total=(serv.precioServicio(id_servicio)+prod.precioProducto(id_producto));
							break;
						case 3:
							cout << endl << "Id. servicio: ";
							getline(cin, id_servicio);
                            total=(serv.precioServicio(id_servicio)+prod.precioProducto(id_producto));
							break;
					}
					existe=true;
				}
				nuevoArchivo << id_nota << "\t" << id_cliente << "\t" << id_producto << "\t" << id_servicio << "\t" << total << endl;
				cont ++;
			}
			archivo.close();
			nuevoArchivo.close();
			if(existe){
				remove("nota_venta.txt");
				rename("nota_venta_new.txt","nota_venta.txt");
				ObtenerRegistro(busqueda);
			} else {
				cout << "NO SE ENCONTRO REGISTRO";
			}
	}
	cin.get();
}

void NotaVenta::ObtenerFila(string cadena){
	string texto;
	int posicion;
	posicion = cadena.find_last_of("\t");
	if (posicion != -1){
		texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
		cadena.erase(posicion, cadena.length()-posicion+1);
		total=atoi(texto.c_str());
		posicion = cadena.find_last_of("\t");

		if(posicion != -1){
			texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
			id_servicio = texto;
			cadena.erase(posicion, cadena.length()-posicion+1);
			posicion =  cadena.find_last_of("\t");

			if(posicion != -1){
					texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
					id_producto = texto;
					cadena.erase(posicion, cadena.length()-posicion+1);
					posicion =  cadena.find_last_of("\t");

					if(posicion != -1){
						texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
						id_cliente = texto.c_str();
						cadena.erase(posicion, cadena.length()-posicion+1);
						id_nota = cadena;
					}
				}
		}
	}
}

bool NotaVenta::ObtenerRegistro(int busqueda){
	int cont=0;
	string cadena;
	ifstream archivo("nota_venta.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
				getline(archivo, cadena);
				ObtenerFila(cadena);

				if (atoi(id_nota.c_str()) == busqueda){
					cout << endl << "Identificador: " << id_nota;
					cout << endl << "Cliente: " << id_cliente;
					cout << endl << "Producto: " << id_producto;
					cout << endl << "Servicio: " << id_servicio;
					cout << endl << "Total: " << total;
					cout << endl;
					return true;

				}
				cont ++;
			}
	}
	return false;
}

#endif // NOTAVENTA_H
