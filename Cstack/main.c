/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on September 8, 2018, 2:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
//#define SIZE 10
///*
// * 
// */
//
//typedef struct {
//    int item[SIZE];
//    int top;
//    
//}Stack;
//
//void init(Stack *sp);
//void push(Stack *, int);
//    
//int pop(Stack *);
//
////initializes stack with -1 to represent it is empty.
//void init(Stack *sp)
//{
// sp->top = -1;   
//}
//void push(Stack *sp, int value)
//{
//    if(sp->top == SIZE -1)
//    {
//        printf("Stack Overflow.\n");
//        return;
//    }
////increments the top so that at index 0, the array is still empty
////in our case, since top is -1(could also be 0), we increment the topso that we can compare the size to the top  to see if there is overflow

//    sp->top++;
////here, we set the value we put in into the item array at the newly incremented top 
//    sp->item[sp->top] = value;
//    
//}
//
//int pop(Stack *sp)
//{
//    if(sp->top == -1)
//    {
//        printf("Stack underflow\n");
//        return -9999;
//    }
//    int value;
//    value = sp->item[sp->top];
//    sp->top--;
//    return value;
//}
//
//int main(int argc, char** argv) {
//    Stack s1, s2;
//    init(&s1);
//    init(&s2);
//    int choice;
//    int userValue;
//    printf("What operation do you want to perform on the stack?\n");
//    
//    
//    
//    
//    while(1)
//    {
//        printf("1.Push\n2.Pop\n3.Exit\n");
//        scanf("%d", &choice);
//        switch(choice){
//                case 1: 
//                        printf("Enter value to push onto stack:");
//                        scanf("%d",&userValue);
//                        push(&s1, userValue);
//                        break;
//                case 2: 
//                    userValue= pop(&s1);
//                    if(userValue !=-9999){
//                        printf("Popped value: %d\n", userValue);
//                    }
//                        break;
//                case 3: 
//                        exit(0);
//                        break;
//                
//                default: printf("Invalid value.");
//        }
//    }
//   
//    
//    
//    
//    
//    return 0;
//}


/*
 * Dynamic Stack implementation
 */

//typedef struct {
//    int *item;
//    int size;
//    int top;
//    
//}Stack;
//
//void init(Stack *sp, int);
//void push(Stack *, int);
//void deallocate(Stack *);  
//int pop(Stack *);
//int getSize(Stack *);

//
//int getSize(Stack *sp)
//{
//    return sp->size;
//}
//
//
//void init(Stack *sp,int size)
//{
// sp->top = -1;
// sp->item = (int *)malloc(sizeof(int) * size);
// if(sp->item == NULL)
// {
//     printf("Memory allocation failed.");
//     exit(1);
// }
//sp->size = size; 
// 
//}
//void push(Stack *sp, int value)
//{
//    if(sp->top == sp->size -1)
//    {
//        int *temp;
//        temp = (int *)malloc(sizeof(int) * sp->size *2);
//        if(temp == NULL)
//        {
//            printf("Stack overflow");
//            return;
//        }
//        int i;
//        for(i=0;i<=sp->top;i++)
//        {
//            temp[i] = sp->item[i];
//            
//        }
//        free(sp->item);
//        sp->item = temp;
//        sp->size *= 2;
//    }
//    sp->top++;
//    sp->item[sp->top] = value;
//    
//}
//
//int pop(Stack *sp)
//{
//    if(sp->top == -1)
//    {
//        printf("Stack underflow\n");
//        return -9999;
//    }
//    int value;
//    value = sp->item[sp->top];
//    sp->top--;
//    return value;
//}
//
//
//void deallocate(Stack *sp)
//{
//    if(sp->item != NULL)
//    {
//        free(sp->item);
//        printf("Stack deallocated.");
//    }
//    sp->top = -1;
//    sp->size = 0;
//}
//int main(int argc, char** argv) {
//    Stack s1;
//    
//    
//    int choice, size;
//    int userValue;
//    printf("Size of the stack: ");
//    scanf("%d",&size);
//    init(&s1, size);
//    printf("What operation do you want to perform on the stack?\n");
//    
//    
//    
//    
//    while(1)
//    {
//        printf("1.Push\n2.Pop\n3.Exit\n");
//        scanf("%d", &choice);
//        printf("Size of stack: %d\n", getSize(&s1));
//        switch(choice){
//                case 1: 
//                        printf("Enter value to push onto stack:");
//                        scanf("%d",&userValue);
//                        push(&s1, userValue);
//                        
//                        break;
//                case 2: 
//                    userValue= pop(&s1);
//                    if(userValue !=-9999){
//                        printf("Popped value: %d\n", userValue);
//                    }
//                        break;
//                case 3: 
//                    deallocate(&s1);
//                        exit(0);
//                        break;
//                
//                default: printf("Invalid value.");
//        }
//    }
//   
//    
//    
//    
//    
//    return 0;
//}




/*
 Print Binary example
 
 */

//typedef struct {
//    int *item;
//    int size;
//    int top;
//    
//}Stack;
//
//void init(Stack *sp, int);
//void push(Stack *, int);
//void deallocate(Stack *);  
//int pop(Stack *);
//int getSize(Stack *);
//void printBinary(unsigned int);
//int isUnderflow(Stack *);
//int isOverflow(Stack *);
//
//int isUnderflow(Stack *sp)
//{
//    return sp->top == -1;
//}
//
//int isOverflow(Stack *sp)
//{
//    return sp->top == sp->size -1;
//}
//
//void printBinary(unsigned int n)
//{
//    Stack s;
//    int placeHolder = n;
//    init(&s, 10);
//    while(n != 0)
//    {
//        if(n%2 == 0)
//        {
//            push(&s, 0);
//            n /= 2;
//        }
//        else {
//            push(&s, 1);
//            n /= 2;
//        }
//    }
//    
//    printf("Binary equivalent of %d is: \n",placeHolder);
//    while(!isUnderflow(&s))
//    {
//        printf("%d",pop(&s));
//    }
//    deallocate(&s);
//}
//int getSize(Stack *sp)
//{
//    return sp->size;
//}
//
//
//void init(Stack *sp,int size)
//{
// sp->top = -1;
// sp->item = (int *)malloc(sizeof(int) * size);
// if(sp->item == NULL)
// {
//     printf("Memory allocation failed.");
//     exit(1);
// }
//sp->size = size; 
// 
//}
//void push(Stack *sp, int value)
//{
//    if(isOverflow(sp))
//    {
//        int *temp;
//        temp = (int *)malloc(sizeof(int) * sp->size *2);
//        if(temp == NULL)
//        {
//            printf("Stack overflow");
//            return;
//        }
//        int i;
//        for(i=0;i<=sp->top;i++)
//        {
//            temp[i] = sp->item[i];
//            
//        }
//        free(sp->item);
//        sp->item = temp;
//        sp->size *= 2;
//    }
//    sp->top++;
//    sp->item[sp->top] = value;
//    
//}
//
//int pop(Stack *sp)
//{
//    if(isUnderflow(sp))
//    {
//        printf("Stack underflow\n");
//        return -9999;
//    }
//    int value;
//    value = sp->item[sp->top];
//    sp->top--;
//    return value;
//}
//
//
//void deallocate(Stack *sp)
//{
//    if(sp->item != NULL)
//    {
//        free(sp->item);
//       
//    }
//    sp->top = -1;
//    sp->size = 0;
//}
//int main(int argc, char** argv) {
//    Stack s1;
//    printBinary(6585);
//    
//    
//    
//    
//    
//    
//    
//    
//    return 0;
//}


/*
 Reversing file content using stack
 
 */




//typedef struct {
//    char *item;
//    int size;
//    int top;
//    
//}Stack;
//
//void init(Stack *sp, int);
//void push(Stack *, char);
//void deallocate(Stack *);  
//char pop(Stack *);
//int getSize(Stack *);
//int reverseIt(char [], char[]);
//int isUnderflow(Stack *);
//int isOverflow(Stack *);
//
//int isUnderflow(Stack *sp)
//{
//    return sp->top == -1;
//}
//
//int isOverflow(Stack *sp)
//{
//    return sp->top == sp->size -1;
//}
//
//
//int getSize(Stack *sp)
//{
//    return sp->size;
//}
//
//
//void init(Stack *sp,int size)
//{
// sp->top = -1;
// sp->item = (char *)malloc(sizeof(char) * size);
// if(sp->item == NULL)
// {
//     printf("Memory allocation failed.");
//     exit(1);
// }
//sp->size = size; 
// 
//}
//void push(Stack *sp, char value)
//{
//    if(isOverflow(sp))
//    {
//        char *temp;
//        temp = (char *)malloc(sizeof(char) * sp->size *2);
//        if(temp == NULL)
//        {
//            printf("Stack overflow");
//            return;
//        }
//        int i;
//        for(i=0;i<=sp->top;i++)
//        {
//            temp[i] = sp->item[i];
//            
//        }
//        free(sp->item);
//        sp->item = temp;
//        sp->size *= 2;
//    }
//    sp->top++;
//    sp->item[sp->top] = value;
//    
//}
//
//char pop(Stack *sp)
//{
//    if(isUnderflow(sp))
//    {
//        printf("Stack underflow\n");
//        return '\0';
//    }
//    int value;
//    value = sp->item[sp->top];
//    sp->top--;
//    return value;
//}
//
//
//void deallocate(Stack *sp)
//{
//    if(sp->item != NULL)
//    {
//        free(sp->item);
//       
//    }
//    sp->top = -1;
//    sp->size = 0;
//}
//
//int reverseIt(char source[], char destination[])
//{
//    FILE *fps, *fpd;
//    const int SIZE = 50;
//    fps = fopen(source, "r");
//    
//    if(fps==NULL)
//    {
//        printf("Error opening source file: %s\n", source);
//        return 0;
//    }
//    fpd = fopen(destination, "w");
//    if(fpd==NULL)
//    {
//        printf("Error opening file %s\n", destination);
//        return 0;
//    }
//    
//    Stack s;
//    init(&s, SIZE);
//    char buffer;
//    buffer = fgetc(fps);
//    while(!feof(fps))
//    {
//        push(&s,buffer);
//        buffer = fgetc(fps);
//    }
//    
//    while(!isUnderflow(&s))
//    {
//        fputc(pop(&s),fpd);
//    }
//        
//    fclose(fps);
//    fclose(fpd);
//    deallocate(&s);
//    return 1;
//}
//
//int main(int argc, char** argv) {
//   
//    int f = reverseIt("/Users/animasian/Desktop/CPrograms/FilePractice/input_text.txt","/Users/animasian/Desktop/CPrograms/FilePractice/rev_text.txt");
//    
//    if(f)
//    {
//        printf("File copied Successfully.\n");
//    }
//    else 
//        printf("Error -- copy failed.\n");
//    
//    
//    
//    
//    
//    return 0;
//}




//Parenthesis Checking program


// implementation of bracket checker program

//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 100
//
//typedef struct {
//	char item[SIZE];
//	int top;
//}Stack;
//
//// function prototypes
//
//// function for stack operations
//void push(Stack *, char);
//char pop(Stack *);
//int isEmpty(Stack *);
//char stacktop(Stack *);
//
//// function required for this application
//int isOpeningMatch(char, char);
//
//// actual implementation of the algorithm
//int checkExpr(char[]);
//
//
//// push operation
//void push(Stack *sp, char v){
//	// checking overflow
//	if (sp->top == SIZE-1){
//		printf("Stack overflow, terminating program\n");
//		exit(1);
//	}
//	// otherwise push
//	sp->item[++sp->top] = v;		
//}
//// Pop operation
//char pop(Stack *sp){
//	if (isEmpty(sp)){
//		printf("Stack underflow, terminating program\n");
//		exit(1);
//	}	
//	return sp->item[sp->top--];
//}
//
//// returns 1 if the stack is empty, 0 otherwise
//int isEmpty(Stack *sp){
//	return sp->top == -1;
//}
//
//char stacktop(Stack *sp){
//	if (isEmpty(sp)){
//		printf("Stack underflow, terminating program\n");
//		exit(1);
//	}
//	return sp->item[sp->top];
//}
//
//int isOpeningMatch(char left, char right){
//	int match = 0;
//	switch(left){
//		case '(': if (right == ')')
//					match = 1;
//				  break;
//		case '{': if (right == '}')
//					match = 1;
//				  break;
//		case '[': if (right == ']')
//					match = 1;
//				  break;
//		default: printf("Invalid symbol encountered, terminating program\n");				  				  		   		
//				 exit(1);
//	}	
//	return match;
//}
//
//int checkExpr(char expr[]){
//	Stack stack;
//	stack.top = -1;
//	
//	int error = 0;
//	int i = 0;
//	while(expr[i]!='\0'){
//		// get the next character from the expr
//		char next_char = expr[i];
//		if (next_char == '(' || next_char == '{' || next_char == '[')
//			push(&stack, next_char);
//		else if(next_char == ')' || next_char == '}' || next_char == ']'){
//			if (isEmpty(&stack)){
//				error = 1;
//				break;
//			}
//			else if(isOpeningMatch(stacktop(&stack), next_char)){
//				pop(&stack);
//			}
//			else{
//				error = 1;
//				break;
//			}
//		}	
//		++i;
//	}
//	if (!error && !isEmpty(&stack)){
//		error = 1;		
//	}
//	return error;	
//}
//
//
//
//int main(){
//	char expr[SIZE];
//	printf("Input expression: ");
//	scanf("%s", expr);
//	
//	if (checkExpr(expr)){
//		printf("Does not contain well formed brackets\n");
//	}	
//	else{
//		printf("Contains well formed brackets\n");
//	}
//	return 0;
//}

#include <math.h>
#define SIZE 50
//typedef struct {
//    double *item;
//    int size;
//    int top;
//    
//}Stack;
//
//void init(Stack *sp);
//void push(Stack *, double);
//void deallocate(Stack *);  
//double pop(Stack *);
//int getSize(Stack *);
//int isEmpty(Stack *);
//
//int getSize(Stack *sp)
//{
//    return sp->size;
//}
//
//int isEmpty(Stack *sp)
//{
// return sp->top == -1;   
//}
//
//void init(Stack *sp)
//{
// sp->top = -1;
// sp->item = (double *)malloc(sizeof(double) * SIZE);
// if(sp->item == NULL)
// {
//     printf("Memory allocation failed.");
//     exit(1);
// }
//sp->size = SIZE; 
// 
//}
//void push(Stack *sp, double value)
//{
//    if(sp->top == sp->size -1)
//    {
//        double *temp;
//        temp = (double *)malloc(sizeof(double) * sp->size *2);
//        if(temp == NULL)
//        {
//            printf("Stack overflow");
//            return;
//        }
//        int i;
//        for(i=0;i<=sp->top;i++)
//        {
//            temp[i] = sp->item[i];
//            
//        }
//        free(sp->item);
//        sp->item = temp;
//        sp->size *= 2;
//    }
//    sp->top++;
//    sp->item[sp->top] = value;
//    
//}
//
//double pop(Stack *sp)
//{
//    if(sp->top == -1)
//    {
//        printf("Stack underflow\n");
//        return -9999;
//    }
//    int value;
//    value = sp->item[sp->top];
//    sp->top--;
//    return value;
//}
//
//
//void deallocate(Stack *sp)
//{
//    if(sp->item != NULL)
//    {
//        free(sp->item);
//        printf("Stack deallocated.");
//    }
//    sp->top = -1;
//    sp->size = 0;
//}
//
//double operate(double leftOp, double rightOp, char oper){
//    double result = 0.0;
//    switch(oper)
//    {
//        case '+': result = leftOp+rightOp;
//        break;
//        case '-': result = leftOp - rightOp;
//        break;
//        case '*': result = leftOp * rightOp;
//        break;
//        case '/': result = leftOp / rightOp;
//        break;
//        case '$': result = pow(leftOp,rightOp);
//        break;
//        default:
//            printf("%c is not a valid operator.\n", oper);
//            exit(1);
//    }
//    return result;
//}
//
//double evalPostfix(char postfix[])
//{
//    Stack s1;
//    init(&s1);
//    int i = 0;
//    while(postfix[i] != '\0'){
//        char token = postfix[i];
//        if(token >= '0' && token <='9'){
//            int v = token - '0';
//            push(&s1, (double)v);
//        }
//        else if(token == '+' || token == '-' || token == '*' || token == '/' || token == '$')
//        {
//            double oprd1 = pop(&s1);
//            double oprd2 = pop(&s1);
//            double result = operate(oprd2, oprd1, token);
//            push(&s1, result);
//        }
//        
//        else{
//            printf("Invalid symbol.\n");
//            exit(0);
//        }
//        
//        
//        i++;
//    }
//    return pop(&s1);
//}
//
//int main(int argc, char** argv) {
//    char postfix[SIZE];
//    printf("Enter postfix expression: ");
//    scanf("%s", postfix);
//    
//    double result = evalPostfix(postfix);
//    printf("%lf\n", result);
//    return 0;
//}










//Infix to postfix assignment
typedef struct{
    char opStack[SIZE];
    int top;
}OperatorStack;

char stackTop(OperatorStack *);
void init(OperatorStack *, int);
void push(OperatorStack *, char);
void deallocate(OperatorStack *);  
char pop(OperatorStack *);
int isEmpty(OperatorStack *);
int prcd(char ,char);
void printPostfix(char[], char[]);

int isEmpty(OperatorStack *sp){
    return sp->top == -1;
}

char stackTop(OperatorStack *sp)
{
    return sp->opStack[sp->top];
}
 
void deallocate(OperatorStack *sp)
{
    free(sp);
    sp->top = -1;
}
void push(OperatorStack *sp, char value){
    if(sp->top == SIZE - 1){
        printf("Stack Overflow.");
        exit(1);
    }
    
    sp->top++;
    sp->opStack[sp->top] = value;
    
}

char pop(OperatorStack *sp){
    if(isEmpty(sp))
    {
        printf("Stack Underflow.");
        return '\0';
    }
    
    return sp->opStack[sp->top--];
}

int prcd (char left, char right)
{
    if(left == '(' || right == '(')
    {
        return 0;
    }
    
    if(right == ')'){
        return 1;
    }
    
    if(left == '*' || left =='/'){
        if(right== '*' || right == '/' || right == '+' || right =='-'){
            return 1;
        }
        else 
            return 0;
    }
    
    if(left == '+' || left =='-')
    {
        if(right == '+' || right == '-')
        {
            return 1;
        }
        else 
            return 0;
    }
    
    if(left == '$')
        return 1;
        
    else 
        return 0;
    
}

void printPostfix(char infix[], char postFix[]){
    OperatorStack s1;
    s1.top= -1;
    int i = 0, j=0, k = 0;
    char topOperator;
    
    
    while(infix[i] != '\0')
    {
        char token = infix[i];
        if(token >= '0' || token >='9'){
            postFix[j] = infix[i];
            j++;
            i++;
        }
        else if(token == '(' || token == ')' || token == '+' || token == '-' || token == '*' || token == '/' || token == '$'){
           while(!isEmpty(&s1) && prcd(stackTop(&s1), token)) {
               topOperator = pop(&s1);
               postFix[j] = topOperator;
               j++;
               
           }
           
           if(token == ')')
           {
               pop(&s1);
           }
           else{
               push(&s1, token);
               
           }
           i++;
           
        }
    }
    
    while(!isEmpty(&s1)){
        topOperator = pop(&s1);
        postFix[j] = topOperator;
        j++;
    }
    
    printf("Postfix:\n");
    while(postFix[k] != '\0')
    {
        printf("%c", postFix[k]);
        k++;
    }
    
}

int main()
{   
    
    char inFix[SIZE];
    char postFix[SIZE] = {'\0'};
    printf("Enter the infix notation of your equation: ");
    scanf("%s", inFix);
    printf("Infix:\n");
    int i = 0;
    while(inFix[i] != '\0')
    {
        printf("%c", inFix[i]);
        i++;
    }
    printf("\n");
    
    printPostfix(inFix, postFix);
   
  
    
    return 0;
}


/*
 WHILE NOT END OF INFIX STRING:
 *  token = GET THE NEXT ELEMENT FROM INFIX STRING
 * IF TOKEN IS AN OPERAND 
 *  APPEND TO POSTFIX STRING
 * ELSE IF TOKEN IS AN OPERATOR
 *   WHILE NOT EMPTY OPERATORSTACK AND PRCD(STACKTOP, TOKEN):
 *     IF TOP_OPERATOR = POP(OPERATORSTACK)
 *     APPEND TOP_OPERATOR WITH POSTFIX STRING
 *   END WHILE
 * IF TOKEN = ')' THEN
 *    POP(OPERATORSTACK)
 * ELSE 
 *    PUSH(OPERATORSTACK, TOKEN)
 * END IF
 * 
 * END IF
 * 
 * END WHILE
 * 
 * WHILE NOT EMPTY OPERATORSTACK:
 *   TOP_OPERATOR = POP(OPERATORSTACK)
 *   APPEND TOP_OPERATOR WITH THE POSTFIX STRING
 * END WHILE
 * 
 * PRINT POSTFIX.
 */
