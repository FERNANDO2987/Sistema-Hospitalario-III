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
// Aqui se desarrollan los metodos de la class QuirofanoManager.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;
#include <cctype>
#include "QuirofanoManager.h"
#include "Quirofano.h"
#include "Tiempo.h"

bool QuirofanoManager::validarID(Quirofano &reg, int id){

	ArchivoQuirofano archivoQ ("archivoQuirofano.dat");
	int cant = archivoQ.getCantidadRegistros();
	for(int i  =0 ; i<cant; i++){
		reg = archivoQ.leerRegistro(i);

	if(reg.getID()== id){
		return true;
	}
	}

	return false;

}
bool esEnteroValido1(const string& input) {
  for (char c : input) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}
int obtenerEnteroValidado1(const string& mensaje) {
  string input;
  cout << mensaje;
  cin >> input;
  cin.ignore();

  while (!esEnteroValido1(input)) {
    cout << "Ingrese en formato numerico. Por favor, intentelo nuevamente: ";
    cin >> input;
    cin.ignore();
  }

  return stoi(input);
}
void QuirofanoManager::Cargar(){
		Quirofano reg1;
		Tiempo reg;
		int id;
        int NroCama;
        string NroQuirofano;
        bool Ocupado;
        Tiempo tiempoProcedimiento;

        cout << "Ingrese ID: ";
        id = obtenerEnteroValidado1("");
        if(validarID(reg1,id)){
			cout << "ID YA UTILIZADO"<<endl;
        }else{

        cout << "Numero de cama: ";
        NroCama = obtenerEnteroValidado1("");
		cout << "Ingrese numero de quirofano : ";
		getline(cin,NroQuirofano);
		cout << "Quirofano ocupado : 1/SI - 0/NO ";
		cin>>Ocupado;
		if (Ocupado==1){
        cout << "Ingrese tiempo : "<<endl;
		cin.ignore();
		reg.Cargar();
		}
		else{
            reg.setHoras(0);
            reg.setMinutos(0);
            reg.setSegundos(0);
		}

		Quirofano aux (id, NroCama,NroQuirofano, Ocupado, reg);

		_archivoQuirofano.guardar(aux);

}
}
void QuirofanoManager::Listar(Quirofano quirofano){

		cout << "ID: " << quirofano.getID() << endl;
        cout << "Numero de cama: " << quirofano.getNroCama() <<endl;
		cout << "Numero de quirofano : " << quirofano.getNroQuirofano() << endl;
		cout << "Quirofano ocupado : 1/SI - 0/NO " << quirofano.getOcupado() << endl;
		cout << "Tiempo : ";
		quirofano.getTiempoProcedimiento().Mostrar();


}
void QuirofanoManager::ListarTodos(){

int cantidadRegistros = _archivoQuirofano.getCantidadRegistros();
    cout<<"==============="<<endl;
    cout<<"  QUIROFANOS: "<<endl;
    cout<<"==============="<<endl;
    cout<<endl;
  for (int i = 0; i<cantidadRegistros; i++)
  {
    Quirofano reg = _archivoQuirofano.leerRegistro(i);

      Listar(reg);
      cout<<endl;
      cout <<"---------------------------------------"<<endl;
  }
}

///BUSCAR QUIROFANO POR ID

void QuirofanoManager::BuscarPorID()
{

    QuirofanoManager reg;
    Quirofano _quirofano;

    ArchivoQuirofano archivoQuirofano ("archivoQuirofano.dat");

    int cantRegQuirofano = archivoQuirofano.getCantidadRegistros();
    int id;
    cout <<"INGRESE EL ID DEL QUIROFANO A BUSCAR: ";
    id=obtenerEnteroValidado1("");
    bool encontro = false;
    for(int i = 0; i<cantRegQuirofano; i++)
    {
        _quirofano = archivoQuirofano.leerRegistro(i);

        if(_quirofano.getID()==id )
        {
            reg.Listar(_quirofano);
            encontro = true;
        }
    }
    if(encontro == false)
    {
        cout << "NO HAY UN QUIROFANO CON ESE ID .. "<<endl;
    }


}


bool QuirofanoManager::existeID(int id)
{
    return _archivoQuirofano.buscar(id)>=0;
}

int QuirofanoManager::generarID()
{
    return _archivoQuirofano.getCantidadRegistros() + 1;
}


void QuirofanoManager::quirofanosOcupados(){

	QuirofanoManager manager;

	Quirofano reg;
	 ArchivoQuirofano ArchivoQ ("archivoQuirofano.dat");

	 int cantReg = ArchivoQ.getCantidadRegistros();
	cout << " QUIROFANOS DISPONIBLES: "<<endl;
	cout << "=========================" <<endl;
	 for(int i = 0; i<cantReg; i++){

		reg = ArchivoQ.leerRegistro(i);
		if(reg.getOcupado() == false){

			manager.Listar(reg);
				cout << endl;
		cout << "=========================" <<endl;
		}


	 }



}
