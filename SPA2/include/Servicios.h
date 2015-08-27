#ifndef SERVICIOS_H
#define SERVICIOS_H
#include <iostream>
#include <string>

using namespace std;

class Servicios
{
    public:
        //Atributos de clase
        string  codigo, descripcion;
        float precio_minimo, precio_maximo;

        //metodos de clases
    public:
        void Capturar();
        void Mostrar();
};

void Servicios::Capturar()
{


    cout << "\nCodigo de servicio: " << endl;
    getline(cin, codigo);

    cout << "\nDescripcion: " << endl;
    getline(cin, descripcion);

    cout << "\nPrecio minimo: " << endl;
    cin>>precio_maximo;

    cout << "\nPrecio maximo: " << endl;
    cin>>precio_minimo;

}

void Servicios::Mostrar(){
    cout<<"Codigo de servicio: " << codigo ;
    cout<<"Descripcion: " << descripcion ;
    cout<<"Precio minimo: $" << precio_minimo ;
    cout<<"Precio maximo: $" << precio_maximo ;
}

#endif // SERVICIOS_H
