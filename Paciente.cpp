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
// Aqui se desarrollan los metodos de la class Paciente.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <cstring>
#include "Paciente.h"

using namespace std;

//Constructor Vacio
Paciente::Paciente(){

}
Fecha::Fecha(){
}

Paciente::Paciente(bool estado,string genero, int documento, Fecha fechaNac,
	Fecha fechaOperacion, string nombre,string apellido, int id, string mail,
	string diagnostico, string patologia, int HC, string profesionalAsig)
{
	_estado = estado;
	strcpy(_genero, genero.c_str());
	_documento = documento;
	_fechaNac = fechaNac;
	_fechaOperacion = fechaOperacion;
	strcpy(_nombre, nombre.c_str());
	strcpy(_apellido, apellido.c_str());
	_id = id;
	strcpy(_mail,mail.c_str());
	strcpy(_diagnostico, diagnostico.c_str());
	strcpy(_patologia, patologia.c_str());
	_HC = HC;
	strcpy(_profesionalAsignado,profesionalAsig.c_str());

}


//set
void Paciente::setEstado(bool estado){
	_estado = estado;
}

void Paciente::setGenero(std::string genero) {
	strcpy(_genero, genero.c_str());
}
void Paciente::setProfesionalAsignado(std::string profesionalAsig){
strcpy(_profesionalAsignado,profesionalAsig.c_str());
}

void Paciente::setDocumento(int documento) {
	_documento = documento;
}

void Paciente::setFechaNacimiento(Fecha fechaNac) {
	_fechaNac = fechaNac;
}

void Paciente::setFechaOperacion(Fecha fechaOperacion) {
	_fechaOperacion = fechaOperacion;
}

void Paciente::setNombre(std::string nombre) {
	strcpy(_nombre, nombre.c_str());
}

void Paciente::setApellido(std::string apellido) {
  strcpy(_apellido, apellido.c_str());
}

void Paciente::setID(int id) {
	_id = id;
}

void Paciente::setEmail(std::string mail) {
	strcpy(_mail, mail.c_str());
}

void Paciente::setDiagnostico(std::string d){
strcpy(_diagnostico, d.c_str());
}

void Paciente::setPatologia(std::string patologia) {
	strcpy(_patologia, patologia.c_str());
}

void Paciente::setHistorialClinico(int HC) {
	_HC = HC;
}
//=======================Fin========================


//get

bool Paciente::getEstado() {
	return _estado;
}

string Paciente::getGenero() {
	string aux = _genero;
	return aux;
}

int Paciente::getDocumento() {
	return _documento;
}



Fecha Paciente::getFechaNacimiento() {
	return _fechaNac;
}

Fecha Paciente::getFechaOperacion() {
	return _fechaOperacion;
}

string Paciente::getNombre() {
	string aux = _nombre;
	return aux;
}
string Paciente::getApellido() {
	string aux = _apellido;
	return aux;
}

int Paciente::getID() {
	return _id;
}

string Paciente::getEmail() {
	string aux = _mail;
	return aux;
}


string Paciente::getDiagnostico(){
	string aux = _diagnostico;
return aux;
}


string Paciente::getPatologia(){
	string aux = _patologia;
return aux;
}

int Paciente::getHistorialClinico(){
return _HC;
}

string Paciente::getProfesionalAsignado(){
string aux = _profesionalAsignado;
return aux;

}







