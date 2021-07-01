//
// Created by Adarsh Akshat on 01/07/21.
//

#include "Storage.h"
#include "VirtualMachine.h"
#include "global.h"
void Storage::init(){
    memset(memory,'0',sizeof(char)*100*4);
    IR=R="";
    IC=0;
    C=false;
}
std::string Storage::getRow(int pos){
    std::string temp="";
    for(int i=0;i<4;i++)
        temp+=memory[pos][i];
    return temp;
}
void Storage::setRow(std::string str,int pos){
    for(int i=0;i<4;i++)
        memory[pos][i]=str[i];
}
void Storage::load(){
    int flag=0;
    char ch;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            /* code */
            inputfile>>ch;
            memory[i][j]=ch;
            if(memory[i][0]=='H'){
                flag=1;
                break;
            }

        }
        if(flag)
            break;
    }
}

void Storage::setIC() {
    IC=0;
}

void Storage::setIC(int pos) {
    IC=pos;
}

int Storage::getIC() {
    return (IC++);
}
//J = IC
void Storage::setIR(int j) {
    IR="";
    for (int i = 0; i < 4;i++) {
        IR+=memory[IC][i];
    }
}
string Storage::getIR(){
    return IR;
}

void Storage::setR(int pos) {
    R="";
    for (int i = 0; i < 4; i++) {
        R+=memory[pos][i];
    }
}
string Storage::getR() {
    return R;
}
void Storage::setC(bool value) {
    C=value;
}

bool Storage::getC() {
    return C;
}