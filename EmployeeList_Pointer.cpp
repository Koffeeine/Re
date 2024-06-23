#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef struct ngaysinh {
    int ngay, thang, nam;
} NgaySinh;

typedef struct item {
    char maNV[30];
    double PCCV;
    double HSL;
    double TotalSalary;
    NgaySinh ns;
} Item;

typedef struct Node {
    Item data;
    struct Node *next;
} Node;

typedef Node *LinkedList;

void init(LinkedList *L) {
    *L = NULL;
}

int isFull(LinkedList L) {
    return 0; 
}

Node* makeNode(Item x) {
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void inputItem(Item *x) {
    printf("Ma NV: ");
    scanf("%s", x->maNV);
    printf("Ngay sinh : ");
    scanf("%d", &x->ns.ngay);
    printf("Thang sinh : ");
    scanf("%d", &x->ns.thang);
    printf("Nam sinh : ");
    scanf("%d", &x->ns.nam);
    printf("He so luong: ");
    scanf("%lf", &x->HSL);
    printf("Phu cap chuc vu: ");
    scanf("%lf", &x->PCCV);
    printf("------------------------------\n");
    x->TotalSalary = (x->HSL + x->PCCV) * 1800000;
}

void outputItem(Item nv) {
    printf("\n---------------------------");
    printf("\n Ma NV = %s", nv.maNV);
    printf("\n Ngay Sinh = %d/%d/%d", nv.ns.ngay, nv.ns.thang, nv.ns.nam);
    printf("\n He so luong = %.2lf", nv.HSL);
    printf("\n Phu cap chuc vu = %.2lf", nv.PCCV);
    printf("\n Tong luong = %.2lf", nv.TotalSalary);
}

void Insert(Item x, int p, LinkedList *L) {
    Node *newNode = makeNode(x);
    if (p == 1) {
        newNode->next = *L;
        *L = newNode;
    }
}

void inputList(LinkedList *L) {
    Item x;
    int m;
    printf("Enter number of Employees: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputItem(&x);
        Insert(x, 1, L);
    }
}

void outputList(LinkedList L) {
    Node *p;
    p = L;
    printf("\n THE LIST YOU HAVE ENTERED");
    while (p != NULL) {
        outputItem(p->data);
        p = p->next;
    }
}

void HighestSalaryEm(LinkedList L) {
    double maxSalary = L->data.TotalSalary;
    Node *maxNode = L;
    Node *p = L->next;
    while (p != NULL) {
        if (p->data.TotalSalary > maxSalary) {
            maxSalary = p->data.TotalSalary;
            maxNode = p;
        }
        p = p->next;
    }
    printf("\n HIGHEST SALARY EMPLOYEE \n");
    outputItem(maxNode->data);
}

int main() {
    LinkedList L;
    int choice;
    do {
        printf("\n------------------------------");
        printf("\n 1. Initialize the list ");
        printf("\n 2. Input data for the list ");
        printf("\n 3. Output data of the list ");
        printf("\n 4. Find the employee with the highest salary ");
        printf("\n 0. Exit ");
        printf("\n Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: {
                break;
            }
            case 1: {
                system("cls");
                init(&L);
                break;
            }
            case 2: {
                system("cls");
                init(&L);
                inputList(&L);
                break;
            }
            case 3: {
                system("cls");
                outputList(L);
                break;
            }
            case 4: {
                system("cls");
                HighestSalaryEm(L);
                break;
            }
        }
    } while (choice != 0);
    return 0;
}
