#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

void printPostorder(struct Node* node)
{
	if (node==NULL)
	  return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout<<node->data<<" ";
}

struct Node* newNode(int data)
{
	struct Node* node = new Node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int main()
{
	struct Node* root=newNode(22);
	root->left=newNode(14);
	root->right=newNode(35);
	root->left->left=newNode(10);
	root->left->right=newNode(19);
	root->right->left=newNode(31);
	root->right->right=newNode(42);
	cout<<"Postorder traversal of the binary tree is: \n";
	printPostorder(root);
	return 0;
}
