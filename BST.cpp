#include <iostream>

using namespace std;

// node
class node {
public:
    int data;
    node* left;
    node* right;
    node( int num )
    {
        data = num;
        left = NULL;
        right = NULL;
    }
};

node* root = NULL;

// insert a node BST
void insert( int data )
{
    node* newNode = new node(data);
    
    if( root == NULL )
    {
        root = newNode;
        return;
    }
    
    node* current = root;
    node* parent = NULL;
    
    while( true )
    {
        parent = current;
        
        // go to left
        if( data < parent->data )
        {
            current = current->left;
        
            // insert to the left
            if( current == NULL )
            {
                parent->left = newNode;
                return;
            }
        }
        else // go to right
        {
            current = current->right;
            
            // insert to right
            if( current == NULL )
            {
                parent->right = newNode;
                return;
            }
        }
    } // end while
}

node* searchNode( int data )
{
    node* current = root;
    
    while( current != NULL )
    {
        if( data == current->data )
        {
            cout << data << " is found! " << endl;
            return current;
        }
        else if( data < current->data ) // go to left
        {
            current = current->left;
        }
        else // go to right
        {
            current = current->right;
        }
    } // end while
    
    cout << data << " is not found! " << endl;
    return NULL;
}

bool searchNode( int data, node* &target, node* &parent )
{
    node* current = root;
    
    while( current != NULL )
    {
        if( data == current->data )
        {
            target = current;
            cout << data << " is found! " << endl;
            return true;
        }
        else if( data < current->data ) // go to left
        {
            parent = current;
            current = current->left;
            
        }
        else // go to right
        {
            parent = current;
            current = current->right;
        }
        
    } // end while
    
    cout << data << " is not found! " << endl;
    return false;
}

node* getMinNode( node* root )
{
    node* current = root;
    
    while( current->left != NULL )
    {
        current = current->left;
    }
    
    return current;
}

bool deleteNode( int data )
{
    node* parent = NULL;
    node* target = NULL;
    
    if( searchNode( data, target, parent ) ) // if data exists, get this node and its parent node
    {
        if( parent != NULL )
        {
            cout<< "target = "<<target->data << ", parent = " << parent->data << endl;
        }
        else
        {
            cout << "target = "<<target->data;
        }
        
        if( target->left == NULL && target->right == NULL ) // removed node is a leaf node
        {
            if( parent->left != NULL && parent->left->data == target->data )
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
            cout << "delete a leaf node: " << data << endl;
        }
        else if( target->left == NULL && target->right != NULL ) // removed node has one child
        {
            if( parent->left != NULL && parent->left->data == target->data )
            {
                parent->left = target->right;
            }
            else
            {
                parent->right = target->right;
            }
            cout << "delete a node which has a child: " << data << endl;
        }
        else if( target->left != NULL && target->right == NULL ) // removed node has one child
        {
            if( parent->left != NULL && parent->left->data == target->data )
            {
                parent->left = target->left;
            }
            else
            {
                parent->right = target->left;
            }
            cout << "delete a node which has a child: " << data << endl;
        }
        else // removed node has 2 children
        {
            node* minNode = getMinNode( target->right );
            cout << "get min node:" << minNode->data << endl;
            // find a minumum value in the right subtree
            deleteNode( minNode->data ); // delete the min node of subtree first
            target->data = minNode->data; // then copy the value to original location
            cout << "delete a node which has two children: " << data << endl;
        }
        return true;
    }
    return false;
}

void inorder( node* root )
{
    if( root != NULL )
    {
        inorder( root->left );
        cout << root->data <<" ";
        inorder( root->right );
    }
}

void preorder( node* root )
{
    if( root != NULL )
    {
        cout << root->data <<" ";
        preorder( root->left );
        preorder( root->right );
    }
}

void postorder( node* root )
{
    if( root != NULL )
    {
        postorder( root->left );
        postorder( root->right );
        cout << root->data <<" ";
    }
}

int main()
{
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
    
    for( int i = 0; i < 7; i++ )
    {
        insert( array[i]) ;
    }
    
    cout<<"inorder:";
    inorder( root ); // inorder:10 14 19 27 31 35 42
    
    cout<<"\npreorder:";
    preorder( root ); // preorder:27 14 10 19 35 31 42
    
    cout<<"\npostorder:";
    postorder( root ); // postorder:10 19 14 31 42 35 27
    cout<<endl;
    
    searchNode(12);
    searchNode(19);
    
    // delete a node
    deleteNode(14);
    
    cout<<"inorder:";
    inorder( root ); // inorder:10 14 27 31 35 42
    cout<<endl;
    
    cout<<"\npreorder:";
    preorder( root ); // preorder:27 19 10 35 31 42
    
    cout<<"\npostorder:";
    postorder( root ); // postorder:10 19 31 42 35 27
    cout<<endl;
    
    return 1;
}

