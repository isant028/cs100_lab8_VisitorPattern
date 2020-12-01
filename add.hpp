#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"
#include <string>
#include <string.h>
#include "iterator.hpp"
class Add: public Base{
	private:
		double lef;
		double rig;
		std::string lefts;
		std::string rights;
		std::string finals;
        public:
                Add(Base* left, Base* right) : Base(){
			lef= left->evaluate();
			rig = right->evaluate();
			lefts = left->stringify();
			rights = right->stringify();
		}
                double evaluate() { 
			return (lef+rig); 
		}
                std::string stringify(){
                        finals = lefts + " + " + rights;
                        return finals;
                }

        Iterator* create_iterator(){
            return Iterator* it = new Iterator(Add* ptr);
        }

};

#endif