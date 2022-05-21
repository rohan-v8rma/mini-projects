#include <iostream>
#include <string.h>

class Student {
    public:
        std::string name;
        int reg_no;
        int fees;

        Student (std::string name_parameter, int reg_no_parameter, int fees_parameter=200000) {
            fees = fees_parameter;
            name = name_parameter;
            // strcpy(name, name_parameter);
            reg_no = reg_no_parameter;
        };
};

class AcadExcel : public Student {
    public:
        char cgpa;
        int income;

        AcadExcel();

        AcadExcel(std::string name_parameter, int reg_no_parameter, char cgpa_parameter, int income_parameter)
        : Student(name_parameter, reg_no_parameter) {
            cgpa = cgpa_parameter;
            income = income_parameter;

            if ((cgpa == 's') && (income < 30000)) {
                fees *= 0;
            }
            else if ((cgpa == 'a') && (31000 < income < 100000)) {
                fees *= 0.5;
            };
            std::cout << "Congratulations " << name << "! Your fees is " << fees << std::endl;
        };
};

class Sport : public Student {
    public: 
        char sport_level; // State (S) / National (N) / International (I)
        int games_played;

        // Sport() {};

        Sport(std::string name_parameter, int reg_no_parameter, char sport_parameter, int game_parameter)
        : Student(name_parameter, reg_no_parameter) {
            sport_level = sport_parameter;
            games_played = game_parameter;

            if ((sport_level == 'i') && (games_played > 2)) {
                fees *= 0;
            }
            else if ((sport_level == 'n') && (games_played > 10)) {
                fees *= 0.5;
            }
            else if ((sport_level == 's') && (30 > games_played > 20)) {
                fees *= 0.25;
            };

            std::cout << "Congratulations " << name << "! Your fees is " << fees << std::endl;
        };
};

int main() {
    AcadExcel rohan("rohan", 21, 's', 15000);
    Sport prerit("prerit", 20, 'i', 1);

    return 0;
}