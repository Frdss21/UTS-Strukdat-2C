#include <iostream>
#include <string>
#include <iomanip> // Untuk mengatur jarak antar kolom tabel

using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Student {
    int NPM;
    string nama;
    float IPK;
    Student* next; // Pointer untuk linked list
};

// Fungsi untuk menambahkan mahasiswa baru ke linked list
void addStudent(Student** head, Student** students, int& numStudents) {
    Student* newStudent = new Student;
    cout << "Masukkan NPM mahasiswa: ";
    cin >> newStudent->NPM;
    cout << "Masukkan nama mahasiswa: ";
    cin.ignore();
    getline(cin, newStudent->nama);
    cout << "Masukkan IPK mahasiswa: ";
    cin >> newStudent->IPK;
    newStudent->next = *head;
    *head = newStudent;

    // Simpan pointer mahasiswa ke dalam array
    students[numStudents++] = newStudent;
}

// Fungsi untuk menampilkan daftar mahasiswa
void displayStudents(Student* head) {
    if (head == nullptr) {
        cout << "Tidak ada mahasiswa dalam daftar." << endl;
        return;
    }
    cout << "Daftar Mahasiswa:" << endl;
    cout << left << setw(10) << "NPM" << setw(20) << "Nama" << setw(10) << "IPK" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    Student* current = head;
    while (current != nullptr) {
        cout << left << setw(10) << current->NPM << setw(20) << current->nama << setw(10) << fixed <<
        setprecision(2) << current->IPK << endl;
        current = current->next;
    }
}

// Fungsi untuk menampilkan daftar mahasiswa dari array
void displayStudentsFromArray(Student** students, int numStudents) {
    cout << "Daftar Mahasiswa (dari array):" << endl;
    cout << left << setw(10) << "NPM" << setw(20) << "Nama" << setw(10) << "IPK" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    for (int i = 0; i < numStudents; i++) {
        Student* current = students[i];
        cout << left << setw(10) << current->NPM << setw(20) << current->nama << setw(10) << fixed <<
        setprecision(2) << current->IPK << endl;
    }
}

int main() {
    Student* head = nullptr; // Pointer ke head linked list
    int choice;

    // Array pointer untuk menyimpan data mahasiswa
    Student* students[10];
    int numStudents = 0;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah mahasiswa" << endl;
        cout << "2. Tampilkan daftar mahasiswa" << endl;
        cout << "3. Tampilkan daftar mahasiswa dari array" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(&head, students, numStudents);
                break;
            case 2:
                displayStudents(head);
                break;
            case 3:
                displayStudentsFromArray(students, numStudents);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 4);

    // Bebaskan memori yang dialokasikan untuk linked list
    Student* current = head;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
