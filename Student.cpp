#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(string name, int id, int note) {
    _name = name;
    _id = id;
    _note = note;
}

void Student::setad(string name) {
    _name = name;
}
void Student::setid(int id) {
    _id = id;
}
void Student::setnote(int note) {
    _note = note;
}

string Student::getad() {
    return _name;
}

int Student::getid() {
    return _id;
}

int Student::getnote() {
    return _note;
}

void Student::writeinformation() {
    cout << "Name: " << _name << "  Id: " << _id << "  Note: " << _note << endl;
}
