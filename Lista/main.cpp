#include <iostream>
#include "List.h"

int main() {
  Node<float> list(1.3);
  list.push(4.5);
  list.push(6.34);
  list.showList();

  // Agrega un elemento al final de la lista
  list.push(2.1);
  list.showList();

  // Elimina el ultimo elemento de la lista
  list.pop();
  list.showList();

  // Inserta un elemento en la posicion indicada
  list.insert(1, 8.3);
  list.showList();

  // Elimina el elemento indicado
  list.del(6.34);
  list.showList();

  // Elimina un elemento de la posicion indicada
  list.delIndex(1);
  list.showList();
  
}