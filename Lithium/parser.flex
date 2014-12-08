%option noyywrap

%{
#include <math.h>
%}

int3        [[:digit:]]{1,3}
int5        [[:digit:]]{3,5}
float12		-?[[:digit:]]"."[[:digit:]]{5}[eE][+-][[:digit:]]{2}	
comment		[^[:space:]][^{int3}{int5}{float12}]+$

%x row1 row2 row3

%%
                    int line_num = 1;
                    BEGIN(row1);
                    char buf[20];

<row1>{int3}	            printf("%d ",atoi(yytext));
<row1>"\n"		            ++line_num; printf("\n"); BEGIN(row2);
<row2>"\n"		            ++line_num; printf("\n"); BEGIN(row3);
<INITIAL>{int5}				printf("%d\n",atoi(yytext));
<row2,INITIAL>{float12}		printf("%g ",atof(yytext));
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
