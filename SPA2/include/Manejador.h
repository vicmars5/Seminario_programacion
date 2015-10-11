#ifndef MANEJADOR_H
#define MANEJADOR_H

#include <fstream>
#include <stdio.h>

#include <Clientes.h>
using namespace std;

class Manejador
{
	public:
	void Guardar();
	void GuardarClientes();
	void LeerClientes();
	void Leer();
    Clientes clientes[2];
};

void Manejador::Guardar(){
	ofstream archivo;
	string frase;

	fflush(stdin);
	cout << "Hola. Expresate :3";
	getline(cin, frase);

    archivo.open("datos.txt");
	if(archivo.is_open()){
		archivo << frase;
		archivo.close();
	} else {
		cout << "NO SE GUARDO EL ARCHIVO" << endl;
	}
}

void Manejador::GuardarClientes(){
    /*
    ofstream archivo;
    archivo.open("clientes.txt");
    for(int cont=0; cont < 2; cont++){
        if(archivo.is_open()){
            archivo << clientes[cont].id_cliente << "," << clientes[cont].nombre << ","
                << clientes[cont].tel[0] << "," << clientes[cont].tel[1] << "," << clientes[cont].tel[2]
                << "," << clientes[cont].correo << endl;
        } else {
            cout << "NO SE GUARDO EL ARCHIVO"  << endl;
        }
    }
    cout << clientes[0].id_cliente;
    */
    ofstream archivo;
    archivo.open("clientes.txt", ios::out);//app permite que se ñaada el registr despues
    for(int cont=0; cont < 2; cont++){
        if(archivo.is_open()){
            archivo << clientes[cont].id_cliente << " " << clientes[cont].nombre << " "
                << clientes[cont].tel[0] << " " << clientes[cont].tel[1] << " " << clientes[cont].tel[2]
                << " " << clientes[cont].correo << endl;
        } else {
            cout << "NO SE GUARDO EL ARCHIVO"  << endl;
        }
    }
    cout << clientes[0].id_cliente;

    getch();
}

void Manejador::LeerClientes(){

    int cont=0;

    ifstream archivo("clientes.txt", ios::in);
    if(archivo.is_open()){
            archivo>> clientes[cont].id_cliente;
            while(!archivo.eof()){
                archivo >> clientes[cont].nombre >> clientes[cont].tel[0] >> clientes[cont].tel[1] >> clientes[cont].tel[2] >> clientes[cont].correo;
                cout << clientes[cont].id_cliente << clientes[cont].nombre << clientes[cont].tel[0] << clientes[cont].tel[1] << clientes[cont].tel[2] << clientes[cont].correo << endl;
                archivo>> clientes[cont].id_cliente;
                cont++;
            }
    }
    getch();
}

void Manejador::Leer(){
	string linea;
	ifstream archivo("datos.txt");
    if(archivo.is_open()){
    	//Mientras que no sea fin de archivo
    	while (! archivo.eof()){
    		getline(archivo, linea);
    		cout << linea << endl;
    	}
    	archivo.close();
    }
}
#endif // MANEJADOR_H
