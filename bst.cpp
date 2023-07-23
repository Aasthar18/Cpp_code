#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
       int data;
       node *right;
       node *left;
       node(int d)
       {
              this->data = d;
              this->left = NULL;
              this->right = NULL;
       }
};


void levelOrderTraversal(node* root)
{
       queue<node*> q;
       q.push(root);
       q.push(NULL);  //separator

       while(!q.empty()){
              node* temp =q.front();
              q.pop();
              if(temp==NULL){
                     cout<<endl;
                     if(!q.empty())
                        q.push(NULL);
              }
              else{
                     cout<<temp->data<<" ";
                     if(temp->left){
                            q.push(temp->left);
                     }
                     if (temp->right)
                     {
                            q.push(temp->right );
                     }
              }
       }
}
node *insertData(node *&root, int d)
{
       // base case
       if (root == NULL)
       {
              root = new node(d);
              return root;
       }

       if (d > root->data)
       {
              // right subtree
              root->right = insertData(root->right, d);
       }

       else
       {
              // left subtree
              root->left = insertData(root->left, d);
       }
       return root;
}

void getData(node *&root)
{
       int data;
       cin >> data;
       while (data != -1)
       {
              insertData(root, data);
              cin >> data;
       }
}

void inorder(node* root){
       //base case
       if(root==NULL)
          return;

       // L Root R   
       inorder(root->left);
       cout<<root->data<<" ";
       inorder(root->right);
}
void postorder(node* root){
       // base case
       if (root == NULL)
          return;
       // L R Root
       postorder(root->left);
       postorder(root->right);
       cout << root->data << " ";
}
void preorder(node* root){
       // base case
       if (root == NULL)
          return;
       //Root L R
       cout << root->data << " ";
       preorder(root->left);
       preorder(root->right);
}
node *minValue(node *root)
{
       node *temp = root;
       while (temp != NULL)
       {
          temp = temp->left;
       }
       return temp;
}

node* deletion(node* root,int val)
{
    if(root==NULL)
      return root;
    if(root->data==val)
    {
       //0 child
       if(root->left==NULL && root->right==NULL)
       {
              delete root;
              return NULL;
       }
       //1 child
       if (root->left != NULL && root->right == NULL)
       {
              node *temp=root->left;
              delete root;
              return temp;
       }
       if (root->left == NULL && root->right != NULL)
       {
              node *temp = root->right;
              delete root;
              return temp;
       }
       //2 children
       if (root->left != NULL && root->right != NULL)
       {
              int min=minValue(root->right)->data;  //inorder successor
              root->data=min;
              root->right=deletion(root->right,min);
              return root;
       
       }
    }
    else if(root->data>val){
       root->left=deletion(root->left,val);
       return root;
    }
    else{
       root->right =deletion(root->right,val);
       return root;
    } 
}


bool search(node *&root, int x)
{
       // base case
       if (root == NULL)
          return false;

       if(root->data==x)
            return true;

       if (root->data>x)
       {
          //  might be in left subtree
            return search(root->left, x);
       }

       else
       {
          //  might be in right subtree
            return search(root->right, x);
       }
}


int main()
{
       node *root = NULL;
       getData(root);
       inorder(root);
       preorder(root);
       postorder(root);
       cout<<search(root,10);
       deletion(root,10);
       levelOrderTraversal(root);
}