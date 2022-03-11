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
    void ordenar();
    bool isChar(char);
};

cListaDoble::cListaDoble() {
    list = NULL;
}

void cListaDoble::print() {
    Node* aux;
    for (aux = list; aux != NULL; aux = aux->siguiente) {
        cout << aux->vocal << endl;
    }
}

void cListaDoble::crearLista() {
    Node* aux = NULL, * aux1 = NULL;
    char letter;

    for (int i = 0; i < 5; i++) {

        if (list == NULL) {
            list = new Node();
            bool isCorrect;
            do {
                cout << "Dame la vocal para primer primer Nodo: ";
                cin >> letter;
                if (isChar(letter)) {
                    isCorrect = true;
                    list->vocal = letter;
                    aux = list;
                    aux1 = list;
                }
                else {
                    system("cls");
                    cout << "Dato no valido, intenta otra vez" << endl;
                    isCorrect = false;
                }
            } while (!isCorrect);
        }
        else {
            aux->siguiente = new Node();
            aux = aux->siguiente;
            aux->anterior = aux1;
            aux1 = aux1->siguiente;
            bool isCorrect;
            do {
                cout << "Dame la vocal de la siguiente vocal: ";
                cin >> letter;
                if (isChar(letter)) {
                    aux->vocal = letter;
                    isCorrect = true;
                }
                else {
                    system("cls");
                    cout << "Dato no valido" << endl;
                    isCorrect = false;
                }
            } while (!isCorrect);
        }
    }
}

void cListaDoble::ordenar() {
    Node* aux;
    char vocales[5];
    int increment = 0;
    for (aux = list; aux != NULL; aux = aux->siguiente) {
        vocales[increment] = aux->vocal;
        increment++;
    }
    for (int i = 0; i < 5; i++) {
        cout << "[ " << i + 1 << " ]: " <<vocales[i]<<endl;
    }
}

bool cListaDoble::isChar(char letter) {
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
    object->ordenar();
    return 0;
}
