#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node{
	int valor;
	struct node * siguiente;
} nodo_a;

int main(){
	nodo_a * cabeza = (nodo_a *) malloc(sizeof(nodo_a)); //Marcar el inicio de la lista
	nodo_a * itera = cabeza;	//Crear un iterador para insertar elementos
	for(int i=0; i<10; i++){
		itera->siguiente = (nodo_a *) malloc(sizeof(nodo_a)); //Habilitar la siguiente posición
		itera->valor = i;	//Asignar el valor a la posición actual
		itera = itera->siguiente;	//Moverse a la siguiente posición
	}
	itera->siguiente = NULL;			//Marcar el fin de la lista
	//Recorrer el arreglo
	itera = cabeza;
	while(itera->siguiente != NULL){
		printf("%d ", itera->valor);	//Mostrar cada elemento
		itera = itera->siguiente;		//Ir al siguiente elemento
	}
	return 0;
}
