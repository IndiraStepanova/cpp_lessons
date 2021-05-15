struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * visitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value);
    double evaluate() const;

    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right);
    ~BinaryOperation();
    double evaluate() const;

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

#include <iostream>

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << '(';
        bop->get_left()->visit(this);
        std::cout << ')';
        std::cout << bop->get_op() << " ";
        std::cout << '(';
        bop->get_right()->visit(this);
        std::cout << ')';
    }
};

int main(){
    Number* left1 = new Number(2);
    Number* right1 = new Number(3);
    BinaryOperation* bop1 = new BinaryOperation(left1, '*', right1);
    Number* right2 = new Number(1);
    BinaryOperation* bop2 = new BinaryOperation(bop1, '+', right2);
    PrintVisitor* v = new PrintVisitor(); //
    bop2->visit(v); //для bop2 вызыв метод с арг v
}