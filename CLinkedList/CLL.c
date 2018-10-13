/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on October 10, 2018, 7:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
/*
 * Circular Linked List implementation
 */

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    struct Node* tail;
    int nodeCount;
}CircularLinkedList;

void initList(CircularLinkedList *);
void createListFromRandomNumbers(CircularLinkedList *, int);
void insertNode(CircularLinkedList *, int);
void printList(CircularLinkedList *);
Node * find(CircularLinkedList *, int);
int deleteNode(CircularLinkedList *);


void menu(){
    printf("   Circular Linked List Operations\n");
    printf("------------------------------------\n");
    printf("1.Create List for random numbers\n");
    
    printf("2.Insert a node\n");
    printf("3.Delete a node\n");
    printf("4.Find\n");
    
    printf("5.Print List\n");
    printf("6.Quit.\n");
}



int main(int argc, char** argv) {

    CircularLinkedList cList;
    initList(&cList);
    
    int choice;
    int quit = 0;
    int data, n , target;
    int success;
    Node *targ = NULL;
    
    while(!quit){
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                printf("How many nodes do you want to put in: ");
                scanf("%d", &n);
                createListFromRandomNumbers(&cList, n);
                break;
            case 2:
                printf("Enter value you want to insert: ");
                scanf("%d", &data);
                insertNode(&cList, data);
                break;
            case 3: 
                data = deleteNode(&cList);
                if(data == -9999){
                    printf("Empty, try inserting a node.\n");
                }
                else
                    printf("Value deleted: %d\n", data);
                break;
            case 4: 
                printList(&cList);
                printf("What value would you like to look for: ");
                scanf("%d", &target);
                targ = find(&cList, target);
                if(targ == NULL){
                    printf("Target not found.");
                }
                else{
                    printf("[ %p | %d ] found.\n", targ, targ->data);
                }
                break;
            case 5: 
                printList(&cList);
                break;
            case 6: 
                quit = 1;
                break;
            default:
                printf("Not a valid choice.\n");
                break;
        }
    }
    return (EXIT_SUCCESS);
}

void initList(CircularLinkedList *cList){
    cList->nodeCount = 0;
    cList->tail = NULL;
}

void insertNode(CircularLinkedList *cList, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
     printf("new node could not be created.");
     return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if(cList->nodeCount == 0){
        newNode->next = newNode;
    }
    else{
        newNode->next = cList->tail->next;
        cList->tail->next = newNode;
    }
    
    cList->tail = newNode;
    cList->nodeCount++;
    
}

int deleteNode(CircularLinkedList *cList){
    if(cList->nodeCount == 0){
        return -9999;
    }
    Node *current = cList->tail->next;
    int data = current->data;
    
    if(cList->nodeCount == 1){
        cList->tail = NULL;
    }
    else{
        cList->tail->next = current->next;
    }
    
    
    cList->nodeCount--;
    return data;
}

Node * find(CircularLinkedList *cList, int target){
    if(cList->nodeCount == 0){
        return NULL;
    }
   
    int done = 0;
    Node *currentNode = cList->tail->next;
    while(!done){
        if(currentNode->data == target){
            return currentNode;
        }
        if(currentNode == cList->tail){
            done = 1;
        }
        else{
            currentNode = currentNode->next;
        }
    }
    
    return NULL;   
}

void createListFromRandomNumbers(CircularLinkedList *cList, int n){
    int i;
    srand(time(NULL));
    for(i = 1; i<= n ; i++){
        int k = rand() % 1000;
        insertNode(cList, k);
    }
}


void printList(CircularLinkedList *cList){
    if(cList->nodeCount == 0){
        printf("List is empty.");
        return;
    }
    int done = 0;
    
    Node *currentNode = cList->tail->next;
    while(!done){
        printf("%4d\n", currentNode->data);
       if(currentNode == cList->tail){
           done = 1;
        }
        currentNode = currentNode->next;
    }
}