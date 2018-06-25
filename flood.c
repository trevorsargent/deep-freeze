//flood it
//Trevor Sargent
//©2013 Accidental C0de. 

#include <FPT.h>

int win;

int board[20][20];
int cellSize;
int live[20][20];

int i;
int j;

double swidth = 500;
double sheight = 650;

double moves;

void welcome(){
	double p[2];
	double xclick, yclick;


	G_rgb(.9,.9,.9);
	G_clear();

	G_rgb(0,0,0);
	G_fill_rectangle(50,300,400,50);
	G_rgb(1,1,1);
	G_fill_rectangle(52,302,396,46);

	G_rgb(0,0,0);
	G_draw_string("Welcome to FloodIt", 54,304);

	G_fill_rectangle(50,230,400,50);
	G_rgb(1,1,1);
	G_fill_rectangle(52,232,396,46);
	G_rgb(0,0,0);
	G_draw_string("Click to PLAY!",54,234);

	G_wait_click(p);
	xclick = p[0];
	yclick = p[1];

	while(1){

		if(((yclick > 230) && (yclick < 280)) && ((xclick > 50) && (xclick < 400))){
			break;
		}

	}


}

void colorSelect(int i, int j){
	if(board[i][j] == 1){
		G_rgb(.92,0,0);
	}else if(board[i][j] == 2){
		G_rgb(0,.92,0);
	}else if(board[i][j] == 3){
		G_rgb(0,0,.92);
	}else if(board[i][j] ==4){
		G_rgb(.92,.92,0);
	}else if(board[i][j] ==5){
		G_rgb(.92,0,.92);
	}else if(board[i][j] ==6){
		G_rgb(0,.92,.92);
	}
}

void draw(){
//clear	
	G_rgb(.9,.9,.9);
	G_clear();

//boundary
	G_rgb(0,0,0);
	G_fill_rectangle(48,198,404,404);
	G_rgb(1,1,1);
	G_fill_rectangle(50,200,400,400);

//draw board
	i=0;
	while(i<20){
		j = 0;
		while(j<20){
			colorSelect(i,j);
			G_fill_rectangle(50+20*i,200+20*j,20,20);
			j++;
		}
		i++;
	}
	
//draw movebar
	G_rgb(0,0,0);
	G_fill_rectangle(50,140,400,20);
	G_rgb(.8,.8,.8);
	G_fill_rectangle(52,142,396*(moves/40),16);

//draw sixbound
	G_rgb(0,0,0);
	G_fill_rectangle(50,25,400,80);
	G_rgb(.9,.9,.9);
	G_fill_rectangle(52,27,396,76);	

//draw sixboxes
	//box 1
	G_rgb(0,0,0);
	G_fill_rectangle(75,40,50,50);
	G_rgb(1,0,0);
	G_fill_rectangle(76,41,48,48);


	//box 2
	G_rgb(0,0,0);
	G_fill_rectangle(135,40,50,50);
	G_rgb(0,1,0);
	G_fill_rectangle(136,41,48,48);


	//box 3
	G_rgb(0,0,0);
	G_fill_rectangle(195,40,50,50);
	G_rgb(0,0,1);
	G_fill_rectangle(196,41,48,48);


	//box 4
	G_rgb(0,0,0);
	G_fill_rectangle(255,40,50,50);
	G_rgb(1,1,0);
	G_fill_rectangle(256,41,48,48);


	//box 5
	G_rgb(0,0,0);
	G_fill_rectangle(315,40,50,50);
	G_rgb(1,0,1);
	G_fill_rectangle(316,41,48,48);


	//box 6
	G_rgb(0,0,0);
	G_fill_rectangle(375,40,50,50);
	G_rgb(0,1,1);
	G_fill_rectangle(376,41,48,48);

}

int playGame(){
	
	int winColor = 0;
	double p[2];
	int xclick;
	int yclick;

	int f;
	int g;
	int k = 0;
	int floodColor = 0;

	floodColor = 0;
//prepare board
	i = 0;
	while(i<20){
		j = 0;
		while(j<20){
			board[i][j] = floor(drand48()*6)+1;
			j++;
		}
		i++;
	}

//prepare live
	i=0;
	while(i<20){
		j=0;
		while(j<20){
			live[i][j] = 0;
			j++;
		}
		i++;
	}
live[0][19] = 1;
floodColor = board[0][19];

//
	while(moves>=0){


//add to live selection
		k=0;
		while(k<5){
			
			i=0;
			while(i<20){
				j=0;
				while(j<20){
					if(live[i][j] == 1){
						f=-1;
						while(f<2){
							g=-1;
							while(g<2){
								if(((i+f >=0 ) && (i+f < 20)) && ((j+g >= 0) && (j+g < 20))){
									if(((board[i+f][j+g] == floodColor) && ((f+g ==1) || (f+g == -1)))){
										live[i+f][j+g] = 1;
									}
								}
								g++;
							}
							f++;
						}
					}
					j++;
				}
				i++;
			}
			k++;
		}
		draw();

	//test for win;
		win = 1;
		i=0;
		while(i<20){
			j=0;
			while(j<20){
				if(live[i][j] = 0){
					win = 0;
				}
				j++;
			}
			i++;
		}
	//	
		G_wait_click(p);
		xclick = p[0];
		yclick = p[1];

	//set floodColor

		if((yclick > 40) && (yclick < 90)){

			if((xclick > 75) && (xclick < 125)){
				floodColor = 1;
						moves--;
			}else if((xclick > 135) && (xclick < 185)){
				floodColor = 2;
						moves--;
			}else if((xclick > 195) && (xclick < 245)){
				floodColor = 3;
						moves--;
			}else if((xclick > 255) && (xclick < 305)){
				floodColor = 4;
						moves--;
			}else if((xclick > 315) && (xclick < 365)){
				floodColor = 5;
						moves--;
			}else if((xclick > 375) && (xclick < 425)){
				floodColor = 6;
						moves--;
			}

		}

	//wipe with floodColor
		i=0;
		while(i<20){
			j=0;
			while(j<20){
				if(live[i][j] == 1){
					board[i][j] = floodColor;
				}
				j++;
			}
			i++;
		}
	}

}

int playAgain(){

	int again;
	double p[2];
	double xclick,yclick;

	G_rgb(.9,.9,.9);
	G_clear();

	G_rgb(0,0,0);
	G_fill_rectangle(50,400,400,50);
	G_rgb(1,1,1);
	G_fill_rectangle(52,402, 396, 46);

	G_rgb(0,0,0);
	if(win == 1){
		G_draw_string("Congratulations! You Win!" , 54, 404);
	}else if(win == 0){
		G_draw_string("You Lost! :( Sorry!", 54, 404);
	}

	G_rgb(0,0,0);
	G_fill_rectangle(50,300,400,50);
	G_rgb(1,1,1);
	G_fill_rectangle(52,302,396,46);

	G_rgb(0,0,0);
	G_draw_string("Would you like to play again?", 54,304);

	G_fill_rectangle(50,230,195,50);
	G_fill_rectangle(255,230,195,50);
	G_rgb(1,1,1);
	G_fill_rectangle(52,232,191,46);
	G_fill_rectangle(257,232,191,46);

	G_rgb(0,0,0);
	G_draw_string("Yes!",54,234);
	G_draw_string("No, Thanks",209,234);

	G_wait_click(p);
	xclick = p[0];
	yclick = p[1];

	if((yclick > 230) && (yclick < 280)){
		if((xclick > 50) && (xclick < 245)){
			again = 1;
		}else if((xclick > 255) && (xclick < 450)){
			again = 0;
		}
	}
	return again;
	}

void thankYou(){

}

int main(){

	G_init_graphics(swidth,sheight);

	int repeat = 1;

	welcome();

	while(repeat == 1){
		moves = 40;
		playGame();
		repeat = playAgain();
	}

	thankYou();



}