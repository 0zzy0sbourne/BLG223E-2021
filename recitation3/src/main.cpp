#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctype.h> // included myself

using namespace std;

void infix_to_postfix(string, string &);
bool higher_priority(char, char);
double eval_prefix(string);
double evaluate(double, double, char);
void infix_to_prefix(string, string &);
void str_reverse(string &);

int main()
{
    string infix;
    string prefix;
    bool is_exit = false;

    while (!is_exit)
    {

        cout << "Input the expression in infix: ";
        cin >> infix;

        if (infix == "E" || infix == "e")
            is_exit = true;

        else
        {
            infix_to_prefix(infix, prefix);
            cout << prefix << endl;
            cout << setprecision(2) << fixed << eval_prefix(prefix) << endl;
        }

        cin.clear();
        cin.ignore();
        infix.clear();
        prefix.clear();
    }

    return EXIT_SUCCESS;
}

void infix_to_postfix(string infix, string &postfix)
{
    stack<char> s;
    // *********************Fill this method

    for (string::iterator it = infix.begin(); it != infix.end(); it++)
    {
        if (isdigit(*it))
        {
            // concatenate to a postfix string
            postfix.push_back(*it);
        }
        else if (!isdigit(*it) && !s.empty())
        {
            if (higher_priority(*it, s.top()))
            { // priority of the top most operator of the stack is less than or equal to scanned operator
                // or equal to scanned operator, push it to stack
                s.push(*it);
            }
            else
            {
                // priority of the top most operator of the stack is greater than scaned operator
                while(higher_priority(s.top(), *it))
                {
                    char c = s.top(); 
                    s.pop(); 
                    postfix.push_back(c); 
                     
                }
                postfix.push_back(*it);
                // s.push(*it); 
            }
        }
        else if (!isdigit(*it) && s.empty())
        {
            s.push(*it);
        }
    }
    // infix string ends, pop all the operators remaining int the stack
    // and concatenate to postfix string
    while (!s.empty())
    {
        char c = s.top();
        s.pop();
        postfix.push_back(c);
    }
}

void infix_to_prefix(string infix, string &prefix)
{
    // *********************Fill this method

    // reverse infix string
    str_reverse(infix);

    infix_to_postfix(infix, prefix);

    str_reverse(prefix);
}

void str_reverse(string &s)
{
    reverse(s.begin(), s.end());
}

bool higher_priority(char first, char second)
{
    if ((first == '*' || first == '/') && (second == '+' || second == '-'))
        return true;
    else
        return false;
}

double eval_prefix(string expr)
{
    stack<double> s;
    double first, second;

    // *********************Fill this method
    for (string::iterator it = expr.begin(); it != expr.end(); it++)
    {
        if (isdigit(*it))
        {
            s.push(*it);
        }
        else
        {
            
            if(s.size() >= 2)
            {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            double result = evaluate(a, b, *it);
            s.push(result);
            }
        }
    }

    double rs = s.top();
    // s.pop();
    return rs;
}

double evaluate(double first, double second, char c)
{
    switch (c)
    {
    case '*':
        return first * second;
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '/':
        return first / second;
    default:
        return 0;
    }
}
