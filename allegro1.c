#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
#define COLOR_BITS 32 
#define Y 400
#define X 250
#define W 200
#define Z 450

int main (void)
{

	allegro_init();
	install_timer();
	install_keyboard();
	set_color_depth(COLOR_BITS);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0); 
	set_window_title("teste alegro");

	int x = 200, y=400; //final da linha

	int i=0;

	while(!key[KEY_ESC])
	{

		if(x>=W && x<=X) 
		{		
		    if (y >=Y && y<=Z)
		    {
			if(y<Z && (x+y)%2 == 0)  /* primeiro quadrante(90 -0 graus) */
				y++;
			if(x<300 && (x+y)%2 != 0)
				x++;
		    }
		    else 
		    
			if(y >= 350 && y <= 400)
			{	   
			    if(y<400 && (x+y)%2 == 0)  /* segundo quadrante */
				y++;
			    if(x>250 && (x+y)%2 != 0)
				x--;
		        }
		    
		}
		if((x >= 250 && x<=300) && (y <= 450 && y>= 400))
		{
			if(y>400 && (x+y)%2 != 0)  /* quarto quadrante(360 - 270) */
				y--;
			if(x>200 && (x+y)%2 == 0)
				x++;
		}

		if(y<=400 && y>=350)// && (x <= 300 && x >= 250)) 
		{
			if(y>300 && (x+y)%2 != 0)  /* terceiro quadrante para segundo(270 - 180) (antes na comparacao era 350)  */
				y--;
			if(x>250 && (x+y)%2 == 0)
				x--;
		} 

/*		if((x<=250 && x>=200) && (y >= 350 && y <= 400))
		{   
			if(y<400 || (x+y)%2 == 0)  / * segundo quadrante * /
				y++;
			if(x>250 || (x+y)%2 != 0)
				x--;

		}
*/
		for(i=0;i<100;i+=10)
		{	
			circlefill(screen, 400, 250, 1, makecol(205, 205, 200));
			line(screen, Y, X, y+i, x+i, 3000); //inicio da linha Y e X, fim da linha e grossura

			circlefill(screen, y+i, x+i, 1, makecol(205, 205, 200));

			line(screen, y+i, x+i, (y+30+i), (x-30+i), 3000); //inicio da linha Y e X, fim da linha e grossura
			for(int j=0;j<10;j++)
			{
				circlefill(screen, (y+30+i+j), (x-30+i+j), 1, makecol(255, 0, 200));
			}
		}
		rest(50);  //nao ficar piscando (velocidade)
		clear(screen); // apagar o rastro
	}
	return 0;

	END_OF_MAIN();

}
