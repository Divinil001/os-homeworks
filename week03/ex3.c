#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *next;
    int value;
};

struct linkedList{
    struct node *next;
};

struct node* node(int value){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    return node;
}

void nodeDestructor(struct node *node){
    free(node);
}

struct linkedList* linkedList(){
    struct linkedList* list = (struct linkedList*)malloc(sizeof(struct linkedList));
    list->next = NULL;
}

void linkedListDestructor(struct linkedList* head){
    if(head->next == NULL){
        free(head);
        return;
    }
    struct node *current = head->next;
    struct node *next = current->next;
    while(current != NULL){
        nodeDestructor(current);
        current = next;
        if(current != NULL) {
            next = current->next;
        }
    }
}

int insert_node(int value, int pos, struct linkedList *head){
    if(pos == 0){
        struct node *newNode = node(value);
        newNode->next = head->next;
        head->next = newNode;
        return 0;
    }
    struct node* currentNode = head->next;
    for (int i = 1; i <= pos; ++i) {
        if(currentNode != NULL){
            if(i == pos){
                struct node *newNode = node(value);
                newNode->next = currentNode->next;
                currentNode->next = newNode;
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

int delete_node(int pos, struct linkedList *head){
    if(pos == 0){
        if(head->next != NULL) {
            struct node *toDelete = head->next;
            head->next = head->next->next;
            nodeDestructor(toDelete);
            return 0;
        } else {
            return 1;
        }
    }

    struct node* currentNode = head->next;
    for (int i = 1; i <= pos; ++i) {
        if (currentNode != NULL) {
            if(i == pos){
                struct node *toDelete = currentNode->next;
                currentNode->next = currentNode->next->next;
                nodeDestructor(toDelete);
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

void print_list(struct linkedList *head){
    if(head->next == NULL){
        printf("Empty list\n");
        return;
    }
    struct node *currentNode = head->next;
    printf("List: head");
    while(currentNode != NULL){
        printf(" -> %d", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(){
    struct linkedList *head = linkedList();

    print_list(head);
    insert_node(10, 0, head);
    print_list(head);
    delete_node(0, head);
    print_list(head);

    insert_node(5, 1, head);
    print_list(head);
    insert_node(1, 0, head);
    print_list(head);
    insert_node(3, 1, head);
    print_list(head);
    insert_node(2, 1, head);
    print_list(head);
    insert_node(4, 3, head);
    print_list(head);
    delete_node(1, head);
    print_list(head);
    delete_node(4, head);
    print_list(head);
    delete_node(2, head);
    print_list(head);

    insert_node(-1, -1, head);
    delete_node(-3, head);
    print_list(head);

    linkedListDestructor(head);

    return 0;
}
