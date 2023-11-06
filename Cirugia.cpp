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
// Aqui se desarrollan la Metodos de la class Cirugia
//
/////////////////////////////////////////////////////////////////////////////////

#include <string>
using namespace std;
#include <cstring>
#include <string>
#include "Cirugia.h"
//Constructores
Cirugia::Cirugia(){
}

Cirugia::Cirugia(bool estado, int id, std::string obs, std::string anti, bool alergia, std::string implan, std::string diagnostico, std::string tipo, std::string procedimiento,int estadoDeCirugias){
_estado = estado;
strcpy(_observacion, obs.c_str());
strcpy(_antibioticos, anti.c_str());
_alergia = alergia;
strcpy(_implantes, implan.c_str());
strcpy(_diagnostico, diagnostico.c_str());
strcpy(_tipoDeCirugia, tipo.c_str());
strcpy(_procedimientos, procedimiento.c_str());
_id = id;
_estadosDeCirugias = estadoDeCirugias;
			}
///================================FIN==========================================

// setters
void Cirugia::setEstado(bool e){
_estado = e;
}
void Cirugia::setID(int id) {
    _id = id;
}
void Cirugia::setObservaciones(std::string observaciones){
strcpy(_observacion,observaciones.c_str());
}
void Cirugia::setAntibioticos (std::string antibioticos){
strcpy(_antibioticos,antibioticos.c_str());
}
void Cirugia::setAlergia(bool alergia){
_alergia = alergia;
}
void Cirugia::setImplantes (std::string implantes){
	strcpy(_implantes,implantes.c_str());
}
void Cirugia::setDiagnostico (std::string diagnostico){
strcpy(_diagnostico,diagnostico.c_str());
}
void Cirugia::setTipoDeCirugia (std::string tipoDeCirugia){
	strcpy(_tipoDeCirugia,tipoDeCirugia.c_str());
}
void Cirugia::setProcedimientos (std::string procedimientos){
strcpy(_procedimientos,procedimientos.c_str());
}
void Cirugia::setEstadoCirugias(int estadoCirugia){
_estadosDeCirugias = estadoCirugia;
}
///================================FIN==========================================

// getters
bool Cirugia::getEstado(){
return _estado;
}
int Cirugia::getID(){
    return _id;
}

string Cirugia::getObservaciones(){
    string aux = _observacion;
    return aux;
}
string Cirugia::getAntibioticos (){
    string aux = _antibioticos;
return aux;
}
bool Cirugia::getAlergia(){
return _alergia;
}
string Cirugia::getImplantes(){
    string aux = _implantes;
return aux;
}
string Cirugia::getDiagnostico(){
    string aux = _diagnostico;
return aux;
}
string Cirugia::getTipoDeCirugia(){
    string aux = _tipoDeCirugia;
return aux;
}
string Cirugia::getProcedimientos(){
    string aux = _procedimientos;
return aux;
}
int Cirugia::getEstadoCirugias(){
return _estadosDeCirugias;
}
///================================FIN==========================================
