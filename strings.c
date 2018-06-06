/*
Name: Zawwwar Naseer & Will Jones
Description: implements our own version of the core functions in C’s string
processing library
Time: 8 hours

*/


#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
//Concatantes the two strings given to the function and assigns to destination
char* mystrcat(char* dest, const char* src){
int d = mystrlen(dest);
int s = mystrlen(src);
char* newnew = malloc(sizeof(char)*(d+s+1)); //creates space for both strings
int k=0;
for (int i=0; dest[i] != '\0'; i++){  //frist string added to newnew
  newnew[i]=dest[i];
  k++;
}

for (int j=0; j<=s; j++){ //second string added to newnew
  newnew[k+j]=src[j];
}
dest = newnew;

return dest;
}

//returns a string pointer pointing to the first occurance of a given character
//in a given string
char* mystrchr(const char* s, int c){

  while (*s != (char) c) {
          if (!*s++) {
              return NULL;
          }
      }

      char* ret = (char *)s;

      return ret;
}

//lexiologically comapres two given Strings and returns and integer value that indicates
//which string has greater value
int mystrcmp(const char* string1, const char* string2){
int str1 = 0;
int str2 = 0;
int x = 0;
int y = 0;

for (size_t i = 0; string1[i] != '\0'; i++) {
  x = string1[i];
  str1 += x;
}

for (size_t i = 0; string2[i] != '\0'; i++) {
  y = string2[i];
  str2 += y;
}

int val = str1 - str2;
return val;


}

//copies one string into another strings pointer
char* mystrcpy(char* str1, const char* str2){

  for (size_t i = 0; str2[i] != '\0'; i++) {
    str1[i] = str2[i];
  }

  return str1;
}

//creates a duplicate string and returns the pointer to that string
char* mystrdup(const char* s){

  char *d = malloc(mystrlen(s) + 1);   // Space for length plus nul
     if (d == NULL) {                  // No memory
       return NULL;
     }
     mystrcpy (d,s);                        // Copy the characters
     return d;

}

//returns the lenght of a given string based on its number of chars
size_t mystrlen(const char* str){
  size_t counter = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    counter++;
  }

  return counter;

}

//finds the first occurrence of the substring needle in the string haystack
char* mystrstr(const char* haystack, const char* needle){
  size_t n = mystrlen(needle);
  size_t h = mystrlen(haystack);
  size_t diff = h-n;
  int index = 0;
  for (int i = 0; i<diff; i++){
    for (int j = 0; j<n; j++){
      if (haystack[i+j]!=needle[j]){
        break;
      }
      if (j == n-1 && haystack[i+j]==needle[j]){
        index = i;
        return (char*)&haystack[index];
      }
    }
  }
  return NULL;
}
