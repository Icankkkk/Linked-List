#include "Library.h"

#ifndef LINKED_LIST
#define LINKED_LIST

// class node
class Node {
public:         // akses modifier
    string nim;       // untuk nilai
    string nama;    // untuk nama
    short int nilai;     // untuk grade

    Node *next;     // pointer
};

// fungsi untuk mencetak seluruh node
void print_list(Node *n) {
    short int data = 1;

    cout << "\nData didalam list:\n";
    while (n != nullptr)    // jika pointer tidak = null, maka terus mencetak
    {
        cout << "Node ke-" << data++ << ":\n";
        cout << "Nim\t: " << n -> nim << '\n';
        cout << "Nama\t: " << n -> nama << '\n';
        cout << "Nilai\t: " << n -> nilai << '\n';
        newLine;        // newline
        n = n->next;    // menunjuk n ke node next
    }
    newLine;   // newline
}

// fungsi untuk mengisi data pada sebuah node
void fill_data(Node *value) {
    cout << "Inputkan NIM anda\t: "; cin >> value -> nim;    // membaca atribut data (integer)
    cout << "Inputkan Nama anda\t: "; cin >> value -> nama;    // membaca atribut nama (string)
    cout << "Inputkan Nilai anda\t: "; cin >> value -> nilai;   // membaca atribut grade (char)
}

// fungsi untuk tambah depan (head)
void push_head(Node **head_ref) { //, int new_data, string new_nama, char new_grade ) {
    Node *new_node = new Node(); // alokasi
   
   /* new_node->data = new_data;
    new_node->nama = new_nama;
    new_node->grade = new_grade; */
    
   /* cout << "input nilai\t: "; cin >> new_node -> data;    // membaca atribut data (integer)
    cout << "input nama\t: "; cin >> new_node -> nama;    // membaca atribut nama (string)
    cout << "input grade\t: "; cin >> new_node -> grade;   // membaca atribut grade (char)
    */ 

    fill_data(new_node); // mengisi data pada  node
    new_node -> next = *head_ref;   // pointer to pointer
    *head_ref = new_node;
}

// fungsi untuk tambah belakang
void push_back(Node **head_ref) {
    Node *new_node = new Node();
    Node *last = *head_ref;
    
    fill_data(new_node);
    new_node -> next = nullptr;

    // kondisi
    while (last -> next != nullptr) 
        last = last -> next;
        last -> next = new_node;  
}

// fungsi untuk tambah ditengah node (diantara head & back)
void push_prev(Node *prev_ref) {
    if (prev_ref == nullptr)
    {
        printf("NULL");
        return;
    }
    // alokasi node baru
    Node *new_node = new Node();

    // mengisi value
    fill_data(new_node);
    new_node -> next = prev_ref -> next;
    prev_ref -> next = new_node; 
}

// fungsi untuk mengapus node sesuai posisi
void deleteNode(Node **head_ref, short int &pos) {
    // jika linkedlist kosong
    if (*head_ref == nullptr)
    return;
    // store head node
    Node *temp = *head_ref;
    // memberikan posisi node sesuai input
    cout << "posisi keberapa yang ingin di hapus ?\n"
         << "key : "; cin >> pos;
    // If head needs to be removed
    if (pos == 0)
    {
        // change head
        *head_ref = temp->next;
        // free head lama
        delete(temp);
        return;
    }
    // Find previous node of the node to be deleted
    for (int i = 0; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;
        // If position is more than number of nodes
        if (temp == nullptr || temp->next == nullptr)
        return;
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node *next = temp->next->next;
    // Unlink the node from linked list
    delete(temp->next);
    // unlink the deleted node from list
    temp->next = next;    
}

// fungsi untuk delete seluruh node atau list
void deleteList(Node **head_ref) {
    Node *current = *head_ref;
    Node * next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete(current);
        current = next;
    }
    *head_ref = nullptr;
}

// fungsi untuk exit
void exit(string status) {
    cout << "Keluar dari menu singly linked-list...\n";
    sleep(2);
    system("clear");
}

void switch_case() {
    
    Node *head = nullptr;   // deklarasi atau inisialisasi awal
    short int pil, posisi;    // untuk switch case

    /* alokasi 
    head = new Node();

    // node default
    head -> data = 100;
    head -> nama = "dimas";
    head -> grade = 'A';
    head -> next = nullptr; */
    system("clear");
    cout << "SINGLY LINKED-LIST\n"
             << "1. push head\n"
             << "2. push back\n"
             << "3. push prev\n"
             << "4. print\n"
             << "5. delete node\n"
             << "6. delete list\n"
             << "7. exit\n\n";
    do {
        
        cout << "Masukan pilihan\t: "; cin >> pil;

        switch(pil) 
        {
            case 1: push_head(&head); break;    // sisip depan
            case 2: push_back(&head); break;    // sisip belakang
            case 3: push_prev(head); break;     // sisip tengah
            case 4: print_list(head); break;    // cetak list
            case 5: deleteNode(&head, posisi); break;   // hapus node
            case 6: deleteList(&head); break;   // hapus semua node
            case 7: exit("keluar dari menu singly-list...\n"); break; // keluar program
            // jika submit selain 1-6
            default: printf("Tidak ada didalam daftar!\n\n"); break;
        }
    } while(pil != 7); // looping
}

#endif // !LINKED_LIST