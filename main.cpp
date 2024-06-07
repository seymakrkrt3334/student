#include<iostream>
#include<iomanip>
#include "Student.h"
#include<list>
using namespace std;

void menu() {
    cout << setfill('*') << setw(20) << "" << " MENU " << setw(20) << "" << setfill('*') << endl;
    cout << "1. Add new record" << endl;
    cout << "2. Show entire list" << endl;
    cout << "3. Delete registration according to student ID" << endl;
    cout << "4. Search for students" << endl;
    cout << "5. Exit" << endl << endl;
}

void registered(list<Student>* lst) {
    string name, surname, completename;
    int id;
    int note;
    cout << "Name:";
    cin >> name >> surname;
    completename = name + " " + surname;
    cout << "ID:";
    cin >> id;
    cout << "Note:";
    cin >> note;
    Student a(completename, id, note);
    lst->push_back(a);

    if (note >= 90 && note < 100) {
        cout << "AA" << endl;
    }
    else if (note < 90 && note >= 85) {
        cout << "BA" << endl;

    }
    else if (note < 85 && note >= 80) {
        cout << "BB" << endl;
    }
    else if (note < 80 && note >= 70) {
        cout << "CB" << endl;
    }
    else if (note < 70 && note >= 60) {
        cout << "CC" << endl;
    }
    else {
        cout << " you are unsuccessful" << endl;
    }

}

void show(list<Student>* lst) {
    list<Student>::iterator it;
    cout << endl << "- - - - - - - - -All of Students as list- - - - - - - - -" << endl;
    for (it = lst->begin(); it != lst->end(); it++) {
        it->writeinformation();
    }
}

void delete_student(list<Student>* lst) {
    int id;
    cout << "please enter id number of student wanting to delete:";
    cin >> id;
    for (auto it = lst->begin(); it != lst->end();) {
        if (it->getid() == id) {
            it = lst->erase(it); // it yeni geçerli iteratör olur
        }
        else {
            ++it;
        }
    }
}

void search(list<Student>* lst) {
    int id;
    cout << "please enter id number of student wanting to search:";
    cin >> id;
    for (auto it = lst->begin(); it != lst->end(); ++it) {
        if (it->getid() == id) {
            cout << endl << "informations of student which you search: " << endl;
            it->writeinformation();
            cout << endl;
        }
    }
}

int main() {

    list<Student>* studentlist = new list<Student>();

    int choice;
    do {
        menu();
        cout << "Your choice (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            registered(studentlist);
            break;
        case 2:
            show(studentlist);
            break;
        case 3:
            delete_student(studentlist);
            break;
        case 4:
            search(studentlist);
            break;
        case 5:
            cout << "Exited" << endl;
            break;
        default:
            cout << "Your choice is mistake!!!" << endl;
            break;
        }
    } while (choice != 5);

    delete studentlist;
    return 0;
}
