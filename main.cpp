#include <iostream>
#include <string>
#include "GroupProjects_stack.h"
#include "doubleLinkedList.h"
using namespace std;
#include "Student.h"

// print students function
void print_students(DoubleLinkedList<Student> &students, int group_number) {
    for (int i = 0; i < students.getSize(); i++) {
        if (students.get_element(i).Get_group_number() == group_number) {
            students.get_element(i).print();
        }
    }
}


int main(){

    DoubleLinkedList<Student> Students;
    

    // create a new students.txt file and write the 6 students data to it    
    ofstream students_file;
    students_file.open("students.txt");
    students_file << "fahrettin Smith 20 1" << endl;
    students_file << "onur Doe 21 2" << endl;
    students_file << "musa Doe 22 4" << endl;
    students_file << "merve Smith 23 2" << endl;
    students_file << "korku Smith 24 1" << endl;
    students_file << "soren Doe 25 3" << endl;
    students_file.close();


    // instert students for 2 groups from a file
    ifstream file;
    file.open("students.txt");
    //is file open check

    if(!file.is_open()){
        cout << "file is not open" << endl;
    }
    else{
        int group_counter = 0;
        string name, surname;
        int age, year_of_school, group_number;
        while(!file.eof()){
            file >> name >> surname >> age >> year_of_school;
            Student student(name, surname, age, year_of_school);
            if(group_counter % 2 == 0){
                student.set_group(1);
            }
            else{
                student.set_group(2);
            }
            Students.instert_end(student);
            group_counter++;
        }
    }
    file.close();
    cout << "Students are insterted" << endl;

    // print all students from group 1
    cout << "Students from group 1:" << endl;
    print_students(Students, 1);
    cout << endl;
    // print all students from group 2
    cout << "Students from group 2:" << endl;
    print_students(Students, 2);
    cout << endl;
    
    string works_to_do[10] = {"work1", "work2", "work3", "work4", "work5", "work6", "work7", "work8", "work9", "work10"};
    MineStack<string> works_to_do_stack;

    for (int i = 0; i < 10; i++) {
        works_to_do_stack.push(works_to_do[i]);
        cout << works_to_do[i] << endl;
    }

    // assign works for every student
    for (int i = 0; i < Students.getSize(); i++) {
        if(Students.get_element(i).Get_group_number() == 1){
            Students.get_element(i).set_work(works_to_do_stack.pop());
            cout << "I did for one" << endl;
        }
        else if(Students.get_element(i).Get_group_number() == 2){
            Students.get_element(i).set_work(works_to_do_stack.pop());
            cout << "I did for two" << endl;
        }
        else{
            cout << "error" << endl;
        }
    }
    

    
    return 0;
}