#include <iostream>
using namespace std;

// Regular Employees
double grossPay(float basic, float houseRentAllowance, float dailyAllowance) {
    return(basic + houseRentAllowance + (dailyAllowance / 100) * basic);
};

// Daily Wage Labourers
double grossPay(int hours, float perHour) {
    return(hours * perHour);
};

// Consolidated Employees
double grossPay(float fixedAmount) {
    return fixedAmount;
};

int main() {
    int option = -1;
    while (true) {
        cout << "1. Regular Employee\n"
             << "2. Daily Wage Labourer\n"
             << "3. Consolidated Employee\n"
             << "Press any other key to exit...\n"
             << "---> ";
        cin >> option;

        float basic, houseRentAllowance, dailyAllowance;

        int hours;
        float perHour;

        float fixedAmount;

        if (option == 1) {
            cout << "Basic : ";
            cin >> basic;
            cout << "House Rent Allowance : ";
            cin >> houseRentAllowance;
            cout << "Daily Allowance :";
            cin >> dailyAllowance;
            
            cout << "Employee wages are " <<  grossPay(basic, houseRentAllowance, dailyAllowance) << endl;
        }
        else if (option == 2) {
            cout << "hours : ";
            cin >> hours;
            cout << "Wage per hour : ";
            cin >> perHour;
            
            cout << "Employee wages are " << grossPay(hours, perHour) << endl;
        }
        else if (option == 3) {
            cout << "Fixed amount : ";
            cin >> fixedAmount;

            cout << "Employee wages are " << grossPay(fixedAmount) << endl;
        }
        else {
            break;
        };
    };
}