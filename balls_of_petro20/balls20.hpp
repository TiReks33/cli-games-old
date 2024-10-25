#ifndef balls20_h
#define balls20_h

char * create_array2d(size_t a, size_t b);

struct CharArray2D
{
	CharArray2D(size_t row=12, size_t col=12) : row(row),col(row)
	{
		char* bal;
		bal=create_array2d(row,col);
		for(size_t i=0;i!=row;++i){
			for(size_t j=0;j!=col;++j){
				bal[i*col+j]='_';
			}
			}
		data=bal;
		bal=NULL;
	}

	CharArray2D(char *data, size_t row=24,size_t col=24): data(data),row(row),col(row)
	{ //build call with(for) already existed matrix

		        //row=col=24;
				char* bal;
				bal=create_array2d(row,col);
				for(size_t i=0;i!=row;++i){
								for(size_t j=0;j!=col;++j){
									bal[i * col + j]=this->data[i*col+j];
									if(
											bal[i*col+j]<33||bal[i*col+j]>38

									)
									bal[i*col+j]='_';
								}
								}
				this->data=bal;
				bal=NULL;
	}

	char &get(size_t i, size_t j){ // set && get, 2 in 1 (by link "&" symbol) =)
		return data[i*col+j];      // so, this structure's matrix can be read,
	}                              // and also modified!
	char *data;
	size_t row;
	size_t col;
	//char *data;
};

struct Shift
{
	explicit Shift(size_t i=0,size_t j=0)
	: i(i), j(j)
	{}
	size_t i;
	size_t j;
};

struct Points
{
	explicit Points(size_t i=0,size_t j=0)
	: i(i), j(j)
	{}
	size_t i;
	size_t j;
};


struct Score
{
	explicit Score(int game_score=0,int score_limit=0)
	:game_score(0),score_limit(1)
	{
		this->game_score=game_score;
		this->score_limit=score_limit;
	}
	int game_score;
	int score_limit;
};

extern struct CharArray2D Ball2D; //for linking my structure in .cpp files
extern struct Shift Shift_ij;

void free_array2d(char *m);
void show_rules(void);
void init(CharArray2D *bal);
void update(CharArray2D *bal);
void play_show(CharArray2D *bal);
void figures(CharArray2D *bal);
void destroy(CharArray2D *bal, Score* sc,
		Points k=Points(),Shift sh=Shift());
bool check_field(CharArray2D *bal,Points k); //function check that the ball is in radius; 1--in radius,0-off
bool alone_check(CharArray2D *bal, Points k);
void victory_check(Score* sc);
void victory();



 //prototypes (declaration) of funcs
#endif //Header
