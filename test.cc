// Copyright 2025 Jake Sherer and Abby Holdcraft
#include<iostream>
#include<string>
using std::string;
#include"myset.h"
#include"myset.cc"
using csce240h_exam3::SetInterface;
using csce240h_exam3::MySet;

int main() {
  cout << "    Constructor tests:" << endl
    << "Default integer set:" << endl;
  MySet<int>* default_int = new MySet<int>(nullptr, 0);
  default_int->Print();

  cout << "Parameterized integer set - Expected {1 2 3 4}" << endl;
  int int_array[4] = {1, 2, 3, 4};
  MySet<int>* int_set = new MySet<int>(int_array, 4);
  int_set->Print();
  cout << "Parameterized character set - Expected {a b c d e f g h i j}" << endl;
  char char_array[10] =
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  MySet<char>* char_set = new MySet<char>(char_array, 10);
  char_set->Print();
  cout << "Parameterized string set - Expected {This Is A String Set}" << endl;
  string string_array[5] = {"This", "Is", "A", "String", "Set"};
  MySet<string>* string_set = new MySet<string>(string_array, 5);
  string_set->Print();

  cout << endl << "    IsElementOf tests:" << endl;
  cout << "Integer set:" << endl;
  cout << "Param = 1 - Expected true (1): "
    << int_set->IsElementOf(1) << endl;
  cout << "Param = -5 - Expected false (0): "
    << int_set->IsElementOf(-5) << endl;
  cout << "Character set:" << endl;
  cout << "Param = 'a' - Expected true (1): ";
  cout << char_set->IsElementOf('a') << endl;
  cout << "Param = 'x' - Expected false (0): "
    << char_set->IsElementOf('x') << endl;

  cout << endl << "    Cardinality tests:" << endl;
  cout << "Integer set Cardinality - Expected 4: "
    << int_set->Cardinality() << endl;
  cout << "Character set Cardinality - Expected 10: "
    << char_set->Cardinality() << endl;
  cout << "Creating int set with duplicates - Expected {1 2 3 4 1 2 3}" << endl;
  int duplicate_int_array[7] = {1, 2, 3, 4, 1, 2, 3};
  MySet<int>* duplicate_int_set = new MySet<int>(duplicate_int_array, 7);
  duplicate_int_set->Print();
  cout << "Creating char set with duplicates - Expected {a a a a a a j a b c d e f g h i j}" << endl;
  char duplicate_char_array[17] =
    {'a', 'a', 'a', 'a', 'a', 'a', 'j',
      'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  MySet<char>* duplicate_char_set = new MySet<char>(duplicate_char_array, 17);
  duplicate_char_set->Print();
  cout << "Duplicate Integer set Cardinality - Expected 4: "
    << duplicate_int_set->Cardinality() << endl;
  cout << "Duplicate Character set Cardinality - Expected 10: "
    << duplicate_char_set->Cardinality() << endl;

  cout << endl << "    AddElement tests:" << endl;
  cout << "Adding elements to string set - Expected {This Is A String Set And Now It's Longer}" << endl;
  string_set->AddElement("And");
  string_set->AddElement("Now");
  string_set->AddElement("It's");
  string_set->AddElement("Longer");
  string_set->Print();

  cout << endl << "    Copying tests:" << endl;
  cout << "Copying longer string set:" << endl;
  MySet<string>* copy_string_set = new MySet<string>(*string_set);
  copy_string_set->Print();

  cout << endl << "    RemoveElement tests:" << endl;
  cout << "Removing elements from string set - Expected {This Is A String Set}" << endl;
  string_set->RemoveElement("And");
  string_set->RemoveElement("Now");
  string_set->RemoveElement("It's");
  string_set->RemoveElement("Longer");
  string_set->Print();

  cout << "Printing copy string set:" << endl;
  copy_string_set->Print();

  cout << endl << "    IsSubsetOf/IsSupersetOf tests:" << endl;
  cout << "Int set 1:";
  int_set->Print();
  cout << "Int set 2:";
  duplicate_int_set->Print();
  cout << "set1.IsSubsetOf(set2) test - Expected true (1): "
  << int_set->IsSubsetOf(*duplicate_int_set) << endl;
  cout << "set2.IsSupersetOf(set1) test - Expected true (1): "
  << duplicate_int_set->IsSupersetOf(*int_set) << endl;
  cout << "Char set 1:";
  char_set->Print();
  cout << "Char set 2:";
  duplicate_char_set->Print();
  cout << "set1.IsSubsetOf(set2) test - Expected true (1): "
  << char_set->IsSubsetOf(*duplicate_char_set) << endl;
  cout << "set2.IsSupersetOf(set1) test - Expected true (1): "
  << duplicate_char_set->IsSupersetOf(*char_set) << endl;
  cout << "String set 1:";
  string_set->Print();
  cout << "String set 2:";
  copy_string_set->Print();
  cout << "set1.IsSubsetOf(set2) test - Expected true (1): "
  << char_set->IsSubsetOf(*duplicate_char_set) << endl;
  cout << "set2.IsSupersetOf(set1) test - Expected true (1): "
  << copy_string_set->IsSupersetOf(*string_set) << endl;

  cout << endl << "    RemoveDuplicate tests:" << endl;
  cout << "Removing duplicates from character set:" << endl << "Initial: ";
  duplicate_char_set->Print();
  duplicate_char_set->RemoveDuplicates();
  cout << "Final: ";
  duplicate_char_set->Print();
  cout << "Expected: {a j b c d e f g h i}" << endl;

  // bool = true, bool = false
  cout << endl << "    Concat tests:" << endl;
  cout << "Concatting character sets, including duplicate values:" << endl
  << "Set 1:";
  duplicate_char_set->Print();
  cout << "Set 2: ";
  char_set->Print();
  duplicate_char_set->Concat(*char_set);
  cout << "Concatenated: ";
  duplicate_char_set->Print();
  cout << "Expected: {a j b c d e f g h i a b c d e f g h i j}" << endl;
  cout << "Concatting string sets, ignoring duplicate values:" << endl
  << "Set 1:";
  string_set->AddElement("Nice!");
  string_set->Print();
  cout << "Set 2: ";
  copy_string_set->Print();
  string_set->Concat(*copy_string_set, false);
  cout << "Concatenated: ";
  string_set->Print();
  cout << "Expected: {This Is A String Set Nice! And Now It's Longer}" << endl;

  // = == != += -= -
  cout << endl << "    Operator tests:" << endl;
  // =
  cout << "Testing assignment operator:" << endl << "Original set: ";
  int_set->Print();
  cout << "Assigning original set to new set - Expected {1 2 3 4}" << endl;
  MySet<int>* assigned_int_set = new MySet<int>(nullptr, 0);
  *assigned_int_set = *int_set;
  assigned_int_set->Print();
  // ==
  cout << "Testing == operator - Expected true (1): "
  << (*int_set == *assigned_int_set) << endl;
  // !=
  cout << "Testing != operator - Expected false (0): "
  << (*int_set != *assigned_int_set) << endl;
  // +=
  cout << "Testing += operator - Expected {1 2 3 4 1 2 3 4}" << endl;
  *int_set += *assigned_int_set;
  int_set->Print();
  // -=
  cout << "Testing -= operator - Expected {1 2 3 4}" << endl;
  *int_set -= *assigned_int_set;
  int_set->Print();
  // -
  cout << "Testing - operator - Expected {}:" << endl;
  *int_set = *int_set - *assigned_int_set;
  int_set->Print();

  cout << endl << "    Intersection tests:" << endl;
  string string_array_1[5] = {"This", "cool", "new", "String", "Set"};
  MySet<string>* string_set_1 = new MySet<string>(string_array_1, 5);
  string string_array_2[4] = {"new", "different", "String", "Set"};
  MySet<string>* string_set_2 = new MySet<string>(string_array_2, 4);
  string_set_1->Print();
  string_set_2->Print();

  cout << "Creating Intersection - Expected {new String Set}" << endl;
  string_set_1->Intersection(*string_set_2);
  string_set_1->Print();

  cout << endl << "    Sorting tests:" << endl;
  // Integer sorting test
  int unsorted_ints[6] = {9, 1, 7, 3, 5, 2};
  MySet<int>* sortable_int_set = new MySet<int>(unsorted_ints, 6);
  cout << "Original int set:" << endl;
  sortable_int_set->Print();

  cout << "After SortAscending() — Expected: 1, 2, 3, 5, 7, 9" << endl;
  sortable_int_set->SortAscending();
  sortable_int_set->Print();

  cout << "After SortDescending() — Expected: 9, 7, 5, 3, 2, 1" << endl;
  sortable_int_set->SortDescending();
  sortable_int_set->Print();

  // Character sorting test
  char unsorted_chars[7] = {'z', 'a', 't', 'b', 'm', 'y', 'e'};
  MySet<char>* sortable_char_set = new MySet<char>(unsorted_chars, 7);
  cout << "Original char set:" << endl;
  sortable_char_set->Print();

  cout << "After SortAscending() — Expected: a, b, e, m, t, y, z" << endl;
  sortable_char_set->SortAscending();
  sortable_char_set->Print();

  cout << "After SortDescending() — Expected: z, y, t, m, e, b, a" << endl;
  sortable_char_set->SortDescending();
  sortable_char_set->Print();
  return 0;
}
