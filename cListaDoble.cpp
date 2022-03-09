#include <iostream>
using namespace std;

class cListaDoble {
private:
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
	bool isChar(char);
};

cListaDoble::cListaDoble() {
	list = NULL;
}

void cListaDoble::print() {
	Node* aux;
	for (aux = list; aux != NULL; aux = aux->siguiente) {
		cout << aux->vocal;
	}
}

void cListaDoble::crearLista() {
	Node* aux = NULL,* aux1 = NULL;
	char letter;
	for (int i = 0; i < 5; i++)
	{
		if ( list == NULL ){
			list = new Node();
			cout << "Dame la vocal para primer primer Nodo: ";
			cin >> list->vocal;
			aux = list;
			aux1 = list;
		}else {
			aux->siguiente = new Node();
			aux = aux->siguiente;
			aux->anterior = aux1;
			aux1 = aux1->siguiente;
			cout<<"Dame la vocal de la siguiente vocal: ";
			cin >> letter;
			if (isChar(letter)) {
				aux->vocal = letter;
			}else {
				cout << "numero no valido" << endl;
			}
		}
	}
}
bool isChar(char letter) {
	switch (letter) {
	
	case 'a':
		return true;
		break;
	case 'e':
		return true;
		break;
	case 'i':
		return true;
		break;
	case 'o':
		return true;
		break;
	case 'u':
		return true;
		break;
	default:
		return false;
		break;
	}
}

int main() {

	cListaDoble* object = new cListaDoble();
	object->crearLista();
	object->print();
	return 0;
}
