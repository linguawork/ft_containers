/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTreeDelete2.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:44 by areggie           #+#    #+#             */
/*   Updated: 2022/05/26 16:56:47 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

C++ program to delete element in binary tree
source: https://www.geeksforgeeks.org/deletion-binary-tree/#:~:text=Given%20a%20binary%20tree%2C%20delete,replace%20with%20the%20last%20element.

*/


// #include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
	int key;
	struct Node *left, *right;
};

/* function to create a new node of tree and
return pointer */
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(struct Node* root,
				struct Node* d_node)
{
	queue<struct Node*> q;
	q.push(root);

	// Do level order traversal until last node
	struct Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->right) {
			if (temp->right == d_node) {
				temp->right = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == d_node) {
				temp->left = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->key == key)
			return NULL;
		else
			return root;
	}

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp;
	struct Node* key_node = NULL;

	// Do level order traversal to find deepest
	// node(temp) and node to be deleted (key_node)
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->key == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->key;
		deletDeepest(root, temp);
		key_node->key = x;
	}
	return root;
}


/***************************print function*************/


#define COUNT 10
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->key);

	// Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
// Pass initial space count as 0
print2DUtil(root, 0);
}



// Driver code
int main()
{
	// struct Node* root = newNode(10);
	// root->left = newNode(11);
	// root->left->left = newNode(7);
	// root->left->right = newNode(12);
	// root->right = newNode(9);
	// root->right->left = newNode(15);
	// root->right->right = newNode(8);

	// I ordered by hand but I am in doubt about the output
	struct Node* root = newNode(10);
	root->left = newNode(5);
	root->left->left = newNode(2);
	root->left->right = newNode(3);
	root->right = newNode(8);
	root->right->left = newNode(6);
	root->right->right = newNode(7);


	cout << "Inorder traversal before deletion : ";
	inorder(root);

	cout << "Printing tree in 2D  before deletion : ";
	print2D(root);

	int key = 5;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);
	cout << "Printing tree in 2D  after deletion : ";
	print2D(root);

	return 0;
}
