#include<stdio.h>

main() {

	char s[10] = { 'a','b','c',0,'i' };
	for (int i = 0; i < 10; i++) {
		printf("%c", s[i]);
	}
	return 0;
}