#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <typename T>
struct q_node{
    T val;
    q_node<T> * next, * prev;
    
    q_node(T now) {
        val = now;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>
struct queue{
public:
    queue(){ head = NULL; last = NULL; }
    void out(){
        if (this->empty()){
            cout << endl;
            return;
        }
        q_node<T> * temp = this->head;
        while (temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void push(T add){
        if (this->empty()){
            this->head = new q_node<T>(add);
            this->last = this->head;
        }
        else{
            this->last->next = new q_node<T>(add);
            this->last = this->last->next;
        }
        
    }
    
    T pop(){
        if (this->empty()) exit(-5);
        T res = this->head->val;
        q_node<T> * temp = this->head;
        this->head = this->head->next;;
        delete(temp);
        return res;
    }
    
    bool empty(){ return head == NULL;}
    
    ~queue(){
        if (empty()) return;
        q_node<T> * now = this->head;
        while (now != NULL){
            q_node<T> * temp = now;
            now = now->next;
            delete temp;
        }
    }
    
private:
    q_node<T> * head, * last;
};

#endif
