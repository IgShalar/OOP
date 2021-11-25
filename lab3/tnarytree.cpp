#include"hexagon.h"
#include"tnarytree.h"
#include<iostream>
#include <stdexcept>

using namespace std;

void TNaryTree::check(){
    if (size >= max_size){
        throw out_of_range("Nodes limit exceeded.");
        exit(-1);
    }
}

TNaryTree::TNaryTree(int n){
    max_size = n;
    root = NULL;
    size = 0;
}

void assign (shared_ptr <node> left,  Hexagon & right){
    if (left->val == NULL){
        Hexagon * ptr = new Hexagon;
        * ptr = right;
        shared_ptr <Hexagon> temp(ptr);
        left->val.swap(temp);
        return;
    }
    * left->val = right;
}

shared_ptr <node> create_node(shared_ptr <node> other){
    node * temp = new node;
    shared_ptr <node> ptr(temp);
    ptr->val = other->val;
    return ptr;
}

void TNaryTree::decrease(){
    size--;
}

int TNaryTree::get_size(){
    return size;
}

void node_copy(shared_ptr <node> now, const shared_ptr <node> other, char p){
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

TNaryTree::TNaryTree(const TNaryTree& other){
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
void TNaryTree::Update(Hexagon &h, std::string &tree_path){
    if (tree_path == ""){
        if (root == NULL){
            check();
            node * ptr = new node;
            shared_ptr <node> temp(ptr);
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
            node * ptr = new node;
            shared_ptr <node> temp(ptr);
            assign(temp, h);
            now->cld = temp;
            size++;
        }
        else assign(now->cld, h);
    }
    else{
        if (now->brt == NULL){
            check();
            node * ptr = new node;
            shared_ptr <node> temp(ptr);
            assign(temp, h);
            now->brt = temp;
            size++;
        }
        else assign(now->brt, h);
    }
}

void TNaryTree::node_delete(shared_ptr <node> now1, TNaryTree &t, shared_ptr <node> rt){
    if (now1==NULL) return;
    t.decrease();
    node_delete(now1->cld, t, rt);
    if (now1 != rt) node_delete(now1->brt, t, rt);
}

// Удаление поддерева
void TNaryTree::Clear(std::string &tree_path){
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
bool TNaryTree::Empty(){
    return root == NULL;
}

double node_square(shared_ptr <node> now){
    if (now == NULL) return 0;
    double res = now->val->Area();
    res += node_square(now->cld);
    res += node_square(now->brt);
    return res;
}

// Подсчет суммарной площади поддерева
double TNaryTree::Area(std::string &tree_path){
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
void print(std::ostream& os, shared_ptr <node> v, bool p){
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
std::ostream& operator<<(std::ostream& os, const TNaryTree& tree){
    if (tree.root == NULL) return os;
    print(os, tree.root, 0);
    return os;
}

TNaryTree::~TNaryTree(){
    string s = "";
    Clear(s);
}
