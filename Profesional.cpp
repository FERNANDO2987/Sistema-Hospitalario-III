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
// Aqui se desarrollan los metodos de la class Profeional.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include <cstring>
#include "Profesional.h"
Profesional::Profesional(){
}

Profesional::Profesional(std::string nombre, std::string apellido, std::string especialidad,int id, int legajo){
strcpy(_Nombre, nombre.c_str());
strcpy(_Apellido, apellido.c_str());
strcpy(_Especialidad, especialidad.c_str());
_Id = id;
_legajo=legajo;
}

///set
void Profesional::setNombre(string nombre){
strcpy(_Nombre, nombre.c_str());
}
void Profesional::setApellido(string apellido){
strcpy(_Apellido, apellido.c_str());
}
void Profesional::setEspecialidad(string especialidad){
strcpy(_Especialidad, especialidad.c_str());
}
void Profesional::setID(int id){
_Id = id;
}
void Profesional::setlegajo(int legajo){
_legajo = legajo;
}
///gets
string Profesional::getNombre(){
string aux = _Nombre;
return aux;
}
string Profesional::getApellido(){
string aux = _Apellido;
return aux;
}
string Profesional::getEspecialidad(){
string aux = _Especialidad;
return aux;
}
int Profesional::getID(){
return _Id;
}
int Profesional::getlegajo(){
return _legajo;
}
