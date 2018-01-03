#include <stdio.h>

int main(void)
{
	char str[80];  /* “ü—Í‚³‚ê‚½•¶š—ñ‚ğŠi”[‚·‚éêŠ */


	puts( "‰½‚©•¶š—ñ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" );
	fgets( str, 80, stdin );

	/* “ü—Í‚³‚ê‚½•¶š—ñ‚ğ‚»‚Ì‚Ü‚Üo—Í‚·‚é */
	puts( str );
	getchar();
	return 0;
}