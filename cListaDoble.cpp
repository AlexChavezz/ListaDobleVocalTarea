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
    char vocales[5];
public:
    cListaDoble();
    void crearLista();
    void print();
    void ordenar();
    bool isVocal(char);
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
    char character;

    for (int i = 0; i < 5; i++) {

        if (list == NULL) {
            list = new Node();
            bool isCorrect;
            do {
                cout << "Dame la vocal para el primer primer Nodo: ";
                cin >> character;
                if (isVocal(character)) {
                    isCorrect = true;
                    list->vocal = character;
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
                cout << "Dame la vocal del siguiente nodo: ";
                cin >> character;
                if (isVocal(character)) {
                    aux->vocal = character;
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
    int increment = 0;

    //  -> Asingno el valor de cada nodo a una posicion de mi array

    for (aux = list; aux != NULL; aux = aux->siguiente) {
        vocales[increment] = aux->vocal;
        increment++;
    }

    // -> Ordenamiento burbuja

    char aux4 = vocales[0];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            if (vocales[i] < vocales[j]) {
                aux4 = vocales[i];
                vocales[i] = vocales[j];
                vocales[j] = aux4;
            }
        }
    }

    // -> Asignar las vocales ordenadas a mi lista doble

    increment = 0;

    for (aux = list; aux != NULL; aux = aux->siguiente) {
        aux->vocal = vocales[increment];
        increment++;
    }
    cout << "lista Ordenada Correctamente" << endl;

}

bool cListaDoble::isVocal(char character) {
    switch (character) {

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
    system("cls");

    int opc;

    do {
        cout << "Que quieres hacer ahora ?" << endl;
        cout << "(1) Ordenar\n(2) Imprimir\n(3) Salir\n:  ";
        cin >> opc;

        switch (opc) {
        case 1:
            system("cls");
            object->ordenar();
            break;
        case 2:
            system("cls");
            object->print();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (opc != 3);

    return 0;
}
