#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
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

int split_child(node *you, int i)
{
    int j, mid;
    node *par, *sib, *y;
    sib = init();
    sib->isLeaf = true;
    int m = (int)ceil(keysPerNode/2);
    if (i == -1)
    {
        mid = you->key[m];
        you->key[mid] = 0;
        you->n--;
        par = init();
        par->isLeaf = false;
        you->isLeaf = true;
        for (j = m; j <= keysPerNode; j++)
        {
            sib->key[j - m] = you->key[j];
            sib->child_ptr[j - m] = you->child_ptr[j];
            sib->n++;
            you->key[j] = 0;
            you->n--;
        }
        for(j = 0; j <= keysPerNode; j++)
        {
            you->child_ptr[j] = NULL;
        }
        par->key[0] = mid;
        par->child_ptr[par->n] = you;
        par->child_ptr[par->n + 1] = sib;
        par->n++;
        root = par;
    }
    else
    {
        y = you->child_ptr[i];
        mid = y->key[m];
        y->key[m] = 0;
        y->n--;
        for (j = m; j < keysPerNode; j++)
        {
            sib->key[j - m] = y->key[j];
            sib->n++;
            y->key[j] = 0;
            y->n--;
        }
        you->child_ptr[i + 1] = y;
        you->child_ptr[i + 1] = sib; 
    }
    return mid;
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
        if (you->isLeaf == true && you->n == keysPerNode)
        {
            temp = split_child(you, -1);
            you = root;
            for (i = 0; i < (you->n); i++)
            {
                if ((a > you->key[i]) && (a < you->key[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < you->key[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            you = you->child_ptr[i];
        }
        else
        {
            while (you->isLeaf == false)
            {
            for (i = 0; i < (you->n); i++)
            {
                if ((a > you->key[i]) && (a < you->key[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < you->key[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
                if ((you->child_ptr[i])->n == 5)
                {
                    temp = split_child(you, i);
                    you->key[you->n] = temp;
                    you->n++;
                    continue;
                }
                else
                {
                    you = you->child_ptr[i];
                }
            }
        }
    }
    you->key[you->n] = a;
    sort(you->key, you->n);
    you->n++;
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
