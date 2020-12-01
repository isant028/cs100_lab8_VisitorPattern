#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class CountVisitor{
    private:
        int ops=0;
        int rands=0;
        int mults=0;
        int divs=0;
        int add=0;
        int sub=0;
        int pow=0;

    public:
        CountVisitor();

        void visit_op();
        int op_count();
        void visit_rand();
        int rand_count();
        void visit_mult();
        int mult_count();
        void visit_div();
        int div_count();
        void visit_add();
        int add_count();
        void visit_sub();
        int sub_count();
        void visit_pow();
        int pow_count();

};

#endif //__COUNT_VISITOR_HPP__
