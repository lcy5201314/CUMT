#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

typedef struct node{
    int data;
    node * next;
}node;


node * add(int n, node * head){
    node * t = new node;
    t->data = n;
    t->next = NULL;
    if (head == NULL){
        head = t;
    }
    else if (head->next == NULL){
        head->next = t;
    }
    else{
        node * p = head->next;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = t;
    }
    return head;
}


void print(node * head){
    node * p = head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void reversePrint(node * p){
    if (p != NULL){
        reversePrint(p->next);
        cout << p->data << " ";
    }
}


void reversePrint2(node * head){
    stack<int> s;
    while (head != NULL){
        s.push(head->data);
        head = head->next;
    }

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){

    node * head = NULL;
    for (int i = 1; i <= 8; i++){
        head = add(i, head);
    }
    print(head);
    reversePrint(head);
    reversePrint2(head);
    system("pause");
   return 0;
}
