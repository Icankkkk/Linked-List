#include "List.h"
#include "DoubleList.h"

void menu(short int &n)
{
   cout << "1. Singly linked-list\n"
        << "2. Doubly linked-list\n"
        << "3. Exit\n\n"
        << "[1/2/3]... ? "; cin >> n;
}
// main fungsi
int main(int argc, char const *argv[])
{
    short int choice;

    do {
      // show menu
      menu(choice);
      // kondisi
      switch(choice)
      {
        case 1: switch_case(); break;
        case 2: switch_case_d(); break;
        case 3: exit(0);
      }
    } while (choice != 3);

    return 0;
}

/*
    link refrensi: 
    https://www.bitdegree.org%2Flearn%2Flinked-list-c-plus-plus
    https://www.geeksforgeeks.org/data-structures/linked-list/
*/