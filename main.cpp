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
    root->getNode("COLLADA").print();

    // collada-node test:
    root->getNodeByAttribute("node", "id", NULL).print();
    printf("\n\n\n\n\n\n\n\n");
    printNodeTree(&root->getNodeByAttribute("node", "id", "Armature"), 0);

    printf("\n");
    printf("%s\n", root->getNode("library_effects").children[0].getAttribute("id").value.c_str());
    printf("%s\n", root->getNode("library_effects").children[0].getNode("diffuse").getNode("color").value.c_str());

    std::vector<float> array = root->getNode("library_effects").children[0].getNode("diffuse").getNode("color").value.toFloatVector();
    for(unsigned int i = 0; i < array.size(); i++)
        printf("%f ", array[i]);
    printf("\n");


    std::vector<int> i_array = root->getNode("library_animations").getNodeByAttribute("source", "id", "Armature_Bone_pose_matrix-output").getChild("float_array").value.toIntegerVector();
    for(unsigned int i = 0; i < i_array.size(); i++)
        printf("%i ", i_array[i]);
    printf("\n");

    delete root;
    return 0;
}
