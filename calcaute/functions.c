#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "functions.h"


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