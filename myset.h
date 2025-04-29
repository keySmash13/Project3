// Copyright 2025 Adrian Holdcraft
#ifndef MYSET_H_
#define MYSET_H_

#include<iostream>
using std::ostream;
#include"setinterface.h"

template<class T>
class MySet : public SetInterface<T> {
 public:
  explicit MySet(T * array = nullptr, int num_elements_ = 1);
  void SetElements(T * array = nullptr, int num_elements = 0);
  T GetElement(int index) const;
  int GetNumElements() const {return num_elements_;}
  MySet(const MySet<T>& tocopy);
  ~MySet();
  void SortAscending();
  void SortDescending();
  void RemoveDuplicates();
  MySet<T>& Concat(const SetInterface<T>& set2, bool includeDuplicates = true);  // Return *this at end
  MySet<T>& operator = (const MySet<T>& tocopy);
  // MySet<T>& operator + (const MySet<T>& toadd);
  MySet<T>& operator += (const MySet<T>& toadd) { return Concat(toadd); }
  MySet<T>& operator - (const MySet<T>& tosub); // Only works if set2 isSubSetOf set1
  MySet<T>& operator -= (const MySet<T>& tosub) { return *this = *this - tosub; }
  bool operator == (const MySet<T>& other);
  bool operator != (const MySet<T>& other) { return !( *this == other ); }

// Interface functions
  void Print() const override;
  bool IsElementOf(T value) const override;
  int Cardinality() const override;
  bool AddElement(const T&) override;
  bool RemoveElement(const T&) override;
  bool IsSubsetOf(const SetInterface<T>& superset) override;
  bool IsSupersetOf(const SetInterface<T>& subset) override;
  void Intersection(const SetInterface<T>& set2) override;

 private:
 T * array_;
 int num_elements_;

};

#endif  // MYSET_H_
