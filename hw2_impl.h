#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw2.h"

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {  
  // COMPLETE HERE
}

template <typename T>
void Heap<T>::insert(T const& element) {
  // COMPLETE HERE
  data.push_back(element);
  heapifyUp(data.size() - 1);
}

template <typename T>
T Heap<T>::extractTop() {
  // COMPLETE HERE
  if(isEmpty()){
    throw std::out_of_range("Empty heap");
  }
  T top = datos[0];
  datos[0] = datos.back();
  datos.pop_back();
  if(datos.size() > 0){
    heapifyDown(0);
  }
  return top;
}

template <typename T>
T Heap<T>::peek() const {
  // COMPLETE HERE
  if(isEmpty()){
    throw std::out_of_range("Empty heap");
  }
  return datos[0];
}

template <typename T>
size_t Heap<T>::size() const {
  // COMPLETE HERE
  return datos.size();
}

template <typename T>
bool Heap<T>::isEmpty() const {
  // COMPLETE HERE
  return datos.empty();
}


template <typename T>
void Heap<T>::clear() {
  // COMPLETE HERE
  datos.clear();
}

template <typename T>
void Heap<T>::heapifyUp(size_t indice){
  while(indice > 0){
    size_t padre = (indice - 1)/2;
    if((minHeap && datos[indice] < datos[padre]) || (!minHeap && datos[indice] > datos[padre])){
      std::swap(datos[indice], datos[padre]);
      indice = padre;
    }else{
      break;
    }
  }
}

template <typename T>
void Heap<T>::heapifyDown(size_t indice){
  size_t hijoIzquierdo, hijoDerecho, target;
  while(indice < datos.size()){
    hijoIzquierdo = 2*indice + 1; 
    hijoDerecho = 2*indice + 2;
    target = indice;
    if(hijjoIzquierdo < datos.sizr() && ((minHeap && datos[hijoIzquierdo] < datos[target]) || (!minHeap && datos[hijoIzquierdo] > datos[target]))){
      target = hijoIzquierdo;
    }
    if(hijoDerecho < datos.size() && ((minHeap && datos[hijoDerecho] < datos[target]) || (!minHeap && datos[hijoDerecho] > datos[target]))){
      target = hijoDerecho;
    }
    if(target == indice){
      break;
    }
    std::swap(datos[indice], datos[target]);
    indice = target;
  }
}

#endif
