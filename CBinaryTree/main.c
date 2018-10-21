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
#include <stdbool.h>

/*
 * Binary tree implementation 
 * from **cslibrary.stanford.edu/110/BinaryTrees,html#csoln**
 */

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
    
}Node;

//recursively look up the target node
static int lookup(Node* node, int target){
    //base case: empty tree
    if(node == NULL){
        return(false);
    }
    else{
        //if found, return true or 1;
        if(target == node->data)
            return 1;
        else{
            //traverse left side if out target is smaller than the current node leaf
            if(target < node->data){//recursive
                return lookup(node->left, target);
            }
            else//else search right side if larger
                return lookup(node->right, target);
        }
    }
}

struct Node *newNode(int data){
  struct Node *node = malloc(sizeof(struct Node)); 
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return node;
}

struct Node *insert(struct Node *node, int data){
    //if tree is empty, return a new single node
    if(node == NULL){
        return(newNode(data));
    }
    else{
        //otherwise recur down the tree;
        if(data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        
        return node;
    }
    
}

struct Node *build123(){
//    //using 3 pointer variables
//    struct Node *root = newNode(2);
//    struct Node *left = newNode(1);
//    struct Node *right = newNode(3);
//    root->left = left;
//    root->right = right;
//    return root;
//    //using one pointer variable
//    struct Node *root = newNode(2);
//    root->left = newNode(1);
//    root->right = newNode(3);
//    return root;
    //using insert 3 times
    struct Node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    
    return root;
}

int size(struct Node *node){
    
    if(node == NULL){
        return 0;
    }
    else{
        return size(node->left) + 1 + size(node->right);
    }
}


int maxDepth(struct Node *node){
    
}

int main(int argc, char** argv) {

    struct Node *tree = build123();
    
    
    return (EXIT_SUCCESS);
}

