#ifndef TREE_INCLUDE_H
#define TREE_INCLUDE_H

#include <cstdint>
#include <string>
#include <vector>

enum Color {
  Black, Red
};

class TreeNode {
public:
  TreeNode *parentNode,
          *leftNode,
          *rightNode;

  std::vector<uint32_t> indexList;

  Color color;
};

class Tree {
  TreeNode *root;

public:
  void insert(std::vector<uint32_t>);

  std::vector<uint32_t> *getValue(std::string &);
};

#endif  // TREE_INCLUDE_H