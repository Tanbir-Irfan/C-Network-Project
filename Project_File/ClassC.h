#include <stdio.h>
#include <math.h>
#include <windows.h>

struct subnet1
{
    int ip1,ip2,ip3,ip4;
    int cidr,flag,store;
    int block_size;
}ip,classC;

int subnet_calculate_C(int num)
{
    if(num==0)
        return 0;
    else if(num==1)
        return 128;
    else if(num==2)
        return 192;
    else if(num==3)
        return 224;
    else if(num==4)
        return 240;
    else if(num==5)
        return 248;
    else if(num==6)
        return 252;
    else if(num==7)
        return 254;
}

void class_C(int ip1,int ip2,int ip3,int ip4,int cidr)
{
    if(cidr==0)
        classC.block_size=256-255;
    else 
        classC.block_size=256-subnet_calculate_C(cidr);
    printf("\n\n\t\t\t\t\t\t\tSubnet Address  |  Broadcast Address\n\n");
    classC.store=0;
    classC.flag=0;
    if(classC.block_size==1)
    {
        for(int i=ip3;i<=255;i++)
        {
            printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,i,0,ip1,ip2,i,255);
            classC.flag++;
        }
        classC.flag=256-classC.flag;
        if(classC.flag!=0)
        {
            for(int i=0,j=ip2+1;i<classC.flag;i++)
            {
                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,j,i,0,ip1,j,i,255);
            }
        }
    }
    else
    {
        if(ip4%classC.block_size!=0)
        {
            for(int i=ip4; i%classC.block_size!=0;)
            {
                i--;
                ip4=i;
            }
        }
        for(int i=0; i<pow(2,cidr); i++)
        {
            printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,ip3,ip4,ip1,ip2,ip3,(ip4+classC.block_size)-1);
            ip4=ip4+classC.block_size;
            if(ip4==256)
            {
                i=(pow(2,cidr)-1)-i;
                if(i!=0)
                {
                    ip4=0;
                    ip3+=1;
                    for(int j=0; j<i; j++)
                    {
                        printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,ip3,ip4,ip1,ip2,ip3,(ip4+classC.block_size)-1);
                        ip4=ip4+classC.block_size;
                    }
                    break;
                }
                else
                    break;
            }
        }
    }  
}