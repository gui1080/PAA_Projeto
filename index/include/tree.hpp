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
    TreeNode(std::string _key, uint32_t value)
        : color(Red),
          key(_key),
          parentNode(nullptr) {
        this->indexList = std::vector<uint32_t>{value};
    }

    TreeNode *child[2] = {nullptr, nullptr},
             *parentNode;

    std::string key;
    std::vector<uint32_t> indexList;

    Color color;

    inline uint8_t dir() {
        return this == parentNode->right ? RIGHT : LEFT;
    }

    inline void show(uint16_t level) {
        printf("%*s%s: %s :%d\n", level * 2, "`", this->color == Black ? "B" : "R", key.c_str(), indexList.size());

        level++;

        if (this->left != nullptr) {
            this->left->show(level);
        }

        if (this->right != nullptr) {
            this->right->show(level);
        }
    }
};

class Tree {
   private:
    TreeNode *root = nullptr;

    void rotate(TreeNode *pivot, uint8_t dir);

   public:
    void insert(std::string &key, uint32_t value);

    std::vector<uint32_t> *getValue(std::string);

    inline void show() {
        if (root == nullptr) {
            printf("-\n");
            return;
        }

        root->show(0);
    }
};

#endif  // TREE_INCLUDE_H