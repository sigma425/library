#include <stdio.h>

int main(void)
{
	char str[80];  /* 入力された文字列を格納する場所 */


	puts( "何か文字列を入力してください。" );
	fgets( str, 80, stdin );

	/* 入力された文字列をそのまま出力する */
	puts( str );
	getchar();
	return 0;
}