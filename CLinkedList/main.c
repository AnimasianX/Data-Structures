/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on October 11, 2018, 1:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Stack Using a Linked List
 */
typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct{
    struct Node *head;
    struct Node *tail;
    int nodeCount;
}LinkedList;


void initList(LinkedList *);
void push(LinkedList *, int);
int pop(LinkedList *);
void printList(LinkedList *);

void initList(LinkedList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}

void push(LinkedList *listptr, int value){
    Node * newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Unable to create node.");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if(listptr->nodeCount == 0){
        listptr->head = newNode;
        listptr->tail = newNode;
    }
    else{
        newNode->next = listptr->head;
        listptr->head = newNode;
    }
    
    listptr->nodeCount++;
}

int pop(LinkedList *listptr){
    if(listptr->nodeCount == 0){
       
        return -9999;
    }
    
    Node * currentNode = listptr->head;
    int data = listptr->head->data;
    if(listptr->nodeCount == 1){
        listptr->head = NULL;
        listptr->tail = NULL;
    }
    else
        listptr->head = listptr->head->next;
    
    listptr->nodeCount--;
    free(currentNode);
    return data;
    
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


void menu(){
    printf("    Stack Implementation with Linked List.\n");
    printf("--------------------------------------------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print\n");
    printf("4. Quit\n");
     
}

int main(int argc, char** argv) {

    LinkedList stack;
    initList(&stack);
    int choice;
    int value;
    while(1){
        menu();
        printf("Choose an operation: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                printf("Please enter value to push into stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if(value == -9999){
                    printf("Stack Underflow\n");
                    break;
                }
                printf("Value popped: %d", value);
                break;
            case 3:
                printList(&stack);
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

