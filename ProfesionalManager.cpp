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
// Aqui se desarrollan los metodos de la class ProfesionalManager.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <cctype>
#include <iomanip>

using namespace std;
#include "ProfesionalManager.h"
#include "PacienteManager.h"
#include "rlutil.h"
using namespace rlutil;
bool ProfesionalManager::validarIDProfesional(Profesional &reg, int id)
{


    ArchivoProfesional archivoPro ("archivoProfesional.dat");
    int cant = archivoPro.contarRegistros();
    for(int i  =0 ; i<cant; i++)
    {
        reg = archivoPro.leerRegistro(i);

        if(reg.getID()==id)
        {
            return true;
        }
    }

    return false;


}
void ProfesionalManager::Cargar()
{
    Profesional reg;
    string nombre;
    string apellido;
    string especialidad;
    int id;
    int legajo;

    cout << "====================================="<<endl;
    cout << "  INGRESE LOS DATOS DEL PROFESIONAL: " << endl;
    cout << "====================================="<<endl<<endl;

    cout << "ID: ";
    id = obtenerEnteroValidado("");
    if(validarIDProfesional(reg,id))
    {
        cout << "ID ya tiene un profesional"<<endl;
    }
    else
    {
        cout << "Nombre: ";
        getline(cin,nombre);
        cout << "Apellido: ";
        getline(cin,apellido);
        cout << "Especialidad: ";
        getline(cin,especialidad);
        cout << "LEGAJO: ";
        legajo = obtenerEnteroValidado("");

    }
    Profesional profesional(nombre, apellido, especialidad, id,  legajo);
    _archivoProf.guardar(profesional);
}
void ProfesionalManager::Listar(Profesional profesional)
{

    cout << endl;
    cout<<"         PROFESIONAL"<<endl;
    cout << "ID: "<< profesional.getID()<< endl;
    cout << "Nombre: " << profesional.getNombre()<<endl;
    cout << "Apellido: "<< profesional.getApellido()<<endl;
    cout << "Especialidad: "<< profesional.getEspecialidad()<<endl;
    cout << "Legajo: "<< profesional.getlegajo() << endl;
    cout <<"---------------------------------"<<endl;

}
void ProfesionalManager::ListarTodos()
{

    int cantidadRegistros = _archivoProf.contarRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Profesional reg = _archivoProf.leerRegistro(i);

        Listar(reg);

    }


}

bool ProfesionalManager::existeID(int id)
{
    return _archivoProf.buscar(id)>=0;
}

int ProfesionalManager::generarID()
{
    return _archivoProf.contarRegistros() + 1;
}

///BUSCAR PROFESIONAL POR ID

void ProfesionalManager::BuscarPorID()
{

    ProfesionalManager reg;
    Profesional _profesional;

    ArchivoProfesional archivoProfesional ("archivoProfesional.dat");

    int cantRegProfesional = archivoProfesional.contarRegistros();
    int id;
    cout <<"INGRESE EL ID DEL PROFESIONAL A BUSCAR: ";
    id = obtenerEnteroValidado("");
    bool encontro = false;
    for(int i = 0; i<cantRegProfesional; i++)
    {
        _profesional = archivoProfesional.leerRegistro(i);

        if(_profesional.getID()==id )
        {
            reg.Listar(_profesional);
            encontro = true;
        }
    }
    if(encontro == false)
    {
        cout << "NO HAY PROFESIONAL CON ESE ID .. "<<endl;
    }
cin.ignore();

}

void ProfesionalManager::BuscarCirugiaPorApellidoProfesional(){
	PacienteManager reg;
	Paciente paciente;
	ArchivoPaciente archivo ("archivoPaciente.dat");

	int cantRegPaciente = archivo.getCantidadRegistros();
    string apellido;
	cout <<"Ingrese apellido del profesional a buscar: ";
	getline(cin,apellido);
	bool encontro = false;
	cout << "las operaciones que tiene el profesional " << apellido << " son: " << endl;
	cout<<endl;
		for(int i = 0; i<cantRegPaciente; i++){
		paciente = archivo.leerRegistro(i);
		if(strcasecmp(paciente.getProfesionalAsignado().c_str(),apellido.c_str())==0 && paciente.getEstado()==true){
			reg.Listar(paciente);
			cout << "---------------------------------------------" << endl;
			encontro = true;
		}
	}
			if(encontro == false){
				cout << "NO HAY PACIENTE CON ESE APELLIDO .. "<<endl;
			}

}
void ProfesionalManager::pacientesPorProfesional(){

	PacienteManager reg;
	Paciente paciente;
	ArchivoPaciente archivo ("archivoPaciente.dat");

	int cantRegPaciente = archivo.getCantidadRegistros();
    string apellido;
	cout <<"Ingrese apellido del profesional a buscar: ";
	getline(cin,apellido);
	//bool encontro = false;
	int contador = 0;
	//cout << "las operaciones que tiene el profesional " << apellido << " son: " << endl;
	cout<<endl;
		for(int i = 0; i<cantRegPaciente; i++){
		paciente = archivo.leerRegistro(i);
		if(strcasecmp(paciente.getProfesionalAsignado().c_str(),apellido.c_str())==0 && paciente.getEstado()==true){
			contador++;
			cout << "---------------------------------------------" << endl;
			//encontro = true;
		}
	}
			if(contador>0){
				cout << "El Dr."<< apellido << " tiene " << contador << " pacientes. "<<endl;
			}else{

			cout << "El Dr."<<apellido << " No tiene pacientes por el momento.. "<<endl;
			}



}
void ProfesionalManager::ListarParaPaciente(Profesional profesional)
{
    cout << endl;

    cout<<setw(5)<<setiosflags(ios::left)<<profesional.getID();
    cout<<setw(10)<<setiosflags(ios::left)<<profesional.getApellido();
    cout<<setw(15)<<setiosflags(ios::left)<<profesional.getNombre();
    cout<<setw(20)<<setiosflags(ios::left)<<profesional.getEspecialidad();

}

void ProfesionalManager::ListarTodosParaPaciente(){
int cantidadRegistros = _archivoProf.contarRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Profesional reg = _archivoProf.leerRegistro(i);

        ListarParaPaciente(reg);

    }

}

string ProfesionalManager::BuscarPorIDParaPaciente(int IDProfesional)
{

    ProfesionalManager reg;
    Profesional _profesional;
    string apellido;

    ArchivoProfesional archivoProfesional ("archivoProfesional.dat");

    int cantRegProfesional = archivoProfesional.contarRegistros();
    bool encontro = false;
    for(int i = 0; i<cantRegProfesional; i++)
    {
        _profesional = archivoProfesional.leerRegistro(i);

        if(_profesional.getID()==IDProfesional)
        {
            encontro = true;
            return _profesional.getApellido();
        }
    }
    if(encontro == false)
    {

        cout << "NO HAY PROFESIONAL CON ESE ID .. "<<endl;


        return "nada";
    }
cin.ignore();
cls();
}
