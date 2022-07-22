%{
#include<stdio.h>
%}

%%
include|main|printf|auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short {fprintf(yyout, "%s, ", yytext);}
[ \n\t]+ {fprintf(yyout, "");}
stdio.h|string.h|file.h {continue;}
[{};,()] {continue;}
[+-/=*%] {continue;}
([a-zA-Z][0-9])+|[a-zA-Z]* {continue;}
.|\n ;
%%

int yywrap() {}
int main(void) {
	extern FILE *yyin, *yyout;
	yyin = fopen("program.c", "r");
	yyout = fopen("output.txt", "w");
	yylex();
	fclose(yyin);
	fclose(yyout);
	return 0;
}
