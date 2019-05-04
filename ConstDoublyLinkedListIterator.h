//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"

template<typename T>
class DoublyLinkedList;

template<typename T>
class ConstDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 friend class DoublyLinkedList<T>;
 public:

    DoublyLinkedList<T>& doublyLinkedList;
    DoubleLinkedNode<T>* curNode;

    ConstDoublyLinkedListIterator(const DoublyLinkedList<T>& ItrdoublyLinkedList, const DoubleLinkedNode<T>* ItrNode);

  ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator& orig);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ConstDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstDoublyLinkedListIterator<T> operator--(int); //post

  //get a const reference to the value
  const T& operator*() const;

};

#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H

template <typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const DoublyLinkedList<T>& ItrdoublyLinkedList, const DoubleLinkedNode<T>* ItrNode)
    : doublyLinkedList(const_cast<DoublyLinkedList<T>&>(ItrdoublyLinkedList)), curNode(const_cast<DoubleLinkedNode<T>*>(ItrNode)) {}

template<typename T>
ConstDoublyLinkedListIterator<T>::ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator &orig)
    : doublyLinkedList(orig.doublyLinkedList),  curNode(orig.curNode){}

template<typename T>
bool ConstDoublyLinkedListIterator<T>::operator==(const ConstDoublyLinkedListIterator<T> &rhs) const {
  if(&doublyLinkedList != &rhs.doublyLinkedList){
    return false;
  }
  else{
    return curNode == rhs.curNode;
  }
}

template<typename T>
bool ConstDoublyLinkedListIterator<T>::operator!=(const ConstDoublyLinkedListIterator<T> &rhs) const {
  return !(*this == rhs);
}

template<typename T>
ConstDoublyLinkedListIterator<T>::operator bool() const {
	return curNode != nullptr;
}

template<typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator++() {

    curNode = curNode->next;
    return *this;

}

template<typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator++(int) {
  ConstDoublyLinkedListIterator copy(*this);
  curNode = curNode->next;
  return copy;
}

template<typename T>
ConstDoublyLinkedListIterator<T>& ConstDoublyLinkedListIterator<T>::operator--() {

    curNode = curNode->previous;
    return *this;

}

template<typename T>
const ConstDoublyLinkedListIterator<T> ConstDoublyLinkedListIterator<T>::operator--(int) {
  ConstDoublyLinkedListIterator copy(*this);
  curNode = curNode->previous;
  return copy;
}

template<typename T>
const T& ConstDoublyLinkedListIterator<T>::operator*() const {
  return curNode->value;
}

