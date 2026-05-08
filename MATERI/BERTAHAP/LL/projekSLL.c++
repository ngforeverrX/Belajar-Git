#include <iostream>
#include <limits>
using namespace std; 

// Memutar musik menggunakan single linked list

struct Node {
    string lagu;
    Node* next;
};

Node* head = NULL;

// insert belakang
void tambahLagu(string judul) {
    Node* laguBaru = new Node();
    laguBaru->lagu = judul;
    laguBaru->next = nullptr;

    
    if (head == NULL) {
        head = laguBaru;
    } else{
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = laguBaru;
    }
    cout << "lagu berhasil ditambahkan\n";
}

// hapus depan
void putarLagu() {
    if (head == NULL) {
        cout << "Lagu Kosong\n";
        return;
    }

    Node* temp = head;
    cout << "Sedang Memutar: " << temp->lagu << endl;
    head = head->next;
    delete temp;
}

//traversal - tampilkan
void tampilkanLagu() {
    if (head == NULL) {
        cout << "Lagu Kosong\n";
        return;
    }

    Node* temp = head;
    int nomor = 1;
    cout << "Semua Lagu: \n";
    while(temp != NULL) {
        cout << nomor << ". " << temp->lagu << endl;
        nomor++;
        temp = temp->next;       
    }
}

// cari node - judul lagu
void cariLagu(string judul) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->lagu == judul) {
            cout << "Lagu ditemukan dengan Judul: " << temp->lagu << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Lagu tidak ditemukan\n";
}

//hapus node - hapus lagu 
// void hapusLagu(string judul) {

// }

int main() {
    int menu;
     
    do {
        cout << "\n======= MENU =======\n";
        cout << "1. Tambah Lagu \n2. Putar Lagu \n3. Tampilkan Lagu"
                 "\n4. Cari Lagu \n5. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (menu) {                
            case 1: {
                string tambahJudul;
                cout << "Tambah Lagu: ";
                getline(cin, tambahJudul);
                tambahLagu(tambahJudul);
                break;
            }

            case 2:
                putarLagu();
                break;
            
            case 3:
                tampilkanLagu();
                break;
            
            case 4: {
                if (head == NULL) {
                cout << "Lagu Kosong \n";
                break;     
                }

                string cari;
                cout << "Judul Lagu: ";
                getline(cin, cari);
                cariLagu(cari);
                break;
            }

            case 5:
                cout << "Program Selesai";
                break;
            
            default:
                cout << "Pilihan tidak valid\n";
        }  
    } while (menu != 5);       
    return 0;
}