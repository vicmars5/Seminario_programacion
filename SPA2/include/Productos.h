#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <iostream>
#include <string>
#include <stdlib.h>

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
};

void Productos::Capturar()
{
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
    system("cls");
    cout << "\nIdentificador: " << id_producto;
    cout << "\nNombre: " << nombre;
    cout << "\nDescripcion: " << descripcion;
    cout << "\nPrecio: " << precio;
}

#endif // PRODUCTOS_H
