#include <iostream>
#include <cctype>
#include "Queue.h"
#include "functions.cpp"

using namespace std;
using namespace functions;
using namespace queue;

int main(){

	queueLinkedList participantes;

	introduccion();

	cin >> participantes;
	
	papaCaliente(participantes);

	return 0;
}