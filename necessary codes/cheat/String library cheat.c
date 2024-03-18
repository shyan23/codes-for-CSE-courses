strcpy() is a standard library function in C++ and is used to copy one string to another. In C++ it is present in the <string.h> and <cstring> header files. 

Syntax: 

char* strcpy(char* dest, const char* src);

Parameters: This method accepts the following parameters:  

    dest: Pointer to the destination array where the content is to be copied.
    srcThe C library function char *strncpy(char *dest, const char *src, size_t n) copies up to n characters from the string pointed to, by src to dest. In a case where the length of src is less than that of n, the remainder of dest will be padded with null bytes.
Declaration

Following is the declaration for strncpy() function.

char *strncpy(char *dest, const char *src, size_t n)

Parameters

    dest − This is the pointer to the destination array where the content is to be copied.

    src − This is the string to be copied.

    n − The number of characters to be copied from source.

Return Value

This function returns the pointer to the copied string.
Example

The following example shows the usage of strncpy() function. Here we have used function memset() to clear the memory location.
Live Demo

#include <stdio.h>
#include <string.h>

int main () {
   char src[40];
   char dest[12];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strncpy(dest, src, 10);

   printf("Final copied string : %s\n", dest);
   
   return(0);
}

Let us compile and run the above program that will produce the following result −

Final copied string : This is tu
: string which will be copied.

Return Value: After copying the source string to the destination string, the strcpy() function returns a pointer to the destination string.

Example:

// C++ program to illustrate
// strcpy() function in C/C++
#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    // Strings Declared
    char str1[] = "Hello Geeks!";
    char str2[] = "GeeksforGeeks";
 
    char str3[40];
    char str4[40];
 
    char str5[] = "GfG";
 
    // String copy used
    strcpy(str2, str1);
    strcpy(str3, "Copy successful");
    strcpy(str4, str5);
 
    // Strings Printed
    cout << "str1: " << str1 << "\nstr2: " << str2
         << "\nstr3: " << str3 << "\nstr4: " << str4;
   
    return 0;
}
Output

str1: Hello Geeks!
str2: Hello Geeks!
str3: Copy successful
str4: GfG

//////////  ////            /   //  /   /   /   /   /   /   /   /   /   /   /   /   /   //  /   /   /   /   /   /
The C library function char *strncpy(char *dest, const char *src, size_t n) copies up to n characters from the string pointed to, by src to dest. In a case where the length of src is less than that of n, the remainder of dest will be padded with null bytes.
Declaration

Following is the declaration for strncpy() function.

char *strncpy(char *dest, const char *src, size_t n)

Parameters

    dest − This is the pointer to the destination array where the content is to be copied.

    src − This is the string to be copied.

    n − The number of characters to be copied from source.

Return Value

This function returns the pointer to the copied string.
Example

The following example shows the usage of strncpy() function. Here we have used function memset() to clear the memory location.
Live Demo

#include <stdio.h>
#include <string.h>

int main () {
   char src[40];
   char dest[12];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strncpy(dest, src, 10);

   printf("Final copied string : %s\n", dest);
   
   return(0);
}

Let us compile and run the above program that will produce the following result −

Final copied string : This is tu

    /////   //  /   /   /   /   /   /   /   /   /   /   /   //  /   /   /   /   /   /   //  


                // Strncat
Application 
Given two strings src and dest in C++, we need to append ‘n’ character from src to dest, let’s say n=5.

Examples:  

Input:  src = "world"
        dest = "Hello "
Output: "Hello world"

Input:  src = "efghijkl"
        dest = "abcd"
Output: "abcdefghi"

Program:  

// C,C++ program demonstrate functionality of strncat()
#include <stdio.h>
#include <string.h>
 
int main()
{
   
   // Take any two strings
   char src[50] = "efghijkl";
   char dest[50]= "abcd";
  
   // Appends 5 character from src to dest
   strncat(dest, src, 5);
     
   // Prints the string
   printf("Source string : %s\n", src);
   printf("Destination string : %s", dest);
    
   return 0;
}

Output: 

Source string : efghijkl
Destination string : abcdefghi



    /   /   /   /   //  /   /   /   /   /   //  /   /   /   /   /   /   /   /   /   /   /   /   /   /   //  /   

C strcmp() is a built-in library function that is used for string comparison. This function takes two strings (array of characters) as arguments, compares these two strings lexicographically, and then returns 0,1, or -1 as the result. It is defined inside <string.h> header file with its prototype as follows:
Syntax of strcmp() in C

strcmp(first_str, second_str );

Parameters of strcmp() in C

This function takes two strings (array of characters) as parameters:

    first_str: First string is taken as a pointer to the constant character (i.e. immutable string).
    second_str: Second string is taken as a pointer to a constant character.

    Note: The reason arguments are taken as const char * instead of only char * is so that the function could not modify the string and also make them applicable for constant strings.

Return Value of strcmp() in C

The strcmp() function returns three different values after the comparison of the two strings which are as follows:
1. Zero ( 0 )

A value equal to zero when both strings are found to be identical. That is, all of the characters in both strings are the same.
2. Greater than Zero ( > 0 )

A value greater than zero is returned when the first not-matching character in first_str has a greater ASCII value than the corresponding character in second_str or we can also say that if the character in first_str is lexicographically after the character of second_str, then zero is returned.
3. Lesser than Zero ( < 0 )

A value less than zero is returned when the first not-matching character in first_str has a lesser ASCII value than the corresponding character in second_str. We can also say that if the character in first_str is lexicographically before the character of second_str, zero is returned.

To know more about ASCII values, refer to this article – ASCII Table
How to use the strcmp() function in C

The following example demonstrates how to use the strcmp() function in C:

// C Program to Demonstrate the use of strcmp() function
#include <stdio.h>
#include <string.h>
 
int main()
{
    // declaring two same string
    char* first_str = "Geeks";
    char* second_str = "Geeks";
 
    // printing the strings
    printf("First String: %s\n", first_str);
    printf("Second String: %s\n", second_str);
 
    // printing the return value of the strcmp()
    printf("Return value of strcmp(): %d",
           strcmp(first_str, second_str));
 
    return 0;
}
Output

First String: Geeks
Second String: Geeks
Return value of strcmp(): 0


    /   /   /   /   /   /   /   /   /   /   //  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   //  /   

    In C/C++, std::strstr() is a predefined function used for string matching. <string.h> is the header file required for string functions. This function takes two strings s1 and s2 as arguments and finds the first occurrence of the string s2 in the string s1. The process of matching does not include the terminating null-characters(‘\0’), but function stops there. 
Syntax

char *strstr (const char *s1, const char *s2);

Parameters

    s1: This is the main string to be examined.
    s2: This is the sub-string to be searched in string.

Return Value

    This function returns a pointer point to the first character of the found s2 in s1 otherwise a null pointer if s2 is not present in s1.
    If s2 points to an empty string, s1 is returned.

Example

The below program illustrates the usage of the strstr() function.

// C program to illustrate strstr()
 
#include <stdio.h>
#include <string.h>
 
int main()
{
    // Take any two strings
    char s1[] = "GeeksforGeeks";
    char s2[] = "for";
    char* p;
 
    // Find first occurrence of s2 in s1
    p = strstr(s1, s2);
 
    // Prints the result
    if (p) {
        printf("String found\n");
        printf("First occurrence of string '%s' in '%s' is "
               "'%s'",
               s2, s1, p);
    }
    else
        printf("String not found\n");
 
    return 0;
}
Output

String found
First occurrence of string 'for' in 'GeeksforGeeks' is 'forGeeks'

Time Complexity: O(n + m), where n is the size of s1 and m is the size of s2.
Auxiliary Space: O(m), where m is the size of s2.



//  /   /   /   /   /   / / /   /   /   //      //  /   /   /   /   //  /   /   /   /   /   /   //  


The C library function strcspn() calculates the length of the number of characters before the 1st occurrence of character present in both the string.
Syntax :

strcspn(const char *str1, const char *str2)

Parameters:
str1 : The Target string in which search has to be made.
str2 : Argument string containing characters
to match in target string.

Return Value:
This function returns the number of characters before the 1st occurrence
of character present in both the string.

// C code to demonstrate the working of 
// strcspn() 
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
  
    int size; 
  
    // initializing strings 
    char str1[] = "geeksforgeeks"; 
    char str2[] = "kfc"; 
  
    // using strcspn() to calculate initial chars 
    // before 1st matching chars. 
    // returns 3 
    size = strcspn(str1, str2); 
  
    printf("The unmatched characters before first matched character :  %d\n", size); 
} 

Output:

The unmatched characters before first matched character :  3

Practical Application : There can be many practical application of this function, be it word games or irregularity calculator. A simple word game is demonstrated in this article.

Rules : According to this game, 2 players play and one player initially generated a string and is asked to produce a string which has as many unmatched characters. After 1 round, player producing string with maximum unmatched characters wins.

// C code to demonstrate the application of 
// strcspn() 
  
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
int main() 
{ 
  
    int score1 = 0, score2 = 0, k = 0, sizen = 0, size = 0; 
  
    // initial Round1 strings 
    char player1[] = "geeks"; 
    char play2[] = ""; 
  
    while (1) { 
        // generating random character 
        char randoml = 'a' + (random() % 26); 
        play2[k++] = randoml; 
  
        size = strcspn(play2, player1); 
  
        if (size == sizen) { 
            // if the character is present, break 
            score2 = size; 
            break; 
        } 
        else { 
            sizen = size; 
        } 
    } 
  
    // initial Round2 strings 
    const char player2[] = "geeks"; 
    char play1[] = ""; 
    k = 0, sizen = 0; 
  
    while (1) { 
        // generating random character 
        char randoml = 'a' + (random() % 26); 
        play1[k++] = randoml; 
  
        size = strcspn(play1, player2); 
  
        if (size == sizen) { 
  
            // if the character is present, break 
            score1 = size; 
            break; 
        } 
        else { 
            sizen = size; 
        } 
    } 
  
    if (score1 > score2) 
        printf("Player 1 won!! Score : %d", score1); 
    else if (score2 > score1) 
        printf("Player 2 won!! Score : %d", score2); 
    else
        printf("Match Drawn!! Score : %d", score1); 
} 

Output:

Match Drawn!! Score : 2


// /    /   /// /   /   /   /   /   /   /   /   /   /   /   /       /   /   /   /   /   /   /   /   /   /   /   /   /   //  

The strspn() function returns the length of the initial substring of the string pointed to by str1 that is made up of only those character contained in the string pointed to by str2.

Syntax :

size_t strspn(const char *str1, const char *str2)
str1 : string to be scanned.
str2 : string containing the 
characters to match.
Return Value : This function
returns the number of characters
in the initial segment of str1 
which consist only of characters 
from str2.

   
// C program to illustrate strspn() function 
#include <stdio.h> 
#include <string.h> 
  
int main () { 
   int len = strspn("geeks for geeks","geek"); 
   printf("Length of initial segment matching : %d\n", len );     
   return(0); 
} 

Output:

Length of initial segment matching 4

   
// C program to illustrate strspn() function 
#include <stdio.h> 
#include <string.h> 
  
int main () { 
   int len = strspn("i am","xyz"); 
   printf("Length of initial segment matching : %d\n", len ); 
   return(0); 
} 

Output:

Length of initial segment matching 0




///         /   /   /   /   //  /   /   /   /       //  /   /   /   /   //  /   /   //  /   /   

memset() is used to fill a block of memory with a particular value.
The syntax of memset() function is as follows :

// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting 
//         from ptr to be filled
void *memset(void *ptr, int x, size_t n);

Note that ptr is a void pointer, so that we can pass any type of pointer to this function.

Let us see a simple example in C to demonstrate how memset() function is used:

// C program to demonstrate working of memset() 
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[50] = "GeeksForGeeks is for programming geeks."; 
    printf("\nBefore memset(): %s\n", str); 
  
    // Fill 8 characters starting from str[13] with '.' 
    memset(str + 13, '.', 8*sizeof(char)); 
  
    printf("After memset():  %s", str); 
    return 0; 
} 

Output:

Before memset(): GeeksForGeeks is for programming geeks.
After memset(): GeeksForGeeks........programming geeks.

Explanation: (str + 13) points to first space (0 based index) of the string “GeeksForGeeks is for programming geeks.”, and memset() sets the character ‘.’ starting from first ‘ ‘ of the string up to 8 character positions of the given string and hence we get the output as shown above.

// C program to demonstrate working of memset() 
#include <stdio.h> 
#include <string.h> 
  
void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]); 
} 
  
int main() 
{ 
    int n = 10; 
    int arr[n]; 
  
    // Fill whole array with 0. 
    memset(arr, 0, n*sizeof(arr[0])); 
    printf("Array after memset()\n"); 
    printArray(arr, n); 
  
    return 0; 
} 

Output:

0 0 0 0 0 0 0 0 0 0


Exercise :
Predict the output of below program.

// C program to demonstrate working of memset() 
#include <stdio.h> 
#include <string.h> 
  
void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]); 
} 
  
int main() 
{ 
    int n = 10; 
    int arr[n]; 
  
    // Fill whole array with 100. 
    memset(arr, 10, n*sizeof(arr[0])); 
    printf("Array after memset()\n"); 
    printArray(arr, n); 
  
    return 0; 
} 


 //  /   /   /   /   /   /   /   /   /   /   /   /   /       /   /   /   /   /   /   /   /   //  /   


The memcpy() function in C and C++ is used to copy a block of memory from one location to another. Unlike other copy functions, the memcpy function copies the specified number of bytes from one memory location to the other memory location regardless of the type of data stored.

It is declared in <string.h> header file. In C++, it is also defined inside <cstring> header file.
Syntax of memcpy

The memcpy function is declared as:

void *memcpy(void *to, const void *from, size_t numBytes);

Parameters

    to: A pointer to the memory location where the copied data will be stored.
    from: A pointer to the memory location from where the data is to be copied.
    numBytes: The number of bytes to be copied.

Return Value

    This function returns a pointer to the memory location where data is copied.

Example of memcpy

Below is the C program to show the working of memcpy()

// C program to demonstrate working of memcpy
#include <stdio.h>
#include <string.h>
 
int main()
{
    char str1[] = "Geeks";
    char str2[] = "Quiz";
 
    puts("str1 before memcpy ");
    puts(str1);
 
    // Copies contents of str2 to str1
    memcpy(str1, str2, sizeof(str2));
 
    puts("\nstr1 after memcpy ");
    puts(str1);
 
    return 0;
}
Output

str1 before memcpy 
Geeks

str1 after memcpy 
Quiz



//  /   /   /   /   /   /   /   /   /   /   //  /   /   /   /   /   /   //  /


The C library function int strncmp(const char *str1, const char *str2, size_t n) compares at most the first n bytes of str1 and str2.
Declaration

Following is the declaration for strncmp() function.

int strncmp(const char *str1, const char *str2, size_t n)

Parameters

    str1 − This is the first string to be compared.

    str2 − This is the second string to be compared.

    n − The maximum number of characters to be compared.

Return Value

This function return values that are as follows −

    if Return value < 0 then it indicates str1 is less than str2.

    if Return value > 0 then it indicates str2 is less than str1.

    if Return value = 0 then it indicates str1 is equal to str2.

Example

The following example shows the usage of strncmp() function.
Live Demo

#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "abcdef");
   strcpy(str2, "ABCDEF");

   ret = strncmp(str1, str2, 4);

   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}

Let us compile and run the above program that will produce the following result −

str2 is less than str1


//  /   /   /   //  /   /   /   /   /   /   /   /   /       /   /   /   /   //      //  /   /   /   /


Description

The C library function char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimiter delim.
Declaration

Following is the declaration for strtok() function.

char *strtok(char *str, const char *delim)

Parameters

    str − The contents of this string are modified and broken into smaller strings (tokens).

    delim − This is the C string containing the delimiters. These may vary from one call to another.

Return Value

This function returns a pointer to the first token found in the string. A null pointer is returned if there are no tokens left to retrieve.
Example

The following example shows the usage of strtok() function.
Live Demo

#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}

Let us compile and run the above program that will produce the following result −

This is 
  www.tutorialspoint.com 
  website


//  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   

Description

The C library function char *strpbrk(const char *str1, const char *str2) finds the first character in the string str1 that matches any character specified in str2. This does not include the terminating null-characters.
Declaration

Following is the declaration for strpbrk() function.

char *strpbrk(const char *str1, const char *str2)

Parameters

    str1 − This is the C string to be scanned.

    str2 − This is the C string containing the characters to match.

Return Value

This function returns a pointer to the character in str1 that matches one of the characters in str2, or NULL if no such character is found.
Example

The following example shows the usage of strpbrk() function.
Live Demo

#include <stdio.h>
#include <string.h>

int main () {
   const char str1[] = "abcde2fghi3jk4l";
   const char str2[] = "34";
   char *ret;

   ret = strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found");
   }
   
   return(0);
}

Let us compile and run the above program that will produce the following result −

First matching character: 3







