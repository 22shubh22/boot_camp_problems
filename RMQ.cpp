#include<iostream>
#include<vector>
#include<math.h>

int value;

int con_Tree(long int [],long int [],int, int,int);
int con_Treemx(long int [],long int [],int, int,int);

using namespace std;

int  con_Tree(long int Input[],long int segTree[],int low ,int high ,int pos)
{
    if(low==high){
        segTree [pos] =Input[low];
        return 0;       //where does it.
    }

    int mid=(low+high)/2;

    con_Tree(Input,segTree,low,mid,2*pos +1);
    con_Tree(Input,segTree,mid+1,high,2*pos +2);

    segTree[pos]=min(segTree[2*pos +1],segTree[2*pos + 2]);

    return segTree[0];
}

int  con_Treemx(long int Input[],long int segTreemx[],int low ,int high ,int pos)
{
    if(low==high){
        segTreemx [pos] = Input[low];
        return 0;       //where does it.
    }

    int mid=(low+high)/2;

    con_Tree(Input,segTreemx,low,mid,2*pos +1);
    con_Tree(Input,segTreemx,mid+1,high,2*pos +2);

    segTreemx[pos]=max(segTreemx[2*pos +1],segTreemx[2*pos + 2]);

    return segTreemx[0];
}

int main(){

int n,q;
cin >> n >> q;

long int Input[n];
for(int i=0;i<n;i++){
    cin >> Input[i];
}

int sr=sqrt(n);

long int segTree[sr];
long int segTreemx[sr];

for(int i=0;i<n;i++){

    //segTreemx[i]=-100000000;
}

//make segment tree

int c=0;
long int s[sr];
long int smx[sr];

for(int i=0;i+sr<=n;i+=sr){

    s[c]=con_Tree(Input,segTree,i,i+sr-1 , 0);
    smx[c]=con_Treemx(Input,segTreemx,i,i+sr-1,0);

   cout << "Head of segment tree ; min:" << s[c] <<"  max:" << smx[c] << endl;
c++;
}

while(q>=1){

int l,r;
cin >> l >> r;

long int mn=100000000;
long int mx=-100000000;


int flag=5;


for(int i=l;i<=r;i%sr==0 && i+sr-1<=r  ? i+=sr : i++){

        if(i%sr==0 && i+sr-1<=r){
            int qut=i/sr;
            mn=min(mn,s[qut]);
            mx=max(mx,smx[qut]);
            flag=1;
        }
        else{
            mn=min(mn,Input[i]);
            mx=max(mx,Input[i]);
            flag=0;
        }

        cout <<flag<< " " << mn <<" " <<  mx << endl;
}

cout <<"min value is " << mn << endl;
cout <<"max value is " << mx;

q--;
}





}
