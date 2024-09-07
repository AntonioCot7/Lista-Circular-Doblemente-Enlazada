#include "Circular_Doubly_Linked_List.h"

int main() {
    CircularDoublyLinkedList<int> lista;

    lista.push_back(10);
    lista.push_front(20);
    lista.push_back(30);

    std::cout << "Elemento al frente: " << lista.front() << std::endl;
    std::cout << "Elemento al final: " << lista.back() << std::endl;
    std::cout << "Elemento en la posición 1: " << lista[1] << std::endl;

    lista.reverse();
    std::cout << "Después de revertir, elemento al frente: " << lista.front() << std::endl;

    return 0;
}
