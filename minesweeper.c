#include <FPT.h>

int blockSide = 20;
int size;
double surround[100][100];
double mines[100][100];
double flagged[100][100];
double checked[100][100];
int i = 0;
int j = 0;

int win = 1;
int end = 0;

int welcome(){
	cout << "Please enter the size of the board on which you would like to play ('8' for 8x8, '16' for 16x16 etc).\n";
	cin >> size;

	G_init_graphics(size*blockSide,size*blockSide);
	return size;
}

int count(int i, int j){

	int count=0;
	int f;
	int g;

	f = -1;
	g = -1;

	
	while(f<2){
		g=-1;
		while(g<2){				
				if((((i+f)>=0) || ((i+f) < size)) && (((j+g)>=0) || ((j+g) < size))){
					if(mines[i+f][j+g] == 1){
						count ++;
					}
				}
			g++;	
		}
		f++;
	}

	return count;
}

void drawCell(int i, int j){

	int f;
	int g;

	if(checked[i][j]==1){
		//do something complicated
		
		if(mines[i][j] == 1){ // if it's a mine
			G_rgb(1,0,0);
			G_fill_rectangle (i*blockSide, j*blockSide, blockSide, blockSide);
			win = 0;
			end = 1;

		}else if(surround[i][j]!=9){ // if it's near a mine

			G_rgb(.85,.85,.85);
			G_fill_rectangle (i*blockSide, j*blockSide, blockSide, blockSide);
			
			if(surround[i][j]==1){

				G_rgb(0,0,1);
				G_draw_string("1", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==2){
			
				G_rgb(0,.75,.5);
				G_draw_string("2", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==3){
			
				G_rgb(1,.25,0);
				G_draw_string("3", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==4){
			
				G_rgb(.75,0,.1);
				G_draw_string("4", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==5){
			
				G_rgb(1,1,0);
				G_draw_string("5", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==6){
			
				G_rgb(0,0,0);
				G_draw_string("6", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==7){
			
				G_rgb(0,0,0);
				G_draw_string("7", i*blockSide+ blockSide/4, j*blockSide + blockSide/8);
			
			}else if(surround[i][j]==8){
			
				G_rgb(0,0,0);
				G_draw_string("8", i*blockSide, j*blockSide);
			}
		}

	}else if(checked[i][j] == 2){
		G_rgb(0.3,0.2,0.2);
		G_fill_rectangle (i*blockSide, j*blockSide, blockSide, blockSide);

	}else if(checked[i][j]==0){
		//draw blank square
		G_rgb(0.7,0.7,0.7);
		G_fill_rectangle (i*blockSide, j*blockSide, blockSide, blockSide);
		//-----
	}
	G_rgb(0,0,0);
	G_rectangle(i*blockSide,j*blockSide,blockSide,blockSide);

}

void checkEnd(){
		i=0;
		end = 1;
		while(i<size){
			j=0;
			while(j<size){
				if((flagged[i][j] == 1) || (flagged[i][j] == -1)){
					end = 0;
				}
				j++;
			}
			i++;
		}
}

void game(){
	int f;
	int g;

	double p[2];

	int xclick;
	int yclick;
	int k=0;
	//prepare arrays
	i=0;
	j=0;
	while(i < 100){
		j=0;
		while(j<100){
			surround[i][j] = 9; //for how many mines surround
			mines[i][j] = 0;
			flagged[i][j] = 0;
			checked[i][j] = 0;
			j++;
		}
		i++;
	}
	//-----

	size = welcome();

	/* ALGORITHM TO DISTRUBUTE SOME ZEROES FIRST BASED ON FIRST CLICK
	//draw cells 
		G_rgb(0,0,0);
		G_clear();
		while(i<size){
			j=0;
	 		while(j<size){drawCell(i,j);
			j++;
		}
		i++;
		}
	G_wait_click(p); // get first click to ensure that that is zero

	xclick = floor(p[0]/blockSide);
	yclick = floor(p[1]/blockSide);

	checked[xclick][yclick] = 1;

	*/


	//distribute mines
	while (k<=1.5*size){
		while(1){
		  i=floor(drand48()*size);
		  j=floor(drand48()*size);	
	    if(mines[i][j]==0){
				mines[i][j]=1;
				flagged[i][j] = 1;
				break;
		  }

		}
		k++; 	
	}
	//-----
	i=0;
	j=0;
	//prepare "surround"
	while(i<100){
		j=0;
		while(j<100){
			surround[i][j] = count(i,j);
			j++;
		}
		i++;
	}
	//-----


	while(end == 0){	

		i = 0;
		j = 0;

		//draw cells
		G_rgb(0,0,0);
		G_clear();
		while(i<size){
			j=0;
	 		while(j<size){
	 			drawCell(i,j);
				j++;
			}
		i++;
		}

		if(win == 0){
			f = 0;
			while(f<size){
				g = 0;
				while(g<size){
					if(mines[f][g] == 1){
						G_rgb(1,0,0);
						G_fill_rectangle (f*blockSide, g*blockSide, blockSide, blockSide);
					}
					g++;
				}
				f++;
			}
		}

		if(end == 0){
			checkEnd();
		}

		G_wait_click(p);

		xclick = floor(p[0]/blockSide);
		yclick = floor(p[1]/blockSide);

		if(checked[xclick][yclick] == 0){
			checked[xclick][yclick] = 2;
			flagged[xclick][yclick]--;
		}else{
			checked[xclick][yclick] = 1;
		}

		//expand zero sections. 
		k=0;
		while(k<100){
			i=0;
			while(i<size){
				j=0;
				while(j<size){
					if((surround[i][j] == 0) && (checked[i][j] == 1)){
						f=-1;
						while(f<2){
							g=-1;
							while(g<2){				
								if((((i+f)>=0) || ((i+f) < size)) && (((j+g)>=0) || ((j+g) < size))){
									if(mines[i+f][j+g] == 0){
										checked[i+f][j+g] = 1;
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
			k++;//expand zero sections
		}

		if(end == 0){
			checkEnd();
		}


	}
}

int main(){
	char y;
	cout << "\n Welcome to Minsesweeper! \n \n";
	while(1){
		win = 1;
		end = 0;
		game();

		G_close();

		if(win == 0){
			cout << "you lost... how sad\n";
		}else if(win == 1){
			cout << "you won! yay!\n";
		}	
		cout << "would you like to play again? (y/n)";
		cin >> y;

		if(y == 'n'){
			break;
		}else{
			cout << "\n \n";
		}
	}
}