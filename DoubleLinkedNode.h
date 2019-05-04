//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

//the class that represents a node in the list

template<typename T>
class DoubleLinkedNode{

  public:
	T value;
	DoubleLinkedNode<T>* previous;
	DoubleLinkedNode<T>* next;

	DoubleLinkedNode(const T& value, DoubleLinkedNode<T>* previous = nullptr, DoubleLinkedNode<T>* next = nullptr);
};

template<typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(const T &value, DoubleLinkedNode<T> *previous, DoubleLinkedNode<T> *next)
: value(value), previous(previous), next(next) {}


#endif //LINKEDLIST_DOUBLELINKEDNODE_H
