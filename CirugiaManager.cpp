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
#include <limits> //Proporciona límites y propiedades de datos.
#include <cctype>  // Para usar la función std::isdigit
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
    ArchivoCirugia archivoC("archivoCirugia.dat");
    int cantRegCirugia = archivoC.getCantidadRegistros();
    ArchivoPaciente archivoP("archivoPaciente.dat");
    int cant = archivoP.getCantidadRegistros();
    int contador1 = 0;

    for (int i = 0; i < cant; i++)
    {
        reg = archivoP.leerRegistro(i);
        aux = archivoC.leerUltimaCirugia();  // Utiliza el nuevo método para obtener la última cirugía

        if (id == reg.getID() && id == aux.getID())
        {
            // Mensajes y acciones relacionadas con el estado de la cirugía
            switch (aux.getEstadoCirugias())
            {
            case 1:
                setColor(GREEN);
                cout << "El paciente tiene una Cirugia iniciada." << endl;
                setColor(WHITE);
                return true;

            case 2:
                setColor(RED);
                cout << "El paciente tiene un Estado de Cirugía en Curso." << endl;
                setColor(WHITE);
                return true;

            case 3:
                setColor(YELLOW);
                cout << "El paciente tiene un Estado de Cirugia por Finalizar." << endl;
                setColor(WHITE);
                return true;

            case 4:
                setColor(BLUE);
                cout << "Cirugia Finalizada y Limpieza de Quirofano." << endl;
                setColor(WHITE);
                contador1++;

                  // Preguntar si se desea cargar una nueva cirugía
                char respuesta;
                cout << "Desea cargar una nueva cirugía para este paciente (S/N): ";
                cin >> respuesta;
                cin.ignore();

                if (respuesta == 'N' || respuesta == 'n') {
                    return true;
                }

                return false;

            default:
                // Otro estado no manejado
                return false;

            }
        }
    }

    return false;
}


///================================FIN==========================================




///=============================================================================
/// FUNCION :bool CirugiaManager::validarID(Paciente &reg, int &id)
/// ACCION : Validacion de ID
/// PARAMETROS: Paciente &reg, int &id
///
/// DEVUELVE : bool --> true o false
///-----------------------------------------------------------------------------

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

int CirugiaManager::generarHC()
{
    return _archivo.getCantidadRegistros() + 1000;
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
    ArchivoPaciente archivoPac("archivoPaciente.dat");
    Paciente reg2;
    Cirugia reg1;
    int id;
    string observacion;
    string antibioticos;
    int alergia;
    string implantes;
    string diagnostico;
    string tipoDeCirugia;
    string procedimientos;
    int estadoCirugia;
    Fecha fechaOperacion;
    Fecha fechalimite;
    int idCirugia;
    bool salir=false;
    int estadoAnterior;
    int historiaClinica;


    do
    {

        cout << "Ingrese ID: ";
        id = obtenerEnteroValidado("");


        if (validarID(reg2, reg1, id))
        {


            salir=true;

        }
        else if (!validarID(reg2, id))
        {
            cout << "El paciente no existe." << endl;
            salir=true;
        }
        else{

//        if(PreguntaEstado(reg2, reg1, id))
//        {
//
//            return;
//           }
//        int op;
//        do{
//            cout << "quiere cargar otra cirugia? 1-SI 0-NO ";
//            op = obtenerEnteroValidado("");
//            if (op <0 || op > 1){
//                cout << "error al ingresar valor, vuelva a intentarlo" << endl;
//            }
//        }while(op <0 || op > 1);
//        cls();
//        if(op == 0)
//        {
//            return;
//        }
//
//        }
//        else{
//            return;
//        }




             cout<<endl;
            cout << "Observaciones: ";
            getline(cin, observacion);


            cout << "Antibioticos: ";
            getline(cin, antibioticos);

            do{
            cout << "Alergico: 1 = SI / 0 = NO ";
            alergia = obtenerEnteroValidado("");
            if (alergia <0 || alergia > 1){
                cout << "error al ingresar valor, vuelva a intentarlo" << endl;
            }
            }while (alergia <0 || alergia > 1);



            cout << "Implantes: ";
            getline(cin, implantes);


            cout << "Diagnostico: ";
            getline(cin, diagnostico);


            cout << "Tipo de cirugia: ";
            getline(cin, tipoDeCirugia);


            cout << "Procedimiento: ";
            getline(cin, procedimientos);




            cout << "Fecha de Operacion/visita (dd mm aaaa): ";
            fechaOperacion.Cargar();
            fechalimite.setAnio(2023);
            fechalimite.setMes(11);
            fechalimite.setDia(7);
           // idCirugia = generarID();
            //cout << "IdCirugia : " <<idCirugia<<endl;
            //cout << "IDCirugia: " <<idCirugia<<endl;
//            if(validarID(reg1,idCirugia))
//            {
//                cout << "ID ya utilizado"<<endl;
//
//            }

            if (fechaOperacion.toString("YYYY/MM/DD") <= fechalimite.toString("YYYY/MM/DD"))
            {
                cout << "La fecha de operacion/visita no puede ser antes de Noviembre del 2023. Por favor, ingrese una fecha vï¿½lida." << endl;
            }
            else
            {
                idCirugia = generarID();
                cout << "IdCirugia : " <<idCirugia<<endl;
                estadoCirugia = 1;
                estadoAnterior=0;
                historiaClinica = generarHC();


                Cirugia reg(estadoCirugia, id, observacion, antibioticos, alergia, implantes, diagnostico, tipoDeCirugia, procedimientos, estadoCirugia, fechaOperacion,idCirugia,estadoAnterior,historiaClinica);
                if(_archivo.guardar(reg)==true)
                {
                    salir=true;
                }

            }

            cin.ignore();


}

    }
    while(!salir);



}

///================================FIN==========================================

bool CirugiaManager::PreguntaEstado(Paciente &reg, Cirugia &aux, int &id)
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



            if(id == reg.getID()&& id == aux.getID()&& aux.getEstadoCirugias()== 1 )
            {
                setColor(GREEN);
                cout<<"Inicio de cirugia"<<endl;
                setColor(WHITE);
                Sleep(3000);
                cls();


                return false;

            }
            if(id == reg.getID()&& id == aux.getID() && aux.getEstadoCirugias()== 2)
            {

                setColor(RED);
                cout << "El paciente tiene un Estado de Cirugia en Curso." << endl;

                setColor(WHITE);
                return false;

            }


            if(id == reg.getID()&& id == aux.getID() && aux.getEstadoCirugias()== 3)
            {

                setColor(YELLOW);
                cout<<"El paciente tiene un Estado de Cirugia por Finalizar"<<endl;
                setColor(WHITE);

                return false;

            }
            if(id == reg.getID()&& id == aux.getID() && aux.getEstadoCirugias()== 4)
            {
                setColor(BLUE);
                cout<<"Cirugia Finalizada y Limpieza de Quirofano"<<endl;
                setColor(WHITE);
                Sleep(3000);
                cls();

                return true;

            }

        }
    }
    return false;

}

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
        cout << "Fecha de Operacion : "<<cirugia.getFechaOperacion().toString()<<endl;
        cout << "IdCirugia:" << cirugia.getIdCirugia() << endl;

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
    return _archivo.getCantidadRegistros() + 100;
}
///================================FIN==========================================

///=============================================================================
/// FUNCION :void CirugiaManager::buscarCirugia()
/// ACCION : se asegura de que exista la cirugia
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void CirugiaManager::buscarHC()
{
    PacienteManager reg;
    CirugiaManager regCirugia;
    Paciente paciente;
    Cirugia cirugia;

    ArchivoPaciente archivo("archivoPaciente.dat");
    ArchivoCirugia archivoC("archivoCirugia.dat");

    int cantRegPacientes = archivo.getCantidadRegistros();
    int cantRegCirugias = archivoC.getCantidadRegistros();
    int hc;
    cout << "Ingrese la HC a buscar: ";

    hc = obtenerEnteroValidado("");
    cout << endl;
    bool encontro = false;
    int id;

    for (int i = 0; i < cantRegPacientes; i++)
    {
        paciente = archivo.leerRegistro(i);

        // Only list the patient once if found
        if (paciente.getHistorialClinico() == hc && paciente.getEstado() == true)
        {
            id = paciente.getID();
            reg.Listar(paciente);
            encontro = true;

        }
    }

        // List all surgeries associated with the patient
        for (int j = 0; j < cantRegCirugias; j++)
        {

            cirugia = archivoC.leerRegistro(j);
            if (cirugia.getID() == id && cirugia.getEstado() == true )
            {
                regCirugia.listarCirugiasPorHC(cirugia);
                cout << "-------------------------------------" << endl;
            }
        }


    if (encontro == false)
    {
        cout << "NO SE ENCONTRO PACIENTES CON ESA #HC .. " << endl;
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
    cout << "Procedimiento: " << cirugia.getProcedimientos()<< endl;

    ///vuelve a la normalidad el color
}
///================================FIN==========================================

void CirugiaManager::listarCirugiasPorHC(Cirugia cirugia)
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
    cout << "Fecha de Visita: " << cirugia.getFechaOperacion().getDia()<<"/"<<cirugia.getFechaOperacion().getMes()<<"/"<<cirugia.getFechaOperacion().getAnio()<< endl;
    ///vuelve a la normalidad el color
}



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
    cout<<"ESTADOS DE CIRUGIAS"<<endl;
    cout<<"----------------------"<<endl;
    setColor(GREEN);
    cout<<"1-Inicializacion de Cirugia"<<endl;
    setColor(RED);
    cout<<"2-Cirugia en Curso"<<endl;
    setColor(YELLOW);
    cout<<"3-Cirugia por Finalizar"<<endl;
    setColor(BLUE);
    cout<<"4-Cirugia Finalizar y Limpieza de Quirofano"<<endl;
    setColor(WHITE);
    cout << endl;

    int id;
    cout <<"Ingrese ID de la Cirugia a buscar: ";
    id=obtenerEnteroValidado("");
    bool encontro = false;
    int nuevoCurso;

    for(int i = 0; i<cantRegCirugia; i++)
    {

        cirugia = archivo.leerRegistro(i);

        if(cirugia.getIdCirugia()==id && cirugia.getEstado()==true && cirugia.getEstadoCirugias() != 4)
        {

            reg.Listar(cirugia);
            encontro = true;
        }

    }
    if (encontro){
            cout << "Nuevo Estado de cirugia: ";
    nuevoCurso = obtenerEnteroValidado("");

    cout << "================="<<endl;
    cout << "DATOS MODIFICADOS"<<endl;
    cout << "================="<<endl;



    for(int i=0; i<cantRegCirugia; i++)
    {

        cirugia = archivo.leerRegistro(i);

        if(cirugia.getIdCirugia()==id && cirugia.getEstado()==true)
        {

            cirugia.setEstadoCirugias(nuevoCurso);
            Modificar(cirugia,i);
            reg.Listar(cirugia);
        }
    }


    }
    else{
        cout << "Esa cirugia no se pudo modificar o ya fue finalizada" << endl;
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
        if(aux.getEstadoCirugias() == 1 && id == aux.getIdCirugia()&& aux.getEstado()== true)
        {

            aux.setEstado(false);
            if(reg.Modificar(aux,i))
            {
                cout << "La cirugia con el id #"<<id<< " se ha eliminado correctamente." <<endl;

                return;

            }
        }

    }

    cout << "NO SE PUEDE ELIMINAR CIRUGIA QUE YA ESTA EN PROCEDIMIENTO!."<<endl;

    cin.ignore();
}
///================================FIN==========================================

void CirugiaManager::obtenerProcedimientosXFecha()
{
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


    for(int i = 0; i<cantRegP; i++)
    {

        paciente = archivoP.leerRegistro(i);

        for(int j = 0; j<cantRegC; j++)
        {

            cirugia = archivoC.leerRegistro(j);
            if(cirugia.getFechaOperacion().getAnio()>= anioDeInicio && cirugia.getFechaOperacion().getAnio()<= anioDeFin)
            {
                if(paciente.getID() == cirugia.getID() && paciente.getEstado()==true && cirugia.getEstado()== true)
                {

                    reg.Listar(cirugia);
                }
            }

        }
    }
    cin.ignore();
}

void CirugiaManager::promedioDeEtapas()
{
    Cirugia cirugia;
    Paciente paciente;

    ArchivoCirugia archivoC("archivoCirugia.dat");

    int contadorEstado1 = 0;
    int contadorEstado2 = 0;
    int contadorEstado3 = 0;
    int contadorEstado4 = 0;

    int cantRegC = archivoC.getCantidadRegistros();

    for (int i = 0; i < cantRegC; i++)
    {
        cirugia = archivoC.leerRegistro(i);

        if (cirugia.getEstadoCirugias() == 1 && cirugia.getEstado()==true)
        {
            contadorEstado1++;
        }
        else if (cirugia.getEstadoCirugias() == 2 && cirugia.getEstado() == true)
        {
            contadorEstado2++;
        }
        else if (cirugia.getEstadoCirugias() == 3 && cirugia.getEstado() == true)
        {
            contadorEstado3++;
        }
        else if (cirugia.getEstadoCirugias() == 4 && cirugia.getEstado() == true)
        {
            contadorEstado4++;
        }
    }

    float totalRegistros = (float)cantRegC;

    float porcentajeEstado1 = (contadorEstado1 / totalRegistros) * 100;
    float porcentajeEstado2 = (contadorEstado2 / totalRegistros) * 100;
    float porcentajeEstado3 = (contadorEstado3 / totalRegistros) * 100;
    float porcentajeEstado4 = (contadorEstado4 / totalRegistros) * 100;

    setColor(GREEN);
    cout << "PORCENTAJE ESTADO #1 (VERDE): " << porcentajeEstado1 << "%" << endl;
    setColor(RED);
    cout << "PORCENTAJE ESTADO #2 (ROJO): " << porcentajeEstado2 << "%" << endl;
    setColor(YELLOW);
    cout << "PORCENTAJE ESTADO #3 (AMARILLO): " << porcentajeEstado3 << "%" << endl;
    setColor(BLUE);
    cout << "PORCENTAJE ESTADO #4 (AZUL): " << porcentajeEstado4 << "%" << endl;
    setColor(WHITE);
}
Cirugia CirugiaManager::ObtenerCirugiaPorIdPaciente(int idPaciente)
{
    ArchivoCirugia archivo("archivoCirugia.dat");
    int cantReg = archivo.getCantidadRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        Cirugia aux = archivo.leerRegistro(i);
        if (aux.getEstadoCirugias() == 1 && aux.getID() == idPaciente && aux.getEstado() == true)
        {
            return aux;
        }
    }

    Cirugia cirugiaNoEncontrada;
    cirugiaNoEncontrada.setID(-1);
    return cirugiaNoEncontrada;
}
