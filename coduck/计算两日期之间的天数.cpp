#include<iostream>
 using namespace std;
 int main(){
        int sy,sm,sd,ey,em,ed,C=0;
        int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        cin>>sy>>sm>>sd;
        cin>>ey>>em>>ed;
        if(ey-sy==0)
        {
                if((sy%4==0&&sy%100!=0)||(sy%400==0))
                        m[2]=29;
                for(int i=sm;i<em;i++)
                {
                        if(i==sm)
                                C=m[i]-sd;
                        else
                        	C+=m[i];
                }
                C+=ed;
                if(sm==em)C=ed-sd;
                cout<<C<<endl;

        }
        else{
                for(int i=sy;i<ey;i++)
                {
                        if(i%4==0&&i%100!=0||i%400==0)C+=366;
                        else C+=365;
                }
                if(sy%4==0&&sy%100!=0||sy%400==0) m[2]=29;
                for(int i=1;i<sm;i++) C-=m[i];
                C-=sd;
                if(ey%4==0&&ey%100!=0||ey%400==0) m[2]=29;
                else m[2]=28;
                for(int i=1;i<em;i++)C+=m[i];
                C+=ed;
                cout<<C<<endl;
        }
        return 0;
    }

