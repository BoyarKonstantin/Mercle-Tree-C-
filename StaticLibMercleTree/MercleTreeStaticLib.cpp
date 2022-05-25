#include <iostream>
#include "../Mercle_tree_cour/TreeStruct.h"
#include "../Mercle_tree_cour/Node.h"
#include "../Mercle_tree_cour/misc.h"
#include"../Mercle_tree_cour/hashNode.h"
#include"../Mercle_tree_cour/Mercle_tree_cour.h"
#include <string>

void MercleTree() {
    std::vector<Node*> leaves;
    //create sample data
    int CONTINUE;
    std::string HashString;
    /*
     Объявляем бесконечный цикл который при вводе "2" - завершает программу и выводит дерево,
     а при "1" - создает новый узел дерева
    */
    for (;;) {
        std::cout << "What u want? "
            << std::endl
            << "1) add new Node "
            << std::endl
            << "2) Output ur Mercle Tree "
            << std::endl;
        std::cin >> CONTINUE;
        /*Если CONTINUE != 1 or 2 - завершаем программу с сообщением об ошибке*/
        if (CONTINUE == 1 || CONTINUE == 2) {
            if (CONTINUE == 1) {
                std::cout << "Input ur node ";
                std::cin >> HashString;
                // Добавляем узел для HashString
                leaves.push_back(new Node(hash_sha256(HashString)));

            }
            if (CONTINUE == 2) {
                //Алгоритм вывода дерева и выход из цикла
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
                break;
            }
        }
        else {
            std::cout << "Error variable not be corrected";
            break;
        }

    }

}
