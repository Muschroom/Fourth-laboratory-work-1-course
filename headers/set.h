#pragma once
#include "tree.h"
#include <vector>
template<typename T>
std::vector<T> Split(std::string str) {
    std::vector<T> tokens;
    std::string current;
    
    for (char c : str) {
        if (c == ' ') {
            if (!current.empty()) {
                tokens.push_back(std::stoi(current));
                current.clear();
            }
        } else {
            current += c;
        }
    }
    
    if (!current.empty()) {
        tokens.push_back(std::stoi(current));
    }
    
    return tokens;
}

template <typename T>
class Set{
private:
    Tree<T> * tree;
public:
    Set(){
        tree = new Tree<T>();
    }

    int get_size() const {
        return tree->size;
    }

    bool empty() const {
        return tree->size == 0;
    }

    void add(T val){
        tree->insert(val);
    }
    
    bool find(T val){
        return tree->find(val);
    }

    void remove(const T& val){
        tree->remove(val);
    }

    void print(){
        tree->print();
    }

    Set<T>* map(std::function<T(T)> func){
        Set<T>* new_set = new Set<T>();
        new_set->tree = tree->map(func);
        return new_set;
    }

    Set<T>* where(std::function<bool(T)> func){
        Set<T>* new_set = new Set<T>();
        new_set->tree = tree->where(func);
        return new_set;
    }

    T reduce(std::function<T(T, T)> func, const T& val){
        return tree->reduce(func, val);
    }

    Set<T>* unio(Set<T>* other){
        Set<T>* new_set = new Set<T>();
        std::string s1 = tree->travel(LNR);
        std::string s2 = other->tree->travel(LNR);
        std::vector<T> first = Split<T>(s1);
        std::vector<T> second = Split<T>(s2);
        for(T val: first){
            new_set->add(val);
        }
        for(T val: second){
            new_set->add(val);
        }
        return new_set;
    }

    Set<T>* intersection(Set<T>* other){
        Set<T>* new_set = new Set<T>();
        std::vector<T> first = Split<T>(tree->travel(LNR));
        std::vector<T> second = Split<T>(other->tree->travel(LNR));
        int i = 0, j = 0;
        while(i < first.size() && j < second.size()){
            if(first[i] == second[j]){
                new_set->add(first[i]);
                i++;
                j++;
            }
            else{
                if(first[i] < second[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
        }
        return new_set;
    }

    Set<T>* differ(Set<T>* other){
        Set<T>* new_set = new Set<T>();
        std::vector<T> first = Split<T>(tree->travel(LNR));
        std::vector<T> second = Split<T>(other->tree->travel(LNR));
        int i = 0, j = 0;
        while(i < first.size() && j < second.size()){
            if(first[i] == second[j]){
                i++;
                j++;
            }
            else{
                new_set->add(first[i]);
                i++;

            }
        }
        return new_set;
    }

    bool has_set(Set<T>* other){
        return tree->hassubtree(other->tree);
    }

    bool is_equal(Set<T>* other){
        return tree->hassubtree(other->tree) && tree->getSize() == other->tree->getSize();
    }

    std::string to_string(){
        return tree->travel(LNR);
    }
    
    ~Set(){
        delete tree;
    }
};

template<typename T>
Set<T>* to_set(std::string str){
    Set<T>* new_set = new Set<T>(); 
    std::vector<T> arr = Split<T>(str);
    for(T val: arr){
        new_set->add(val);
    }
    return new_set;
}