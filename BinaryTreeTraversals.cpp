#include<iostream>
#include<bits/stdc++.h>

 using namespace std;
 
 struct node{
 	int data;
 	struct node *left;
 	struct node *right;
 };
 
 struct node* insert_node(int new_data){
 	struct node* temp = (struct node*)malloc(sizeof(struct node));
 	
 	temp->data = new_data;
 	temp->left = NULL;
 	temp->right = NULL;
 	
 	return temp;
 }
 
 void printInOrder(struct node* node){
 	if(node==NULL){
 		return;
	 }
	 
	 printInOrder(node->left);
	 printf("%d ",node->data);
	 printInOrder(node->right);
	 
 }
 
 void postOrder(struct node* node){
 	if(node==NULL){
 		return;
	 }
	 
	 postOrder(node->left);
	 postOrder(node->right);
	 printf("%d ",node->data);
	 
 }
 
 void preOrder(struct node* node){
 	if(node==NULL){
 		return;
	 }
	 
	 printf("%d ",node->data);
	 preOrder(node->left);
	 preOrder(node->right);
	 
 }
 
 int main(){
 	
 	struct node* root = insert_node(1);
 	
 	root->left = insert_node(2);
 	root->right = insert_node(3);
 	root->left->left = insert_node(4);
 	root->right->left = insert_node(5);
 	
 	printInOrder(root);
 	printf("\n");
 	postOrder(root);
 	printf("\n");
 	preOrder(root);
 	
 	getchar();
 return 0;
 }

