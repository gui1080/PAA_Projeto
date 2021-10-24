#include "../include/tree.hpp"

std::vector<uint32_t> *Tree::getValue(std::string &key) {
    if (this->root == nullptr) {
        return nullptr;
    }

    TreeNode *curNode = this->root;
    int32_t stringDiff;

    do {
        stringDiff = curNode->key.compare(key);
        if (stringDiff > 0) {
            curNode = curNode->right;
        } else if (stringDiff < 0) {
            curNode = curNode->left;
        }

        if (curNode == nullptr) {
            return nullptr;
        }
    } while (stringDiff != 0);

    return &(curNode->indexList);
}

void Tree::insert(std::string &key, uint32_t value) {
    if (this->root == nullptr) {
        this->root = new TreeNode(key, value);
        return;
    }

    TreeNode *parent, *child = this->root;

    uint8_t dir;

    while (child != nullptr) {
        parent = child;
        int32_t stringDiff = parent->key.compare(key);

        if (stringDiff > 0) {
            child = parent->right;
            dir = RIGHT;
        } else if (stringDiff < 0) {
            child = parent->left;
            dir = LEFT;
        } else {
            if (parent->indexList.back() != value) {
                parent->indexList.push_back(value);
            }
            return;
        }
    }

    TreeNode *newNode = new TreeNode(key, value);

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
        grandparent->color = Red;

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