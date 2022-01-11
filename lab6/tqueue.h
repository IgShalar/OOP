#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using namespace std;

template <typename T>
struct q_node{
    shared_ptr <T> val;
    shared_ptr< q_node<T> > next;
    
    q_node(T &now) {
        T * temp = new T;
        * temp = now;
        val.reset(temp);
        next = NULL;
    }
    
    ~q_node(){
        val = NULL;
        next = NULL;
//        cout << "DELETED" << endl;
    }
};

template <typename T>
struct TQueue{
public:
    TQueue(){ head = NULL; }
    void print(){
        if (this->empty()){
            cout << endl;
            return;
        }
        q_node<T> * temp = this->head.get();
        while (temp != NULL){
            cout << * temp->val << " ";
            temp = temp->next.get();
        }
        cout << endl;
    }
    void push(T add){
        if (this->empty()){
            q_node <T> * temp = new q_node<T>(add);
            this->head.reset(temp);
        }
        else{
            q_node<T> * now = this->head.get();
            while (now->next != NULL) now = now->next.get();
            q_node <T> * temp = new q_node<T>(add);
            now->next.reset(temp);
        }
    }
    
    T pop(){
        if (this->empty()) exit(-1);
        T res = * this->head->val.get();
        shared_ptr< q_node<T> > temp(this->head->next);
        this->head = temp;
        temp = NULL;
        return res;
    }
    
    bool empty(){ return head == NULL;}
    
    void find_delete(T t){
        if (* this->head.get()->val == t){
            this->head = this->head->next;
            return;
        }
        q_node <T> * now = this->head.get();
        while (* now->next->val != t){
            if (now->next == NULL) exit(-1);
            now = now->next.get();
        }
        now->next = now->next->next;
    }
    
    ~TQueue(){
        this->head = NULL;
    }
    
    
private:
    shared_ptr <q_node <T> > head;
};

#endif
