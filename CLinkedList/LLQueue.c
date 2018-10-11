/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on October 11, 2018, 1:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Queue implementation using Linked List
 */

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    struct Node* head;
    struct Node* tail;
    int nodeCount;
}LinkedList;


void initList(LinkedList *);
void insertQueue(LinkedList *, int);
void printList(LinkedList *);
int deleteQueue(LinkedList *);

void initList(LinkedList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}

void insertQueue(LinkedList *listptr, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Unable to allocate new Node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if(listptr->nodeCount == 0){
        listptr->head = newNode;
        listptr->tail = newNode;
    }
    else{
        listptr->tail->next = newNode;
        listptr->tail = newNode;
    }
    
    
    
    listptr->nodeCount++;
}

void printList(LinkedList *listptr){
        if(listptr->nodeCount == 0){
        printf("List is empty.");
        return;
    }
    
    Node *currentNode = listptr->head;
    while(currentNode != NULL){
        printf("%4d\n", currentNode->data);
        //once currentNode is assigned to the next node
        //if that next node point to null, it will run once more
        //and then terminate
        //[50|100] -> [100|'\0']
        //currentNode -> [100|'\0'] -> NULL(terminate)
        currentNode = currentNode->next;
    }
}

int deleteQueue(LinkedList *listptr){
    if(listptr->nodeCount == 0){
        return -9999;
    }
    
    Node* current = listptr->head;
    int data = listptr->head->data;
    if(listptr->nodeCount == 1){
        listptr->head = NULL;
        listptr->tail = NULL;
    }
    else{
        listptr->head = current->next;
    }
    
    free(current);
    listptr->nodeCount--;
    return data;
        
}

void menu(){
    printf("    Queue Implementation with Linked List.\n");
    printf("--------------------------------------------------\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print\n");
    printf("4. Quit\n");
}


int main(int argc, char** argv) {

    LinkedList queue;
    initList(&queue);
    int choice;
    int value;
    while(1){
        menu();
        printf("Choose an operation: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                printf("Please enter value to insert into the queue: ");
                scanf("%d", &value);
                insertQueue(&queue, value);
                break;
            case 2:
                value = deleteQueue(&queue);
                if(value == -9999){
                    printf("Queue Underflow\n");
                    break;
                }
                printf("Value deleted: %d", value);
                break;
            case 3:
                printList(&queue);
                break;
            case 4:
                exit(1);
            default:
                printf("Not a valid choice.\n");
                break;
        }
    }
    return (EXIT_SUCCESS);
}

