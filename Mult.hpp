#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "base.hpp"

class Mult : public Base { 
    public:
    double value1;
    double value2;
    double testfinal;
    Base* leftnode;
    Base* rightnode;
   
        Mult(Base* test1,Base* test2) : Base() { 
        value1  = test1->evaluate();
        value2  = test2 -> evaluate();
        testfinal = value1 * value2;
}
       virtual double evaluate()  {return testfinal;} 
        virtual std::string stringify()
        {return std::to_string(value1) + "*" + std::to_string(value2);}

        Iterator* create_iterator(){
                     Iterator* it = new BinaryIterator(this);
                return it;
        }

        Base* get_left(){
            return this->leftnode;
        }

        Base* get_right(){
            return this->rightnode;
        }
};

#endif //__MULT_HPP__