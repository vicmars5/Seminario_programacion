#ifndef SERVICIOS_H
#define SERVICIOS_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

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
        void Buscar();
        void Menu();
};

void Servicios::Capturar()
{
    fflush(stdin);

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
    cout << endl <<"Codigo de servicio: " << codigo ;
    cout << endl <<"Descripcion: " << descripcion ;
    cout << endl <<"Precio minimo: $" << precio_minimo ;
    cout << endl <<"Precio maximo: $" << precio_maximo ;
    getch();
}

void Servicios::Buscar(){
    system("cls");
    string busqueda;
    cout << "Escriba el codigo del servicio que desea buscar: ";
    cin >> busqueda;
    if (codigo == busqueda){
        Mostrar();
    } else { cout << "No  existe"; getch();}

}

void Servicios::Menu(){
    bool repetir=true;
    int opcion;

    do{
        system("cls");
        fflush(stdin);

        cout << "   Servicios"
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
#endif // SERVICIOS_H
