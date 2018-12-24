#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <complex.h>
#include <stdio.h>
#include <math.h>

double width=700;height=700;
double xMin=-2.5,xMax=2.5;
double yMin=-2.5,yMax=2.5;
double Cx,Cy,escapeRatio=2.0;
int MaxIterations=100;
complex z,c;

void Mandelbrot()
{
    double PWidth=(xMax-xMin)/width;
    double PHeight=(yMax-yMin)/height;
    for(int y=0;y<height;y++)
    {
        Cy=yMin+y*PHeight;
        for(int x=0;x<width;x++)
        {
            ALLEGRO_COLOR pixelColor=al_map_rgb(0,0,0);
            Cx=xMin+x*PWidth;
            c=Cy+Cx*I;
            z=c; //
            int iteracion;
            for(iteracion=0;iteracion<MaxIterations &&
            (creall(z)*creall(z))+(cimagl(z)*cimagl(z))<escapeRatio*escapeRatio;iteracion++)
            {
                z=z*z+c;//Cambiar esta funcion para diferentes resultados
            }
            if(iteracion==MaxIterations)
            {
                pixelColor = al_map_rgb(255,255,255);//black
            }
            else
            {
                if(iteracion>=1)
                pixelColor = al_map_rgb((255/100)*iteracion,(255/100)*iteracion,(255/100)*iteracion);

            }
            al_draw_pixel(y,x,pixelColor);
        }
    }
}

int main(int argc, char **argv){

    //Create Display
    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    display = al_create_display(1366, 768);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
    al_clear_to_color(al_map_rgb(255,255,255));

    al_init_primitives_addon();

    Mandelbrot();

    al_flip_display();


    al_rest(10000.0);

    al_destroy_display(display);

    return 0;
}
