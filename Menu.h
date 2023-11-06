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
// Aqui se desarrolla la class Menu
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu
{
public:

    ///MENUN PRINCIPAL

    ///FUNCION PARA MOSTRAR EL MENU PRINCIPAL
    void MenuPrincipal();
    ///FUNCION PARA MOSTRAR EL MENU PACIENTE
    void MenuPaciente();
    ///FUNCION PARA MOSTRAR EL MENU CIRUGIA
    void MenuCirugia();
    ///FUNCION PARA MOSTRAR EL MENU ESTADOS DE CIRUGIA
    void MenuEstadosCirugias();
    ///FUNCION PARA MOSTRAR EL MENU PROFESIONAL
    void MenuProfesional();
    ///FUNCION PARA MOSTRAR EL MENU QUIROFANO
    void MenuQuirofano();
    ///FUNCION PARA MOSTRAR EL MENU CONFIGURACIONES
    void MenuConfiguracion();
    void MenuInformes();
    ///PRESENTACIO
    void Presentacion();

    ///MOSTRAR MENU


};
///FUNCIONES DE MUNU GLOBALES
void mostrarMenuPrincipal();

///FUNCION GLOBAL PARA COLORES
void showItem(const char* text, int posx, int posy, bool selected);


#endif // MENU_H_INCLUDED
