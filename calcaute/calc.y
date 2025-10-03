%define parse.error verbose
%debug
%locations

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.h"
#include<math.h>
extern int yylex(void);

%}

%union {
    struct ast* a;
    double dval;
    char* sval;
}

%token <dval> NUMBER
%token <sval> IDENT
%token PLUS MINUS MUL DIV LPAREN RPAREN POW EOL

%left PLUS MINUS
%left MUL DIV
%right UMINUS POW
%type <a> expr factor term

%start input

%%
input:
    /* empty line */
    | input expr EOL {  
                        printf("= %g\n", eval($2));
                        printf("> ");
                    }
    | input EOL   {printf("> ");}
    ;

expr: factor
    | expr PLUS factor  {$$ = newast('+',$1, $3);}
    | expr MINUS factor {$$ = newast('-',$1, $3);}
    ;

factor: term
    | factor MUL term   {$$ = newast('*', $1, $3);}
    | factor DIV term   {$$ = newast('/',$1, $3);}
    ;

term: NUMBER    {$$ = newnum($1);}
    | MINUS expr {$$ = newast('m',$2,NULL);}
    | LPAREN expr RPAREN {$$ = $2;}
    ;

%%

int main(int argc, char* argv[]){
    printf("Enter expressions (Ctrl+D to quit);\n");
    return yyparse();
}
