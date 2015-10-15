#include <iostream>
#include <conio.h>
#include <sstream>

std::string toString(int i)
{
    if(i<10)
    {
        std::stringstream ss ; 
        ss<<i;
        std::string deci;
        ss>>deci;        
        return deci;
    }
    else
    {
        switch(i)
        {
            case 10:
                return "A";
            case 11:
                return "B";
            case 12:
                return "C";
            case 13:
                return "D";
            case 14:
                return "E";
            case 15:
                return "F";
            default:
                return " ";
        }
    }
}

std::string convertToBase(int deci,int base)
{
    if (deci<base)
        return toString(deci);
    return convertToBase(deci/base,base).append(toString(deci%base));
}

int abnormalExit(std::string Name)
{
    std::cout<<"Please provide right parameters"<<std::endl;
    std::cout<<"Usage:"<<std::endl;
    std::cout<<"   "<<Name<<" <+ve number in decimal> <base from 2 to 16>";
    getchar();
    return -1;
}

int main(int argc, char **argv)
{
    if (argc!=3)
        return abnormalExit(argv[0]);
    std::stringstream ss;
    ss<<argv[1]<<" "<<argv[2];
    int deci,base;
    ss>>deci>>base;
    if (base<2 || base>16 || deci<=0)
        return abnormalExit(argv[0]);
    std::cout<<"Decimal number is "<<deci<<std::endl;
    std::cout<<"To Be converted to base "<<base<<std::endl;
    std::cout<<convertToBase(deci,base);
    getchar();
    return 0;
}