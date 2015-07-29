/*************
 * header file
 ****************/

BpTree(int);
	//this constructor creates an empty tree, the parameter sets the number of keys 
	//that can be stored in each node (leaf and interior)

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
	//prints the values in key (not value) order