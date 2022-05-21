#include <iostream>
#include <string.h>
using namespace::std;

class Student {
    public:
        string name;
        int reg_no;
        int fees;

        Student (string name, int reg_no, int fees=200000) {
            this->fees = fees;
            this->name = name;
            // strcpy(this->name, name);
            this->reg_no = reg_no;
        };
};

class AcadExcel : public Student {
    public:
        char cgpa;
        int income;

        AcadExcel();

        AcadExcel(string name, int reg_no, char cgpa, int income)
        : Student(name, reg_no) {
            this->cgpa = cgpa;
            this->income = income;

            if ((this->cgpa == 's') && (this->income < 30000)) {
                fees *= 0; // we need not use `this` pointer with fees because there is no local fees variable
            }
            else if ((this->cgpa == 'a') && ((31000 < this->income)) && (this->income < 100000)) {
                fees *= 0.5;
            };
            cout << "Congratulations " << name << "! Your fees is " << fees << endl;
        };
};

class Sport : public Student {
    public: 
        char sport_level; // State (S) / National (N) / International (I)
        int games_played;

        // Sport() {};

        Sport(string name, int reg_no, char sport_level, int games_played)
        : Student(name, reg_no) {
            this->sport_level = sport_level;
            this->games_played = games_played;

            if ((this->sport_level == 'i') && (this->games_played > 2)) {
                fees *= 0;
            }
            else if ((this->sport_level == 'n') && (this->games_played > 10)) {
                fees *= 0.5;
            }
            else if ((this->sport_level == 's') && ((30 > this->games_played) && (this->games_played > 20))) {
                fees *= 0.25;
            };

            cout << "Congratulations " << name << "! Your fees is " << fees << endl;
        };
};

int main() {
    AcadExcel rohan("rohan", 21, 's', 15000);
    Sport prerit("prerit", 20, 'i', 1);

    return 0;
}