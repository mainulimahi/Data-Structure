#include<iostream>
using namespace std;

struct student{
int ID;
float cgpa;
student *left,*right;

};
student *root=NULL,*current;



void makenode(int id,float cg){


student *newnode=new student;
newnode->ID=id;
newnode->cgpa=cg;
newnode->left=NULL;
newnode->right=NULL;
if(root==NULL){
    root=newnode;
    current=newnode;

}
else{current=root;
while(current!=NULL){
        if(current->ID==id){
        cout<<"ID duplication\n";
        delete(newnode);
        break;
        }
      else  if(current->ID>id){
    if(current->left==NULL){
        current->left=newnode;
        break;
    }
    else current=current->left;
}
else if (current->ID<id){
    if(current->right==NULL){
        current->right=newnode;
        break;
    }
    else current=current->right;
}
}
}
}


int deleteID(int id){

    student *temp,* last;
    current=root;
    int result=0;
   while(current!=NULL){
    if(id<current->ID){
        last=current;
        current=current->left;
    }
    else if(id>current->ID){
        last=current;
        current=current->right;
    }
    else if(id==current->ID){
            //if id is leaf
        if(current->right==NULL && current->left==NULL){
            if(current==root){
                delete(current);
                root=NULL;
                result=1;
                break;
            }
           else if(last->ID<current->ID)
                last->right=NULL;
            else last->left=NULL;
            delete(current);
            result=1;
            break;
        }
        //if id has one child

        if(current->right!=NULL && current->left==NULL){
            if(current==root){

            current->ID=current->right->ID;
            current->cgpa=current->right->cgpa;
            current=current->right;
            delete(current);
            result=1;
            break;
        }
            else if(last->ID<current->ID)
                last->right=current->right;
            else last->left=current->right;
            delete(current);
            result=1;
            break;
        }
        else if(current->left!=NULL && current->right==NULL){
             if(current==root){

            current->ID=current->left->ID;
            current->cgpa=current->left->cgpa;
            current=current->left;
            delete(current);
            result=1;
            break;
        }

         else   if(last->ID<current->ID)
                last->right=current->left;
            else last->left=current->left;
            delete(current);
            result=1;
            break;
        }
        //if id has two children
        else if(current->left!=NULL && current->right!=NULL){
            temp=current;
            current=current->right;
            while(current->left!=NULL){

                current=current->left;

        }

        temp->ID=current->ID;
        temp->cgpa=current->cgpa;

        delete(current);

        result=1;
        break;


    }
   }
   }
   return result;
}


void listnode(student *current){
if(current!=NULL){
    listnode(current->left);
    cout<<current->ID<<" "<<current->cgpa<<endl;
    listnode(current->right);
    }


}
void searchid(int id){
current=root;
while(current!=NULL){
    if(current->ID==id){
       cout<<"Student ID: "<<id<<"\nStudent CGPA: "<<current->cgpa<<endl;
       break;
    }
    else if(current->ID>id){
        if(current->left==NULL)
        {
        cout<<"ID not found \n";
        break;
        }
        else current=current->left;
    }
    else if(current->ID<id){
        if(current->right==NULL){
            cout<<"ID not found\n";
            break;
        }
        else current=current->right;
    }
}
}



int main(){
int id,ch,x=1;
float cg;
while(x!=0){
cout<<"Enter choice:\n1.Delete ID\t2.Insert ID\t3.Search ID\n4.List ID\t5.Exit\n";
cin>>ch;
switch(ch){
case 1:{if(root==NULL){
        cout<<"Tree is empty\n";
    }
    else{cout<<"Enter id to delete:\n";
    cin>>id;

    deleteID(id);

     if(deleteID(id)==1){
        cout<<"ID deleted\n";
    }
    else if(deleteID(id)==0){
        cout<<"ID not in tree\n";
    }
    }break;
}
case 2:{cout<<"Enter id\n:";
        cin>>id;
        cout<<"Enter cgpa:\n";
         cin>>cg;
         makenode(id,cg);
         break;
}
case 3:{cout<<"Enter id\n:";
        cin>>id;
        searchid(id);
        break;}
case 4: {listnode(root);
break;}
case 5:x=0;

}

}
return 0;
}
