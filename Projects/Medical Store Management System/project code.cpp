#include <stdio.h>
#include <string.h>
#define MAX 50

// Medicine, supplier,customer structures
struct Medicine {
    char name[50];
    char batch[20];
    char expiry[15];
    int price;
    int stock;
};
struct Supplier {
    char name[50];
    char phone[20];
    char company[50];
};
struct Customer {
    char name[50];
    char phone[20];
    char address[50];
};

struct Medicine medicines[MAX];
int medcount = 0;

struct Supplier suppliers[MAX];
int supcount = 0;

struct Customer customers[MAX];
int cuscount = 0;
// functions that I would be using for customers, medicines and suppliers
void medicinemenu();
void suppliermenu();
void customermenu();

void addmedicine();
void viewmedicine();
void updatemedicine();
void deletemedicine();
void searchmedicine();

void addsupplier();
void viewsupplier();

void addcustomer();
void viewcustomer();

// main menu with recursion
void mainMenu() {
    int choice;
    printf("\n======= MAIN MENU =======\n");
    printf("1. Medicine Section\n");
    printf("2. Supplier Section\n");
    printf("3. Customer Section\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        medicinemenu();
        mainMenu(); //recursion
    }
    else if (choice == 2) {
        suppliermenu();
        mainMenu(); //recursion
    }
    else if (choice == 3) {
        customermenu();
        mainMenu(); //recursion
    }
    else if (choice == 4) {
        printf("\n Program has been exitted\n");
        return;// no recursion as program has been exit
    }
    else {
        printf("\nInvalid choice and enter choice againThank you!\n");
        mainMenu(); // recursion
    }
}
// MEDICINE FUNCTIONS
void addmedicine() {
    if (medcount >= MAX) {
        printf("\nMedicine list is full\n");
        return;
    }
    struct Medicine *m = &medicines[medcount];

    printf("\nEnter Medicine Name: ");
    scanf(" %[^\n]", m->name);
    printf("Enter Batch No: ");
    scanf(" %[^\n]", m->batch);
    printf("Enter Expiry Date: ");
    scanf(" %[^\n]", m->expiry);
    printf("Enter Price: ");
    scanf("%d", &m->price);
    printf("Enter Stock: ");
    scanf("%d", &m->stock);

    medcount++;
    printf("\nMedicine Added Successfully!\n");
}

void viewmedicine() {
    if (medcount == 0) {
        printf("\nNo medicines available.\n");
        return;
    }
    printf("\n----Medicine List----\n");
    for (int i = 0; i < medcount; i++) {
        struct Medicine *m = &medicines[i];

        printf("\nMedicine %d:\n", i + 1);
        printf("Name: %s\n", m->name);
        printf("Batch: %s\n", m->batch);
        printf("Expiry: %s\n", m->expiry);
        printf("Price: %d\n", m->price);
        printf("Stock: %d\n", m->stock);
    }
}

void searchmedicine() {
    char name[50];
    if (medcount == 0) {
        printf("\nNo medicines available.\n");
        return;
    }
    printf("\nEnter Medicine Name to Search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < medcount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            struct Medicine *m = &medicines[i];

            printf("\nMedicine Found!\n");
            printf("Name: %s\n", m->name);
            printf("Batch: %s\n", m->batch);
            printf("Expiry: %s\n", m->expiry);
            printf("Price: %d\n", m->price);
            printf("Stock: %d\n", m->stock);
            return;
        }
    }
    printf("\nMedicine Not Found.\n");
}

void updatemedicine() {
    char name[50];
    if (medcount == 0) {
        printf("\nNo medicines to update.\n");
        return;
    }
    printf("\nEnter Medicine Name to Update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < medcount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {

            printf("Enter New Price: ");
            scanf("%d", &medicines[i].price);
            printf("Enter New Stock: ");
            scanf("%d", &medicines[i].stock);
            printf("\nMedicine Updated Successfully!\n");
            return;
        }
    }

    printf("\nMedicine Not Found.\n");
}

void deletemedicine() {
    char name[50];
    if (medcount == 0) {
        printf("\nNo medicines to delete.\n");
        return;
    }
    printf("\nEnter Medicine Name to Delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < medcount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {

            for (int j = i; j < medcount - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medcount--;
            printf("\nMedicine Deleted Successfully!\n");
            return;
        }
    }
    printf("\nMedicine Not Found.\n");
}

// SUPPLIER FUNCTIONS
void addsupplier() {
    if (supcount >= MAX) {
        printf("\nSupplier list full!\n");
        return;
    }
    struct Supplier *s = &suppliers[supcount];

    printf("\nEnter Supplier Name: ");
    scanf(" %[^\n]", s->name);
    printf("Enter Phone No: ");
    scanf(" %[^\n]", s->phone);
    printf("Enter Company Name: ");
    scanf(" %[^\n]", s->company);

    supcount++;
    printf("\nSupplier Added Successfully!\n");
}

void viewsupplier() {
    if (supcount == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }
    printf("\n--- Supplier List ---\n");
    for (int i = 0; i < supcount; i++) {
        struct Supplier *s = &suppliers[i];

        printf("\nSupplier %d:\n", i + 1);
        printf("Name: %s\n", s->name);
        printf("Phone: %s\n", s->phone);
        printf("Company: %s\n", s->company);
    }
}
// CUSTOMER FUNCTIONS
void addcustomer() {
    if (cuscount >= MAX) {
        printf("\nCustomer list full!\n");
        return;
    }
	struct Customer *c = &customers[cuscount];

    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", c->name);
    printf("Enter Phone No: ");
    scanf(" %[^\n]", c->phone);
    printf("Enter Address: ");
    scanf(" %[^\n]", c->address);

    cuscount++;
    printf("\nCustomer Added Successfully!\n");
}

void viewcustomer() {
    if (cuscount == 0) {
        printf("\nNo customers available.\n");
        return;
    }
    printf("\n----------- Customer List -----------\n");
    for (int i = 0; i < cuscount; i++) {
        struct Customer *c = &customers[i];
        printf("\nCustomer %d:\n", i + 1);
        printf("Name: %s\n", c->name);
        printf("Phone: %s\n", c->phone);
        printf("Address: %s\n", c->address);
    }
}
// SUBMENUS
void medicinemenu() {
    int choice;
    while (1) {
        printf("\n----- Medicine Menu -----\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addmedicine();
        else if (choice == 2) viewmedicine();
        else if (choice == 3) searchmedicine();
        else if (choice == 4) updatemedicine();
        else if (choice == 5) deletemedicine();
        else if (choice == 6) break;
        else printf("Invalid Choice!\n");
    }
}

void suppliermenu() {
    int choice;
    while (1) {
        printf("\n----- Supplier Menu -----\n");
        printf("1. Add Supplier\n");
        printf("2. View Suppliers\n");
        printf("3. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addsupplier();
        else if (choice == 2) viewsupplier();
        else if (choice == 3) break;
        else printf("Invalid Choice!\n");
    }
}

void customermenu() {
    int choice;
    while (1) {
        printf("\n----- Customer Menu -----\n");
        printf("1. Add Customer\n");
        printf("2. View Customers\n");
        printf("3. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addcustomer();
        else if (choice == 2) viewcustomer();
        else if (choice == 3) break;
        else printf("Invalid Choice!\n");
    }
}

int main() {
    printf("\n....MEDICAL STORE MANAGEMENT SYSTEM....\n");
    mainMenu(); // recursive menu
    
    return 0;
}

