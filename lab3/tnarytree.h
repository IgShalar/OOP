#ifndef TNARYTREE_H
#define TNARYTREE_H

#include "hexagon.h"

using namespace std;

class node{
    
public:
    shared_ptr <node> brt, cld;
    shared_ptr <Hexagon> val;
    
    node(){
        cld = NULL;
        brt = NULL;
        val = NULL;
    }
    
};

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
    void Update(Hexagon &now, std::string &tree_path);
    
    // Удаление поддерева
    void Clear(std::string &tree_path);
    
    // Проверка наличия в дереве вершин
    bool Empty();
    
    // Подсчет суммарной площади поддерева
    double Area(std::string &tree_path);
    
    // Вывод дерева в формате вложенных списков, где каждый вложенный список является:
    // "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры
    friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);
    
    ~TNaryTree();
    
private:
    shared_ptr <node> root;
    shared_ptr <node> now;
    int size;
    int max_size;
    int get_size();
    void check();
    void decrease();
    void node_delete(shared_ptr <node>, TNaryTree &, shared_ptr <node>);
    void change_val(Hexagon &);
};

#endif
