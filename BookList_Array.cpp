#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef struct {
    char name[100];
    char author[50];
    int year;
} Book;

typedef struct {
    Book Elems[N];
    int size;
} List;

void init(List *L) {
    L->size = 0;
}

int isFull(List L) {
    return (L.size == N);
}

void inputBook(Book *book) {
    printf("Name: ");
    getchar(); // Clear input buffer
    fgets(book->name, sizeof(book->name), stdin);
    book->name[strlen(book->name) - 1] = '\0'; 
    printf("Author: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strlen(book->author) - 1] = '\0'; 
    printf("Year of publication: ");
    scanf("%d", &book->year);
    printf("------------------------------\n");
}

void outputBook(Book book) {
    printf("\n---------------------------");
    printf("\n Name: %s", book.name);
    printf("\n Author: %s", book.author);
    printf("\n Year of publication: %d", book.year);
}

void Insert(Book book, int p, List *L) {
    if (!isFull(*L) && (p >= 1) && (p <= L->size + 1)) {
        L->size++;
        for (int i = L->size - 1; i >= p; i--)
            L->Elems[i] = L->Elems[i - 1];
        L->Elems[p - 1] = book;
    }
}

void inputList(List *L) {
    Book book;
    int m;
    printf("Enter number of books: m = ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        inputBook(&book);
        Insert(book, 1, L); 
    }
}

void outputList(List L) {
    printf("\n THE LIST OF BOOKS\n");
    for (int i = 0; i < L.size; i++)
        outputBook(L.Elems[i]);
}

void BooksPublishedInYear(List L, int year) {
    printf("\nBooks published in %d:\n", year);
    for (int i = 0; i < L.size; i++) {
        if (L.Elems[i].year == year) {
            outputBook(L.Elems[i]);
        }
    }
}

int main() {
    List L;
    int choice;
    do {
        printf("\n------------------------------");
        printf("\n 1. Initialize the list ");
        printf("\n 2. Input data for the list ");
        printf("\n 3. Output data of the list ");
        printf("\n 4. Find books published in a specific year ");
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
                int year;
                printf("Enter year to find books published: ");
                scanf("%d", &year);
                BooksPublishedInYear(L, year);
                break;
            }
            default: {
                printf("Invalid choice! Please choose again.\n");
                break;
            }
        }
    } while (choice != 0);
    return 0;
}
