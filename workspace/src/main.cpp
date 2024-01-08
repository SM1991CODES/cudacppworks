#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>

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
    //
    unique_ptr<int> ptr1(new int()); // create uninit unique pointer
    *ptr1 = 100;
    cout << "&ptr1 = " << ptr1.get() << ", *ptr1 = " << *ptr1 << endl;

    unique_ptr<int> ptr2 = make_unique<int>(99); // unique ptr with init value
    cout << "&ptr2 = " << ptr2.get() << ", *ptr2 = " << *ptr2 << endl;

    int data = 9;
    unique_ptr<int> ptr3(&data); // create unique ptr for existing variable
    cout << "&ptr3 = " << ptr3.get() << ", *ptr3 = " << *ptr3 << endl;

    unique_ptr<int> ptr4;
    ptr4 = move(ptr3);
    if (ptr3 == nullptr)
    {
        cout << "unique_ptr ptr3 has been moved to unique_ptr ptr4 and hence is now a null_ptr" << endl;
    }
    else
    {
        cout << "WARNING: ptr3 should have been a null_ptr" << endl;
    }
    cout << "&ptr4 = " << ptr4.get() << ", *ptr4 = " << *ptr4 << endl;
    //
    int myVal = 25;
    shared_ptr<int> sPtr1(new int(myVal));
    cout << "use count => " << sPtr1.use_count() << ", value = " << *sPtr1 << endl;
    *sPtr1 -= 1;
    cout << "*sPtr1 = " << *sPtr1 << "value in myVal = " << myVal << endl;

    shared_ptr<int> sPtr2 = sPtr1; // shared pointers can be copied, copies only address, not actual value
    cout << "use count sPtr2 = " << sPtr2.use_count() << " use count sPtr1 = " << sPtr1.use_count() << endl;

    sPtr2.reset(); // don't need this pointer to the data any more
    cout << "use count sPtr2 = " << sPtr2.use_count() << endl;

    cout << "use count sPtr1 = " << sPtr1.use_count() << endl;


    return 0;
}