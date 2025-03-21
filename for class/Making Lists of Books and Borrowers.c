#include <stdio.h>
#include <string.h>

typedef struct {
    char borrowerID[12], name[20];
    int count;
} BorrowerInfo;

typedef struct {
    char bookID[12], title[80], author[80];
    int count;
} BookInfo;

typedef struct {
    int year, month, day;
} DateInfo;

typedef struct {
    BorrowerInfo *borrower;
    BookInfo *book;
    DateInfo borrowDate, dueDate, returnDate;
} CirculateInfo;

void doOption(int actionID, BorrowerInfo *borrower, int *borrowerTotal, BookInfo *book, int *bookTotal){
    switch (actionID) {
    case 1:
        // Borrow a book
        break;

    case 2:
        // Return a book
        break;

    case 3:
        // Print all borrowers
        printf("\nData of all borrowers:\n");
        for (int i = 0; i < *borrowerTotal; i++) {
            printf("Borrower ID: %s, Name: %s\n", borrower[i].borrowerID, borrower[i].name);
        }
        break;

    case 4:
        // Print all books
        printf("\nData of all books:\n");
        for (int i = 0; i < *bookTotal; i++) {
            printf("Book ID: %s\nTitle: %s\nAuthor: %s\n", book[i].bookID, book[i].title, book[i].author);
        }
        break;

    case 5:
        // Print all circulation records
        break;

    case 6:
        // Add a new borrower
            printf("\nEnter Borrower ID: ");
            scanf("%s", borrower[*borrowerTotal].borrowerID);
            printf("Enter Borrower Name: ");
            scanf("%s", borrower[*borrowerTotal].name);
            (*borrowerTotal)++;
        break;

    case 7:
        // Add a new book
        if (*bookTotal < 50) {
            printf("\nEnter Book ID: ");
            scanf("%s", book[*bookTotal].bookID);
            printf("Enter Book Title: ");
            scanf("%s", book[*bookTotal].title);
            printf("Enter Book Author: ");
            scanf("%s", book[*bookTotal].author);
            (*bookTotal)++;
            printf("Book added successfully.\n");
        }
        break;
    case 0:
        printf("\nThanks for using NTOU CSE Library Circulation System!!");
        break;
    }
}

int main(){
    BookInfo book[50];
    BorrowerInfo borrower[20];
    CirculateInfo record[200];
    int bookTotal = 0, borrowerTotal = 0, recordTotal = 0;
    int actionID =-1;

    while(actionID !=0){
        printf("\nMenu of NTOU CSE Library Circulation System\n"
               "1. Borrow a book.\n"
               "2. Return a book.\n"
               "3. Print all the borrowers.\n"
               "4. Print all the books.\n"
               "5. Print all the circulation records.\n"
               "6. Add a new borrower.\n"
               "7. Add a new book.\n"
               "0. Exit.\n"
               "Please choose one action: ");
        scanf("%d",&actionID);
        while (getchar() != '\n' && getchar() != EOF);
        doOption(actionID, borrower, &borrowerTotal, book, &bookTotal);
    }

    return 0;
}
           \n
1. Borrow a book.
 2. Return a book.
 3. Print all the borrowers.
 4. Print all the books.
 5. Print all the circulation records.
 6. Add a new borrower.
 7. Add a new book.
 0. Exit.");
}
