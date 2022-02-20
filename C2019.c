#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Node
{
    char tu[101];
    char nghia[101];
    struct Node *left;
    struct Node *right;
} Node;
char tu[101];
char nghia[101];
Node *r = NULL;
Node *makeNode(char tu[], char nghia[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->tu, tu);
    strcpy(newNode->nghia, nghia);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insert(Node *r, char tu[], char nghia[])
{
    if (r == NULL)
    {
        r = makeNode(tu, nghia);
    }
    else if (strcmp(tu, r->tu) < 0)
    {
        r->left = insert(r->left, tu, nghia);
    }
    else if (strcmp(tu, r->tu) > 0)
    {
        r->right = insert(r->right, tu, nghia);
    }
    return r;
}

void inorder(Node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%s\t%s\n", r->tu, r->nghia);
        inorder(r->right);
    }
}
void nhap()
{
    FILE *fp;
    fp = fopen("A.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s %s", tu, nghia);
        r = insert(r, tu, nghia);
    }
}
void menu()
{
    printf("========================\n");
    printf("1. Duyet cay\n");
    printf("2. Them tu\n");
    printf("3. Tim tu\n");
    printf("4. Thoat\n");
}
void process1()
{
    inorder(r);
}
void process2()
{
    printf("Nhap tu: ");
    scanf("%s", tu);
    printf("Nhap nghia: ");
    scanf("%s", nghia);
    r = insert(r, tu, nghia);
}
Node *find(Node *r, char tu[])
{
    if (r == NULL)
    {
        return NULL;
    }
    else
    {
        
        if (strcmp(tu, r->tu) < 0)
        {
            printf("%s\n", r->tu);
            return find(r->left, tu);
        }
        else if (strcmp(tu, r->tu) > 0)
        {
            printf("%s\n", r->tu);
            return find(r->right, tu);
        }
        else
        {
            printf("%s\t", r->tu);
            printf("%s\n", r->nghia);
            return r;
            
        }
    }
}
void process3()
{
    printf("Nhap tu: ");
    scanf("%s", tu);
    Node* h=find(r, tu);
    if(h==NULL)
    {
        printf("Khong tim thay tu\n");
    }
}

int main()
{
    nhap();
    int x;
    do
    {
        menu();
        scanf("%d", &x);
        if (x < 1 || x > 4)
        {
            printf("Nhap sai!. Hay nhap lai chuc nang: \n");
            scanf("%d", &x);
        }
        if (x == 1)
            process1();
        if (x == 2)
            process2();
        if (x == 3)
            process3();
        if (x == 4)
            break;
    } while (1 <= x && x <= 4);
}