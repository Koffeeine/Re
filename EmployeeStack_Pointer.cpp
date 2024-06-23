#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max 100

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

typedef struct Stack {
    item Data[Max];
    int Top;
} Stack;

void Init(Stack *S) {
    S->Top = 0;
}

int IsEmpty(Stack *S) {
    return (S->Top == 0);
}

int IsFull(Stack *S) {
    return (S->Top == Max);
}

void Push(item x, Stack *S) {
    if (!IsFull(S)) {
        S->Data[S->Top] = x;
        S->Top++;
    }
}

item Pop(Stack *S) {
    item temp;
    if (!IsEmpty(S)) {
        S->Top--;
        temp = S->Data[S->Top];
        return temp;
    }
    else {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
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

void inputStack(Stack *S) {
    Item x;
    int m;
    printf("Enter number of Employees: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputItem(&x);
        Push(x, S);
    }
}

void outputStack(Stack *S) {
    printf("\n THE STACK YOU HAVE ENTERED \n");
    for (int i = S->Top - 1; i >= 0; i--) {
        outputItem(S->Data[i]);
    }
}

void HighestSalaryEm(Stack *S) {
    double maxSalary = S->Data[0].TotalSalary;
    int index = 0;
    for (int i = S->Top - 1; i >= 0; i--) {
        if (S->Data[i].TotalSalary > maxSalary) {
            maxSalary = S->Data[i].TotalSalary;
            index = i;
        }
    }
    printf("\n HIGHEST SALARY EMPLOYEE \n");
    outputItem(S->Data[index]);
}

int main() {
    Stack *S = (Stack *)malloc(sizeof(Stack));
    int choice;
    Init(S);
    do {
        printf("\n------------------------------");
        printf("\n 1. Initialize the stack ");
        printf("\n 2. Input data for the stack ");
        printf("\n 3. Output data of the stack ");
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
                Init(S);
                break;
            }
            case 2: {
                system("cls");
                inputStack(S);
                break;
            }
            case 3: {
                system("cls");
                outputStack(S);
                break;
            }
            case 4: {
                system("cls");
                HighestSalaryEm(S);
                break;
            }
        }
    } while (choice != 0);

    free(S);
    return 0;
}
