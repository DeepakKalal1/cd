%{
#include<stdio.h>
%}

%%
include|main|printf|auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short {ECHO; printf("\tKEYWORD\n");}
stdio.h|string.h|file.h {ECHO; printf("\tHEADER FILE\n");} 						
[{};,()] {ECHO; printf("\tSEPERATOR\n");}						
[+-/=*%] {ECHO; printf("\tOPERATOR\n");}						
([a-zA-Z][0-9])+|[a-zA-Z]* {ECHO; printf("\tIDENTIFIER\n");}    
.|\n ; 															
%%

int yywrap() {}
int main(void) {
	extern FILE *yyin;
	yyin = fopen("program.c", "r");
	yylex();
	fclose(yyin);
	return 0;
}
