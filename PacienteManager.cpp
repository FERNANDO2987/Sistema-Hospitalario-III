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
// Aqui se desarrollan los metodos de la class PacienteManager.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "Cirugia.h"
#include "PacienteManager.h"
#include "CirugiaManager.h"
#include "ProfesionalManager.h"
#include <iomanip>

using namespace std;
#include "rlutil.h"
using namespace rlutil;

// Función para generar una historia clínica de 5 dígitos sin repetición
int PacienteManager:: generarHistoriaClinica() {
    // Generar una semilla aleatoria usando el tiempo actual
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::unordered_set<int> historiasClinicasGeneradas;

    while (true) {
        // Generar un número de historia clínica aleatorio de 5 dígitos
        int historiaClinica = std::rand() % 90000 + 10000;

        // Verificar si el número de historia clínica ya ha sido generado
        if (historiasClinicasGeneradas.find(historiaClinica) == historiasClinicasGeneradas.end()) {
            historiasClinicasGeneradas.insert(historiaClinica);
            return historiaClinica;
        }
    }
}
bool PacienteManager::validarID(Paciente &reg, int id){


	ArchivoPaciente archivoP ("archivoPaciente.dat");
	int cant = archivoP.getCantidadRegistros();
	for(int i  =0 ; i<cant; i++){
		reg = archivoP.leerRegistro(i);

	if(reg.getID()== id){
		return true;
	}
	}

	return false;


}
bool esEnteroValido(const string& input) {
  for (char c : input) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

int obtenerEnteroValidado(const string& mensaje) {
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


void PacienteManager::Cargar(){
	Paciente reg;
 bool estado;
  string genero;
  int documento;
  string nombre;
  string apellido;
  int id;
  string mail;
  string diagnostico;
  string patologia;
  int HC;
  int d, m, a;
  string profesional;
  Fecha fechaNac;
  Fecha fechaAlta;
  Fecha fechaOperacion;
  ProfesionalManager profManager;
  int IDProfesional;



  cout << "=================================="<<endl;
  cout << "  INGRESE LOS DATOS DEL PACIENTE: " << endl;
  cout << "=================================="<<endl<<endl;
  id = generarID();
  cout << "ID : " <<id<<endl;
	if(validarID(reg,id)){
			cout << "ID ya utilizado"<<endl;

	}else{

 // cin.ignore();
  cout << "Nombre: ";
  getline(cin, nombre);

  cout << "Apellido: ";
  getline(cin, apellido);
  do{
  cout << "Fecha de nacimiento (dd mm aaaa): ";
  fechaNac.Cargar();
  cout << "Fecha Operacion (dd mm aaaa): ";
  fechaOperacion.CargaFechaOperacion();
  if (fechaNac.toString("YYYY/MM/DD") <= fechaOperacion.toString("YYYY/MM/DD")){
    cout << "Documento: ";
  documento = obtenerEnteroValidado("");

  cout << "Genero: ";
  getline(cin, genero);
  cout << "Email: ";
  getline(cin, mail);
  cout << "Diagnostico: ";
  getline(cin, diagnostico);
  HC = generarHistoriaClinica();
  cout << "Historial clinico: " << HC <<endl;
  system("pause");
  cls();



  cout<<"ID "<<"  APELLIDO   "<<"  NOMBRE  "<< "  ESPECIALIDAD  " << endl;
  profManager.ListarTodosParaPaciente();

do{
  cout << endl << "Ingrese el ID del Profesional que desee:";
  IDProfesional = obtenerEnteroValidado("");

  profesional = profManager.BuscarPorIDParaPaciente(IDProfesional);
  }while (profesional == "nada");

  estado = true;



   Paciente pac(estado, genero, documento, fechaNac,
               fechaOperacion, nombre, apellido, id, mail,
               diagnostico, patologia, HC, profesional);
  _archivo.guardar(pac);
  return;
  }
  cls();
  cout << "hubo un error en las fechas, por favor vuelva a ingresarlas" << endl;
  }while (true);
}

}

//void PacienteManager::Listar(Paciente paciente){
//	if(paciente.getEstado() == true){
//cout<<"             PACIENTE"<<endl;
//cout<<endl;
//cout << "ID: " << paciente.getID() << endl;
//cout << "Nombre: "<< paciente.getNombre()<< endl;
//cout << "Apellido: "<< paciente.getApellido()<<endl;
//cout << "Fecha Nacimiento: "<< paciente.getFechaNacimiento().toString()<<endl;
//cout << "Fecha de Operacion : "<<paciente.getFechaOperacion().toString()<<endl;
//cout << "Documento: "<<paciente.getDocumento()<<endl;
//cout << "Genero: "<<paciente.getGenero()<<endl;
//cout << "Email: "<< paciente.getEmail()<<endl;
//cout << "Diagnostico: "<<paciente.getDiagnostico()<<endl;
//cout << "Historial clinico: "<< paciente.getHistorialClinico()<<endl;
//cout << "Profesional asignado: "<< paciente.getProfesionalAsignado()<<endl;
//cout<<"--------------------------------------------------"<<endl;
//	}
//}


//void PacienteManager::ListarTodos(){
//ArchivoPaciente archivoP ("archivoPaciente.dat");
//
//int cantidadRegistros = _archivo.getCantidadRegistros();
//
//  for (int i = 0; i<cantidadRegistros; i++)
//  {
//    Paciente reg = _archivo.leerRegistro(i);
//	if(reg.getEstado()==true){
//
//      Listar(reg);
//	}
//      cout << endl;
//  }
//}





void PacienteManager::Listar(Paciente paciente) {
    if (paciente.getEstado() == true) {
        //std::cout << std::left << std::setw(10) << "ID";
        cout<<endl;
         cout << "ID: ";
 cout<<paciente.getID();
        std::cout << std::left << std::setw(20) << "NOMBRE";
        std::cout << std::left << std::setw(20) << "APELLIDO\n";

        // Definir la longitud del campo deseado
int desplazamiento = -10; // Podría ser cualquier valor negativo o positivo

// Imprimir los espacios necesarios antes del campo para desplazarlo hacia la izquierda


        std::cout << std::left << std::setw(10) << paciente.getNombre();
        std::cout << std::left << std::setw(20) << paciente.getApellido() << std::endl;
        // Ajusta los anchos y agrega más campos según sea necesario
    }
}

void PacienteManager::ListarTodos() {
    ArchivoPaciente archivoP("archivoPaciente.dat");

    int cantidadRegistros = _archivo.getCantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        Paciente reg = _archivo.leerRegistro(i);
        if (reg.getEstado() == true) {
            Listar(reg);
            std::cout << std::endl;
        }
    }
}



bool PacienteManager::existeID(char id)
{
    return _archivo.buscar(id)>=0;
}

int PacienteManager::generarID()
{
    return _archivo.getCantidadRegistros() + 1;
}


int esEnteroValido(char cadena[10]) {
    int longitud = strlen(cadena);
    // Quitar espacios, saltos de línea, etcétera
    while (longitud > 0 && isspace(cadena[longitud - 1]))
        longitud--;
    if (longitud <= 0) return 0;
    int i;
    for (i = 0; i < longitud; ++i) {
        // En caso de que sea un guión, y que no esté al inicio, no es válido
        if (cadena[i] == '-' && i > 0) {
            return 0;
        }
        // Si no es dígito, tampoco es válido
        if (!isdigit(cadena[i]) && cadena[i] != '-') {
            return 0;
        }
    }
    return 1;
}

bool PacienteManager::Modificar(Paciente &reg, int i){
bool modifico;

FILE *p;

p = fopen("archivoPaciente.dat", "rb+");

if(p == NULL){
	return false;
}
fseek(p, sizeof(Paciente)*i,0);

modifico = fwrite(&reg,sizeof(reg),1,p);
fclose(p);
return modifico;

}



/*void PacienteManager::Eliminar(Paciente& reg) {
	ArchivoPaciente archivo;
	int id;
	int pos;
	cout << "INGRESE ID A BUSCAR:";
	cin >> id;
	cout << endl;
	pos = archivo.buscar(id);
	if (pos >= 0) {
		// Obtener la cirugia asociada al pac
		CirugiaManager cirugiaManager;
		Cirugia cirugia;
		cirugia = cirugiaManager.ObtenerCirugiaPorIdPaciente(id);

		if (cirugia.getEstadoCirugias() > 1) {
			cout << "NO SE PUEDE ELIMINAR PACIENTE CON CIRUGIA EN PROCEDIMIENTO!." << endl;
			return;
		}


		reg.setEstado(false);
		archivo.guardarModificacion(reg, pos);

		/// Eliminar la cirugía asociada al paciente
		if (cirugia.getID() != -1) {
			cirugiaManager.EliminarCirugia(cirugia);
		}

		cout << "El paciente con el id #" << id << " y su cirugia se han eliminado correctamente." << endl;
	}
	else {
		cout << "NO SE PUDO ELIMINAR EL PACIENTE." << endl;
	}
}*/
void PacienteManager::Eliminar(Paciente& reg) {
	PacienteManager manager;
	ArchivoPaciente archivo;
	int cantRegP = archivo.getCantidadRegistros();
		CirugiaManager cirugiaManager;
		Cirugia cirugia;
	ArchivoCirugia archivoC;
		int cantRegC = archivoC.getCantidadRegistros();
	int id;
	int pos = 0;
	cout << "INGRESE ID A BUSCAR:";
	id = obtenerEnteroValidado("");
	cout << endl;
		for(int i = 0; i<cantRegC; i++){

			cirugia = archivoC.leerRegistro(i);

			for(int j = 0; j<cantRegP; j++){
				reg = archivo.leerRegistro(j);

				if(reg.getID() == id && cirugia.getID() == id && reg.getEstado() == true && cirugia.getEstado() == true){

					if(cirugia.getEstadoCirugias() == 1){

						reg.setEstado(false);
						cirugia.setEstado(false);

						Modificar(reg,i);
						cirugiaManager.EliminarCirugia(cirugia);
					pos = i;
				cout << "ELIMINACION EXITOSA.!"<<endl;
				cout << "Se elimino paciente: " << id << " Y su cirugia."<<endl;
					}else{

			cout << "NO SE PUEDE ELIMINAR PACIENTE Y CIRUGIA EN CURSO"<<endl;
					}

				}


			}

		}

}

void PacienteManager::buscarPacientePorID(){

    PacienteManager reg;
	Paciente paciente;

	ArchivoPaciente archivo ("archivoPaciente.dat");

	int cantRegPaciente = archivo.getCantidadRegistros();
	int id;
	cout <<"Ingrese ID de paciente a buscar: ";
	id = obtenerEnteroValidado(" ");
	bool encontro = false;
	for(int i = 0; i<cantRegPaciente; i++){
		paciente = archivo.leerRegistro(i);

		if(paciente.getID()==id && paciente.getEstado()==true){
			reg.Listar(paciente);
			encontro = true;
		}
	}
			if(encontro == false){
				cout << "NO HAY PACIENTE CON ESE ID .. "<<endl;
			}
cin.ignore();
}
void PacienteManager::copiaDeSeguridadPaciente(){
	int CantRegPaciente = _archivo.getCantidadRegistros();
	Paciente *vec = new Paciente[CantRegPaciente];
	if(vec == nullptr){
		cout << "ERROR .. "<<endl;
		return;
	}
	_archivo.leer(vec,CantRegPaciente);
	_archivoBackUp.vaciar();
	if(_archivoBackUp.guardar(vec, CantRegPaciente)){
		cout << "BackUp CORRECTAMENTE"<<endl;
	}else{
	cout << "ERROR AL REALIZAR BACKUP"<<endl;
	}

	delete [] vec;



 }
void PacienteManager::restaurarBkp(){
int CantRegPaciente = _archivo.getCantidadRegistros();
	Paciente *vec = new Paciente[CantRegPaciente];
	if(vec == nullptr){
		cout << "ERROR .. "<<endl;
		return ;
	}
	_archivoBackUp.leer(vec,CantRegPaciente);
	_archivo.vaciar();
	if(_archivo.guardar(vec, CantRegPaciente)){
		cout << "RESTAURACION BackUp CORRECTAMENTE"<<endl;
	}else{
	cout << "ERROR AL REALIZAR RESTAURACION BACKUP"<<endl;

	}

	delete [] vec;

}
void PacienteManager::modificarMail(){
		PacienteManager reg;
	Paciente paciente;

	ArchivoPaciente archivo ("archivoPaciente.dat");

	int cantRegPaciente = archivo.getCantidadRegistros();
	int id;
	cout <<"Ingrese ID de paciente a buscar: ";
	id=obtenerEnteroValidado("");
    string nuevoMail;


	for(int i = 0; i<cantRegPaciente; i++){
		paciente = archivo.leerRegistro(i);

		if(paciente.getID()==id && paciente.getEstado()==true){

		reg.Listar(paciente);
		}
	}
	cout << endl;
		cout << "Escribir nuevo MAIL : ";
		cin>>nuevoMail;

		cout << "================="<<endl;
		cout << "DATOS MODIFICADOS"<<endl;
		cout << "================="<<endl;

			for(int i = 0; i<cantRegPaciente; i++){
		paciente = archivo.leerRegistro(i);

		if(paciente.getID()==id && paciente.getEstado()==true){

		paciente.setEmail(nuevoMail);
		Modificar(paciente,i);
		reg.Listar(paciente);
		}
		}
cin.ignore();
}

void PacienteManager::convertirAMayusculas(char* apellido) {
    int longitud = std::strlen(apellido);
   int i = 0;
    apellido[i] = std::toupper(apellido[i]);
}

void PacienteManager::BuscarPorApellido(){

    PacienteManager reg;
	Paciente paciente;
	ArchivoPaciente archivo ("archivoPaciente.dat");

	int cantRegPaciente = archivo.getCantidadRegistros();
    string apellido;
	cout <<"Ingrese apellido del paciente a buscar: ";
	getline(cin,apellido);
	bool encontro = false;
		for(int i = 0; i<cantRegPaciente; i++){
		paciente = archivo.leerRegistro(i);
		if(strcasecmp(paciente.getApellido().c_str(),apellido.c_str()) == 0 && paciente.getEstado()==true){
			reg.Listar(paciente);
			cout << "---------------------------------------------" << endl;
			encontro = true;
		}
	}
			if(encontro == false){
				cout << "NO HAY PACIENTE CON ESE APELLIDO .. "<<endl;
			}

}
void PacienteManager::listarPaciente(Paciente paciente){

if(paciente.getEstado() == true){

cout << "ID: " << paciente.getID() << endl;
cout << "Nombre: "<< paciente.getNombre()<< endl;
cout << "Apellido: "<< paciente.getApellido()<<endl;
cout << "Fecha de Operacion : "<<paciente.getFechaOperacion().toString()<<endl;
cout << "Historial clinico: "<< paciente.getHistorialClinico()<<endl;
cout << "Profesional asignado: "<< paciente.getProfesionalAsignado()<<endl;
	}



}
