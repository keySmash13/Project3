// Copyright 2025 Jake Sherer and Abby Holdcraft
#ifndef MYSET_H_
#define MYSET_H_

#include"setinterface.h"
#include<iostream>
using std::ostream;

namespace csce240h_exam3 {

template<class T>
class MySet : public SetInterface<T> {
 private:
  T * array_;
  int num_elements_;

 public:
  // VIRTUAL FUNCTIONS
  void Print() const override;
  bool IsElementOf(T value) const override; 
  int Cardinality() const override; 
  bool AddElement(const T&) override; 
  bool RemoveElement(const T&) override; 
  bool IsSubsetOf(const SetInterface<T>& superset) override; 
  bool IsSupersetOf(const SetInterface<T>& subset) override; 
  void Intersection(const SetInterface<T>& set2) override; 

  // ADDED FUNCTIONALITY
  explicit MySet(T* array = nullptr, int num_elements = 0);
  MySet(const MySet<T>& tocopy);
  ~MySet();
  void SetElements(T * array = nullptr, int num_elements = 0) const;
  void SortAscending();
  void SortDescending();
  void RemoveDuplicates();
  MySet<T>& Concat(const SetInterface<T>& set2, bool includeDuplicates = true);  // Return *this at end
  void GetElement(int index, T& output) const;
  MySet<T>& operator = (const MySet<T>& tocopy);
  // MySet<T>& operator + (const MySet<T>& toadd);
  MySet<T>& operator += (const MySet<T>& toadd) { return Concat(toadd); }
  MySet<T>& operator - (const MySet<T>& tosub); // Only works if set2 isSubSetOf set1 
  MySet<T>& operator -= (const MySet<T>& tosub) { *this = *this - *tosub; }
  bool operator == (const MySet<T>& other);
  bool operator != (const MySet<T>& other) { return !( *this == other ); }
  friend ostream& operator << (ostream& where_to, const MySet<T>& mySet);
}; // end class MySet

}  // end namespace csce240h_exam3

#endif  // MYSET_H_