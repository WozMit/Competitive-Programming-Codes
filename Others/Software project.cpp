//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

struct Persona{
	int dni, dd, mm, aa;
	string nombres, apellidos;
	char sexo;
	Persona(){}
	Persona(int pdni, string pnombres, string papellidos, int pdd, int pmm, int paa, char psexo){
		dni = pdni;
		nombres = pnombres;
		apellidos = papellidos;
		dd = pdd;
		mm = pmm;
		aa = paa;
		sexo = psexo;
	}
	bool operator <(Persona b) const{ return dni < b.dni; }
	void Mostrar(){
		printf(" %-20d %-25s %-25s %d/%d/%-10d %c\n", dni, nombres.c_str(), apellidos.c_str(), dd, mm, aa, sexo);
	}
};

struct Docente{
	int dni;
	string curso;
	string condicion;
	double sueldo;
	Docente(){}
	Docente(int pdni, string pcurso, string pcondicion, double psueldo){
		dni = pdni;
		curso = pcurso;
		condicion = pcondicion;
		sueldo = psueldo;
	}
	bool operator <(Docente b) const{ return dni < b.dni; }
	void Mostrar(){
		printf(" %-15d %-20s %-18s %.1f\n", dni, curso.c_str(), condicion.c_str(), sueldo);
	}
};

struct Alumno{
	int dni, grado;
	string nivel;
	char seccion;
	Alumno(){}
	Alumno(int pdni, int pgrado, string pnivel, char pseccion){
		dni = pdni;
		grado = pgrado;
		nivel = pnivel;
		seccion = pseccion;
	}
	bool operator <(Alumno b) const{ return dni < b.dni; }
	void Mostrar(){
		printf(" %-17d %-10d %-18s %c\n", dni, grado, nivel.c_str(), seccion);
	}
};
vector<Persona> Lista_personas;
vector<Docente> Lista_docentes;
vector<Alumno> Lista_alumnos;

void MenuPrincipal();
void MenuPersonas();
void MenuDocentes();
void MenuAlumnos();
void ListarPersonas();
void ListarDocentes();
void ListarAlumnos();
void AgregarPersona();
void AgregarDocente();
void AgregarAlumno();
void ModificarPersona();
void ModificarDocente();
void ModificarAlumno();
void EliminarPersona();
void EliminarDocente();
void EliminarAlumno();
bool ExistePersona(int pdni);
bool ExisteDocente(int pdni);
bool ExisteAlumno(int pdni);

void MenuPrincipal(){
	puts("\n/////////////// Menu principal ///////////////\n");
	puts("1) Menu de personas");
	puts("2) Menu de docentes");
	puts("3) Menu de alumnos");
	puts("4) Reportes especiales");
	int op = -1;
	while(op < 1 || op > 4){
		printf("\nIngrese una opcion: ");
		scanf("%d", &op);
	}
	switch(op){
		case 1:
			MenuPersonas();
			break;
		case 2:
			MenuDocentes();
			break;
		case 3:
			MenuAlumnos();
			break;
		case 4:
			MenuPrincipal();
			break;
	}
}

void MenuPersonas(){
	puts("\n/////////////// Menu de personas ///////////////\n");
	puts("1) Listar personas");
	puts("2) Agregar persona");
	puts("3) Modificar datos de persona");
	puts("4) Eliminar persona");
	puts("5) Volver al menu principal");
	int op = -1;
	while(op < 1 || op > 5){
		printf("\nIngrese una opcion: ");
		scanf("%d", &op);
	}
	switch(op){
		case 1:
			ListarPersonas();
			MenuPersonas();
			break;
		case 2:
			AgregarPersona();
			MenuPersonas();
			break;
		case 3:
			ModificarPersona();
			MenuPersonas();
			break;
		case 4:
			EliminarPersona();
			MenuPersonas();
			break;
		case 5:
			MenuPrincipal();
			break;
	}
}

void MenuDocentes(){
	puts("\n/////////////// Menu de docentes ///////////////\n");
	puts("1) Listar docentes");
	puts("2) Agregar docente");
	puts("3) Modificar datos de docente");
	puts("4) Eliminar docente");
	puts("5) Volver al menu principal");
	int op = -1;
	while(op < 1 || op > 5){
		printf("\nIngrese una opcion: ");
		scanf("%d", &op);
	}
	switch(op){
		case 1:
			ListarDocentes();
			MenuDocentes();
			break;
		case 2:
			AgregarDocente();
			MenuDocentes();
			break;
		case 3:
			ModificarDocente();
			MenuDocentes();
			break;
		case 4:
			EliminarDocente();
			MenuDocentes();
			break;
		case 5:
			MenuPrincipal();
			break;
	}
}

void MenuAlumnos(){
	puts("\n/////////////// Menu de alumnos ///////////////\n");
	puts("1) Listar alumnos");
	puts("2) Agregar alumno");
	puts("3) Modificar datos de alumno");
	puts("4) Eliminar alumno");
	puts("5) Volver al menu principal");
	int op = -1;
	while(op < 1 || op > 5){
		printf("\nIngrese una opcion: ");
		scanf("%d", &op);
	}
	switch(op){
		case 1:
			ListarAlumnos();
			MenuAlumnos();
			break;
		case 2:
			AgregarAlumno();
			MenuAlumnos();
			break;
		case 3:
			ModificarAlumno();
			MenuAlumnos();
			break;
		case 4:
			EliminarAlumno();
			MenuAlumnos();
			break;
		case 5:
			MenuPrincipal();
			break;
	}
}

bool ExistePersona(int pdni){
	for(int i=0; i<Lista_personas.size(); i++)
		if(Lista_personas[i].dni == pdni) return true;
	return false;
}

bool ExisteDocente(int pdni){
	for(int i=0; i<Lista_docentes.size(); i++)
		if(Lista_docentes[i].dni == pdni) return true;
	return false;
}

bool ExisteAlumno(int pdni){
	for(int i=0; i<Lista_alumnos.size(); i++)
		if(Lista_alumnos[i].dni == pdni) return true;
	return false;
}

void ListarPersonas(){
	puts("\n//////////////////////////////////// Lista de personas ////////////////////////////////////\n");
	printf(" %-20s %-25s %-25s %-13s %s\n", "DNI", "Nombres", "Apellidos", "F. Nacim.", "Sexo");
	puts("---------------------------------------------------------------------------------------------");
	for(int i=0; i<Lista_personas.size(); i++)
		Lista_personas[i].Mostrar();
}

void ListarDocentes(){
	puts("\n//////////////////////////////////// Lista de docentes ////////////////////////////////////\n");
	printf(" %-15s %-20s %-18s %s\n", "DNI", "Curso", "Condicion", "Sueldo");
	puts("----------------------------------------------------------------");
	for(int i=0; i<Lista_docentes.size(); i++)
		Lista_docentes[i].Mostrar();
}

void ListarAlumnos(){
	puts("\n/////////////////////////// Lista de alumnos ///////////////////////////\n");
	printf(" %-17s %-10s %-18s %s\n", "DNI", "Grado", "Nivel", "Seccion");
	puts("----------------------------------------------------------");
	for(int i=0; i<Lista_alumnos.size(); i++)
		Lista_alumnos[i].Mostrar();
}

void AgregarPersona(){
	puts("\n//////////////////////////////////// Agregar nueva persona ////////////////////////////////////\n");
	int pdni, pdd, pmm, paa;
	string pnombres, papellidos;
	char psexo;
	printf("DNI de la nueva persona: ");
	scanf("%d", &pdni);
	if(ExistePersona(pdni)){
		puts("\nLa persona ya se encuentra registrada.\n");
		printf("Presione enter para continuar...");
		getchar();
		return;
	}
	printf("Nombres: ");
	cin >> pnombres;
	printf("Apellidos: ");
	cin >> papellidos;
	printf("Fecha de nacimiento (dd/mm/aa): ");
	scanf("%d/%d/%d", &pdd, &pmm, &paa);
	printf("Sexo (M/F): ");
	scanf(" %c", &psexo);
	Persona P = Persona(pdni, pnombres, papellidos, pdd, pmm, paa, psexo);
	printf("\n %-20s %-25s %-25s %-13s %s\n", "DNI", "Nombres", "Apellidos", "F. Nacim.", "Sexo");
	puts("---------------------------------------------------------------------------------------------");
	P.Mostrar();
	printf("\nConfirmar (s/n): ");
	scanf(" %c", &psexo);
	if(psexo == 's'){
		Lista_personas.push_back(P);
		printf("\nPersona agregada con exito!\n");
	} else{
		printf("\nSe cancelo la operacion.\n");
	}
}

void AgregarDocente(){
}

void AgregarAlumno(){
}

void ModificarPersona(){
}

void ModificarDocente(){
}

void ModificarAlumno(){
}

void EliminarPersona(){
}

void EliminarDocente(){
}

void EliminarAlumno(){
}

int main(){
	Persona p1 = Persona(72712961, "Jared", "Leon Malpartida", 8, 7, 1997, 'M');
	Persona p2 = Persona(75642159, "John Salchichon", "Vergara Telechea", 8, 7, 1997, 'F');
	Docente d1 = Docente(75642159, "Matematicas", "Contratado", 1500.0);
	Docente d2 = Docente(72712961, "Fisica Nuclear", "Nombrado", 50000.0);
	Alumno a1 = Alumno(75642159, 1, "Primaria", 'Z');
	Alumno a2 = Alumno(72712961, 5, "Secundaria", 'C');
	Lista_personas.push_back(p1);
	Lista_personas.push_back(p2);
	Lista_docentes.push_back(d1);
	Lista_docentes.push_back(d2);
	Lista_alumnos.push_back(a1);
	Lista_alumnos.push_back(a2);
	MenuPrincipal();
	return 0;
}
