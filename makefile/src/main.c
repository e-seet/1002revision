// Running in vscode?
// gcc -o main main.c utils.c
// ./main

#include "../include/utils.h"

void preprocessor()
{
	int i;
	i = 0;
	
	printf("Class Size: %d\n", ClassSize);
	while (ClassSize > i)
	{
		printf("i: %d\n", i);
		i++;
	}

	// Where does the total function comes from? 
	// It comes from utils.c, where you defined the function prototype
	// Therefore the compiler looks for the function and finds it in utils.c
	// Hence, there is no fault
	printf("Total Sweets: %d\n", total(ClassSize));
}

void passbyvalue(int c)
{
  printf("value:%d\n", c);
  c = c + c;
  printf("value:%d\n", c);
}

void passbyreference(int *c)
{
  printf("value:%d\n", *c);
  *c = *c + *c;
  printf("value:%d\n", *c);
}

// Look at the difference between the two functions
// You will be able to see that pass by reference,
// we are passing the address of the variable
// and in pass by value, we are passing the value of the variable
// As a result, in pass by reference, we are able to change the value of the variable
// while in pass by value, we are not able to change the value of the variable
void passbyreferenceorvalue() {
  // Pass by reference vs Pass by value
  int a = 5;
  int *ptr = &a;

  /* Pass by value */
  printf("value of a:%d\n", a);
  passbyvalue(a);
  printf("value of a:%d\n", a);

  /* Pass by ref */
  printf("Derefence ptr:%d\n", *ptr);
  printf("Check value of a:%d\n", a);
  passbyreference(ptr);
  printf("Derefence the ptr:%d\n", *ptr);
  printf("Check the updated value of a:%d\n\n\n", a);
}

char *strFromMalloc()
{
	// Memory allocation for the str pointer
	// sizeof char refers to how much space each char takes
	// strlen refers to the length of the string so that we can properly allocate the memory
	char *str = (char *) malloc(sizeof(char) * strlen("Good Day!"));
	if (str == NULL)
		printf("Error");

	//	copy the string into the char pointer.
	//	Note: Strcpy is a function that copies the string from the second argument to the first argument
	// 	Strcpy is available only after importing string.h
	strcpy(str, "Good Day!");
	return str;
}

void printarray(char *arr, int len)
{
	int i = 0;

	while (len > i)
	{
		printf("%c", arr[i]);
		i++;
	}
}

void printarray2(char *arr)
{
	int i = 0;
	while(arr[i]!='\0')
	{
		printf("%c", arr[i]);
		i++;
	}
}

// Char pointers
void charpointersBasic()
{
	// take note of the different ways you are using char pointers
	char *a = "Today";
	char b[] = "is";
	char c[1024] = "a";
	char *d = strFromMalloc();
	char e[] = {'a','b','c','d'};
	char f[] = {'a','b','c','d', '\0'};

	// You can print all of them in the same format
	printf("%s\n", a);
	printf("%s\n", b);
	printf("%s\n", c);
	printf("%s\n", d);

	int length = sizeof(e) / sizeof(e[0]);
	printarray(e, length);
	printarray2(f);

	//	Note: After malloc, it is important to free the memory
	free(d);
}

// Here we will be looking in depth into char array / char pointers
// All of them can be referenced by char pointer [char *]
// Why do we classify them as char pointers? Despite the fact that they are char arrays?
void charpointersBasic2()
{
	char *a = "Today";
	char b[] = "Today";
	int i = 0;
	// Let's take a look at the string first
	printf("a:%s\nb:%s\n", a, b);

	// Look at this while loop for a and b.
	// You will not be able to see any difference
	// despite being declared in 2 different manner
	// This is because they are both char pointers
	while (a[i] != '\0' && b[i] != '\0')
	{
		printf("a:%c\n", a[i]);
		printf("b:%c\n", b[i]);
		i++;
	}
}

// 4 of the string prototype
// char *strcpy(char *dest, const char *src);
// char *strncpy(char *dest, const char *src, size_t n);
// char *strcat(char *dest, const char *src);
// char *strncat(char *dest, const char *src, size_t n);

// 2 of the string comparison prototype
// int strcmp(const char *s1, const char *s2);
// int strncmp(const char *s1, const char *s2, size_t n);

void stringcomparison()
{
	char *dest = (char *) malloc(sizeof(char) * strlen("Hello!"));
	if (dest == NULL)
		printf("Error with malloc");
	char *src = (char *) malloc(sizeof(char) * strlen("World!"));
	if (src == NULL)
		printf("Error with malloc");
	dest = strcpy(dest, "Hello!");
	src = strcpy(src, "World!");

	char *example1 = (char *) malloc(sizeof(char) * strlen(dest));
	if (example1 == NULL)
		printf("Error with malloc");
	example1 = strcpy(example1, src);
	printf("example1: %s\n", example1);

	// Note: strncpy is a function that copies the string from the second argument to the first argument
	// the 3rd argument represents how many characters you want to copy over.
	char *example2 = (char *) malloc(sizeof(char) * strlen(dest));
	if (example2 == NULL)
		printf("Error with malloc");
	example2 = strncpy(example2, src, 3);
	printf("example2: %s\n", example2);

	// Simply put the 2 strings together.
	// note to allocate enough space for this.
	char *example3 = (char *) malloc(sizeof(char) * (strlen(dest) + strlen(src)) );
	if (example3 == NULL)
		printf("Error with malloc");
	example3 = strcpy(example3, dest);
	example3 = strcat(example3, src);
	printf("example3: %s\n", example3);

	// What happens if there is not enough space allocated?
	char *example3_1 = (char *) malloc(sizeof(char) * (strlen(dest)));
	if (example3_1 == NULL)
		printf("Error with malloc");
	example3_1 = strcat(example3_1, src);
	printf("example3.1: %s\n", example3_1);

	char *example4 = (char *) malloc ( sizeof(char) * strlen(dest) + strlen(src));
	if (example4 == NULL)
		printf("Error with malloc");
	example4 = strncat(example4, src, 3);
	printf("example4: %s\n", example4);

	// string comparison
	char *example5 = (char *) malloc(sizeof(char) * strlen(dest));
	if (example5 == NULL)
		printf("Error with malloc");
	example5 = strcpy(example5, dest);
	printf("example 5 [Result = 0 as it matches totally]: %d\n", strcmp(example5, dest));
	printf("example 5 [Result != 0 ] as it doesn't not match: %d\n", strcmp(src, dest));
	printf("How did this integer value come about?\n");
	printf("It is the ascii difference between the first character that does not match\n");
	printf("In this case: Src[0] - Dest[0] = W(87) - H(72) \n");


	char *example6 = (char *) malloc(sizeof(char) * 3);
	if (example6 == NULL)
		printf("Error with malloc");
	example6 = strcpy(example6, "Hel");
	printf("example 6 [Result = 0 as it matches totally]: %d\n", strncmp(example6, dest, 2));
	printf("example 6 [Result != 0 as it does not match]: %d\n", strncmp(example6, src, 2));

	free(dest);
	free(src);
	free(example1);
	free(example2);
	free(example3);
	free(example3_1);
	free(example4);
	free(example5);
	free(example6);
}

// Note: To go through
void charpointersintermediate2()
{
	// Note: Always ask yourself whether you are derefencing?
	// If you are not dereferencing, you are printing the memory address

	int a = 6;
	int *b = &a;
	// By now you should already know a and b
	printf("Memory address of a: %p\n", &a);

	int *c;
	int **d;
	// What about c and d?
	c = b;
	d = &c;
	
	// What are we printing here?
	printf("C's content:%p\n\n", c);
	printf("C derefenced:%d\n\n", *c);

	printf("C's memory address:%p\n", &c);

	printf("D's content:%p\n\n", d);

	printf("D derefenced:%p\n", *d);
	printf("A's memory address: %p\n\n", &a);
	
	// Bonus: What about **d?
	// printf("D derefenced twice:%d\n", **d);

}

// manevouring of pointers while i print each characters
void offsetPointers2(char *str)
{
	char *ptr = str;
	
	while(*ptr)
	{
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
	printf("what is the pointer now:%c\n", *ptr);
	
	// note we are using '' instead of ""
	if (*ptr == '\0')
		printf("it is a null terminator\n");
}

// adding of pointers to see certain characters
void offsetPointers1(char *str)
{
	char *ptr1;
	char *ptr2;
	ptr1 = str;
	ptr2 = str;

	printf("Ptr1 char [A]:%c\n", *(ptr1));
	printf("Ptr2 char [A]:%c\n", *(ptr2));
	int i = 0;
	while(*str)
	{
		printf("%d:%c\n",i ,*str);
		str++;
		i ++;
	}

	//part 1:
	printf("\nPtr1 char:%c\n", *(ptr1+3));
	printf("Ptr2 char:%c\n", *(ptr2+3));
	printf("Ptr1 char [A]:%c\n", *(ptr1));

	//part 2: Moving the pointers to the next character / memory address
	ptr1 = ptr1 + 3;
	printf("Ptr1 char [D]:%c\n", *(ptr1));
	
	*ptr2 = *ptr2 + 4;
	printf("Ptr2 char [E]:%c\n", *(ptr2));

	//What's wrong with this?
	printf("Ptr2 char [?]:%c\n", *(ptr2-1));

}

// !To Go through
// !IMPORTANT: Swapping of pointers
void swappointer()
{
	int a = 5;
	int *ptr1 = &a;

	int b = 10;
	int *ptr2 = &b;
	printf("Before swapping\n");
	printf("Derefence ptr1:%d\n", *ptr1);
	printf("Derefence ptr2:%d\n", *ptr2);

	//how to swap pointer?
	int *temp;
	temp = ptr1;

	ptr1 = ptr2;
	ptr2 = temp;

	printf("After swapping\n");
	printf("Derefence ptr1:%d\n", *ptr1);
	printf("Derefence ptr2:%d\n", *ptr2);
}

// using while loop with i to print each character
// then show that i can see either character even at the end
void usingsubscripted(char *str)
{
	printf("Original str:%s\n", str);
	int i = 0;
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	
	printf("Notice that there string is unchanged as we did not move the pointer\n");
	printf("str:%s\n", str);
	printf("First character: %c", str[0]);
}

// More stuff about pointers
// !!To go through
void charpointersintermediate1()
{
	char *str = (char *) malloc(sizeof(char) * strlen("ABCDEFGHIJKL"));
	if (str == NULL)
		printf("Error with malloc");
	str = strcpy(str, "ABCDEFGHIJKL");

	printf("The original str:%s\n\n", str);

	// offsetPointers1(str);
	// offsetPointers2(str);
	// usingsubscripted(str);
	//Note: We need to always free the memory after using malloc
	free(str);
}

void arrayofpointerss()
{
	char *str = "The quick brown fox jumps over the lazy dog";
	char **arrayofpointers;
	
	arrayofpointers = ft_split(str, ' ');

	int i = 0;
	while(arrayofpointers[i])
	{
		printf("Memory address of the pointer:%p\n", arrayofpointers[i]);
		printf("Each pointer's string:%s\n", arrayofpointers[i]);
		printf("First character of the string:%c\n\n", arrayofpointers[i][1]);
		i++;
	}

	// Free everything back
	while(arrayofpointers[i])
	{
		free(arrayofpointers[i]);
		arrayofpointers[i] = NULL;
		i++;
	}
	free(arrayofpointers);

}

void testyourself() {

  int a[5];
  for (int i = 0; i < 5; i++)
  {
    a[i] = 1;
    for (int j = 0; j < i; j++)
	{
      a[i] += a[j];
    }
  }

  int *pa = a + 5 - 1;

  while (pa >= a)
  {
    int n = *pa;
    while (n >= 1)
	{
      n = n / 2;
    }
    printf("%d\n", *pa);
    pa--;
  }
  printf("\n\n");
}

void memoryallocation()
{
	char *str;
	int i;

	printf("size of int:%lu\n", sizeof(int));
	printf("size of char:%lu\n\n", sizeof(char));

	int length = strlen("Hello World!");

	// note malloc sometimes will fill with \0
	// but other times there may be garbish
	str = malloc(sizeof(char) * length);
	if (str == NULL)
		printf("Error with malloc");

	while(*str++)
	{
		printf("%c", *str);
	}

	char *str2;
	str2 = calloc(sizeof(char), length);
	i = 0;
	while(str2[i] != '\0')
	{
		printf("%c", str2[i]);
		i++;
	}
	printf("value of i:%d\n",i);

	free(str);
	free(str2);
	
}



void memmoryallocationstruct()
{
	/* initialise a variable of type student */
	// Student stud1 = { "Sachin Kumar", 101, 16, "INF1002" };
	// struct Fruit fruit1 = {"mango", 5};
	Student *head = NULL;

	Student *student1 = (Student *) malloc(sizeof(Student));
	if (student1 == NULL)
		printf("Error malloc-ing");

	if (head == NULL)
		head = student1;

	// filling the details of the first node
	strcpy(student1->name, "Ahmad");
	student1->next = NULL;
	student1->age = 10;
	student1->roll = 20;
	printf("Name:%s, Age:%d, Roll:%d\n", student1->name, student1->age, student1->roll);
	
	// Create another node and link it.
	Student *student2 = (Student *) malloc (sizeof(Student));
	if(student2 == NULL)
		printf("Error malloc-ing");
	
	// filling the details of the second node
	strcpy(student2->name, "Barbie");
	student2->next = NULL;
	student2->age = 11;
	student2->roll = 21;

	// create a pointer, reference to head
	Student *curr = NULL;
	if (head != NULL)
		curr = head;
	
	// Loop to the last node
	printf("\nLooping with curr pointer \n");
	// Why does this not print anything?
	while(curr->next != NULL)
	{
		printf("name:%s\n", curr->name);
		curr = curr ->next;
	}
	// Last node points to the newly created node
	curr->next = student2;


	// Create the third node and link it
	Student *student3 = (Student *) malloc (sizeof(Student));
	if(student3 == NULL)
		printf("Error malloc-ing");

	// Filling the details for node 3
	strcpy(student3->name, "Catherine");
	student3->next = NULL;
	student3->age = 13;
	student3->roll = 22;

	// Create another pointer. 
	// Alternatively you can reuse the previous pointer
	// Here, we create a new pointer to show the difference
	Student *cur2 = NULL;
	if (head != NULL)
		cur2 = head;
	printf("\n\nLooping with cur2 pointer \n");
	// why does this print only one?
	while(cur2->next != NULL)
	{
		printf("name:%s\n", cur2->name);
		cur2 = cur2 ->next;
	}
	// Link the last node to the newly created node
	cur2 -> next = student3;

	Student *cur;
	cur = head;
	//Is there any difference between the 2 while loop?

	while(cur->next != NULL)
	{

		printf("name:%s\n", cur->name);
		cur = cur->next;

	}


	cur = head;
	while(cur)
{		printf("name:%s\n", cur->name);
		cur = cur->next;
}


	// Link list operation (delete)
	Student *temp;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

void linkedlist2()
{
	Student *head = NULL;
	Student *curr;

	//node 1
	Student *student1 = (Student *) malloc(sizeof(Student));
	if (student1 == NULL)
		printf("Error malloc-ing");
	strcpy(student1->name, "Ahmad");
	student1->next = NULL;
	student1->age = 10;
	student1->roll = 20;

	head = student1;
	curr = head;

	//node 2
	Student *student2 = (Student *) malloc (sizeof(Student));
	if(student2 == NULL)
		printf("Error malloc-ing");
	strcpy(student2->name, "Barbie");
	student2->next = NULL;
	student2->age = 11;
	student2->roll = 21;

	curr ->next = student2;
	curr = curr->next;

	//node3
	Student *student3 = (Student *) malloc (sizeof(Student));
	if(student3 == NULL)
		printf("Error malloc-ing");
	strcpy(student3->name, "Catherine");
	student3->next = NULL;
	student3->age = 13;
	student3->roll = 22;

	curr ->next = student3;
	curr = curr->next;

	curr = head;
	while(curr)
	{
		printf("name:%s\n", curr->name);
		curr = curr->next;
	}

	// What if i want to insert Catherine before Barbie
	Student *prev;
	curr = head;
	while(curr)
	{
		printf("name:%s\n", curr->name);
		if (strcmp(curr->name, "Barbie") == 0)
		{
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("sorting the linked list example:\n\n");
	// Currently:
	// node1: prev [A]
	// node2: curr [B]
	// node3: temp [c]
	Student *temp;
	temp = curr ->next; 

	prev -> next = temp; // a points to c
	temp -> next = curr; // c points to b
	curr -> next = NULL; //!! important to leave the last node to null

	Student *cur;
	cur = prev; // prev have become the head / first node
	// check out result here
	while(cur)
	{
		printf("%s\n", cur->name);
		cur = cur->next;
	}

}

int main(void) {
	//Pre-processor && Define [Wk8]
	// preprocessor();

	// Week 9
	// passbyreferenceorvalue();
	// charpointersBasic(); // The various way of declaring a char pointer
	// charpointersBasic2(); // char *str vs char str[]
	// String manipulations
	// stringcomparison(); // String comparison

	// Week 10
	// swappointer();
	// charpointersintermediate1(); // Pointers: Pointer to memory address. Pointer to pointer
	// charpointersintermediate2(); // More about pointers and 
	
	// Good to know. Do not need to know how to write
	// Focus more on the concept and how i have an array of pointers
	// and how i access each individual pointer inside
	// arrayofpointerss();

	// Self study: constant and its uses
	// testyourself();

	//Week 11
	//malloc vs calloc.
	// note malloc may have garbage value sometimes
	// memoryallocation();
	
	// Memory allocation for Struct [user defined data type / class if you like it]
	// memmoryallocationstruct(); // Includes linked list too

	//linked List sorting position
	// linkedlist2();

}