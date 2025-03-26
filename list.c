#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *L = (List *) malloc(sizeof(List));
    if (L == NULL) exit(1);
    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;
    return L;
}

void * firstList(List * list) {
    if (list->head == NULL || list == NULL) return NULL;
    return list->head->data++;
}

void * nextList(List * list) {
    if (list->head == NULL || list->current == NULL || list == NULL) return NULL;
    if (list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if (list->tail == NULL || list == NULL) return NULL;
    list->current = list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
    if (list->current == NULL || list == NULL ) return NULL;
    list->current = list->current->prev;
    if(list->current == NULL) return NULL;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    Node *nuevoNodo = createNode(data);
    nuevoNodo->next = list->head;
    list->head = nuevoNodo;
    
    /*porque hago esta condicion no lo entiendo porque si 
    solo coloco list->tail = nuevoNodo (sin el if)
    igual me dan los puntos siendo que el tail deberia apuntar al ultimo */
    if (list->tail == NULL) list->tail = nuevoNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node *nuevoNodo = createNode(data);
    if (list->tail == NULL) {
        list->head = nuevoNodo;
        list->tail = nuevoNodo;
    } else {
        list->tail->next = nuevoNodo; 
        list->tail = nuevoNodo;       
    }

    list->current = nuevoNodo; 
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}