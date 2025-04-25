// Copyright 2025 Jake Sheror and Abby Holdcraft
#include"setinterface.h"
#include<iostream>
using std::ostream;
#include<string>
using std::string;
using std::cout;
using std::endl;
#include"myset.h"

namespace csce240h_exam3 {

template<class T>
MySet<T>::MySet(T * array, int num_elements) {
  SetElements(array, num_elements);
}

template<class T>
MySet<T>::MySet(const MySet<T>& tocopy) {
  SetElements(tocopy.array_, tocopy.num_elements_);
}

template<class T>
MySet<T>::~MySet() {
  delete [] array_;
}

template<class T>
void MySet<T>::SetElements(T * array, int num_elements) const {
  if (array_ != nullptr)
    delete [] array_;
  num_elements_ = num_elements;
  array_ = new T[num_elements_];
  for (int i = 0; i < num_elements_; i++)
    array_[i] = array[i];
}

template<class T>
void MySet<T>::Print() const {}

template<class T>
bool MySet<T>::IsElementOf(T value) const {} 

template<class T>
int MySet<T>::Cardinality() const {} 

template<class T>
bool MySet<T>::AddElement(const T&) {} 

template<class T>
bool MySet<T>::RemoveElement(const T&) {} 

template<class T>
bool MySet<T>::IsSubsetOf(const SetInterface<T>& superset) {} 

template<class T>
bool MySet<T>::IsSupersetOf(const SetInterface<T>& subset) {} 

template<class T>
void MySet<T>::Intersection(const SetInterface<T>& set2) {} 

template<class T>
void MySet<T>::SortAscending() {}

template<class T>
void MySet<T>::SortDesnending() {}

template<class T>
void MySet<T>::RemoveDuplicates() {}

template<class T>
MySet<T>& MySet<T>::Concat(const SetInterface<T>& set2, bool includeDuplicates) {}  // Return *this at end

template<class T>
MySet<T>& MySet<T>::operator = (const MySet& tocopy) {}

// template<class T>
// MySet<T>& operator + (const MySet<T>& toadd) {}

template<class T>
MySet<T>& MySet<T>::operator - (const MySet<T>& tosub) {} // Only works if set2 isSubSetOf set1 

template<class T>
bool MySet<T>::operator == (const MySet<T>& other) {}

template<class T>
ostream& operator << (ostream& where_to, const MySet<T>& mySet);

}  // end namespace csce240h_exam3