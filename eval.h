#ifndef PG_EVAL_H
#define PG_EVAL_H
double evaluate(char * infix);
char * toPostfix(char * infix, char * postfix);
double parsePostfix(char * postfix);
#endif /* PG_EVAL_H */