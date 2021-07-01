//
// Created by Adarsh Akshat on 01/07/21.
//

#ifndef PHASE1_VIRTUALMACHINE_H
#define PHASE1_VIRTUALMACHINE_H

#include <fstream>
#include <string>

using namespace std;


class VirtualMachine {
private:
    int fetched_IC;
    bool terminate,fetched_C;
    std::string fetched_IR,operand,operatr,fetched_R,compare_string;
public:
    int operandtoline(string operand);
    void fetch();
    void decode();
    void execute();
};

#endif //PHASE1_VIRTUALMACHINE_H
