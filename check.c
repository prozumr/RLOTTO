// check how to return an array from function

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void transform(int *MyArray) ;

int main() {
	
	char eingabe[7];
	char ausgabe[7];
	
	printf("Mache deine Eingabe: ");
	scanf("%s", &eingabe);
	printf("\nDeine Eingabe war; %s\n", eingabe);
	
	// ausgabe = transform(eingabe);
	
	return 0;
}


void transform(int *MyArray) {
	
	char* arr = malloc(7);
    strcpy(arr, MyArray);
    return arr;
	
}


/*
char *testfunc() {
    char* arr = malloc(100);
    strcpy(arr,"xxxx");
    return arr;
} */


/*
char* testfunc()
{
    char* str = malloc(10 * sizeof(char));
    return str;
} */