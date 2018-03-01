#include<stdio.h>
//#include<conio.h>
#include <curses.h>
#include <ncurses.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>



//declaring gotoxy() function

void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}

int main()
{

     clock_t start,end,total;
     char str[1000],ch,reset;
     char arr[1000]="Type this text to proceed. This is a typing test. Let's see how much you score. All the best!";
     FILE *file;

     int size,i,j,len=strlen(arr);
     long double high,score;
     start=clock();

     file=fopen("score.txt","a");
     fseek(file,0,SEEK_END);
     size=ftell(file);
     if(size==0)
     {
	      fprintf(file,"%s","0.00");
     }
     fclose(file);

     system("clear");
     i=0;
     while(i<len)
     {
	       system("clear");
	       gotoxy(27,4);
	       printf("WELCOME TO TYPING TUTOR!");
	       printf("\n\n\nText: ");
	       for(j=i;j<len;j++)
	       {
		         printf("%c", arr[j]);
	       }
	       if(getch()==arr[i])
		       i++;
	       else
		       continue;
     }
     end=clock();
     score=(long double)len/((long double)(end-start)/(long double)CLOCKS_PER_SEC);
     system("clear");
     file=fopen("score.txt","r");

     fscanf(file,"%Lf",&high);
     printf("\n\n\n\t\t\t\tTYPING TUTOR");
     printf("\n\n\t\tScore: %Lf taps/second",score);
     printf("\n\n\t\tPrevious High Score: %Lf taps/second",high);
     if(score>high)
     {
	      high=score;
	       printf("\n\n\t\tNew Record!");
     }
     fclose(file);
     printf("\n\n\t\tReset Score? (y/n)  ");
     scanf("%c",&reset);

     if(reset=='y')
	      high=0.00;
     file=fopen("score.txt","w");
     fprintf(file,"%Lf",high);
     fclose(file);

     return 0;
}
