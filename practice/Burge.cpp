 #include<bits/stdc++.h>
 using namespace std;
 //ע����ʵļ��㷽ʽ����ֱ������Ϊ�����жϺ�ʱʣ�µĺ���������ͬ������ʣ�೬������ʱֻʣһ�ֺ�����
 int main(){
     int line,number;
     double p[50000]={0};
     p[1]=1;
     for(int i=1;i<50000;i++){
        p[i+1]=p[i]*(2*i-1)/(2*i);
     }
     cin>>line;
     for(int i=0;i<line;i++){
         cin>>number;
        //  if(i)
        //     printf("\n");
         printf("%.4lf\n",1-p[number/2]);
     }
 }