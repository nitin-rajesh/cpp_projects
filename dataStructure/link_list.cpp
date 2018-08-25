#include<iostream>
using namespace std;

struct node{
    int num;
    char data;
    node*link;
};
void printList(node*head){
    node*tail=head;
    while(tail){
        cout<<tail->data;
        tail=tail->link;
    }
    cout<<endl;
}
node* createnode(node*tail){
      node *temp=new node;
      cout<<"Tail inside fn: "<<tail<<endl;
      cout<<"Temp: "<<temp<<'\t';
      //temp->data=value;
      temp->link=NULL;
      {	
        tail->link=temp;
        cout<<"Tail-link: "<<tail->link;
        tail=temp;
        tail->link=NULL;
        //delete temp;
        cout<<"\tUpdated Tail: "<<tail<<endl;
      }
      return tail;
}
node* addNode();
node* inputList(node*head){
    node*temp=new node;
    temp=head;
    while(temp){
        cin>>temp->data;
        if(temp->data==13||temp->data=='.'){
            return head;
        }
        temp=temp->link;
    }
    return head;
}
node*addToStart(node*start){
    node*temp=new node;
    temp->link=start;
    temp->data='/';
    return temp;
}
node*addToEnd(node*start){
    node*temp=new node;
    temp=start;
    while(temp->link){
        temp=temp->link;
    }
    node*endNode=new node;
    temp->link=endNode;
    endNode->link=NULL;
    endNode->data='/';
    return start;
}
node*addToMid(node*start,int pos){
    node*current=new node;
    node*previous=new node;
    current=start;
    int i=0;
    while(i<pos&&current->link->link){
        previous=current;
        current=current->link;
        i++;
    }
    node*midNode=new node;
    previous->link=midNode;
    midNode->link=current;
    midNode->data='.';
    return start;
}
node*deleteAtStart(node*start){
    node*temp=new node;
    temp=start;
    start=temp->link;
    temp->link=NULL;
    delete temp;
    return start;
}
node*deleteAtEnd(node*start){
    node*temp=new node;
    temp=start;
    while(temp->link->link){
        temp=temp->link;
    }
    delete temp->link;
    temp->link=NULL;
    //delete temp;
    return start;
}
node*deleteAtMid(node*start,int pos){
    node*current=new node;
    node*previous=new node;
    current=start;
    int i=1;
    while(i<pos&&current->link->link){
        previous=current;
        current=current->link;
        i++;
    }
    previous->link=current->link;
    delete current;
    return start;
}
int main(){
    node*head=new node;
    node*tail=new node;
    //tail=head;
    /*head=link;
    tail=link;
    link=NULL;*/
    cout<<"Head"<<head<<endl;
    head=tail;
    cout<<"Lenght of list: ";
    int len;
    cin>>len;
    for(int i=1;i<len;i++){
        cout<<endl;
        tail=createnode(tail);
        cout<<"Tail outside fn: "<<tail<<endl;
        cout<<endl;
    }
    tail->link=NULL;
    tail=head;
    cout<<head<<endl;
    head=inputList(head);
    printList(head);
    tail=head;
    head=addToStart(head);
    //head=inputList(head);
    printList(head);
    head=addToEnd(head);
    //head=inputList(head);
    printList(head);
    int pos=len-3;
    head=addToMid(head,pos);
    printList(head);
    head=deleteAtStart(head);
    printList(head);
    head=deleteAtEnd(head);
    printList(head);
    head=deleteAtMid(head,pos);
    printList(head);
    
    node*head2=new node;
    node*tail2=new node;
    //tail=head;
    /*head=link;
    tail=link;
    link=NULL;*/
    /*cout<<"Lenght of list 2: ";
    cin>>len;
    tail2=head2;
    for(int i=1;i<len;i++){
        cout<<endl;
        tail=createnode(tail);
        cout<<"Tail outside fn: "<<tail<<endl;
        cout<<endl;
    }
    head=inputList(head);*/
}
