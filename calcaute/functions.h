#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

double call_func(const char* name, double arg);
double lookup(const char* name);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E  2.71828182845904523536
#endif

struct ast {
    int nodetype;
    struct ast* l;
    struct ast* r;
};


struct numval{
    int nodetype;
    double number;
};

// build ast
struct ast* newast(int nodetype, struct ast* l, struct ast* r);
struct ast* newnum(double num);

// evaluate ast
double eval(struct ast*);

void treefree(struct ast*);

void yyerror(const char*s, ...);
extern int yylineno;

#endif