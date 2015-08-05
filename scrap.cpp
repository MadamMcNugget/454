#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int keysPerNode;

struct node
{
    int *key;
    node **child_ptr;
    bool isLeaf;
    int n;
}*root = NULL, *np = NULL, *you = NULL;

struct record
{
    string message;
}record;

node * init()
{
    int i;
    np = new node;
    np->key = new int[keysPerNode];
    np->child_ptr = new node *[keysPerNode+1];
    np->isLeaf = true;
    np->n = 0;
    for (i = 0; i < keysPerNode+1; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}
void traverse(node *p)
{
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->isLeaf == false)
        {
            traverse(p->child_ptr[i]);
        }
        cout << " " << p->key[i];
    } 
    if (p->isLeaf == false)
    {
        traverse(p->child_ptr[i]);
    }
    cout<<endl;
}

void sort(int *p, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}


void split_child(node *you, int k)
{
    node *par, *sib;
    sib = init();

    you->key[keysPerNode]=k

    //int temparray[keysPerNode+1];
    for (int i = 0 ; i < keysPerNode ; i++)
    {
        temparray[i] = you->key[i];
    }
    temparray[keysPerNode] = k;
    sort(temparray, temparray+keysPerNode+1);

    int m = (int)ceil((keysPerNode+1)/2);


    for (int i = m ; i < keysPerNode ; i++)  // add new half into new node
    {
        sib->key[i-m] = temparray[i];
    }

    for (int i = 0 ; i < m ; i++)  // replace old node with new first half of temparray
    {
        you->key[i] = temparray[i];
    }
    for (int i = m ; i < keysPerNode ; i++)
    {
        you->key[i] = NULL;
    }

    //if (you->par == NULL)
    par = init();
    par->key[0] = sib->key[0];

}
 
void insert(int a)
{
    int i, temp;
    you = root;
    if (you == NULL)
    {
        root = init();
        you = root;
    }
    else
    {
        you->key[you->n] = a;
        sort(you->key, you->n);
        you->n++;

        if (you->isLeaf == true && you->n > keysPerNode)  // if leaf and full
        {

            split_child(you);

        }
    }
}

void menu()
{
    cout<<"\n~Menu~\n\n";
    cout<<"1: insert key\n";
    cout<<"2: traverse\n";
    cout<<"3: quit\n";

    int i;
    cout<<"Enter choice: ";
    cin>>i;

    switch(i){
        case 1:{
            int key;
            string mes;
            cout<<"enter key: ";
            cin>>key;
            cout<<"enter message: ";
            cin>>mes;
            insert(key);
            menu();
            break;
        }
        case 2: {
            traverse(root);
            menu();
            break;
        }
        case 3: {
            cout<<"bye";
            exit (EXIT_SUCCESS);
            break;
        }
    }
}

int main()
{
    //int i, n, t;
    cout<<"number of keys in a node: ";
    cin>>keysPerNode;
    /*cout<<"number of elements: ";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cout<<"enter the element\n";
        cin>>t;
        insert(t);
    }
    cout<<"traversal of constructed tree\n";
    traverse(root);*/

    menu();
}
