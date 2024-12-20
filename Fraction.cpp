#include <iostream>
#include <numeric>


class Fraction{
    private:
    int numerator;
    int denominator;
    
    void Simplify() {
        //divide numerator and denominator by gcd
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        
        if (denominator < 0 ) {
            denominator *= -1;
            numerator *= -1;
        }
    }
    
    
    public:
    
    Fraction(int num = 0, int den= 1) : 
    numerator(num),
    denominator(den) {
        //check if denominator == 0 , that's a problem
        
        if (denominator == 0) {
            std::cout << " The denominator can't bew zero";
        }
        Simplify();
    }
    
    int GetNumerator() const {
        return numerator;
    }
    
    int GetDenominator() const {
        return denominator;
    }
    
    //Addition 
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.GetDenominator() + denominator * other.GetNumerator();
        int den = denominator * other.GetDenominator();
        return Fraction(num, den);
    }
    
    //Subtraction
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.GetDenominator() - denominator * other.GetNumerator();
        int den = denominator * other.GetDenominator();
        return Fraction(num, den);
    }
    
    //Multiplication
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.GetNumerator();
        int den = denominator * other.GetDenominator();
        return Fraction(num, den);
    }
    
    //Division
    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.GetDenominator();
        int den = denominator * other.GetNumerator();
        return Fraction(num, den);
    }
    
    //Assignment
    Fraction& operator=(const Fraction& other) {
        numerator = other.GetNumerator();
        denominator = other.GetDenominator();
        Simplify();
        return *this;
    }
    
    
    //Compound assignment
    Fraction& operator+=(const Fraction& other) {
       numerator = numerator * other.GetDenominator() + denominator * other.GetNumerator();
       denominator = denominator * other.GetDenominator();
        Simplify();
        return *this;
    }
    
    //Comp. Subtraction
    Fraction& operator-=(const Fraction& other) {
       numerator = numerator * other.GetDenominator() - denominator * other.GetNumerator();
       denominator = denominator * other.GetDenominator();
        Simplify();
        return *this;
    }
    
    //comp.mult.
    Fraction& operator*=(const Fraction& other) {
       numerator = numerator * other.GetNumerator();
       denominator = denominator * other.GetDenominator();
        Simplify();
        return *this;
    }
    
    //comp. div.
    Fraction& operator/=(const Fraction& other) {
       numerator = numerator * other.GetDenominator();
       denominator = denominator * other.GetNumerator();
        Simplify();
        return *this;
    }
    
    //Convert to double
    double ToDouble() const {
        return (double)(numerator)/(double)(denominator);
    }
    
    
    //output stream << operator
     friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.GetNumerator() << "/" << fraction.GetDenominator();
        return os;
    }
    
    //input stream >> operator
    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        char slash;
        int num, den;
        is >> num >> slash >> den;
        
        fraction = Fraction(num, den);
        return is;
        
    }
};



int main()
{
    Fraction f,g;
    std::cout << f;
    std::cin >> f >> g;
    std::cout << f << " " << g << " " << f+g << " "<< f-g << " " << f*g << " " << f/g << "\n" << f.ToDouble() << " "<< g.ToDouble();
    f += g;
    
    
    return 0;
}

