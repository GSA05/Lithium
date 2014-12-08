%option noyywrap

%{
#include <math.h>
%}

int3        [[:digit:]]{1,3}
int5        [[:digit:]]{3,5}
float12		-?[[:digit:]]"."[[:digit:]]{5}[eE][+-][[:digit:]]{2}	
comment		[^[:space:]][^{int3}{int5}{float12}]+$

%x first_row

%%
                    int line_num = 1;
                    BEGIN(first_row);

<first_row>{int3}	        printf("%d ",atoi(yytext));
<first_row>"\n"		        ++line_num; printf("\n"); BEGIN(INITIAL);
<INITIAL>{int5}				printf("%d\n",atoi(yytext));
<INITIAL>{float12}			printf("%g\n",atof(yytext));
<INITIAL>[[:space:]]+ 
% //{comment}		        printf("%s\n",yytext);
<<EOF>>                     printf("%d\n",line_num); yyterminate();
<*>.|"\n"

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
