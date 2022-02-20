#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// write BST functions
typedef struct Node
{
    int data;
    char toy[101];
    struct Node *left;
    struct Node *right;
} Node;
int data;
char toy[101];
Node *r = NULL;
Node *makeNode(int data, char toy[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->toy, toy);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insert(Node *r, int data, char toy[])
{
    if (r == NULL)
    {
        r = makeNode(data, toy);
    }
    else if (data < r->data)
    {
        r->left = insert(r->left, data, toy);
    }
    else if (data > r->data)
    {
        r->right = insert(r->right, data, toy);
    }
    return r;
}
Node *find(Node *r, int data)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (data == r->data)
    {
        return r;
    }
    else if (data < r->data)
    {
        return find(r->left, data);
    }
    else if (data > r->data)
    {
        return find(r->right, data);
    }
}
Node *findMin(Node *r)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (r->left == NULL)
    {
        return r;
    }
    else
    {
        return findMin(r->left);
    }
}
Node *findMax(Node *r)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (r->right == NULL)
    {
        return r;
    }
    else
    {
        return findMax(r->right);
    }
}
Node *removeChild(Node *r, int data)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (data < r->data)
    {
        r->left = removeChild(r->left, data);
    }
    else if (data > r->data)
    {
        r->right = removeChild(r->right, data);
    }
    else
    {
        if (r->left == NULL && r->right == NULL)
        {
            free(r);
            r = NULL;
        }
        else if (r->left == NULL)
        {
            Node *temp = r;
            r = r->right;
            free(temp);
        }
        else if (r->right == NULL)
        {
            Node *temp = r;
            r = r->left;
            free(temp);
        }
        else
        {
            Node *temp = findMin(r->right);
            r->data = temp->data;
            strcpy(r->toy, temp->toy);
            r->right = removeChild(r->right, temp->data);
        }
    }
    return r;
}
void printTree(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    printTree(r->left);
    printf("%d %s\n", r->data, r->toy);
    printTree(r->right);
}

void inorder(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    inorder(r->right);
    printf("%d %s\n", r->data, r->toy);
    inorder(r->left);
}
void menu()
{
    printf("================================\n");
    printf("1. Doc file A\n");
    printf("2. Doc file B\n");
    printf("3. Tim kiem\n");
    printf("4. Tong hop\n");
    printf("5. Thong ke\n");
    printf("6. Thoat\n");
    printf("================================\n");
}
void process1()
{
    char c;
    FILE *fp = fopen("A.txt", "r");
    while (fscanf(fp, "%d%c", &data, &c) != EOF)
    {
        if (c == '\t')
        {
            fscanf(fp, "%s", toy);
        }
        else
        {
            toy[0] = '\0';
        }
        r = insert(r, data, toy);
    }
    fclose(fp);
}

int main()
{
    /*int x;
    do
    {
        menu();
        scanf("%d", &x);
        if (!(x <= 6 && x >= 1))
        {
            while (!(x <= 6 && x >= 1))
            {
                printf("Nhap sai, moi nhap lai\n");
                scanf("%d", &x);
            }
        }
        if (x == 1)
            process1();
        if (x == 2)
            process2();
        if (x == 3)
            process3();
        if (x == 4)
            process4();
        if (x == 5)
            process5();
        if (x == 6)
            break;

    } while (1 <= x && x <= 6);*/
    process1();
    inorder(r);
    return 0;
}