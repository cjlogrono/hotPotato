#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

namespace queue{

	typedef struct personNode{

		string name;
		personNode *next;

	}* listNodePTR;

	class queueLinkedList{

		public:

			queueLinkedList();

			~queueLinkedList();

			void addName(string nombre);

			bool empty() const;

			bool full() const;

			int getSize();

			void iterate(int veces);

			string front() const;

			string back() const;

			void deleteFront();

			friend ostream& operator <<(ostream& out, queueLinkedList& jugadores);

			friend istream& operator >>(istream& in, queueLinkedList& jugadores);

		private:

			listNodePTR actual;
			listNodePTR previo;
			listNodePTR first;
			listNodePTR last;

			int size;

	};
} //queue

#endif //QUEUE_H
#include "Queue.cpp"