%define parse.error verbose
%debug
%locations

%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char* s);
%}

%union {
    int ival;
}

%token <ival> NUMBER
%token PLUS MINUS MUL DIV LPAREN RPAREN

%left PLUS MINUS
%left MUL DIV
%right UMINUS
%type <ival> expr

%start input

%%
input:
    /* empty line */
    | input line
    ;

line:
    expr '\n'    {printf("= %d\n", $1);}
    | '\n'
    ;

expr: NUMBER
    | expr PLUS expr  {$$ = $1 + $3;}
    | expr MINUS expr {$$ = $1 - $1;}
    | expr MUL expr {$$ = $1 * $3;}
    | expr DIV expr {$$ = $1 / $3;}
    | MINUS expr %prec UMINUS { $$ = -$2;}
    | LPAREN expr RPAREN { $$ = $2;}
    ;

%%

extern int yylineno;
int main(int argc, char* argv[]){
    printf("Enter expressions (Ctrl+D to quit);\n");
    return yyparse();
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n at line %d",s,yylineno);
}