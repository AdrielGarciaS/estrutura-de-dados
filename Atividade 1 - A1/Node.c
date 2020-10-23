#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Node.h"

Node* create() {
  Node* head = NULL;
  head = (Node*) malloc(sizeof(Node));

  return head;
}

void addOnBegin(Node* head, int value) {

  if (head->value == NULL) {
    head->value = value;
    return;
  }

  Node* newNode = create();
  newNode->value = head->value;
  newNode->next = head->next;

  head->value = value;
  head->next = newNode;
}

void addOnEnd(Node* head, int value) {

  if (head->value == NULL) {
    head->value = value;
    return;
  }
  
  Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  Node* newNode = create();
  newNode->value = value;
  newNode->next = NULL;

  current->next = newNode;
}

int removeLastOne(Node* head) {
  
  int removedValue = 0;

  if (head->next == NULL) {
    removedValue = head->value;
    head->value = NULL;
    return removedValue;
  }

  Node* current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  removedValue = current->next->value;
  free(current->next);
  current->next = NULL;
  
  return removedValue;
}

void printNodeList(Node* head) {

  if (head->next == NULL && head->value == NULL) {
      printf("\nA lista está vazia\n");
      return;
    }

  Node* current = head;

  if (current != NULL) {
    printf("\nA lista está assim:\n");

    while (current != NULL) {
      printf("valor: %d\n", current->value);
      current = current->next;
    }
  }

}

int removeValue(Node* head, int value) {
  int removedValue = 0;

  if (head->value == value) {
    Node* tempNode = head->next;
    removedValue = head->value;

    head->value = head->next->value;
    head->next = head->next->next;

    printf("\n%d\n", head->value);

    tempNode = NULL;
    free(tempNode);

    return removedValue;
  }

  Node* current = head;

  while (current->next != NULL && current->next->value != value) {
    current = current->next;
  }

  removedValue = current->next->value;

  if (current->next->next != NULL) {
    Node* tempNode = current->next;

    current->next = current->next->next;

    tempNode = NULL;
    free(tempNode);
  }

  return removedValue;
}

void addOrdenered(Node* head, int value) {
  
  if (head->value == NULL) {
    head->value = value;
    return;
  }

  if (value <= head->value)
    addOnBegin(head, value);

  Node* current = head;
  Node* lowerThanValue = create();
  lowerThanValue->value = INT_MIN;

  while (current->next != NULL) {
    if (current->next->value <= value && current->next->value > lowerThanValue->value) 
      lowerThanValue = current->next;

    current = current->next;
  }

  printf("\no menor valor antes de value é %d\n", lowerThanValue->value);

  Node* newNode = create();
  newNode->value = value;

  insertNewNodeOnPosition(newNode, lowerThanValue);
}

void insertNewNodeOnPosition(Node* newNode, Node* nodePosition) {
  Node* tempNode = create();
  tempNode = nodePosition->next;

  nodePosition->next = newNode;

  newNode->next = tempNode;

  tempNode = NULL;
  free(tempNode);
}