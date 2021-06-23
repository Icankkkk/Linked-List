#include "Library.h"

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

// class node untuk doubly linked list
class Node_d {
public:    
    short int nilai;
    Node_d *next;   // pointer untuk node next di DDL
    Node_d *prev;   // pointer untuk node previous di DDL    
};

// fungsi untuk mengisi data
void fill(Node_d *value) {
    cout << "Inputkan nilai\t: "; cin >> value -> nilai;
}

// fungsi untuk mencetak list
void printList(Node_d *node) {
    while (node != nullptr)
    {
        cout << "Nilai\t: " << node->nilai;
        newLine;    // pindah baris
        node = node->next;
    }
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(Node_d **head_ref) {
    // alokasi node baru
    Node_d *new_node = new Node_d();
    // menggunakan fungsi untuk mengisi data
    fill(new_node);
    // Make next of new node as head and previous as NULL
    new_node->next = *head_ref;
    new_node->prev = nullptr;
    // change prev of head node to new node
    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;
    // move the head to point to the new node
    *head_ref = new_node;
}   

// fungsi untuk exit
void exit_d() {
    cout << "Keluar dari menu doubly linked-list...\n";
    sleep(2);
    system("clear");
}

void switch_case_d() {
    Node_d * head = nullptr;    // deklarasi awal
    short int choice;

    system("clear");
    do {
        cout << "DOUBLY LINKED-LIST\n"
             << "1. push\n"
             << "2. insert after (dalam proses...)\n"
             << "3. append (dalam proses...)\n"
             << "4. insert before (dalam proses...)\n"
             << "5. print list\n"
             << "6. exit\n\n"
             << "masukan pilihan : "; cin >> choice;
        
        switch(choice) {
            case 1: push(&head); break;
            case 5: printList(head); break;
            case 6: exit_d(); break;
            default: printf("Tidak ada didalam daftar!\n"); break;
        }
    } while (choice != 6);
}

#endif // !DOUBLE_LINKED_LIST