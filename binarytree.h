struct _Node
{
    #define Node struct _Node 
    char name[32];
    Node *left;
    Node *right;
};

Node *createNode(char *name);
void storeNode(Node *node, char *name);
void freeNodes(Node *node);
void printTabs(int tabs);
void _printTree(Node *node, int tabs);
void printTree();
void _printTreeOrdered(Node *node);
void printTreeOrdered();
