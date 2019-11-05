#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
bool findElement(Node* root,int value)
{
    if(root==NULL) return false;            // FOR EMPTY TREE...
    if(root->data == value)
        return true;
    else if(root->data < value)
       return findElement(root->right,value);
    else if(root->data > value)
       return findElement(root->left,value);
}
void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    int l=0;
    while(!q.empty())
    {
        Node* current = q.front();
        cout << current->data << " ";
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL) q.push(current->right);
        q.pop();
    }
}
void mirror(Node* root)
{
    if(root==NULL)
        return;
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
}
int countLeaves(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left)+countLeaves(root->right);
}
int countNonLeaves(Node* root,int *countnonleaves)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right == NULL)
        return 0;
    else
        (*countnonleaves)++;
    countNonLeaves(root->left,countnonleaves);
    countNonLeaves(root->right,countnonleaves);
}
int max(int a,int b)
{
    return a>b?a:b;
}
int height(Node* root)
{
    if(root==NULL)
        return -1;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight,rHeight)+1;
}
Node* getNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* findMinNode(Node* root)
{
    Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
Node* deleteNode(Node* root,int data)
{
    if(root==NULL) return NULL;
    if(root->data < data)
        root->right=deleteNode(root->right,data);
    else if(root->data > data)
        root->left=deleteNode(root->left,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            Node* temp=findMinNode(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,root->data);
        }
    }
    return root;
    
}
Node* insertNode(Node* root,int data)
{
    if(root==NULL)
    {
         root = getNewNode(data);
        return root;
    }
    else if(root->data >= data )
        root->left = insertNode(root->left,data);
    else
        root->right = insertNode(root->right,data);
    return root;
}
void preOrder(Node* root)
{
    if(root==NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data <<" ";
}
void inOrder(Node* root)
{

    if(root==NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    cout << "Enter the root node: ";
    int value;
    cin >> value;
    Node* root = NULL;
    root = insertNode(root,value);
    char ch;
    bool b;
    int opt;
    do{
        cout << "Enter the element you want to insert: ";
        cin >> value;
        insertNode(root,value);
        cout << "Enter y to insert more and n for exit: ";
        cin >> ch;
    }while(ch=='y');
    do{
        cout << "Choose an option" << endl;
        cout << "1.Preorder" << endl;
        cout << "2.Postorder" << endl;
        cout << "3.Inorder" << endl;
        cout << "4.Level order traversal" << endl;
        cout << "5.Height of the tree" << endl;
        cout << "6.Search a node" << endl;
        cout << "7.Create a mirror image" << endl;
        cout << "8.Delete a node" << endl;
        cout << "9.Count non-leaf nodes" << endl;
        cout << "10.Count leaf nodes" << endl;
        cin >> opt;
        switch(opt)
        {
            case 1: preOrder(root);
                    break;
            case 2: postOrder(root);
                    break;
            case 3: inOrder(root);
                    break;
            case 4: levelOrder(root);
                    break;
            case 5: value = height(root);
                    cout << "Height of the tree is: " << value << endl;
                    break;
            case 6: cout << "Enter the node you want to search: ";
                    cin >> value;
                    b=findElement(root,value);
                    if(b) cout << "Node found" <<endl;
                    else cout << "Node not found" << endl;
                    break;
            case 7: mirror(root);
                    inOrder(root);
                    break;
            case 8: cout <<"Enter the node you want to delete: ";
                    cin >> value;
                    deleteNode(root,value);
                    inOrder(root);
                    break;
            case 9: {
                    value=0;
                    countNonLeaves(root,&value);
                    cout << "Number of non-leaf nodes are: "<< value << endl;
                    break;
                    }
            case 10: cout << "Number of leaf nodes are: " << countLeaves(root) << endl;
                    break;
            default: cout << "Invalid option" << endl;

        }
        cout << "Enter y for again n for exit: ";
        cin >> ch;
    }while(ch=='y');
    return 0;
}
