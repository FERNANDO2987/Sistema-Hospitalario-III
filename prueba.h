#ifndef PRUEBA_H
#define PRUEBA_H


class prueba
{
 private:
 	int id;
 	char nombre[10];
 	char apellido[10];
 public:
 	void setID(int i){id=i};
	void setNombre(const char* n){{strcpy(nombre,n;)};
	void setApellido(const char* a){{strcpy(apellido,a;)};

	int getID(){return  id};
	const char* getNombre(){return nombre};
	const char* getApellido(){return apellido};
	void Mostrar(){
	cout << "nombre: "<<nombre<<endl;
	cout << "napellido: "<<apellido<<endl;
	cout << "id "<<id<<endl;
	}
};

#endif // PRUEBA_H

