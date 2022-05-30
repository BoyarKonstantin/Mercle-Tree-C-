#include <iostream>
#include "TreeStruct.h"
#include <string>

void MercleTree() {
    std::vector<Node*> leaves;
    //create sample data
    int CONTINUE;
    std::string HashString;
    /*
     Îáúÿâëÿåì áåñêîíå÷íûé öèêë êîòîðûé ïðè ââîäå "2" - çàâåðøàåò ïðîãðàììó è âûâîäèò äåðåâî,
     à ïðè "1" - ñîçäàåò íîâûé óçåë äåðåâà
    */
    for (;;) {
        std::cout << "What u want?"
            << std::endl
            << "1) add new Node" 
            << std::endl
            << "2) Output ur Mercle Tree" 
            << std::endl;
        std::cin >> CONTINUE;
        /*Åñëè CONTINUE != 1 or 2 - çàâåðøàåì ïðîãðàììó ñ ñîîáùåíèåì îá îøèáêå*/
        if (CONTINUE == 1 || CONTINUE == 2) {
            if (CONTINUE == 1) {
                std::cout << "Input ur node";
                std::cin >> HashString;
                // Äîáàâëÿåì óçåë äëÿ HashString
                leaves.push_back(new Node(hash_sha256(HashString)));

            }
            if (CONTINUE == 2) {
                //Àëãîðèòì âûâîäà äåðåâà è âûõîä èç öèêëà
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
