#ifndef CLAC_H
#define CLAC_H

/*李春阳制作*/
#include <iostream>
#include <fstream>
#include <stack>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class calc
{
private:
    stack<char> operators;
    stack<double> operands;

    char getSign(void)
    {
        return operators.top();
    }

    double getNum(void)
    {
        return operands.top();
    }

    void popSign(void)
    {
        operators.pop();
    }

    void popNum(void)
    {
        operands.pop();
    }

    double popAndGetNum(void)
    {
        double num = getNum();
        popNum();
        return num;
    }

    char popAndGetSign(void)
    {
        char sign = getSign();
        popSign();
        return sign;
    }
public:
    double final_result;

    void push(double num)
    {
        operands.push(num);
    }

    void push(char sign)
    {
        operators.push(sign);
    }

    char get(void)
    {
        return getSign();
    }

    void pop(void)
    {
        popSign();
    }

    double result(void)
    {
        if (!operands.empty())
            return getNum();
        return 0.0;
    }

    void calculate(void)
    {
        double post = popAndGetNum();
        char sign = popAndGetSign();
        double pre = popAndGetNum();
        double result = 0.0;
        switch (sign)
        {
        case '+':
            result = pre + post;
            break;
        case '-':
            result = pre - post;
            break;
        case '*':
            result = pre * post;
            break;
        case '/':
            if (fabs(post) < 1e-6)
            {
                calc::writeResult("#1");
                exit(EXIT_SUCCESS);
            }
            else
                result = pre / post;
            break;
        case '^':
            result = pow(pre, post);
            break;
        case '%':
            result = static_cast<int>(pre) % static_cast<int>(post);
            break;
        }
        //cout << result << endl;
        final_result = result;
        push(result);
    }

    bool canCalculate(char sign)
    {
        if (sign == '(' || sign == '[' || sign == '{' || operators.empty())
            return false;
        char t = getSign();
        if (t == '^')
            return true;
        switch (t)
        {
        case '+':
        case '-':
            return sign == '+' || sign == '-';
        case '*':
        case '/':
        case '%':
            return sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '%';
        }
        return false;
    }

    bool empty(void)
    {
        return operators.empty();
    }

    static void writeResult(const string& s)
    {
        ofstream out;
        out.open("result.txt");
        out << s;
        out.close();
    }

    void writeResult(void)
    {
        ofstream out;
        out.open("result.txt");
        if (result() < 1e15)
        {
            out << fixed;
            out << setprecision(12);
        }
        out << result();
        out.close();
    }
};





class check
{
private:
    string s;
    size_t len;
    char c;
    bool valid(void)
    {
        if (isSignOrDot(0) || isRightBrace(0))
            return false;
        len = s.size();
        stack<char> braces;
        for (size_t i = 0; i < len; ++i)
        {
            if (isLeftBrace(i))
            {
                if (isSignOrDot(i + 1))
                {
                    if (s[i + 1] != '-' && s[i + 1] != '+')
                        return false;
                }
                if (isRightBrace(i + 1))
                    return false;
                braces.push(s[i]);
            }
            else if (isRightBrace(i))
            {
                if (isDot(i + 1) || isDigit(i + 1) || isLeftBrace(i + 1))
                    return false;
                if (isRightBrace(i + 1))
                {
                    stack<char> braces_copy(braces);
                    if (braces_copy.empty())
                        return false;
                    braces_copy.pop();
                    if (braces_copy.empty())
                        return false;
                }
                if (braces.empty())
                    return false;
                char brace = braces.top();
                if ((brace == '(' && s[i] != ')') || (brace == '[' && s[i] != ']') || (brace == '{' && s[i] != '}'))
                    return false;
                braces.pop();
            }
            else if (isSign(i))
            {
                if (isSign(i + 1) || isDot(i + 1) || isRightBrace(i + 1))
                    return false;
            }
            else if (isDot(i))
            {
                if (isSignOrDot(i + 1) || isBrace(i + 1))
                    return false;
            }
            else if (isDigit(i))
            {
                if (isRightBrace(i + 1))
                {
                    if (braces.empty())
                        return false;
                    char brace = braces.top();
                    if ((brace == '(' && s[i + 1] != ')') || (brace == '[' && s[i + 1] != ']') || (brace == '{' && s[i + 1] != '}'))
                        return false;
                }
            }
        }
        return braces.empty();
    }

    bool set(size_t i)
    {
        if (i >= len)
            return false;
        c = s[i];
        return true;
    }

    bool isSign(size_t i)
    {
        if (set(i))
            return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
        return false;
    }

    bool isDot(size_t i)
    {
        if (set(i))
            return c == '.';
        return false;
    }

    bool isBrace(size_t i)
    {
        return isLeftBrace(i) || isRightBrace(i);
    }

    bool isLeftBrace(size_t i)
    {
        if (set(i))
            return c == '(' || c == '[' || c == '{';
        return false;
    }

    bool isRightBrace(size_t i)
    {
        if (set(i))
            return c == ')' || c == ']' || c == '}';
        return false;
    }

    bool isSignOrDot(size_t i)
    {
        return isSign(i) || isDot(i);
    }

    bool isDigit(size_t i)
    {
        if (set(i))
            return isdigit(c);
        return false;
    }

public:

    check() {}
    bool valid(const string& s)
    {
        this->s = s;
        return valid();
    }

    string getResult(void)
    {
        size_t len = s.size();
        for (size_t i = 0; i < len; ++i)
        {
            if (s[i] == '(' && (s[i + 1] == '-' || s[i + 1] == '+'))
                s.insert(i + 1, "0");
        }
        return s;
    }
};








#endif // CLAC_H
