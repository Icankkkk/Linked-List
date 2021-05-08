#include <iostream>
#include <string>
using std::cout; using std::cin; using std::string;

// class node
class Node {
    public:
    int data;
    string nama;
    char grade;

    Node *next;
};

// fungsi untuk mencetak seluruh node
void print_list(Node *n) {
    while (n != nullptr)    // jika pointer tidak = null, maka terus mencetak
    {
        cout << n -> data << ' ';
        cout << n -> nama << ' ';
        cout << n -> grade << ' ';
        cout << '\n';
        n = n->next;    // menunjuk n ke node next
    }
    cout << '\n';
}

// fungsi untuk mengisi data pada sebuah node
void fill_data(Node *n) {
    cout << "input nilai\t: "; cin >> n -> data;    // membaca atribut data (integer)
    cout << "input nama\t: "; cin >> n -> nama;    // membaca atribut nama (string)
    cout << "input grade\t: "; cin >> n -> grade;   // membaca atribut grade (char)
}

// fungsi tambah depan (head)
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

// fungsi tambah belakang
void push_back(struct Node ** head_ref) {
    struct Node *new_node = new Node();
    struct Node *last = *head_ref;
    fill_data(new_node);
    new_node -> next = nullptr;

    // kondisi
    while (last -> next != nullptr)
    last = last -> next;
    last -> next = new_node;
    
}

void swicth_case() {
    
    Node *head = nullptr;   // deklarasi atau inisialisasi awal
 
    /* alokasi 
    head = new Node();

    // node default
    head -> data = 100;
    head -> nama = "dimas";
    head -> grade = 'A';
    head -> next = nullptr; */

    int pil;    // untuk switch case

      do {
        cout << "\n1. push head\n"
             << "2. push back\n"
             << "3. print\n"
             << "4. exit\n\n"
             << "Masukan pilihan\t: "; cin >> pil;

        switch(pil) {
            case 1: push_head(&head); break;
            case 2: push_back(&head); break;
            case 3: print_list(head); break;
            case 4: exit(0); break;
            default: cout << "Tidak tersedia\n"; break;
        }
    } while(pil != 4); // looping
}

// main fungsi
int main(int argc, char const *argv[])
{
   
   // second = new Node();

    // head
  /*  head -> data = 20;
    head -> nama = "Faisal";
    head -> grade = 'A';
    head -> next = second;

    // second node
    second -> data = 30;
    second -> nama = "kevin";
    second -> grade = 'B';
    second -> next = nullptr; */

    // output
  /*  push_head(&head, 18, "fadia", 'C');
    push_head(&head, 17, "budi", 'A');
    push_head(&head, 20, "dimas", 'B'); */

 /*   push_head(&head);
    head -> next = nullptr;
    print_list(head);
    push_head(&head);
    cout << "Setelah di tambah\n";
    print_list(head); */

    swicth_case();  // memanggil fungsi

    return 0;
}

/*
    link refrensi : www.bitdegree.org%2Flearn%2Flinked-list-c-plus-plus
*/