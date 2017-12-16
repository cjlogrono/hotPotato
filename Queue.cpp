#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>
#include <math.h>
#include "Queue.h"
#define MAX_SIZE 10

using namespace std;

namespace queue{

	queueLinkedList::queueLinkedList(){

		last = NULL;
		first = NULL;
		actual = NULL;
		previo = NULL;
		size = 0;
	}

	queueLinkedList::~queueLinkedList(){}

	void queueLinkedList::addName(string nombre){

		listNodePTR newNode;
		newNode = new personNode;

		newNode->name = nombre;
		newNode->next = NULL;

		size++;

		if(first == NULL){
			
			first = newNode;
			last = newNode;

		}else{

			last->next = newNode;
			newNode->next = first;
			last = newNode;
		}
	}

	bool queueLinkedList::empty() const{

		return (size == 0);
	}

	bool queueLinkedList::full() const{

		return (size == MAX_SIZE);
	}

	void queueLinkedList::iterate(int veces){

		actual = first;
		previo = last;

		for(int i = 0; i < veces - 1; i++){

			previo = actual;
			actual = actual->next;
		}

		first = actual;
		last = previo;
	}

	int queueLinkedList::getSize(){

		return size;
	}

	string queueLinkedList::front() const{

		return first->name;
	}

	string queueLinkedList::back() const{

		return last->name;
	}

	void queueLinkedList::deleteFront(){

		listNodePTR temp;

			temp = first; 
			first = first->next;

			cout << "\n\nEl jugador eliminado es: " << temp->name << "\n\n";
			delete temp;
			size--;
			
			if(first == NULL){ 
			
				last = NULL;
			}

			if(size == 1){

				first->next = NULL;
			
			}else{

				last->next = first;
			}
	}

	ostream& operator <<(ostream& out, queueLinkedList& jugadores){

		if(jugadores.front() == jugadores.back()){

			cout << "\n\nEl jugador ganador es: ";

			cout << jugadores.first->name << endl << endl;

		}else{

			cout << "\n\nLos jugador restantes son: ";
			jugadores.actual = jugadores.first;

			for(int i = 0; i < jugadores.getSize(); i++){
				
				cout << jugadores.actual->name << " ";

				if(jugadores.actual->next == NULL){

					jugadores.actual = jugadores.first;
				
				}else{

					jugadores.actual = jugadores.actual->next;
				}
			}
		}

		return out;
	}

	istream& operator >>(istream& in, queueLinkedList& jugadores){

			bool stop = false;
			string nombre;

			cout << "\nIntroduzca todos los nombres de los jugadores.\n";
			cout << "****Separar cada valor con espacios****\n";
			cout << "Maximo de 10 jugadores, si habran menos jugadores \nintroduzca el 0 cuando termine.\n";
			cout << "Nombre: ";
			cin >> nombre;

			jugadores.addName(nombre);

			do{

				cin.clear();
				cin.ignore(1000, ' ');
				cin >> nombre;

				if(nombre == "0" || jugadores.full()){

					stop = true;

				}else{

					jugadores.addName(nombre);
					stop = false;
				}

			}while(!stop);

			return in;
	}
}
#endif //QUEUE_CPP