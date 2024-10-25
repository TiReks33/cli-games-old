#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "redspies_header.h"
////////////////////////////////////////////

///////////////////////////////////////////
int main(void){
	//start (1)

        //char ins[2]={"!"}; //symb for game "initialization"
	      char ins='!';
FILE *pf;
char buffer[256];
pf=fopen("/usr/share/red-spies/logo","r");
    if(pf)
    {
        // пока не дойдем до конца, считываем по 256 байт
    	// scan 256 byte from buffer until EOF
        while((fgets(buffer, 256, pf))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(pf);
    }

printf(" '1' - start, 'i' - show game rules, 'q' - quit\n");
//char a = '!';

//"main menu"
do{
//"main menu"
//
	/*
   if(fgets(ins,3,stdin)){ //scanning symbol && clear buffer
        char *p;
        if (p=strchr(ins,'\n')){
            *p = 0;
        } else {
            scanf("%*[&^\n]"); scanf("%*c");
        }
    }
*/
	scanf(" %c",&ins);
	while (getchar()!='\n');
        //switch(ins[0]){
	switch(ins){
                case '1': printf("Let's begin\n");break;
                case 'q': printf("Bye!\n"); return 0;
	        case 'i': printf("Show game rules\n");show_rules();printf("\n1 - Start, i - Show game rules again, q - quit\n");break;
                default: printf("Try again! Press 1 to start game, i - to show rules, q - to quit\n");break;
        }
//"main menu"
  //}while(ins[0]!='1');
}while(ins!='1');
//"main menu"

//end(1)

//STARt (2)

//chose side (reds/blues)
int s=1;//1 - reds (by default), 0 - blues
int*p_s=&s;


int red_score=0, blue_score=0; // 1st condition of victory counters
int *p_red=&red_score;
int*p_blue=&blue_score;

//check 2nd condition of victory(half reds or half blues killed)_

int reds_killed=0,blues_killed=0;
int *p_rkill=&reds_killed;
int *p_bkill=&blues_killed;


char ches[9][9][3]; // game board matrix
char(*p_ches)[9][3];
p_ches=ches; // pointer for board actions funcs

init_show(p_ches);


////////////////////////////CONDITION_OF_VICTORY
do{
///////////////////////////CONDITION_OF_VICTORY

if(s==0)printf("Move for Blue team\n");else if(s==1) printf("Move for Red team\n");

play_show(p_ches);

//end(2)

//START(3) 
//
 printf(" Press [m]ove | [a]ttack | [e]xit\n"); 
  do{
	  /*
 	if(fgets(ins,3,stdin)){
        char *p;
        if (p=strchr(ins,'\n')){
            *p = 0;
        } else {
            scanf("%*[&^\n]"); scanf("%*c");
        }
    }*/
	  scanf(" %c",&ins);
	  while (getchar()!='\n');
	//switch(ins[0]){
	  switch(ins){
                case 'm': //printf(" [[choose figure to move]]\n coordinates in format \"3 3\"\n");
			  move(p_ches,p_s,p_red,p_blue);
			  break;
		case 'a': //printf(" [[choose your FIGHTER]]\n coordinates in format \"3 3\"\n");

			  attack(p_ches,p_s,p_red,p_blue,p_rkill,p_bkill);
			  break;
		case 'e': printf("Bye!\n"); return 0;
                default: printf("Try again! 1 or 0\n");break;
	}

//}while(ins[0]!='m'&&ins[0]!='a');
  }while(ins!='m'&&ins!='a');



//////////////////////////////////////////CONDITION_OF_VICTORY
}while(blue_score!=4&&red_score!=4);
/////////////////////////////////////////CONDITION_OF_VICTORY



return 0;
}


