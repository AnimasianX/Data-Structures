/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on September 30, 2018, 3:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * Linked List
 */


typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct{
    struct Node *head;
    struct Node *tail;
    int nodeCount;
}LinkedList;



//function prototypes
void initList(LinkedList *);
void createListRandomNumbers(LinkedList *, int);
int loadFromFile(LinkedList *, char *);
void insertAtHead(LinkedList *, int);
void insertAtTail(LinkedList *, int);
void printListDetail(LinkedList *);
void printList(LinkedList *);
Node * find(LinkedList *, int, Node **);
int deleteFirst(LinkedList *);
int deleteLast(LinkedList *);
int deleteTarget(LinkedList *, int);
void reverse(LinkedList *);


//functions
void initList(LinkedList *l){
    l->head = NULL;
    l->tail = NULL;
    l->nodeCount = 0;
}

void createListRandomNumbers(LinkedList *listptr, int n){
    int i;
    srand(time(NULL));
    for(i = 1; i<= n ; i++){
        int k = rand() % 1000;
        insertAtTail(listptr, k);
    }
}
void insertAtHead(LinkedList *listptr, int data){
    //create the new node
    
    Node *newNodePtr = (Node*)malloc(sizeof(Node));
    if(newNodePtr == NULL){
        printf("Unable to create new node.");
    }
    
    newNodePtr->data = data;
    newNodePtr->next = NULL;
    
    if(listptr->nodeCount == 0){
        listptr->head = newNodePtr;
        listptr->tail = newNodePtr;
    }
    else{
        //we need to assign the current head node to 
        //new node and then assign the head to the new Node.
        newNodePtr->next = listptr->head;
        listptr->head = newNodePtr;
    }
    listptr->nodeCount++;
}

void insertAtTail(LinkedList *listptr, int data){
    //create a new node
    //dynamically allocate size
    Node *newNodePtr = (Node*)malloc(sizeof(Node));
    if(newNodePtr == NULL){
        printf("Unable to create new node");
        return;
    }
    
    //assign new node with inputted data and
    //point it to null
    newNodePtr->data = data;
    newNodePtr->next = NULL;
    
    //if our current linked list is empty
    //then assign the head and tail of our linked
    //list to the new node.
    if(listptr->nodeCount == 0){
        printf("Linked list is empty.\n");
        printf("Adding new node.\n");
        listptr->head = newNodePtr;
        listptr->tail = newNodePtr;
    }
    //else we point the tail of the current linked list
    //to the newly added node
    //
    else{
       //adding the address of new node to the next pointer field of the
       //new node
        //basically point the next node to the new node
        //and then assign the tail to the new node
        //current tail->next is pointing to null
        //so we assign that next to the new node
        //and then assign our tail node to the new node
        listptr->tail->next = newNodePtr;
        listptr->tail = newNodePtr;
    }
    listptr->nodeCount++;
}

void printListDetail(LinkedList *listptr){
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
        printf("Node %d: (%p)[%d | %p]\n",counter,currentNode,currentNode->data,currentNode->next);
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

int loadFromFile(LinkedList *listptr, char *c){
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
        insertAtTail(listptr, data);
        fscanf(inputFile, "%d", &data);
    }
    fclose(inputFile);
    return 1;
}

void printList(LinkedList *listptr){
    if(listptr->nodeCount == 0){
        printf("List is empty.");
        return;
    }
    
    Node *currentNode = listptr->head;
    while(currentNode != NULL){
        printf("%d\n", currentNode->data);
        //once currentNode is assigned to the next node
        //if that next node point to null, it will run once more
        //and then terminate
        //[50|100] -> [100|'\0']
        //currentNode -> [100|'\0'] -> NULL(terminate)
        currentNode = currentNode->next;
    }
}

int deleteFirst(LinkedList *listptr){
    if(listptr->nodeCount == 0){
        printf("Error, list is empty.\n");
        return -9999;
    }
     Node *currentNode = listptr->head;
     int data = currentNode->data;
    if(listptr->nodeCount == 1){
        //only one node i n the list
        listptr->head = NULL;
        listptr->tail = NULL;
        
    }
    else{
        listptr->head = currentNode->next;
    }
     free(currentNode);
     listptr->nodeCount--;
     return data;
}

int deleteLast(LinkedList *listptr){
    if(listptr->nodeCount == 0){
        return -9999;
    }
    Node *currentNode = listptr->head;
    Node *lastNode = listptr->tail;
    int data = lastNode->data;
    if(listptr->nodeCount == 1){
        //only one node i n the list
        listptr->head = NULL;
        listptr->tail = NULL;
        
    }
    else{
        while(currentNode->next != listptr->tail){
            currentNode = currentNode->next;
            }
        listptr->tail = currentNode;
        listptr->tail->next = NULL;
    }
    
    free(lastNode);
    listptr->nodeCount--;
    return data;  
}

Node * find(LinkedList *listptr, int target, Node **prev){
    
    if(listptr->nodeCount == 0){
        printf("List is empty.");
        return NULL;
    }
    *prev = NULL;
    
    Node *currentNode = listptr->head;
    while(currentNode != NULL){
      if(currentNode->data == target){
          break;
      }  
      *prev = currentNode;
      currentNode = currentNode->next;
    }
    
    return currentNode;
}

int deleteTarget(LinkedList *listptr, int target){
    //initialize current and previous node to populate
    
    Node *current = NULL, *prev = NULL;
    //current returns current node and addresses prev
    //to the immediate node previous to the current one
    //by referencing prev
    current = find(listptr, target, &prev);
    
    if(current == NULL){
        return -9999;
    }
    
    int data = current->data;
    if(current == listptr->head){
       return  deleteFirst(listptr);
    }
    else if(current == listptr->tail){
       return deleteLast(listptr);
    }
    else
    {
        prev->next = current->next;
        free(current);
        listptr->nodeCount--;
        return data;
    }
    
}

void reverse(LinkedList *listptr){
    
    if(listptr->nodeCount <= 1){
        printf("Cannot reverse a list with no nodes.");
        return;
    }
    
    Node *q, *p, *r;
    q = NULL;
    p = listptr->head;
    r = p->next;
    while(1){
        p->next = q;
        if(p == listptr->tail){
            break;
        }
        q = p;
        p = r;
        r = r->next;
    }
    listptr->tail = listptr->head;
    listptr->head = p;
}


void menu(){
    printf("   Singly Linked List Operations\n");
    printf("------------------------------------\n");
    printf("1.Load from file\n");
    
    printf("2.Insert at head\n");
    printf("3.Insert at tail\n");
    printf("4.Print list (detail)\n");
    
    printf("5.Print List(detail)\n");
    printf("6.Find\n");
    
    printf("7.Delete First\n");
    printf("8.Delete last\n");
    printf("9.Delete target node\n");
    printf("10.Reverse\n");
    printf("11.Create Random List\n");
    printf("12.Quit\n");
    
}
int main(int argc, char** argv) {

    LinkedList list;
    initList(&list);
    
    int choice;
   
    Node *current = NULL, *prev = NULL;
    int value;
    int quit = 0;
    int success;
    
    while(!quit){
        menu();
        printf("Please input your choice: ");
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
                printf("Input value at head: ");
                scanf("%d", &value);
                insertAtHead(&list, value);
                break;
            case 3:
                printf("Input value at tail: ");
                scanf("%d", &value);
                insertAtTail(&list, value);
                break;
            case 4:
                printListDetail(&list);
                break;
            case 5:
                printList(&list);
                break;
            case 6:
                printf("Input value to find: ");
                scanf("%d", &value);
                current = find(&list, value, &prev);
                if(current == NULL){
                    printf("Target not found");
                }
                else
                {
                    printf("[Current : %p ] [Previous : %p ]", current, prev);
                }
                break;
            case 7:
                value = deleteFirst(&list);
                if(value == -9999){
                    printf("List is empty, deletion failed.");
                }
                else
                    printf("Deleted Value from head: %d", value);
                
                break;
            case 8:
                value = deleteLast(&list);
                if(value == -9999){
                    printf("List is empty, deletion failed.");
                }
                else
                    printf("Deleted Value from tail: %d", value);
                break;
            case 9:
                printf("Enter target to delete: ");
                scanf("%d", &value);
                int data = deleteTarget(&list, value);
                if(data == -9999){
                    printf("Target not found. Does not exist.\n");
                }
                else{
                    printf("Target node with data: %d is deleted successfully", data);
                }
                break;
            case 10:
                reverse(&list);
                break;
            case 11:
                printf("How many number do you want to generate?");
                scanf("%d", &value);
                createListRandomNumbers(&list, value);
                break;
            case 12:
                choice = -1;
                break;  
            default:
                printf("Not a valid choice.");
        }
    }
    return (EXIT_SUCCESS);
}

//    printf("   Singly Linked List Operations\n");
//    printf("------------------------------------");
//    printf("1.Load from file\n");
//    
//    printf("2.Insert at head\n");
//    printf("3.Insert at tail\n");
//    printf("4.Print list (detail)\n");
//    
//    printf("5.Print List(detail)\n");
//    printf("6.Find\n");
//    
//    printf("7.Delete First\n");
//    printf("8.Delete last\n");
//    printf("9.Delete target node\n");
//    printf("10.Reverse\n");
//    printf("11.Generate with random numbers\n");
//    printf("12.Quit\n");


