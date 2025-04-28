// Copyright 2025 csce240h
#include"setinterface.h"
#include"myset.h"
using std::cout;
using std::endl;

using csce240h_exam3::SetInterface;
using csce240h_exam3::MySet;

int main() {
  cout << "Testing SetInterface Methods:" << endl << endl;

  cout << "SET 1: Creating default set of type int:" << endl;
  SetInterface<int> * set_1 = new MySet<int>();
  set_1->Print();  // {}
  cout << endl;

  cout << "Adding 10 elements:" << endl;
  for (int i = 1; i <= 10; i++)
    set_1->AddElement(i);
  set_1->Print();  // {1 2 3 4 5 6 7 8 9 10}
  cout << endl;

  cout << "Does set 1 contain the number 10?" << endl;
  cout << set_1->IsElementOf(10);  // 1
  cout << endl;

  cout << "SET 2: Creating new int array:" << endl;
  int array[4] = {1,2,3,4};
  SetInterface<int> * set_2 = new MySet(array, 4);
  set_2->Print();  // {1 2 3 4}
  cout << endl;

  cout << "Is set 1 a subset of set 2?" << endl;
  cout << set_2->IsSubsetOf(*set_1) << endl;  // 1
  cout << endl;

  cout << "Is set 2 a superset of set 1?" << endl;
  cout << set_1->IsSupersetOf(*set_2) << endl;  // 1
  cout << endl;

  cout << "SET_3: Creating copy of set 1:" << endl;
  SetInterface<int> * set_3(set_1);
  set_3->Print();  // {1 2 3 4 5 6 7 8 9 10}
  cout << endl;

  cout << "Removing elements from set 1:" << endl;
  for (int i=10; i > 4; i--)
    set_1->RemoveElement(i);
  set_1->Print();  // {1 2 3 4}
  cout << endl;

  cout << "Adding duplicate elements to set 3:" << endl;
  for (int i = 0; i < 4; i++)
    set_3->AddElement(array[i]);  // {1 2 3 4 5 6 7 8 9 10 1 2 3 4}
  set_3->Print();
  cout << endl;
  
  cout << "How many unique elements are in set 3?" << endl;
  cout << set_3->Cardinality() << endl;  // 10
  cout << endl;
  
  return 0;
}
