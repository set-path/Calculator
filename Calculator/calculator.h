#ifndef CALCULATOR_H
#define CALCULATOR_H
using namespace std;
#include <string>
#include <stack>

class Calculator
{
public:
    Calculator();
private:
    char priority[7][7] =
    { {'>','>','<','<','<','>','>'},{'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},{'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=','X'},{'>','>','>','>','X','>','>'},
    {'<','<','<','<','<','X','='} };
    string expression;
    double result;
    stack<char> OPTR;
    stack<double> OPND;
    bool flag;
public:
    char GetExpression(char c);
    int Calculation();
    double operate(double left, double right, char optr);
    double char2double(char* s, int& cnt);
    char prior(char left, char right);
    void init();
    string showexpression();
    double showresult();
    void setexpression(string s);
    void setresult(double res);
    void subrxpression(int begin, int end);
    bool showflag();
};

#endif // CALCULATOR_H
