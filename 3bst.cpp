#include<iostream>
using namespace std;

class node 
{
public:
    int data;
    node *left;
    node *right;
};

class tree 
{
public:
    node *root = NULL;

    node* create(int key) 
    {
        node* newNode = new node;
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void insert(int key, node *root) 
    {
        if (key < root->data) 
        {
            if (root->left == NULL) 
            {
                root->left = create(key);
            }
            else 
            {
                insert(key, root->left);
            }
        }
        else if (key > root->data) 
        {
            if (root->right == NULL) 
            {
                root->right = create(key);
            }
            else 
            {
                insert(key, root->right);
            }
        }
        else 
        {
            cout << "Duplicate entries not allowed\n";
        }
    }

    void search(int key, node *root) 
    {
        if (root == NULL) 
        {
            cout << "Search not found\n";
            return;
        }
        if (key == root->data) 
        {
            cout << "Search found\n";
            return;
        }
        if (key < root->data) 
        {
            search(key, root->left);
        }
        else 
        {
            search(key, root->right);
        }
    }

    void inorder(node *root) 
    {
        if (root != NULL) 
        {
            inorder(root->left);
            cout << root->data << "\n";
            inorder(root->right);
        }
    }

    void preorder(node *root) 
    {
        if (root != NULL) 
        {
            cout << root->data << "\n";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(node *root) 
    {
        if (root != NULL) 
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << "\n";
        }
    }
    void min(node *root)
    {
    	while(root->left!=NULL)
    	{
    		root=root->left;
    	}
    	cout<<"Min value: "<<root->data;
    }
    void swap(node *root)
    {
    	if(root==NULL)
    	return;
    	
    	node *temp;
    	temp=root->left;
    	root->left=root->right;
    	root->right=temp;
    	swap(root->left);
    	swap(root->right);
    }
    int longest(node *root)
    {
    	if(root==NULL)
    	return 0;
    	
    	int left=longest(root->left);
    	int right=longest(root->right);
    	if(left>right)
    	{
    		return (left+1);
    	}
    	else
    	{
    		return (right+1);
    	}
    }
    	
    	
};

int main() 
{
    tree t;
    int ch;
    int key;
    int search;
    do 
    {
        cout << "\n1.Insert\n";
        cout << "2.Search\n";
        cout << "3.Inorder\n";
        cout << "4.Preorder\n";
        cout << "5.Postorder\n";
        cout << "6.Minimum node\n";
        cout << "7.Swap node\n";
        cout << "8.Longest path\n";
        cout << "9.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter node to add in Binary Search Tree: ";
            cin >> key;
            if (t.root == NULL) {
                t.root = t.create(key);
            }
            else {
                t.insert(key, t.root);
            }
            break;
        case 2:
            cout << "Enter node to be searched: ";
            cin >> search;
            t.search(search, t.root);
            break;
        case 3:
            t.inorder(t.root);
            break;
        case 4:
            t.preorder(t.root);
            break;
        case 5:
            t.postorder(t.root);
            break;
        case 6:
        	t.min(t.root);
        	break;
        case 7:
        	t.swap(t.root);
        	break;
        case 8:
        	cout<<"Number of nodes in longest path is: "<<t.longest(t.root);
        	break;
        case 9:
            exit(0);
            break;
        }
    } 
    while (ch != 9);
    return 0;
}

