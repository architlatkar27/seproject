#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>

#define d 256

using namespace std;

void rabin_carp_search(char pat[],string str,int line_number){
    int q=101;
	int M=strlen(pat);
	int N=str.length();
	int i,j;
	int p=0,t=0,h=1;
    bool match_found=false;
	for(i=0;i<M-1;i++) h=(h*d)%q;
	//calculate hash value of pattern and first window 
	for(i=0;i<M;i++){
		p=(d*p+pat[i])%q;
		t=(d*t+str[i])%q;
	}
	//slide the window over text and check for matches
	for(i=0;i<=N-M;i++){
		//printf("hash of pat %d\thash of str %d\n",p,t);
		if(p==t){//if hash matches confirm by checking all characters
            for(j=0;j<M;j++){
                if(str[i+j]!=pat[j]) break;
            }
            if(j==M){ 
                match_found=true;
                cout<<"pattern found at line "<<line_number<<endl;
                return;
            }
		}
		//calculate hash value for next window by removing leading digit and adding next digit
		if(i<N-M){
			t=(d*(t-str[i]*h)+str[i+M])%q;
			if(t<0) t+=q; //if t is negative add q to make positive
		}
		
	}
	//no match found 
    if(match_found==false) cout<<"no match found in line number"<<line_number<<"\n";
	
}