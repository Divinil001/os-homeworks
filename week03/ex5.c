#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *next;
    struct node *prev;
    int value;
};


struct doublyLinkedList{
    struct node *head;
    struct node *tail;
    int size;
};

struct node* node(int value){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void nodeDestructor(struct node *node){
    free(node);
}

struct doublyLinkedList* doublyLinkedList(){
    struct doublyLinkedList* list = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
    list->head = (struct node*)malloc(sizeof(struct node));
    list->head->next = NULL;
    list->head->prev = NULL;
    list->tail = (struct node*)malloc(sizeof(struct node));
    list->tail->next = NULL;
    list->tail->prev = NULL;
    list->size = 0;
}

void doublyLinkedListDestructor(struct doublyLinkedList *list){
    if(list->head->next == NULL){
        free(list);
        return;
    }
    struct node *current = list->head->next;
    struct node *next = current->next;
    while(current != list->tail){
        nodeDestructor(current);
        current = next;
        if(current != list->tail) {
            next = current->next;
        }
    }
    free(list);
}

int insert_node(int value, int pos, struct doublyLinkedList *list){
    if(pos == 0 && list->size == 0){
        struct node *newNode = node(value);
        newNode->next = list->tail;
        newNode->prev = list->head;
        list->head->next = newNode;
        list->tail->prev = newNode;
        list->size++;
        return 0;
    }
    struct node* currentNode = list->head->next;
    for (int i = 0; i <= pos; ++i) {
        if(currentNode != NULL){
            if(i == pos){
                struct node *newNode = node(value);
                newNode->next = currentNode;
                currentNode->prev->next = newNode;
                newNode->prev = currentNode->prev;
                currentNode->prev = newNode;
                list->size++;
                return 0;
            } else {
                currentNode = currentNode->next;
            }
        } else {
            return 1;
        }
    }
    return 1;
}

int delete_node(int pos, struct doublyLinkedList *list){
    if(pos == 0){
        if(list->head->next != NULL) {
            struct node *toDelete = list->head->next;
            list->head->next->next->prev = list->head;
            list->head->next = list->head->next->next;
            nodeDestructor(toDelete);
            list->size--;
            return 0;
        } else {
            return 1;
        }
    }

    struct node* currentNode = list->head->next;
    for (int i = 1; i <= pos; ++i) {
        if (currentNode != list->tail) {
            if(i == pos){
                struct node *toDelete = currentNode->next;
                currentNode->next->next->prev = currentNode;
                currentNode->next = currentNode->next->next;
                nodeDestructor(toDelete);
                list->size--;
                return 0;
            } else {
                currentNode = currentNode->next;
            }
        } else {
            return 1;
        }
    }
    return 1;
}

void print_list(struct doublyLinkedList *list){
    if(list->size == 0){
        printf("Empty list\n");
        return;
    }
    struct node *currentNode = list->head->next;
    printf("List: head");
    while(currentNode != list->tail){
        printf(" -> %d", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(){
    struct doublyLinkedList *list = doublyLinkedList();

    print_list(list);
    insert_node(10, 0, list);
    print_list(list);
    delete_node(0, list);
    print_list(list);

    insert_node(5, 1, list);
    print_list(list);

    insert_node(1, 0, list);
    print_list(list);
    insert_node(3, 1, list);
    print_list(list);
    insert_node(2, 1, list);
    print_list(list);
    insert_node(4, 3, list);
    print_list(list);
    delete_node(1, list);
    print_list(list);
    delete_node(4, list);
    print_list(list);
    delete_node(2, list);
    print_list(list);

    insert_node(-1, -1, list);
    print_list(list);
    delete_node(-3, list);
    print_list(list);

    doublyLinkedListDestructor(list);

    return 0;
}
