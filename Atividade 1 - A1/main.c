#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void main() {
  
  Node* head = create();
  head->value = 0;
  head->next = NULL;

  for(int i = 0; i < 10; i++) 
    addOnEnd(head, i + 1);

  addOnBegin(head, 999);

  printNodeList(head);

  printf("Removendo o último item do valor: %d\n", removeLastOne(head));

  printNodeList(head);

  while (head->next != NULL) {
    printf("Removendo o último item do valor: %d\n", removeLastOne(head));
  }

  printNodeList(head);

  printf("Removendo o último item do valor: %d\n", removeLastOne(head));

  addOnBegin(head, 1111);
  printNodeList(head);

  printf("Removendo o último item do valor: %d\n", removeLastOne(head));
  printNodeList(head);
  
  addOnBegin(head, 2222);
  printNodeList(head);

  for(int i = 0; i < 15; i++) 
    addOnEnd(head, i + 1);
  
  printNodeList(head);

  printf("Removendo o item do valor: %d\n", removeValue(head, 2222));
  printNodeList(head);

  printNodeList(head);

  addOrdenered(head, 13);

  printNodeList(head);

}