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
void yyerror(const char* s);

%}

%union {
    double dval;
    char* sval;
}

%token <dval> NUMBER
%token <sval> IDENT
%token PLUS MINUS MUL DIV LPAREN RPAREN POW

%left PLUS MINUS
%left MUL DIV
%right UMINUS POW
%type <dval> expr

%start input

%%
input:
    /* empty line */
    | input line
    ;

line:
    expr '\n'    {printf("= %g\n", $1);}
    | '\n'
    ;

expr: NUMBER
    | IDENT LPAREN expr RPAREN      {$$ = call_func($1, $3); free($1);}
    | IDENT            {$$ = lookup($1); free($1);}
    | expr PLUS expr  {$$ = $1 + $3;}
    | expr MINUS expr {$$ = $1 - $1;}
    | expr MUL expr {$$ = $1 * $3;}
    | expr DIV expr {$$ = $1 / $3;}
    | expr POW expr  {$$=pow($1,$3);}
    | MINUS expr %prec UMINUS { $$ = -$2;}
    | LPAREN expr RPAREN { $$ = $2;}
    ;

%%

extern int yylineno;
void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n at line %d",s,yylineno);
}


int main(int argc, char* argv[]){
    printf("Enter expressions (Ctrl+D to quit);\n");
    return yyparse();
}
