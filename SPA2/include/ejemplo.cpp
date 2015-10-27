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
		while(!archivoprotesis.eof()){
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

					case 1:
						system("cls");
						fflush(stdin);
						cout<<"\nIngresa el nuevo nombre de la protesis:\n"<<endl;
						getline(cin,auxnombre);
						cout<<"\nNombre modificado"<<endl;
						modificarprotesis<<auxnombre<<'\n'<<RegistrosProtesis[posicionProtesis].codigo<<'\n'<<RegistrosProtesis[posicionProtesis].precio<<" ";
						break;
					case 2:
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
