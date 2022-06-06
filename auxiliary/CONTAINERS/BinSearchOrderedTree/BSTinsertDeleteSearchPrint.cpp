/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTinsertDeleteSearch.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:16:07 by areggie           #+#    #+#             */
/*   Updated: 2022/05/26 19:37:41 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	It is useful to understand BINARY SEARCH TREE before making RED BLACK TREE

	Binary Search Tree is an ordered tree 
	So the algorithm works for ordered trees

	READ THIS BEFORE making!!! 
	General info: https://www.freecodecamp.org/news/binary-search-trees-bst-explained-with-examples/

	

	BST visualizer
		https://visualgo.net/en/bst?slide=5


	For practice problems and more, visit: http://www.mycodeschool.com 



	IMPLEMENTATION OF BINARY SEARCH TREE
	
	A very good explanation of INSERT elem in BST (ordered tree)
	https://www.youtube.com/watch?v=COZK7NATh4k

	A very good explanation of DELETE elem in BST (ordered tree)
	https://www.youtube.com/watch?v=gcULXE7ViZw&t=14s


	https://gist.github.com/mycodeschool/9465a188248b624afdbf
	The code has INSERT and DELETE methods together

	When deleting we have 3 cases:

	case 1 : leaf (just delete it)

	case 2: one child (delete and attach NULL)

	case 3: two nodes (delete,find min on the right and put in place of deleted OR 
	find max on the left and put in place of deleted )


*/

/* Deleting a node from Binary search tree */
#include<iostream>

using namespace std;

struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

/**************DELETING_ELEMENT************************/

//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 

/**********************ONE of TRAVERSAL FUNCTIONS****************************/ 
//Function to visit nodes in Inorder

void Inorder(Node *root) 
{
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 


 
/************ Function to Insert Node in a Binary Search Tree***********/
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

/***************************print function added with graphics *************/


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
	printf("%d\n", root->data);

	// Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
// Pass initial space count as 0
print2DUtil(root, 0);
}



/***************SEARCH FUNCTION******************/
Node *search(Node *root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->data == key)
		return root;
	else 
		return root; // if not found return the old value
	
	// Key is greater than root's key
	if (root->data < key)
		return search(root->right, key);

	// Key is smaller than root's key
	if (root->data > key)
		return search(root->left, key);
	

}


int main() 
{
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); // methof insert keeps the order of BST 
	root = Insert(root,10);
	root = Insert(root,3);
	root = Insert(root,4); 
	root = Insert(root,1);
	root = Insert(root,11);

	Node* found =search(root, 8);
	printf("Searched and found the element, which is: \n");
	if (found == root)
		cout << "Not found" << endl;
	else
		cout << found->data << endl;

	/**I added printing the BST, it prints from left to right**/
	printf("printing before deletion and after insertion");
	print2D(root); 

	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	cout << "printing after deletion 5" << endl;
	print2D(root);

	//Print Nodes in Inorder Traversal
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}