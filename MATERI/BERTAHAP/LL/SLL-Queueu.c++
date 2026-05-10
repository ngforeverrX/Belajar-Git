#include <iostream>
using namespace std;

struct Node {
    string nama;
    string keluhan;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void tambahAntrean(string nama, string keluhan) {       //Enqueue
    Node* pasienBaru = new Node();
    pasienBaru->nama = nama;
    pasienBaru->keluhan = keluhan;
    pasienBaru->next = nullptr;

    if (front == NULL && rear == NULL) {
        front = rear = pasienBaru;
    } else {
        rear->next = pasienBaru;
        rear = pasienBaru;
    }

}

void panggilAntrean() {     //Dequeue
    if (front == NULL) {
        cout << "Antrian pasien kosong\n";
        return;
    }

    Node* hapus = front;
    cout << "Pasien dengan nama: " << hapus->nama << "dengan keluhan: " << hapus->keluhan << "telah keluar\n";
    front = hapus->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete hapus;
}

void tamppilkanPasien() {
    if (front == NULL) {
        cout << "Antrian pasien kosong\n";
        return;
    }

    Node* temp = front;
    int nomor = 1;
    cout << "Semua pasien: \n";
    while (temp != NULL){
        cout << nomor << ". " << "Nama: " << temp->nama << " Keluahan: " << temp->keluhan << endl;
        nomor++;
        temp = temp->next;
    }   
}


int main() {

}