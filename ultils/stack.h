#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <class T>
class Stack{
private:
   Node<T> *head;
   int size;
public:
  Stack(){
    head=NULL;
    size=0;
  };
  bool isEmpty(){
    return head==NULL;
  };
  void push(T x){
      size++;
      Node<T> *temp=new Node<T>;
      temp->data=x;
      temp->next=NULL;
      if(head!=NULL){
        temp->next=head;
      }
      head=temp;
  };
  void show(){
    Node<T> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
  };
  T pop(){
    if(head==NULL){
        return -1;
    }
    size--;
    T value=head->data;
    Node<T> *temp=head;
    head=head->next;
    delete temp;
    return value;
  };
  T top(){
    return !isEmpty() ? head->data : -1;
  };


};
