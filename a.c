#include <stdio.h>
#include <stdlib.h>

int pre (char op){
    return op == '^'? 3 : (op == '*' || op == '/')? 2 : 1;
}
int main(){
    int i,j;

    char infix []="A+B*C-D/E";//o/p : ABC*+DE/-
    int sz= strlen(infix);

    char postfix[sz];
    int sz =strlen(infix);

    char postfix[sz];
    int n=-1;
    for (i=0;i < sz;i++)
       postfix[i]='\0';

       char oprstk[10];
       int top = -1;

       //---------

       for (i=0;i < sz;i++){
          char nx = infix[i];

          if(nx== '+'|| nx == '-'||nx== '*'||nx=='/') {
              if (top== -1) {
                  oprstk[++top] = nx;
              } else {
                  while (top != -1 && pre(oprstk[top]) >= pre(nx)) {
                      postfix[++n] = oprstk[top--];
                  }
                  oprstk[++top] = nx;
              }
          } else {
              postfix[++n] = nx;
          }
       }
       while (top != -1) {
           postfix[++n] = oprstk[top--];
       }
       postfix[++n] = '\0';
       printf("Postfix expression: %s\n", postfix);
       return 0;
   }
