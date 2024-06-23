#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef struct {
    char maSV[30];
    char hoTen[30];
    char nganhHoc[60];
    int namSinh;
    double toan;
    double tin;
    double anh;
    double dtb;
} item;

typedef struct Node {
    item Data;
    struct Node *Next;
} Node;

typedef struct {
    Node *top;
} Stack;

Node *MakeNode(item x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->Next = NULL;
    p->Data = x;
    return p;
}

void init(Stack *S) {
    S->top = NULL;
}

int isEmpty(Stack *S) {
    return (S->top == NULL);
}

void push(item x, Stack *S) {
    Node *newNode = MakeNode(x);
    newNode->Next = S->top;
    S->top = newNode;
}

item pop(Stack *S) {
    if (isEmpty(S)) {
        item emptyItem = {"", "", "", 0.0, 0.0, 0.0, 0.0};
        return emptyItem;
    } else {
        Node *p = S->top;
        S->top = S->top->Next;
        item data = p->Data;
        free(p);
        return data;
    }
}

void inputItem(item *x) {
    printf("Ma SV: ");
    scanf("%s", x->maSV);
    printf("Ho ten: ");
    scanf("%s", x->hoTen);
    printf("Nganh hoc: ");
    scanf("%s", x->nganhHoc);
    printf("Nam sinh: ");
    scanf("%d", &x->namSinh);
    printf("Diem mon Toan: ");
    scanf("%lf", &x->toan);
    printf("Diem mon Tin: ");
    scanf("%lf", &x->tin);
    printf("Diem mon Anh: ");
    scanf("%lf", &x->anh);
    printf("------------------------------\n");
    x->dtb = (x->toan + x->tin + x->anh) / 3.0;
}

void outputItem(item sv) {
    printf("\n---------------------------");
    printf("\n Ma SV = %s", sv.maSV);
    printf("\n Ho ten = %s", sv.hoTen);
    printf("\n Nganh hoc = %s", sv.nganhHoc);
    printf("\n Nam sinh = %d", sv.namSinh);
    printf("\n Diem Toan = %.2lf", sv.toan);
    printf("\n Diem Tin = %.2lf", sv.tin);
    printf("\n Diem Anh = %.2lf", sv.anh);
    printf("\n Diem TB = %.2lf", sv.dtb);
}

void inputStack(Stack *S) {
    item x;
    int m;
    printf("Enter the number of students: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputItem(&x);
        push(x, S);
    }
}

void outputStack(Stack *S) {
    printf("\n THE STACK YOU HAVE ENTERED\n");
    Node *current = S->top;
    while (current != NULL) {
        outputItem(current->Data);
        current = current->Next;
    }
}

void StudentsBornInYear(Stack *S, int year) {
    printf("\nSTUDENTS BORN IN %d\n", year);
    printf("---------------------------\n");
    int found = 0;
    Node *current = S->top;
    while (current != NULL) {
        if (current->Data.namSinh == year) {
            outputItem(current->Data);
            found = 1;
        }
        current = current->Next;
    }
    if (!found) {
        printf("No students born in %d found.\n", year);
    }
}

int main() {
    Stack S;
    init(&S);
    int choice;

    do {
        printf("\n---------------------------");
        printf("\n 1. Initialize the stack ");
        printf("\n 2. Input data for a stack ");
        printf("\n 3. Output data of the stack ");
        printf("\n 4. Check if the stack is empty ");
        printf("\n 5. Find students born in the year 2004 ");
        printf("\n 0. Exit ");
        printf("\n Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: {
                break;
            }
            case 1: {
                system("cls");
                init(&S);
                break;
            }
            case 2: {
                system("cls");
                inputStack(&S);
                break;
            }
            case 3: {
                system("cls");
                outputStack(&S);
                break;
            }
            case 4: {
                system("cls");
                if (isEmpty(&S)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            }
            case 5: {
                system("cls");
                StudentsBornInYear(&S, 2004);
                /*int year;
                printf("Enter the birth year to search for: ");
                scanf("%d", &year);
                StudentsBornInYear(&S, year);*/
                break;
            }
            default: {
                printf("Invalid choice! Please choose again.\n");
                break;
            }
        }
    } while (choice != 0);

    // giai phong bo nho
    Node *current = S.top;
    while (current != NULL) {
        Node *temp = current;
        current = current->Next;
        free(temp);
    }

    return 0;
}
