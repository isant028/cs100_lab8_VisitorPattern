#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"
#include <string>
#include <string.h>
#include "op.hpp"
class Div : public Base {

        private:
                double ri;
                double le;
                Base* leftnode;
                Base* rightnode;
                std::string top;
                std::string bot;
                std::string divi;

        public:
                Div(Base* left, Base* right) : Base() {
                        leftnode = left;
                        rightnode = right;
                         ri = right->evaluate();
                         le = left->evaluate();
			                top =left->stringify();
			                bot = right->stringify();
                }

                double evaluate()
                {
                        return (le/ri);
                }

                std::string stringify()
                {
                        divi = top + " / " + bot;
                        return divi;
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
        void accept(CountVisitor* myvisitor){
            myvisitor->visit_div();
        }

};

#endif