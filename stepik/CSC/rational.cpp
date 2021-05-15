#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational other) {
        this->numerator_ = this->numerator_ * other.denominator_ + other.numerator_ * denominator_;
        this->denominator_ *= other.denominator_;
    }

    void sub(Rational other) {
        numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
    }

    void mul(Rational other) {
        numerator_ *= other.numerator_;
        denominator_ *= other.denominator_;
    }

    void div(Rational other) {
        numerator_ *= other.denominator_;
        denominator_ *= other.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;}


    Rational& operator+=(Rational other)
    {
        add(other);
        return *this;
    }
    
    Rational& operator-=(Rational other)
    {
        this->sub(other);
        return *this;
    }

    Rational& operator*=(Rational other)
    {
        this->mul(other);
        return *this;
    }

    Rational& operator/=(Rational other)
    {
        this->div(other);
        return *this;
    }

    Rational operator-() const {
        Rational neg_rational = *this;
        neg_rational.neg();
        return neg_rational;}

    Rational operator+() const {return Rational(numerator_*1, denominator_);}
    
    

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational first, Rational const& second)
    {
        return first += second;
    }
Rational operator-(Rational first, Rational const& second)
    {
        return first -= second;
    }
Rational operator*(Rational first, Rational const& second)
    {
        return first += second;
    }
Rational operator/(Rational first, Rational const& second)
    {
        return first -= second;
    }

int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);

    //r1 += r2;
    //r1.operator+=(r2);
    //r1 += (r2 += r3);

    int x=5; 
    Rational R1=2; 
    Rational R2 = r1 + R1;
    Rational R3 = R1 + x;
    std::cout << R2.to_double() << std::endl;
    std::cout << R3.to_double() << std::endl;
   

    r1.add(r2);
    std::cout << r1.to_double() << std::endl;
    r1.sub(r2);
    std::cout << r1.to_double() << std::endl;
    r1.neg();
    std::cout << r1.to_double() << std::endl;
    r3.mul(r1);
    std::cout << r3.to_double() << std::endl;
    r3.div(r2);
    std::cout << r3.to_double() << std::endl;

}
