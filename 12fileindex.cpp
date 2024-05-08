#include <iostream>
#include <fstream>

using namespace std;

class Employee {
private:
    int employee_id;
    char name[50];
    char post[50];
    float salary;

public:
    void setData() {
        cout << "\nEnter Employee ID: ";
        cin >> employee_id;
        cout << "Enter Name of Employee: ";
        cin.ignore(); 
        cin.getline(name, 50);
        cout << "Enter Post of Employee: ";
        cin.getline(post, 50);
        cout << "Enter Salary of Employee: ";
        cin >> salary;
    }

    void showData() {
        cout << "\n\tEmployee ID: " << employee_id;
        cout << "\n\tEmployee Name: " << name;
        cout << "\n\tEmployee Post: " << post;
        cout << "\n\tEmployee Salary: " << salary << endl;
    }

    int getEmployeeId() {
        return employee_id;
    }
};

void writeRecord() {
    ofstream outFile("Employee.dat", ios::binary | ios::app);
    Employee obj;
    obj.setData();
    outFile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
    outFile.close();
}

void display() {
    ifstream inFile("Employee.dat", ios::binary);
    Employee obj;
    while (inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        obj.showData();
    }
    inFile.close();
}

void search(int n) {
    ifstream inFile("Employee.dat", ios::binary);
    Employee obj;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        if (obj.getEmployeeId() == n) {
            cout << "\nRecord found!";
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

void deleteRecord(int n) {
    ifstream inFile("Employee.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary | ios::out);
    Employee obj;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        if (obj.getEmployeeId() != n) {
            outFile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("Employee.dat");
    rename("temp.dat", "Employee.dat");

    if (found) {
        cout << "\nRecord deleted!";
    } else {
        cout << "\nRecord not found!";
    }
}

void modifyRecord(int n) {
    fstream file("Employee.dat", ios::in | ios::out | ios::binary);
    Employee obj;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        if (obj.getEmployeeId() == n) {
            cout << "\nEnter new details of Employee";
            obj.setData();
            long pos = file.tellg();
            file.seekp(pos - sizeof(obj), ios::beg);
            file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
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
        cout << "\n****** Menu ******";
        cout << "\n1. Add Employee";
        cout << "\n2. Display Employee";
        cout << "\n3. Search Employee";
        cout << "\n4. Delete Employee";
        cout << "\n5. Modify Employee";
        cout << "\n6. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                writeRecord();
                break;

            case 2:
                display();
                break;

            case 3:
                int s;
                cout << "\nEnter Employee ID to be searched: ";
                cin >> s;
                search(s);
                break;

            case 4:
                int d;
                cout << "\nEnter Employee ID to be deleted: ";
                cin >> d;
                deleteRecord(d);
                break;

            case 5:
                int m;
                cout << "\nEnter Employee ID to be modified: ";
                cin >> m;
                modifyRecord(m);
                break;

            case 6:
                cout << "\nThanks for using this program!";
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }
    } while (ch != 6);

    return 0;
}
