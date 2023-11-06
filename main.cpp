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
// Aqui se llama a la presentacion y al Menu. Son quien tienen todo los metodos
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
#include "Menu.h"
#include "ArchivoPaciente.h"
#include "PacienteManager.h"
#include "QuirofanoManager.h"
#include "ProfesionalManager.h"
#include "CirugiaManager.h"
#include "rlutil.h"
#include "Tiempo.h"

using namespace rlutil;
int main()
{

  Menu menu;
 setBackgroundColor(MAGENTA);///COLOR DE FONDO DE PANTALLA
  menu.Presentacion(); ///Llama a presentacion
  Sleep(4000); ///Detiene la pantalla por 3 segundos
   setBackgroundColor(BLACK);///COLOR DE FONDO DE PANTALLA
  cls();///LIMPIA LA PANTALLA

  ///MUESTRA LAS OPCIONES DE MENU
  menu.MenuPrincipal();


    return 0;
}
