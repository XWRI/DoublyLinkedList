//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"

template<typename T>
class DoublyLinkedList;


template<typename T>
class ConstReverseDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

public:

    DoublyLinkedList<T>& doublyLinkedList;
    DoubleLinkedNode<T>* curNode;

    ConstReverseDoublyLinkedListIterator(const DoublyLinkedList<T>& ItrdoublyLinkedList, const DoubleLinkedNode<T>* ItrNode);

  //copy constructor
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ConstReverseDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstReverseDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstReverseDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstReverseDoublyLinkedListIterator<T> operator--(int);//post

  //get a const reference to the value
  const T& operator*() const;

};

#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H

template<typename T>
ConstReverseDoublyLinkedListIterator<T>::ConstReverseDoublyLinkedListIterator(const DoublyLinkedList<T> &ItrdoublyLinkedList, const DoubleLinkedNode<T>* ItrNode)
    : doublyLinkedList(const_cast<DoublyLinkedList<T>&>(ItrdoublyLinkedList)),
    curNode(const_cast<DoubleLinkedNode<T>*>(ItrNode)){}

template<typename T>
ConstReverseDoublyLinkedListIterator<T>::ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator &orig)
    : doublyLinkedList(orig.doublyLinkedList),  curNode(orig.curNode){}

template<typename T>
bool ConstReverseDoublyLinkedListIterator<T>::operator==(const ConstReverseDoublyLinkedListIterator<T> &rhs) const {
  if(&doublyLinkedList != &rhs.doublyLinkedList){
    return false;
  }
  else{
    return curNode == rhs.curNode;
  }
}

template<typename T>
bool ConstReverseDoublyLinkedListIterator<T>::operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const {
  return !(*this == rhs);
}

template<typename T>
ConstReverseDoublyLinkedListIterator<T>::operator bool() const {
  return curNode != nullptr;
}

template<typename T>
ConstReverseDoublyLinkedListIterator<T>& ConstReverseDoublyLinkedListIterator<T>::operator++() {

    curNode = curNode->previous;
    return *this;

}

template<typename T>
const ConstReverseDoublyLinkedListIterator<T> ConstReverseDoublyLinkedListIterator<T>::operator++(int) {
  ConstReverseDoublyLinkedListIterator copy(*this);
  curNode = curNode->previous;
  return copy;
}

template<typename T>
ConstReverseDoublyLinkedListIterator<T>& ConstReverseDoublyLinkedListIterator<T>::operator--() {

    curNode = curNode->next;
    return *this;

}

template<typename T>
const ConstReverseDoublyLinkedListIterator<T> ConstReverseDoublyLinkedListIterator<T>::operator--(int) {
  ConstReverseDoublyLinkedListIterator copy(*this);
  curNode = curNode->next;
  return copy;
}

template<typename T>
const T& ConstReverseDoublyLinkedListIterator<T>::operator*() const {
  return curNode->value;
}


