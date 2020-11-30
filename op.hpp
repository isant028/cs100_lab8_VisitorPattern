#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

#include <string>

class Op : public Base {
    public:
        Op(double value) : Base() { val = value; }
        virtual double evaluate() { return val; }
        virtual std::string stringify() {
		std::string value2 = std::to_string(val);
	       	return value2; 
	}
   private:
	double val;
};

#endif //__OP_HPP__