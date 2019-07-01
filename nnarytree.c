#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include "nnarytree.h"

Node ROOT = NULL;
char *ROOTNAME = "ROOT";

// Node ROOT = NULL;
// char *TREENAME = "ROOT";
// #define COUNT 1

Node createNode(char *name)
{
    Node node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->parent = NULL;
    node->child = NULL;
    node->previous = NULL;
    node->next = NULL;
    return node;
}

// void storeNode(Node node, char *name)
// {
//     //Create ROOT of binary tree
//     if(ROOT == NULL)
//     {
//         ROOT = createNode(TREENAME);
//         node = ROOT;
//     }

//     //fill in the nodes inside the tree
//     if(strcmp(name, node->name) == -1)
//         if(node->left == NULL)
//             node->left = createNode(name);
//         else
//             storeNode(node->left, name);
//     else if(strcmp(name, node->name) == 1)
//         if(node->right == NULL)
//             node->right = createNode(name);
//         else
//             storeNode(node->right, name);
// }

int main(void)
{
    printf("before node creation\n");
    Node root = createNode(ROOTNAME);
    printf("%s\n", root->name);
    printf("after node creation\n");

    DIR *d;
    struct dirent *dir;
    d = opendir("C:/Users/Robert/Desktop/Directory For Nnary Tree");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return(0);
}