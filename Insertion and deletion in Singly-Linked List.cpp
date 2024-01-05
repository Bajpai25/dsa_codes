# include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next=NULL;
    
    // creating custom constructor
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
    // creating custom destructor for deleting and releasing memory Node
    
    ~Node(){
        int value=this->data;
        // memory free 
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"deleted node value is :"<<value<<endl;
    }
};
    
    // for inserting at first
    
    void insert_at_head(Node* &head,int data){
        Node* temp=new Node(data);
        temp->next=head;
        head=temp;
    }
    // for inserting at last
    
    void insert_at_tail(Node* &tail ,int data){
        Node* temp=new Node(data);
        tail->next=temp;
        temp=tail;
    }
    // for insertion at any place in the linked list
    
    void insert_at_pos(Node* &head, Node* &tail, int pos,int data){
        // when insert at start
        
        if(pos==1){
            insert_at_head(head,data);
        }
        
        // when to insert at any pos
        
        Node* temp=head;
        Node* insert=new Node(data);
        int count=1;
        
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        
        insert->next=temp->next;
        temp->next=insert;
        
        // when to insert at last
        
        if(temp->next==nullptr){
            tail=temp;
        }
    }
    
    void delete_value(int position, Node* &head){
        // delete at the start position // head
        
        
        if(position==1){
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        else{
        
        // delete at any position including the last position too
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        
        // deleting the current node too
        
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        }
    
    }
    // print the linked list 
    
    void print(Node* &head){
        while(head!=NULL){
            cout<<head->data<<"->";
            head=head->next;
        }
    }

int main()

{   Node* n1=new Node(10);
    
    Node* head=n1;
    Node* tail=n1;
    
    insert_at_head(head,12);
    insert_at_head(head,13);
    insert_at_head(head,14);
    insert_at_head(head,15);
    insert_at_head(head,16);
    insert_at_head(head,17);
    insert_at_head(head,18);
    insert_at_head(head,19);
    insert_at_head(head,20);
    insert_at_head(head,21);
    insert_at_head(head,22);
    insert_at_pos(head,tail,2,23);
    insert_at_pos(head,tail,13,9);
    delete_value(13,head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
     print(head);

return 0;
}
