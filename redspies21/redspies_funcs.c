#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "redspies_header.h"

//definition of funcs

const int limit = 123;

short int s1_jump=0,s1_mock=0, //spies "super" jump && "play dead" limits
		s2_jump=0,s2_mock=0,
		e1_jump=0,e1_mock=0,
		e2_jump=0,e2_mock=0,
		spy_limit=1;




void show_rules(void){ //rules of game .txt

FILE *mf;
char buffer[256];
mf=fopen("/usr/share/red-spies/instr.txt","r");
    if(mf)
    {
        // пока не дойдем до конца, считываем по 256 байт
        while((fgets(buffer, 256, mf))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(mf);
    }

}








/////////////////////////////////////////////////////////////////////
void init_show(char (*p_num)[9][3]){
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
		strcpy(p_num[i][j],"_ ");
	}
}
int k=0;

//Initialization of board

do{
       strcpy(p_num[1][k],"R ");
       strcpy(p_num[6][k],"B ");
       k++;
}while(k!=8);
//spies:
strcpy(p_num[1][2],"S1");
strcpy(p_num[1][5],"S2");
strcpy(p_num[6][2],"E1");
strcpy(p_num[6][5],"E2");

//
k=0;
char c=48;
do{
	p_num[k][8][0]=c;
	p_num[8][k][0]=c;
	k++;
	c++;
}while(k!=8);
k=0;
strcpy(p_num[8][8]," ");

}





void play_show(char (*p_num)[9][3]){ //show current board with figures
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
       printf("%s ",p_num[i][j]);
	}
	printf("\n\n");
}
}






//
void play_chose(int*p_s, char (*p_num)[9][3]){ // show targets to move/attack (for ex.,R->#,E1->#1)
	char ch='?';
    int a=0;

	if (*p_s==0){ //if BLUEs
		for(int i=0;i<8;i++){


			for(int j=0;j<8;j++){


				if(a>=26||a<0)a=0;

		       if(strcmp(p_num[i][j],"B ")==0){

		    	   ch=97+a;
		    	   ++a;
		    	   if(a>=26)a=0;

		    	   p_num[i][j][0]=ch;

		       } else
		                         if(strcmp(p_num[i][j],"E1")==0){
		       		    	  		  ch=49;
		       		    	  		  p_num[i][j][0]=ch;
		       		    	  		p_num[i][j][1]=' ';

		       } else
		       		    	  		    	 if(strcmp(p_num[i][j],"E2")==0){

		       		    	  		    	 		    	ch=50;
		       		    	  		      		    p_num[i][j][0]=ch;
		       		    	  		      		p_num[i][j][1]=' ';

		       		    	  		    	 } else
		                                 if(strcmp(p_num[i][j],"R ")==0){
		    	                          ch=35;
		    	                          p_num[i][j][0]=ch;

		       } else
		       if(strcmp(p_num[i][j],"S1")==0){
		      		    	                          ch=35;
		      		    	                        p_num[i][j][0]=ch;
		      		    	                      p_num[i][j][1]='1';

		       } else
		    	   if(strcmp(p_num[i][j],"S2")==0){
		    	                   	              ch=35;
		    	                   	              p_num[i][j][0]=ch;
		    	                   	              p_num[i][j][1]='2';}


			}

		}


	} else if(*p_s==1){ //if REDs
		for(int i=0;i<8;i++){

			for(int j=0;j<8;j++){

				if(a>=26||a<0)a=0;


		       if(strcmp(p_num[i][j],"R ")==0){
		    	   ch=97+a;
		    	   ++a;
		    	    if(a>=26)a=0;
		    	   p_num[i][j][0]=ch;
		       } else
		    	   if(strcmp(p_num[i][j],"S1")==0){

		    	  		    	   ch=49;
		    	  		    	 p_num[i][j][0]=ch;
		    	  		    	p_num[i][j][1]=' ';}
		    	   else
		    	  		    	 if(strcmp(p_num[i][j],"S2")==0){

		    	  		    	 		    	ch=50;
		    	                  p_num[i][j][0]=ch;
		    	                  p_num[i][j][1]=' ';}
		    	  		else
		    	  		    	 if(strcmp(p_num[i][j],"B ")==0){
		    	                      ch=35;
		       		    	        p_num[i][j][0]=ch;}
		            else
		       if(strcmp(p_num[i][j],"E1")==0){
		       		      		  ch=35;
		       		      		p_num[i][j][0]=ch;
		                        p_num[i][j][1]='1';}
		       else
                if(strcmp(p_num[i][j],"E2")==0){
                	              ch=35;
                	              p_num[i][j][0]=ch;
                	              p_num[i][j][1]='2';}
			}

		}

	}


}






void play_clear(int*p_s, char (*p_num)[9][3]){ //exit from "play_chose" (#->B,#2->E2 etc.)

	if (*p_s==0){ //if BLUEs
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){

				if(p_num[i][j][0]>96&&p_num[i][j][0]<limit){
					strcpy(p_num[i][j],"B ");
				}
				if(p_num[i][j][0]==49){
									strcpy(p_num[i][j],"E1");
								}
				if(p_num[i][j][0]==50){
					strcpy(p_num[i][j],"E2");
				}
				if(p_num[i][j][0]=='#'){
					                    if(p_num[i][j][1]=='1')
								       strcpy(p_num[i][j],"S1");
										else if(p_num[i][j][1]=='2')
								       strcpy(p_num[i][j],"S2");
										else
									strcpy(p_num[i][j],"R ");
								}


			}

		}

	} else if(*p_s==1){ //if REDs
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(p_num[i][j][0]>96&&p_num[i][j][0]<limit){
									strcpy(p_num[i][j],"R ");
								}
								if(p_num[i][j][0]==49){
									strcpy(p_num[i][j],"S1");
												}
								if(p_num[i][j][0]==50){
									strcpy(p_num[i][j],"S2");
								}
								if(p_num[i][j][0]=='#'){

							if(p_num[i][j][1]=='1')
							strcpy(p_num[i][j],"E1");
							else if(p_num[i][j][1]=='2')
						strcpy(p_num[i][j],"E2");
							else
						strcpy(p_num[i][j],"B ");
												}



			}

		}

	}
}






void side(int*p_s){ //Change current team (for "step-by-step")
*p_s=(*p_s>0)?0:1;

}


/* simple function to empty stdin */
void empty_stdin (void)
{
    int c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}


void move(char (*p_num)[9][3],int*p_s,int*red_score,int*blue_score){ //move your team figure on board
int u=0; //crutch for 96-125 ascii letter-symbols diapazon/"kostil'" na diapazon symbolov ascii
   printf("Choose your figure\n");
   play_chose(p_s,p_num); // change units to targets letters abcd.. and 1/2
   play_show(p_num);

	char symb[2]="?"; //temp mass for scan symb
	char sym='?';
   if(fgets(symb,2,stdin)){
	   sym=symb[0];
	   while (getchar()!='\n');
    }
   //while (getchar()!='\n'){};


   //char sym='?';
   //sym=symb[0]; //symb from temp mass to char for next comparision

   //while (getchar()!='\n');

///////////////////////////////
if((sym>96&&sym<limit)||sym==49||sym==50){ //if figure is abc..xyz or 1/2
//////////////////////////////

if(*p_s==0){
    	 for(size_t j=0;j<8;j++){
    		 for(size_t i=0;i<8;i++){

    		 if(p_num[i][j][0]==sym){ //IF this symbol found in board
    			 u=1; //crutch is symb found, then this symb exist;
    			 if(p_num[i][j][0]>96&&p_num[i][j][0]<limit){ //if this symb is letter (basic unit)
            	   if(strcmp(p_num[i-1][j],"_ ")==0){
            		   strcpy(p_num[i-1][j],p_num[i][j]);
            		   strcpy(p_num[i][j],"_ ");

            		   if(i-1==0){*blue_score+=1;
            		   		printf("blues have +1 point\n");
            		   		if (*blue_score==4){end_game('B',p_num);
            		   		}
            		   	}

            	   }else{ printf("STEP IS IMPOSSIBLE\n");play_clear(p_s,p_num);return;}


            	   //---------------------------------------------------


               } else if(p_num[i][j][0]=='1'||p_num[i][j][0]=='2'){ //if Spy unit
            	   //IF CONDITIONS FOR SUPER MOVE EXISTS-->
            	   if((strcmp(p_num[i-1][j],"_ ")==0)&&(strcmp(p_num[i-2][j],"_ ")==0)&&
            			   ((p_num[i][j][0]=='1'&&e1_jump<spy_limit)||(p_num[i][j][0]=='2'&&e2_jump<spy_limit))){
                             do{
            /*5*/	   printf("You select spy-unit. Choose between [B]asic move and [S]uper move");//scan sym
            		   if(fgets(symb,2,stdin)){
            			   sym=symb[0];
            			   while (getchar()!='\n');
            		       }
                             }while(sym!='B'&&sym!='S');

            		     //sym=symb[0];
            		     //while (getchar()!='\n');
            		   //end scan

            		     if(sym=='B'){ //if basic move

            			   strcpy(p_num[i-1][j],p_num[i][j]);
            			   strcpy(p_num[i][j],"_ ");


                       if(i-1==0){*blue_score+=1;
                     		   		printf("blues have +1 point\n");
                     		   		if (*blue_score==4){end_game('B',p_num);
                     		   		}
                     		   	}

            		   }


            		   else if (sym=='S'){ //if "super" jump
            			   if(p_num[i][j][0]=='1')e1_jump+=1;
                    		else if(p_num[i][j][0]=='2')e2_jump+=1;
            			   strcpy(p_num[i-2][j],p_num[i][j]);
            			   strcpy(p_num[i][j],"_ ");

            			   if(i-2==0){*blue_score+=1;
							printf("blues have +1 point\n");
							if (*blue_score==4){end_game('B',p_num);
							}
            			               		   	}

            		   }
            	   } else  if(strcmp(p_num[i-1][j],"_ ")==0){//IF ONLY BASIC MOVE POSSIBLE FOR SPY
                		   strcpy(p_num[i-1][j],p_num[i][j]);
                		   strcpy(p_num[i][j],"_ ");

         if(i-1==0){*blue_score+=1;
                     		   		printf("blues have +1 point\n");
                     		   		if (*blue_score==4){end_game('B',p_num);
                     		   		}
                     		   	}

                	   }else{ printf("THE STEP IMPOSSIBLE\n");play_clear(p_s,p_num);return;}

    		 }

    	 }
     }
    	 }
    	 if(u==0){ printf("Figure not found\n");play_clear(p_s,p_num);return;} //crutch, if symb not exist


}else if(*p_s==1){

	for(size_t j=0;j<8;j++){
	    		 for(size_t i=0;i<8;i++){


	    		 if(p_num[i][j][0]==sym){
	    			 u=1;
	               if(sym>96&&sym<limit){
	            	   if(strcmp(p_num[i+1][j],"_ ")==0){
	            		   strcpy(p_num[i+1][j],p_num[i][j]);
	            		   strcpy(p_num[i][j],"_ ");

	            		   if(i+1==7){*red_score+=1; //CHECK VICTORY AFTER MOVE
	            		       			 		printf("reds have +1 point\n");
	            		       			 		if(*red_score==4){end_game('R',p_num);
	            		       			 		}
	            		       			 	}

	            	   }else{ printf("STEP IS IMPOSSIBLE\n");play_clear(p_s,p_num);return;}

	            	   break;
	            	   //---------------------------------------------------


	               } else if(sym=='1'||sym=='2'){
	            	   if((strcmp(p_num[i+1][j],"_ ")==0)&&(strcmp(p_num[i+2][j],"_ ")==0)&&
	            			   ((p_num[i][j][0]=='1'&&s1_jump<spy_limit)||(p_num[i][j][0]=='2'&&s2_jump<spy_limit))){
	            		   do{
	            		   printf("You select spy-unit. Choose between [B]asic move and [S]uper move");
	            /*5*/	   //scan sym
	            		   if(fgets(symb,2,stdin)){
	            			   sym=symb[0];
	            			   while (getchar()!='\n');
	            		       }
	            		   }while(sym!='B'&&sym!='S');

	            		     //sym=symb[0];
	            		     //while (getchar()!='\n');
	            		   //end scan
	            		   if(sym=='B'){

	            			   strcpy(p_num[i+1][j],p_num[i][j]);
	            			   strcpy(p_num[i][j],"_ ");


	         if(i+1==7){*red_score+=1; //CHECK VICTORY AFTER MOVE
	        	            		       			 		printf("reds have +1 point\n");
	        	            		       			 		if(*red_score==4){end_game('R',p_num);
	        	            		       			 		}
	        	            		       			 	}

	            		   }else if (sym=='S'){
	            			   if(p_num[i][j][0]=='1')s1_jump+=1;
	            			    else if(p_num[i][j][0]=='2')s2_jump+=1;
	            			   strcpy(p_num[i+2][j],p_num[i][j]);
	            			   strcpy(p_num[i][j],"_ ");


	            			   if(i+2==7){*red_score+=1; //CHECK VICTORY AFTER MOVE
	            			  	            		       			 		printf("reds have +1 point\n");
	            			  	            		       			 		if(*red_score==4){end_game('R',p_num);
	            			  	            		       			 		}
	            			  	            		       			 	}

	            		   }
	            	   } else  if(strcmp(p_num[i+1][j],"_ ")==0){//=>=>
	                		   strcpy(p_num[i+1][j],p_num[i][j]);
	                		   strcpy(p_num[i][j],"_ ");


	 if(i+1==7){*red_score+=1; //CHECK VICTORY AFTER MOVE
		            		       			 		printf("reds have +1 point\n");
		            		       			 		if(*red_score==4){end_game('R',p_num);
		            		       			 		}
		            		       			 	}

	                	   }else{ printf("STEP IMPOSSIBLE\n");play_clear(p_s,p_num);return;}
                      break;
	    		 }

	    	 }
	     }
	    	 }

	if(u==0){ printf("Figure not found\n");play_clear(p_s,p_num);return;}

}


} else{printf("!!Wrong letter!!\n"); play_clear(p_s,p_num);return;}


u=0;
play_clear(p_s,p_num); //revert board
side(p_s); //change team (step by step)
}
















void attack(char (*p_num)[9][3],int*p_s,int*red_score,int*blue_score,int*p_rkill,int*p_bkill){

	 play_chose(p_s,p_num);
	 printf("Choose your figure\n");
	 play_show(p_num);

	 size_t i=0,j=0; //your figure coordinates
	 size_t ki=0,kj=0;//target to attack coordinates

	 bool found=0; //exit from cycles when symbol found

	 		 char symb[2]={"!"};
	 		char sym='t';

	 if(*p_s==0){ //if BLUEs

		 /////////////
		 		 /////////////////


		 		 //SCAN_FIGURE
		 		 		   if(fgets(symb,2,stdin)){
		 		 			 sym=symb[0];
		 		 			while (getchar()!='\n');
		 		 		       }
		 		 		    //END_OF_SCAN


		 		 		    //
		 		 		  //while (getchar()!='\n');
		 		 		    //[4.]


		 		 		    /////////////////////////////////////////////
		 		 		    	if((sym>96&&sym<limit)||sym=='1'||sym=='2'){
		 		 		    ////////////////////////////////////////////
		 		 		    		for(size_t x = 0;x<8;x++){
		 		 		    		for(size_t y = 0;y<8;y++){

		 		 		    			if(p_num[x][y][0]==sym){
		 		 		    				i=x;j=y;
		 		 		    				found=true;
		 		 		    				break;
		 		 		    			}

		 		 		    		}
		 		 		    		if(found)
		 		 		    			break;
		 		 		    	}
                             found=false;

		 		 		    	play_clear(p_s,p_num);
		 		 		    	side(p_s);
		 		 		    	play_chose(p_s,p_num);

		 		 		    	printf("Choose target to attack\n");

		 		 		    	play_show(p_num);
		 		 		    	} else {printf("Wrong letter\n");play_clear(p_s,p_num);return;}

		 		 		    	//[5.]


		 		 		    	if(fgets(symb,2,stdin)){
		 		 		    		sym=symb[0];
		 		 		    		while (getchar()!='\n');
		 		 		    			     }
		 		 		    			    //END_OF_SCAN


		 		 		    			    //sym=symb[0];
		 		 		    			  //while (getchar()!='\n');

		 		 		    			    //////////////////////////////////////////////
		 		 		    			    	if((sym>96&&sym<limit)||sym=='1'||sym=='2'){ //IF figure
		 		 		    			    /////////////////////////////////////////////

		 		 		    			    		for(size_t x = 0;x<8;x++){
		 		 		    			    		for(size_t y = 0;y<8;y++){

		 		 		    			    			if(p_num[x][y][0]==sym){
		 		 		    			    				ki=x;kj=y;
		 		 		    			    				found=true;
		 		 		    			    				break;
		 		 		    			    			}

		 		 		    			    		}
		 		 		    			    		if(found)
		 		 		    			    			break;
		 		 		    			    	}
		 		 		    			    		found=false;
		 		 		    			    	}else {printf("Wrong letter\n");play_clear(p_s,p_num);side(p_s);return;}


		 		 		    			 play_show(p_num);

		 		 		    			    	//[6.]


		 		 		    			    		if(strcmp(p_num[i][j],"#1")==0||strcmp(p_num[i][j],"#2")==0){ //IF SPY (specifically)

		 		 		    			    		//{1}NEXT IS VARIATIONS OF SPY ATTACKS

		 		 		    			    		//{a} up-right
		 		 		    			    		if(sym==p_num[ki][kj][0]&&(i-ki==1&&j-kj==-1)){
		 		 		    			    			if(strcmp(p_num[i-2][j+2],"_ ")==0){
		 		 		    			    			   strcpy(p_num[i-2][j+2],p_num[i][j]);
		 		 		    			    			   strcpy(p_num[i-1][j+1],"_ ");
		 		 		    			    			   strcpy(p_num[i][j],"_ ");
		 		 		    			    			   //kill count
		 		 		    			    			   *p_rkill+=1;
		 		 		    			    			   //check victory row
		 		 		    			    			  		   if(i-2==0){*blue_score+=1;
		 		 		    			    			  		   printf("blues have +1 point\n");
		 		 		    			    			  		   }
		 		 		    			    			}else {printf("attack to up-righ impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 		 		    			    			//{b} up-left
		 		 		    			    		} else if(sym==p_num[ki][kj][0]&&(i-ki==1&&j-kj==1)){
		 		 		    			    			if(strcmp(p_num[i-2][j-2],"_ ")==0){
		 		 		    			    			   strcpy(p_num[i-2][j-2],p_num[i][j]);
		 		 		    			    			   strcpy(p_num[i-1][j-1],"_ ");
		 		 		    			    			   strcpy(p_num[i][j],"_ ");
		 		 		    			    			   //kill count
		 		 		    			    			   *p_rkill+=1;
		 		 		    			    			   //check victory row
		 		 		    			    			   		    if(i-2==0){*blue_score+=1;
		 		 		    			    			   		    printf("blues have +1 point\n");
		 		 		    			    			   		    }
		 		 		    			    			}else {printf("attack to up-left impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 		 		    			    			//{c} down-left
		 		 		    			    		} else if(sym==p_num[ki][kj][0]&&(i-ki==-1&&j-kj==1)&&i!=0){
		 		 			    			    			if(strcmp(p_num[i+2][j-2],"_ ")==0){
		 		 			    			    			   strcpy(p_num[i+2][j-2],p_num[i][j]);
		 		 			    			    			   strcpy(p_num[i+1][j-1],"_ ");
		 		 			    			    			   strcpy(p_num[i][j],"_ ");
		 		 			    			    			   //kill count
		 		 			    			    			   *p_rkill+=1;
		 		 			    			    			}else {printf("attack to down-left impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 		 			    			    		//{d} down-right
		 		 			    			    	} else if(sym==p_num[ki][kj][0]&&(i-ki==-1&&j-kj==-1)&&i!=0){
		 		 			    			    			if(strcmp(p_num[i+2][j+2],"_ ")==0){
		 		 				    			    			   strcpy(p_num[i+2][j+2],p_num[i][j]);
		 		 				    			    			   strcpy(p_num[i+1][j+1],"_ ");
		 		 				    			    			   strcpy(p_num[i][j],"_ ");
		 		 				    			    			   //kill count
		 		 				    			    			   *p_rkill+=1;
		 		 				    			    			} else {printf("attack to down-right impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 		 			    			    		//down
		 		 			    			    	} else if(sym==p_num[ki][kj][0]&&(i-ki==-1&&j-kj==0)&&i!=0){
															if(strcmp(p_num[i+2][j],"_ ")==0){
																   strcpy(p_num[i+2][j],p_num[i][j]);
																   strcpy(p_num[i+1][j],"_ ");
																   strcpy(p_num[i][j],"_ ");
																   //kill count
																   *p_rkill+=1;
																} else {printf("down slot after enemy unit is not empty\n");play_clear(p_s,p_num);side(p_s);return;}

		 		 			    			    	} else{printf("Attack with emissarius is impossible\n");play_clear(p_s,p_num);side(p_s);return;}

		 		 		    			    		//{1}END
		 		 		    			    	} else if(strcmp(p_num[i][j],"# ")==0){  //IF you choose COMMON figure (specifically)

		 		 		    			    			if(p_num[i-1][j][0]>96&&p_num[i-1][j][0]<limit&&strcmp(p_num[i-2][j],"_ ")==0){
		 		 		    			    				    			    			if(strcmp(p_num[ki][kj],p_num[i-1][j])==0){
		 		 		    			    				    			    			   strcpy(p_num[i-2][j],p_num[i][j]);
		 		 		    			    				    			    			   strcpy(p_num[i-1][j],"_ ");
		 		 		    			    				    			    			   strcpy(p_num[i][j],"_ ");
		 		 		    			    				    			    			   //kill count
		 		 		    			    				    			    			    *p_rkill+=1;
		 		 		    			    				    			    			  //check victory row
																								if(i-2==0){*blue_score+=1;
																								printf("blues have +1 point\n");
																								}
		 		 		    			    				    			    			}
		 		 		    			    			} else //if target is red SPY -->
		 												if((p_num[i-1][j][0]=='1'||p_num[i-1][j][0]=='2')&&strcmp(p_num[i-2][j],"_ ")==0){
		 																					if(strcmp(p_num[ki][kj],p_num[i-1][j])==0){
		 																					   strcpy(p_num[i-2][j],p_num[i][j]);
		 																					   //strcpy(p_num[i-1][j],"_ "); //kill
		 																					   strcpy(p_num[i][j],"_ ");

		 																					   //check spies "play dead" limit
		 																					   if(p_num[i-1][j][0]=='1'&&s1_mock<spy_limit){
		 																					   s1_mock+=1;
		 																					   printf("Red spy pretended to be dead\n");

		 																					   //if limit->kill spies
		 																					   }else if(p_num[i-1][j][0]=='1'&&s1_mock==spy_limit){
		 																						  strcpy(p_num[i-1][j],"_ "); //kill
		 																						 //kill count
																								*p_bkill+=1; //kill count
		 																					   }

		 																					  if(p_num[i-1][j][0]=='2'&&s2_mock<spy_limit){
																							   s2_mock+=1;
																							   printf("Red spy pretended to be dead\n");


																							   }else if(p_num[i-1][j][0]=='2'&&s2_mock==spy_limit){
																								  strcpy(p_num[i-1][j],"_ "); //kill
																								  //kill count
																							    *p_bkill+=1; //kill count
																							   }


		 																					 //check victory row
																							if(i-2==0){*blue_score+=1;
																							printf("blues have +1 point\n");
																							}

		 																					}

		 		 		    			    		}else{printf("Attack with standard unit impossible\n");play_clear(p_s,p_num);side(p_s);return;}

		 		 		    			    			//IF not spy or soldier -->
		 		 		                                  } else {printf("Figure letter is not relate to any of exist classes\n");play_clear(p_s,p_num);side(p_s);return;}



		 		 		    			    	//check alive in enemy team; 2nd victory condition
		 		 		    			    	 if(*p_rkill==4){
		 		 		    			    			    printf("Reds surrender\n");
		 		 		    			    			   end_game('B',p_num);
		 		 		    			    			        }
		 		 		    			    	 //1st victory condition
		 		 		    			    	 if (*blue_score==4){end_game('B',p_num);}


		 ////////////
		 		 ////////////////

	 } else if(*p_s==1){ //if REDs
/////////////
		 /////////////////


		 //SCAN_FIGURE
		 		   if(fgets(symb,2,stdin)){
		 			  sym=symb[0];
		 			 while (getchar()!='\n');
		 		       }
		 		    //END_OF_SCAN


		 		    //sym=symb[0];
		 		   //while (getchar()!='\n');
		 		    //[4.]

		 		    /////////////////////////////////////////////
		 		    	if((sym>96&&sym<limit)||sym=='1'||sym=='2'){
		 		    ////////////////////////////////////////////
		 		    		for(size_t x = 0;x<8;x++){
		 		    		for(size_t y = 0;y<8;y++){

		 		    			if(p_num[x][y][0]==sym){
		 		    				i=x;j=y;
		 		    				found=true;
		 		    				break;
		 		    			}

		 		    		}
		 		    		if(found)
		 		    			break;
		 		    	}
                      found=0;

		 		    	play_clear(p_s,p_num);
		 		    	side(p_s);
		 		    	play_chose(p_s,p_num);

		 		    	printf("Choose target to attack\n");

		 		    	play_show(p_num);
		 		    	} else {printf("Wrong letter\n");play_clear(p_s,p_num);return;}

		 		    	//[5.]


		 		    	if(fgets(symb,2,stdin)){
		 		    		sym=symb[0];
		 		    		while (getchar()!='\n');
		 		    			     }
		 		    			    //END_OF_SCAN


		 		    			    //sym=symb[0];
		 		    			   //while (getchar()!='\n');
		 		    			    //////////////////////////////////////////////
		 		    			    	if((sym>96&&sym<limit)||sym=='1'||sym=='2'){ //IF figure
		 		    			    /////////////////////////////////////////////

		 		    			    		for(size_t x = 0;x<8;x++){
		 		    			    		for(size_t y = 0;y<8;y++){

		 		    			    			if(p_num[x][y][0]==sym){
		 		    			    				ki=x;kj=y;
		 		    			    				found=1;
		 		    			    				break;
		 		    			    			}

		 		    			    		}
		 		    			    	if(found)
		 		    			    		break;
		 		    			    	}
		 		    			    		found=0;
		 		    			    	}else {printf("Wrong letter\n");play_clear(p_s,p_num);side(p_s);return;}


		 		    			 play_show(p_num);

		 		    			    	//[6.]

		 		    			    		if(strcmp(p_num[i][j],"#1")==0||strcmp(p_num[i][j],"#2")==0){ //IF SPY (specifically)

		 		    			    		//{1}NEXT IS VARIATIONS OF SPY ATTACKS

		 		    			    		//{a} up-right
		 		    			    		if(sym==p_num[ki][kj][0]&&(i-ki==1&&j-kj==-1)&&i!=7){
		 		    			    			if(strcmp(p_num[i-2][j+2],"_ ")==0){
		 		    			    			   strcpy(p_num[i-2][j+2],p_num[i][j]);
		 		    			    			   strcpy(p_num[i-1][j+1],"_ ");
		 		    			    			   strcpy(p_num[i][j],"_ ");
		 		    			    			   //kill count
		 		    			    			   *p_bkill+=1;

		 		    			    			}else {printf("attack to up-right impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 		    			    			//{b} up-left
		 		    			    		} else if(sym==p_num[ki][kj][0]&&(i-ki==1&&j-kj==1)&&i!=7){
		 		    			    			if(strcmp(p_num[i-2][j-2],"_ ")==0){
		 		    			    			   strcpy(p_num[i-2][j-2],p_num[i][j]);
		 		    			    			   strcpy(p_num[i-1][j-1],"_ ");
		 		    			    			   strcpy(p_num[i][j],"_ ");
		 		    			    			   //kill count
		 		    			    			   *p_bkill+=1;

		 		    			    			}else {printf("attack to up-left impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 		    			    			//{c} down-left
		 		    			    		} else if(sym==p_num[ki][kj][0]&&(i-ki==-1&&j-kj==1)){
		 			    			    			if(strcmp(p_num[i+2][j-2],"_ ")==0){
		 			    			    			   strcpy(p_num[i+2][j-2],p_num[i][j]);
		 			    			    			   strcpy(p_num[i+1][j-1],"_ ");
		 			    			    			   strcpy(p_num[i][j],"_ ");
		 			    			    			   //kill count
		 			    			    			   *p_bkill+=1;
		 			    			    			  //check victory row
														if(i+2==7){*red_score+=1;
														printf("reds have +1 point\n");
														}
		 			    			    			}else {printf("attack to down-left impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 			    			    		//{d} down-right
		 			    			    	} else if(sym==p_num[ki][kj][0]&&(i-ki==-1&&j-kj==-1)){
		 			    			    			if(strcmp(p_num[i+2][j+2],"_ ")==0){
		 				    			    			   strcpy(p_num[i+2][j+2],p_num[i][j]);
		 				    			    			   strcpy(p_num[i+1][j+1],"_ ");
		 				    			    			   strcpy(p_num[i][j],"_ ");
		 				    			    			   //kill count
		 				    			    			   *p_bkill+=1;
		 				    			    			  //check victory row
															if(i+2==7){*red_score+=1;
															printf("reds have +1 point\n");
															}
		 				    			    			} else {printf("attack to down-right impossible\n");play_clear(p_s,p_num);side(p_s);return;}
		 			    			    			//down
												} else if(sym==p_num[ki][kj][0]&&(i-ki==1&&j-kj==0)&&i!=7){
														if(strcmp(p_num[i-2][j],"_ ")==0){
															   strcpy(p_num[i-2][j],p_num[i][j]);
															   strcpy(p_num[i-1][j],"_ ");
															   strcpy(p_num[i][j],"_ ");
															   //kill count
															   *p_bkill+=1;
															} else {printf("down slot after enemy unit is not empty\n");play_clear(p_s,p_num);side(p_s);return;}

		 			    			    	} else{printf("Attack with spy is impossible\n");play_clear(p_s,p_num);side(p_s);return;}

		 		    			    		//{1}END
		 		    			    	} else if(strcmp(p_num[i][j],"# ")==0){  //IF you choose COMMON figure (specifically)

		 		    			    			if(p_num[i+1][j][0]>96&&p_num[i+1][j][0]<limit&&strcmp(p_num[i+2][j],"_ ")==0){
		 		    			    				    			    			if(strcmp(p_num[ki][kj],p_num[i+1][j])==0){
		 		    			    				    			    			   strcpy(p_num[i+2][j],p_num[i][j]);
		 		    			    				    			    			   strcpy(p_num[i+1][j],"_ ");
		 		    			    				    			    			   strcpy(p_num[i][j],"_ ");
		 		    			    				    			    			   //kill count
		 		    			    				    			    			    *p_bkill+=1;
		 		    			    				    			    			   //check victory row
																						if(i+1==7){*red_score+=1;
																						printf("reds have +1 point\n");
																						}
		 		    			    				    			    			}
		 		    			    			} else //if target is blues emissarius
												if((p_num[i+1][j][0]=='1'||p_num[i+1][j][0]=='2')&&strcmp(p_num[i+2][j],"_ ")==0){
																					if(strcmp(p_num[ki][kj],p_num[i+1][j])==0){
																					   strcpy(p_num[i+2][j],p_num[i][j]);
																					   //strcpy(p_num[i+1][j],"_ "); //kill
																					   strcpy(p_num[i][j],"_ ");

																					   //check emissar "play dead" limit
																					   if(p_num[i+1][j][0]=='1'&&e1_mock<spy_limit){
																					   e1_mock+=1;
																					   printf("Blue emissarius pretended to be dead\n");

																					   //if limit->kill emis
																					   }else if(p_num[i+1][j][0]=='1'&&e1_mock==spy_limit){
																						  strcpy(p_num[i+1][j],"_ "); //kill
																						  //kill count
																						*p_rkill+=1; //kill count
																					   }

																					   if(p_num[i+1][j][0]=='2'&&e2_mock<spy_limit){
																						   e2_mock+=1;
																						   printf("Blue emissarius pretended to be dead\n");


																						   }else if(p_num[i+1][j][0]=='2'&&e2_mock==spy_limit){
																							  strcpy(p_num[i+1][j],"_ "); //kill
																							  //kill count
																							*p_rkill+=1; //kill count
																						   }


																						//check victory row
																							if(i+1==7){*red_score+=1;
																							printf("reds have +1 point\n");
																							}
																					}

		 		    			    		}else{printf("Attack with standard unit impossible\n");play_clear(p_s,p_num);side(p_s);return;}

		 		    			    			// if not spy or soldier -->
		 		                                  } else {printf("Figure letter is not relate to any of exist classes\n");play_clear(p_s,p_num);side(p_s);return;}



		 		    			    	//check alive in enemy team; 2nd victory condition
		 		    			    	 if(*p_bkill==4){
		 		    			    			    printf("Blues surrender\n");
		 		    			    			   end_game('R',p_num);
		 		    			    			        }
		 		    			    	 //1st victory condition
		 		    			    	 if (*red_score==4){end_game('R',p_num);}


////////////
		 ////////////////
	 }

play_clear(p_s,p_num);

}









//////////////////////////////////////////////////////////////////////////////////







void end_game(char a,char (*p_num)[9][3]){ //victory func
if(a=='B'){play_show(p_num);printf("BLUEs victory\n");
            FILE *mr;
char end_buffer[256];
mr=fopen("/usr/share/red-spies/blues","r");
    if(mr)
    {
        // пока не дойдем до конца, считываем по 256 байт
    	// scan for 256 bytes until EOF
        while((fgets(end_buffer, 256, mr))!=NULL)
        {
            printf("%s", end_buffer);
        }
        fclose(mr);
    }

	_Exit (EXIT_SUCCESS);

}else if(a=='R'){play_show(p_num);printf("REDs victory\n");
      FILE *mr;
char end_buffer[256];
mr=fopen("/usr/share/red-spies/reds","r");
    if(mr)
    {
        // пока не дойдем до конца, считываем по 256 байт
        while((fgets(end_buffer, 256, mr))!=NULL)
        {
            printf("%s", end_buffer);
        }
        fclose(mr);
    }

	_Exit (EXIT_SUCCESS);
}

}





