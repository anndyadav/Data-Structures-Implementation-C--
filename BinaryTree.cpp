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
 int main(){
 	
 	struct node* root = insert_node(1);
 	
 	root->left = insert_node(2);
 	root->right = insert_node(3);
 	root->left->left = insert_node(4);
 	
 	getchar();
 return 0;
 }

