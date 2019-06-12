#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    #define Node struct Node
    char *name;
    Node *left;
    Node *right;
};

Node *ROOT = NULL;
char *TREENAME = "ROOT";
#define COUNT 1

Node *createNode(char *name)
{
    Node *node = malloc(sizeof(Node));
    node->name = name;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void storeNode(Node *node, char *name)
{
    //Create ROOT of binary tree
    if(ROOT == NULL)
    {
        ROOT = createNode(TREENAME);
        node = ROOT;
    }

    //fill in the nodes inside the tree
    if(strcmp(name, node->name) == -1)
        if(node->left == NULL)
            node->left = createNode(name);
        else
            storeNode(node->left, name);
    else if(strcmp(name, node->name) == 1)
        if(node->right == NULL)
            node->right = createNode(name);
        else
            storeNode(node->right, name);

}

void freeNodes(Node *node)
{
    if(node == NULL)
        return;
            
    freeNodes(node->left);
    freeNodes(node->right);
    printf("Space freed from node with name: %s\n", node->name);
    free(node);
}


void printTabs(int tabs)
{
    for (int i = COUNT; i < tabs; i++) 
        printf("    ");
}

void _printTree(Node *node, int tabs)
{
    if(node == NULL)
    {
        printTabs(tabs+1);
        printf("----\n");
        return;
    }        

    tabs = tabs + COUNT;
    printTabs(tabs);
    printf("%s\n", node->name);
    _printTree(node->left, tabs);
    _printTree(node->right, tabs);

}

void printTree()
{
    _printTree(ROOT, 0);
}

void _printTreeOrdered(Node *node)
{
    //print names in order
    if(node != NULL)
    {
        _printTreeOrdered(node->left);
        printf("%s\n", node->name);
        _printTreeOrdered(node->right);
    }
}

void printTreeOrdered()
{
    _printTreeOrdered(ROOT->right);
}

int main()
{
    storeNode(ROOT, "teemo");
    storeNode(ROOT, "alistar");
    storeNode(ROOT, "draven");
    storeNode(ROOT, "leo");
    storeNode(ROOT, "bram");
    storeNode(ROOT, "harld");
    storeNode(ROOT, "david");
    
    printTreeOrdered();
    printf("\n");
    printTree();
    printf("\n");
    freeNodes(ROOT);

    return 0;
}