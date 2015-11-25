#ifndef SERVICIOS_H
#define SERVICIOS_H
#include <iostream>
#include <fstream>

#include <string>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Servicios
{
    public:
        //Atributos de clase
        string  codigo, descripcion;
        float precio_minimo, precio_maximo;

        //metodos de clases
    public:
    	int CantidadRegistros();
        void Capturar();
        void Mostrar();
        void Buscar();
        void Menu();
        void Modificar();
 		void ObtenerFila(string cadena);
 		bool ObtenerRegistro(int busqueda);
        string nombreServicio(string busqueda);
        float precioServicio(string busqueda);
};

string Servicios::nombreServicio(string busqueda){
    int cont=1;
    string cadena;
    bool existe=false;

    ifstream archivo("servicios.txt", ios::in);
    if(archivo.is_open()){
            while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);

                if (atoi(codigo.c_str()) == atoi(busqueda.c_str())){
                    existe=true;
                    return descripcion;
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

float Servicios::precioServicio(string busqueda){
    int cont=1;
    string cadena;
    bool existe=false;

    ifstream archivo("servicios.txt", ios::in);
    if(archivo.is_open()){
            while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);

                if (atoi(codigo.c_str()) == atoi(busqueda.c_str())){
                    existe=true;
                    return ((precio_minimo+precio_maximo)/2);
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

int Servicios::CantidadRegistros(){
	string linea;
	int cant_registros=0;
	ifstream archivo("servicios.txt");
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

void Servicios::Capturar()
{
    int cant;
	cout << "\t Cuantos servicios desea ingresar?";
	cin >> cant;
	cin.ignore();
	if(cant <= (MAX_REGISTROS-CantidadRegistros())){
		ofstream archivo;
		archivo.open("servicios.txt", ios::app);
		if(archivo.is_open()){
			cout << "Registros en BD " << CantidadRegistros() << endl << endl;
			for (int x=0 ; x<cant ; x++){

			    cout << "\nCodigo de servicio: " << endl;
			    getline(cin, codigo);

			    cout << "\nDescripcion: " << endl;
			    getline(cin, descripcion);

			    cout << "\nPrecio minimo: " << endl;
			    cin>>precio_minimo;
			    cin.ignore();

			    cout << "\nPrecio maximo: " << endl;
			    cin>>precio_maximo;
			    cin.ignore();
			    cout << endl;

				cout << endl;
				archivo << codigo << "\t" << descripcion << "\t" << precio_minimo << "\t" << precio_maximo << endl;

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



void Servicios::Mostrar(){
    int cont=1;
    string cadena;
    ifstream archivo("servicios.txt", ios::in);
    if(archivo.is_open()){
            while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);
                cout << endl <<"Codigo de servicio: " << codigo ;
                cout << endl <<"Descripcion: " << descripcion ;
                cout << endl <<"Precio minimo: $" << precio_minimo ;
                cout << endl <<"Precio maximo: $" << precio_maximo ;
                cout << endl;

                cont ++;
            }
    }
    if(cont==1) {
        cout << "Archivo vacio" << endl;
    }
    cin.get();
}

void Servicios::Modificar(){
    system("clear");
	int busqueda, cont=1;
	string cadena, info_archivo="";
	bool existe=false;
	cout << "Escriba el identificador del servicio que desea buscar: ";
	cin >> busqueda;
	cin.ignore();

	ifstream archivo("servicios.txt", ios::in);
	ofstream nuevoArchivo("servicios_new.txt", ios::app);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);
                if (atoi(codigo.c_str()) == busqueda){
                	int opcion;
                    cout << endl << "Codigo: " << codigo;
                    cout << endl << "1.-Descripcion: " << descripcion;
                    cout << endl << "2.-Precio minimo: " << precio_minimo;
                    cout << endl << "3.-Precio maximo: " << precio_maximo;
                    cout << endl;
                    cout << "Seleccione la opcion que desea modificar";
                    cin >> opcion;
                    cin.ignore();
                    switch (opcion) {
                    	case 1:
                    		cout << endl << "Descripcion: ";
                    		getline(cin, descripcion);
                    		break;
                    	case 2:
                    		cout << endl << "Precio minimo: ";
                    		cin >> precio_minimo;
                    		cin.ignore();
                    		break;
                    	case 3:
                    		cout << endl << "Precio maximo: ";
                    		cin >> precio_maximo;
                    		cin.ignore();
                    		break;
                    }
                    existe=true;
                }
                nuevoArchivo << codigo << "\t" << descripcion << "\t" << precio_minimo << "\t" << precio_maximo << endl;
                cont ++;
			}
            archivo.close();
            nuevoArchivo.close();
			if(existe){
                remove("servicios.txt");
                rename("servicios_new.txt","servicios.txt");
                ObtenerRegistro(busqueda);
			} else {
                cout << "NO SE ENCONTRO REGISTRO";
			}
	}
    cin.get();
}

bool Servicios::ObtenerRegistro(int busqueda){
    int cont=0;
    string cadena;
    ifstream archivo("servicios.txt", ios::in);
	if(archivo.is_open()){
			while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);

                if (atoi(codigo.c_str()) == busqueda){
				    cout << endl <<"Codigo de servicio: " << codigo ;
				    cout << endl <<"Descripcion: " << descripcion ;
				    cout << endl <<"Precio minimo: $" << precio_minimo ;
				    cout << endl <<"Precio maximo: $" << precio_maximo ;
				    cout << endl;
                    return true;

                }
                cont ++;
			}
	}
    return false;
}

void Servicios::ObtenerFila(string cadena){
    string texto;
    int posicion;
    posicion = cadena.find_last_of("\t");
	if (posicion != -1){
		texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
		cadena.erase(posicion, cadena.length()-posicion+1);
		precio_maximo=atoi(texto.c_str());
		posicion = cadena.find_last_of("\t");

		if(posicion != -1){
			texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
			precio_minimo = atoi(texto.c_str());
			cadena.erase(posicion, cadena.length()-posicion+1);
			posicion =  cadena.find_last_of("\t");

			if(posicion != -1){
				texto = cadena.substr(posicion+1, cadena.length()-posicion+1);
				descripcion = texto.c_str();
				cadena.erase(posicion, cadena.length()-posicion+1);
				codigo = cadena;
			}
		}
	}

}
void Servicios::Buscar(){
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
    /*
    ifstream archivo("masajistas.txt", ios::in);
    if(archivo.is_open()){
            while(!archivo.eof() && (cont <= CantidadRegistros())){
                getline(archivo, cadena);
                ObtenerFila(cadena);

                if (codigo == busqueda){
                    cout << endl <<"Codigo de servicio: " << codigo ;
                    cout << endl <<"Descripcion: " << descripcion ;
                    cout << endl <<"Precio minimo: $" << precio_minimo ;
                    cout << endl <<"Precio maximo: $" << precio_maximo ;
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
    }*/

}

void Servicios::Menu(){
    bool repetir=true;
    int opcion;

    do{
        system("clear");

        cout << "   Servicios"
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
#endif // SERVICIOS_H
