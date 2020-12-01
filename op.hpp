#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include <string>
#include "visitor.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { val = value; }
        virtual double evaluate() { return val; }
        virtual std::string stringify() {
		std::string value2 = std::to_string(val);
	       	return value2; 
        }
        virtual Iterator* create_iterator(){
            Iterator* it = new NullIterator(this);
            return it;
        }

        virtual Base* get_left(){
            return nullptr;
        }

        virtual Base* get_right(){
            return nullptr;
        }

        void accept(CountVisitor* myvisitor){
            myvisitor->visit_op();
        }
   private:
	double val;
};

#endif //__OP_HPP__