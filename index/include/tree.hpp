#ifndef TREE_INCLUDE_H
#define TREE_INCLUDE_H

#include <cstdint>
#include <string>
#include <vector>

#define LEFT 0
#define RIGHT 1
#define left child[LEFT]
#define right child[RIGHT]

enum Color {
    Black,
    Red
};

class TreeNode {
   public:
    TreeNode(std::string _key, std::vector<uint32_t> value)
        : color(Red),
          key(_key),
          indexList(value),
          parentNode(nullptr) {}

    TreeNode *child[2] = {nullptr, nullptr}, *parentNode;

    std::string key;
    std::vector<uint32_t> indexList;

    Color color;

    inline uint8_t dir() {
        return this == parentNode->right ? RIGHT : LEFT;
    }
};

class Tree {
   private:
    TreeNode *root = nullptr;

    void rotate(TreeNode *pivot, uint8_t dir);

   public:
    void insert(std::string &key, std::vector<uint32_t> value);

    std::vector<uint32_t> *getValue(std::string &);
};

#endif  // TREE_INCLUDE_H