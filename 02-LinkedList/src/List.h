
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string;

#ifndef LINKED_LIST
#define LINKED_LIST
#define newLine cout << '\n';

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
    while (n != nullptr)    // jika pointer tidak = null, maka terus mencetak
    {
        cout << n -> nim << ' ';
        cout << n -> nama << ' ';
        cout << n -> nilai << ' ';
        newLine;        // newline
        n = n->next;    // menunjuk n ke node next
    }
    newLine;   // newline
}

// fungsi untuk mengisi data pada sebuah node
void fill_data(Node *value) {
    cout << "Input NIM\t: "; cin >> value -> nim;    // membaca atribut data (integer)
    cout << "Input Nama\t: "; cin >> value -> nama;    // membaca atribut nama (string)
    cout << "Input Nilai\t: "; cin >> value -> nilai;   // membaca atribut grade (char)
}

// fungsi untuk tambah depan (head)
void push_head(struct Node **head_ref) { //, int new_data, string new_nama, char new_grade ) {
    struct Node *new_node = new Node(); // alokasi
   
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
void push_back(struct Node **head_ref) {
    struct Node *new_node = new Node();
    Node *last = *head_ref;
    
    fill_data(new_node);
    new_node -> next = nullptr;

    // kondisi
    while (last -> next != nullptr) 
        last = last -> next;
        last -> next = new_node;  
}

// fungsi untuk tambah ditengah node (diantara head & back)
void push_prev(struct Node *prev_ref) {
    if (prev_ref == nullptr)
    {
        printf("node yang diberikan sebelumnya tidak boleh NULL");
        return;
    }
    // alokasi node baru
    struct Node *new_node = new Node();

    // mengisi value
    fill_data(new_node);
    new_node -> next = prev_ref -> next;
    prev_ref -> next = new_node; 
}

void switch_case() {
    
    Node *head = nullptr;   // deklarasi atau inisialisasi awal
    short int pil;    // untuk switch case
 
    /* alokasi 
    head = new Node();

    // node default
    head -> data = 100;
    head -> nama = "dimas";
    head -> grade = 'A';
    head -> next = nullptr; */

    do {
        newLine;
        cout << "1. push head\n"
             << "2. push back\n"
             << "3. push prev\n"
             << "4. print\n"
             << "5. exit\n\n"
             << "Masukan pilihan\t: "; cin >> pil;

        switch(pil) 
        {
            case 1: push_head(&head); break;
            case 2: push_back(&head); break;
            case 3: push_prev(head); break;
            case 4: print_list(head); break;
            case 5: exit(0); break;
            // jika submit selain 1-5
            default: printf("Tidak ada didalam daftar!\n"); break;
        }
    } while(pil != 5); // looping
}

#endif // !LINKED_LIST