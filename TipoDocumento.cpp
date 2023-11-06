// AUTOR : RAMIREZ MATIAS HERNAN,ROMERO NAHUEL FRANCO,PALACIOS FERNANDO GUILLERMO
// FECHA DE CREACION : 28/06/2023.
// ULTIMA ACTUALIZACION: 28/06/2023.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 17.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// Aqui se desarrollan los metodos de la class TipoDeDocumento.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include "TipoDocumento.h"
#include <string>

void TipoDocumento::setDocumento(string documento){
Documento = documento;
}
void TipoDocumento::setPasaporte(string pasaporte){
Pasaporte = pasaporte;
}
void TipoDocumento::setLibretaCivica(string Libretacivica){
LibretaCivica = Libretacivica;}

string TipoDocumento::getDocumento(){
return Documento;
}
string TipoDocumento::getPasaporte(){
return Pasaporte;
}
string TipoDocumento::getLibretaCivica(){
return  LibretaCivica;
}

void TipoDocumento::Cargar(){
 char opcion;
 while(true){

 cout << "Ingrese tipo de documentacion : "<<endl;
 cout << "1- Documento Nacional de Identificacion "<<endl;
 cout << "2- Libreta Civica "<<endl;
 cout << "3- Pasaporte "<<endl;
 cout << "4- SALIR"<<endl;
 cin>>opcion;


 switch(opcion){
case '1':
	cout << "Ingrese numero de documento: ";
	cin>>Documento;
	return;
	break;
case '2':
	cout << "ingrese Numero de Libreta Civica: ";
	cin>>LibretaCivica;
	return;
	break;
case '3':
	cout << "Ingrese numero de Pasaporte: ";
	cin>>Pasaporte;
	return;
	break;
case '4':
	return;
	break;
default:
	cout << "OPCION INCORRECTA."<<endl;
	break;

 }
 cin.get();

 }

}
void TipoDocumento::Mostrar(){
cout << "Documento nacional de identidad: "<< Documento<<endl;
cout << "Libreta Civica: "<< LibretaCivica<<endl;
cout << "Pasaporte: "<<Pasaporte<<endl;

}
