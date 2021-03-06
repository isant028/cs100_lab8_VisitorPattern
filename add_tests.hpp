#ifndef __ADD_TESTS_HPP__
#define __ADD_TESTS_HPP__

#include "op.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "visitor.hpp"
#include "Rand.hpp"
#include "div.hpp"
#include "pow.hpp"

TEST(AddIteratorTest, BasicAddTest){
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Add* test = new Add(three, seven);
    Iterator* temp = test->create_iterator();
    temp->first();
    EXPECT_EQ(temp->current()->evaluate(), 3);
    EXPECT_EQ(temp->is_done(), false);
    temp->next();
    EXPECT_EQ(temp->current()->evaluate(), 7);
    EXPECT_EQ(temp->is_done(), false);
    temp->next();
    EXPECT_EQ(temp->current(), nullptr);
    EXPECT_EQ(temp->is_done(), true);
}

TEST(AddIteratorTest, DoubleAddTest){
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* eight = new Op(8);
    Add* test = new Add(three, seven);
    Add* test1 = new Add(test, eight);
    Iterator* temp = test1->create_iterator();
    Iterator* temp2 = test->create_iterator();
    temp->first();
    temp2->first();
    EXPECT_EQ(temp->current()->evaluate(), 10);
    EXPECT_EQ(temp2->current()->evaluate(), 3);
    temp->next();
    temp2->next();
    EXPECT_EQ(temp->current()->evaluate(), 8);
    EXPECT_EQ(temp2->current()->evaluate(), 7);
    temp->next();
    temp2->next();
    EXPECT_EQ(temp->current(), nullptr);
    EXPECT_EQ(temp2->current(), nullptr);
}

TEST(OpIteratorTest, BasicOperandTest){
    Base* three = new Op(3);
    Iterator* temp = three->create_iterator();
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(temp->current(), nullptr);
}


TEST(SubIteratorTest, BasicSubTest){
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Sub* tester = new Sub(seven, three);
    Iterator* temp = tester->create_iterator();
    temp->first();
    EXPECT_EQ(temp->current()->evaluate(), 7);
    temp->next();
    EXPECT_EQ(temp->current()->evaluate(), 3);
    temp->next();
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(temp->current(), nullptr);

}


TEST(MultIteratorTest, BasicMultTest){
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Mult* test = new Mult(three, seven);
    Iterator* temp = test->create_iterator();
    EXPECT_EQ(temp->is_done(), false);
    temp->first();
    EXPECT_EQ(temp->current()->evaluate(), 3);
    EXPECT_EQ(temp->is_done(), false);
    temp->next();
    EXPECT_EQ(temp->is_done(), false);
    EXPECT_EQ(temp->current()->evaluate(), 7);
    temp->next();
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(temp->current(), nullptr);

}

TEST(DivIteratorTest, BasicDivTest){
    Base* four = new Op(4);
    Base* eight = new Op(8);
    Mult* test = new Mult(four, eight);
    Iterator* temp = test->create_iterator();
    temp->first();
    EXPECT_EQ(temp->is_done(), false);
    EXPECT_EQ(temp->current()->evaluate(), 4);
    temp->next();
    EXPECT_EQ(temp->is_done(), false);
    EXPECT_EQ(temp->current()->evaluate(), 8);
    temp->next();
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(temp->current(), nullptr);

}


TEST(VisitorTest, BasicVisitTest){
    Base* three = new Op(3);
    Base* four = new Op(4);
    Add* test = new Add(three, four);
    Iterator* temp = new PreorderIterator(test);
    CountVisitor* visitor = new CountVisitor();
    test->accept(visitor);
    temp->first();
    EXPECT_EQ(temp->is_done(), false);
    EXPECT_EQ(temp->current()->evaluate(), 3);
    temp->current()->accept(visitor);
    EXPECT_EQ(visitor->add_count(), 1);
    EXPECT_EQ(visitor->op_count(), 1);
    temp->next();
    EXPECT_EQ(temp->current()->evaluate(), 4);
    temp->current()->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 2);
}

TEST(VisitorTest, AnotherVisitTest){
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* five = new Op(5);
    Base* six = new Op(6);
    Add* test = new Add(three, four);
    Add* test1 = new Add(test, five);
    Add* test2 = new Add(test1, six);
    
    CountVisitor* visitor = new CountVisitor();
    Iterator* temp = new PreorderIterator(test2);
    test2->accept(visitor);
    
    temp->first();
    while(!(temp->is_done())){
        if(temp->current() != nullptr){
            temp->current()->accept(visitor);
            EXPECT_EQ(temp->is_done(), false);
        }
        temp->next();
    }
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(visitor->add_count(), 3);
    EXPECT_EQ(visitor->op_count(), 4);
}

TEST(RandTest, BasicRandTest){
    Rand* rand = new Rand(3);
    Iterator* temp = rand->create_iterator();
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(temp->current(), nullptr);
}

TEST(DivTest, BasicDivTest){
    Base* six = new Op(6);
    Base* three = new Op(3);
    Div* div = new Div(six, three);
    Iterator* temp = div->create_iterator();
    temp->first();
    EXPECT_EQ(temp->current()->evaluate(), 6);
}

TEST(PowTest, BasicDivTest){
    Base* two = new Op(2);
    Base* three = new Op(3);
    Pow* pow = new Pow(three, two);
    Iterator* temp = pow->create_iterator();
    temp->first();
    EXPECT_EQ(temp->current()->evaluate(), 3);
    temp->next();
    EXPECT_EQ(temp->current()->evaluate(), 2);
}

TEST(PreorderTest, MainTest){
    Base* three = new Op(3);
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* six = new Op(6);

    Add* add = new Add(three, two);
    Add* add2 = new Add (four, six);
    Add* add3 = new Add(add, add2);
    Sub* sub = new Sub(add3, four);
    Div* div = new Div(sub, two);
    Add* add4 = new Add(div, six);
    Mult* mult = new Mult(add4, two);
    Pow* pow = new Pow(mult, two);
    Rand* rand = new Rand(2);
    Sub* sub2 = new Sub(pow, rand);

    CountVisitor* visitor = new CountVisitor();
    Iterator* temp = new PreorderIterator(sub2);
    sub2->accept(visitor);

    temp->first();
    while(!(temp->is_done())){
        if(temp->current() != nullptr){
            temp->current()->accept(visitor);
            EXPECT_EQ(temp->is_done(), false);
        }
        temp->next();
    }
    EXPECT_EQ(temp->is_done(), true);
    EXPECT_EQ(visitor->add_count(), 4);
    EXPECT_EQ(visitor->div_count(), 1);
    EXPECT_EQ(visitor->sub_count(), 2);
    EXPECT_EQ(visitor->mult_count(), 1);
    EXPECT_EQ(visitor->rand_count(), 1);
    EXPECT_EQ(visitor->pow_count(), 1);
    EXPECT_EQ(visitor->op_count(), 9);
}
#endif