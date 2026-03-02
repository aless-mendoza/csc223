#include <stdio.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;

struct node *insrtEl();
void preord();
void inorder();
void postord();
struct node *findSml();
struct node *findLrg();
struct node *delElem();
struct node *mirror();
int totNodes();
int totExtNd();
int totIntNd();
int Height();
struct node *delTree();


int main()
{
    int option, val;
    struct node *ptr;
    tree = NULL;
    do {
	printf("\n ******MAIN MENU******* \n");
	printf("\n 1. Insert Element");
	printf("\n 2. Preorder Traversal");
	printf("\n 3. Inorder Traversal");
	printf("\n 4. Postorder Traversal");
	printf("\n 5. Find the smallest element");
	printf("\n 6. Find the largest element");
	printf("\n 7. Delete an element");
	printf("\n 8. Count the total number of nodes");
	printf("\n 9. Count the total number of external nodes");
	printf("\n 10. Count the total number of internal nodes");
	printf("\n 11. Determine the height of the tree");
	printf("\n 12. Find the mirror image of the tree");
	printf("\n 13. Delete the tree");
	printf("\n 14. Exit");
	printf("\n\n Enter your option : ");
	scanf("%d", &option);
	switch (option) {
	case 1:
	    printf("\n Enter the value of the new node : ");
	    scanf("%d", &val);
	    tree = insrtEl(tree, val);
	    break;
	case 2:
	    printf("\n The elements of the tree are : \n");
	    preorder(tree);
	    break;
	case 3:
	    printf("\n The elements of the tree are : \n");
	    inorder(tree);
	    break;
	case 4:
	    printf("\n The elements of the tree are : \n");
	    postord(tree);
	    break;
	case 5:
	    ptr = findSml(tree);
	    printf("\n Smallest element is :%d", ptr->data);
	    break;
	case 6:
	    ptr = findLrg(tree);
	    printf("\n Largest element is : %d", ptr->data);
	    break;
	case 7:
	    printf("\n Enter the element to be deleted : ");
	    scanf("%d", &val);
	    tree = delElem(tree, val);
	    break;
	case 8:
	    printf("\n Total no. of nodes = %d", totNodes(tree));
	    break;
	case 9:
	    printf("\n Total no. of external nodes = %d",
		   totExtNd(tree));
	    break;
	case 10:
	    printf("\n Total no. of internal nodes = %d",
		   totIntNd(tree));
	    break;
	case 11:
	    printf("\n The height of the tree = %d", Height(tree));
	    break;
	case 12:
	    tree = mirror(tree);
	    break;
	case 13:
	    tree = delTree(tree);
	    break;
	}
    } while (option != 14);
    return 0;
}

struct node *insrtEl(tree, val)
struct node *tree;
int val;
{
    struct node *ptr, *ndptr, *parptr;
    ptr = (struct node *) alloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL) {
	tree = ptr;
	tree->left = NULL;
	tree->right = NULL;
    } else {
	parptr = NULL;
	ndptr = tree;
	while (ndptr != NULL) {
	    parptr = ndptr;
	    if (val < ndptr->data)
		ndptr = ndptr->left;
	    else
		ndptr = ndptr->right;
	}
	if (val < parptr->data)
	    parptr->left = ptr;
	else
	    parptr->right = ptr;
    }
    return tree;
}

void preorder(tree)
struct node *tree;
{
    if (tree != NULL) {
	printf("%d\t", tree->data);
	preorder(tree->left);
	preorder(tree->right);
    }
}

void inorder(tree)
struct node *tree;
{
    if (tree != NULL) {
	inorder(tree->left);
	printf("%d\t", tree->data);
	inorder(tree->right);
    }
}

void postord(tree)
struct node *tree;
{
    if (tree != NULL) {
	postord(tree->left);
	postord(tree->right);
	printf("%d\t", tree->data);
    }
}

struct node *findSml(tree)
struct node *tree;
{
    if ((tree == NULL) || (tree->left == NULL))
	return tree;
    else
	return findSml(tree->left);
}

struct node *findLrg(tree)
struct node *tree;
{
    if ((tree == NULL) || (tree->right == NULL))
	return tree;
    else
	return findLrg(tree->right);
}

struct node *delElem(tree, val)
struct node *tree;
int val;
{
    struct node *cur, *parent, *suc, *psuc, *ptr;
    if (tree->left == NULL) {
	printf("\n The tree is empty ");
	return (tree);
    }
    parent = tree;
    cur = tree->left;
    while (cur != NULL && val != cur->data) {
	parent = cur;
	cur = (val < cur->data) ? cur->left : cur->right;
    }
    if (cur == NULL) {
	printf("\n The value to be deleted is not present in the tree");
	return (tree);
    }
    if (cur->left == NULL)
	ptr = cur->right;
    else if (cur->right == NULL)
	ptr = cur->left;
    else {
	psuc = cur;
	suc = cur->right;
	while (suc->left != NULL) {
	    psuc = suc;
	    suc = suc->left;
	}
	if (cur == psuc) {
	    suc->left = cur->right;
	} else {
	    suc->left = cur->left;
	    psuc->left = suc->right;
	    suc->right = cur->right;
	}
	ptr = suc;
    }
    if (parent->left == cur)
	parent->left = ptr;
    else
	parent->right = ptr;
    free(cur);
    return tree;
}

int totNodes(tree)
struct node *tree;
{
    if (tree == NULL)
	return 0;
    else
	return (totNodes(tree->left) + totNodes(tree->right) + 1);
}

int totExtNd(tree)
struct node *tree;
{
    if (tree == NULL)
	return 0;
    else if ((tree->left == NULL) && (tree->right == NULL))
	return 1;
    else
	return (totExtNd(tree->left) +
		totExtNd(tree->right));
}

int totIntNd(tree)
struct node *tree;
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
	return 0;
    else
	return (totIntNd(tree->left)
		+ totIntNd(tree->right) + 1);
}

int Height(tree)
struct node *tree;
{
    int lftht, rgtht;
    if (tree == NULL)
	return 0;
    else {
	lftht = Height(tree->left);
	rgtht = Height(tree->right);
	if (lftht > rgtht)
	    return (lftht + 1);
	else
	    return (rgtht + 1);
    }
}

struct node *mirror(tree)
struct node *tree;
{
    struct node *ptr;
    if (tree != NULL) {
	mirror(tree->left);
	mirror(tree->right);
	ptr = tree->left;
	tree->left = tree->right;
	tree->right = ptr;
    }
    return tree;
}

struct node *delTree(tree)
struct node *tree;
{
    if (tree != NULL) {
	delTree(tree->left);
	delTree(tree->right);
	free(tree);
    }
    return NULL;
}


