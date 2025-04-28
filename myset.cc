// Copyright 2025 Jake Sherer and Abby Holdcraft
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
  if (num_elements < 0)
    return;
  num_elements_ = num_elements;
  if (array_ != nullptr)
    delete [] array_;
  if (num_elements_ == 0) {
    array_ = nullptr;
    return;
  }
  array_ = new T[num_elements_];
  for (int i = 0; i < num_elements_; i++)
    array_[i] = array[i];
}

// Print the set in {1 2 ...} format
template<class T>
void MySet<T>::Print() const {
  cout << "{";
  for (int i=0; i < num_elements_; ++i) {
    cout << array_[i] << " ";
  }
  cout << "}" << endl;
}

// Return true if value is in set
template<class T>
bool MySet<T>::IsElementOf(T value) const {
  for (int i = 0; i < num_elements_; ++i) {
    if (array_[i] == value)
      return true;
  }
  return false;
}

// TODO
template<class T>
int MySet<T>::Cardinality() const {return 0;}

// Add value to the set if it is not present already
template<class T>
bool MySet<T>::AddElement(const T& toadd) {
  // Check if it exists
  if (IsElementOf(toadd))
    return false;

  // Create new array and add element to end
  T* temp = new T[num_elements_ + 1];
  for (int i = 0; i <num_elements_; ++i)
    temp[i] = array_[i];
  temp[num_elements_] = toadd;

  // Free memory
  delete[] array_;
  array_ = temp;
  ++num_elements_;
  return true;
}

// Remove value from set if it exists
template<class T>
bool MySet<T>::RemoveElement(const T& toremove) {
  // Check if it exists
  if (!IsElementOf(toremove))
    return false;

  // Create new array and copy over elements while skipping toremove
  T* temp = new T[num_elements_ - 1];
  int index = 0;
  for (int i = 0; i < num_elements_; ++i) {
    if (array_[i] != toremove)
      temp[index++] = array_[i];
  }

  // Free memory
  delete[] array_;
  array_ = temp;
  --num_elements_;
  return true;
}

// TODO: can you get instances of superset?
template<class T>
bool MySet<T>::IsSubsetOf(const SetInterface<T>& superset) {
  for (int i = 0; i < num_elements_; i++) {
    bool found = false;
    for (int j = 0; j < superset.num_elements_; j++) {
      if ( array_[i] == static_cast<const MySet<T>&>(superset).GetElement(i) ) {
        found = true;
        break;
      }
    }
    if (!found)
      return false;
  }
  return true;
}

template<class T>
bool MySet<T>::IsSupersetOf(const SetInterface<T>& subset) {
  return subset.IsElementOf(*this);
} 

// TODO: can you get instances of superset?
template<class T>
void MySet<T>::Intersection(const SetInterface<T>& set2) {
  MySet<T> newSet = new MySet();
  for (int i = 0; i < num_elements_; i++) {
    for (int j = 0; j < set2.num_elements_; j++) {
      if (array_[i] == set2.array_[j]) {
        newSet.AddElement(set2.array_[j]);
      }
    }
  }
  SetElements(newSet.array_, newSet.num_elements_);
}

// Sort the set in ascending order using insertion sort
template<class T>
void MySet<T>::SortAscending() {
  for (int i = 0; i < num_elements_; ++i) {
    T key = array_[i];
    int j = i - 1;
    while (j >= 0 && array_[j] > key) {
      array_[j + 1] = array_[j];
      --j;
    }
    array_[j + 1] = key;
  }
}
// Sort the set in descending order using insertion sort
template<class T>
void MySet<T>::SortDescending() {
  for (int i = 1; i < num_elements_; ++i) {
    T key = array_[i];
    int j = i - 1;
    while (j >= 0 && array_[j] < key) {
      array_[j + 1] = array_[j];
      --j;
    }
    array_[j + 1] = key;
  }
}

template<class T>
void MySet<T>::RemoveDuplicates() {
  MySet<T> newSet = new MySet();
  for (int i = 0; i < num_elements_; i++) {
    if (!newSet.IsElementOf(array_[i]))
      newSet.AddElement(array_[i]);
  }
  SetElements(newSet.array_, newSet.num_elements_);
}

template<class T>
MySet<T>& MySet<T>::Concat(const SetInterface<T>& set2, bool includeDuplicates) {
  int new_size = num_elements_;
  // Get number of new elements as new_size
  for (int i = 0; i < set2.Cardinality(); ++i) {
    T temp = static_cast<const MySet<T>&>(set2).GetElement(i);
    if (includeDuplicates || !IsElementOf(temp)) {
      ++new_size;
    }
  }
  T* new_array = new T[new_size];
  int index = 0;
  // Copy current elements
  for (int i = 0;i < num_elements_; ++i) {
    new_array[index] = array_[i];
    index++;
  }
  // Copy new elements
  for (int i = 0; i < set2.Cardinality(); ++i) {
    T temp = static_cast<const MySet<T>&>(set2).GetElement(i);
    if(includeDuplicates || !IsElementOf(temp)) {
      new_array[index] = temp;
      index++;
    }
  }
  // Free memory
  delete[] array_;
  array_ = new_array;
  num_elements_ = index;
  return *this;
}

template<class T>
T MySet<T>::GetElement(int index) const {
  if (index >= 0 && index < num_elements_) {
    return array_[index];
  }
}

template<class T>
MySet<T>& MySet<T>::operator = (const MySet& tocopy) {
  SetElements(tocopy.array_, tocopy.num_elements_);
}

// template<class T>
// MySet<T>& operator + (const MySet<T>& toadd) {}

template<class T>
MySet<T>& MySet<T>::operator - (const MySet<T>& tosub) {
  if ( IsSupersetOf(tosub) ) {
    MySet<T> newSet = new MySet(nullptr, num_elements_ - tosub.num_elements_);
    int index = 0;
    for (int i = 0; i < num_elements_; i++) {
      if (!tosub.IsElementOf(array_[i])) {
        newSet.array_[index++] = array_[i];
      }
    }
  } else {
    cout << "Cannot subtract! Second set is not a subset of first set." << endl;
  }
}

template<class T>
bool MySet<T>::operator == (const MySet<T>& other) {
  if (num_elements_ == other.num_elements_) {
    for (int i = 0; i < num_elements_; i++) {
      if (array_[i] != other.array_[i])
        return false;
    }
    return true;
  }
  return false;
}

template<class U>
ostream& operator << (ostream& where_to, const MySet<U>& mySet) {
  mySet->Print();
  return where_to;
}

}  // end namespace csce240h_exam3
