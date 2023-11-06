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
// Aqui se desarrollan los metodos de la class Quirofano.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

#include "Quirofano.h"

Quirofano::Quirofano(){

}
Quirofano::Quirofano(int ID, int NroCama, string NroQuirofano, bool Ocupado, Tiempo TiempoProc){
_id = ID;
_NroCama = NroCama;
strcpy(_NroQuirofano,NroQuirofano.c_str());
_Ocupado = Ocupado;
_tiempoProcedimiento = TiempoProc;
}

//sets
void Quirofano::setNroCama(int cama){
_NroCama = cama;
}

void Quirofano::setNroQuirofano(string quirofano){
strcpy(_NroQuirofano,quirofano.c_str());
}

void Quirofano::setID(int id){
_id = id;
}

void Quirofano::setOcupado(bool ocupado){
_Ocupado = ocupado;
}

///gets

int Quirofano::getNroCama(){
return _NroCama;
}

string Quirofano::getNroQuirofano(){
return _NroQuirofano;
}

int Quirofano::getID(){
return _id;
}

bool Quirofano::getOcupado(){
return _Ocupado;
}
Tiempo Quirofano::getTiempoProcedimiento(){
return _tiempoProcedimiento;

}
