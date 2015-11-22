#include "protesis.h"
#include "MenuPrincipal.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#define Max_Protesis 20

Protesis RegistrosProtesis[Max_Protesis];
int posicionProtesis;

//Menu principal de la clase Protesis

void Protesis::MenuProtesis()
{

    MenuPrincipal p;
    do
    {
        system("cls");
        cout<<"\n___PROTESIS___"<<endl;
        cout<<"\n \nQue deseas hacer?\n\n__1)Registrar protesis \n \n___2)Mostrar registro \n \n____3)Buscar Protesis \n \n_____4)Modificar registro\n \n______5)Volver al menu principal"<<endl;
        cout<<"\n \nElige la opcion:"<<endl;
        cin>>opcion;
        getchar();

        if(opcion==1)
        {
            system("cls");
            Capturar();

        }
        else
            if(opcion==2)
            {
                Mostrar();

            }
            else

                if(opcion==3)
                {
                    system("cls");
                    Buscar();
                    cout<<"\n \n"<<endl;
                    system("pause");

                    MenuProtesis();
                }

                else

                    if(opcion==4)
                    {
                        system("cls");
                        Modificar();
                        cout<<"\n \n"<<endl;
                        system("pause");
                        MenuProtesis();
                    }


else

                    if(opcion==5)
                    {
                        system("cls");
                        p.Menuprincipal();
                    }
    }
    while (opcion<0 && opcion>5);
    cout<<"\n \nOpcion no valida (Presione Enter para continuar)"<<endl;
    printf("\n \n");
    system("pause");
   MenuProtesis();
}

//Para meter la informacion por medio del teclado
void Protesis::Capturar()
{
    int CantidadProtesis=1;
    ofstream protesis;
    protesis.open("Datos_Protesis.txt",ios::app);
    for(posicionProtesis=0; posicionProtesis<CantidadProtesis; posicionProtesis++)
    {
        cout<<"\nNombre de protesis:"<<endl;
        getline(cin, RegistrosProtesis[posicionProtesis].nombre);
        cout<<"\nCodigo:"<<endl;
        getline(cin,RegistrosProtesis[posicionProtesis].codigo);
        cout<<"\nPrecio de la protesis:"<<endl;
        cin>>RegistrosProtesis[posicionProtesis].precio;

        protesis<<RegistrosProtesis[posicionProtesis].nombre<<'\n'<<RegistrosProtesis[posicionProtesis].codigo<<'\n'<<RegistrosProtesis[posicionProtesis].precio<<" ";

        posicionProtesis++;

        fflush(stdin);
    }
    protesis.close();
    system("pause");

    MenuProtesis();

}

//Muestra la informacion recabada

void Protesis::Mostrar()
{
int contadorprotesis=1;

    system("cls");
ifstream aprotesis;
aprotesis.open("Datos_Protesis.txt",ios::in);
if(aprotesis.is_open())
{

for(posicionProtesis=0; posicionProtesis<Max_Protesis; posicionProtesis++)
{
   getline(aprotesis,RegistrosProtesis[posicionProtesis].nombre,'\n');
while(!aprotesis.eof())
{

    getline(aprotesis,RegistrosProtesis[posicionProtesis].codigo, '\n');
    aprotesis>>RegistrosProtesis[posicionProtesis].precio;


cout<<"Protesis #"<<contadorprotesis<<endl;
cout<<"__________________________________________________"<<endl;
    cout<<"\nNombre de protesis:"<<RegistrosProtesis[posicionProtesis].nombre<<endl;
    cout<<"\nCodigo:"<<RegistrosProtesis[posicionProtesis].codigo<<endl;
    cout<<"\nPrecio de la protesis:$"<<RegistrosProtesis[posicionProtesis].precio<<endl;
cout<<"__________________________________________________"<<endl;

contadorprotesis++;
getline(aprotesis,RegistrosProtesis[posicionProtesis].nombre, '\n');
}

} //aqui

}
aprotesis.close();

    cout<<"\n \n"<<endl;
    system("pause");

    MenuProtesis();

}

void Protesis::Buscar()
{

string buscarcodigoingresar;
ifstream leerprotesis;
leerprotesis.open("Datos_Protesis.txt",ios::in);
encontrado=false;

    cout<<"\n \nCodigo de protesis por buscar:"<<endl;
    cin>>buscarcodigoingresar;

for(posicionProtesis=0; posicionProtesis<Max_Protesis; posicionProtesis++)
{
getline(leerprotesis,RegistrosProtesis[posicionProtesis].nombre,'\n');
while(!leerprotesis.eof())
{

getline(leerprotesis,RegistrosProtesis[posicionProtesis].codigo,'\n');
leerprotesis>>RegistrosProtesis[posicionProtesis].precio;

    if(buscarcodigoingresar==RegistrosProtesis[posicionProtesis].codigo)
    {

encontrado=true;
cout<<"__________________________________________________"<<endl;
        cout<<"\nNombre de protesis:"<<RegistrosProtesis[posicionProtesis].nombre<<endl;
        cout<<"\nCodigo:"<<RegistrosProtesis[posicionProtesis].codigo<<endl;
        cout<<"\nPrecio:$"<<RegistrosProtesis[posicionProtesis].precio<<endl;

cout<<"__________________________________________________"<<endl;

    }

getline(leerprotesis,RegistrosProtesis[posicionProtesis].nombre);

}

}

if(encontrado==false)
{


cout<<"\nProtesis no registrada bajo ese codigo\n"<<endl;
}
leerprotesis.close();
}
void Protesis::Modificar()
{
system("cls");
string auxcodigo,auxnombre,auxprecio;
int codigoencontrado, modificarP;

ofstream modificarprotesis;

modificarprotesis.open("Auxiliar_Protesis.txt",ios::app);

ifstream archivoprotesis;

archivoprotesis.open("Datos_Protesis.txt",ios::in);

encontrado=false;

cout<<"\nIngresa el codigo de la protesis a modificar:"<<endl;
getline(cin,auxcodigo);

for(posicionProtesis=0; posicionProtesis<Max_Protesis; posicionProtesis++)
{

getline(archivoprotesis,RegistrosProtesis[posicionProtesis].nombre);
while(!archivoprotesis.eof())
{

getline(archivoprotesis,RegistrosProtesis[posicionProtesis].codigo);
archivoprotesis>>RegistrosProtesis[posicionProtesis].precio;

if(auxcodigo==RegistrosProtesis[posicionProtesis].codigo)
{

encontrado=true;

fflush(stdin);

cout<<"__________________________________________________"<<endl;
        cout<<"\nNombre de protesis:"<<RegistrosProtesis[posicionProtesis].nombre<<endl;
        cout<<"\nCodigo:"<<RegistrosProtesis[posicionProtesis].codigo<<endl;
        cout<<"\nPrecio:$"<<RegistrosProtesis[posicionProtesis].precio<<endl;

cout<<"__________________________________________________"<<endl;

cout<<"\n\nQue deseas modificar?:"<<endl;
cout<<"\n__1)Nombre de la protesis"<<endl;
cout<<"\n___2)Precio de la protesis"<<endl;
cout<<"\n____3)Regresar"<<endl;

cout<<"\n\nElige la opcion:\n"<<endl;
cin>>modificarP;

switch(modificarP)
{

case 1:{

system("cls");
fflush(stdin);

cout<<"\nIngresa el nuevo nombre de la protesis:\n"<<endl;

getline(cin,auxnombre);

cout<<"\nNombre modificado"<<endl;

modificarprotesis<<auxnombre<<'\n'<<RegistrosProtesis[posicionProtesis].codigo<<'\n'<<RegistrosProtesis[posicionProtesis].precio<<" ";

break;
}



case 2:{


system("cls");

fflush(stdin);

cout<<"\nIngresa el nuevo precio de la protesis:\n"<<endl;

getline(cin,auxprecio);


cout<<"\nPrecio modificado"<<endl;

modificarprotesis<<RegistrosProtesis[posicionProtesis].nombre<<'\n'<<RegistrosProtesis[posicionProtesis].codigo<<'\n'<<auxprecio<<" ";

break;

}

}

}

else
{

modificarprotesis<<RegistrosProtesis[posicionProtesis].nombre<<'\n'<<RegistrosProtesis[posicionProtesis].codigo<<'\n'<<RegistrosProtesis[posicionProtesis].precio<<" ";

}

getline(archivoprotesis,RegistrosProtesis[posicionProtesis].nombre);

}

}






if(encontrado==false)

{
cout<<"\n\nProtesis no registrada bajo ese codigo"<<endl;
}
modificarprotesis.close();
archivoprotesis.close();
remove("Datos_Protesis.txt");
rename("Auxiliar_Protesis.txt","Datos_Protesis.txt");
}
