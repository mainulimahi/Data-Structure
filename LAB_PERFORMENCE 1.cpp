//two way linked list

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node * root = NULL;

//Defining a function to add a node after a previous node
int insertData(int num){
    //create node
    node *nn=new node;
    nn->data=num;
    nn->left= NULL;
    nn->right=NULL;

    if(root == NULL){
        root=nn;
    }else{
        node *child=root,*parent;
        while(child!=NULL){
            parent=child;
            if(child->data < num)child=child->right;
            else if(child->data > num) child=child->left;
            else if(child->data == num){
                cout<<num<< " is a duplicate data!!!\n\n";
                return 0;
            }
        }
        if(parent->data < num)parent->right=nn;
        else parent->left=nn;
    }
    return 1;
}


void visit(node *parent){
    if(root == NULL)cout<<"Tree does not exist!\n\n";
    if(parent!=NULL){
        visit(parent->left);
        cout<<parent->data<< " ";
        visit(parent->right);
    }
}

void searchData(int num){
    node *ptr;
    ptr=root;
    if(root==NULL)
     cout<"Tree is empty\n";
    else {
     while(ptr!=NULL){
   if (ptr->data<num)ptr=ptr->right;
   else if(ptr->data>num)ptr=ptr->left;
   else if(ptr->data==num){
      cout<<"Data found\n";
      break;
   }
     }
     if (ptr==NULL)
        cout<<"Data not found\n";
    }//implement search function, return 0 if not found or 1 if found
}

int deleteData(int num){
    //implement delete function, return 1 if deleted or 0 if not found
    node* ptr=root,*temp,* last;
    int result=0;
   while(ptr!=NULL){
    if(num<ptr->data){
        last=ptr;
        ptr=ptr->left;
    }
    else if(num>ptr->data){
        last=ptr;
        ptr=ptr->right;
    }
    else if(num==ptr->data){
            //if num is leaf
        if(ptr->right==NULL && ptr->left==NULL){
            if(last->data<ptr->data)
                last->right=NULL;
            else last->left=NULL;
            delete(ptr);
            result=1;
            break;
        }
        //if num has one child
        if(ptr->right!=NULL && ptr->left==NULL){
            if(last->data<ptr->data)
                last->right=ptr->right;
            else last->left=ptr->right;

            result=1;
            break;
        }
        else if(ptr->left!=NULL && ptr->right==NULL){
            if(last->data<ptr->data)
                last->right=ptr->right;
            else last->left=ptr->right;

            break;
        }
        //if num has two children
        else if(ptr->left!=NULL && ptr->right!=NULL){
            temp=ptr;
            if(ptr=root)
            last=ptr;
            ptr=ptr->right;
            while(ptr->left!=NULL){
                last=ptr;
                ptr=ptr->left;

        }

        temp->data=ptr->data;
     //   last->left=NULL;


        result=1;
        break;


    }
   }
   }
   return result;
}


int main(){
    // Keeping some elements into an array
    int a[7]={9,11,4,3,7,15,1},x,result;
    for(int i=0;i<7;i++)insertData(a[i]);
    visit(root);
  cout<<"Enter data to search:\n";
   cin>>x;
    searchData(x);

    cout<<"Enter data to delete:\n";
   cin>>x;
   result=deleteData(x);
   if(result==0)
    cout<<"Data not in tree\n";
    if(result==1)
        cout<<"Data deleted\n";
    return 0;
}
