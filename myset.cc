// Adrian
#include "myset.h"
#include <iostream>
using std::ostream;
#include<string>
using std::string;
using std::cout;
using std::endl;

namespace csce240h_exam3 {

// Constructor
template<class T>
MySet<T>::MySet(T* array, int num_elements) {
  SetElements(array, num_elements);
}

// Copy Constructor
template<class T>
MySet<T>::MySet(const MySet<T>& tocopy) {
  SetElements(tocopy.array_, tocopy.num_elements_);
}

// Destructor
template<class T>
MySet<T>::~MySet() {
  delete [] array_;
}

// Sets array and number of elements to parameters
template<class T>
void MySet<T>::SetElements(T * array, int num_elements) {
  if (num_elements < 0)
    return;
  num_elements_ = num_elements;
  if (array_ != nullptr)
    delete [] array_;
  if (num_elements_ == 0) {
    return;
  }
  array_ = new T[num_elements_];
  for (int i = 0; i < num_elements_; i++)
    array_[i] = array[i];
}

// Prints object
template<class T>
void MySet<T>::Print() const {
  cout << '{';
  if (num_elements_ != 0)
    cout << array_[0];
  for (int i = 1; i < num_elements_; i++) {
    cout << ' ' << array_[i];
  }
  cout << '}' << endl;
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

// Gets element at parameterized index
template<class T>
T MySet<T>::GetElement(int index) const {
  if (index >= 0 && index < num_elements_) {
    return array_[index];
  }
  return T{};
}

// Return the number of unique elements in a set
template<class T>
int MySet<T>::Cardinality() const {
  T seen[num_elements_];
  int num_seen = 1;
  seen[0] = array_[0];
  for (int i = 1; i < num_elements_; ++i) {
    seen[num_seen++] = array_[i];
    for (int j = 0; j < num_seen-1; ++j) {
      if (seen[j] == array_[i]) {
        --num_seen;
        j = num_seen;
      }
    }
  }
  return num_seen;
}

// Add value to the set if it is not present already
template<class T>
bool MySet<T>::AddElement(const T& toadd) {
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

// Checks if object is a subset of parameterized set
template<class T>
bool MySet<T>::IsSubsetOf(const SetInterface<T>& superset) {
  for (int i = 0; i < num_elements_; i++) {
    bool found = false;
    for (int j = 0;
         j < static_cast<const MySet<T>&>(superset).GetNumElements();
         j++) {
      if ( array_[i] ==
           static_cast<const MySet<T>&>(superset).GetElement(j) ) {
        found = true;
        break;
      }
    }
    if (!found)
      return false;
  }
  return true;
}

// Checks if object is a superset of parameterized set
template<class T>
bool MySet<T>::IsSupersetOf(const SetInterface<T>& subset) {
  for (int i = 0;
    i < static_cast<const MySet<T>&>(subset).GetNumElements();
    i++) {
    bool found = false;
    for (int j = 0; j < num_elements_; j++) {
      if ( array_[j] ==
           static_cast<const MySet<T>&>(subset).GetElement(i) ) {
        found = true;
        break;
      }
    }
    if (!found)
      return false;
  }
  return true;
}

// Makes set into the intersection of the object and parameter's sets
template<class T>
void MySet<T>::Intersection(const SetInterface<T>& set2) {
  MySet<T> newSet;
  for (int i = 0; i < num_elements_; i++) {
    for (int j = 0;
         j < static_cast<const MySet<T>&>(set2).GetNumElements();
         j++) {
      if (array_[i] ==
          static_cast<const MySet<T>&>(set2).GetElement(j)) {
        newSet.AddElement
          (static_cast<const MySet<T>&>(set2).GetElement(j));
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

}  // end namespace csce240h_exam3

