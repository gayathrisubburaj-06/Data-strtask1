#include <iostream>
#include <string>
using namespace std;

struct Node {
    string item;
    Node* next;
};

Node* head = NULL;

// Add an item
void addItem(string item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Remove an item
void removeItem(string item) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->item != item) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Item not found\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Item removed\n";
}

// Search an item
void searchItem(string item) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->item == item) {
            cout << "Item found\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Item not found\n";
}

// Display all items
void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "Shopping list is empty\n";
        return;
    }

    cout << "\nShopping List:\n";
    while (temp != NULL) {
        cout << temp->item << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string item;

    do {
        cout << "\n--- Shopping List ---\n";
        cout << "1. Store item\n";
        cout << "2. Add an item\n";
        cout << "3. Remove an item\n";
        cout << "4. Search for an item\n";
        cout << "5. Display all items\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Item stored using linked list.\n";
                break;

            case 2:
                cout << "Enter item: ";
                cin >> item;
                addItem(item);
                break;

            case 3:
                cout << "Enter item to remove: ";
                cin >> item;
                removeItem(item);
                break;

            case 4:
                cout << "Enter item to search: ";
                cin >> item;
                searchItem(item);
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
