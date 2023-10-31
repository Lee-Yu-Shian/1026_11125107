#include <iostream>
#include<cstdlib> 
#include<cstring>
#include <typeinfo>
#include "1026_11125107_Node.hpp"
#include "1026_11125107_Student.hpp"
using namespace std;
#pragma once



template<class T>
class Queue {
private:
    int count;
    Node<T>* front; // 序列前端指標
    Node<T>* rear; // 序列後端指標

public:
    Queue();
    ~Queue();
    bool IsEmpty();//檢查是否為空，T:為空；F:不為空
    Node<T>* Front();//前端元素
    Node<T>* Rear();//後端元素
    int Push(T &item);//放入元素
    int Pop();//刪除元素
};

template<class T>
Queue<T>::Queue() : front(NULL) , rear(NULL) , count(0) {}//預設值

template<class T>
Queue<T>::~Queue()
{
    while (front) //front會依次將所有元素進行刪除，直到其指向NULL
    {
        Node<T>* temp = front;
        front = front->next;
        delete temp;//設定暫存元素進行刪除(比較保險)
    }
}

template<class T>
bool Queue<T>::IsEmpty() {
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
Node<T>* Queue<T>::Front() {
    if (IsEmpty()) 
    {
        throw std::runtime_error("Queue is empty.");//出現空時報錯
    }
    else
    {
        return front;
    }
}

template<class T>
Node<T>* Queue<T>::Rear() {
    if (IsEmpty()) 
    {
        throw std::runtime_error("Queue is empty.");//出現空時報錯
    }
    else
    {
        return rear;
    }
}


template<class T>
int Queue<T>::Push(T &item) {
    Node<T>* new_node = new Node<T>(); //利用動態記憶體，直到用盡記憶體空間
    new_node->data = item; //存入對應資料
    new_node->next = NULL; //新資料應存入NULL連結(GND)

    if (IsEmpty()) 
    {
        front = new_node; //若內部無元素，front指向新元素
    } 
    else 
    {
        rear->next = new_node; //否則舊rear指向新元素的位置
    }

    rear = new_node; //rear指向新元素
    count++;

    return 0;
}


template<class T>
int Queue<T>::Pop() {
    if (IsEmpty()) {
        throw std::runtime_error("Queue is empty.");//當內部無值時報錯
    }

   Node<T>* temp = front;
    front = front->next;
    delete temp;
    count--;

    if (count == 0) //如果沒有元素時
    { 
        rear = NULL;
        front = NULL;
    }
    else if (count == 1) // 如果僅有一個元素時
    { 
        rear = front;
    }

    return 0;
}