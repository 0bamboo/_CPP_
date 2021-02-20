#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

// using namespace std;

// How to create a function :

//  Void function :a
void        example_void_func()
{
    using namespace std;
    cout << "\nHello from void function\n";
}

// Function with arguments and return value :

double         power(double base, double exp)
{
    int count;
    double result;

    count = 0;
    result = 1;
    while (count < exp)
    {
        result = result * base;
        count = count + 1;
    }
    return result;
}

// Function with arguments and no return value :

void        print_power(double base, double exp)
{
    int count;
    double result;
    auto x = 4U;

    count = 0;
    result = 1;
    std::cout << x << std::endl;
    while (count < exp)
    {
        result *= exp;
        count += 1;
    }
    std::cout << "\nThe result of print_power function is : " << result << std::endl;
}

// Function for data types :

void        data_types_func()
{
    unsigned char uc;
    char c;
    int i;
    unsigned int ui;
    bool found;

    using namespace std;
    uc = 255;
    found = true;
    c = 255; // max for char is 255 (ascii table)
    i = 23524;
    ui = -223423233;
    cout << uc << " <-uc | c-> " << c << endl;
    cout << " This the value of int : " << i << " --- and this is the value of unsigned int : " << ui << endl;
    cout << "This is boolean variable : "<< boolalpha << found << endl;
}

void        print_string()
{
    char c_string[] = "hello";
    using namespace std;
    string cpp_string;
    string string_cpp_in;
    string getline_string;
    string testing_methods;


    // You can't assign to c_string without allocating i guess
    // c_string = "hello from c string";
    cpp_string = "hello";
    //  Yes we can use string concatenation in cpp class string COOL right !!
    cpp_string += " from cpp string";
    cout << "c string : " << c_string << "\n cpp string : " << cpp_string << endl;
    cin >> string_cpp_in;
    cout << string_cpp_in << " Length method (cpp way) : " << string_cpp_in.length() << " Strlen function (c way) : i tried strlen funciton but it does not work on string (class) type " << endl;
    // We use getline for getting the whole string from the console because when we use cin it gets only the first string befor finds white space 
    // When you use the cin function before getline the getline gets the rest of the first cin : for example when you enter hello from console, the first cin returns 'hello' and getline returns ' from console'
    getline(cin, getline_string);  // you can use this one for getting the string 
    // and this one for getting numbers and everything else ==> cin.getline()
    cout << "Getline string : " << getline_string << endl;
    
    //  Methods : are functions attached to an object ;
    testing_methods.insert(0, "hello from method insert");  // so insert method takes to arguments the first is the index where to insert and the second is the insert value
    testing_methods.replace(18, 6, "replace"); // replace method takes 3 args, index when to start the numbers of chars to replace and  what we want to replace with
    testing_methods.erase(18, 1); // erasse method takes 2 or 1 arg it depends on you , the first one is for positionnal index and the second is the number of chars to remove
    testing_methods.pop_back(); // for removing the last char in the string ,
    cout << testing_methods << endl;

}

//  Function for hex and octal :

void        print_hex_oct()
{
    int x;
    using namespace std;

    x = 3732;
    //  For converting decimal to hex :
    cout << "3732 to hex : " << hex << x << endl;
    // For converting decimal to octal :
    cout << "3732 to hex : " << oct << x << endl;
}

int main()
{
    int base;
    int exponent;
    using namespace std;

    // std::cout << "Please enter the base :\n";
    // std::cin >> base;
    // std::cout << "Please enter the exponent :\n";
    // std::cin >> exponent;
    // std::cout << "The result is : "<< pow(base, exponent)<< std::endl;
    cout << "------------------------------------"<< endl;
    example_void_func();
    cout << "This the result of power function : " << power(2, 3) << endl;
    print_power(3, 3);
    cout << "---------------------------------------" << endl;
    data_types_func();
    cout << "--------------------------------------" << endl;
    print_string();
    cout << "-------------------------------------" << endl;
    print_hex_oct();
}