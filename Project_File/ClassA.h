#include <stdio.h>
#include <math.h>
#include <windows.h>

struct subnet3
{
    int cidr,flag,store;
    int block_size;
    int block[260];
}classA;

int subnet_calculate_A(int num)
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

void class_A(int ip1,int ip2,int ip3,int ip4,int cidr,int flag)
{
    if(cidr==0)
        classA.block_size=256-255;
    else 
        classA.block_size=256-subnet_calculate_A(cidr);
    printf("\n\n\t\t\t\t\t\t\tSubnet Address  |  Broadcast Address\n\n");
    classA.store=0;
    classA.flag=0;
    if(classA.block_size==1)
    {
        if(flag==1)
        {
            for(int i=ip1;i<=255;i++)
                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",i,0,0,0,i,255,255,255);
        }
        else if(flag==2)
        {
            for(int i=ip2;i<=255;i++)
            {
                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,i,0,0,ip1,i,255,255);
                classA.flag++;
            }
            classA.flag=256-classA.flag;
            if(classA.flag!=0)
            {
                for(int i=0,j=ip1+1;i<classA.flag;i++)
                {
                    printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",j,i,0,0,j,i,255,255);
                }
            }
        }
        else
        {
            for(int i=ip3;i<=255;i++)
            {
                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,i,0,ip1,ip2,i,255);
                classA.flag++;
            }
            classA.flag=256-classA.flag;
            if(classA.flag!=0)
            {
                for(int i=0,j=ip2+1;i<classA.flag;i++)
                {
                    printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,j,i,0,ip1,j,i,255);
                }
            }
        }
        
    }
    else
    {
        if(flag==1)
        {
            if(ip2%classA.block_size!=0)
            {
                for(int i=ip2; i%classA.block_size!=0;)
                {
                    i--;
                    ip2=i;
                }
            }
            for(int i=0; i<pow(2,cidr); i++)
            {
                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,0,0,ip1,(ip2+classA.block_size)-1,255,255);
                ip2=ip2+classA.block_size;
                if(ip2==256)
                {
                    i=(pow(2,cidr)-1)-i;
                    if(i!=0)
                    {
                        ip2=0;
                        ip1+=1;
                        for(int j=0; j<i; j++)
                        {
                            printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,0,0,ip1,(ip2+classA.block_size)-1,255,255);
                            ip2=ip2+classA.block_size;
                        }
                        break;
                    }
                    else
                        break;
                }
            }
        }
        else if(flag==2)
        {
            if(ip3%classA.block_size!=0)
            {
                for(int i=ip3; i%classA.block_size!=0;)
                {
                    i--;
                    ip3=i;
                }
            }
            for(int count=0; count<256; )
            {
                for(int j=0; j<(pow(2,cidr)); j++)
                {
                    printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,ip3,0,ip1,ip2,(ip3+classA.block_size)-1,255);
                    count++;
                    ip3+=classA.block_size;
                    if(ip3==256)
                    {
                        j=(pow(2,cidr)-1)-j;
                        if(j!=0)
                        {
                            ip2++;
                            ip3=0;
                            for(int k=0; k<j; k++)
                            {
                                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,ip3,0,ip1,ip2,(ip3+classA.block_size)-1,255);
                                count++;
                                ip3=ip3+classA.block_size;
                            }
                            classA.flag++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if(classA.flag!=0)
                {
                    classA.flag=0;
                    continue;
                }
                else
                {
                    ip2++;
                    ip3=0;
                }
            }
        }
        else
        {
            if(ip4%classA.block_size!=0)
            {
                for(int i=ip4; i%classA.block_size!=0;)
                {
                    i--;
                    ip4=i;
                }
            }
            for(int count=0; count<256; )
            {
                for(int j=0; j<(pow(2,cidr)); j++)
                {
                    printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,ip3,ip4,ip1,ip2,ip3,(ip4+classA.block_size)-1);
                    count++;
                    ip4+=classA.block_size;
                    if(ip4==256)
                    {
                        j=(pow(2,cidr)-1)-j;
                        if(j!=0)
                        {
                            ip3++;
                            ip4=0;
                            for(int k=0; k<j; k++)
                            {
                                printf("\t\t\t\t\t\t\t%i.%i.%i.%i  | %i.%i.%i.%i\n",ip1,ip2,ip3,ip4,ip1,ip2,ip3,(ip4+classA.block_size)-1);
                                count++;
                                ip4=ip4+classA.block_size;
                            }
                            classA.flag++;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if(classA.flag!=0)
                {
                    classA.flag=0;
                    continue;
                }
                else
                {
                    ip3++;
                    ip4=0;
                }
            }
        }
        
    }
}