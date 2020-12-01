#include "add.hpp"
#include "sub.hpp"
#include "op.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "Rand.hpp"
#include "Mult.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include <iostream>

using namespace std;
int main(){
    Base* three = new Op(3);
    Base* five = new Op(5);
    Base* two = new Op(2);
    Base* six = new Op(6);

    Add* add = new Add(three, five);
    Add* add1 = new Add(add, two);
    Sub* sub = new Sub(add1, five);
    Mult* mult = new Mult(sub, two);
    Add* add3 = new Add(mult, three);
    Add* add4 = new Add(add3, two);
    Div* div = new Div(add4, three);
    Pow* pow = new Pow(div, two);
    Sub* sub2 = new Sub(pow, six);

    CountVisitor* visitor = new CountVisitor();
    Iterator* temp = new PreorderIterator(sub2);
    sub2->accept(visitor);

    temp->first();
    while(!(temp->is_done())){
        if(temp->current() != nullptr){
            temp->current()->accept(visitor);
        }
        temp->next();
    }

    cout << "Add Count: " << visitor->add_count() << endl;
    cout << "Sub Count: " << visitor->sub_count() << endl;
    cout << "Rand Count: " << visitor->rand_count() << endl;
    cout << "Div Count: " << visitor->div_count() << endl;
    cout << "Mult Count: " << visitor->mult_count() << endl;
    cout << "Op Count: " << visitor->op_count() << endl;
    cout << "Pow Count: " << visitor->pow_count() << endl;


    return 0;
}