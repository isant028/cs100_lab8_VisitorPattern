#ifndef SUB_HPP
#define SUB_HPP

#include "base.hpp"
#include <string>
#include <string.h>
class Sub: public Base{
	private:
		double lef;
		double rig;
        Base* leftnode;
        Base* rightnode;
		std::string lefts;
		std::string rights;
		std::string finals;
        public:
                Sub(Base* left, Base* right) : Base(){
			lef= left->evaluate();
			rig = right->evaluate();
			lefts = left->stringify();
			rights = right->stringify();
		}
                double evaluate() { 
			return (lef-rig); 
		}
                std::string stringify(){
                        finals = lefts + " - " + rights;
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