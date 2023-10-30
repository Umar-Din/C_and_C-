/*
string operations in cpp
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

//function to get the length of the string
int length(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

//upper case to lower case returning new string
char* lower(char str[]){
    int i=0;
    while(str[i] != '\0'){i++;}
    char* string = (char *)malloc((i+1)*sizeof(char));
    int j=0;
    while (str[j] != '\0')
    {
        if(str[j] >= 65 && str[j] <= 90){
            string[j] = str[j]+32;
        }else if(str[j]>=97 && str[j]<=122){
            string[j] = str[j];
        }else{
            string[j] = str[j];
        }
        j++;
    }
    string[j] = '\0';
    return string;
    
}

void show(char *str){
    int i=0;
    while(str[i] != '\0'){
        cout<<str[i++];
    }
}


int main(){
    char stringone[] = "Hello World Welocme To World Of String";
    cout<<stringone<<endl;
    cout<<length(stringone)<<endl;
    char* stringtwo = lower(stringone);
    // show(stringtwo);
    cout<<stringtwo<<endl; 

    return 0;
}