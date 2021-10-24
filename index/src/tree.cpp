#include "../include/tree.hpp"

void Tree::insert(std::string &key, std::vector<uint32_t> value) {
    TreeNode *newNode = new TreeNode(key, value);
    if (this->root == nullptr) {
        this->root = newNode;
        return;
    }

    TreeNode *parent, *child = this->root;

    uint8_t dir;

    while (child != nullptr) {
        parent = child;
        if (parent->key.compare(key) > 0) {
            child = parent->right;
            dir = RIGHT;
        } else {
            child = parent->left;
            dir = LEFT;
        }
    }

    newNode->parentNode = parent;

    parent->child[dir] = newNode;

    TreeNode *grandparent, *uncle;

    do {
        if (parent->color == Black)
            return;

        grandparent = parent->parentNode;
        if (grandparent == nullptr) {
            parent->color = Black;
            return;
        }

        dir = parent->dir();
        uncle = grandparent->child[1 - dir];

        if (uncle == nullptr || uncle->color == Black) {
            if (newNode == parent->child[1 - dir]) {
                this->rotate(parent, dir);
                newNode = parent;
                parent = grandparent->child[dir];
            }

            this->rotate(grandparent, 1 - dir);
            parent->color = Black;
            grandparent->color = Red;
            return;
        }

        parent->color = Black;
        uncle->color = Black;
        grandparent->color = Black;

        newNode = grandparent;

        parent = newNode->parentNode;

    } while (parent != nullptr);
}

void Tree::rotate(TreeNode *subroot, uint8_t dir) {
    TreeNode *subrootParent = subroot->parentNode,
             *pivot = subroot->child[1 - dir],
             *innerChild = nullptr;

    innerChild = pivot->child[dir];
    subroot->child[1 - dir] = innerChild;

    if (innerChild != nullptr) {
        innerChild->parentNode = subroot;
    }

    pivot->child[dir] = subroot;
    subroot->parentNode = pivot;

    pivot->parentNode = subrootParent;

    if (subrootParent != nullptr) {
        subrootParent->child[subroot == subrootParent->right ? RIGHT : LEFT] = pivot;
    } else {
        this->root = pivot;
    }
}