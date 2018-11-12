#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int lps[1000];
void buildfunction(string subs)
{
    int n= subs.size();
    int i=1;
    int len=0;
    lps[0]=0;
    while(i<n)
    {
        if(subs[i]==subs[len])
        {
            len++;
            lps[i]=len;
            i++;

        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }

    }
}
int  KMP(string text, string pattrn )
{
    buildfunction(pattrn);
    int S_text=text.size();
    int S_pattrn=pattrn.size();
    /*for(int i=0;i<S_pattrn;i++)
    {
    cout<<lps[i]<<endl;
    }*/
    int i=0;
    int j=0;
    while(i<S_text)
    {
        if(pattrn[j]==text[i])
        {
            j++,i++;
        }
        if (j==S_pattrn){
            return(i-j);

            }
        else if(i<S_text&&pattrn[j]!=text[i])
        {
        //cout<<"Test"<<endl;
            if(j!=0){
                j=lps[j-1];
               // cout<<j<<" Value"<<endl;
               }

            else{
                i=i+1;}

        }
    }
    return -1;

}
int main()
{
int t;
   scanf("%d",&t);
   while(t--)
   {
   char text[1000000];
   scanf("%s",text);
   int n;
   scanf("%d",&n);
   while(n--)
   {
   char patt[1000];
   scanf("%s",patt);
   if(KMP(text,patt)==-1)
   printf("n\n");
   else
   printf("y\n");
   }
   }
    return 0;
}
