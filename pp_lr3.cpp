#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*El of Tree*/
struct Node {
	int value;
	Node *left;
	Node *right;
};

bool can = true;

void InsertTree(Node **root, int data) {
	if (!(*root)) {
		(*root) = new Node;
		(*root)->value = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else {
		if (data < (*root)->value) InsertTree(&(*root)->left, data);
		else InsertTree(&(*root)->right, data);
	}
}

void PrintTree(Node *root) {
	if (root) {
		PrintTree(root->left);
		printf("%3d  ",root->value);
		PrintTree(root->right);
	}
}

void getQuantityOfElement(Node *root) {
	if (root && can) {
		getQuantityOfElement(root->left);
		if ((root -> value > 0) && (can)) {
			printf("%3d  ", root->value);
			can = false;
			root = NULL;
			return;
		}
		getQuantityOfElement(root->right);
	}
}

int main() {
	srand((unsigned)time(NULL));
	Node *root = NULL;

	for (int i = 0; i < 10; i++) InsertTree(&root, rand() % 51 - 25);
	printf("Created Tree:\n");
	PrintTree(root);
	printf("MPTree:");
	getQuantityOfElement(root);
	printf("\nВиконав студент групи ПЗ-144 ZeitMaster\n");
	return 0;
}

