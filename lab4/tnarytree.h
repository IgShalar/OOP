#ifndef TNARYTREE_H
#define TNARYTREE_H

#include "hexagon.h"
#include<iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class node{
    
public:
    shared_ptr <node<T>> brt, cld;
    shared_ptr <T> val;
    
    node(){
        cld = NULL;
        brt = NULL;
        val = NULL;
    }
    
};

template <typename T>
class TNaryTree {
public:
    // Инициализация дерева с указанием размера
    TNaryTree(int);
    
    // Полное копирование дерева
    TNaryTree(const TNaryTree& other);
    
    // Добавление или обновление вершины в дереве согласно заданному пути.
    // Путь задается строкой вида: "cbccbccc",
    // где 'c' - старший ребенок, 'b' - младший брат
    // последний символ строки - вершина, которую нужно добавить или обновить.
    // Пустой путь "" означает добавление/обновление корня дерева.
    void Update(T &now, std::string &tree_path);
    
    // Удаление поддерева
    void Clear(std::string &tree_path);
    
    // Проверка наличия в дереве вершин
    bool Empty();
    
    // Подсчет суммарной площади поддерева
    double Area(std::string &tree_path);
    
    // Вывод дерева в формате вложенных списков, где каждый вложенный список является:
    // "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const TNaryTree<U> &tree);
    
    ~TNaryTree();
    
private:
    shared_ptr <node<T>> root;
    shared_ptr <node<T>> now;
    int size;
    int max_size;
    int get_size();
    void check();
    void decrease();
    void node_delete(shared_ptr <node<T>>, TNaryTree &, shared_ptr <node<T>>);
    void change_val(T &);
};


template <typename T>
void TNaryTree<T>::check(){
    if (size >= max_size){
        throw out_of_range("Nodes limit exceeded.");
        exit(-1);
    }
}

template <typename T>
TNaryTree<T>::TNaryTree(int n){
    max_size = n;
    root = NULL;
    size = 0;
}

template <typename T>
void assign (shared_ptr <node<T>> left,  T & right){
    if (left->val == NULL){
        T * ptr = new T;
        * ptr = right;
        shared_ptr <T> temp(ptr);
        left->val.swap(temp);
        return;
    }
    * left->val = right;
}

template <typename T>
shared_ptr <node<T>> create_node(shared_ptr <node<T>> other){
    node<T> * temp = new node<T>;
    shared_ptr <node<T>> ptr(temp);
    ptr->val = other->val;
    return ptr;
}

template <typename T>
void TNaryTree<T>::decrease(){
    size--;
}

template <typename T>
int TNaryTree<T>::get_size(){
    return size;
}

template <typename T>
void node_copy(shared_ptr <node<T>> now, const shared_ptr <node<T>> other, char p){
    if (other == NULL) return;
    if (p == 'c') {
        now->cld = create_node(other);
        now = now->cld;
    }
    else{
        now->brt = create_node(other);
        now = now->brt;
    }
    node_copy (now, other->cld, 'c');
    node_copy (now, other->brt, 'b');
}

// Полное копирование дерева

template <typename T>
TNaryTree<T>::TNaryTree(const TNaryTree<T> &other){
    if (other.root == NULL) return;
    size = other.size;
    max_size = other.max_size;
    root = create_node(other.root);
    node_copy (root, other.root->cld, 'c');
}

// Добавление или обновление вершины в дереве согласно заданному пути.
// Путь задается строкой вида: "cbccbccc",
// где 'c' - старший ребенок, 'b' - младший брат
// последний символ строки - вершина, которую нужно добавить или обновить.
// Пустой путь "" означает добавление/обновление корня дерева.
template <typename T>
void TNaryTree<T>::Update(T &h, std::string &tree_path){
    if (tree_path == ""){
        if (root == NULL){
            check();
            node<T> * ptr = new node<T>;
            shared_ptr <node<T>> temp(ptr);
            assign(temp, h);
            root = temp;
            size++;
        }
        else assign(root, h);
        return;
    }
    if (root == NULL || tree_path[0] == 'b'){
        throw invalid_argument("Invalid tree_path.");
        exit(-1);
    }
    now = root;
    for (int i = 0; i < tree_path.size() - 1; i++){
        if (tree_path[i] == 'c') now = now->cld;
        else now = now->brt;
        if (now == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
    }
    if (tree_path[tree_path.size() - 1] == 'c'){
        if (now->cld == NULL){
            check();
            node<T> * ptr = new node<T>;
            shared_ptr <node<T>> temp(ptr);
            assign(temp, h);
            now->cld = temp;
            size++;
        }
        else assign(now->cld, h);
    }
    else{
        if (now->brt == NULL){
            check();
            node<T> * ptr = new node<T>;
            shared_ptr <node<T>> temp(ptr);
            assign(temp, h);
            now->brt = temp;
            size++;
        }
        else assign(now->brt, h);
    }
}

template <typename T>
void TNaryTree<T>::node_delete(shared_ptr <node<T>> now1, TNaryTree<T> &t, shared_ptr <node<T>> rt){
    if (now1==NULL) return;
    t.decrease();
    node_delete(now1->cld, t, rt);
    if (now1 != rt) node_delete(now1->brt, t, rt);
}

// Удаление поддерева
template <typename T>
void TNaryTree<T>::Clear(std::string &tree_path){
    now = NULL;
    if (tree_path == ""){
        node_delete(root, * this, root);
        root = NULL;
        return;
    }
    if (root == NULL || tree_path[0] == 'b'){
        throw invalid_argument("Invalid tree_path.");
        exit(-1);
    }
    now = root;
    for (int i = 0; i < tree_path.size() - 1; i++){
        if (tree_path[i] == 'c'){
            now = now->cld;
        }
        else now = now->brt;
        if (now == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
    }
    if (tree_path[tree_path.size() - 1] == 'c'){
        if (now->cld == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
        node_delete (now->cld, * this, now->cld);
        now->cld = now->cld->brt;
    }
    else{
        if (now->brt == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
        node_delete (now->brt, * this, now->brt);
        now->brt = now->brt->brt;
    }
}

// Проверка наличия в дереве вершин
template <typename T>
bool TNaryTree<T>::Empty(){
    return root == NULL;
}

template <typename T>
double node_square(shared_ptr <node<T>> now){
    if (now == NULL) return 0;
    double res = now->val->Area();
    res += node_square(now->cld);
    res += node_square(now->brt);
    return res;
}

// Подсчет суммарной площади поддерева
template <typename T>
double TNaryTree<T>::Area(std::string &tree_path){
    if (tree_path == "") return node_square(root);
    if (root == NULL || tree_path[0] == 'b'){
        throw invalid_argument("Invalid tree_path.");
        exit(-1);
    }
    now = root;
    for (int i = 0; i < tree_path.size() - 1; i++){
        if (tree_path[i] == 'c') now = now->cld;
        else now = now->brt;
        if (now == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
    }
    if (tree_path[tree_path.size() - 1] == 'c'){
        if (now->cld == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
        return node_square (now->cld);
    }
    else{
        if (now->brt == NULL){
            throw invalid_argument("Invalid tree_path.");
            exit(-1);
        }
        return node_square (now->brt);
    }
    return 0;
}

// Вывод дерева в формате вложенных списков, где каждый вложенный список является:
// "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры
template <typename T>
void print(std::ostream& os, shared_ptr <node<T>> v, bool p){
    os << v->val->Area();
    if (v->cld != NULL){
        os << ": [";
        print(os, v->cld, 1);
    }
    if (v->brt != NULL){
        os << ", ";
        print(os, v->brt, 1);
    }
    else if (p) os << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const TNaryTree<T> &tree){
    if (tree.root == NULL) return os;
    print(os, tree.root, 0);
    return os;
}

template <typename T>
TNaryTree<T>::~TNaryTree(){
    string s = "";
    Clear(s);
}


#endif
