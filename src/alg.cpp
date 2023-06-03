// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
    BST<std::string> tree;
  std::ifstream file(filename);
  std::string word;
  while (!file.eof()) {
    char c = file.get();
    if (c >= 'A' && c <= 'Z')
        c = c + ('a' - 'A');
    if (c >= 'a' && c <= 'z') {
      word += c;
    } else {
      tree.Add(word);
      word.clear();
    }
  }
  return tree;
}
