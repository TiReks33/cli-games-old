#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits>
#include "balls20.hpp"
////////////////////////////////////////////

//struct CharArray2D Array2D;

///////////////////////////////////////////

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//global variables and pointers:
//game score and score limit
  //int game_score=0;
//int*p_score=&game_score;
  //int score_limit=500;
//int*p_limit=&score_limit;
Score* sc = new Score(0,500);
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main(void){

	std::cout << sc->game_score <<" "<< sc->score_limit <<"\n";

bool bye=0;
        char ins='?'; //symb for game "initialization"

        std::string line;

           std::ifstream in("logo"); // open file for read
           if (in.is_open())
           {
               while (std::getline(in, line))
               {
                   std::cout << line << std::endl;
               }
           }
           in.close();     // close file

std::cout << (" '1' - start, 'i' - show game rules, 'q' - quit\n");

//"main menu"
do{
//"main menu"

   std::cin >> ins;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new line

        switch(ins){
                case '1': std::cout << ("Let's begin;\nchoose size of board:\n'1' - 4x4, '2' - 8x8,"
                		  " '3' - 10x10,\n'4' - 12x12, '5' - 16x16; '6' - 24x24;\nor 'q' - to quit\n");
                          break;

                case 'q': std::cout << ("Bye!\n"); return 0;

                case 'i': std::cout <<("\tGame rules:\n");show_rules();
                          std::cout <<("\n1 - Start, i - Show game rules again, q - quit\n");
                          break;

                default: std::cout <<("Try again! Press 1 to start game, i - to show rules, q - to quit\n");
                          break;
        }

//"main menu"
}while(ins!='1');
//"main menu"

size_t size=0;

do{

//select size of board
   std::cin >> ins;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new line

        switch(ins){
                case '1': size=4;sc->score_limit=80;break;
                case '2': size=8;sc->score_limit=160;break;
	            case '3': size =10;sc->score_limit=240;break;
	            case '4': size =12;sc->score_limit=320;break;
	            case '5': size = 16;sc->score_limit=400;break;
	            case '6': size = 24;sc->score_limit=480;break;
	            case 'q': std::cout << ("Bye!\n"); return 0;

	             default: std::cout <<("Try again! Choose size of board: '1' - 4x4, '2' - 8x8,"
	            		  " '3' - 10x10, '4' - 12x12, '5' - 16x16; '6' - 24x24; or 'q' - to quit\n");
	                      break;
        }

//"size of board"
}while(ins!='1'&&ins!='2'&&ins!='3'&&ins!='4'&&ins!='5'&&ins!='6');


//TEST{1}
std::cout << "test after ch size\n";
std::cout << "test after ch size"<<std::endl;

//!!NOT recommended (better initialize in function at heap, not stack
char bal[size][size]; // game board matrix
char *p_bal=&bal[0][0]; // pointer for board actions funcs
//!!

//size_t w=0,k=0;
for(size_t w=0;w!=size;++w){
	for(size_t k =0;k!=size;++k){
		bal[w][k]='#';
		//std::cout<<size;
//std::cout<<bal[w][k];
	}
	std::cout<<std::endl;
}
std::cout << "TEST INIT\n";
for(size_t w=0;w!=size;++w){
	for(size_t k =0;k!=size;++k){
std::cout<<bal[w][k];
	}
	std::cout<<std::endl;
}
std::cout<<std::endl;

bal[2][2]='$';
bal[3][3]='%';
bal[4][4]='!';
//w=0;k=0;
for(size_t w=0;w!=size;++w){
	for(size_t k=0;k!=size;++k){
std::cout<<bal[w][k];
	}
	std::cout<<std::endl;
}
//TEST{1}end

                                          //extern object of structure from .hpp file -->
//CharArray2D Ball2D;
    //CharArray2D Ball2D(size);
        CharArray2D Ball2D(size,size);
            //CharArray2D Ball2D(p_bal); //with exist matrix (that included correct symbs;
                //CharArray2D Ball2D(p_bal,size); //if not -- incorr.symbs will be deleted
                    //CharArray2D Ball2D(p_bal,size,size);
                                             //<--"game board" matrix and its pointer
CharArray2D *p_ball2d=&Ball2D;//&Ball2D;

std::cout << "test size parametres : \n";
std::cout << p_ball2d->col << p_ball2d->row << std::endl;

std::cout << "TEST INIT2->\n";
for(size_t w=0;w!=size;++w){
	for(size_t k =0;k!=size;++k){
std::cout<<p_ball2d->get(w, k);
	}
	std::cout<<std::endl;
}
std::cout<<std::endl;

init(p_ball2d);

play_show(p_ball2d);

update(p_ball2d);

play_show(p_ball2d);

//std::cin >> size;

////////////////////////////CONDITION_OF_VICTORY
do{
///////////////////////////CONDITION_OF_VICTORY

std::cout << "Destroy this balls!!\n";


do{
	printf("\tYour current points: %d\n\tlimit is:%d\n\n",sc->game_score,sc->score_limit);
	play_show(p_ball2d);
std::cout << " [d]estroy balls | [u]pdate | [r]eset | [e]xit\n";

std::cin >> ins;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new line

char ci='?';
char cj='?';
size_t ki=0,kj=0;
	switch(ins){
		case 'd': destroy(p_ball2d,sc);
			      break;

		case 'u': update(p_ball2d);
		          break;

		case 'r': figures(p_ball2d);
		          break;

		case 'e': std::cout << "Bye!\n";
		          //free_array2d(&p_ball2d->data);
		          bye=1;
		          //return 0;
		          break; //for cleaning memory

		default : std::cout << "Try again! 1 or 0\n";
                  break;
	}

}while(ins!='d'&&ins!='u'&&ins!='r'&&bye!=1);

std::cout << "ещё чуть-чуть!\n";
std::cout << sc->game_score << std::endl;
//////////////////////////////////////////CONDITION_OF_VICTORY
//}while(game_score<score_limit&&bye!=1);
}while((sc->game_score)<(sc->score_limit)&&bye!=1);
/////////////////////////////////////////CONDITION_OF_VICTORY
std::cout << "сейчас память будеть очищена\n";
//free_array2d(&p_ball2d->data,size,size);

  free_array2d(p_ball2d->data);

	//delete[] Ball2D.data;

	return 0;
}


