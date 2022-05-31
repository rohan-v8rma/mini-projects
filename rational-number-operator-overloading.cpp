#include <iostream>
using namespace::std;

class Rational {

    friend istream &operator >> (istream& in, Rational& rationalObj);
    friend ostream &operator << (ostream& out, Rational& rationalObj);

    private:
        int numerator;
        int denominator;

        void reduce() {
            int min = 2;
            while (true) {
                if ((min > numerator) && (min > denominator)) {
                    break;
                };
                while((numerator % min == 0) && (denominator % min == 0)) {
                    numerator /= min;
                    denominator /= min;
                };
                min++;
            };
        };
    public:

        Rational(int numerator = 0, int denominator = 1) {
            this -> numerator = numerator;
            this -> denominator = denominator;
        }; 

        Rational operator + (const Rational& rationalObj);
        Rational operator - (const Rational& rationalObj);
        Rational operator - (); // unary minus*
        
        double doubleValue( ) const;
};

Rational Rational::operator + (const Rational& rationalObj) {
    
    Rational sum;
    
    
    sum.numerator = numerator * rationalObj.denominator + rationalObj.numerator * denominator;
    sum.denominator = denominator * rationalObj.denominator;

    sum.reduce();

    return sum;
};

Rational Rational::operator - (const Rational& rationalObj) {
    
    Rational diff;
  
    /*
    Note that the first operand is the one whose member operator function we are accessing, 
    the second one is the one that is passed by reference
    */
    diff.numerator = numerator * rationalObj.denominator - rationalObj.numerator * denominator;
    diff.denominator = denominator * rationalObj.denominator;

    diff.reduce();

    return diff;
};

Rational Rational::operator - () {
    
    numerator *= -1;

    return *this;
};

istream& operator >> (istream& in, Rational& rationalObj) {
    
    cout << "Enter the numerator: ";
    in >> rationalObj.numerator;

    cout << "\nEnter the denominator: ";
    in >> rationalObj.denominator;

    return in;
};

ostream& operator << (ostream& out, Rational& rationalObj) {

    rationalObj.reduce(); 
    /*
    we are able to access reduce because this operator function is declared as a friend
    of the Rational class.
    */
    out << "The number is: ( " << rationalObj.numerator << " / " << rationalObj.denominator << " )\n";
    
    return out;
};

int main() {
    Rational reduceTest(144, 432);

    cout << reduceTest;
    
    Rational first(1, 3);
    Rational second(1, 6);

    // Test of binary (+) operator
    Rational sum = first + second;
    cout << sum;

    // Test of binary (-) operator
    Rational difference = first - second;
    cout << difference;

    // Test of unary (-) operator
    Rational complement = -first;
    cout << complement;

}