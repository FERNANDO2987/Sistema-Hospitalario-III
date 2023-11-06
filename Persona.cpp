#include <iostream>
using namespace std;
#include "Persona.h"
#include "Fecha.h"
#include "cstring"

void Persona::setApellido(string apellido){
_apellido=apellido;
}
void Persona::setNombre(string nombre){
_nombre=nombre;
}
void Persona::setDocumento (TipoDocumento Dni){
_documento = Dni;
}
void Persona::setID(int id){
_id = id;
}
void Persona::setEmail(string email){
_mail = email;
}
void Persona::setEstado(bool estado){
_estado = estado;
}
void Persona::setFechaAlta(Fecha fechaAlta){
_fechaAlta = fechaAlta;
}
void Persona::setFechaBaja(Fecha fechaBaja){
_fechaBaja= fechaBaja;
}
void Persona::setFechaNacimiento(Fecha fechaNacimiento){
_fechaNac=fechaNacimiento;
}
void Persona::setGenero(string genero){
_genero = genero;
}

TipoDocumento Persona::getDocumento(){
return _documento;
}
string Persona::getNombre(){
return _nombre;
}
string Persona::getApellido(){
return _apellido;
}
bool Persona::getEstado(){
return _estado;
}
int Persona::getID(){
return _id;
}
string Persona::getEmail(){
return _mail;
}
string Persona::getGenero(){
return _genero;
}
Fecha Persona::getFechaAlta(){
return _fechaAlta;
}
Fecha Persona::getFechaBaja(){
return _fechaBaja;
}
Fecha Persona::getFechaNacimiento(){
return _fechaNac;
}

void Persona::Mostrar(){
	TipoDocumento reg;
	Fecha regNacimiento, regAlta, regBaja;
cout<<"Nombre : " << _nombre<<endl;
cout<<"Apellido : "<< _apellido <<endl;
cout << "Genero: " << _genero<<endl;

reg.Mostrar();

cout << "ID: " << _id <<endl;
cout << "Email: " << _mail <<endl;
cout << "Fecha de Nacimiento : ";
regNacimiento.Mostrar();
cout << "Fecha de Alta: ";
regAlta.Mostrar();
cout << "Fecha de baja: ";
regBaja.Mostrar();
}
void Persona::Cargar(){
	TipoDocumento reg;
	Fecha regNacimiento, regAlta, regBaja;
cout << "Ingrese Nombre: ";
cin >> _nombre;
cout << "Ingrese apellido: ";
cin>>_apellido;
cout << "Genero: ";
cin>>_genero;
reg.Cargar();
cout << "ID: ";
cin >>_id;
cout << "MAIL: ";
cin>>_mail;
cout << "Fecha de Nacimiento : ";
regNacimiento.Cargar();
cout << "Fecha de Alta: ";
regAlta.Cargar();
cout << "Fecha de baja: ";
regBaja.Cargar();

}

