#include <iostream>
#include "TreeStruct.h"

int main() {
    std::vector<Node*> leaves;

    //create sample data
    leaves.push_back(new Node(hash_sha256("aksl;fjk;kla")));
    leaves.push_back(new Node(hash_sha256("1234")));
    leaves.push_back(new Node(hash_sha256("!@'kl;fmasl;kjkfl;askl;fkwqop;'fkqwl;'fko;E&")));
    leaves.push_back(new Node(hash_sha256("asnfklasjkl;fjmwqkl;fjqwkl;fjklwqjfilpwqjfioqwjfipqwjfiop")));

    // initialize leaves
    for (unsigned int i = 0; i < leaves.size(); i++) {
        leaves[i]->left = NULL;
        leaves[i]->right = NULL;
    }

    MerkleTree* hashTree = new MerkleTree(leaves);
    std::cout << hashTree->root->hash << std::endl;
    hashTree->printTree(hashTree->root, 0);

    for (unsigned int k = 0; k < leaves.size(); k++) {
        delete leaves[k];
    }

    delete hashTree;

    return 0;
}