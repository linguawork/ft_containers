/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RonRBTpseudoCode.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:14:38 by areggie           #+#    #+#             */
/*   Updated: 2022/05/30 19:25:43 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	here I need to write the pseudo code for operations with black tree
	(following the video's of RON, looks tricky)

	Lecture 1 is intro to the strict rules of RBT.


	The time code is to the lecture 2.
		(You may copy-paste the time code below into the comment to the video, 
		the link is shown above)
		2:33 Example of Colorflip because we have two consecutive red elements(violation) and we have red aunt, after COLORFLIP we have to make the root black (3:25);
		3:58 We INSERT 6 and we have got 2 red elements(violation).
		4:17 Null is always black, and it is a black aunt of 6, so we need to ROTATE
		5:25 We have RL rotation in red zone. This is like in AVL tree motion (by Abdul Bari), instead of double rotation we make one simple.
		6:08 After rotation we need to fix (RESOLVE colors in parent-grandparent-aunt triangle) and get:
			B
		/     \
		R       R
		within the triangle (always working within one triangle).
		7:05 We INSERT 8 (adding is always red) and we have violation (two consecutive reds) and red aunt, so we COLORFLIP in the triangle of aunt, grandparent, parent. So we change colors into:
			R
		  /    \
		 B      B

		8:32 it is interesting that the children of the root can be black or red,  alternatively one of them can be red or black. 3 states: all black, all red, one of them red(meaning another is black). And that is ok. As we can see.
		8:56 = 4:17
		9:38 LL-rotation (we drag over nail the one above two consecutive elements down raising the two red up)
		10:47 After rotation we RESOLVE colors. We have three consecutive reds, so we need to make
		equal number of black nodes on the left and the right sides of the root to have the balance. (root is always black, then we can have red and then black)
		10:51 INSERT 10, it is red. Again violation, again ROTATE and FLIPCOLORS in parent - grandparent -aunt triangle.
		14:38 ROTATE two reds in LL-rotation (dragging), 5 is dragged over nail and will hang from 3. (Abdul Bari good note).
		15:04 RESOLVE colors (black root, red layer, black layer).
		15:53 checking validity of the tree ( counting black node on the left  and on the right from the root, they should be equal, which is a balanced tree.
		17:00 Valid RBT is not always valid AVL tree
		17:10 Conclusion. BOOLEANS for colors, 6 rules for REBALANCING the RBT	

*/		

/*
		Red Black Tree 3 - Classes
		https://www.youtube.com/watch?v=-qjrcxVmf2Q
		This is the pseudo-code for RBT (creating a class, interface and nested class)
*/
			
		class RedBlackInterface<K, V>;
			
		template <struct K, struct V>
		public class RedBlackTree<K, V> // Key, Value
		{
			private:
				Node<K, V> root; // inner class will hold K, V
				int size; // number of elements in our tree
		

			public:
			
			class Node <K, V> // for map container <int, int>
			{
				private:
					K key_;
					V value_
					Node<K, V> left, right, parent;// 3:56 everynode has three branches: LeftChild, RightChild, Parent
					/*
							parent
							|
							Node
						   /	\
						Left  	Right
					
					*/		
					// 4:10 root's parent is NULL, this will be the marker of the root
					// if Node == parent then it is root
 
					bool isBlack; // true - black, false - red; 2:08
					bool isLeftChild; // 3:01 one more boolean to determine which side is aunt
					//if parent's isLeftChild true, then aunt will be on the right and counterwise
				public:
				//constructor (initialize all values)
					Node(K key, V value) : key_(key), value_(value)	
					{
						left = NULL;
						right = NULL;
						parent = NULL;
						
						isBlack =false;// new nodes must be red
						//poor little node
						isLeftChild = false; // we dont know where is the node (left or right)
						
					}
			};
			
			public:
			void add
			
				
		};	
			

/*
		Red Black Tree 4 - Add methods
		https://www.youtube.com/watch?v=p8TSYkDz0eI
*/
/********Lecture 3 starts here********/
		class RedBlackInterface<K, V>;
		
	template <struct K, struct V>
	class RedBlackTree<K, V> // Key, Value
	{
		private:
			Node<K, V> root; // inner class will hold K, V
			int size; // number of elements in our tree
	
		public:
		class Node <K, V>
		{
			private:
				K key_;
				V value_
				Node<K, V> left, right, parent;// 3:56 everynode has three branches: LeftChild, RightChild, Parent
				/*
						parent
						|
						Node
						/	\
					Left  	Right
				
				*/		
				// 4:10 root's parent is NULL, this will be the marker of the root
				// if Node == parent then it is root

				bool isBlack; // true - black, false - red; 2:08
				bool isLeftChild; // 3:01 one more boolean to determine which side is aunt
				//if parent's isLeftChild true, then aunt will be on the right and counterwise
			public:
			//constructor (initialize all values)
				Node(K key, V value) : key_(key), value_(value)	
				{
					left = NULL;
					right = NULL;
					parent = NULL;
					
					isBlack =false;// new nodes must be red
					//poor little node
					isLeftChild = false; // we dont know where is the node (left or right)
					// it does not matter if it is true or false, it is new node, alone
				}
		};
		
		/********Lecture 4 starts here********/
		public:
		void add (K key, V value)
		{
			Node<K, V> node = new Node<K, V>(key, value); // create a new node
			if (root == NULL) // if this the first Node
			{
				root = Node;
				root.black = true; // the root is always black
				size++; 
			}
				
			//if this is not the first Node
			add(root, Node);
			size++;
			
		}
		
		private: // 2:55
		void add (Node<K, V> parent, Node<K, V> newNode) // here will be the parent of the node
		//which we are going to add
		// parent is the node to which we will attach newNode
		// here we need to compare newNode with the NODE where we are at
		//we will use friend class Comparable to compare the keys only 10:27
		{
			// this is the manipulation of the right hand side
			//if new node is bigger than the parent key (we add to the right)
			if(((Comparable <K>) newNode.key).compareTo(parent.key) > 0) // too complicated
			// if you manipulating the duplicates then set  >=  
			{
				// if there is a free place for the right node
				if(parent.right == null) 					 
				{
					//in the triangle we add the right node
					parent.right = NewNode // мы кладем в право
					//и саму ноду кладем parent
					NewNode.parent = parent // в новой ноде в родителя записали родителя
					//так как ушли направо значит это не правый ребенок
					NewNode.isLeftChild = false; // it is important to set it here
					return;
				}	
				//if the place for the right child is occupied
				return add (parent.right, NewNode)

				
			}
			// if there is a free place for the left node
			if(parent.left == null) 					 
			{
				//in the triangle we add the left node
				parent.left = NewNode // мы кладем в левого ребенка
				//и саму ноду кладем parent
				NewNode.parent = parent // в новой ноде в родителя записали родителя
				//так как ушли влево значит это левый ребенок
				NewNode.isLeftChild = true; // it is important to set it here
				return;
			}	
			//if the place for the left child is occupied
			return add (parent.right, NewNode)
		}
		//after inserting a new node, 8:50 now we need to check for violations
		//it will take the node we just added
		checkColor(newNode)	
	};	
		






/*
	Red Black Tree 5 checking violations in the tree
	https://www.youtube.com/watch?v=pJWAi6u7Nq4

*/
			
		class RedBlackInterface<K, V>;
			
		template <struct K, struct V>
		public class RedBlackTree<K, V> // Key, Value
		{
			private:
				Node<K, V> root; // inner class will hold K, V
				int size; // number of elements in our tree
		

			public:
			
			class Node <K, V> // for map container <int, int>
			{
				private:
					K key_;
					V value_
					Node<K, V> left, right, parent;// 3:56 everynode has three branches: LeftChild, RightChild, Parent
					/*
							parent
							|
							Node
						   /	\
						Left  	Right
					
					*/		
					// 4:10 root's parent is NULL, this will be the marker of the root
					// if Node == parent then it is root
 
					bool isBlack; // true - black, false - red; 2:08
					bool isLeftChild; // 3:01 one more boolean to determine which side is aunt
					//if parent's isLeftChild true, then aunt will be on the right and counterwise
				public:
				//constructor (initialize all values)
					Node(K key, V value) : key_(key), value_(value)	
					{
						left = NULL;
						right = NULL;
						parent = NULL;
						
						isBlack =false;// new nodes must be red
						//poor little node
						isLeftChild = false; // we dont know where is the node (left or right)
						
					}
			};
			
			public:
			void add
			
				
		};	
			

/***************Lecture 3 starts here********/
	class RedBlackInterface<K, V>;
		
	template <struct K, struct V>
	class RedBlackTree<K, V> // Key, Value
	{
		private:
			Node<K, V> root; // inner class will hold K, V
			int size; // number of elements in our tree
	
		public:
		class Node <K, V>
		{
			private:
				K key_;
				V value_
				Node<K, V> left, right, parent;// 3:56 everynode has three branches: LeftChild, RightChild, Parent
				/*
						parent
						|
						Node
						/	\
					Left  	Right
				
				*/		
				// 4:10 root's parent is NULL, this will be the marker of the root
				// if Node == parent then it is root

				bool isBlack; // true - black, false - red; 2:08
				bool isLeftChild; // 3:01 one more boolean to determine which side is aunt
				//if parent's isLeftChild true, then aunt will be on the right and counterwise
			public:
			//constructor (initialize all values)
				Node(K key, V value) : key_(key), value_(value)	
				{
					left = NULL;
					right = NULL;
					parent = NULL;
					
					isBlack =false;// new nodes must be red
					//poor little node
					isLeftChild = false; // we dont know where is the node (left or right)
					// it does not matter if it is true or false, it is new node, alone
				}
		};
		
		/********Lecture 4 starts here********/
		public:
		void add (K key, V value)
		{
			Node<K, V> node = new Node<K, V>(key, value); // create a new node
			if (root == NULL) // if this the first Node
			{
				root = Node;
				root.black = true; // the root is always black
				size++; 
			}
				
			//if this is not the first Node
			add(root, Node);
			size++;
			
		}
		
		private: // 2:55
		void add (Node<K, V> parent, Node<K, V> newNode) // here will be the parent of the node
		//which we are going to add
		// parent is the node to which we will attach newNode
		// here we need to compare newNode with the NODE where we are at
		//we will use friend class Comparable to compare the keys only 10:27
		{
			// this is the manipulation of the right hand side
			//if new node is bigger than the parent key (we add to the right)
			if(((Comparable <K>) newNode.key).compareTo(parent.key) > 0) // too complicated
			// if you manipulating the duplicates then set  >=  
			{
				// if there is a free place for the right node
				if(parent.right == null) 					 
				{
					//in the triangle we add the right node
					parent.right = NewNode // мы кладем в право
					//и саму ноду кладем parent
					NewNode.parent = parent // в новой ноде в родителя записали родителя
					//так как ушли направо значит это не правый ребенок
					NewNode.isLeftChild = false; // it is important to set it here
					return;
				}	
				//if the place for the right child is occupied
				return add (parent.right, NewNode)		
			}
			// if there is a free place for the left node
			if(parent.left == null) 					 
			{
				//in the triangle we add the left node
				parent.left = NewNode // мы кладем в левого ребенка
				//и саму ноду кладем parent
				NewNode.parent = parent // в новой ноде в родителя записали родителя
				//так как ушли влево значит это левый ребенок
				NewNode.isLeftChild = true; // it is important to set it here
				return;
			}	
			//if the place for the left child is occupied
			return add (parent.right, NewNode)
		}
		//after inserting a new node, 8:50 now we need to check for violations
		//it will take the node we just added
		// checkColor(newNode); // see below
		
		//https://www.youtube.com/watch?v=pJWAi6u7Nq4
		/****Lecture 5 starts here******************/

		void checkColor(Node<K, V> node)
		{
			if (node == root)
				return;
			//violation of two consecutive red nodes 5:30
			if(!node.black && !node.parent.black) 
			{
				//here will be the method to check aunt's color
				//and to check the number of black nodes
				correctTree(node);			
			}
			//checking color of the parent after corrections
			//this method will go up to the root node
			checkColor(node.parent)  
		}

		//6:59 
		void correctTree(Node<K, V> node)
		{
			//8:12punting the other method
			if (node.parent.isLeftChild) // meaning true
			//if parent is left child, then autn is the right child
			{
				//we dont know if the aunt is null or a node (2 possibilities)
				//so we foresee the possibility if it is null (which is blach)
				if(node.parent.parent.right == NULL ||
					node.parent.parent.right.isBlack) //if the node is black
					return rotate(node); // will be introduced in the 6th lesson
				//10:50 if the aunt is red we change color of grandparent and parent
				if(node.parent.parent.right != NULL)
					node.parent.parent.right.isBlack = false //if the node is red (Rob mistyped)
				{
					node.parent.parent.isBlack = false // сhange grandparent color to red	
					node.parent.isBlack = true; //parent's color should be black
					return;
				}
			}
			
			//underneath is the same code with left node	
						//8:12punting the other method
			if (node.parent.isLeftChild = false) // meaning parent is a Right Child
			//then aunt is the left child
			{
				//we dont know if the aunt is null or a node (2 possibilities)
				//so we foresee the possibility if it is null (which is blach)
				if(node.parent.parent.left == NULL ||
					node.parent.parent.left.isBlack) //if the node is black
					return rotate(node);
				//10:50 if the aunt is red we change color of grandparent and parent
				if(node.parent.parent.left != NULL)
					node.parent.parent.left.isBlack = false //if the node is red (Rob mistyped)
				{
					node.parent.parent.isBlack = false // сhange grandparent color to red	
					node.parent.isBlack = true; //parent's color should be black
					return;
				}
			}
			
		}

		//https://www.youtube.com/watch?v=IuG3WSaDumc
		/**************Here is the lecture 6*************/
		

		//4types of rotation: right, left, left -rgiht, right-left
		
		//here is right or right-left
		void rotate(Node<K,V> node)
		{
			if(node.isLeftChild)// if we are on the left node
			{
				//right-right
				if (node.parent.isLeftChild) // if parent is left
				{//we are left, parent is left so we right rotate or drag to the right
				//so grandparent has to move
					rightRotate(node.parent.parent)
				//after rotation we correct the colors
					node.isBlack = false
					node.parent.isBlack = true;
					if (node.parent.right != NULL)
						node.parent.right.isBlack = false;
						return;
				}
				
				rightLeftRotate(node.parent.parent);
				node.isBlack = true;
				node.rihgt.isBlack = false;
				node.left.isBlach = false;
				return;		
			}
			// here is the code to mirror when Node is Right Child
			if(node.isLeftChild =false)// if we are on the right node
			{
				//right-left
				if (node.parent.isLeftChild=false) // if parent is right child
				{//we are left, parent is child so we right-left(Abdul Bari) rotate or drag to the right and then jump over to the left
				//so grandparent has to move
					rightLeftRotate(node.parent.parent)
				//after rotation we correct the colors
					node.isBlack = true;
					node.rihgt.isBlack = false;
					node.left.isBlach = false;
					return;		
				}
				
			}

			//here is the lecture N7
			//https://www.youtube.com/watch?v=fpESZSHrsp0

			void leftRotate(Node <K, V> node)
			//we have a ptr tree to perform a drag to left, 1:30
			{
				Node<K,V> temp = node.right; // save the right node into temp (to be parent)
				node.right = temp.left // the freed node.right get temp.left
				if (node.right != null) // if the right child is not empty
				{
					node.right.parent = node; // we attach node to him as a parent
					node.right.isLeft =false; // mark as the right node with the boolean
				}
				//if we are the root node
				if (node.parent == NULL)
				{
						//we are at the root node, which has the global ptr;
						//the global root ptr should point to temp (which s)
						root = temp;
						temp = parent.null;
				}
				else
				{ //manipulate 2 ptr here to parent and to tmp
					(temp.parent = node.parent) //attach upper parent
					if(node.isLeftChild) // if the node is the left child of the parent
					{
						temp.isLeftChild = true;
						temp.parent.left = temp; // temp turns into left child 6:23
					
					}
					else // // if the node is the right child of the parent
					{
						temp.isLeftChild = false;
						temp.parent.right = temp;
					}
					
					temp.left = node;
					node.isLeft = true;
					node.parent = temp; // 7:37 - 12:12 (repetition)
				}	
					
					//the rest of the rotation we may write ourselves
					//more information is in Cormen book
			}
			

			

			
		}

			


			
	};	

	
	
	