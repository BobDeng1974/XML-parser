#include "XML.h"

void printNodeTree(const XNode* ptr, unsigned int level)
{
    if(ptr == NULL) return;
    for(unsigned int i = 0; i < ptr->children.size(); i ++)
    {
        for(unsigned int s = 0; s < level; s++) printf("_");
        ptr->children.at(i).print();
        printNodeTree(&ptr->children.at(i), level + 1);
    }
}

int main()
{
    const XNode* root = XFILE("/Users/Jas/AndroidStudioProjects/MyApplication/app/src/main/assets/models/Bear.dae").getRoot();
    printNodeTree(root, 0);

    printf("Search for node COLLADA:\n");
    root->findNode("COLLADA")->print();

    // collada-node test:
    root->findNodeByAttribute("node", "id", NULL)->print();
    printf("\n\n\n\n\n\n\n\n");
    printNodeTree(root->findNodeByAttribute("node", "id", "Armature"), 0);

    delete root;
    return 0;
}
