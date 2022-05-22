#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Node.h"
#include "SHA256.h"
#include "misc.h"

struct MerkleTree {
    Node* root;
    MerkleTree(std::vector<Node*> blocks);
    ~MerkleTree();
    void printTree(Node* n, int indent);
    void deleteTree(Node* n);
};