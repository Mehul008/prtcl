#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class node
{
    public:

    node *left, *right;
    int dada;
};

class Breadthfs
{
    public:

    node *insert(node *, int);
    void bfs(node *);
};

node *insert(node *root, int data)