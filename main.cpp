#include <iostream>
#include<iostream>
#include<string.h>
#include<fstream>
#include<string>
#include "Storage.h"
#include "VirtualMachine.h"
#include "global.h"


void run(char *filename){
    inputfile.open(filename);
    outputfile.open("output.txt");
    std::string s,s1;
    while(!(inputfile.eof()))
    {
        getline(inputfile,s);
        if(s.find("$AMJ")!=-1)
        {
            memory.init();
            memory.load();
            continue;
        }
        else if(s.find("$DTA")!=-1)
            cpu.fetch();
        else if(s.find("$END")!=-1)
            continue;
    }
    inputfile.close();
    outputfile.close();
}
int main(int argc,char *argv[]) {
    if (argc < 2) {
        std::cout  << argv[0] << " Requires an Input file Name in argument\n";
        return 0;
    }
    run(argv[1]);
    return 0;
}