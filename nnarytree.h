struct _Node
{
    #define Node struct _Node * 
    char name[32];
    Node next;
    Node previous;
    Node child;
    Node parent;
};

Node createNode(char *name);
void storeNode(Node node, char *name);
