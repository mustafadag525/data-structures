total_amount
1st month: capital+capital*interest=capital(1+interest)=1stcapital
2st month: 1stcapital+1stcapital*interest
Bu şekilde devam etmektedir.
Cevap 2. Adımdadır.
Adım 2
double calculates(double capital, double interest, int months)
{
if ( months <= 0 ){
return capital;}
return ( calculates( capital*(1+interest), interest, months-1));
}
Kodumuz:
#include <stdio.h>
double calculates(double capital, double interest, int months);
int main()
{
double capital=3000.45;
double interest=0.01,result;
int months=11;
result=calculates(capital,interest,months);
printf("%f",result);
return 0;
}
double calculates(double capital, double interest, int months)
{
if ( months <= 0 ){
return capital;}
return ( calculates( capital*(1+interest), interest, months-1));
}
