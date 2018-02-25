#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <class T>

class List{
private:
   Node<T> *head;
   Node<T> *tail;
   int size;

public:
  List(){
    head=NULL;
    tail=NULL;
    size=0;
  };
  void show(){
    Node<T> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
  };
  bool isEmpty(){
    return head==NULL && tail==NULL;
  };
  void pushFront(T x){
      size++;
      Node<T> *newItem=new Node<T>;
      newItem->data=x;
      newItem->prev=NULL;
      if(isEmpty()){
        head=tail=newItem;
        newItem->next=NULL;
      }else{
        newItem->next=head;
        head->prev=newItem;
        head=newItem;
      }
  };
  T topFront(){
    return isEmpty() ? -1 : head->data;
  };
  void popFront(){
      if(isEmpty()){
        cout<<"Cannot pop front!"<<endl;
      }else{

        Node<T> *temp=head;
        if(size==1){
          head=tail=NULL;
        }else{
          temp->next->prev=NULL;
          head=head->next;
        }
        delete temp;
        size--;
      }
  };
  void pushBack(T x){

      Node<T> *newItem=new Node<T>;
      size++;
      newItem->data=x;
      newItem->next=NULL;
      if(isEmpty()){
        newItem->prev=NULL;
        head=tail=newItem;
      }else{
        newItem->prev=tail;
        tail->next=newItem;
        tail=newItem;
      }

  };
  T topBack(){
    return tail->data;
  };
  void popBack(){
      if(isEmpty()){
        cout<<"Cannot pop back!"<<endl;
      }else{
        Node<T> *temp=tail;
        if(size==1){
          head=tail=NULL;
        }else{

          temp->prev->next=NULL;
          tail=tail->prev;
        }
        delete temp;
        size--;
      }

  };
  bool find(T t){
    Node<T> *temp=head;
    while(temp!=NULL){
        if(temp->data==t)
          return true;
        temp=temp->next;
    }
    return false;
  };
  List<T> filterByValue(T x){
    List<T> contain;
    Node<T> *temp=head;
    while(temp!=NULL){
        if(temp->data==x)
          contain.pushBack(x);
        temp=temp->next;
    }
  };
  void insert(int pos,T key){
    if(pos<1 || pos>size){
      cout<<"Cannot insert"<<endl;
    }else{
      Node<T> *item=new Node<T>;
      item->data=key;
      if(size==0){
        head=tail=item;
        item->next=NULL;
        item->prev=NULL;
      }else{
        Node<T> *temp=NULL;
        if(pos<=size/2){
          temp=head;
          if(pos==1){
            head=item;
            item->prev=NULL;
          }else{
            for(int i=0;i<pos-1;i++){
              temp=temp->next;
            }
            temp->prev->next=item;
            item->prev=temp->prev;
          }
          temp->prev=item;
          item->next=temp;
        }else{
          temp=tail;
          if(pos==size){
            tail=item;
            item->next=NULL;
          }else{
            for(int i=size-1;i>pos-1;i--){
              temp=temp->prev;
            }
            temp->next->prev=item;
            item->next=temp->next;
          }
          temp->next=item;
          item->prev=temp;
        }
      }
      size++;
    }
  };
  int length(){
    return size;
  }
  void remove(int pos){
    if(pos<1 || pos>size){
      cout<<"Cannot remove"<<endl;
    }else{
      Node<T> *temp=NULL;
      if(pos<=size/2){
        temp=head;
        if(pos==1){
          head=temp->next;
          temp->next->prev=NULL;
        }else{
          for(int i=0;i<pos-1;i++){
            temp=temp->next;
          }
          temp->prev->next=temp->next;
          temp->next->prev=temp->prev;
        }
        delete temp;
      }else{
        temp=tail;
        if(pos==size){
          tail=temp->prev;
          temp->prev->next=NULL;
        }else{
          for(int i=size-1;i>pos-1;i--){
            temp=temp->prev;
          }
          temp->next->prev=temp->prev;
          temp->prev->next=temp->next;
        }
        delete temp;
      }
      size--;
    }
  };
  int indexOf(T any){
    Node<T> *temp=head;
    int count=0;
    while(temp!=NULL){
      if(temp->data==any)
        return count;
      temp=temp->next;
      count++;
    }
    return -1;
  };
  void removeAll(){
    while(head!=NULL){
      Node<T> *temp=head;
      head=head->next;
      delete temp;
    }
    size=0;
  };
  T valueAt(int pos){
    Node<T> *temp=pos<=size/2 ? head : tail;
    int c = pos<=size/2 ? 0 : size-1;
    if(c==0){
      while(c<pos){
        temp=temp->next;
        c++;
      }
      return temp->data;
    }else{
      while(c>pos){
        temp=temp->prev;
        c--;
      }
      return temp->data;
    }
  };
  void copy(List<T> &list,int h,int t){
    list.removeAll();
    int count=0;
    Node<T> *temp=head;
    while(count<=t){
      if(count>=h){
        list.pushBack(temp->data);
      }
      temp=temp->next;
      count++;
    }
  };
  void change(int pos,T val){
    Node<T> *temp=pos<=size/2 ? head : tail;
    int c = pos<=size/2 ? 0 : size-1;
    if(c==0){
      while(c<pos){
        temp=temp->next;
        c++;
      }
    }else{
      while(c>pos){
        temp=temp->prev;
        c--;
      }
    }
    temp->data=val;
  };
  void merge(int h,int m,int t){
    List<T> temp1;
    List<T> temp2;
    int c1=m-h+1,c2=t-m;
    copy(temp1,h,m);
    copy(temp2,m+1,t);
    int i=0,j=0,count=h;
    while(i<c1 && j<c2){
      if(temp1.valueAt(i) <= temp2.valueAt(j)){
        change(count,temp2.valueAt(j));
        j++;
      }else{
        change(count,temp1.valueAt(i));
        i++;
      }
      count++;
    }
    while(i<c1){
      change(count,temp1.valueAt(i));
      i++;
      count++;
    }
    while(j<c2){
      change(count,temp2.valueAt(j));
      j++;
      count++;
    }
    temp1.removeAll();
    temp2.removeAll();
  };
  void sort(int h,int t){
    if(h<t){
    int m=(h+t)/2;
      sort(h,m);
      sort(m+1,t);
      merge(h,m,t);
    }
  };

};
