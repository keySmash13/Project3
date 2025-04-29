// Holdcraft
#ifndef _SETINTERFACE_H_
#define _SETINTERFACE_H_

namespace csce240h_exam3 {

template<class T>
class SetInterface {
 public:
  virtual void Print() const = 0;
  virtual bool IsElementOf(T value) const = 0;
  virtual int Cardinality() const = 0;
  virtual bool AddElement(const T&) = 0;
  virtual bool RemoveElement(const T&) = 0;
  virtual bool IsSubsetOf(const SetInterface<T>& superset) = 0;
  virtual bool IsSupersetOf(const SetInterface<T>& subset) = 0;
  virtual void Intersection(const SetInterface<T>& set2) = 0;
};

}  // end namespace csce240h_exam3

#endif  // _SETINTERFACE_H_
