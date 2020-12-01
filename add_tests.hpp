#ifndef __ADD_TESTS_HPP__
#define __ADD_TESTS_HPP__

#include "op.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "add.hpp"
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

#endif