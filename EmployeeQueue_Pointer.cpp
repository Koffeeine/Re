#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ngaysinh {
    int ngay, thang, nam;
} NgaySinh;

typedef struct item {
    char maNV[30];
    double PCCV;
    double HSL;
    double TotalSalary;
    NgaySinh ns;
    struct item* next;
} Item;

typedef struct Queue {
    Item *front, *rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = Q->rear = NULL;
}

int IsEmpty(Queue *Q) {
    return (Q->front == NULL);
}

void Enqueue(Item *x, Queue *Q) {
    x->next = NULL;
    if (IsEmpty(Q)) {
        Q->front = Q->rear = x;
    } else {
        Q->rear->next = x;
        Q->rear = x;
    }
}

Item* Dequeue(Queue *Q) {
    if (IsEmpty(Q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    Item *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    return temp;
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

void outputItem(Item *nv) {
    printf("\n---------------------------");
    printf("\n Ma NV = %s", nv->maNV);
    printf("\n Ngay Sinh = %d/%d/%d", nv->ns.ngay, nv->ns.thang, nv->ns.nam);
    printf("\n He so luong = %.2lf", nv->HSL);
    printf("\n Phu cap chuc vu = %.2lf", nv->PCCV);
    printf("\n Tong luong = %.2lf", nv->TotalSalary);
}

void inputQueue(Queue *Q) {
    Item x;
    int m;
    printf("Enter number of Employees: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputItem(&x);
        Item *newItem = (Item *)malloc(sizeof(Item));
        *newItem = x;
        Enqueue(newItem, Q);
    }
}

void outputQueue(Queue *Q) {
    printf("\n THE QUEUE YOU HAVE ENTERED \n");
    Item *current = Q->front;
    while (current != NULL) {
        outputItem(current);
        current = current->next;
    }
}

void HighestSalaryEm(Queue *Q) {
    if (IsEmpty(Q)) {
        printf("Queue is empty\n");
        return;
    }
    double maxSalary = Q->front->TotalSalary;
    Item *maxSalaryEmp = Q->front;
    Item *current = Q->front->next;
    while (current != NULL) {
        if (current->TotalSalary > maxSalary) {
            maxSalary = current->TotalSalary;
            maxSalaryEmp = current;
        }
        current = current->next;
    }
    printf("\n HIGHEST SALARY EMPLOYEE \n");
    outputItem(maxSalaryEmp);
}

int main() {
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    InitQueue(Q);
    int choice;
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
            default: {
                printf("Invalid choice! Please choose again.\n");
                break;
            }
        }
    } while (choice != 0);

    while (!IsEmpty(Q)) {
        Item *temp = Dequeue(Q);
        free(temp);
    }
    free(Q);

    return 0;
}
