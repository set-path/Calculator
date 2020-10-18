#include "calculator.h"
#include <sstream>
#include <iomanip>

Calculator::Calculator()
{
    this->expression="";
    this->result=0;
    this->flag=false;
}

char Calculator::GetExpression(char c)
{
    this->expression += c;
    return c;
}

int Calculator::Calculation(){
    this->flag=false;
    if(this->expression=="="){
        return -1;
    }
    double left, right;
    int cnt = 0;
    for (int i = 0; i < this->expression.length() - 1; i++) {
        if (isdigit(this->expression[i])) {
            this->OPND.push(char2double(&this->expression[i], cnt));
            i += cnt;
        }
        else {
            if (this->OPTR.empty() || prior(this->OPTR.top(), this->expression[i]) == '<') {
                this->OPTR.push(this->expression[i]);
            }
            else if (prior(this->OPTR.top(), this->expression[i]) == '>') {
                right = this->OPND.top();
                this->OPND.pop();
                left = this->OPND.top();
                this->OPND.pop();
                if (this->OPTR.top() == '/' && right == 0.0) {
                    this->flag=true;
                    while (!this->OPTR.empty()) {
                        this->OPTR.pop();
                    }
                    while (!this->OPND.empty()) {
                        this->OPND.pop();
                    }
                    break;
                }
                this->OPND.push(this->operate(left, right, this->OPTR.top()));
                this->OPTR.pop();
                i--;
            }
            else if (prior(this->OPTR.top(), this->expression[i]) == '=') {
                this->OPTR.pop();
            }
        }
    }
    while (!this->OPTR.empty()) {
        right = this->OPND.top();
        this->OPND.pop();
        left = this->OPND.top();
        this->OPND.pop();
        if (this->OPTR.top() == '/' && right == 0.0) {
            this->flag=true;
            while (!this->OPTR.empty()) {
                this->OPTR.pop();
            }
            while (!this->OPND.empty()) {
                this->OPND.pop();
            }
            break;
        }
        this->OPND.push(this->operate(left, right, this->OPTR.top()));
        this->OPTR.pop();
    }
    if(!this->OPND.empty()){
        this->result = this->OPND.top();
        this->OPND.pop();
    }
    return 0;
}

double Calculator::operate(double left, double right, char optr) {
    double temp = 0;
    if (optr == '+') {
        temp = left + right;
    }
    else if (optr == '-') {
        temp = left - right;
    }
    else if (optr == '*') {
        temp = left * right;
    }
    else if (optr == '/') {
        temp = left / right;
    }
    return temp;
}

double Calculator::char2double(char* s, int& cnt) {
    stringstream ss;
    double temp;
    int i = 0;
    while (1) {
        if ((s[i] >= '0' && s[i] <= '9')||s[i]=='.') {
            ss << s[i];
        }
        else {
            break;
        }
        i++;
    }
    ss >> temp;
    cnt = --i;
    return temp;
}

char Calculator::prior(char left, char right) {
    int row, col;
    if (left == '+') {
        row = 0;
    }
    else if (left == '-') {
        row = 1;
    }
    else if (left == '*') {
        row = 2;
    }
    else if (left == '/') {
        row = 3;
    }
    else if (left == '(') {
        row = 4;
    }
    else if (left == ')') {
        row = 5;
    }
    else if (left == '#') {
        row = 6;
    }
    if (right == '+') {
        col = 0;
    }
    else if (right == '-') {
        col = 1;
    }
    else if (right == '*') {
        col = 2;
    }
    else if (right == '/') {
        col = 3;
    }
    else if (right == '(') {
        col = 4;
    }
    else if (right == ')') {
        col = 5;
    }
    else if (right == '#') {
        col = 6;
    }
    return this->priority[row][col];
}

void Calculator::init()
{
    this->expression="";
}

string Calculator::showexpression()
{
    return this->expression;
}

double Calculator::showresult()
{
    return result;
}

void Calculator::setexpression(string s)
{
    this->expression = s;
}

void Calculator::setresult(double res)
{
    this->result = res;
}

void Calculator::subrxpression(int begin, int end)
{
    this->expression = this->expression.substr(begin, end - begin);
}

bool Calculator::showflag()
{
    return this->flag;
}
