// Copyright 2025 Jake Sherer and Abby Holdcraft
#include"myset.h"
#include"myset.cc"
#include<iostream>
#include<string>
using std::string;
using csce240h_exam3::SetInterface;
using csce240h_exam3::MySet;

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

  cout << endl << "    IsSubsetOf/IsSupersetOf tests:" << endl;
  cout << "Int set 1:";
  int_set.Print();
  cout << "Int set 2:";
  duplicate_int_set.Print();
  cout << "set1.IsSubsetOf(set2) test, expected true (1): "
  << int_set.IsSubsetOf(duplicate_int_set) << endl;
  cout << "set2.IsSupersetOf(set1) test, expected true (1): "
  << duplicate_int_set.IsSupersetOf(int_set) << endl;
  cout << "Char set 1:";
  char_set.Print();
  cout << "Char set 2:";
  duplicate_char_set.Print();
  cout << "set1.IsSubsetOf(set2) test, expected true (1): "
  << char_set.IsSubsetOf(duplicate_char_set) << endl;
  cout << "set2.IsSupersetOf(set1) test, expected true (1): "
  << duplicate_char_set.IsSupersetOf(char_set) << endl;
  cout << "String set 1:";
  string_set.Print();
  cout << "String set 2:";
  copy_string_set.Print();
  cout << "set1.IsSubsetOf(set2) test, expected true (1): "
  << char_set.IsSubsetOf(duplicate_char_set) << endl;
  cout << "set2.IsSupersetOf(set1) test, expected true (1): "
  << copy_string_set.IsSupersetOf(string_set) << endl;

  cout << endl << "    RemoveDuplicate tests:" << endl;
  cout << "Removing duplicates from character set:" << endl << "Initial: ";
  duplicate_char_set.Print();
  duplicate_char_set.RemoveDuplicates();
  cout << "Final: ";
  duplicate_char_set.Print();

  // bool = true, bool = false
  cout << endl << "    Concat tests:" << endl;
  cout << "Concatting character sets, including duplicate values:" << endl << "Set 1:";
  duplicate_char_set.Print();
  cout << "Set 2: ";
  char_set.Print();
  duplicate_char_set.Concat(char_set);
  cout << "Concatenated: ";
  duplicate_char_set.Print();
  cout << "Concatting string sets, ignoring duplicate values:" << endl << "Set 1:";
  string_set.Print();
  cout << "Set 2: ";
  copy_string_set.Print();
  string_set.Concat(copy_string_set, false);
  cout << "Concatenated: ";
  string_set.Print();

  // = == != += -= -
  cout << endl << "    Operator tests:" << endl;
  // =
  cout << "Testing assignment operator:" << endl << "Original set: ";
  int_set.Print();
  cout << "Assigning original set to new set:" << endl;
  MySet<int> assigned_int_set;
  assigned_int_set = int_set;
  assigned_int_set.Print();
  // ==
  cout << "Testing == operator, expected true (1): "
  << (int_set == assigned_int_set) << endl;
  // !=
  cout << "Testing != operator, expected false (0): "
  << (int_set != assigned_int_set) << endl;
  // +=
  cout << "Testing += operator:" << endl;
  int_set += assigned_int_set;
  int_set.Print();
  // -=
  cout << "Testing -= operator:" << endl;
  int_set -= assigned_int_set;
  int_set.Print();
  // -
  cout << "Testing - operator, expected {}:" << endl;
  int_set = int_set - assigned_int_set;
  int_set.Print();

  cout << endl << "    Intersection tests:" << endl;
  string str_arr_1[7] = {"I", "just", "made", "a", "new", "string", "set"};
  MySet<string> str_set_1(str_arr_1, 7);
  str_set_1.Print();
  string str_arr_2[8] = {"And", "this", "string", "set", "is", "a", "different", "set"};
  MySet<string> str_set_2(str_arr_2, 8);
  str_set_1.Print();
  cout << "Creating Intersection:" << endl;
  str_set_1.Intersection(str_set_2);
  str_set_1.Print();

  // TODO
  cout << endl << "    Sort tests:" << endl;  // Ascending and Descending
  
  return 0;
}
