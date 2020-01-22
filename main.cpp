/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or const reference types ** WHERE POSSIBLE **
    hint: There is no reference equivalent to nullptr.  
    So don't try to convert nullptr, if nullptr is being returned anywhere
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    T* compare(T* a, T* b) 
    { 
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr; 
    }
};

struct U
{
    float num1 { 0 }, num2 { 0 };
    float reduceAndMultiplyFunction(const float& update)      //12
    {
        num1 = update;
        while( std::abs(num2 - num1) > 0.001f )
        {
            num2 += 0.1f ;
        }
        return num2 * num1;
    }
};

struct Reduce
{
    static float reduceAndMultiplyFunction(U& that, const float& update)        //10
    { 
        std::cout << "U's num1 value: " << that.num1 << std::endl;
        that.num1 = update;
        std::cout << "U's num1 updated value: " << that.num1 << std::endl;
        while( std::abs(that.num2 - that.num1) > 0.001f )
        {
            /*
            write something that makes the distance between that->num2 and that->num1 get smaller
            */
            that.num2 += 0.1f ;
        }
        std::cout << "U's num2 updated value: " << that.num2 << std::endl;
        return that.num2 * that.num1;
    }
};
        
int main()
{
    T t1(35, "William");                                             //6
    T t2(31, "Emma");                                             //6
    
    Compare f;                                            //7
    auto smaller = f.compare(&t1, &t2);  //
    std::cout << "the smaller one is << " << smaller->name << std::endl;

    U u;
    float updatedValue = 5.f;
    std::cout << "Reduce's multiplied values: " << Reduce::reduceAndMultiplyFunction(u, updatedValue)  << std::endl;                  //11
    
    U u1;
    std::cout << "U's multiplied values: " << u1.reduceAndMultiplyFunction( updatedValue ) << std::endl;

}       




