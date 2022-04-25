#include <stdio.h>
#include <string.h>

void func(char* p, int x){
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){
    printf("Hello world!\n");
    char s1[10] = "Hello ";
    char s2[10] = "World!\n";
    strncat(s1,s2,7);

    //or
    char* a = "Hello";
    char* b = "World!"; 
    printf("%s %s\n",a,b);

    printf(s1);

    func("asd",1);
    func("asd2",21);
    func("creative pairs",0);
    func("is that enough",999);
    return 0;
}