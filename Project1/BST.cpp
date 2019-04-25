#include "BST.h"

//default constructor
template<typename T>
BST<T>::BST()
{
	root = NULL;
}

//destructor
template<typename T>
BST<T>::~BST()
{
	destroyTree(root);
}

//destroyTree
template<typename T>
void  BST<T>::destroyTree()
{
	destroyTree(root);
}

//destroy
template<typename T>
void  BST<T>::destroyTree(Node<T>* &p)
{
	if (p != NULL)
	{
		destroyTree(p->llink);
		destroyTree(p->rlink);
		delete p;
		p = NULL;
	}
}

//inorderTraversal
template<typename T>
void BST<T>::inorderTraversal() const
{
	if (root == NULL)
		cerr << "There is no tree.";
	else
	{
		inorderTraversal(root);
	}
}

//totalNodes
template<typename T>
int BST<T>::totalNodes() const
{
	if (root == NULL)
		return 0;
	else
		return totalNodes(root);
}

/***************************************************************

Implement your functions below this line.

***************************************************************/

// Definition function insert
// Your code here...
template<typename T>
void BST<T>::insert(const T& insertItem)
{
	Node<T> * newNode = new Node<T>;
	newNode->data = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (root == NULL)
		root = newNode;
	else
	{
		if (root->data == insertItem)
			cerr << "The item to insert is already in the list - " <<
			"duplicates are not allowed." << endl;
		else if (root->data > insertItem && root->llink == NULL)
			root->llink = newNode;
		else if (root->data < insertItem && root->rlink == NULL)
			root->rlink = newNode;
		else if (root->data > insertItem)
		{
			Node<T> * parent = root;
			root = root->llink;
			insert(insertItem);
			root = parent;
			parent = NULL;
		}
		else
		{
			Node<T> * parent = root;
			root = root->rlink;
			insert(insertItem);
			root = parent;
			parent = NULL;
		}
	}
}

// Definition function inorderTraversal(Node*)
// Your code here...
template<typename T>
void BST<T>::inorderTraversal(Node<T> * nextRoot) const
{
	if (nextRoot == NULL)
		cerr << "There is no tree." << endl;
	else
	{
		inorderTraversal(nextRoot->llink);
		cout << nextRoot->data << " ";
		inorderTraversal(nextRoot->rlink);
	}
}

// Definition function treeHeight()
// Your code here...
template<typename T>
int BST<T>::treeHeight() const
{
	if (root == NULL)
		return -1;
	else
		return treeHeight(root);
}

// Definition function treeHeight(Node*)
// Your code here...
template<typename T>
int BST<T>::treeHeight(Node<T> * nextRoot) const
{
	if (nextRoot == NULL)
		return -1;
	else
	{
		int leftHeight = treeHeight(nextRoot->llink);
		int rightHeight = treeHeight(nextRoot->rlink);

		int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;

		return max + 1;
	}
}

// Definition totalNodes(Node*)
// Your code here...
template<typename T>
int BST<T>::totalNodes(Node<T> * nextRoot) const
{
	if (nextRoot == NULL)
		return 0;
	else
		return 1 + totalNodes(nextRoot->llink) + totalNodes(nextRoot->rlink);
}
