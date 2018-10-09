/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on September 27, 2018, 11:59 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Algorithm for FIFO Queue using 1-D array
 */
#define SIZE 5



///****Problem with this queue is that it does not account for the space used earlier in the array
// for example, if you dequeue, the rear and front do not decrement
// therefore, once it reaches the max size, it will have overflow and underflow.


typedef struct{
   int item[SIZE];
   int rear;
   int front;
}Queue;

//prototypes
void init(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);

//
void init(Queue *q){
  
   q->front = 0;
   q->rear = 0;
   
}

void enqueue(Queue *q, int value){
   if(q->rear == SIZE){
       printf("Queue Overflow.");
       return;
   }
   
   
   q->item[q->rear] = value;
   q->rear = (++q->rear);
  
}
int dequeue(Queue *q){
   if(q->rear == q->front)
   {
       printf("Queue Underflow.");
       exit(1);
       
   }
   
   int v = q->item[q->front];
   q->front = (q->front + 1);
   
   return v;
   
   
}
//int main(int argc, char** argv) {
   Queue q;
   init(&q);

//This section to test queue working[
////    enqueue(&q, 5);
////    enqueue(&q, 10);
////    enqueue(&q, 15);
////    enqueue(&q, 20);
////    
////    printf("%d\n", dequeue(&q));
////    printf("%d\n", dequeue(&q));
////    printf("%d\n", dequeue(&q));
////    printf("%d\n", dequeue(&q));
////    printf("%d\n", dequeue(&q));
//    
// ]
   int quit = 0;
   int value;
   while(!quit){
       int choice;
       printf("Input your option:\n1.Enqueue\n2.Dequeue\n3.Quit\n");
       scanf("%d", &choice);
       
       switch(choice){
           case 1: 
               printf("Input value to enqueue: ");
               scanf("%d", &value);
               enqueue(&q, value);
               break;
           case 2:
               value = dequeue(&q);
               if(value = -9999)
               {
                   printf("Queue Underflow\n");
               }
               else
                   printf("Dequeued value: %d\n", value);
               break;
           case 3: 
               quit = 1;
               break;
           default: 
               printf("Not a valid choice.\n");
               
            
               
       }
   }
   
   
   return (EXIT_SUCCESS);
}



//*****// circular queue fixes the FIFO problem//*****//



typedef struct{
   int item[SIZE];
   int rear;
   int front;
}Queue;

//prototypes
void init(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);

//
void init(Queue *q){
  //test
   q->front = SIZE -1;
   q->rear = SIZE -1;
   
}

void enqueue(Queue *q, int value){
  //if rear + 1 % SIZE is front, then you cannot add anymore
   if((q->rear + 1) % SIZE == q->front){
       printf("Queue Overflow.");
       return;
   }
   
   //
  
   q->rear = (q->rear +1) % SIZE;
   q->item[q->rear] = value;
  
}
int dequeue(Queue *q){
   if(q->rear == q->front)
   {
       
       return -9999;
       
   }
   
   
   q->front = (q->front + 1) % SIZE;
   int v = q->item[q->front];
   return v;
   
   
}
int main(int argc, char** argv) {
   Queue q;
   init(&q);
//    enqueue(&q, 5);
//    enqueue(&q, 10);
//    enqueue(&q, 15);
//    enqueue(&q, 20);
//    
//    printf("%d\n", dequeue(&q));
//    printf("%d\n", dequeue(&q));
//    printf("%d\n", dequeue(&q));
//    printf("%d\n", dequeue(&q));
//    printf("%d\n", dequeue(&q));
   
   int quit = 0;
   int value;
   while(!quit){
       int choice;
       printf("Input your option:\n1.Enqueue\n2.Dequeue\n3.Quit\n");
       scanf("%d", &choice);
       
       switch(choice){
           case 1: 
               printf("Input value to enqueue: ");
               scanf("%d", &value);
               enqueue(&q, value);
               break;
           case 2:
               value = dequeue(&q);
               if(value == -9999)
               {
                   printf("Queue Underflow\n");
               }
               else
                   printf("Dequeued value: %d\n", value);
               break;
           case 3: 
               quit = 1;
               break;
           default: 
               printf("Not a valid choice.\n");
               
            
               
       }
   }
   
   
   return (EXIT_SUCCESS);
}




/********************
 * Double ended queue
 *******************/

#define SIZE 5
typedef struct{
    int item[SIZE];
    int front;
    int rear;
}dQueue;

void init(dQueue *);
void insertAtRear(dQueue *, int);
int deleteFromRear(dQueue *);
void insertAtFront(dQueue *, int);
int deleteFromRear(dQueue *);

void init(dQueue *q){
    q->front = 0;
    q->rear = -1;
}


void insertAtRear(dQueue *q, int value){
    if(q->rear == SIZE -1){
        printf("Unable to add anymore to rear.\n");
        return;
    }
    q->rear = q->rear + 1;
    q->item[q->rear] = value;
}


int deleteFromRear(dQueue *q){
    if(q->front > q->rear){
       
        return -9999;
    }
    
    int value;
    value = q->item[q->rear];
    q->rear = q->rear - 1;
    return value;
}

//it inserts front at the current value backwards
//goes down by one and then inserts 
void insertAtFront(dQueue *q, int value){
    if(q->front == 0){//basically it inserts like a stack
        printf("Cannot insert at front\n");
        return;
    }
    
    q->front = q->front - 1;
    q->item[q->front] = value;
}

//if front value is greater than rear, it should print underflow because there will be nothing in the queue.
//same as starting case
int deleteFromFront(dQueue *q){
    if(q->front > q->rear){
        
        return -9999;
    }
    //first element will always be rear at 0 to delete
    int value = q->item[q->front];
    q->front = q->front + 1;
    return value; 
}

int main(){
    dQueue q;
    init(&q);
    
    int i = 1;
    int choice;
    while(i){
        printf("Choice:\n1.Add to Rear\n2.Delete from Rear\n3.Add to Front\n4.Delete from Front\n5.Exit\n");
        scanf("%d", &choice);
        int value = 0;
        switch(choice){
            case 1:
                printf("Enter your value to add to rear: ");
                scanf("%d", &value);
                insertAtRear(&q, value);
                break;
            case 2:
                value = deleteFromRear(&q);
                if(value == -9999){
                    printf("Queue underflow.\n");
                    break;
                }
                printf("Deleted value: %d\n", value);
                break;
            case 3:
                printf("Enter your value to add to rear: ");
                scanf("%d", &value);
                insertAtFront(&q, value);
                break;
            case 4:
                value = deleteFromFront(&q);
                if(value == -9999){
                    printf("Queue underflow.\n");
                    break;
                }
               
                printf("Deleted value: %d\n", value);
                break;
            case 5:
                printf("Exiting.");
                i = 0;
                break;
            default:
                printf("Not a valid choice.\n");
        }
    }
    
    return 0;
}
