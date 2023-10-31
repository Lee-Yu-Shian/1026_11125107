#include <iostream>
#include<cstdlib> 
#include<cstring>
#include <typeinfo>

using namespace std;
#pragma once

//Node
template <class T>
class Node {
public:
    T data; // 資料
    Node<T>* next; // 傳送門
    
    Node();//建構子
    ~Node();//解構子
};

template <class T>
Node<T>::Node() : next(NULL), data() {}//預設值

template<class T>
Node<T>::~Node()
{

}