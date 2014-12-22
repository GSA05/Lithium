%{
#include <math.h>
#include "unkmacsin.h"
%}

%option noyywrap
%option c++
%option outfile="lex.UNK.c"

int3        [[:digit:]]{1,3}
int5        [[:digit:]]{3,5}
float12		-?[[:digit:]]"."[[:digit:]]{5}[eE][+-][[:digit:]]{2}	
comment		[^[:space:]][^{int3}{int5}{float12}]+$

%x row1 row2 row3 row4 row5 material comment isotopes concentrations models isotopes_t concentrations_t temperature groups

%%
                    int line_num = 1;
                    int line_num_prev = 0;
                    BEGIN(row1);
                    int i = 0;
                    int j = 0;
                    int nums[2];
                    int num_group;

<row1>{
    {int3}                              switch(++i){
                                            case 1:
                                                s->setGeometry(atoi(yytext));
                                                break;
                                            case 2:
                                                break;
                                            case 3:
                                                s->setGroups(atoi(yytext));
                                                break;
                                            case 4:
                                                s->setGroupsT(atoi(yytext));
                                                break;
                                            case 5:
                                                break;
                                            case 6:
                                                s->setPred(atoi(yytext));
                                                break;
                                        }
    "\n"		                        ++line_num; printf("\n"); BEGIN(row2);
}
<row2>{
    {float12}                           s->setAlbedo(atoi(yytext));
    <row2>"\n"                          ++line_num; printf("\n"); BEGIN(row3);
}
<row4,row5>{int3}                       s->setGeometry(atoi(yytext));
<row3,temperature>{float12}             printf("%g ",atof(yytext)); i++;
<row3>"\n"		                        ++line_num; printf("\n"); BEGIN(row4);
<row4>"\n"		                        ++line_num; printf("\n"); BEGIN(row5);
<row5>"\n"	                            ++line_num; printf("\n"); i = 0; BEGIN(material);
<temperature>"\n"	                    if(i != 0) { ++line_num; printf("\n"); i = 0; j = 0; BEGIN(groups); }
<material>{int3}                        nums[i] = atoi(yytext); printf("%d ",nums[i++]); if(i == 2) BEGIN(comment);
<comment>.*"\n"                         ++line_num; printf("\n"); printf("%s",yytext); i = 0; BEGIN(isotopes);
<isotopes>{
    {int5}                              printf("%d ",atoi(yytext)); i++;
    "\n"                                line_num_prev = line_num++; if(i == nums[0]) { printf("\n"); i = 0; BEGIN(concentrations); }
}
<concentrations>{
    {float12}                           printf("%g ",atof(yytext)); i++;
    "\n"                                line_num_prev = line_num++; if(i == nums[0]) { printf("\n"); i = 0; BEGIN(models); }
}
<models>{
    {int3}                              printf("%d ",atoi(yytext)); i++;
    "\n"                                line_num_prev = line_num++; if(i == nums[0]) { printf("\n"); i = 0; if(nums[1]) BEGIN(isotopes_t); else BEGIN(temperature); }
}
<isotopes_t>{
    {int5}                              printf("%d ",atoi(yytext)); i++;
    "\n"                                line_num_prev = line_num++; if(i == nums[1]) { printf("\n"); i = 0; BEGIN(concentrations_t); }
}
<concentrations_t>{
    {float12}                           printf("%g ",atof(yytext)); i++;
    "\n"                                line_num_prev = line_num++; if(i == nums[1]) { printf("\n"); i = 0; BEGIN(temperature); }
}
<groups>{
    {int3}                              printf("%d ",atoi(yytext)); if(j++ == 0) { num_group = atoi(yytext); printf("\n"); }
    "\n"                                if(j != 0) { ++line_num; if(num_group) printf("\n"); }; if(++i == nums[0]) { i = 0; BEGIN(material); } else j = 0;
}
<INITIAL>[[:space:]]+ 
<<EOF>>                                 /*printf("%d\n",line_num);*/ yyterminate();
<*>.|"\n"

%%

/*main(int argc, char **argv)
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
}*/
UNKMacsinScanner::UNKMacsinScanner(std::istream *in,
                                   std::ostream *out)
    : UNKFlexLexer(in,out)
{
}

UNKMacsinScanner::~UNKMacsinScanner()
{
}

#ifdef yylex
#undef yylex
#endif

int UNKFlexLexer::yylex()
{
    std::cerr << "in UNKFlexLexer::yylex() !" << std::endl;
    return 0;
}
