#include <windows.h>
#include <stdio.h>
#include <conio.h>

//screen: goto [x,y]
void gotoXY (int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void resizeConsole(int width, int height);
void ShowScrollbar(BOOL Show);
void DisableResizeWindow();
void SetConsole();
void SetFontSize(int size);
void TextColor (int color);
void setColor(int Background_color, int Text_color);
