#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fp;
typedef struct Node
{
    char place[41];
    int h;
    int m;
    struct Node *next;
} Node;
Node *head = NULL;
char place[41];
int h, m;
Node *makeNode(char place[], int h, int m)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->place, place);
    newNode->h = h;
    newNode->m = m;
    newNode->next = NULL;
    return newNode;
}
Node *insertLast(Node *head, char place[], int h, int m)
{
    Node *newNode = makeNode(place, h, m);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
void menu()
{
    printf("================================\n");
    printf("CHUONG TRINH TRUY VET COVID 19\n");
    printf("1. Nap file log lich su di chuyen\n");
    printf("2. In ra lich su di chuyen\n");
    printf("3. Tiem kiem lich su theo dia diem\n");
    printf("4. Tim kiem lich su theo thoi gian\n");
    printf("5. Kiem tra truy vet moi nhat\n");
    printf("6. Thoat\n");
    printf("================================\n");
}
void process1()
{
    fp = fopen("log.txt", "r");
    while (fscanf(fp, "%s %d %d", place, &h, &m) != EOF)
    {
        head = insertLast(head, place, h, m);
    }
    fclose(fp);
}
void process2()
{
    Node *temp = head;
    printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
    while (temp != NULL)
    {
        printf("%-50s%-10d%-10d\n", temp->place, temp->h, temp->m);
        temp = temp->next;
    }
}
void process3()
{
    printf("Nhap dia diem can tim kiem: ");
    scanf("%s", place);
    Node *temp = head;
    int dem = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->place, place) == 0)
        {
            if (dem > 0)
                printf(", ");
            printf("%d:%d", temp->h, temp->m);
            dem++;
        }
        temp = temp->next;
    }
    if (dem == 0)
        printf("Ban chua toi dia diem nay");
    printf("\n");
}
void process4()
{
    printf("Nhap gio can tim kiem: ");
    scanf("%d", &h);
    printf("Nhap phut can tim kiem: ");
    scanf("%d", &m);
    while (h < 0 || h > 23 || m < 0 || m > 59)
    {
        printf("Gio hoac phut khong hop le. Nhap lai: \n");
        scanf("%d%d", &h, &m);
    }
    Node *temp = head;
    int dem = 0;
    while (temp != NULL)
    {
        if (temp->h == h && temp->m == m)
        {
            if (dem > 0)
                printf(", ");
            printf("%s", temp->place);
            dem++;
        }
        temp = temp->next;
    }
    if (dem == 0)
        printf("Ban chua toi gio nay");
    printf("\n");
}
void process5()
{
    printf("Nhap dia diem va thoi gian;\n");
    scanf("%s %d %d", place, &h, &m);
    while (h < 0 || h > 23 || m < 0 || m > 59)
    {
        printf("Gio hoac phut khong hop le. Nhap lai: \n");
        scanf("%d", &h);
        scanf("%d", &m);
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->place, place) == 0)
        {
            if (temp->h > h)
            {
                printf("Ban co kha nang bi nhiem Covid, can phai khai bao y te ngay lap tuc\n");
                break;
            }
            if (temp->h == h && temp->m >= m)
            {
                printf("Ban co kha nang bi nhiem Covid, can phai khai bao y te ngay lap tuc\n");
                break;
            }
            printf("Ban khong co kha nang bi nhiem Covid\n");
        }
        temp = temp->next;
    }
}
void freelinklist()
{
    Node *temp = head;
    while (temp != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
}
int main()
{
    int x;
    do
    {
        menu();
        scanf("%d", &x);
        if (!(1 <= x && x <= 6))
        {
            while (!(1 <= x && x <= 6))
            {
                printf("Nhap lai tinh nang: ");
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

    } while ((1 <= x && x <= 6));

    return 0;
}
