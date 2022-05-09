#include <stdio.h>
#include <string.h>

struct employee_details {
    char name;
    float salary;
    int work_hours;
};

int main() {
    struct employee_details employee_list[10];
    
    char name = 'a';
    int work_hours = 4;
    
    for(int index = 0; index < 10; index++) {
        employee_list[index].name = name;
        name += 1;
        
        employee_list[index].salary = 0;
        
        employee_list[index].work_hours = work_hours;
        work_hours += 1;
        
    }
    
    //Salary Increase
    for(int index = 0; index < 10; index++) {
        if (employee_list[index].work_hours >= 12) {
            employee_list[index].salary += 150;
        }
        else if (employee_list[index].work_hours >= 10) {
            employee_list[index].salary += 100;
        }
        else if (employee_list[index].work_hours >= 8) {
            employee_list[index].salary += 50;
        };
    }
    for(int index = 0; index < 10; index++) {
        printf("%d %f\n", employee_list[index].work_hours, employee_list[index].salary);
    }
    
    return 0;
}