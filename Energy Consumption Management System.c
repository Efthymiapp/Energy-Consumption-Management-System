#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>

//dhlwsh global metavlhtwn
int  x=0,flag,user,testA;
char  number[3]="123";

struct address//struct dieu8unsh me tis emfwleumenes tis
{
	char streetName[20];
	int streetNumber;
	float meters;
};
struct Client
{
	char name[20];
	char surname[20];
	struct address details;
	char password[20];
	char username[20];
    float cost[12][3];
} CLIENT;
struct Client clients[19];

//dhlwsh sunarthsewn
void signup_user();
void login_user();
void view_user();
void modify_user();
void calculate_cost();
void payment();
void most_expensive();


int main(int argc, char *argv[]) 
{
	int a;
	char answer[2];
	do //do while tis epiloges sto menu tou xrhsth ,oso o xrhsths den exei pathsei 0 gia na to kanei terminate
    {
    	
       system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
        
	   //Munhma pou einai h arxiki o8onh tou systhmatos, opou rwtaei an 8elei na kanei register h log in h exit etsi wtse na ksekinisei to  programma analoga me thn epilogh tou         	
       printf("\t Home Screen \n\n This is the main menu!\n If you want to Register press 'a'\n If you want to Log in press 'b'\n If you want to Exit the program press 'c' \n\n "); 

        do //elegxos gia to ti apanthsh edwse o xrhsths wste na metrhsw thn metavlhth i gia na mpainei sthn switch ws integer kai sumfwna me thn apanthsh tou xrhsth na mpainei sthn antistoixh sunarthsh 
        {
              
			   scanf(" %s", answer );
                  if (strcmp(answer, "a")==0) //elegxoume me strcmp an h apanthsh tou xrhsth isoutai me register tote to i na pairnei thn timh 1
                  {
                        a=1;
                  }
                  else if (strcmp(answer, "b")==0)//elegxoume me strcmp an h apanthsh tou xrhsth isoutai me log in tote to i na pairnei thn timh 2
				  {
                        a=2;
                  }
                  else if (strcmp(answer, "c")==0)//elegxoume me strcmp an h apanthsh tou xrhsth isoutai me exit tote to i na pairnei thn timh 3
				  {
                        a=3;
                  }
                  else //an h apanthsh tou xrhsth isoutai me otidhpote allo pera apo tis 3 do8oumenes epiloges tote to i na pairnei thn timh 4 kai ektupwnetai analogo mhnuma kai ton ksanavazei na apanthsei
                  {
                        a=4;
                        printf("\n Wrong answer please try again!\n\n If you want to log in press 'a'\n If you want to sign up press 'b'\n If you want to terminate the program press 'c' \n\n "); 
                  }
        }while (a==4);//sun8hkh while loop wste otan o xrhsths plhktrologei la8os apanthsh na vlepei to mhnuma pou ton enhmerwnei mexri na epileksei thn swsth
    
    
      
      switch(a)//domh pollaplwn epilogwn switch opou aksiopoiei thn metavlhth i pou upologizame prin kai tmhmatopoiei se cases tis epiloges
      {
            case 1://an h apanthsh tou isoutai me register tote mpainei se auto to case 
            {
              
                system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                signup_user();
                break;
            }
            case 2://an h apanthsh tou isoutai me login tote mpainei se auto to case 
            {
            	system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                login_user();
                break;
			}	
			case 3://an h apanthsh tou isoutai me exit tote mpainei se auto to case 
			{
				printf(" You chose exit !\n");
				break;
		    }    
	  }
		    
	}while(a!=3);	    
		    
	return 0;
}


void signup_user()//sunarthsh wste na kanei sign up o user sto susthma kai tou zhtaei ta aparaithta stoixeia
{
    int z=0 ;
    char testB,testC;
       
    if (x<20)//afou to susthma exei capacity 20 xrhstwn elegxw kata tyn egkrafh ama exei upervh to orio
    {
	
     //aples printf kai scanf gia na parw ta stoixeia tou user
     printf(" You chose sign up! \n Please fill up your information\n ");
     printf("\n What is your name?\n ");
     scanf(" %s",clients[x].name);
     printf("\n What is your surname?\n ");
     scanf(" %s",clients[x].surname);
     printf("\n What is your address?\n ");
     scanf(" %s",clients[x].details.streetName);
     printf("\n What is your address's number?\n ");
     scanf(" %d",&clients[x].details.streetNumber);
     printf("\n What is your home Sq.meters?\n ");
     scanf(" %f",&clients[x].details.meters);
     printf("\n Please choose your password\n ");
     scanf(" %s",clients[x].password);
     
         while (clients[x].surname[z]!='\0') //elegxos gia to an balei kefalaia grammata na ta kanei pezaa to susthma gia to  username
		 {  
            testB=clients[x].surname[z];
            testC=tolower(testB);
            if (testB!=testC)
			{
                clients[x].surname[z]=tolower(clients[x].surname[z]);
            }
            z++;
         }
     clients[x].username[0] = '\0';  
     strcat(clients[x].username,clients[x].surname); // strcat() function enwnei 2 strings kai etsi mporoume na ftiaksoume to epi8umito username
     strcat(clients[x].username,number);
     
     printf("\n You signed up!\n Your username is: %s \n Your password is: %s",clients[x].username,clients[x].password);
     sleep(5);
     system("cls");
     x++;
    }
    else
    {
     	printf(" Sorry you can not register ,we are full!\n ");
	}
 
}

void login_user()
{
	int b,entry;
	char option[2],un[20],pw[20] ;
	system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
    printf(" You chose login! \n\n");//o user epelsekse login opote tou vazoume na plhktrologisei to username tou kai to password tou 
    
       do //while loop opou na sunexizetai h epanalhpsh kai na emfanizetai analogo mhnuma ama exei plhktrologizei la8os username mexri na valei to swsto
         {
         	entry=0;
            printf("\n Enter your username here: \n ");
            scanf(" %s",un);
            printf("\n Enter your password here: \n ");
            scanf(" %s", pw);
            for (b=0; b<20; b++) //for loop kai gia tous 20 xrhstes
             {
		  
                if((strcmp(un,clients[b].username)==0) && (strcmp(pw,clients[b].password)==0))//edw elegxoume me strcmp an to username pou ebale o xrhsths einai to idio me auto pou evale sto sign up ,to un, kai emfanizei analogo mhnuma
                {
                  printf("\n You have entered your Username and Password successfully!\n");
                  user=b;//me thn metavlhth user xarakthrizei to susthma poios xrhsths einai
                }
                else
                {
                  entry++;
                }  
             }
             if(entry==20) //xrhsimopoioume to entry gia na deiksoume oti sthn epanalhpsh for ,egine h prospelash tou pinaka 20 fores kai den vre8hke antistoixo username kai password 
             {
             	printf("\n Username or Password is incorrect.Please try again!\n");
			 }
           }while(entry==20);
        
        system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
        printf(" You logged in!\n");
	     do//do while gia na elgxei an vazei thn swsth apanthsh gia menu
         {
		   
		     do
			 {
			    printf("\n Client Screen\n\n Please type the number of the option that you want ,here is the menu:\n 1.View\n 2.Modify\n 3.Calculate\n 4.Payment\n 5.Most expensive\n 6.logout\n ");
                scanf(" %s",option);
                system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
               	if (strcmp(option, "1")==0)
               	{
               		 system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                     view_user();
				}
				else if(strcmp(option, "2")==0)
				{
				     system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                     modify_user();	
				}
				else if (strcmp(option, "3")==0)
				{
					 system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                     calculate_cost();
                     testA=1;//metavlhth pou me boh8aei na kserw an mphke sto calculate o user
				}
				else if (strcmp(option, "4")==0)
				{
					 system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                     if (testA==1)
                     {
					    payment();
					 }
					 else
					 {
					 	printf("You can't pay yet,you have to calculate your cost first!\n ");
					 }
				}
				else if(strcmp(option, "5")==0)
				{
					 system("cls");//entolh pou ka8arizei ola ta prohgoumena mhnumata wste na exei ka8arh o9onh mono me ta kainouria mhnumata
                     most_expensive();
				}
				else if (strcmp(option, "6")==0)
				{
					 printf("You chose exit!\n ");
				     break;
				}
				else
				{
				 	printf("You typed wrong number! Please try again ");
				}
             }while(strcmp(option, "6")!=0);  //na vlepei to client screen otan vgenei apo ka8e if, osoo den pataei exit
         }while((strcmp(option, "1")!=0) && (strcmp(option, "2")!=0) && (strcmp(option, "3")!=0) && (strcmp(option, "4")!=0) && (strcmp(option, "5")!=0) && (strcmp(option, "6")!=0) );    
   
}

void view_user()
{
	printf(" These are user's information:\n Name: %s \n Surname: %s\n",clients[user].name,clients[user].surname);
    printf(" Address: %s %d\n",clients[user].details.streetName,clients[user].details.streetNumber);
    printf(" Sq.meters: %.0f\n Username: %s\n Password:%s\n ",clients[user].details.meters,clients[user].username,clients[user].password);
}


void modify_user()
{
	printf(" You chose to edit your information! You can only change your address.Please type the new street name,number and sq.meters: \n");
	scanf("%s %d %f",clients[user].details.streetName,&clients[user].details.streetNumber,&clients[user].details.meters);
}

void calculate_cost()
{
	int i;
	float charge,days;
	
	printf(" Please insert the monthly number of kWh you have wasted. Starting with January etc..\n ");
	
	for(i=1; i<=12; i++) //for loop gia ton ka8e ena mhna
	{
	
		printf(" Please type the amount of kWh for the %d month\n ",i);  	
    	do //elegxos gia to an to poso kilovatwrwn pou 8a valei o user 8a einai 8etiko
     	{
    	 scanf("%f", &clients[user].cost[i][1]);
        	if (clients[user].cost[i][1]<0)
         	{
	         	printf("This number can not be accepted. Please try again!\n ");
        	}
        }while(clients[user].cost[i][1]<0);
     
        if ((clients[user].cost[i][1]>=0) && (clients[user].cost[i][1]<=1600)) //elegxos gia na mpei timi sto charge analoga me to pinakaki
        {
        	charge = 0.005;
    	}
     	else if((clients[user].cost[i][1]>=1601) && (clients[user].cost[i][1]<=2000))
    	{
	    	charge = 0.008;
    	}
    	else
    	{
	    	charge = 0.009;
    	}
    
		if ((i==1) || (i==3) || (i==5) || (i==7) || (i==8 )|| (i==10 )|| (i==12))
		{
			days=31;
		}
		else if (i==2)
		{
			days=28;
		}
	    else
	    {
	    	days=30;
		}
		
	  clients[user].cost[i][2] = (float)clients[user].details.meters * (float)charge * (float)clients[user].cost[i][1] * ((float) days/(float)365) ; //upologismos final cost
	  clients[user].cost[i][2] = floorf(clients[user].cost[i][2]*100)/100; // stroggulopoihsh tou final cost
	  clients[user].cost[i][3] = 0;  //flag oti den exei plhrw8ei o mhnas
	  
     }
	
}

void payment()
{
	int month,c,flagmonth=0;
	float costguess;
	printf(" You chose payment! Here are the months with their costs:\n");
	
  for(c=1; c<=12; ++c)
  {
    switch(c)
    {
     	case 1:
	       printf(" January: %.2f\n",clients[user].cost[1][2]);
	       break;
	     case 2:
	       printf(" February: %.2f\n",clients[user].cost[2][2]);
  	       break;
      	case 3:
           printf(" March: %.2f\n",clients[user].cost[3][2]);
	       break;
      	case 4:
	       printf(" April: %.2f\n",clients[user].cost[4][2]);
	       break;
     	case 5:
	       printf(" May: %.2f\n",clients[user].cost[5][2]);
	       break;
     	case 6:
	       printf(" June: %.2f\n",clients[user].cost[6][2]);
	       break;
     	case 7:
	       printf(" July: %.2f\n",clients[user].cost[7][2]);
	       break;
     	case 8:
	       printf(" August: %.2f\n",clients[user].cost[8][2]);
	       break;
     	case 9:
	       printf(" September: %.2f\n",clients[user].cost[9][2]);
	       break;
     	case 10:
	       printf(" October: %.2f\n",clients[user].cost[10][2]);
	       break;
     	case 11:
	       printf(" November: %.2f\n",clients[user].cost[11][2]);
	       break;
      	case 12:
	       printf(" December: %.2f\n",clients[user].cost[12][2]);
	       break;
	 }
    }
	printf(" Please choose the number of which month you want to pay!\n ");
   do
   {
	 scanf("%d", &month);
	 if (clients[user].cost[month][3]==0)
	 {
	 	flagmonth=1; //flag gia elegxo egkurothtas gia thn plhrwmh tou month
	 	printf(" You can pay for this month! Please type the amount of cost\n ");
	 	do
	 	{
		 scanf("%f",&costguess);
		   if(costguess==clients[user].cost[month][2]) //an valei o xrhsths to swsto poso ,h plhrwmh ginetai apodekth
		   {
		   	 printf(" The payment was successfull!\n ");
		   	 clients[user].cost[month][3] = 1; // flag pou deinxei oti plhrw8hke o mhnas
		   }
		   else
		   {
		   	 printf(" The amount is incorrect and the payment failed. Please try again\n ");
		   }
	     }while(costguess != clients[user].cost[month][2]);
	 }
	 else
	 {
	 	printf(" This month has already been paid. Please choose a different one!\n ");
	 	 flagmonth=0;
	 }
  }while(flagmonth==0);
}

void most_expensive()
{
    float expe = 0;
    int expmonth = 0, j;
    char *months[] = {"", "January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};

    for (j = 1; j <= 12; j++)
    {
        if (clients[user].cost[j][3] == 1) // a? ? µ??a? ??e? p?????e?
        {
            if (clients[user].cost[j][2] > expe)
            {
                expe = clients[user].cost[j][2];
                expmonth = j;
            }
        }
    }

    if (expmonth == 0)
    {
        printf("You haven't paid any months yet, so there's no most expensive one!\n");
        return;
    }

    printf("Your most expensive month was **%s** with a total cost of **%.2f €**\n\n", 
            months[expmonth], expe);
}




























