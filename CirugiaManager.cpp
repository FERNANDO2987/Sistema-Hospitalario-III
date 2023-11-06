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
// Aqui se desarrollan la Metodos de la class CirugiaManager
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;
#include "CirugiaManager.h"
#include "PacienteManager.h"
#include "rlutil.h"
using namespace rlutil;


///=============================================================================
/// FUNCION :bool CirugiaManager::Modificar(Cirugia &reg, int i)
/// ACCION : Modifica archivo cirugia
/// PARAMETROS: Cirugia &reg, int i
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------
bool CirugiaManager::Modificar(Cirugia &reg, int i)
{
    bool modifico;

    FILE *p;

    p = fopen("archivoCirugia.dat", "rb+");

    if(p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Cirugia)*i,0);

    modifico = fwrite(&reg,sizeof(reg),1,p);
    fclose(p);
    return modifico;

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :bool CirugiaManager::validarID(Paciente &reg, Cirugia &aux,int &id)
/// ACCION : Validacion de ID
/// PARAMETROS: Paciente &reg, Cirugia &aux,int &id
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------
bool CirugiaManager::validarID(Paciente &reg, Cirugia &aux, int &id)
{
    ArchivoCirugia archivoC ("archivoCirugia.dat");
    int cantRegCirugia = archivoC.getCantidadRegistros();
    ArchivoPaciente archivoP ("archivoPaciente.dat");
    int cant = archivoP.getCantidadRegistros();
    for(int i  =0 ; i<cant; i++)
    {
        reg = archivoP.leerRegistro(i);
        for(int j = 0; j<cantRegCirugia; j++)
        {
            aux = archivoC.leerRegistro(j);

            if(id == reg.getID()&& id == aux.getID())
            {
                return true;

            }

        }
    }

    return false;
}
///================================FIN==========================================


bool CirugiaManager::validarID(Paciente &reg, int &id)
{
    ArchivoPaciente archivoP ("archivoPaciente.dat");
    int cant = archivoP.getCantidadRegistros();
    for(int i  =0 ; i<cant; i++)
    {
        reg=archivoP.leerRegistro(i);
            if(id == reg.getID())
            {
                return true;

            }
    }

    return false;
}
///=============================================================================
/// FUNCION :void CirugiaManager::Cargar()
/// ACCION : Cargar una cirugia
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void CirugiaManager::Cargar()
{
    ArchivoPaciente archivoPac ("archivoPaciente.dat");
    Paciente paci;
    Paciente reg2;
    Cirugia reg1;
    bool estado;
    int id;
    string observacion;
    string antibioticos;
    bool alergia;
    string implantes;
    string diagnostico;
    string tipoDeCirugia;
    string procedimientos;
    int estadoCirugia;
//no esta hecho algo asi como reg2 = archivopac
    cout << "Ingrese ID:";
    //cin>>id;
    id = obtenerEnteroValidado("");
    if(validarID(reg2, reg1, id) == true)
    {
        cout << "EL ID YA TIENE UNA CIRUGIA PENDIENTE";
    }
    else
    { if (validarID(reg2,id)== false){
        cout << "el paciente no existe";
    }else{

       // for (int i=0;i<archivoPac.getCantidadRegistros();i++){
         //   paci = archivoPac.leerRegistro(i);
           // if (id == paci.getID()){
               // cin.ignore();
                cout << "Observaciones: ";
                getline(cin,observacion);
                cout << "Antibioticos: ";
                getline(cin,antibioticos);
                cout << "Alergico: 1 = SI / 0 = NO ";
                cin>>alergia;
                cin.ignore();
                cout << "Implantes: ";
                getline(cin,implantes);
                cout << "Diagnostico: ";
                getline(cin,diagnostico);
                cout << "Tipo de cirugia: ";
                getline(cin,tipoDeCirugia);
                cout << "Procedimiento: ";
                getline(cin,procedimientos);

                estado = true;
                //cout << "Estado de cirugia: ";
                estadoCirugia = 1;

Cirugia reg( estado, id,observacion,antibioticos, alergia, implantes, diagnostico, tipoDeCirugia, procedimientos, estadoCirugia);

    _archivo.guardar(reg);

            //}
            //else{
             //   cout << "no hay paciente con ese ID, no se pudo crear la cirugia";
               // return;
            //}
        }
    }
    cin.ignore();
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::Listar(Cirugia cirugia)
/// ACCION : Lista la cirugia
/// PARAMETROS: Cirugia cirugia
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void CirugiaManager::Listar(Cirugia cirugia)
{
    if (cirugia.getEstado()==true)
    {
        int estado = cirugia.getEstadoCirugias();
        switch(estado)
        {
        case 1:

            setColor(GREEN);
            cout<<"            INICIO DE CIRUGIA: "<<endl;
            cout<<endl;

            break;
        case 2:

            setColor(RED);

            cout<<"            CIRUGIA EN CURSO: "<<endl;
            cout<<endl;

            break;
        case 3:
            setColor(YELLOW);
            cout<<"            CIRUGIA POR FINALIZAR: "<<endl;
            cout<<endl;

            break;
        case 4:
            setColor(BLUE);
            cout<<"            CIRUGIA FINALIZADA Y LIMPIEZA DE QUIROFANO: "<<endl;
            cout<<endl;

            break;

        }
        cout << "Ingrese ID:" << cirugia.getID() << endl;
        cout << "Observaciones: " << cirugia.getObservaciones() << endl;
        cout << "Antibioticos: " << cirugia.getAntibioticos() << endl;
        cout << "Alergico: 1 = SI / 0 = NO " << cirugia.getAlergia() << endl;
        cout << "Implantes: " << cirugia.getImplantes() << endl;
        cout << "Diagnostico: " << cirugia.getDiagnostico() << endl;
        cout << "Tipo de cirgugia: " << cirugia.getTipoDeCirugia() << endl;
        cout << "Procedimiento: " << cirugia.getProcedimientos() << endl;
        cout << "Estado de cirugia: "<< cirugia.getEstadoCirugias() << endl;
        cout<<"---------------------------------------------------------------------"<<endl;
    }

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::ListarTodos()
/// ACCION : Lista todas las cirugias
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void CirugiaManager::ListarTodos()
{

    int cantidadRegistros = _archivo.getCantidadRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Cirugia reg = _archivo.leerRegistro(i);
        if(reg.getEstado()==true)
        {

            Listar(reg);
            cout << endl;
        }
    }
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :bool CirugiaManager::existeID(int id)
/// ACCION : Se asegura que exista el ID
/// PARAMETROS: int id
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------

bool CirugiaManager::existeID(int id)
{
    return _archivo.buscar(id)>=0;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :int CirugiaManager::generarID()
/// ACCION : genera un id a partir de la cantidad de registros+1
/// PARAMETROS:
///
/// DEVUELVE : int --> devuelve un id
///-----------------------------------------------------------------------------

int CirugiaManager::generarID()
{
    return _archivo.getCantidadRegistros() + 1;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::buscarCirugia()
/// ACCION : se asegura de que exista la cirugia
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void CirugiaManager::buscarCirugia()
{
    CirugiaManager reg;
    Cirugia cirugia;

    ArchivoCirugia archivo ("archivoCirugia.dat");

    int cantRegCirugias = archivo.getCantidadRegistros();
    int id;
    cout <<"Ingrese ID de la cirugia a buscar: ";
    id=obtenerEnteroValidado("");
    bool encontro = false;
    for(int i = 0; i<cantRegCirugias; i++)
    {
        cirugia = archivo.leerRegistro(i);

        if(cirugia.getID()==id && cirugia.getEstado()==true)
        {
            reg.Listar(cirugia);
            encontro = true;
        }
    }
    if(encontro == false)
    {
        cout << "NO SE ENCONTRO CIRUGIAS CON ESE #ID .. "<<endl;
    }

}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::mostrarCirugiaYPaciente()
/// ACCION : lista cirugia y paciente
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------

void CirugiaManager::mostrarCirugiaYPaciente()
{
    CirugiaManager reg;
    Cirugia cirugia;
    ArchivoCirugia archivo ("archivoCirugia.dat");
    int cantRegCirugias = archivo.getCantidadRegistros();
    PacienteManager aux;
    Paciente paciente;
    ArchivoPaciente archivoP("archivoPaciente.dat");
    int canteRegPacientes = archivoP.getCantidadRegistros();

    int id;
    cout <<"Ingrese ID : ";
    id=obtenerEnteroValidado("");
    for(int i = 0; i<canteRegPacientes; i++)
    {

        paciente = archivoP.leerRegistro(i);
        for(int j = 0; j<cantRegCirugias; j++)
        {

            cirugia = archivo.leerRegistro(j);

            if(id == paciente.getID()&& paciente.getEstado() == true && id == cirugia.getID() && cirugia.getEstado()==true)
            {

                reg.listarCirugias(cirugia);
                cout << "-------------------------------" << endl;
                aux.listarPaciente(paciente);
                return;
            }
        }
    }
cout << "NO HAY RESULTADOS EN LA BUSQUEDA.." <<endl;
cin.ignore();
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :bool CirugiaManager::listarCirugias(Cirugia cirugia)
/// ACCION : Lista cirugia con su color correspondiente
/// PARAMETROS: Cirugia cirugia
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------
void CirugiaManager::listarCirugias(Cirugia cirugia)
{

    int estado = cirugia.getEstadoCirugias();
    switch(estado)
    {
    case 1:
        setColor(GREEN);
        break;
    case 2:
        setColor(RED);
        break;
    case 3:
        setColor(YELLOW);
        break;
    case 4:
        setColor(BLUE);
        break;
    default:
        setColor(WHITE);
        break;
    }
    cout << "Observaciones: " << cirugia.getObservaciones() << endl;
    cout << "Antibioticos: " << cirugia.getAntibioticos() << endl;
    cout << "Alergico: 1 = SI / 0 = NO " << cirugia.getAlergia() << endl;
    cout << "Implantes: " << cirugia.getImplantes() << endl;
    cout << "Diagnostico: " << cirugia.getDiagnostico() << endl;
    cout << "Tipo de cirgugia: " << cirugia.getTipoDeCirugia() << endl;
    cout << "Procedimiento: " << cirugia.getProcedimientos() << endl;
    ///vuelve a la normalidad el color
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::modificarCursoDeCirugia()
/// ACCION : modifica el curso y el color de la cirugia
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------

void CirugiaManager::modificarCursoDeCirugia()
{
    CirugiaManager reg;
    Cirugia cirugia;

    ArchivoCirugia archivo ("archivoCirugia.dat");

    int cantRegCirugia = archivo.getCantidadRegistros();
    int id;
    cout <<"Ingrese ID de paciente a buscar: ";
    id=obtenerEnteroValidado("");

    int nuevoCurso;

    for(int i = 0; i<cantRegCirugia; i++)
    {

        //cirugia = archivo.leerRegistro(i);

        if(cirugia.getID()==id && cirugia.getEstado()==true)
        {

            reg.Listar(cirugia);
        }
    }
    cout << endl;
    cout << "Nuevo Estado de cirugia: ";
    cin>>nuevoCurso;

    cout << "================="<<endl;
    cout << "DATOS MODIFICADOS"<<endl;
    cout << "================="<<endl;

    for(int i=0; i<cantRegCirugia; i++)
    {

        cirugia = archivo.leerRegistro(i);

        if(cirugia.getID()==id && cirugia.getEstado()==true)
        {

            cirugia.setEstadoCirugias(nuevoCurso);
            Modificar(cirugia,i);
            reg.Listar(cirugia);
        }
    }
cin.ignore();
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::EliminarCirugia(Cirugia &aux)
/// ACCION : elimina cirugia
/// PARAMETROS: Cirugia &aux
///
/// DEVUELVE :
///-----------------------------------------------------------------------------

void CirugiaManager::EliminarCirugia(Cirugia &aux)
{
    CirugiaManager reg;
    ArchivoCirugia archivo("archivoCirugia.dat");
    int i, id;
    int cantReg = archivo.getCantidadRegistros();

    cout << "INGRESE ID DE LA CIRUGIA A ELIMINAR: ";
    cin>>id;
    for( i = 0; i<cantReg; i++)
    {
        aux = archivo.leerRegistro(i);
        if(aux.getEstadoCirugias() == 1 && id == aux.getID()&& aux.getEstado()== true)
        {

            aux.setEstado(false);
           if(reg.Modificar(aux,i)){
        cout << "La cirugia con el id #"<<id<< " se ha eliminado correctamente." <<endl;

        return;

           }
        }

    }

        cout << "NO SE PUEDE ELIMINAR CIRUGIA QUE YA ESTA EN PROCEDIMIENTO!."<<endl;

cin.ignore();
}
///================================FIN==========================================

void CirugiaManager::obtenerProcedimientosXFecha(){
	Fecha fecha;
	Fecha fechaF;
	Cirugia cirugia;
	CirugiaManager reg;
    ArchivoCirugia archivoC("archivoCirugia.dat");

    PacienteManager aux;
	Paciente paciente;
	ArchivoPaciente archivoP ("archivoPaciente.dat");

	int cantRegP = archivoP.getCantidadRegistros();
	int cantRegC = archivoC.getCantidadRegistros();
	int anioDeInicio;
	int anioDeFin;
	cout << "INGRESE FECHA DE INICIO :";
	cin>>anioDeInicio;

	cout << "INGRESE FECHA DE FINALIZACION: ";
	cin>>anioDeFin;


	for(int i = 0; i<cantRegP; i++){

		paciente = archivoP.leerRegistro(i);

		for(int j = 0; j<cantRegC; j++){

			cirugia = archivoC.leerRegistro(j);
			if(paciente.getFechaOperacion().getAnio()>= anioDeInicio && paciente.getFechaOperacion().getAnio()<= anioDeFin){
				if(paciente.getID() == cirugia.getID() && paciente.getEstado()==true && cirugia.getEstado()== true){

					reg.Listar(cirugia);
				}
			}

		}
	}
cin.ignore();
}

void CirugiaManager::promedioDeEtapas() {
    Cirugia cirugia;
    Paciente paciente;

    ArchivoCirugia archivoC("archivoCirugia.dat");

    int contadorEstado1 = 0;
    int contadorEstado2 = 0;
    int contadorEstado3 = 0;
    int contadorEstado4 = 0;

    int cantRegC = archivoC.getCantidadRegistros();

    for (int i = 0; i < cantRegC; i++) {
        cirugia = archivoC.leerRegistro(i);

        if (cirugia.getEstadoCirugias() == 1 && cirugia.getEstado()==true) {
            contadorEstado1++;
        }
        else if (cirugia.getEstadoCirugias() == 2 && cirugia.getEstado() == true) {
            contadorEstado2++;
        }
        else if (cirugia.getEstadoCirugias() == 3 && cirugia.getEstado() == true) {
            contadorEstado3++;
        }
        else if (cirugia.getEstadoCirugias() == 4 && cirugia.getEstado() == true) {
            contadorEstado4++;
        }
    }

    float totalRegistros = (float)cantRegC;

    float porcentajeEstado1 = (contadorEstado1 / totalRegistros) * 100;
    float porcentajeEstado2 = (contadorEstado2 / totalRegistros) * 100;
    float porcentajeEstado3 = (contadorEstado3 / totalRegistros) * 100;
    float porcentajeEstado4 = (contadorEstado4 / totalRegistros) * 100;

    cout << "PORCENTAJE ESTADO #1 (VERDE): " << porcentajeEstado1 << "%" << endl;
    cout << "PORCENTAJE ESTADO #2 (ROJO): " << porcentajeEstado2 << "%" << endl;
    cout << "PORCENTAJE ESTADO #3 (AMARILLO): " << porcentajeEstado3 << "%" << endl;
    cout << "PORCENTAJE ESTADO #4 (AZUL): " << porcentajeEstado4 << "%" << endl;
}
Cirugia CirugiaManager::ObtenerCirugiaPorIdPaciente(int idPaciente) {
	ArchivoCirugia archivo("archivoCirugia.dat");
	int cantReg = archivo.getCantidadRegistros();

	for (int i = 0; i < cantReg; i++) {
		Cirugia aux = archivo.leerRegistro(i);
		if (aux.getEstadoCirugias() == 1 && aux.getID() == idPaciente && aux.getEstado() == true) {
			return aux;
		}
	}

	Cirugia cirugiaNoEncontrada;
	cirugiaNoEncontrada.setID(-1);
	return cirugiaNoEncontrada;
}
