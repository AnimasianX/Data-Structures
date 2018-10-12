/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deq.c
 * Author: animasian
 *
 * Created on October 12, 2018, 3:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Double ended queue implementation using linked list
 */

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
    int nodeCount;
}deq;

void initQueue(deq *);
void addFirst(deq *, int);
void addLast(deq *, int);
int deleteFirst(deq *);
int deleteLast(deq *);


void menu(){
    printf("        Double Ended Queue Operations       \n");
    printf("---------------------------------------------\n");
    printf("1.Insert at front\n");
    printf("2.Insert at rear\n");
    printf("3.Delete front\n");
    printf("4.Delete rear\n");
    printf("5.Quit\n");
}

int main(int argc, char** argv) {

    deq queue;
    initQueue(&queue);
    int data, choice;
    int quit = 0;
    while(!quit){
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
       switch(choice){
           case 1:
               printf("Input data to put into first node: ");
               scanf("%d", &data);
               addFirst(&queue, data);
               break;
           case 2:
               printf("Input data to put into last node: ");
               scanf("%d", &data);
               addLast(&queue, data);
               break;
           case 3:
               if(queue.nodeCount > 0){
                   data = deleteFirst(&queue);
                   printf("Deleted value from front: %d\n", data);
               }
               else{
                   printf("Underflow, Queue is empty.\n");
               }
               break;
           case 4: 
               if(queue.nodeCount > 0){
                   data = deleteLast(&queue);
                   printf("Deleted value from rear: %d\n", data);
               }
               else
               {
                   printf("Underflow, Queue is empty.\n");
               }
               break;
           case 5:
               quit = 1;
           default:
               printf("not a valid choice.");
               break;
    }
    
    }
    return (EXIT_SUCCESS);
}

void initQueue(deq *queue){
    queue->head = NULL;
    queue->tail = NULL;
    queue->nodeCount = 0;
}


int deleteFirst(deq *queue){
    if(queue->nodeCount == 0){
        return -999;
    }
    Node *current = queue->head;
    int data = current->data;
    if(queue->nodeCount == 1){
        queue->head = NULL;
        queue->tail = NULL;
    }
    else{
        queue->head = queue->head->next;
        queue->head->prev = NULL;
    }
    free(current);
    queue->nodeCount--;
    return data;
}

int deleteLast(deq *queue){
    if(queue->nodeCount == 0){
        return -999;
    }
    Node *current = queue->tail;
        
    if(queue->nodeCount == 1){
        queue->head = NULL;
        queue->tail = NULL;
    }
    else{
        queue->tail = queue->tail->prev;
        queue->tail->next = NULL;
    }
    int data = current->data;
    queue->nodeCount--;
    free(current);
    return data;
}


void addFirst(deq *queue, int data){
    /*
     create new node first
     * assign node content with data 
     * initialize previous and next pointer(NULL)
     */
    Node *newPtr = (Node*)malloc(sizeof(Node));
    if(newPtr == NULL){
        printf("Unable to create new node.");
        return;
    }
    newPtr->data = data;
    newPtr->prev = NULL;
    newPtr->next = NULL;
    
    if(queue->nodeCount == 0){
        queue->head = newPtr;
        queue->tail = newPtr;
        
    }
    else{
        newPtr->next = queue->head;
        queue->head->prev = newPtr;
        queue->head = newPtr;
    }
    queue->nodeCount++;
}

void addLast(deq *queue, int data){
    Node *newPtr = (Node*)malloc(sizeof(Node));
    if(newPtr == NULL){
        printf("Unable to create new node.");
        return;
    }
    newPtr->data = data;
    newPtr->prev = NULL;
    newPtr->next = NULL;
    
    if(queue->nodeCount == 0){
        queue->head = newPtr;
        queue->tail = newPtr;
        
    }
    else{
        queue->tail->next = newPtr;
        newPtr->prev = queue->tail;
        queue->tail = newPtr;
    }
    queue->nodeCount++;
}



