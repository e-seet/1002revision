// Preprocessor Directive: They are executed before a program is compiled
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Example of pre-processor directive
#define ClassSize 10


typedef struct Student{
	char name[20];
	int roll;
	int age;
	char class[12];
	struct Student *next;
} Student;

struct Fruit
{
	char fruitname[20];
	int	value;
};

// An example of function prototype
int total(int x);

// Essentially, take a string and split by the delimiter. Return an array of pointers
char	**ft_split(char const *s, char c);