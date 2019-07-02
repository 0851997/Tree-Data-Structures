#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include "nnarytree.h"

Node ROOT = NULL;

Node createNode(char *name)
{
    Node node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->child = NULL;
    node->next = NULL;
    node->parent = NULL;
    node->previous = NULL;
    return node;
}

void makeDirectoryTree(Node node, char *name)
{


    //fill in the nodes inside the tree
    // if(strcmp(name, node->name) == -1)
    //     if(node->left == NULL)
    //         node->left = createNode(name);
    //     else
    //         storeNode(node->left, name);
    // else if(strcmp(name, node->name) == 1)
    //     if(node->right == NULL)
    //         node->right = createNode(name);
    //     else
    //         storeNode(node->right, name);
}

int main(void)
{


    
    
    
    DIR *d;
    struct dirent *dir;
    char *dirName = "C:/Users/Robert/Desktop/Directory For Nnary Tree";
    d = opendir(dirName);
    if (d)
    {
        int i = 0;
        while ((dir = readdir(d)) != NULL)
        {
            printf("%d. %s\n", i, dir->d_name);
            
            if(i>1)
            {
                char str[80] = "C:/Users/Robert/Desktop/Directory For Nnary Tree";
                struct dirent *dir2;
                printf("Are you working?");
                //strcpy(str, dirName); 
                printf("Are you working?");
                strcat(str, "/");
                printf("Are you working?");
                strcat(str, dir->d_name);
                printf("%s", str);
                
                printf("%s",str);
                DIR *doo = opendir(str);
                while((dir2 = readdir(doo)) != NULL)
                {
                    printf("%d.x %s\n", i, dir->d_name);
                }
            }

            i++;
        }
        closedir(d);
    }
    return(0);
}