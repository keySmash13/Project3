// Adrian
#include"myset.h"
#include"myset.cc"
#include<iostream>
#include<string>
using std::string;

int main() {
  cout << "    Constructor tests:" << endl
    << "Default integer set:" << endl;
//  SetInterface<int> * default_int_set = new MySet<int>();
//  MySet<int> default_int_set();
//  default_int_set->Print();

  cout << "Parameterized integer set:" << endl;
  int int_array[4] = {1,2,3,4};
  MySet<int> int_set(int_array, 4);
  int_set.Print();
  cout << "Parameterized character set:" << endl;
  char char_array[10] =
    {'a','b','c','d','e','f','g','h','i','j'};
  MySet<char> char_set(char_array, 10);
  char_set.Print();
  cout << "Parameterized string set:" << endl;
  string string_array[5] = {"This", "Is", "A", "String", "Set"};
  MySet<string> string_set(string_array, 5);
  string_set.Print();

  cout << endl << "    IsElementOf tests:" << endl;
  cout << "Integer set:" << endl;
  cout << "Param = 1, Expected true (1): "
    << int_set.IsElementOf(1) << endl;
  cout << "Param = -5, Expected false (0): "
    << int_set.IsElementOf(-5) << endl;
  cout << "Character set:" << endl;
  cout << "Param = 'a', Expected true (1): ";
  cout << char_set.IsElementOf('a') << endl;
  cout << "Param = 'x', Expected false (0): "
    << char_set.IsElementOf('x') << endl;

  cout << endl << "    Cardinality tests:" << endl;
  cout << "Integer set Cardinality, expected 4: "
    << int_set.Cardinality() << endl;
  cout << "Character set Cardinality, expected 10: "
    << char_set.Cardinality() << endl;
  cout << "Creating int set with duplicates:" << endl;
  int duplicate_int_array[7] = {1,2,3,4,1,2,3};
  MySet<int> duplicate_int_set(duplicate_int_array, 7);
  duplicate_int_set.Print();
  cout << "Creating char set with duplicates:" << endl;
  char duplicate_char_array[17] =
    {'a','a','a','a','a','a','j',
      'a','b','c','d','e','f','g','h','i','j'};
  MySet<char> duplicate_char_set(duplicate_char_array, 17);
  duplicate_char_set.Print();
  cout << "Duplicate Integer set Cardinality, expected 4: "
    << duplicate_int_set.Cardinality() << endl;
  cout << "Duplicate Character set Cardinality, expected 10: "
    << duplicate_char_set.Cardinality() << endl;

  cout << endl << "    AddElement tests:" << endl;
  cout << "Adding elements to string set:" << endl;
  string_set.AddElement("And");
  string_set.AddElement("Now");
  string_set.AddElement("It's");
  string_set.AddElement("Longer");
  string_set.Print();

  cout << endl << "    Copying tests:" << endl;
  cout << "Copying longer string set:" << endl;
  MySet copy_string_set(string_set);
  copy_string_set.Print();

  cout << endl << "    RemoveElement tests:" << endl;
  cout << "Removing elements from string set:" << endl;
  string_set.RemoveElement("And");
  string_set.RemoveElement("Now");
  string_set.RemoveElement("It's");
  string_set.RemoveElement("Longer");
  string_set.Print();

  cout << "Printing copy string set:" << endl;
  copy_string_set.Print();

  cout << endl << "    IsSubsetOf tests:" << endl;
  cout << "Int set 1:";
  int_set.Print();
  cout << "Int set 2:";
  duplicate_int_set.Print();
  cout << "set1.IsSubsetOf(set2) test, expected true (1): "
  << int_set.IsSubsetOf(duplicate_int_set) << endl;
  cout << "Char set 1:";
  char_set.Print();
  cout << "Char set 2:";
  duplicate_char_set.Print();
  cout << "set1.IsSubsetOf(set2) test, expected true (1): "
  << char_set.IsSubsetOf(duplicate_char_set) << endl;
  cout << "String set 1:";
  string_set.Print();
  cout << "String set 2:";
  copy_string_set.Print();
  cout << "set1.IsSubsetOf(set2) test, expected true (1): "
  << char_set.IsSubsetOf(duplicate_char_set) << endl;

  cout << endl << "    IsSupersetOf tests:" << endl;
//TODO

  return 0;
}
