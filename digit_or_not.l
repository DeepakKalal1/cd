/* Lex program to check whether input is digit or not. */
%{x
#include<stdio.h>
#include<stdlib.h>
%}
/* Rule Section */
%%
[0-9]* printf("digit");
.* printf("not a digit");
%%
int yywrap(void){}
int main()
{
		// The function that starts the analysis
	yylex();
		return 0;
}
