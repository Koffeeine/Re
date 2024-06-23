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

typedef struct List {
    Item Elems[N];
    int size;
} List;

void init(List *L) {
    L->size = 0;
}

int isFull(List L) {
    return (L.size == N);
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

void Insert(Item x, int p, List *L) {
    if (!isFull(*L) && (p >= 1) && (p <= L->size + 1)) {
        L->size++;
        for (int i = L->size - 1; i >= p; i--)
            L->Elems[i] = L->Elems[i - 1];
        L->Elems[p - 1] = x;
    }
}

void inputList(List *L) {
    Item x;
    int m;
    printf("Enter number of Employees: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputItem(&x);
        Insert(x, 1, L);
    }
}

void outputList(List L) {
    printf("\n THE LIST YOU HAVE ENTERED");
    for (int i = 0; i < L.size; i++)
        outputItem(L.Elems[i]);
}

void HighestSalaryEm(List L) {
    double maxSalary = L.Elems[0].TotalSalary;
    int index = 0;
    for (int i = 1; i < L.size; i++) {
        if (L.Elems[i].TotalSalary > maxSalary) {
            maxSalary = L.Elems[i].TotalSalary;
            index = i;
        }
    }
    printf("\n HIGHEST SALARY EMPLOYEE \n");
    outputItem(L.Elems[index]);
}

int main() {
    List L;
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
