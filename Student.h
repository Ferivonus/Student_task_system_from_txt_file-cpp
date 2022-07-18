#include <string>
#include <iostream>
#include <fstream>

namespace std{

    class Student{
    private:
        string name, surname, full_Name, work_to_do;
        int age, year_of_school, group_number;
        bool is_in_group = false;
        bool is_work_done = false;
        
    public:
        Student(string name, string surname, int age, int year_of_school) {
            this->name = name;
            this->surname = surname;
            full_Name = name + " " + surname;
            this->age = age;
            this->year_of_school = year_of_school;
            this->work_to_do = work_to_do;
        }

        Student(){
            name = "";
            surname = "";
            full_Name = "";
            work_to_do = "";
            age = 0;
            year_of_school = 0;
            group_number = 0;
            is_in_group = false;
            is_work_done = false;
        }
        void set_group(int group_number) {
            this->group_number = group_number;
            is_in_group = true;
        }
        void set_work(string work_to_do) {
            this->work_to_do = work_to_do;
        }

        void print(){
            cout << full_Name << " " << age << endl;
        }

        friend ostream& operator<<(ostream& os, const Student& student) {
            os <<"the students name and surname is that, "<< student.full_Name << " and age is " << student.age;
            if(student.is_work_done){
                os << " he did " << student.work_to_do;
            }
            else{
                os << " he is working on " << student.work_to_do;
            }
            os << endl;
            return os;
        }
        
        void work_done(){
            is_work_done = true;
        }

        void Set_name(string name){
            this->name = name;
        }
        
        void Set_surname(string surname){
            this->surname = surname;
        }

        void Set_age(int age){
            this->age = age;
        }
        
        void Set_year_of_school(int year_of_school){
            this->year_of_school = year_of_school;
        }

        int Get_group_number(){
            return group_number;
        }

        

        friend istream& operator>>(istream& is, Student& student) {
            cout << "enter the students name: ";
            is >> student.name;
            cout << "enter the students surname: ";
            is >> student.surname;
            cout << "enter the students age: ";
            is >> student.age;
            cout << "enter the students year of school: ";
            is >> student.year_of_school;
            return is;
        }

        ~Student() {}
    };

    
}

