#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include <string>

class Pow: public Base{
        public:
                Pow(Base* left, Base* right) : Base(){
                    leftnode = left;
                    rightnode = right;
			num= left->evaluate();
			exp = right->evaluate();
			lefts = left->stringify();
			rights = right->stringify();
		}
                double evaluate() {
			double calc = 1;
			for(int i = 0; i < exp; i++){
				calc = calc*num;
			}
			 return calc; 
		}
               std::string stringify(){
                       finals = lefts + "**" + rights;
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
        private:
		std::string lefts;
		std::string rights;
                std::string finals;
		double num;
		double exp;
        Base* leftnode;
        Base* rightnode;
};

#endif