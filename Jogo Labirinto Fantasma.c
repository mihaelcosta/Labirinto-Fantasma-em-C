#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define AlturaMax 23 
#define AlturaMin 1 
#define Comprimento 77
#define ComprimentoIncio 1

char reto=205, parede=186, quinaSD=187, quinaIE=200, quinaID=188, quinaSE=201;

int ganhou=0, morte=0;
int s,i;
int opcao;

char tabuleiro[25][77];
char caminho[25][77];

int movimento(char caminho[25][77]);
int historia();

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void campo(char tabuleiro[25][77], char caminho[25][77]){
	system("color 0B");
    printf("%c", 218);
	for(s=0;s<77;s++){printf("%c",196);}
   	printf("%c\n", 191);
    for(s=0;s<23;s++){
        for(i=0;i<77;i++){
            if (s==6 && i==74){
                tabuleiro[s][i] = '$';
            }
            else{
                tabuleiro[s][i] = ' ';
            }
            caminho[s][i] = '*';
		}	
	} 
   	for(i=0;i<3;i++){
            if (i==2){
            	caminho[2][i]=quinaSD;
			}
			else{
				caminho[2][i]=reto;
			}
	}
	for(s=3;s<7;s++){ 		
	    caminho[s][2]=parede;
	} 
    for(s=5;s<9;s++){
		caminho[s][0]=parede;
	}
	caminho[4][0]=quinaSD;
    
    caminho[7][2]=quinaIE;
    caminho[7][3]=reto;
	caminho[7][4]=quinaSD;
    
    caminho[9][0]=quinaIE;
    caminho[9][1]=reto;
	caminho[9][2]=quinaSD;

    for(s=8;s<15;s++){	
		caminho[s][4]=parede;
	}
	for(s=10;s<17;s++){
        caminho[s][2]=parede;
	} 
	for(i=4;i<7;i++){
            if (i==6){
            	caminho[15][i]=quinaID;
			}
			else if(i==4){
                caminho[15][i]=quinaIE;
            }
            else{
				caminho[15][i]=reto;
			}
            
	}
	for(i=2;i<7;i++){
        if (i==2){
            caminho[17][i]=quinaIE;
        }
        else if (i==6){
            caminho[17][i]=quinaSD;
        }
        else{
            caminho[17][i]=reto;
        }
        
	}
    for(s=14;s>1;s--){
        if (s==2){
    		caminho[s][6]=quinaSE;
		}
		else{
			caminho[s][6]=parede;
		}	
	}   
	for(s=18;s<21;s++){
		caminho[s][6]=parede;	
	}
	for(s=4;s<19;s++){
		caminho[s][8]=parede;	
	} 
	for(i=8;i<18;i++){
            if (i==8){
            	caminho[19][i]=quinaIE;
			}
			else if(i==17){
				caminho[19][i]=quinaID;
			}
			else{
				caminho[19][i]=reto;
			}
	}
	for(s=18;s>16;s--){
		caminho[s][17]=parede;
	}
    for(i=10;i>7;i--){
		if(i==10){
			caminho[4][i]=quinaSD;
		}
		else if(i==8){
            caminho[4][i]=quinaSE;
        }
        else{
			caminho[4][i]=reto;
		}
	}
	for(i=6;i<20;i++){
            if (i==6){
            	caminho[21][i]=quinaIE;
			}
			else if(i==19){
				caminho[21][i]=quinaID;
			}
			else{
				caminho[21][i]=reto;
			}
	}
    for(i=10;i<18;i++){
        if(i==10){
            caminho[16][i]=quinaIE;
        }
        else if(i==17){
            caminho[16][i]=quinaSD;
        }
        else{
            caminho[16][i]=reto;
        }
    }
    for(s=5;s<16;s++){
		caminho[s][10]=parede;
	}
    for(s=15;s<21;s++){
		caminho[s][19]=parede;
	}
    for(i=12;i<20;i++){
        if(i==12){
            caminho[14][i]=quinaIE;
        }
        else if(i==19){
            caminho[14][i]=quinaSD;
        }
        else{
            caminho[14][i]=reto;
        }
    }
    for(s=7;s<14;s++){
		caminho[s][12]=parede;
	}
    for(i=12;i<18;i++){
        if(i==12){
            caminho[6][i]=quinaSE;
        }
        else if(i==17){
            caminho[6][i]=quinaSD;
        }
        else{
            caminho[6][i]=reto;
        }
    }
    for(s=7;s<13;s++){
		caminho[s][17]=parede;
	}
    for(i=7;i<13;i++){
        if(i==12){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    caminho[3][12]=parede;
    for(i=12;i<20;i++){
        if(i==12){
            caminho[4][i]=quinaIE;
        }
        else if(i==19){
            caminho[4][i]=quinaSD;
        }else{
            caminho[4][i]=reto;
        }
    }
    for(s=5;s<11;s++){
        caminho[s][19]=parede;
    }
    for(i=19;i<27;i++){
        if(i==19){
            caminho[11][i]=quinaIE;
        }else if(i==26){
            caminho[11][i]=quinaID;
        }else{
            caminho[11][i]=reto;
        }
    }
    for(s=10;s>4;s--){
        caminho[s][26]=parede;
    } 
    for(s=14;s<20;s++){
        caminho[s][26]=parede;
    } 
    for(i=26;i<29;i++){
        if(i==26){
            caminho[20][i]=quinaIE;
        }else if(i==28){
            caminho[20][i]=quinaID;
        }else{
            caminho[20][i]=reto;
        }
    }
    for(s=16;s<20;s++){
        caminho[s][28]=parede;
    } 
    for(i=26;i>23;i--){
        if(i==26){
            caminho[4][i]=quinaSD;
        }else if(i==24){
            caminho[4][i]=quinaSE;
        }else{
            caminho[4][i]=reto;
        }
    }
    for(s=5;s<8;s++){
        caminho[s][24]=parede;
    }
    for(i=24;i>21;i--){
        if(i==24){
            caminho[8][i]=quinaID;
        }else if(i==22){
            caminho[8][i]=quinaIE;
        }else{
            caminho[8][i]=reto;
        }
    }
    for(i=26;i>16;i--){
        if(i==26){
            caminho[13][i]=quinaSD;
        }else if(i==17){
            caminho[13][i]=quinaIE;
        }else{
            caminho[13][i]=reto;
        }
    }
    for(s=10;s>=5;s--){    
        caminho[s][26]=parede;
    }
    for(s=7;s>2;s--){
        caminho[s][22]=parede;
    }
    for(i=22;i<29;i++){
        if(i==22){
            caminho[2][i]=quinaSE;
        }else if(i==28){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    for(s=3;s<=12;s++){    
        caminho[s][28]=parede;
    }
    for(i=28;i<34;i++){
        if(i==28){
            caminho[13][i]=quinaIE;
        }else if(i==33){
            caminho[13][i]=quinaID;
        }else{
            caminho[13][i]=reto;
        }
    }
    for(s=12;s>2;s--){    
        caminho[s][33]=parede;
    }
    for(i=33;i<39;i++){
        if(i==33){
            caminho[2][i]=quinaSE;
        }else if(i==38){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    for(s=3;s<19;s++){    
        caminho[s][38]=parede;
    }
    for(i=38;i<49;i++){
        if(i==38){
            caminho[19][i]=quinaIE;
        }else if(i==48){
            caminho[19][i]=quinaID;
        }else{
            caminho[19][i]=reto;
        }
    }
     for(s=18;s>11;s--){    
        caminho[s][48]=parede;
    }
    for(i=48;i>45;i--){
        if(i==48){
            caminho[11][i]=quinaSD;
        }else if(i==46){
            caminho[11][i]=quinaIE;
        }else{
            caminho[11][i]=reto;
        }
    }
    caminho[10][46]=parede;
    caminho[8][48]=parede;
    caminho[6][40]=parede;
    caminho[4][48]=parede;
    caminho[14][62]=parede;
    caminho[15][62]=parede;
    caminho[3][72]=parede;
    caminho[4][72]=quinaID;
    caminho[4][71]=quinaSE;
    caminho[19][62]=parede;
    caminho[20][62]=parede;
    caminho[10][53]=parede;
    caminho[4][36]=quinaSD;
    caminho[4][35]=quinaSE;
    for(i=48;i>45;i--){
        if(i==48){
            caminho[9][i]=quinaID;
        }else if(i==46){
            caminho[9][i]=quinaSE;
        }else{
            caminho[9][i]=reto;
        }
    }
    for(i=48;i>39;i--){
        if(i==48){
            caminho[7][i]=quinaSD;
        }else if(i==40){
            caminho[7][i]=quinaIE;
        }else{
            caminho[7][i]=reto;
        }
    }
    for(i=40;i<49;i++){
        if(i==48){
            caminho[5][i]=quinaID;
        }else if(i==40){
            caminho[5][i]=quinaSE;
        }else{
            caminho[5][i]=reto;
        }
    }
    for(i=48;i<57;i++){
        if(i==48){
            caminho[3][i]=quinaSE;
        }else if(i==56){
            caminho[3][i]=quinaSD;
        }else{
            caminho[3][i]=reto;
        }
    }
    for(s=4;s<16;s++){    
        caminho[s][56]=parede;
    }
    for(i=56;i<63;i++){
        if(i==56){
            caminho[16][i]=quinaIE;
        }else if(i==62){
            caminho[16][i]=quinaID;
        }else{
            caminho[16][i]=reto;
        }
    }
    for(i=59;i<63;i++){
        if(i==59){
            caminho[13][i]=quinaIE;
        }else if(i==62){
            caminho[13][i]=quinaSD;
        }else{
            caminho[13][i]=reto;
        }
    }
    for(s=5;s<13;s++){    
        caminho[s][59]=parede;
    }
    for(i=59;i<68;i++){
        if(i==59){
            caminho[4][i]=quinaSE;
        }else if(i==67){
            caminho[4][i]=quinaSD;
        }else{
            caminho[4][i]=reto;
        }
    }
    for(s=5;s<16;s++){    
        caminho[s][67]=parede;
    }
    for(i=67;i<70;i++){
        if(i==67){
            caminho[16][i]=quinaIE;
        }else if(i==69){
            caminho[16][i]=quinaID;
        }else{
            caminho[16][i]=reto;
        }
    }
    for(s=3;s<16;s++){    
        caminho[s][69]=parede;
    }
    for(i=69;i<73;i++){
        if(i==69){
            caminho[2][i]=quinaSE;
        }else if(i==72){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    for(s=5;s<18;s++){    
        caminho[s][71]=parede;
    }
    for(i=65;i<72;i++){
        if(i==65){
            caminho[18][i]=quinaIE;
        }else if(i==71){
            caminho[18][i]=quinaID;
        }else{
            caminho[18][i]=reto;
        }
    }
     for(s=7;s<18;s++){    
        caminho[s][65]=parede;
    }
     for(i=61;i<66;i++){
        if(i==61){
            caminho[6][i]=quinaSE;
        }else if(i==65){
            caminho[6][i]=quinaSD;
        }else{
            caminho[6][i]=reto;
        }
    }
     for(s=7;s<11;s++){    
        caminho[s][61]=parede;
    }
    for(i=61;i<65;i++){
        if(i==61){
            caminho[11][i]=quinaIE;
        }else if(i==64){
            caminho[11][i]=quinaSD;
        }else{
            caminho[11][i]=reto;
        }
    }
    for(s=12;s<19;s++){    
        caminho[s][64]=parede;
    }
     for(i=64;i<74;i++){
        if(i==64){
            caminho[19][i]=quinaIE;
        }else if(i==73){
            caminho[19][i]=quinaID;
        }else{
            caminho[19][i]=reto;
        }
    }
    for(s=6;s<19;s++){    
        caminho[s][73]=parede;
    }
    for(i=73;i<76;i++){
        if(i==73){
            caminho[5][i]=quinaSE;
        }else if(i==75){
            caminho[5][i]=quinaSD;
        }else{
            caminho[5][i]=reto;
        }
    }
    for(s=6;s<21;s++){    
        caminho[s][75]=parede;
    }
    for(i=62;i<76;i++){
        if(i==62){
            caminho[21][i]=quinaIE;
        }else if(i==75){
            caminho[21][i]=quinaID;
        }else{
            caminho[21][i]=reto;
        }
    }
    for(i=54;i<63;i++){
        if(i==54){
            caminho[18][i]=quinaIE;
        }else if(i==62){
            caminho[18][i]=quinaSD;
        }else{
            caminho[18][i]=reto;
        }
    }
    for(s=6;s<18;s++){    
        caminho[s][54]=parede;
    }
    for(i=50;i<55;i++){
        if(i==50){
            caminho[5][i]=quinaSE;
        }else if(i==54){
            caminho[5][i]=quinaSD;
        }else{
            caminho[5][i]=reto;
        }
    }
    for(s=6;s<10;s++){    
        caminho[s][50]=parede;
    }
    for(i=50;i<54;i++){
        if(i==50){
            caminho[9][i]=quinaIE;
        }else if(i==53){
            caminho[9][i]=quinaSD;
        }else{
            caminho[9][i]=reto;
        }
    }
    for(i=50;i<54;i++){
        if(i==50){
            caminho[11][i]=quinaSE;
        }else if(i==53){
            caminho[11][i]=quinaID;
        }else{
            caminho[11][i]=reto;
        }
    }
    for(s=12;s<21;s++){    
        caminho[s][50]=parede;
    }
    for(i=36;i<51;i++){
        if(i==36){
            caminho[21][i]=quinaIE;
        }else if(i==50){
            caminho[21][i]=quinaID;
        }else{
            caminho[21][i]=reto;
        }
    }
    for(s=5;s<21;s++){    
        caminho[s][36]=parede;
    }
    for(s=5;s<15;s++){    
        caminho[s][35]=parede;
    }
    for(i=28;i<36;i++){
        if(i==28){
            caminho[15][i]=quinaSE;
        }else if(i==35){
            caminho[15][i]=quinaID;
        }else{
            caminho[15][i]=reto;
        }
    }
	for(s=0;s<23;s++){
        printf("%c", 179);
        for(i=0;i<77;i++){
			printf("%c",tabuleiro[s][i]);
		}	
        printf("%c\n", 179);
	}
	printf("%c", 192);
	for(s=0;s<77;s++){printf("%c",196);}
   	printf("%c", 217);
}
int mapa(char caminho[25][77]){
	system("color 0B");
    int opcao;
    int s,i;
    printf("%c", 218);
	for(s=0;s<77;s++){printf("%c",196);}
   	printf("%c\n", 191);
    for(s=0;s<23;s++){
        for(i=0;i<77;i++){
            caminho[s][i] = ' ';
		}	
	} 
   	for(i=0;i<3;i++){
            if (i==2){
            	caminho[2][i]=quinaSD;
			}
			else{
				caminho[2][i]=reto;
			}
	}
	for(s=3;s<7;s++){ 		
	    caminho[s][2]=parede;
	} 
    for(s=5;s<9;s++){
		caminho[s][0]=parede;
	}
	caminho[4][0]=quinaSD;
    
    caminho[7][2]=quinaIE;
    caminho[7][3]=reto;
	caminho[7][4]=quinaSD;
    
    caminho[9][0]=quinaIE;
    caminho[9][1]=reto;
	caminho[9][2]=quinaSD;

    for(s=8;s<15;s++){	
		caminho[s][4]=parede;
	}
	for(s=10;s<17;s++){
        caminho[s][2]=parede;
	} 
	for(i=4;i<7;i++){
            if (i==6){
            	caminho[15][i]=quinaID;
			}
			else if(i==4){
                caminho[15][i]=quinaIE;
            }
            else{
				caminho[15][i]=reto;
			}
            
	}
	for(i=2;i<7;i++){
        if (i==2){
            caminho[17][i]=quinaIE;
        }
        else if (i==6){
            caminho[17][i]=quinaSD;
        }
        else{
            caminho[17][i]=reto;
        }
        
	}
    for(s=14;s>1;s--){
        if (s==2){
    		caminho[s][6]=quinaSE;
		}
		else{
			caminho[s][6]=parede;
		}	
	}   
	for(s=18;s<21;s++){
		caminho[s][6]=parede;	
	}
	for(s=4;s<19;s++){
		caminho[s][8]=parede;	
	} 
	for(i=8;i<18;i++){
            if (i==8){
            	caminho[19][i]=quinaIE;
			}
			else if(i==17){
				caminho[19][i]=quinaID;
			}
			else{
				caminho[19][i]=reto;
			}
	}
	for(s=18;s>16;s--){
		caminho[s][17]=parede;
	}
    for(i=10;i>7;i--){
		if(i==10){
			caminho[4][i]=quinaSD;
		}
		else if(i==8){
            caminho[4][i]=quinaSE;
        }
        else{
			caminho[4][i]=reto;
		}
	}
	for(i=6;i<20;i++){
            if (i==6){
            	caminho[21][i]=quinaIE;
			}
			else if(i==19){
				caminho[21][i]=quinaID;
			}
			else{
				caminho[21][i]=reto;
			}
	}
    for(i=10;i<18;i++){
        if(i==10){
            caminho[16][i]=quinaIE;
        }
        else if(i==17){
            caminho[16][i]=quinaSD;
        }
        else{
            caminho[16][i]=reto;
        }
    }
    for(s=5;s<16;s++){
		caminho[s][10]=parede;
	}
    for(s=15;s<21;s++){
		caminho[s][19]=parede;
	}
    for(i=12;i<20;i++){
        if(i==12){
            caminho[14][i]=quinaIE;
        }
        else if(i==19){
            caminho[14][i]=quinaSD;
        }
        else{
            caminho[14][i]=reto;
        }
    }
    for(s=7;s<14;s++){
		caminho[s][12]=parede;
	}
    for(i=12;i<18;i++){
        if(i==12){
            caminho[6][i]=quinaSE;
        }
        else if(i==17){
            caminho[6][i]=quinaSD;
        }
        else{
            caminho[6][i]=reto;
        }
    }
    for(s=7;s<13;s++){
		caminho[s][17]=parede;
	}
    for(i=7;i<13;i++){
        if(i==12){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    caminho[3][12]=parede;
    for(i=12;i<20;i++){
        if(i==12){
            caminho[4][i]=quinaIE;
        }
        else if(i==19){
            caminho[4][i]=quinaSD;
        }else{
            caminho[4][i]=reto;
        }
    }
    for(s=5;s<11;s++){
        caminho[s][19]=parede;
    }
    for(i=19;i<27;i++){
        if(i==19){
            caminho[11][i]=quinaIE;
        }else if(i==26){
            caminho[11][i]=quinaID;
        }else{
            caminho[11][i]=reto;
        }
    }
    for(s=10;s>4;s--){
        caminho[s][26]=parede;
    } 
    for(s=14;s<20;s++){
        caminho[s][26]=parede;
    } 
    for(i=26;i<29;i++){
        if(i==26){
            caminho[20][i]=quinaIE;
        }else if(i==28){
            caminho[20][i]=quinaID;
        }else{
            caminho[20][i]=reto;
        }
    }
    for(s=16;s<20;s++){
        caminho[s][28]=parede;
    } 
    for(i=26;i>23;i--){
        if(i==26){
            caminho[4][i]=quinaSD;
        }else if(i==24){
            caminho[4][i]=quinaSE;
        }else{
            caminho[4][i]=reto;
        }
    }
    for(s=5;s<8;s++){
        caminho[s][24]=parede;
    }
    for(i=24;i>21;i--){
        if(i==24){
            caminho[8][i]=quinaID;
        }else if(i==22){
            caminho[8][i]=quinaIE;
        }else{
            caminho[8][i]=reto;
        }
    }
    for(i=26;i>16;i--){
        if(i==26){
            caminho[13][i]=quinaSD;
        }else if(i==17){
            caminho[13][i]=quinaIE;
        }else{
            caminho[13][i]=reto;
        }
    }
    for(s=10;s>=5;s--){    
        caminho[s][26]=parede;
    }
    for(s=7;s>2;s--){
        caminho[s][22]=parede;
    }
    for(i=22;i<29;i++){
        if(i==22){
            caminho[2][i]=quinaSE;
        }else if(i==28){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    for(s=3;s<=12;s++){    
        caminho[s][28]=parede;
    }
    for(i=28;i<34;i++){
        if(i==28){
            caminho[13][i]=quinaIE;
        }else if(i==33){
            caminho[13][i]=quinaID;
        }else{
            caminho[13][i]=reto;
        }
    }
    for(s=12;s>2;s--){    
        caminho[s][33]=parede;
    }
    for(i=33;i<39;i++){
        if(i==33){
            caminho[2][i]=quinaSE;
        }else if(i==38){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    for(s=3;s<19;s++){    
        caminho[s][38]=parede;
    }
    for(i=38;i<49;i++){
        if(i==38){
            caminho[19][i]=quinaIE;
        }else if(i==48){
            caminho[19][i]=quinaID;
        }else{
            caminho[19][i]=reto;
        }
    }
     for(s=18;s>11;s--){    
        caminho[s][48]=parede;
    }
    for(i=48;i>45;i--){
        if(i==48){
            caminho[11][i]=quinaSD;
        }else if(i==46){
            caminho[11][i]=quinaIE;
        }else{
            caminho[11][i]=reto;
        }
    }
    caminho[10][46]=parede;
    caminho[8][48]=parede;
    caminho[6][40]=parede;
    caminho[4][48]=parede;
    caminho[14][62]=parede;
    caminho[15][62]=parede;
    caminho[3][72]=parede;
    caminho[4][72]=quinaID;
    caminho[4][71]=quinaSE;
    caminho[19][62]=parede;
    caminho[20][62]=parede;
    caminho[10][53]=parede;
    caminho[4][36]=quinaSD;
    caminho[4][35]=quinaSE;
    for(i=48;i>45;i--){
        if(i==48){
            caminho[9][i]=quinaID;
        }else if(i==46){
            caminho[9][i]=quinaSE;
        }else{
            caminho[9][i]=reto;
        }
    }
    for(i=48;i>39;i--){
        if(i==48){
            caminho[7][i]=quinaSD;
        }else if(i==40){
            caminho[7][i]=quinaIE;
        }else{
            caminho[7][i]=reto;
        }
    }
    for(i=40;i<49;i++){
        if(i==48){
            caminho[5][i]=quinaID;
        }else if(i==40){
            caminho[5][i]=quinaSE;
        }else{
            caminho[5][i]=reto;
        }
    }
    for(i=48;i<57;i++){
        if(i==48){
            caminho[3][i]=quinaSE;
        }else if(i==56){
            caminho[3][i]=quinaSD;
        }else{
            caminho[3][i]=reto;
        }
    }
    for(s=4;s<16;s++){    
        caminho[s][56]=parede;
    }
    for(i=56;i<63;i++){
        if(i==56){
            caminho[16][i]=quinaIE;
        }else if(i==62){
            caminho[16][i]=quinaID;
        }else{
            caminho[16][i]=reto;
        }
    }
    for(i=59;i<63;i++){
        if(i==59){
            caminho[13][i]=quinaIE;
        }else if(i==62){
            caminho[13][i]=quinaSD;
        }else{
            caminho[13][i]=reto;
        }
    }
    for(s=5;s<13;s++){    
        caminho[s][59]=parede;
    }
    for(i=59;i<68;i++){
        if(i==59){
            caminho[4][i]=quinaSE;
        }else if(i==67){
            caminho[4][i]=quinaSD;
        }else{
            caminho[4][i]=reto;
        }
    }
    for(s=5;s<16;s++){    
        caminho[s][67]=parede;
    }
    for(i=67;i<70;i++){
        if(i==67){
            caminho[16][i]=quinaIE;
        }else if(i==69){
            caminho[16][i]=quinaID;
        }else{
            caminho[16][i]=reto;
        }
    }
    for(s=3;s<16;s++){    
        caminho[s][69]=parede;
    }
    for(i=69;i<73;i++){
        if(i==69){
            caminho[2][i]=quinaSE;
        }else if(i==72){
            caminho[2][i]=quinaSD;
        }else{
            caminho[2][i]=reto;
        }
    }
    for(s=5;s<18;s++){    
        caminho[s][71]=parede;
    }
    for(i=65;i<72;i++){
        if(i==65){
            caminho[18][i]=quinaIE;
        }else if(i==71){
            caminho[18][i]=quinaID;
        }else{
            caminho[18][i]=reto;
        }
    }
     for(s=7;s<18;s++){    
        caminho[s][65]=parede;
    }
     for(i=61;i<66;i++){
        if(i==61){
            caminho[6][i]=quinaSE;
        }else if(i==65){
            caminho[6][i]=quinaSD;
        }else{
            caminho[6][i]=reto;
        }
    }
     for(s=7;s<11;s++){    
        caminho[s][61]=parede;
    }
    for(i=61;i<65;i++){
        if(i==61){
            caminho[11][i]=quinaIE;
        }else if(i==64){
            caminho[11][i]=quinaSD;
        }else{
            caminho[11][i]=reto;
        }
    }
    for(s=12;s<19;s++){    
        caminho[s][64]=parede;
    }
     for(i=64;i<74;i++){
        if(i==64){
            caminho[19][i]=quinaIE;
        }else if(i==73){
            caminho[19][i]=quinaID;
        }else{
            caminho[19][i]=reto;
        }
    }
    for(s=6;s<19;s++){    
        caminho[s][73]=parede;
    }
    for(i=73;i<76;i++){
        if(i==73){
            caminho[5][i]=quinaSE;
        }else if(i==75){
            caminho[5][i]=quinaSD;
        }else{
            caminho[5][i]=reto;
        }
    }
    for(s=6;s<21;s++){    
        caminho[s][75]=parede;
    }
    for(i=62;i<76;i++){
        if(i==62){
            caminho[21][i]=quinaIE;
        }else if(i==75){
            caminho[21][i]=quinaID;
        }else{
            caminho[21][i]=reto;
        }
    }
    for(i=54;i<63;i++){
        if(i==54){
            caminho[18][i]=quinaIE;
        }else if(i==62){
            caminho[18][i]=quinaSD;
        }else{
            caminho[18][i]=reto;
        }
    }
    for(s=6;s<18;s++){    
        caminho[s][54]=parede;
    }
    for(i=50;i<55;i++){
        if(i==50){
            caminho[5][i]=quinaSE;
        }else if(i==54){
            caminho[5][i]=quinaSD;
        }else{
            caminho[5][i]=reto;
        }
    }
    for(s=6;s<10;s++){    
        caminho[s][50]=parede;
    }
    for(i=50;i<54;i++){
        if(i==50){
            caminho[9][i]=quinaIE;
        }else if(i==53){
            caminho[9][i]=quinaSD;
        }else{
            caminho[9][i]=reto;
        }
    }
    for(i=50;i<54;i++){
        if(i==50){
            caminho[11][i]=quinaSE;
        }else if(i==53){
            caminho[11][i]=quinaID;
        }else{
            caminho[11][i]=reto;
        }
    }
    for(s=12;s<21;s++){    
        caminho[s][50]=parede;
    }
    for(i=36;i<51;i++){
        if(i==36){
            caminho[21][i]=quinaIE;
        }else if(i==50){
            caminho[21][i]=quinaID;
        }else{
            caminho[21][i]=reto;
        }
    }
    for(s=5;s<21;s++){    
        caminho[s][36]=parede;
    }
    for(s=5;s<15;s++){    
        caminho[s][35]=parede;
    }
    for(i=28;i<36;i++){
        if(i==28){
            caminho[15][i]=quinaSE;
        }else if(i==35){
            caminho[15][i]=quinaID;
        }else{
            caminho[15][i]=reto;
        }
    }
	for(s=0;s<23;s++){
        printf("%c", 179);
        for(i=0;i<77;i++){
			printf("%c",caminho[s][i]);
		}	
        printf("%c\n", 179);
	}
	printf("%c", 192);
	for(s=0;s<77;s++){printf("%c",196);}
   	printf("%c", 217);
}
int main(){
    //menu
    int s,i;
    do{
        int a,b,L,L2;
        inicio:
        opcao=0;
        L=2;L2=2;b=2;
        system("cls"); 
        system("color 0B"); 
        printf("     O Labirinto Fantasma!");
        system("color 0B");
        printf("\n\n     1 - JOGAR \n     2 - COMO JOGAR \n     3 - HISTORIA DO LABIRINTO \n     4 - MAPA\n     5 - SAIR");
        do{
            gotoxy(1,L);
            printf("  >");
            gotoxy(12,8);
            if(kbhit){a=getch();}
            if(a == 80){     
                _beep(400,100); /*seta p/baixo*/
                L2=L;L++;b++;
                if(b>6){b=2;L=2;}
            }
            if(a == 72){ 
                  _beep(300,100);    /*seta p/cima */
                L2=L;L--;b--;
                if(b<2){b=5;L+=4;}
            }
            if(L!=L2){gotoxy(1,L2);printf("    ");L2=L;}
            if(a == 13){
                 _beep(500,100);
                 opcao=b-1;}
        }while(opcao == 0);
    switch (opcao) {
    case 1:
        system("cls");
	    campo(tabuleiro, caminho);
	    ganhou = movimento(caminho);
        system("cls");
        if(ganhou == 1){
            printf("\n Parabens!!\n Voce ajudou a encontrar o tesouro!!\n");
        printf("\n Numero de mortes: %d\n", morte);
        printf("\n\n Pressione ESC Para Voltar Ao Menu Principal");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);}
        else{
            goto inicio;
        }
        
        break;
    case 2:
        system("cls");
        printf("Como Jogar!");
        printf("\n\nPara jogar 'O Labirinto Fantasma' eh necessario compreender os seguintes passos:");
        printf("\n1 - Utilize as setas para sua locomocao pelo mapa!");
        printf("\n2 - O mapa estara invisivel, portanto voce nao vera as paredes do labirinto!!");
        printf("\n3 - Ao esbarrar em uma parede, seu personagem morre, volta ao inicio e a parede aparecera no mapa.");
        printf("\n4 - Aperte 'esc' para sair a qualquer momento!");
        printf("\n5 - Tente concluir o percurso no menor numero de mortes possivel!!!");
        printf("\n\nBoa Sorte!!!");
        
        printf("\nPressione ESC Para Voltar Ao Menu Principal");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 3:
        system("cls");
        historia();
        /*Sleep(3000);*/
        printf("\nPressione ESC Para Voltar Ao Menu Principal");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 4:
        system("cls");
        char caminho[25][77];
        mapa(caminho);
        printf("\nPressione ESC Para Voltar Ao Menu Principal");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 5:
        system("cls");
        printf("Voce pediu para sair, obrigado por jogar...");
        for(a=0;a<10;a++){
            printf(".");
            Sleep(300);
        }
        printf("!\n\n");
		exit(0);
            
    default:
        printf("Você deve escolher uma opção válida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
        }
    }while(opcao != 5);
    return 0;
}

int historia(){
    printf("Era uma vez, um reino encantado chamado Bradland....");
    Sleep(8000);
    system("cls");
    Sleep(500);
    printf("A familia real vivia tranquilamente, quando um jovem desconhecido surge nos arredores de Bradland....");
    Sleep(8000);
    system("cls");
    Sleep(500);
    printf("A princesa do reino se apaixona por esse desconhecido, porem a familia real nao aceita muito bem....");
    Sleep(8000);
    system("cls");
    Sleep(500);
    printf("O rei arthur terceiro diz ao jovem rapaz que para ser digno de casar com a princesa... ");
    printf("\nEle tera que passar pelo labirinto fantasma e pegar o tesouro escondido!");
    Sleep(8000);
    system("cls");
    Sleep(500);
    printf("O jovem entao parte em busca do tesouro no fim do labirinto, ajude-o a achar!!\n\n");
    Sleep(8000);
}
	

movimento(char caminho[24][77]){
	inicio:;
    int X=1,C=1,C2=1,Y=2,L=4,L2=4,a;
	do{
	gotoxy(C,L);
	printf("O");
	if(kbhit){
	a=getch();
	}
	if(a == 80 && Y < AlturaMax){
        if (caminho[L][C-1]!='*'){
			gotoxy(C,L2+1);
            printf("%c",caminho[L][C-1]);
            gotoxy(C,L2);
        	printf(" ");
        	L2=L;
            morte++;
            goto inicio;
        }
        L2=L;
        L++;
        Y++;
    }/*seta p/baixo*/
	if(a == 72 && Y > AlturaMin){
         if (caminho[L-2][C-1]!='*'){
			gotoxy(C,L2-1);
            printf("%c",caminho[L-2][C-1]);
            gotoxy(C,L2);
        	printf(" ");
        	L2=L;
            morte++;
            goto inicio;
        }
        else if(tabuleiro[L-2][C-1]=='$'){
            return ganhou = 1;
        }
        L2=L;
        L--;
        Y--;
    }/*seta p/cima */
	if(a == 75 && X > ComprimentoIncio){
        if(caminho[L-1][C-2]!='*'){
			gotoxy(C-1,L2);
            printf("%c",caminho[L-1][C-2]);
            gotoxy(C,L2);
        	printf(" ");
        	L2=L;
            morte++;
			goto inicio;
		}
        C2=C;
        C--;
        X--;
    }/*esqueda*/
	if(a == 77 && X < Comprimento){
        if(caminho[L-1][C]!='*'){
			printf("%c",caminho[L-1][C]);
			gotoxy(C,L2);
        	printf(" ");
        	L2=L;
            morte++;
			goto inicio;
		}
		C2=C;
        C++;
        X++;
    }/*direita*/
	if(L!=L2){
        gotoxy(C,L2);
        printf(" ");
        L2=L;
    }
	if(C!=C2){
        gotoxy(C2,L2);
        printf(" ");
        C2=C;
    }
    if (a==27){
        ganhou = 2;
    }
	}while(ganhou == 0);
}

