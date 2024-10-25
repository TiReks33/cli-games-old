#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <stdbool.h>
#include "balls20.hpp"


//definition of funcs

//const int limit = 100;

char * create_array2d(size_t a, size_t b)
{
	char *m=new char[a*b];
	for(size_t i=1;i!=a;++i)
		m[i]=m[i-1]+b;
	return m;
}

void free_array2d(char *m)
{
	//delete[] m[0];
	delete[] m;
	//*m=NULL;
}

void free_array2d(char **m)
{
	delete[] m[0];
	delete[] m;
	//*m=NULL;
}



void show_rules(void){ //rules of game .txt

    std::string line;

       std::ifstream in("descr.txt"); // окрываем файл для чтения
       if (in.is_open())
       {
           while (std::getline(in, line))
           {
               std::cout << line << std::endl;
           }
       }
       in.close();     // закрываем файл
}






void init(CharArray2D *bal){
for(size_t i=0;i!=bal->row-1;i++){
	for(size_t j=0;j!=bal->col-1;j++){
		if(
				(bal->get(i,j))<33||(bal->get(i,j))>38
				)
		bal->get(i,j)='_';
	}
}
size_t k=0;

//Initialization of board



//
k=0;
char c=97;
do{
	//bal[(row-1)*col+k]=c;
	bal->get(bal->row-1,bal->col-(bal->col-k))=c; //row, "col-(col-k) -- reverse
	//bal[(row-(row-k)+1)*col-1]=c;
	bal->get(bal->row-(bal->row-k),bal->col-1)=c; //col
	k++;
	c++;
}while(k!=bal->row);
k=0;

}

void update(CharArray2D *bal)
{
	    srand(time(NULL));
		for(size_t i=0;i!=bal->row-1;++i){
			for(size_t j=0;j!=bal->col-1;++j){
				if(bal->get(i,j)=='_')
				bal->get(i,j)=33+rand()%(6);
			}
		}
}


void play_show(CharArray2D *bal){ //show current board with figures
	std::cout << "parameters : " << bal->row << bal->col<<"\n";
for(size_t i=0;i!=bal->row;++i){
	printf("\t");
	for(size_t j=0;j!=bal->col;++j){
       std::cout << bal->get(i, j) << " ";
	}
	std::cout << std::endl;
}
std::cout<<std::endl;
}



void figures(CharArray2D *bal){
    srand(time(NULL));
	for(size_t i=0;i!=bal->row-1;++i){
		for(size_t j=0;j!=bal->col-1;++j){
			//if(bal->get(i,j)=='_')
			bal->get(i,j)=33+rand()%(6);
		}
	}

}

bool check_field(CharArray2D *bal,Points k)
{
	if(
		  ( k.i>((bal->row)-2)||k.j>((bal->col)-2) ) //coordinates is correct ('a' to max letter of size)
	                          ||
		               ( k.i<0||k.j<0 ) //same
	   ){
		std::cout << "ki =="<<k.i << "kj =="<<k.j<<"\n";
		return 0;
	     }
	return 1;
}

bool alone_check(CharArray2D *bal,Points k)
{

		if(
		bal->get(k.i,k.j-1)!=bal->get(k.i,k.j) &&
		bal->get(k.i-1,k.j)!=bal->get(k.i,k.j) &&
		bal->get(k.i,k.j+1)!=bal->get(k.i,k.j) &&
		bal->get(k.i+1,k.j)!=bal->get(k.i,k.j) &&
		bal->get(k.i-1,k.j-1)!=bal->get(k.i,k.j) &&
		bal->get(k.i-1,k.j+1)!=bal->get(k.i,k.j) &&
		bal->get(k.i+1,k.j-1)!=bal->get(k.i,k.j) &&
		bal->get(k.i+1,k.j+1)!=bal->get(k.i,k.j)
		  )
		   return 1;

		return 0;
}


void destroy(CharArray2D *bal,Score* sc,
		Points k,Shift sh)
{
	Points k2; //"target coordinates" object to find the shifts between balls
	 k2.i=k.i,k2.j=k.j;
    char ci='?',cj='?';


        	//play_show(bal,row,col);
        	//COORDINATES 2
        	do{
        		play_show(bal);
        		//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
        		//INSERT COORDINATES

        						std::cout << "Введите координаты исходного шара.\nВведите символьный номер строки\n";

        						std::cin >> ci;
        						std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        						std::cout << "stroka i "  << (size_t)(ci-'1')<<"\n";

        					    std::cout << "Введите координаты исходного шара.\nВведите символьный номер столбца\n";

        						std::cin >> cj;
        						std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        						std::cout << "stolbec "  << (size_t)(cj-'1')<<"\n";

        						//ci = ((size_t)(ci-'1'))-48;
        						k.i = (ci-'1')-48;
        						std::cout << "ci: "<< k.i;
        						//cj = ((size_t)(cj-'1'))-48;
        						k.j = (cj-'1')-48;
        					    std::cout << " cj: "<<k.j << std::endl;
        					    //INSERT COORDINATES

        					    if (!check_field(bal,k))
								{std::cout <<"this ball off the radius!\n";
								return;} //if ball off the radius --exit

        					    if (alone_check(bal,k))
        					    {std::cout <<"this ball lonely buddy!\n";
        					    return;} //if only 1 ball in radius->exit func


        		//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
        		do{
        		std::cout << "Введите координаты целевого шара.\nВведите символьный номер строки\n";

        		std::cin >> ci;
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой

        		std::cout << "stroka "  << (size_t)(k2.i-'1')<<"\n";

        	    std::cout << "Введите координаты целевого шара.\nВведите символьный номер столбца\n";

        		std::cin >> cj;
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой

        		std::cout << "stolbec "  << (size_t)(k2.j-'1')<<"\n";

        		//k.i2 = ((size_t)(k.i2-'1'))-48;
        		k2.i = (ci-'1')-48;
        		std::cout << "k2.i: "<< k2.i;
        		//k2.j = ((size_t)(k2.j-'1'))-48;
        		k2.j = (cj-'1')-48;
        	    std::cout << " k2.j: "<<k2.j << std::endl;

        	    if(k2.j==k.j&&k2.i==k.i)
        	    	std::cout<<"chosen target same as previous. choose another ball!\n";

        	    if(!check_field(bal,k2))
        		std::cout <<"chosen target is off the radius. "
        				"please insert correct coordinates of target\n";
        		}while(!check_field(bal,k2));
        	}while (k2.j==k.j&&k2.i==k.i);                            //#1, shift_i && sh_j==0
        	//COORDINATES 2
        	sh.i=k2.i-k.i;sh.j=k2.j-k.j; //shift i, shift j
        	std::cout << "shift i= "<< sh.i<< "shift j= "<<sh.j<<std::endl;
        	//std::cout << "module shift i= "<< abs(sh.i)<< "module shift j= "<<abs(sh.j)<<std::endl;
        	std::cout << "TEST\n";
        	//std::cin >> flag;

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
        	int i=0,j=0;
            char temp='?';
            int ti=i,tj=j;

        if(bal->get(k.i+sh.i, k.j+sh.j)==bal->get(k.i, k.j)) //if second ball is wrong -- 1st not be destroyed
        	                                                 //(minimum 2 balls will have been destroyed)
        {
            if((sh.i>0&&sh.j>0&&sh.i==sh.j)
            		||(sh.i<0&&sh.j<0&&sh.i==sh.j)){ //#2 && #3
        	//for(int i=0;i<=sh.i;++i){
        	     i=k.i;ti=i;
        	     j=k.j;tj=j;
        	     temp=bal->get(i,j);
        	     do{
        	     bal->get(i,j)='_';
        	     sc->game_score+=(20*(i-k.i));
        	     ++i;++j;
        	     }while(bal->get(i,j)==temp);
        	     i=ti;j=tj;
        	     do{
				 bal->get(i,j)='_';
				 sc->game_score+=(20*(k.i-i));
				 --i;--j;
				 }while(bal->get(i,j)==temp);
        	     i=0;j=0;
        		//}
        	}

        	else

        	if ((sh.i==0&&sh.j>0)
        			||(sh.i==0&&sh.j<0)){ //#4 && #6
        		j=k.j; tj=j;
        		temp=bal->get(k.i,j);
                do{
        		//for(int j=0;j<=sh.j;++j){
        			bal->get(k.i,j)='_';
        			sc->game_score+=(20*(j-k.j));
        		//}
        			++j;
                }while(bal->get(k.i,j)==temp);
                j=tj;
                do{
                	bal->get(k.i,j)='_';
					sc->game_score+=(20*(k.j-j));
					--j;
                }while(bal->get(k.i,j)==temp);
        	j=0;
        	}

        	else

        	if ((sh.i>0&&sh.j==0)||
			     (sh.i<0&&sh.j==0)){            //#5 && #7
                i=k.i;ti=i;
        		//for(int i=0;i<=sh.i;++i){
    			temp=bal->get(i,k.j);
        		do{
                 bal->get(i,k.j)='_';
        			sc->game_score+=(20*(i-k.i));
        			++i;
        		}while(bal->get(i,k.j)==temp);
        		i=ti;
        		do{
				 bal->get(i,k.j)='_';
					sc->game_score+=(20*(k.i-i));
					--i;
				}while(bal->get(i,k.j)==temp);
        	i=0;
        	}

        	else

        	        	if ((sh.i>0&&sh.j<0)||
        				     (sh.i<0&&sh.j>0)){            //up-right && down-left
        	                i=k.i;ti=i;
        	                j=k.j;tj=j;
        	        		//for(int i=0;i<=sh.i;++i){
        	    			temp=bal->get(i,j);
        	        		do{
        	                 bal->get(i,j)='_';
        	        			sc->game_score+=(20*(i-k.i));
        	        			++i;--j;
        	        		}while(bal->get(i,j)==temp);
        	        		i=ti; j=tj;
        	        		do{
        					 bal->get(i,j)='_';
        						sc->game_score+=(20*(k.i-i));
        						--i;++j;
        					}while(bal->get(i,j)==temp);
        	        	i=0;j=0;
        	        	}

            play_show(bal);
        	  victory_check(sc);

               //

		//victory condition
        //play_show(bal,row,col);
		//if(*sc->game_score>=*sc->score_limit) victory();

		std::cout << "Current score: " << sc->game_score; // view current score
        }
}



void victory_check(Score* sc)
{
	if(sc->game_score>=sc->score_limit) victory();
}

void victory()
{
	std::string line;

	       std::ifstream in("victory.txt"); // окрываем файл для чтения
	       if (in.is_open())
	       {
	           while (std::getline(in, line))
	           {
	               std::cout << line << std::endl;
	           }
	       }
	       in.close();     // закрываем файл

	//_Exit (EXIT_SUCCESS);
}
