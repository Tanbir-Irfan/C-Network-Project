#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "ClassC.h"
#include "ClassB.h"
#include "ClassA.h"

int main(void)
{
    
    ip.flag=0;
    system("cls");
    system("color 09");
    printf("\n\n\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2  IP Subnet Mask Calculator  \xB2\xB2\xB2\xB2\xB2");
    Sleep(3500);
    system("cls");
    system("color 0B");
    printf("\n\n\t\t\t\t\t\t\tPlease give me an ip address=");
    scanf("%i.%i.%i.%i",&ip.ip1,&ip.ip2,&ip.ip3,&ip.ip4);
    printf("\t\t\t\t\t\t\tAlso give me a CIDR value=");
    scanf("%i",&ip.cidr);
    ip.store=ip.cidr;
    if(ip.cidr>30 || ip.cidr<8)
        printf("\t\t\t\t\t\t\tInvalid CIDR value you have given and CIDR value range is from 8 to 30\n");
    else
    {
        while(ip.cidr!=0)
        {
            if(ip.cidr>=8)
            {
                ip.flag++;
                ip.cidr-=8;
            }
            else
                break;
        }
    }
    if(ip.flag==1)
        printf("\t\t\t\t\t\t\t%i.%i.%i.%i is the subnet mask of that ip address\n",255,subnet_calculate_C(ip.cidr),0,0);
    else if(ip.flag==2)
        printf("\t\t\t\t\t\t\t%i.%i.%i.%i is the subnet mask of that ip address\n",255,255,subnet_calculate_C(ip.cidr),0);
    else if(ip.flag==3)
        printf("\t\t\t\t\t\t\t%i.%i.%i.%i is the subnet mask of that ip address\n",255,255,255,subnet_calculate_C(ip.cidr));

    if(ip.ip1>=0 && ip.ip1<=127)
    {
        if(ip.ip1==0)
        {
            printf("\n\t\t\t\t\t\t\tFirst byte can't be 0 though this address is included in class 'A'"
            "\n\t\t\t\t\t\t\tbecause it is reserved to designate the default route\n\n");
        }
            
        else if(ip.ip1==127)
            printf("\t\t\t\t\t\t\tFirst byte can't be 127 because it is reserved for diagnostic\n");
        else
        {
            class_A(ip.ip1,ip.ip2,ip.ip3,ip.ip4,ip.cidr,ip.flag);
        }
        
    }
    else if(ip.ip1>=128 && ip.ip1<=191)
    {
        if(ip.store<16)
            printf("\n\n\t\t\t\t\t\t\tMask bit cann't be less than 16 for the ip address of class B\n");
        else
            class_B(ip.ip1,ip.ip2,ip.ip3,ip.ip4,ip.cidr,ip.flag);
        
    }
    else if(ip.ip1>=192 && ip.ip1<=223)
    {
        if(ip.store<24)
            printf("\n\n\t\t\t\t\t\t\tMask bit cann't be less than 24 for the ip address od class C\n");
        else
            class_C(ip.ip1,ip.ip2,ip.ip3,ip.ip4,ip.cidr);
    }
    else
    {
        printf("\t\t\t\t\t\t\tThis ip address is wrong please try again");
    }
    
    return 0;
}
