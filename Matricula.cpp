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
// Aqui se desarrollan los metodos de la class Matricula
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;
#include "Matricula.h"


//Setters
void Matricula::setID(int _id){
id=_id;
}
void Matricula::setMatriculaNacional(string _matriculaNacional){
matriculaNacional=_matriculaNacional;
}
void Matricula::setMatriculaProvincial (string _matriculaProvincial){
matriculaProvincial=_matriculaProvincial;
}
///================================FIN==========================================

//Getters
int Matricula::getID(){
return id;
}

string Matricula::getMatriculaNacional(){
return matriculaNacional;
}

string Matricula::getMatriculaProvincial(){
return matriculaProvincial;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void Matricula::Cargar()
/// ACCION : carga la matricula
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------

void Matricula::Cargar(){
    int opc;
cout << "ingrese su ID:";
cin >> id;
cout << "que matricula tiene? 1- provincial 2- nacional:";

do{
cin >> opc;
if (opc==1){
    cout << "ingrese el numero de su matricula:";
    cin >> matriculaProvincial;
}
else{
    if (opc==2){
        cout << "ingrese el numero de su matricula:";
        cin >> matriculaNacional;
    }
    else {
        cout << "esa opcion no estaba, volve a elegir";
    }
}
}while (opc!= 1 || opc!= 2);

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void Matricula::Mostrar()
/// ACCION : muestra la matricula
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Matricula::Mostrar(){

cout << "su id es: " << id << endl;
cout << "su matricula provincial es: " << matriculaProvincial;
cout << "su matricula nacional es: " << matriculaNacional;

}
///================================FIN==========================================
