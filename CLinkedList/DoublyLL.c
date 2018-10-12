/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoublyLL.c
 * Author: animasian
 *
 * Created on October 11, 2018, 2:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
/*
 * Double-ended Linked List implementation
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
}DblList;



//prototypes
void initList(DblList *);
void addFirst(DblList *, int);
void addLast(DblList *, int);
int loadFromFile(DblList *, char *);
void createListFromRandomNumbers(DblList *, int);
void printListDetail(DblList *);
void printForward(DblList *);
void printReverse(DblList *);
Node* find(DblList *, int);
int insertAfter(DblList *,int, int);
int insertBefore(DblList *, int, int);
int deleteFirst(DblList *);
int deleteLast(DblList *);
int deleteTarget(DblList *, int);
void menu();
// end of prototypes


void menu(){
    printf("   Doubly Linked List Operations\n");
    printf("------------------------------------\n");
    printf("1.Load from file\n");
    
    printf("2.Generate random numbers\n");
    printf("3.Add at first position\n");
    printf("4.Add to last position\n");
    
    printf("5.Print List(detail)\n");
    printf("6.Print first to last\n");
    
    printf("7.Print last to first\n");
    printf("8.Find\n");
    printf("9.Insert After\n");
    printf("10.Insert before\n");
    printf("11.Delete first\n");
    printf("12.Delete last\n");
    printf("13.Delete target node\n");
    printf("14.Quit\n");
    
}

int main(int argc, char** argv) {

    DblList list;
    initList(&list);
    int choice;
    int quit = 0;
    int data, n, target;
    int success;
    Node *current = NULL, *prev = NULL;
    
    while(!quit){
        menu();
        printf("Please enter an operation: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                 success = loadFromFile(&list, "/Users/animasian/CProjects/Datafile/loadNodeData.txt");
                if(success == 1)
                printf("File has been loaded.");
                else
                    printf("Error loading file.");
                break;
            case 2:
                printf("How many number do you want to generate?");
                scanf("%d", &n);
                createListFromRandomNumbers(&list, n);
                break;
            case 3:
                printf("What value would you like to add: ");
                scanf("%d", &data);
                addFirst(&list, data);
                break;
            case 4:
                printf("What value would you like to add: ");
                scanf("%d", &data);
                addLast(&list, data);
                break;
            case 5:
                printListDetail(&list);
                break;
            case 6:
                printForward(&list);
                break;
            case 7:
                printReverse(&list);
                break;
            case 8:
                printf("What value to find: ");
                scanf("%d", &target);
                current = find(&list, target);
                if(current == NULL){
                    printf("Linked list does not have the target specified.\n");
                }
                else{
                    printf("Target Exists:\n");
                    printf("[%p|%d]", current, current->data);
                }
                break;
            case 9:
                printForward(&list);
                printf("Where do you want to insert after?");
                scanf("%d", &target);
                
                printf("What value do you want to insert: ");
                scanf(" %d", &data);
                if(insertAfter(&list, target, data)){
                    printf("Insert After %d was successful!\n", target);
                }
                else{
                    printf("Inserting after %d failed. Target may not exist.\n", target);
                }
                break;
            case 10: 
                 printForward(&list);
                printf("Where do you want to insert before?");
                scanf("%d", &target);
                
                printf("What value do you want to insert: ");
                scanf(" %d", &data);
                if(insertBefore(&list, target, data)){
                    printf("Insert After %d was successful!\n", target);
                }
                else{
                    printf("Inserting after %d failed. Target may not exist.\n", target);
                }
                break;
            case 11:
                if(deleteFirst(&list)){
                    printf("First node deleted successfully.\n");
                }
                else{
                    printf("Unable to delete first node.\n");
                }
                break;
            case 12:
                if(deleteLast(&list)){
                    printf("Last node deleted successfully.\n");
                }
                else{
                    printf("Unable to delete last node.\n");
                }
                break;
            case 13:
                printf("Enter target node to delete: ");
                scanf("%d", &target);
                if(deleteTarget(&list, target)){
                    printf("Target deleted successfully.");
                    
                }
                else
                {
                    printf("Error: unable to delete.\nAre you sure the target exists?\n");
                }
                break;
            case 14:
                exit(1);
                break;
            default:
                printf("not a valid choice.");
                break;
        }
        
    }
    return (EXIT_SUCCESS);
}


void initList(DblList *listptr){
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->nodeCount = 0;
}

void addFirst(DblList *listptr, int data){
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
    
    if(listptr->nodeCount == 0){
        listptr->head = newPtr;
        listptr->tail = newPtr;
        
    }
    else{
        newPtr->next = listptr->head;
        listptr->head->prev = newPtr;
        listptr->head = newPtr;
    }
    listptr->nodeCount++;
}

void addLast(DblList *listptr, int data){
    Node *newPtr = (Node*)malloc(sizeof(Node));
    if(newPtr == NULL){
        printf("Unable to create new node.");
        return;
    }
    newPtr->data = data;
    newPtr->prev = NULL;
    newPtr->next = NULL;
    
    if(listptr->nodeCount == 0){
        listptr->head = newPtr;
        listptr->tail = newPtr;
        
    }
    else{
        listptr->tail->next = newPtr;
        newPtr->prev = listptr->tail;
        listptr->tail = newPtr;
    }
    listptr->nodeCount++;
}

void printListDetail(DblList *listptr){
     if(listptr->nodeCount == 0){
        printf("List is empty.");
        return;
    }
    
    printf("Printing linked list in detail:\n");
    printf("Head: %p\n", listptr->head);
    Node *currentNode = (Node*)malloc(sizeof(Node));
    currentNode = listptr->head;
    int counter = 1;
    while(currentNode != NULL){
        printf("Node %d: (%p)[%p | %d | %p]\n",counter,currentNode,currentNode->prev,currentNode->data,currentNode->next);
        //once currentNode is assigned to the next node
        //if that next node point to null, it will run once more
        //and then terminate
        //[50|100] -> [100|'\0']
        //currentNode -> [100|'\0'] -> NULL(terminate)
        currentNode = currentNode->next;
        counter++;
    }
    printf("Tail: %p\n", listptr->tail);
}


int loadFromFile(DblList *listptr, char *c){
    FILE *inputFile = fopen(c, "r");
    if(inputFile == NULL){
        printf("Error, cannot open file.");
        return 0;
    }
    
    int data;
    //first parameter is the input file
    //second parameter is the format identifier
    //third is where the variable should be stored
    fscanf(inputFile, "%d", &data);
    while(!feof(inputFile)){
        addLast(listptr, data);
        fscanf(inputFile, "%d", &data);
    }
    fclose(inputFile);
    return 1;
}

void createListFromRandomNumbers(DblList *listptr, int n){
    int i;
    srand(time(NULL));
    for(i = 1; i<= n ; i++){
        int k = rand() % 1000;
        addLast(listptr, k);
    }
}

void printForward(DblList *listptr){
    Node *current = listptr->head;
    if(current == NULL){
        printf("Linked list is empty\n");
        return;
    }
    printf("Content of doubly linked list:\n");
    while(current != NULL){
        printf("%4d", current->data);
        current = current->next;
    }
    printf("\n--End --\n");
}

void printReverse(DblList *listptr){
    Node *current = listptr->tail;
    if(current == NULL){
        printf("Linked list is empty.");
        return;
    }
    printf("Doubly linked list content backwards: \n");
    while(current != NULL){
     printf("%4d", current->data);
     current = current->prev;
    }
    
    printf("\n -- End -- \n");
}

Node* find(DblList *listptr, int target){
    Node *current;
    for(current = listptr->head; current!=NULL; current = current->next){
        if(current->data == target){
            return current;
        }
    }
    return NULL;
}

int insertAfter(DblList *listptr, int target, int data){
    Node *current = find(listptr, target);
    if(current == NULL){
        return 0;
    }
    
    if(current == listptr->tail){
        addLast(listptr, data);
    }
    else{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        if(newNode == NULL){
            printf("Node could not be allocated.");
            return 0;
        }
        
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        newNode->next->prev = newNode;
    }
    listptr->nodeCount++;
    return 1;
}

int insertBefore(DblList *listptr, int target, int data){
    Node *current = find(listptr, target);
    if(current == NULL){
        return 0;
    }
    
    if(current == listptr->head){
        addFirst(listptr, data);
    }
    else{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        if(newNode == NULL){
            printf("Node could not be allocated.");
            return 0;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev = newNode;
        newNode->prev->next = newNode;
        
    }
    listptr->nodeCount++;
    return 1;
}

int deleteFirst(DblList *listptr){
    if(listptr->nodeCount == 0){
        return 0;
    }
    Node *current = listptr->head;
    if(listptr->nodeCount == 1){
        listptr->head = NULL;
        listptr->tail = NULL;
    }
    else{
        listptr->head = listptr->head->next;
        listptr->head->prev = NULL;
    }
    free(current);
    listptr->nodeCount--;
    return 1;
}

int deleteLast(DblList *listptr){
    if(listptr->nodeCount == 0){
        return 0;
    }
    Node *current = listptr->tail;
        
    if(listptr->nodeCount == 1){
        listptr->head = NULL;
        listptr->tail = NULL;
    }
    else{
        listptr->tail = listptr->tail->prev;
        listptr->tail->next = NULL;
    }
    listptr->nodeCount--;
    free(current);
    return 1;
}


int deleteTarget(DblList *listptr, int target){
    Node *current = find(listptr, target);
    if(current == NULL){
        return 0;
    }
    
    if(current == listptr->head){
        deleteFirst(listptr);
    }
    else if(current == listptr->tail){
        deleteLast(listptr);
    }
    else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        listptr->nodeCount--;
        return 1;
    }
   
}
