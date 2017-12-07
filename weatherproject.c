/*		                                    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		                                    *      COMPUTER SCIENCE PROJECT WORK        *
		                                    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

	                                           *** SOFTWARE FOR THE WEATHER REPORT ***
*/
/*
           /// INTRODUCTION ///
   -------------------------------------
   -  NAME     :- MOHD NAYAB ANWAR     -
   -  SECTION  :- K17EG                -
   -  ROLL NO. :- K17EGB-36            -
   -------------------------------------
*/
// HEADER FILES //
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<process.h>

struct city//to  store the details of the cities
{
	char city[100],wth[100];
	int temp;
	float hum;
	float wind;
	float press;
	float vis;
	
}c;
char query[20],city[20];

int i,n,key,l,found;

FILE *fp;
main()
{
	                       // **********************  Main Menu   *******************
	main:system("cls");
	
	system("COLOR 3");
	
	printf("\n\t\t\t\t\t\t**** WELCOME TO Mini~Weather  ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\n\t\t=========================\n\n\t\t[1]  Add database\n\t\t[2]  Your database\n\t\t[3]  Search Your city\n\t\t[0]  Exit\n\n\t\t=========================\n\t\t");

    printf("\n\t\tEnter Your Choice :: ");

    scanf("%d",&key);
    
    switch(key)

    {

    case 0:
    	
    	system("cls");
    	
        system("COLOR B0");
        
        printf("\n\n\t\t     #######  THANKS   ######");
        
        printf("\n\n\t\t================================\n");

        printf("\n\n\n\t\tAre you sure you want to exit ? ");

        break;

        /* *********************   Add database   ************  */

    case 1:
    	
    	system("cls");
    	
    	system("COLOR 7");
    	
    	 printf("\n\t\t================================\n\t\t\tAdd Database\n\t\t================================\n\n\n");

        fp=fopen("weather.txt","a");

        while (key!=0)

        {
            fflush(stdin);

            printf("\n\t\tName of city (Use small fonts) :: ");

            gets(c.city);

            fflush(stdin);

            printf("\t\tTemperature\t: "); //input in centrigrate

            scanf("%d",&c.temp);

            fflush(stdin);

            printf("\t\tWeather\t\t: ");//either winter,summer,rainy or any other in string only

            gets(c.wth);

            fflush(stdin);
            
            printf("\t\tHumidity\t: ");
            
            scanf("%f",&c.hum);
            
            fflush(stdin);
            
            printf("\t\tWind speed\t: ");
            
            scanf("%f",&c.wind);
            
            fflush(stdin);
            
            printf("\t\tVisibilty\t: ");
            
            scanf("%f",&c.vis);
            
			fflush(stdin);
			
           
            printf("\n\n\t\t================================");
			
			fflush(stdin);
            
            printf("\n\n\t\tDo you wish to add more contacts\n\n\t\t[1] Yes\t\t[0] No\n\n\t\t");
			
			scanf("%d",&key);
			
			if(key==1)
			{
				continue;
			}
			else
			
			goto main;

            printf("\n");

            fwrite(&c,sizeof(c),1,fp);

        }

        fclose(fp);

        break;

        /* *********************   Your Database   *************************  */

    case 2:
    	
    	system("cls");
    	
    	system("COLOR 5");

        printf("\n\t\t================================\n\t\t\tYour Database\n\t\t================================\n\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("weather.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&c,sizeof(c),1,fp)==1)

            {

                if(c.city[0]==i || c.city[0]==i-32)

                {

                    printf("\n\n\t\tName of city\t:: %s\n\t\tTemperature\t:: %d C\n\t\tWeather\t\t:: %s\n\t\tHumidity\t:: %.2f %%\n\t\tWind Speed\t:: %.2f Km/h\n\t\tVisibility\t:: %.2f Km",c.city,
                           c.temp,c.wth,c.hum,c.wind,c.vis);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("\n\n\t\t================================\n\n",found);

                getch();
            }

            fclose(fp);

        }

        break;

        /* ******************* Search Your City **********************  */

    case 3:
    	
    	system("cls");
    	
    	system("COLOR 2");
     
        again:
        
        do

        {

            found=0;

            printf("\n\n\t\t===============================\n\t\t    ##  Database Search  ##\n\t\t===============================\n\n\n\t\tName of city :: ");

            fflush(stdin);

            scanf("%s",&query);

            l=strlen(query);

            fp=fopen("weather.txt","r");

            printf("\n\n\t\tSearch result for '%s' \n\n\t\t===============================\n",query);

            while(fread(&c,sizeof(c),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    city[i]=c.city[i];

                city[l]='\0';

                if(stricmp(city,query)==0)

                {

                     printf("\n\t\tName of city\t:: %s\n\t\tTemperature\t:: %d C\n\t\tWeather\t\t:: %s\n\t\tHumidity\t:: %0.2f %%\n\t\tWind Speed\t:: %0.2 Km/h\n\t\tVisibility\t:: %0.2 Km",c.city,
                           c.temp,c.wth,c.hum,c.wind,c.vis);

                    found++;

                    if (found==1)

                    {
                        printf("\n\n\t\t===============================");
                        
                        printf("\n\n\t\tDo you want to search again ?\n\n\t\t[1] Yes\t\t\t[0] No\n\n\t\t");
                        
                        scanf("%d",&key);
                        
                        if(key==1)
                        {
                        	goto again;
						}
						
						else
						
				        goto main;

                        getch();

                    }

                }
            
            }
            
            if(found==0)
                
                 printf("\n\n\t\tSORRY ! No match found \a\n\n\t\tTry again ?\n\n\t\t[1] Yes\t\t\t[0] No\n\n\t\t");

                 scanf("%d",&key);

            fclose(fp);

           

        }
        while(key==1);

        break;

        /* *********************************************/
        
    default:

        printf("\n\n\t\tInvalid Choice !\a");

        break;

    }

    printf("\n\n\n\t\tEnter the Choice :\n\n\t\t[1] Main Menu\t\t\t[0] Exit\n\n\t\t");

    scanf("%d",&key);

    switch (key)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("\n\n\t\tInvalid Choice !\a");

        break;

    }

    return 0;

	                       
	getch();
	
	/*  ****************************    THANKS    **************************************  */
}


