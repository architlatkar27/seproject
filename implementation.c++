#include<stdio.h>
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include "rabin_carp.h"

using namespace std;

int main(int argc,char** argv){
    if(argc<3){
        cout<<"usage of this program:\n";
        cout<<"./search filepath string_to_be_searched\n";
        cout<<"please use the above format\n";
        exit(0);
    }
    ifstream target_file(argv[1]);
    string line;
    int line_number=0;
    while(std::getline(target_file,line)){
        rabin_carp_search(argv[2],line,line_number++);
    }
}