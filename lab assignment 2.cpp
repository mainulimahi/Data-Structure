#include<iostream>
using namespace std;
void bubblesort(int s[],int n){
int i,j,z;
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(s[i]>s[j]){
z=s[i];
s[i]=s[j];
s[j]=z;}}}}

void selectsort(int s[],int n){
int small,i,j;
for(small=0;small<n-1;small++){
for(i=small+1;i<n;i++){
if(s[small]>s[i]){
j=s[small];
s[small]=s[i];
s[i]=j;}}}}

void insertsort(int s[],int n){
int i,j,temp;
for(i=1;i<n;i++){
j=i-1;
temp=s[i];
while( j>=0 && temp<s[j]){
s[j+1]=s[j];
j--;}
s[j+1]=temp;}}

int main(){
int n,choice;
cout<<"enter size of array\n";
cin>>n;
int a[n];
int i,j,z;

cout<<"Enter array elements\n";

for(i=0;i<n;i++){
cin>>a[i];
}
cout<<"Select sorting catagogy:\n1.Bubble Sort  2.Selection Sort  3.Insertion Sort\n";
cin>>choice;

if(choice==1)
    bubblesort(a,n);
else if(choice==2)
    selectsort(a,n);
else if(choice==3)
    insertsort(a,n);

else cout<<"Invalid entry\n";

cout<<"New array\n";
for(i=0;i<n;i++){
cout<<a[i]<<endl;
}
return 0;
}

