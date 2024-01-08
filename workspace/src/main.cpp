#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*
Function tests post fix and prefix operators ++ and --
*/
void postfix_prefix() 
{
    int x = 10;
    cout << "x = " << x << endl;
    cout << "x++ = " << x++ << "at this line " << endl;
    cout << "x++ at this line = " << x << endl;
    cout << "++x at this line = " << ++x << endl;
    cout << "++x at this line = " << x << endl;

    int i_x = 10;
    cout << "i_x / 3 = " << i_x / 3 << endl;
    cout << "i_x % 3 = " << i_x % 3 << endl;
    //
    float f_x = 10.0;
    float q = 3;
    cout << "f_x / 3 = " << f_x / 3.0 << endl;  // NOTE: % is not applicable to floats as it does not have a meaning

    char n = '\0';
    cout << "null = " << n << endl;

}

/**
 * Function demos use of strings
**/
void strings()
{
    string s = "hello, my name is sambit";
    cout << "string -> " << s << endl;
    //
    string s2 = "this is concated later\n";
    cout << "Concated string -> " << s + " " + s2 << endl;
}

/**
 * FUnction uses the ternary statement to check if two numbers are equal or not
*/
string ternary_check(int a, int b)
{
    string res;
    //
    res = (a == b) ? "equal": \
    (a < b) ? "smaller" : "greater";
    return res;
}

int readInt()
{
    int a;
    cout << "Enter an int" << endl;
    cin >> a;
    return a;
}

string readString()
{
    string s;
    cout << "Enter a string" << endl;
    cin >> s;
    return s;
}

float readFloat()
{
    float f;
    cout << "Enter a float" << endl;
    cin >> f;
    return f;
}

/**
 * Function shows use of ranges in C++17
*/
void ranges()
{
    int a[] = {1, 2, 3, 4, 5, 0};
    for(int val : a)
        cout << val << endl;

    for(int i=0; auto c = a[i]; i++)
    {
        cout << c << endl;
    }
}

void pointertest()
{
    int a = 345;
    cout << "&a = " << &a << endl;
}


int main(int argc, char *argv[])
{
    cout << "Hello World\n";
    //
    postfix_prefix();
    //
    strings();
    //
    string res = ternary_check(10, 20);
    cout << "ternary_check(10, 20) -> " << res << endl;
    res = ternary_check(20, 20);
    cout << "ternary_check(10, 20) -> " << res << endl;
    res = ternary_check(20, 10);
    cout << "ternary_check(10, 20) -> " << res << endl;
    //
    // int n = readInt();
    // cout << "Number read -> " << n << endl;
    // string s;
    // s = readString();
    // cout << "String read -> " << s << endl;
    // float f;
    // f = readFloat();
    // cout << "Float read -> " << f << endl;
    //
    ranges();
    //
    cout << "Number of commandline args -> " << argc << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << "cmdline " << i << " = " << argv[i] << endl;
    }
    //

    pointertest();


    return 0;
}