//
// Created by Adarsh Akshat on 01/07/21.
//

#include "VirtualMachine.h"
#include "Storage.h"
#include "global.h"
int VirtualMachine::operandtoline(string operand) {
    int line;
    line = ((int)operand[0]-48)*10+((int)operand[1]-48);
    return line;
}
void VirtualMachine::fetch() {
    memory.setIC();
}
void VirtualMachine::decode() {
    terminate=false;
    while(!terminate)
    {
        fetched_IC = memory.getIC();
        memory.setIR(fetched_IC);
        fetched_IR=memory.getIR();
        operatr=fetched_IR.substr(0,2);
        operand=fetched_IR.substr(2,2);
        if(!(operatr.compare("LR")))
        {
            int pos=operandtoline(operand);
            memory.setR(pos);
        }
        else if (!(operatr.compare("SR")))
        {
            fetched_R=memory.getR();
            int pos=operandtoline(operand);
            memory.setRow(fetched_R, pos);
        }
        else if (!(operatr.compare("CR")))
        {
            fetched_R=memory.getR();
            int pos=operandtoline(operand);
            compare_string=memory.getRow(pos);
            if(fetched_R.compare(compare_string)==0)
                memory.setC(true);
            else
                memory.setC(false);
        }
        else if (!(operatr.compare("BT")))
        {
            fetched_C=memory.getC();
            if(fetched_C)
            {
                int pos=operandtoline(operand);
                memory.setIC(pos);
            }
        }
        else if (!(operatr.compare("GD")))
        {
            SI=1;
            execute();
        }
        else if (!(operatr.compare("PD")))
        {
            SI=2;
            execute();
        }
        else
        {
            SI=3;
            execute();
        }
    }
}

void VirtualMachine::execute() {
    if(SI==1)
    {
        string s;
        int pos=operandtoline(operand);
        pos=(pos/10)*10;
        getline(inputfile,s);
        if(!s.empty() && s[s.size()-1]=='\r')
            s.erase(s.size()-1);
        int len=s.length(),start=0,i;
        string s1;
        for(i=pos;start<len;i++)
        {
            if((len-start)<4)
                s1=s.substr(start,(len-start));
            else
                s1=s.substr(start,4);
            start+=4;
            memory.setRow(s1,i);
        }
    }
    else if(SI==2)
    {
        int pos=operandtoline(operand),flag=0;
        pos=(pos/10)*10;
        string ans="",temp="";
        for(int i=pos;i<pos+10;i++)
        {
            temp=memory.getRow(i);
            for(int j=0;j<4;j++)
            {
                if(temp[j]=='\0' || temp[j]=='0')
                {
                    break;
                    flag=1;
                }
                ans+=temp[j];
            }
            if(flag)
                break;
        }
        outputfile<<ans<<endl;
    }
    else
    {
        terminate=true;
        outputfile<<endl<<endl;
    }

}