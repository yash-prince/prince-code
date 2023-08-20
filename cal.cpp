#include <iostream>

using namespace std;

double power(double base, int exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
    {
        result = result * base;
    }
    return result;
}

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double sine(double x, int term)
{
    double result = 0.0;
    for (int n = 0; n < term; n++)
    {
        double value = (power(-1.0, n) * power(x, 2 * n + 1)) / factorial(2 * n + 1);
        result += value;
    }
    return result;
}

double cosine(double x, int term)
{
    double result = 0.0;
    for (int n = 0; n < term; n++)
    {
        double value = (power(-1.0, n) * power(x, 2 * n)) / factorial(2 * n);
        result += value;
    }
    return result;
}

int main()
{
    char o;
    int a, b;
    double angle;
    int term;

    cout << "choose the operator (+, -, *, /, ^, s, c, t): " << endl;
    cin >> o;

    if (o == 's' || o == 'c' || o == 't')
    {
        cout << "enter the angle in radians: ";
        cin >> angle;
        cout << "no of terms: ";
        cin >> term;

        if (o == 's')
        {
            double sineValue = sine(angle, term);
            cout << "sin(" << angle << ") = " << sineValue << endl;
        }
        else if (o == 'c')
        {
             double cosineValue = sine(angle, term);
            cout << "cos(" << angle << ") = " << cosineValue << endl;
        }
        else if (o == 't')
        { double sineValue = sine(angle, term);
         double cosineValue = sine(angle, term);
            
            if (cosineValue != 0.0)
            {
               
                cout <<sineValue/cosineValue;
            }
            else
            {
                cout << "tan(" << angle << ") is undefined" << endl;
            }
        }
    }
    else if (o == '+' || o == '-' || o == '*' || o == '/' || o == '^')
    {
        cout << "enter the first number: ";
        cin >> a;
        cout << "enter the second number: ";
        cin >> b;

        switch (o)
        {
            case '^':
                cout << a << "^" << b << " = " << power(a, b) << endl;
                break;
            case '+':
                cout << a << " + " << b << " = " << a + b << endl;
                break;
            case '-':
                cout << a << " - " << b << " = " << a - b << endl;
                break;
            case '*':
                cout << a << " * " << b << " = " << a * b << endl;
                break;
            case '/':
                if (b != 0)
                {
                    cout << a << " / " << b << " = " << static_cast<double>(a) / b << endl;
                }
                else
                {
                    cout << "Division by zero is undefined" << endl;
                }
                break;
            default:
                cout << "Invalid operator" << endl;
                break;
        }
    }
    else
    {
        cout << "Invalid operator" << endl;
    }

    return 0;
}