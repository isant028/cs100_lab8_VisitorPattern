#include "visitor.hpp"

CountVisitor::CountVisitor(){}

void CountVisitor::visit_op(){
    this->ops += 1;
}

void CountVisitor::visit_rand(){
    this->rands += 1;
}

void CountVisitor::visit_mult(){
    this->mults += 1;
}

void CountVisitor::visit_div(){
    this->divs += 1;
}

void CountVisitor::visit_add(){
    this->add += 1;
}

void CountVisitor::visit_sub(){
    this->sub += 1;
}

void CountVisitor::visit_pow(){
    this->pow += 1;
}

int CountVisitor::add_count(){
    return this->add;
}

int CountVisitor::op_count(){
    return this->ops;
}

int CountVisitor::pow_count(){
    return this->pow;
}

int CountVisitor::sub_count(){
    return this->sub;
}

int CountVisitor::mult_count(){
    return this->mults;
}

int CountVisitor::div_count(){
    return this->divs;
}

int CountVisitor::rand_count(){
    return this->rands;
}