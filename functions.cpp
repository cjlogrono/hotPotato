#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"

using namespace queue;

namespace functions{

	void introduccion(){

		cout << "\n\nBienvenidos, este programa creara una lista ciruclar de \njugadores con los datos que usted introduzca.\n";
	 	cout << "Luego juagaran papa caliente hasta que alguien gane.\n";
	}

	void papaCaliente(queueLinkedList& userObject){

		bool invalid = true;
		int veces;

		if(userObject.front() != userObject.back()){

			do{

				cout << "\n\nCuantas veces dire \"papa caliente\"?\n";
				cout << "Veces: ";
				cin >> veces;

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;
					cout << "\n\n\n***Introdujo un numero invalido por favor trate de nuevo***\n\n\n";

				}else if(veces <= 0){

					invalid = true;
					cout << "\n\n\n***Introdujo un numero negativo o zero, tratelo denuevo***\n\n\n";

				}else{

					invalid = false;
				}

			}while(invalid);

			userObject.iterate(veces);
			userObject.deleteFront();
			cout << userObject;
			papaCaliente(userObject);
		}
	}
}