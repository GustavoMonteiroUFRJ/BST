#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <pthread.h>
// #include <math.h>


struct teste
{
	int x;
	void* p;
	double d;
};

typedef struct teste teste;

int main(int argc, char const *argv[]){
	
	teste a;

	//a = (teste*) malloc(sizeof(teste)*1);

	a.x = 10;
	a.p = (void*) &a;
	a.d = 10.2;


	printf("%d - %g = %g \n", a.x, a.d, a.x - a.d );
	free(&a);
	printf("%d - %g = %g \n", a.x, a.d, a.x - a.d );

	return 0;
}