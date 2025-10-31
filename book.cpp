#include <stdio.h>
#include <string.h>

// Define the structure for a book
struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity; // Number of copies available
};

// Function to add a new book
void addBook(struct Book library[], int *numBooks) {
    if (*numBooks >= 100) { // Limit for example
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("\nEnter details for new book:\n");
    printf("Enter ID: ");
    scanf("%d", &library[*numBooks].id);
    printf("Enter title: ");
    scanf(" %99[^\n]", library[*numBooks].title); // Read string with spaces
    printf("Enter author: ");
    scanf(" %99[^\n]", library[*numBooks].author);
    printf("Enter quantity: ");
    scanf("%d", &library[*numBooks].quantity);

    (*numBooks)++;
    printf("Book added successfully.\n");
}

// Function to check book availability by title
void checkAvailability(struct Book library[], int numBooks) {
    char searchTitle[100];
    printf("\nEnter title of the book to check: ");
    scanf(" %99[^\n]", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(searchTitle, library[i].title) == 0) {
            printf("Book found: '%s' by %s\n", library[i].title, library[i].author);
            printf("Available copies: %d\n", library[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with title '%s' not found in the library.\n", searchTitle);
    }
}

// Function to display all books
void listAllBooks(struct Book library[], int numBooks) {
    if (numBooks == 0) {
        printf("\nNo books in the library.\n");
        return;
    }

    printf("\n--- All Books in Library ---\n");
    for (int i = 0; i < numBooks; i++) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d\n",
               library[i].id, library[i].title, library[i].author, library[i].quantity);
    }
}

int main() {
    struct Book library[100]; // Array to store up to 100 books
    int numBooks = 0; // Current number of books in the library
    int choice;

    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add New Book\n");
        printf("2. Check Book Availability\n");
        printf("3. List All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                checkAvailability(library, numBooks);
                break;
            case 3:
                listAllBooks(library, numBooks);
                break;
            case 4:
                printf("Thank You. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
