#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    int roll_no;
    char name[50];
    char addr[50];

public:
    void setData() {
        cout << "\nEnter Roll No.: ";
        cin >> roll_no;

        cout << "Enter name of student: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter the address of the student: ";
        cin.getline(addr, 50);
    }

    void showData() {
        cout << "\nRoll No.: " << roll_no;
        cout << "\nName: " << name;
        cout << "\nAddress: " << addr << endl;
    }

    int retroll_no() {
        return roll_no;
    }
};

void write_record() {
    ofstream outFile("student.dat", ios::binary | ios::app);
    if (!outFile) {
        cout << "File could not be opened!";
        return;
    }
    Student obj;
    obj.setData();
    outFile.write((char*)&obj, sizeof(obj));
    outFile.close();
}

void display() {
    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened!";
        return;
    }
    Student obj;
    while (inFile.read((char*)&obj, sizeof(obj))) {
        obj.showData();
    }
    inFile.close();
}

void search(int n) {
    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened!";
        return;
    }
    Student obj;
    bool found = false;
    while (inFile.read((char*)&obj, sizeof(obj))) {
        if (obj.retroll_no() == n) {
            obj.showData();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nRecord not found!";
    }
    inFile.close();
}

void delete_record(int n) {
    ifstream inFile("student.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    if (!inFile || !outFile) {
        cout << "File could not be opened!";
        return;
    }
    Student obj;
    while (inFile.read((char*)&obj, sizeof(obj))) {
        if (obj.retroll_no() != n) {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }
    inFile.close();
    outFile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    cout << "\nRecord deleted!";
}

void modify_record(int n) {
    fstream file("student.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File could not be opened!";
        return;
    }
    Student obj;
    bool found = false;
    while (file.read((char*)&obj, sizeof(obj))) {
        if (obj.retroll_no() == n) {
            cout << "\nEnter new details for the student:";
            obj.setData();
            long pos = file.tellg();
            file.seekp(pos - sizeof(obj));
            file.write((char*)&obj, sizeof(obj));
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nRecord not found!";
    }
    file.close();
}

int main() {
    int ch;
    do {
        cout << "\n**** Menu ****";
        cout << "\n1. Write";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Modify";
        cout << "\n6. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter number of records: ";
                int n;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    write_record();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "\nEnter Roll No to be searched: ";
                int s;
                cin >> s;
                search(s);
                break;
            case 4:
                cout << "\nEnter Roll No to be deleted: ";
                int d;
                cin >> d;
                delete_record(d);
                break;
            case 5:
                cout << "\nEnter Roll No to be modified: ";
                int m;
                cin >> m;
                modify_record(m);
                break;
            case 6:
                cout << "\nThanks for using this program!";
                break;
            default:
                cout << "\nInvalid choice. Try again.";
        }
    } while (ch != 6);

    return 0;
}
