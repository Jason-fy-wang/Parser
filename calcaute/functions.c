#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "functions.h"
#include<stdarg.h>

double call_func(const char* name, double arg){
    if(strcasecmp(name,"sin") == 0) {
        return sin(arg);
    }
    if(strcasecmp(name,"cos") == 0) {
        return cos(arg);
    }
    if(strcasecmp(name,"tan") == 0) {
        return tan(arg);
    }
    if(strcasecmp(name,"asin") == 0) {
        return asin(arg);
    }
    if(strcasecmp(name,"acos") == 0) {
        return acos(arg);
    }
    if(strcasecmp(name,"atan") == 0) {
        return atan(arg);
    }
    if(strcasecmp(name,"sqrt") == 0) {
        return sqrt(arg);
    }
    if(strcasecmp(name,"log") == 0) {
        return log(arg);
    }
    if(strcasecmp(name,"log10") == 0) {
        return log10(arg);
    }
    if(strcasecmp(name,"exp") == 0) {
        return exp(arg);
    }
    if(strcasecmp(name,"abs") == 0) {
        return abs(arg);
    }
    if(strcasecmp(name,"floor") == 0) {
        return floor(arg);
    }
        if(strcasecmp(name,"ceil") == 0) {
        return ceil(arg);
    }

    fprintf(stderr,"Unknown function: %s\n", name);
    return 0.0;
}


double lookup(const char* name){
    if (strcasecmp(name, "pi") == 0) {
        return M_PI;
    }

    if(strcasecmp(name,"e") == 0) {
        return M_E;
    }

    fprintf(stderr, "Unknow identifier :%s\n", name);
    return 0.0;
}

// build ast
struct ast* newast(int nodetype, struct ast* l, struct ast* r){
    struct ast* a = malloc(sizeof(struct ast));
    if (!a) {
        yyerror("out of space");
        exit(1);
    }

    a->nodetype = nodetype;
    a->l = l;
    a->r = r;

    return a;
}

struct ast* newnum(double num) {
    struct numval* a = malloc(sizeof(struct numval));
    a->nodetype = 'k';
    a->number = num;
    return (struct ast*) a;
}

// evaluate ast
double eval(struct ast* ast) {
    double v;

    switch (ast->nodetype)
    {
    case 'k':
        v = ((struct numval*)ast)->number;
        break;
    case 'm':
        v = -eval(ast->l);
        break;
    case '+': 
        v = eval(ast->l) + eval(ast->r);
        break;
        
    case '-': 
        v = eval(ast->l) - eval(ast->r);
        break;
    case '*': 
        v = eval(ast->l) * eval(ast->r);
        break;
    case '/': 
        v = eval(ast->l) / eval(ast->r);
        break;
    default:
        printf("internal error: bad node: %c\n", ast->nodetype);
        break;
    }
    return v;
}

void treefree(struct ast* ast){
    switch(ast->nodetype){
        case '+':
        case '-':
        case '*':
        case '/':
            treefree(ast->r);
        case '|':
        case 'm':
            treefree(ast->l);
        
        case 'k':
            free(ast);
            break;
        default:
            printf("internal error: free bad node: %c\n", ast->nodetype);
            break;
    }
}

void yyerror(const char*s, ...) {
    va_list ap;
    va_start(ap,s);

    fprintf(stderr, "%d error:", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}