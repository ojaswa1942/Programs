/*
A C-program which takes year and month as input and outputs calendar format of corresponding month and year.
Determination of day_of_week is generalized from the competitive determination method, a representation of 
which can be seen in this link: https://www.youtube.com/watch?v=_xnC70CY6ro

Modifications can be made, for instance, a menu or action keys to change month of calendar.
*/
#include<stdio.h>
int leap(int year)
{
	if(year%100==0) {if(year%400==0) return 1; else return 0;}
	if(year%4==0) return 1;
	else return 0;
}
int day_of_week(int year,int month)
{
	int sum=1,ymod=year%4,ans;
	sum=sum+((year%100)%7)+(((year%100)/4)%7);
	switch (ymod)
	{
		case 0: sum+=6; break;
		case 1: sum+=4; break;
		case 2: sum+=2; break;
		case 3: sum+=0; break;
	}
	switch (month)
	{
		case 1: sum+=1; break;
		case 2: sum+=4; break;
		case 3: sum+=4; break;
		case 4: sum+=0; break;
		case 5: sum+=2; break;
		case 6: sum+=5; break;
		case 7: sum+=0; break;
		case 8: sum+=3; break;
		case 9: sum+=6; break;
		case 10: sum+=1; break;
		case 11: sum+=4; break;
		case 12: sum+=6; break;
	}
	ans=sum%7;
	if(ans==0) ans=6; else ans--;
	return ans;
}

void main()
{
	system("clear");
	int year,month,i,j;
	printf("Enter year(YYYY): "); scanf("%d",&year);
	printf("Enter month(MM): "); scanf("%d",&month);
	int month_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(leap(year)) month_day[1]=29;
	char *month_name[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	char week_name[]={'S','M','T','W','T','F','S'};
	if(month>0 && month<13)
	{
		printf("\t\t\t  %s, %d\n\n\t",month_name[month-1],year);
		for(i=0;i<7;i++) 
			printf("%c\t",week_name[i]); 
		printf("\n\n");
		j=day_of_week(year,month);
		for(i=0;i<j;i++) printf("\t ");
			for(i=1;i<=month_day[month-1];i++)
				{printf("\t%d",i);
				j++;
				if(j==7){
					j=0; 
					printf("\n");}
				}
		printf("\n\n");
	}
	else 
		printf("\t\t\tInvalid Input\n\n");
}
