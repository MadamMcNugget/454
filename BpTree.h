/****************
 * header file
 ****************/

#include <iostream>
using namespace std;

class BpTree
{
	public:
		BpTree(int n);	//this constructor creates an empty tree, the parameter sets the number
						//of keys that can be stored in each node (leaf and interior)
		~BpTree();   // the destructor

		void insert(int, string);
			//inserts the key (int) and value (string) into the tree

		void remove(int);
			//searches the tree for the key (int), if found removes the 
			//key and associated value from the tree

		void find(int);
			//searches the tree for the key (int), if found returns the matching value

		void printKeys();
			//prints the keys in each node with nodes of the same level appearing on the same line

		void printValues();
			//prints the values in key (not value) order. Print one value per line.

	private:
		int numKeys;  // number of keys


			
};

struct node
{
    int *key;
    node **child_ptr;
    bool isLeaf;
    int n;
    node *parent;
}*root = NULL, *np = NULL, *you = NULL;