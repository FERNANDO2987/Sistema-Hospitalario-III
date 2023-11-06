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
// Aqui se desarrolla las opciones distintas de los Menues y la Presentacion
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include <time.h>
#include "rlutil.h"
#include "Menu.h"
#include "ArchivoPaciente.h"
#include "PacienteManager.h"
#include "CirugiaManager.h"
#include "QuirofanoManager.h"
#include "Fecha.h"
#include "Tiempo.h"
#include "ProfesionalManager.h"

using namespace rlutil;

///=============================================================================
/// FUNCION :void Menu::Presentacion()
/// ACCION : Muestra una introduccion
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------

void Menu::Presentacion()
{
    setColor(WHITE);
    system("cls");
    gotoxy(45, 9);
    cout << "-------------------------------------" << endl;
    gotoxy(45, 10);
    cout << "|        Sistema Hospitalario        |" << endl;
    gotoxy(45, 11);
    cout << "-------------------------------------" << endl;
    gotoxy(45, 12);
    cout << "|                                    |" << endl;
    gotoxy(45, 13);
    cout << "|     Bienvenido al sistema          |" << endl;
    gotoxy(45, 14);
    cout << "|     hospitalario.                  |" << endl;
    gotoxy(45, 15);
    cout << "|                                    |" << endl;
    gotoxy(45, 16);
    cout << "|     Este sistema te permite        |" << endl;
    gotoxy(45, 17);
    cout << "|     gestionar informacion          |" << endl;
    gotoxy(45, 18);
    cout << "|     relacionada con pacientes,     |" << endl;
    gotoxy(45, 19);
    cout << "|     medicos, cirugias y mas.       |" << endl;
    gotoxy(45, 20);
    cout << "|                                    |" << endl;
    gotoxy(45, 21);
    cout << "-------------------------------------" << endl;
    gotoxy(45, 22);
    // Sleep(3000); ///Detiene la pantalla 3 segundos
    // system("pause > nul"); /// Limpiar la pantalla después del retraso


  gotoxy(10, 25);
 cout<<"AUTORES: "<<endl;
  gotoxy(10, 26);
 cout<<"         RAMIREZ MATIAS HERNAN. "<<endl;
  gotoxy(10, 27);
 cout<<"         ROMERO NAHUEL FRANCO. "<<endl;
  gotoxy(10, 28);
 cout<<"         PALACIOS FERNANDO GUILLERMO. "<<endl;

}

///FUNCION PARA SELECIONAR COLOR

void showItem(const char* text, int posx, int posy, bool selected)
{
    if(selected)
    {
        setBackgroundColor(COLORES::MAGENTA); ///color de fondo

    }
    else
    {
        setBackgroundColor(COLORES::BLACK); ///color de fondo
    }

    locate(posx,posy);
    cout<<text<<endl;
    setBackgroundColor(COLORES::BLACK); ///vuleve al estado normal del color de fondo

}

///================================FIN==========================================

///=============================================================================
/// FUNCION : void Menu::MenuPrincipal()
/// ACCION : Muestra todos los menues
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Menu::MenuPrincipal()
{
    Menu menu;
    PacienteManager _pacienteManager;



    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" MENU PACIENTE       ",40, 11, y==0);
        showItem(" MENU PROFESIONAL    ",40, 12, y==1);
        showItem(" MENU CIRUGIA        ",40, 13, y==2);
        showItem(" MENU QUIROFANO      ",40, 14, y==3);
        showItem(" INFORMES            ",40, 15, y==4);
        showItem(" SALIR               ",40, 16, y==5);

        /*
        locate(38,11 +y);
        cout<<(char)175<<endl;
        int key = getkey(); ///Devuelve un entero

        cout<<"key: "<<key;
        anykey(); ///Espera que el usuario ingrese una tecla
        */

        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>5) ///limitacion de movimiento
            {
                y=5;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
                MenuPaciente();
                break;

            case 1:
                cls();
                MenuProfesional();
                break;

            case 2:
                cls();
                MenuCirugia();
                break;

            case 3:
                cls();
                MenuQuirofano();
                break;
			case 4: ///Sale del sistema
				cls();
                MenuInformes();
                break;

            case 5: ///Sale del sistema
                op=0;

                break;

            default:
                break;
            }

            break;



        default:
            break;
        }




    }
    while(op!=0);


}

///================================FIN==========================================

///=============================================================================
/// FUNCION : void Menu::MenuPaciente()
/// ACCION : Muestra el menu paciente
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Menu::MenuPaciente()
{
    PacienteManager paciente;
    ArchivoPaciente archiPaciente;
    Paciente pacient;
    Cirugia reg;




    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" CARGAR PACIENTE ",40, 11, y==0);
        showItem(" BUSCAR PACIENTE POR ID ",40, 12, y==1);
        showItem(" BUSCAR PACIENTE POR APELLIDO ",40, 13, y==2);
        showItem(" LISTAR TODOS LOS PACIENTES ",40, 14, y==3);
        showItem(" ELIMINAR PACIENTE POR ID ",40, 15, y==4);
        showItem(" MODIFICAR MAIL ",40, 16, y==5);
        showItem(" CONFIGURACION ",40, 17, y==6);
        showItem(" VOLVER  ",40, 18, y==7);


        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>7) ///limitacion de movimiento
            {
                y=7;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
                paciente.Cargar();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 1:
                cls();
                paciente.buscarPacientePorID();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 2:
                cls();
                paciente.BuscarPorApellido();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 3:
                cls();
                paciente.ListarTodos();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
                //se agrega comentario
            case 4:
                cls();
                paciente.Eliminar(pacient);
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 5:
                cls();
                paciente.modificarMail();
               cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 6:
                cls();
                MenuConfiguracion();

                //  system("pause");
                cls();
                break;

            case 7:
                cls();
                op=0;
                break;

            default:
                break;
            }

            break;




        default:
            break;
        }




    }
    while(op!=0);

}

///================================FIN==========================================

///=============================================================================
/// FUNCION : void Menu::MenuProfesional()
/// ACCION : Muestra el menu profesional
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Menu::MenuProfesional()
{
    ProfesionalManager Profesi;
    ArchivoProfesional archiProfe;
    Profesional prof;


    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" CARGAR PROFESIONAL ",40, 11, y==0);
        showItem(" BUSCAR PROFESIONAL POR ID ",40, 12, y==1);
        showItem(" LISTAR TODOS LOS PROFESIONAL  ",40, 13, y==2);
        showItem(" LISTAR PACIENTES POR PROFESIONAL ",40, 14, y==3);
        showItem(" VOLVER  ",40, 15, y==4);


        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>4) ///limitacion de movimiento
            {
                y=4;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
                Profesi.Cargar();
               cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;

            case 1:
                cls();
                Profesi.BuscarPorID();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;

            case 2:
                cls();
                Profesi.ListarTodos();
               cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 3:
                cls();
                Profesi.BuscarCirugiaPorApellidoProfesional();
               cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;

            case 4:
                cls();
                op=0;
                break;

            default:
                break;
            }

            break;



        default:
            break;
        }




    }
    while(op!=0);


}

///================================FIN==========================================

///=============================================================================
/// FUNCION : void Menu::MenuQuirofano()
/// ACCION : Muestra el menu quirofano
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------

void Menu::MenuQuirofano()
{
    QuirofanoManager _quirofanoManager;


    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" CARGAR QUIROFANO ",40, 11, y==0);
        showItem(" BUSCAR QUIROFANO POR ID ",40, 12, y==1);
        showItem(" LISTAR TODOS LOS QUIROFANO ",40, 13, y==2);
        showItem(" VOLVER  ",40, 14, y==3);


        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>3) ///limitacion de movimiento
            {
                y=3;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
                _quirofanoManager.Cargar();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);

                break;

            case 1:
                cls();
                _quirofanoManager.BuscarPorID();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);

                break;

            case 2:
                cls();
                _quirofanoManager.ListarTodos();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);

                break;

            case 3:
                cls();
                op=0;
                break;

            default:
                break;
            }

            break;



        default:
            break;
        }




    }
    while(op!=0);
}

///================================FIN==========================================

///=============================================================================
/// FUNCION : void Menu::MenuCirugia()
/// ACCION : Muestra el menu cirugia
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Menu::MenuCirugia()
{

    CirugiaManager _cirugiaManager;
    PacienteManager _pacienteManager;
    Cirugia cirugia;

    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" CARGAR CIRUGIA ",40, 11, y==0);
        showItem(" BUSCAR CIRUGIA POR ID ",40, 12, y==1);
        showItem(" LISTADO DE CIRUGIAS ",40, 13, y==2);
        showItem(" CAMBIAR ESTADO DE LA CIRUGIA ",40, 14, y==3);
        showItem(" MOSTRAR CIRUGIA POR APELLIDO ",40, 15, y==4);
        //showItem(" ELIMINAR CIRUGIA ",40, 16, y==5);
        showItem(" VOLVER  ",40, 16, y==5);


        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>5) ///limitacion de movimiento
            {
                y=5;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
                _cirugiaManager.Cargar();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);
                break;
            case 1:
                cls();
                _cirugiaManager.mostrarCirugiaYPaciente();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);
                break;
            case 2:
                cls();
                _cirugiaManager.ListarTodos();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);
                break;
            case 3:
                cls();
                _cirugiaManager.modificarCursoDeCirugia();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);
                break;
            case 4:
                cls();
                _pacienteManager.BuscarPorApellido();
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);
                break;

           /* case 5:
                cls();
               // _cirugiaManager.EliminarCirugia(cirugia);
                cout << endl;
                setColor(WHITE);
                system("pause");
                cls();
                setColor(WHITE);
                break;*/

            case 5:
                cls();
                op=0;
                break;

            default:
                break;
            }

            break;



        default:
            break;
        }




    }
    while(op!=0);


}
///================================FIN==========================================

///=============================================================================
/// FUNCION : void Menu::MenuConfiguracion()
/// ACCION : Muestra el menu configuracion
/// PARAMETROS:
///
/// DEVUELVE :
///-----------------------------------------------------------------------------
void Menu::MenuConfiguracion()
{
    PacienteManager _pacienteManager;


    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" COPIA DE SEGURIDAD ",40, 11, y==0);
        showItem(" RESTAURAR COPIA DE SEGURIDAD ",40, 12, y==1);

        showItem(" VOLVER  ",40, 13, y==2);


        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>2) ///limitacion de movimiento
            {
                y=2;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
                _pacienteManager.copiaDeSeguridadPaciente();

                break;
            case 1:
                cls();
                _pacienteManager.restaurarBkp();

                break;

            case 2:
                cls();
                op=0;
                break;

            default:
                break;
            }

            break;



        default:
            break;
        }




    }
    while(op!=0);


}
void Menu::MenuInformes()
{
    Paciente pacient;
    PacienteManager paciente;
    ArchivoPaciente archiPaciente;

    Cirugia cirugia;
    CirugiaManager managerCirugia;
    ArchivoCirugia archivoC;

	ProfesionalManager profesionalM;
	QuirofanoManager quirofanoM;


    int op = 1;
    int y=0; ///Variable para mover el cursor
    hidecursor(); ///oculta el cursor

    do
    {

        showItem(" PROCEDIMIENTOS QUIRURGICOS POR FECHA ",40, 11, y==0);
        showItem(" PORCENTAJES DE LAS ETAPAS QUIRURGICAS ",40, 12, y==1);
        showItem(" CANTIDAD DE PACIENTES POR PROFESIONAL ",40, 13, y==2);
        showItem(" INFORME DE UTILIZACION DE QUIROFANOS ",40, 14, y==3);
        showItem(" VOLVER  ",40, 15, y==4);


        switch(getkey())
        {
        case 14: ///UP
            locate(38,11 +y);
            cout<<" "<<endl;
            y--; ///mueve hacia arriba

            if(y<0)///limitacion de movimiento
            {
                y=0;
            }
            break;

        case 15: ///DOWN
            locate(38,11 +y);
            cout<<" "<<endl;
            y++; ///mueve hacia abajo
            if(y>4) ///limitacion de movimiento
            {
                y=4;
            }

            break;

        case 1: ///ENTER

            ///swicth para validar el enter dependiendo la opcion
            switch(y)
            {
            case 0:
                cls();
				managerCirugia.obtenerProcedimientosXFecha();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 1:
                cls();
                managerCirugia.promedioDeEtapas();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 2:
                cls();
                profesionalM.pacientesPorProfesional();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 3:
                cls();
                quirofanoM.quirofanosOcupados();
                cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 4:

                cls();
                op=0;
                break;
                break;
            case 5:
                cls();
                paciente.modificarMail();
               cout << endl;
				setColor(WHITE);
				system("pause");
                cls();
				setColor(WHITE);
                break;
            case 6:
                cls();
                MenuConfiguracion();

                //  system("pause");
                cls();
                break;

            case 7:
                cls();
                op=0;
                break;

            default:
                break;
            }

            break;




        default:
            break;
        }




    }
    while(op!=0);

}


