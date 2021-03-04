#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <fstream>

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
    // auto x = 4U;

    count = 0;
    result = 1;
    // std::cout << x << std::endl;
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
    uc = 55;
    found = true;
    c = 55; // max for char is 255 (ascii table)
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

unsigned int         factorial_(unsigned int number)
{
    if (number > 1)
        return (number * factorial_(number - 1));
    else
        return 1;
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
    cout << "3732 to oct : " << oct << x << endl;
}

void print_string_vector()
{
    using namespace std;
    vector<string> str;

    str = {"hello world", "hi"};
    str.push_back("hi again");
    cout << str.size() << endl;
    cout << str[str.size() - 1] << endl;

}

bool    create_a_file()
{
    std::ofstream file;
    int ret;

    using namespace std;

    file.open("test.c");
    ret = file.is_open();
    if (ret)
        cout << "File succefully opened .\n";
    file << "#include <stdio.h>\nint main(){\nprintf(\"hello from file creatd using cpp\");}";
    file.close();
    return ret;
}


void        read_from_a_file()
{
    std::ifstream file("test.c"); // or file.open("test.c")
    std::string input;
    std::vector<std::string> data;
    std::string line;

    // U can use getline for reading a line each time
    getline(file, line);
    std::cout << line << std::endl;
    while (file >> input)
        data.push_back(input);
    for (std::string line : data) // range-based loop
        std::cout << " string : " << line << std::endl;
}
  

//  Example of functions that use pass a variable by reference :

void pass_(int &a)
{
    a = 5;
    std::cout << a << std::endl;
}

void swap_vectors_by_reference(std::string &a, std::string &b)
{
    std::string tmp;

    tmp = a;
    a = b;
    b = tmp;
}

// Example of overloads funtions :

struct Rect
{
    int length;
    int width;
};

int area(int length, int width)
{
    return length*width;
}

int area(int length)
{
    return length*length;
}

int area(Rect rect)
{
    return rect.length * rect.width;
}


//  How to create a namespace :
namespace hello_ns
{
    int area_(int a = 11)
    {
        return a * a;
    }
    
}

// How to create a function template :

template <typename T>

T template_function(T &x)
{
    return x;
}

// Creating a struct with private access modifier : 

struct User_s
{
    std::string name;
    std::string last_name;
    // if you want to get the value of this private variable you need for example to define another function and return this private variable :
    std::string get_private()
    {
        return private_var;
    }
    private:
        // the in line assignement is reserved for c++ 11
        std::string private_var = "hello i'm private_var ";
};

// Creating a Class :

class Class_user
{
    // this is how to declare a private variable in class its not like struct no need of using private flag 
    std::string this_a_private_var;

    // for creating public elements :
    public:
        std::string hello_from_class;
        std::string something;
        
        // This is how to create a constructor in cpp : you give it the name of the class
        Class_user()
        {
            std::cout << "when object is created , this construct will execute" << std::endl;

            // If you want to use the variables that you created in the class we use them like this : {the same for private variables}
            this->hello_from_class = "|my value changed using {this} way|";
        }

        // This is how to create a destructor : you give it also the name of the class
        ~Class_user()
        {
            std::cout << "class destroyed" << std::endl;
        }
};  

class User
{
    public:
        std::string user_name;
        std::string user_l_name;

        void print_something()
        {
            std::cout << "hello from something not understandable" << std::endl;
        }

        // ~another_thing()
        // {
        //     std::cout << "hello";
        // }
};

int add_user_if_not_exist(std::vector<User> &users, User user)
{
    int i;

    i = 0;
    while (i < users.size())
    {
        if (users[i].user_l_name == user.user_l_name && users[i].user_name == user.user_name)
            return 1;
        i++;
    }
    users.push_back(user);
    return 0;
}


int main()
{   
    // creating an instance of struct :
    // User_s user_1;
    // // Creating an instance of class :
    // Class_user class_instance;
    // int base;
    // int exponent;
    // using namespace std;
    // unsigned int ret;
    // int a[]={1,2,3,4};
    // int b = 4;
    // string first_name = "abdennacer";
    // string last_name = "ama";

    // // Pass by reference:
    // pass_(b);
    // for(int s : a)
    //     cout << s << "\t";
    // swap_vectors_by_reference(first_name, last_name);
    // cout << first_name << " " << last_name << endl;

    // // Example of template function :
    // cout << "This a templatize function using an int var : " << template_function(b) << endl;
    // cout << " For string var : " << template_function(first_name) << endl;
    
    // // Overloads functions/
    // Rect r;
    // r.length = 10;
    // r.width = 10;
    // cout << "Function area that uses struct as parameter : " << area(r) << endl;
    // cout << "Funcion area that uses two int variables as parameter : " << area(b, b) << endl;
    // cout << "Function area that uses one int variable as parameter : " << area(b) << endl;

    // // You can not access to the vars inside the private modifier in the struct User :
    // // cout << "something_else : " << user_1.private_var << endl;
    // user_1.name = "paayk";
    // user_1.last_name = "chihaja";
    // cout << "name : " << user_1.name << "\t";
    // cout << "last_name : " << user_1.last_name << "\t";
    // cout << "private_var : " << user_1.get_private() << "\n";
    
    // // Other option besides overload is default vlaue;
    // cout << "Function area that uses default value : " << hello_ns::area_() << endl;

    // // This a templitized array : array<type, size> nameofthearray;
    // array<int, 35> array = {3,2,3,2};

    // // array = {3,2,3,2};
    
    // for (int i = 0; i < array.size(); i++)
    //     cout << array[i] << "\t";
    
    // // Range-based loop 
    // // for (int n : array)
    // //     cout << n << "\t";

    // // std::cout << "Please enter the base :\n";
    // // std::cin >> base;
    // // std::cout << "Please enter the exponent :\n";
    // // std::cin >> exponent;
    // // // std::cout << "The result is : "<< pow(base, exponent)<< std::endl;
    // cout << "------------------------------------"<< endl;
    // example_void_func();
    // cout << "This the result of power function : " << power(2, 3) << endl;
    // print_power(3, 3);
    // cout << "---------------------------------------" << endl;
    // data_types_func();
    // cout << "--------------------------------------" << endl;
    // print_string();
    // cout << "-------------------------------------" << endl;
    // print_hex_oct();
    // cout << "----------------fact----------------------" << endl;
    // ret = factorial_(4);
    // cout << dec << ret << endl;
    // cout << "------------------------------------\n";
    // print_string_vector();
    // cout << "-------------------------------------\n";
    // if (create_a_file())
    // {
    //     cout << "------------Read from file-----------------\n";
    //     read_from_a_file();
    // }

    // // This is an an example of using variable from the class we created :
    // cout << "Enter something for the variable on class : ";
    // cin >> class_instance.something;
    // cout << class_instance.something << endl;

    // //  This is a mini exo using classes and vectors :
    // vector<User> users;
    // User user1;
    // User user2;
    // User user3;
    // User user;

    // user1.user_name = "omar";
    // user1.user_l_name = "piko";

    // user2.user_name = "paayk";
    // user2.user_l_name = "paayk";

    // user3.user_name = "abdennacer";
    // user3.user_l_name = "ama";

    // users.push_back(user1);
    // users.push_back(user2);
    // users.push_back(user3);

    // cout << "Enter the name of the user : ";
    // cin >> user.user_name;
    // cout << "\n";
    // cout << "Enter the last name of the user :";
    // cin >> user.user_l_name;
    // if (add_user_if_not_exist(users, user))
    //     cout << "The user already exists." << endl;
    // else
    //     cout << "The user has been added ." << endl;
    // cout << " The users are :" << endl<< endl;
    // for (int i = 0; i < users.size(); i++)
    //     cout << users[i].user_name << "\t" << users[i].user_l_name << endl;
    User please_do_not_print_something();
}