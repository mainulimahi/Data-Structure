//heap

#include<iostream>
using namespace std;

const int MAX_SIZE=100;
int Heap[MAX_SIZE+1], N=0;


void deletesort(){

int temp, curr=1,lc=Heap[2*curr],rc=Heap[2*curr+1],p=Heap[curr];//index
int    swaph=1;
while(swaph!=0){

       swaph=0;
if((p>lc)||(p>rc)){
        if(2*curr+1>N){
            temp=Heap[2*curr];
           Heap[2*curr]=Heap[curr];//lc=p
           Heap[curr]=temp;//p=lc
           curr=2*curr;//current=lc

          swaph=1;
        }

     else   if((lc<p)&&(lc<rc)){//lc is smallest
           temp=Heap[2*curr];
           Heap[2*curr]=Heap[curr];//lc=p
           Heap[curr]=temp;//p=lc
           curr=2*curr;//current=lc

          swaph=1;
        }
        else if((rc<p)&&(rc<lc)){//rc is smallest
            temp=Heap[2*curr+1];//temp=rc
            Heap[2*curr+1]=Heap[curr];//rc=p
            Heap[curr]=temp;//p=rc
            curr=2*curr+1;//current=rc

            swaph=1;
        }
 if(2*curr>N) break;

 lc=Heap[2*curr],rc=Heap[2*curr+1],p=Heap[curr];
}

}
}

void insertsort(){
int temp=N,swaph,child=Heap[temp],in=N/2,parent=Heap[in];

while(swaph!=0){
    swaph=0;
    if(temp>1){
        if(child<parent){

            Heap[in]=child;//parent=child
            Heap[temp]=parent;//child=parent
            swaph=1;
        }
        temp=in,child=Heap[temp],in=temp/2,parent=Heap[in];
    }
}


}
void Heapify(){
    int p=N/2,swapCount=0;
    while(p>=1){//repeat for each parent
        int curr=p,lc=curr*2, rc=lc+1, sm;



        while(lc<=N){//repeat till leaf nodes are reached
            if(rc>N)sm=lc;
            else sm=Heap[lc]<Heap[rc]?lc:rc;
            if(Heap[curr]>Heap[sm]){
                int tmp=Heap[curr];
                Heap[curr]=Heap[sm];
                Heap[sm]=tmp;
                swapCount++;
                curr=sm;
                lc=curr*2;
                rc=lc+1;
            }
            else break;
        }
        p--;
    }
    cout<<"Total Swap: "<<swapCount<<"\n\n";
}

int insertHeap(int data){
    //implement this function
    Heap[N+1]=data;
    N++;
    insertsort();
}
int deleteRoot(){
    //implement this function
    int temp;
    temp=Heap[1];
  Heap[1]=Heap[N];
  Heap[N]=temp;
  N--;
deletesort();

}

void sortHeap(){
    int tmp=N;
    for(int i=0;i<tmp; i++)deleteRoot();
    cout<<"Sorted List: ";
    for(int i=1;i<=tmp;i++)cout<<Heap[i]<<" ";
        cout<<"\n\n";
    N=tmp;
    Heapify();
}

void showHeap(){
    if(N>0){
       for(int i=1;i<=N;i++)cout<<Heap[i]<<" ";
        cout<<"\n\n";
    }
    else cout<<"Heap does not exist!\n\n";
}

int main(){
    //cout<<"Enter Number of elements? ";
    //cin>> N;
    //while(N<1 || N>100){
    //    cout<<"Enter a value less than 100\n\n";
    //    cin>> N;
    //}
    N=12;
    int a[13]={0,45,38,30,32,40,15,5,43,20,10,35,25};
    for(int i=1;i<=N;i++){
        //cout<<"Heap["<<i<<"]: ";
        //cin>>Heap[i];
        Heap[i]=a[i];
    }


    showHeap();
    Heapify();
    showHeap();

    while(1){
        int choice=-1;
        cout<<"0) Exit\n1) Insert\n2) Delete root\n3) sort \nEnter Option: ";
        cin>>choice;
        switch(choice){
        case 1:
            int value;
            cout<<"Enter a value to insert: ";
            cin>>value;
            insertHeap(value);
            showHeap();
            break;
        case 2:
            deleteRoot();
            showHeap();
            break;
        case 3:
            sortHeap();
            showHeap();
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
}

