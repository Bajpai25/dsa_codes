

#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
// approach 1 
T.C=O(n)
  S.C=O(n)
class Solution
{
    private:
    void insertatTail(Node*&head,Node*&tail,int data){
        Node*insert=new Node(data);
        if(head==NULL){
            head=insert;
            tail=insert;
            return ;
        }
        tail->next=insert;
        tail=insert;
    }
    public:
    Node *copyList(Node *head)
    {
       Node*clonehead=NULL;
       Node*clonetail=NULL;
       Node*temp=head;
       while(temp!=NULL){
           insertatTail(clonehead,clonetail,temp->data);
           temp=temp->next;
       }
       unordered_map<Node*,Node*>m;
       Node*originalnode=head;
       Node*clonenode=clonehead;
       // mapping from original to clone node 
       while(originalnode!=NULL && clonenode!=NULL){
           m[originalnode]=clonenode;
           originalnode=originalnode->next;
           clonenode=clonenode->next;
       }
       
       //ab hum log mapping se check karnege aur wahi links original se copy linked liost mein apply karenge
        
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
            clonenode->arb=m[originalnode->arb];
            originalnode=originalnode->next;
           clonenode=clonenode->next;
        }
        return clonehead;
        
    }

};
