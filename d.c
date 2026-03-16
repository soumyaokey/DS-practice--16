#include <stdio.h>
#include <stdlib.h>

int pre (char op){
  return op == '^' ? 3 : op == '*' || op == '/' ? 2 : 1 ;
}

char oprstk[10];
int top =-1;

void push (char nx) {
        oprstk[++top] = nx;
}

int is_empty() {
    return top == -1?1:0;
}

int main (){
int i,j;

          char infix []="A*B+((C-*D)^Z))/E^F^G";//o/p:AB-CD*Z^+EFG^^/
         int sz= strlen (infix);

         char postfix[sz];
         int n = -1;
         for (i=0;i<sz;i++)
         postfix[i]='\0';

         

         //-----------
for (i=0;i<sz;i++){
  char nx = infix[i];

  if (nx=='+' || nx == '-' || nx == '*' || nx == '/' || nx == '^') {
      if (top == -1) {
          oprstk[++top] = nx;
      } else if (pre(oprstk[top]) == '(') {
          oprstk[++top] = nx;
      } else if (pre(oprstk[top]) >= pre(nx)) {
          oprstk[++top] = nx;
      } else if (pre(oprstk[top]) < pre(nx)) {
        do
        {
            postfix[++n] = oprstk[top--];
        } while (top != -1 && pre(oprstk[top]) >= pre(nx));
          oprstk[++top] = nx;
      }
  } else if (nx == '(') {
      oprstk[++top] = nx;
  } else if (nx == ')') {
      while (top != -1 && oprstk[top] != '(') {
          postfix[++n] = oprstk[top--];
      }
      top--;
    }else{
      postfix[++n] = nx;
    }
  }
  while (top != 0)
    postfix[++n] = oprstk[top--];

    for (i = 0; i <= n; i++) {
        printf("%c", postfix[i]);
    }

    return 0;
}