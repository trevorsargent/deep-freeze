#include <FPT.h>

int h,w;
int win=0;
double swidth = 600, sheight = 600;
double board[100][100];
double checked[100][100];
int i=0, j=0, k=1;
double numPairs;
double cardWidth,cardHeight;
double p[2];
double k1, k2;
int ia,ja,ib,jb;

void drawCard(int i, int j){

  G_rgb(1,1,1);
  G_fill_rectangle(i*cardWidth, j*cardHeight,cardWidth,cardHeight);
  G_rgb(0,0,0);
  G_fill_rectangle(i*cardWidth+2, j*cardHeight+2, cardWidth-4, cardHeight-4);
  G_rgb(1,1,1);
  G_fill_rectangle(i*cardWidth+4, j*cardHeight+4, cardWidth-8, cardHeight-8);

}

void drawColor(int i, int j){

  //color select based on k;
  if(board[i][j]==1){
    G_rgb(1,0,0);
  }else if(board[i][j]==2){
    G_rgb(0,1,0);
  }else if(board[i][j]==3){
    G_rgb(0,0,1);
  }else if(board[i][j]==4){
    G_rgb(1,1,0);
  }else if(board[i][j]==5){
    G_rgb(1,0,1);
  }else if(board[i][j]==6){
    G_rgb(0,1,1);
  }else if(board[i][j]==7){
    G_rgb(1,0.5,0);
  }else if(board[i][j]==8){
    G_rgb(1,0,0.5);
  }else if(board[i][j]==9){
    G_rgb(.5,1,0);
  }else if(board[i][j]==10){
    G_rgb(0,1,.5);
  }else if(board[i][j]==11){
    G_rgb(0,0.5,1);
  }else if(board[i][j]==12){
    G_rgb(.5,0,1);;
  }else if(board[i][j]==13){
    G_rgb(1,.5,.5);
  }else if(board[i][j]==14){
    G_rgb(.5,1,.5);
  }else if(board[i][j]==15){
    G_rgb(.5,.5,1);
  }else if(board[i][j]==16){
    G_rgb(.5,.5,.5);
  }else if(board[i][j]==17){

  }else if(board[i][j]==18){

  }else if(board[i][j]==19){

  }else if(board[i][j]==20){

  }

  G_fill_rectangle(i*cardWidth+6,j*cardHeight+6,cardWidth-12,cardHeight-12);

}




int main(){
 
	//zeroes out the array
	
	while(i<100){
	  while(j<100){
	    board[i][j] = 0;
	    checked[i][j] = 0;
	    j++;
	  }	
	  i++;
	}

	cout << "Welcome to 'Memory'. Please enter the size of the (square) board. (must be an even number of cards...)" << endl;
	
	
	//get size of board
	while(1){
	  cout << "Number of Cards, square: ";
	  cin >> h;
	  w=h;
	  if(fmod((h*w),2)==0){break;}
		
	  cout << "that wont work - try again!" << endl;
	}
	
	G_init_graphics(swidth,sheight);
	i=0; j=0;
	numPairs=h*w/2;
	cardWidth=swidth/w;
	cardHeight=sheight/h;
	while(win==0){
		
	  while (k<=numPairs){
	    while(1){
	      i=floor(drand48()*h);
	      j=floor(drand48()*w);
		
	      if(board[i][j]==0){
		board[i][j]=k;
		break;
	      }

	    }

	    while(1){
	      i=floor(drand48()*h);
	      j=floor(drand48()*w);
		
	      if(board[i][j]==0){
		board[i][j]=k;
		break;
	      }

	    }
	    k++; 	
	  }



	
	//*draw out cards
	  i=0;j=0;
	  while(i<h){
	    j=0;
	    while(j<w){
	      if(board[i][j]!=0){
		drawCard(i,j);
	      }
	    
	      j++;
	    }
	    i++;
	  }
	  G_wait_click(p);
	//flip card 1
	  ia=floor(p[0]/cardWidth);
	  ja=floor(p[1]/cardHeight);
	  drawColor(ia,ja);
	  k1=board[ia][ja];

	  while(1){

	  G_wait_click(p);
	//flip card 2
	  ib=floor(p[0]/cardWidth);
	  jb=floor(p[1]/cardHeight);

	  if((ib!=ia)||(jb!=ja)){
	      break;
	  }
	  }
	  drawColor(ib,jb);
	  k2=board[ib][jb];

	//check if same
	  if(k1==k2){
	    board[ia][ja]=0;
	    board[ib][jb]=0;

	  }

	  G_wait_click(p);
	//loop to *
	  G_rgb(.25,.25,.25);
	  G_clear();

	  i=0;j=0;
	  win=1;
	  while(i<h){
	    while(j<w){
	      if(board[i][j]!=0){
		win=0;
	      }
	      j++;
	    }
	    i++;
	  }

	}

}
