#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "base.hpp"

class Mult : public Base { 
    public:
    double value1;
    double value2;
    double testfinal;
   
        Mult(Base* test1,Base* test2) : Base() { 
        value1  = test1->evaluate();
        value2  = test2 -> evaluate();
        testfinal = value1 * value2;
}
       virtual double evaluate()  {return testfinal;} 
        virtual std::string stringify()
        {return std::to_string(value1) + "*" + std::to_string(value2);}
};

#endif //__MULT_HPP__