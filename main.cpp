#define MAX 65534
#include <string>
#include<stdio.h>
#include<time.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
using namespace std;
char cryptotext[MAX];
char plaintext[MAX];
int keystream[MAX];
int main()
{ char text[256],t[256];
    int s[256];
    cout<<"enter plain text:";
    cin.getline(text,255);

    int textlength = strlen(text);
     for(int i = 0; i < 256; i++){
        s[i] = i;
    }

int n,ss,u=0;
char key[256];
cout<<endl;
cout<<"enter key:";
 cin.getline(key,255);
n= strlen(key);

ss=n;

if(ss<256)
{
    for(int i=0;i<256;i++)
    {
       if(u<ss)
       {
         t[i]=key[u];
           u++;
       }
       else{u=0;
       i--;

       }
    }
}
 int temp,j=0;

for(int i = 0; i < 256; i++){
        j = (j + s[i] + t[i]) % 256;

        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

int z=textlength;
int  a=0,b=0,c, tt,index = 0;
     while(z>0){
        a= (a+1)%256;
        b = (b + s[a]) % 256;
        c = s[a];
        s[a] = s[b];
        s[b] = c;
        tt = (s[a] + s[b]) % 256;
        keystream[index] = s[tt];
        index ++;
        z--;
    }

    for(int i = 0; i < textlength; i++){
        cryptotext[i] = char(keystream[i] ^ int(text[i])); // تشفير

    }
    cout<<endl;
   cout<<"keys      XOR     ciphertext"<<endl;

    for(int i = 0; i < textlength; i++){

         cout<<keystream[i]<<"       "<<(keystream[i] ^ int(text[i]))<<"       "<<cryptotext[i]<<endl;

    }
    cout<<endl;
     cout<<"--------------plain text:-------------------------";
    for(int i = 0; i < textlength; i++){
        plaintext[i] = char(keystream[i] ^ cryptotext[i]);   // فك تشفير

    }

    for(int i = 0; i < textlength; i++){
       cout<<plaintext[i];
    }
   // ============ اكتمال فك التشفير ============


    return 0;}

