//
//  main.cpp
//  project6
//
//  Created by William Eden on 19/01/2020.
//  Copyright © 2020 William Eden. All rights reserved.
//

/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2
 
 Create a branch named Part1
 
 Pointers
 
 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
 you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
 note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
 note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
 be sure to make it work with the pointer semantics being used in the if statements.
 see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
 the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack
 
 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n): value(v), name(n){}//1
    int value;//2
    std::string name;//3
};

struct Compare                                //4
{
    T* compare(T* a, T* b) //5
    { 
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float num1 { 0 }, num2 { 0 };
    float reduceAndMultiplyFunction(float* update)      //12
    {
        num1 = *update;
        while( std::abs(num2 - num1) > 0.001f )
        {
            num2 += 0.1f ;
        }
        return num2 * num1;
    }
};

struct Reduce
{
    static float reduceAndMultiplyFunction(U* that, float* update)        //10
    { 
        float result = 0.0f;
        if(that != nullptr && update != nullptr)
        {
            std::cout << "U's num1 value: " << that->num1 << std::endl;
            that->num1 = *update;
            std::cout << "U's num1 updated value: " << that->num1 << std::endl;
            while( std::abs(that->num2 - that->num1) > 0.001f )
            {
                /*
                write something that makes the distance between that->num2 and that->num1 get smaller
                */
                that->num2 += 0.1f ;
            }
            std::cout << "U's num2 updated value: " << that->num2 << std::endl;
            result = that->num2 * that->num1;
        }
        return result;
    }
};
        
int main()
{
    T t1(35, "William");                                             //6
    T t2(31, "Emma");                                             //6
    
    Compare f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U u;
    float updatedValue = 5.f;
    std::cout << "Reduce's multiplied values: " << Reduce::reduceAndMultiplyFunction(&u, &updatedValue)  << std::endl;                  //11
    
    U u1;
    std::cout << "U's multiplied values: " << u1.reduceAndMultiplyFunction( &updatedValue ) << std::endl;

}       




