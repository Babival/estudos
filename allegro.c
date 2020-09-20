#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>

#define COLOR_BITS 32
#define CORROSA (makecol(205,205,200))
#define IMAGENAME "teste.bmp"
 
  int main(void)
  {
      allegro_init();
 
      BITMAP *buff;
      PALETTE pal;
      get_palette(pal);
      // Create a buffer for smooth animation.
 
      buff = create_bitmap(320,240);
      if(buff == NULL)
  {
    printf("Could not create buffer!\n");
    exit(EXIT_FAILURE);
  } 
     
      set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0); /*tamanho da tela*/
      set_color_depth(COLOR_BITS);
      set_window_title("teste allegro");
      install_keyboard();
      install_timer();

//      while(!key[KEY_ESC])
  //    {
      circlefill(buff, 400, 250, 50, makecol(205, 205, 200));
   textprintf_ex(buff, font, 50, 50, CORROSA , CORROSA, "Teste do circulo.");


      
      save_bitmap(IMAGENAME, buff, pal);
      destroy_bitmap(buff);
      
      allegro_exit();

      printf("Imagem %s salva com sucesso!\n", IMAGENAME);
      return EXIT_SUCCESS;
 
      END_OF_MAIN();
 }




