%option noyywrap
%%
[0-9]+	ECHO;
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