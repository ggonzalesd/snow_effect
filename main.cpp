#include<cstdlib>
#include<ctime>
#include "lib.h"


#define FPS 16

int BASE = 0;
int BASEx = 0;

class CopoDeNieve{
private:
	float x,y;
	bool dead;
	float speed;
	char c;

public:
	CopoDeNieve(int, int);
	~CopoDeNieve();

	void loop();
	void kill();
	bool to_remove();
};

// -------------------------------------

CopoDeNieve::CopoDeNieve(int x, int y){
	int _ = rand()%2;

	if(_==0) c = '.';
	if(_==1) c = '*';

	this->x = (float)x;
	this->y = (float)y;

	dead = false;

	speed = (float)(rand()%30) + 0.02;
	speed /= 1000;
	speed += 0.03*(c=='*');


}

CopoDeNieve::~CopoDeNieve(){
	move(y, x); printw(" ");
}

// --- --- --- ---

void CopoDeNieve::kill(){
	dead = true;
}

bool CopoDeNieve::to_remove(){
	return dead;
}

void CopoDeNieve::loop(){
	move(y, x); printw(" ");

	this->y += speed;

	move(y, x); printw("%c",c);

	if(y > MY -1 - BASE) kill();
}

// -------------------------------------

// -------------------------------------

class Controler{
private:
	CopoDeNieve** array;
	int n;

	int timed;
	int timed_spawn;
	int limite;

	int elim;

public:
	Controler();
	~Controler();

	void add(CopoDeNieve*);
	void remove();

	void loop();
	void clean();
};

// -------------------------------------

Controler::Controler(){
	array = NULL;
	n = 0;
	timed = 0;

	timed_spawn = 10; // Set 15
	limite = 60;

	elim = 0;
}

Controler::~Controler(){

}

// -------------------------------------

void Controler::add(CopoDeNieve* copo){
	//printf("Hola\n");
	if(n>0){
		CopoDeNieve** arrayx = new CopoDeNieve*[n+1];

		for(int i=0; i<n; i++){
			arrayx[i] = array[i];
		}
		arrayx[n] = copo;

		delete []array;

		array = arrayx;
		n++;
	}else{
		this->array = new CopoDeNieve*[1];
		array[0] = copo;

		n = 1;

	}

}

void Controler::remove(){
	int nx = 0;

	for(int i=0; i<n; i++){
		if(array[i]->to_remove()==false) nx++;
	}

	if(nx){
		CopoDeNieve** arrayx = new CopoDeNieve*[nx];
		int j=0;

		for(int i=0; i<n; i++){
			if(array[i]->to_remove()){
				delete array[i];
				elim++;
			}else{
				arrayx[j] = array[i];
				j++;
			}
			
		}

		delete []array;

		array = arrayx;

	}else{
		delete []array;
		array = NULL;
	}

	n = nx;
}

void Controler::loop(){
	timed++;

	if(timed > timed_spawn && n<limite){
		
		add(new CopoDeNieve(
				rand()%MX,
				1
		));

		timed = 0;
	}

	if(elim > 20){
		elim = 0;
		BASE++;
	}

	for(int i=0; i<n; i++){
		array[i]->loop();
	}
	remove();

}

void Controler::clean(){
	if(n){
		for(int i=0; i<n; i++){
			delete array[i];
		}
		delete []array;

		array = NULL;
		n = 0;
	}


	clear();


}

// -------------------------------------

void draw_snow(){
	for(int j=0; j<BASE; j++){
		for(int i=1; i<MX-1; i++){
			move(MY-j-1, i);
			
			addch(ACS_CKBOARD);
		}
	}
}

int main(){
	srand(time(NULL));

	Controler* A = new Controler;

	GInit();



	while(true){
		Gloop(FPS);

		BASEx = BASE;

		A->loop();

		if(RESIZED || (BASE+4)> MY){
			if((BASE+4)> MY){
				for(int i=0; i<6; i++){
					if(i%2){
						draw_snow();
					}else{
						clear();
					}

					refresh();
					napms(350);
				}
			}
			A->clean();
			BASE = 0;
		}

		if(BASEx != BASE){
			draw_snow();
		}

		if(KEY == 'q' || KEY == 'Q') break;

		//move(1,1); printw("%d %d", MX, MY);

	}

	GEnd();
}
