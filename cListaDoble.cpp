#include <iostream>
using namespace std;

class cListaDoble {
protected:
	class Node {
		public:
		char vocal;
		Node* siguiente;
		Node* anterior;
	};
	Node* list;
public:
	cListaDoble();
	void crearLista();
	void print();
};

cListaDoble::cListaDoble() {
	list = NULL;
}

void cListaDoble::print() {
	
}

void cListaDoble::crearLista() {
	cListaDoble* aux = NULL,* aux1 = NULL;
	
	for (int i = 0; i < 5; i++)
	{
		if ( list == NULL ){
			list = new Node();
			cout << "Dame la vocal para primer primer Nodo: ";
			cin >> list->vocal;
		}
	}

}


int main() {

	cListaDoble* object = new cListaDoble();
	object->print();

	return 0;
}
