#ifndef TNARYTREE_H
#define TNARYTREE_H

#include "hexagon.h"

class node{
    
public:
    node * cld, * brt;
    Hexagon val;
    
    node(){
        cld = NULL;
        brt = NULL;
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
    node * root;
    node * now;
    int size;
    int max_size;
    int get_size();
    void check();
    void decrease();
    void node_delete(node *, TNaryTree &, node * rt);
};

#endif
