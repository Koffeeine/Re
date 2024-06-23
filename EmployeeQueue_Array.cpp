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

typedef struct Queue {
    item Data[Max];
    int Front, Rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->Front = 0;
    Q->Rear = -1;
}

int IsEmpty(Queue *Q) {
    return (Q->Front > Q->Rear);
}

int IsFull(Queue *Q) {
    return (Q->Rear == Max - 1);
}

void Enqueue(item x, Queue *Q) {
    if (!IsFull(Q)) {
        Q->Rear++;
        Q->Data[Q->Rear] = x;
    } else {
        printf("Queue is full\n");
        exit(EXIT_FAILURE);
    }
}

item Dequeue(Queue *Q) {
    item temp;
    if (!IsEmpty(Q)) {
        temp = Q->Data[Q->Front];
        Q->Front++;
        return temp;
    } else {
        printf("Queue is empty\n");
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

void inputQueue(Queue *Q) {
    Item x;
    int m;
    printf("Enter number of Employees: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputItem(&x);
        Enqueue(x, Q);
    }
}

void outputQueue(Queue *Q) {
    printf("\n THE QUEUE YOU HAVE ENTERED \n");
    for (int i = Q->Front; i <= Q->Rear; i++) {
        outputItem(Q->Data[i]);
    }
}

void HighestSalaryEm(Queue *Q) {
    double maxSalary = Q->Data[Q->Front].TotalSalary;
    int index = Q->Front;
    for (int i = Q->Front + 1; i <= Q->Rear; i++) {
        if (Q->Data[i].TotalSalary > maxSalary) {
            maxSalary = Q->Data[i].TotalSalary;
            index = i;
        }
    }
    printf("\n HIGHEST SALARY EMPLOYEE \n");
    outputItem(Q->Data[index]);
}

int main() {
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    int choice;
    InitQueue(Q);
    do {
        printf("\n------------------------------");
        printf("\n 1. Initialize the queue ");
        printf("\n 2. Input data for the queue ");
        printf("\n 3. Output data of the queue ");
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
                InitQueue(Q);
                break;
            }
            case 2: {
                system("cls");
                inputQueue(Q);
                break;
            }
            case 3: {
                system("cls");
                outputQueue(Q);
                break;
            }
            case 4: {
                system("cls");
                HighestSalaryEm(Q);
                break;
            }
        }
    } while (choice != 0);

    free(Q);
    return 0;
}
