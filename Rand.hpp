#ifndef __RAND_HPP__
#define __RAND_HPP__
#include "base.hpp"
#include <string>
class Rand: public Base { 
    public:
    double value1;
  
       Rand(double test) : Base()  
        {value1  = std::rand()%100;}
       virtual double evaluate()  {return value1;} 
        virtual std::string stringify()
        {return std::to_string(value1);}
};

#endif //__RAND_HPP__