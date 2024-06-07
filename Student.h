#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
private:
    std::string _name;
    int _id;
    int _note;
public:
    Student(std::string name, int id, int note);
    void setad(std::string name);
    void setid(int id);
    void setnote(int note);

    std::string getad();
    int getid();
    int getnote();
    void writeinformation();
};

#endif

