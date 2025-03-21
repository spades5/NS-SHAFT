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

void doOption(int actionID, BorrowerInfo *borrower, int *borrowerTotal,BookInfo *book, int *bookTotal, CirculateInfo *record, int *recordTotal){
    switch (actionID) {
    case 1: {
        // Borrow a book
        char borrowerID[12], bookID[12];
        printf("\nInput the borrower ID: ");
        scanf("%s", borrowerID);

        // Search for borrower
        int borrowerIndex = -1;
        for (int i = 0; i < *borrowerTotal; i++) {
            if (strcmp(borrowerID,borrower[i].borrowerID)==0) {
                borrowerIndex = i;
                break;
            }
        }
        if (borrowerIndex == -1) {
            printf("Borrower ID not found.\n");
            break;
        }

        printf("Input the book ID: ");
        scanf("%s", bookID);

        // Search for book
        int bookIndex = -1;
        for (int i=0;i<*bookTotal;i++) {
            if (strcmp(bookID,book[i].bookID)==0) {
                bookIndex = i;
                break;
            }
        }
        if (bookIndex==-1) {
            printf("Book ID not found.\n");
            break;
        }

        // Input borrow and due dates
        DateInfo borrowDate, dueDate;
        printf("Input the borrowing date (year/month/day): ");
        scanf("%d/%d/%d", &borrowDate.year, &borrowDate.month, &borrowDate.day);
        printf("Input the due date (year/month/day): ");
        scanf("%d/%d/%d", &dueDate.year, &dueDate.month, &dueDate.day);

        // Create circulation record
        record[*recordTotal].borrower = &borrower[borrowerIndex];
        record[*recordTotal].book = &book[bookIndex];
        record[*recordTotal].borrowDate = borrowDate;
        record[*recordTotal].dueDate = dueDate;
        record[*recordTotal].returnDate = (DateInfo){0, 0, 0}; // Initialize return date
        (*recordTotal)++;

        printf("A circulation record has been created.\n");
        break;
    }

    case 2: { // Return a book
        char borrowerID[12], bookID[12];
        printf("\nInput the borrower ID: ");
        scanf("%s", borrowerID);
        printf("Input the book ID: ");
        scanf("%s", bookID);

        // Search for matching circulation record
        int recordIndex = -1;
        for (int i = 0; i < *recordTotal; i++) {
            if (strcmp(record[i].borrower->borrowerID, borrowerID) == 0 && strcmp(record[i].book->bookID, bookID) == 0 && record[i].returnDate.year == 0 && record[i].returnDate.month == 0 &&record[i].returnDate.day == 0) {
                recordIndex = i;
                break;
            }
        }

        if (recordIndex == -1) {
            printf("No matching record found or the book has already been returned.\n");
            break;
        }

        // Input return date
        DateInfo returnDate;
        printf("Input the return date (year/month/day): ");
        scanf("%d/%d/%d", &returnDate.year, &returnDate.month, &returnDate.day);

        // Update return date
        record[recordIndex].returnDate = returnDate;
        printf("A book has been returned.");
        break;
    }


    case 3:{
        // Print all borrowers
        printf("\nData of all borrowers:\n");
        for (int i = 0; i < *borrowerTotal; i++) {
            printf("Borrower ID: %s, Name: %s\n", borrower[i].borrowerID, borrower[i].name);
        }
        break;
    }

    case 4:{
        // Print all books
        printf("\nData of all books:\n");
        for (int i = 0; i < *bookTotal; i++) {
            printf("Book ID: %s\nTitle: %s\nAuthor: %s\n", book[i].bookID, book[i].title, book[i].author);
        }
        break;
    }

    case 5:{
        // Print all circulation records
        for(int i=0;i<*recordTotal;i++){
            printf("%s      %s        %d/%d/%d        %d/%d/%d       %d/%d/%d\n",record[i].borrower->borrowerID, record[i].book->bookID,record[i].borrowDate.year, record[i].borrowDate.month, record[i].borrowDate.day,record[i].dueDate.year, record[i].dueDate.month, record[i].dueDate.day,record[i].returnDate.year, record[i].returnDate.month, record[i].returnDate.day);
        }
        break;
    }

    case 6:{
        // Add a new borrower
            printf("\nEnter Borrower ID: ");
            scanf("%s", borrower[*borrowerTotal].borrowerID);
            printf("Enter Borrower Name: ");
            scanf("%s", borrower[*borrowerTotal].name);
            (*borrowerTotal)++;
        break;
    }

    case 7:{
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
    }
    case 0:{
        printf("\nThanks for using NTOU CSE Library Circulation System!!");
        break;
    }
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
        doOption(actionID,&borrower,&borrowerTotal,&book,&bookTotal,&record,&recordTotal);
    }

    return 0;
}
