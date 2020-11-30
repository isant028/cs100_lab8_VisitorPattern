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
                std::string top;
                std::string bot;
                std::string divi;

        public:
                Div(Base* left, Base* right) : Base() {
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

};

#endif