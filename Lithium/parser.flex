%option noyywrap

%{
#include <math.h>
%}

int3		[[:digit:]]{1,3}
int5		[[:digit:]]{3,5}
float12		-?[[:digit:]]"."[[:digit:]]{5}[eE][+-][[:digit:]]{2}	
comment		[^[:space:]][^{int3}{int5}{float12}]+$

%%

{int3}		printf("%d\n",atoi(yytext));
{int5}		printf("%d\n",atoi(yytext));
{float12}	printf("%g\n",atof(yytext));
[[:space:]]+ 
% //{comment}	printf("%s\n",yytext);
[^0-9]*		

%%

main(int argc, char **argv)
{
	++argv; --argc;
	if(argc>0)
	{
		yyin = fopen(argv[0],"r");
	}
	else
	{
		yyin = stdin;
	}
	yylex();
}
