#include<iostream>
#include<cstring>
using namespace std;

class node 
{
public:
    char k[20];
    char m[20];
    node *left;
    node *right;
};

class dict
{
	public:
		    node *root = NULL;
		    
		    void create() 
    		    {
    		    	char ans;
    		    	do
    		    	{
        		node* newNode = new node;
        		
    		    	cout<<"Enter key: ";
    		    	cin>>newNode->k;
    		    	cout<<"Enter meaning: ";
    		    	cin>>newNode->m;
        		newNode->left = NULL;
        		newNode->right = NULL;
        		if(root==NULL)
        		{
        			root=newNode;
        		}
        		else
        		{
        			insert(root,newNode);
        		}
        		cout<<"Do you want to continue? ";
        		cin>>ans;
        		}
        		while(ans!='n');
        	   }
        	   void insert(node *root, node *temp)
        	   {
        	       if (strcmp(temp->k, root->k)<1)
        	       {
        	       	if(root->left==NULL)
        	       	{
        	       		root->left=temp;
        	       	}
        	       	else
        	       	{
        	       		insert(root->left, temp);
        	       	}
        	       }
        	       else if (strcmp(temp->k, root->k)>1)
        	       {
        	       	if(root->right==NULL)
        	       	{
        	       		root->right=temp;
        	       	}
        	       	else
        	       	{
        	       		insert(root->right, temp);
        	       	}
        	       }
        	        
        	       else
        	       {
        	       	cout<<"Duplicates entries not allowed!!!!!!!!";
        	       }
        	      }
        	      void display(node *root)
        	      {
        	          if (root != NULL) 
        	          {
                              display(root->left);
            		      cout << root->k <<" : "<<root->m << "\n";
            		      display(root->right);
        		  }
    			}
    			void min(node *root)
    			{
    				while(root->left!=NULL)
    				{
    					root=root->left;
    				}
    				cout<<"Min value: "<<root->k;
    			}
    			void search(node* root, char key[20])
			{
    				if (root == NULL)
    				{
        				cout << "Search not found";
    				}
    				else if (strcmp(root->k, key) == 0)
    				{
        				cout << "Key found: " << root->k << " : " << root->m;
    				}
    				else if (strcmp(root->k, key) < 0)
    				{
        				search(root->right, key);
    				}
    				else
    				{
        			search(root->left, key);
    				}
			}

     			node *deleteNode(node *root, char key[20])
    			{
    				node *temp;
        			if (root == NULL)
        			{
         				cout << "Key not found!";
            				return root;
        			}
        			if (strcmp(key, root->k) < 0)
        			{
            				root->left = deleteNode(root->left, key);
        			}
        			else if (strcmp(key, root->k) > 0)
        			{
            				root->right = deleteNode(root->right, key);
        			}
        			else
        			{
            				if (root->left == NULL)
            				{
                				node *temp = root->right;
                				delete root;
                				return temp;
            				}
            				else if (root->right == NULL)
           			 	{
                				node *temp = root->left;
                				delete root;
                				return temp;
            				}
            				node *temp = minValueNode(root->right);
            				strcpy(root->k, temp->k);
            				root->right = deleteNode(root->right, temp->k);
        			}
        			return root;
    			}
    			node *minValueNode(node *root)
    			{
        			while (root->left != NULL)
        			{
            				root = root->left;
        			}
        			return root;
    			}
			void update(node* root, char key[20], char newValue[20]) 
    			{
    				if (root == NULL) 
    				{
        				cout << "Key not found!";
        				return;
    				}
    				if (strcmp(root->k, key) == 0) 
    				{
        				strcpy(root->m, newValue);
        				cout << "Value updated successfully!";
    				} 
    				else if (strcmp(root->k, key) < 0) 
    				{
       				 	update(root->right, key, newValue);
    				} 
    				else 
    				{
      				  	update(root->left, key, newValue);
    				}
			}
};
int main()
{
	dict d;
	int ch;

    do 
    {
        cout << "\n1.Insert\n";
        cout << "2.Display\n";
        cout << "3.Minimum\n";
        cout << "4.Search\n";
        cout << "5.Delete\n";
        cout << "6.Update\n";
        cout << "7.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            d.create();
            break;
        case 2:
            d.display(d.root);
            break;
        case 3:
            d.min(d.root);
            break;
        case 4:
            char key[20];
            cout << "Enter key to search: ";
            cin >> key;
            d.search(d.root, key);
            break;
        case 5:
            char deleteKey[20];
    	    cout << "Enter key to delete: ";
    	    cin >> deleteKey;
    	    d.deleteNode(d.root, deleteKey);
    	    break;
    	case 6:
    	    char updateKey[20], updateValue[20];
    	    cout << "Enter key to update: ";
    	    cin >> updateKey;
    	    cout << "Enter new value: ";
    	    cin >> updateValue;
    	    d.update(d.root, updateKey, updateValue);
    	    break;

        case 7:
            exit(0);
            break;
        }
    } 
    while (ch != 7);
    return 0;
}
   		
  
