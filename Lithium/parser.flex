%option noyywrap

%{
#include <math.h>
%}

int3        [[:digit:]]{1,3}
int5        [[:digit:]]{3,5}
float12		-?[[:digit:]]"."[[:digit:]]{5}[eE][+-][[:digit:]]{2}	
comment		[^[:space:]][^{int3}{int5}{float12}]+$

%x row1 row2 row3 row4 row5 material comment isotopes concentrations models isotopes_t concentrations_t temperature

%%
                    int line_num = 1;
                    int line_num_prev = 0;
                    BEGIN(row1);
                    char buf[20];
                    int i = 0;
                    int nums[2];

<row1,row4,row5>{int3}	    printf("%d ",atoi(yytext));
<row2,row3>{float12}		printf("%g ",atof(yytext));
<row1>"\n"		            ++line_num; printf("\n"); BEGIN(row2);
<row2>"\n"		            ++line_num; printf("\n"); BEGIN(row3);
<row3>"\n"		            ++line_num; printf("\n"); BEGIN(row4);
<row4>"\n"		            ++line_num; printf("\n"); BEGIN(row5);
<row5>"\n"		            ++line_num; printf("\n"); i = 0; BEGIN(material);
<material>{int3}            nums[i] = atoi(yytext); printf("%d ",nums[i++]); if(i == 2) BEGIN(comment);
<comment>.*"\n"             ++line_num; printf("\n"); printf("%s",yytext); i = 0; BEGIN(isotopes);
<isotopes>{
    {int5}                  printf("%d ",atoi(yytext)); if(++i == nums[0] ) { ++line_num; printf("\n"); i = 0; BEGIN(concentrations); }
    "\n"                    line_num_prev = line_num++;
}
<concentrations>{
    {float12}               printf("%g ",atof(yytext)); if(++i == nums[0] ) { ++line_num; printf("\n"); i = 0; BEGIN(models); }
    "\n"                    line_num_prev = line_num++;
}
<INITIAL>[[:space:]]+ 
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
