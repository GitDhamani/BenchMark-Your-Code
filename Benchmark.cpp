#include <iostream>
#include <chrono>

struct timer
{    
    //Cannot use Auto
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    
    //Check time upon object creation
    timer() { m_start = std::chrono::high_resolution_clock::now(); }

    ~timer() 
    {  
    //Check time upon object destruction    
    auto m_end = std::chrono::high_resolution_clock::now(); 
    
    //Now Cast m_start and m_end timepoints as microseconds into startus and endus
    auto startus = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();    
    
    auto endus = std::chrono::time_point_cast<std::chrono::microseconds>(m_end).time_since_epoch().count(); 
                 
    auto Duration = endus - startus;    
    std::cout<<"\nTime Taken was: "<<Duration/1000.0<<" ms ("<<Duration<<" us)";
    
    }
};


void Func(const int& val)
{
    timer t;
    
    //Put Your Function Code here   
}

int main()
{
    Func(30);

    return 0;
}
