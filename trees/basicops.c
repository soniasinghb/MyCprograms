#include<stdio.h>
#include<stdlib.h>
struct treenode{
    char data[20];
    struct treenode *leftnode;
    struct treenode *rightnode;  
};
void insert(struct treenode**,int);
void inorder(struct treenode*);
void preorder(struct treenode*);
void postorder(struct treenode*);
void del(struct treenode*,int);
void search(struct treenode*,int);
void locate(struct treenode**,int ,struct treenode**,struct treenode**,int);

int main()
{
    struct treenode *s;

}
