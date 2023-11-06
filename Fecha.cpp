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
// Aqui se define  la class Fecha.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
#include "Fecha.h"
#include <string>
#include <sstream>
#include <cctype>
//Constructor
Fecha::Fecha(int dia, int mes, int anio){
   _dia = dia;
   _mes = mes;
   _anio = anio;

}
//Getters
int Fecha::getDia(){
   return _dia;
}
int Fecha::getMes(){
   return _mes;
}
int Fecha::getAnio(){
   return _anio;
}
bool Fecha::esFechaValida(int dia, int mes, int anio) {
  // Verificar el rango del año (asumimos años entre 1900 y 2100)
  if (anio < 1900 || anio > 2100) {
    return false;
  }

  // Verificar el rango del mes (entre 1 y 12)
  if (mes < 1 || mes > 12) {
    return false;
  }

  // Verificar el rango del día en base al mes
  int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)) {
    // Año bisiesto, febrero tiene 29 días
    diasEnMes[1] = 29;
  }
  if (dia < 1 || dia > diasEnMes[mes - 1]) {
    return false;
  }

  return true;
}
bool Fecha::esEnteroValido(const string& input) {
  for (char c : input) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

int Fecha::obtenerEnteroValidado(const string& mensaje) {
  string input;
  cout << mensaje;
  cin >> input;
  cin.ignore();

  while (!esEnteroValido(input)) {
    cout << "Ingrese en formato numerico. Por favor, intentelo nuevamente: ";
    cin >> input;
    cin.ignore();
  }

  return stoi(input);
}


///================================FIN==========================================

///=============================================================================
/// FUNCION :string Fecha::toString(string formatoFecha)
/// ACCION : formatea la fecha
/// PARAMETROS: string formatoFecha
///
/// DEVUELVE : string DD/MM/YYYY
///-----------------------------------------------------------------------------
string Fecha::toString(string formatoFecha){
   string fechaFormateada = "";

   string DD = to_string(_dia);
   string MM = to_string(_mes);
   string YYYY = to_string(_anio);
   // DD/MM/YYYY
   if (_dia < 10){
      DD = "0" + to_string(_dia);
   }
   if (_mes < 10){
      MM = "0" + to_string(_mes);
   }

   if (formatoFecha == "DD/MM/YYYY"){
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }
   else if (formatoFecha == "YYYY/MM/DD"){
      fechaFormateada = YYYY + "/" + MM + "/" + DD;
   }
   else{
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }

   return fechaFormateada;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void Fecha::Cargar()
/// ACCION : Carga una fecha
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Fecha::Cargar(){
	cout << "DIA: ";
_dia = obtenerEnteroValidado ("");
while(_dia>31 || _dia < 1){
	cout << "DIA invalido, por favor, ingrese un dia: ";
	_dia = obtenerEnteroValidado ("");
}

cout << "MES: ";
_mes = obtenerEnteroValidado ("");
while (_dia>29 && _mes == 2 || _mes < 1 || _mes > 12 || _dia > 30 && _mes< 8 && _mes %2== 0 || _dia > 30 && _mes > 8 && _mes%2==1) {


        cout << "Mes invalido. Por favor, ingrese un mes válido (1 a 12)." << endl;

        cout << "MES: ";
        _mes = obtenerEnteroValidado ("");

    }

cout << "ANIO: ";
_anio = obtenerEnteroValidado ("");
while(_dia == 29 && _mes == 2 && ((_anio % 4 == 0 && _anio % 100 != 0)|| _anio % 400 == 0 ) -1 || _anio <1950 || _anio>2023){

	cout << "Anio invalido. Por favor, ingrese un nuevo anio." << endl;
	Cargar();
	//cout << "ANIO: ";
	//_anio = obtenerEnteroValidado ("");
}
}

void Fecha::CargaFechaOperacion(){
	cout << "DIA: ";
_dia = obtenerEnteroValidado ("");
while(_dia>31 || _dia < 1){
	cout << "DIA invalido, por favor, ingrese un dia: ";
	_dia = obtenerEnteroValidado ("");
}

cout << "MES: ";
_mes = obtenerEnteroValidado ("");
while (_dia>29 && _mes == 2 || _mes < 1 || _mes > 12) {


        cout << "Mes invalido. Por favor, ingrese un mes válido (1 a 12)." << endl;

        cout << "MES: ";
        _mes = obtenerEnteroValidado ("");

    }

cout << "ANIO: ";
_anio = obtenerEnteroValidado ("");
while(_dia == 29 && _mes == 2 && ((_anio % 4 == 0 && _anio % 100 != 0)|| _anio % 400 == 0 )  -1 || _anio <2010 || _anio<2023){

	cout << "Las operaciones se haran a partir del 2023." << endl;
	cout << "ingrese una nueva fecha de operacion." << endl;
	CargaFechaOperacion();
	//cout << "ANIO: ";
	//_anio = obtenerEnteroValidado ("");
}

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void Fecha::Mostrar()
/// ACCION : muestra la fecha
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Fecha::Mostrar(){
	if(!esFechaValida(_dia, _mes, _anio)){
		cout << "FECHA INVALIDA"<< endl;
		}else{

 cout << _dia << "/" << _mes<< "/"<<_anio<<endl;
		}
}
///================================FIN==========================================

