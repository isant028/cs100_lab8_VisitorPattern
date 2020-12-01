#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"
#include <string>
#include <string.h>
#include "iterator.hpp"
#include "binary_iterator.cpp"
class Add: public Base{
	private:
		double lef;
		double rig;
        Base* leftnode;
        Base* rightnode;
		std::string lefts;
		std::string rights;
		std::string finals;
        public:
                Add(Base* left, Base* right) : Base(){
                    leftnode = left;
                    rightnode = right;
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


#endif