#include"graphics.h"
#include<math.h>
#include<stdlib.h>
#define COLOR(r,g,b) (r| (g << 8)|(b << 16)|0x0F000000)
void snowflake(int x, int y, int r, int c)
{
    setcolor(c);
    moveto(x, y - 2 * r);
    lineto(x, y + 2 * r);

    moveto(x - 2 * r, y);
    lineto(x + 2 * r, y);

    moveto(x - r, y - r);
    lineto(x + r, y + r); 
     
    moveto(x - r, y + r);
    lineto(x + r, y - r);

}
float main()
{
    int x[100], y[100], r[100], color;
    initwindow(1920/1.25, 1080/1.25);
    do
    {
        for (int i = 0; i < 100; i++)
        {
            r[i] = rand() % 20 + 10;
            x[i] = rand() % 1920/1.25 - 20;
            y[i] = rand() % 1080/1.25 - 20;
            color = rand() % 15 + 1;
            delay(5);
            snowflake(x[i], y[i], r[i], color);
            delay(5);
        }
        for (int i = 0; i < 100; i++)
        {
            snowflake(x[i], y[i], r[i], 0);
            delay(5);
        }
    } while (!kbhit());
    getch();
    closegraph();
}