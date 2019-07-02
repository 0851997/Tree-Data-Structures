struct _Node
{
    #define Node struct _Node *
    char name[32];
    Node child;
    Node next;
    Node parent;
    Node previous;
};

Node createNode(char *name);
void storeNode(Node node, char *name);
