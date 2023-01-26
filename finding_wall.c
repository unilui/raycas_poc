#include <math.h>
#include <stdio.h>

#define PLAYER_Y 224
#define PLAYER_X 96

#define MAP_WIDTH 7
#define MAP_HEIGHT 7

int worldMap[MAP_WIDTH][MAP_HEIGHT]=
{
	{1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1},
};

double radians(int nbr)
{
	return (nbr * (M_PI / 180));
}

void horizontal_check(int angle)
{
	int	a_y;

	if (angle < 180)
		a_y = floor(PLAYER_Y / 64) * 64 - 1; // ray facing up
	else
		a_y = floor(PLAYER_Y / 64) * 64 + 64; // ray facing down


	int a_x = PLAYER_X + ((PLAYER_Y - a_y) / tan(radians(angle)));
	printf("A_x = %d\n", a_x / 64);
	printf("A_y = %d\n", a_y / 64);
	if (a_x < 0 || a_x > MAP_WIDTH - 1)
		return (0);
	if (a_y < 0 || a_y > MAP_HEIGHT - 1)
		return (0);
}

void vertical_check(int angle)
{
	int b_x;

	if (angle < 90 || angle > 270)
		b_x = floor(PLAYER_X / 64) * (64) + 64; // ray facing right
	else
		b_x = floor(PLAYER_X / 64) * (64) - 1; // ray facing left
	printf("b_x = %d\n", b_x / 64);

	int b_y = PLAYER_Y + (PLAYER_X - b_x) * tan(radians(angle));
	printf("b_y = %d\n", b_y / 64);
	if (b_x < 0 || b_x > MAP_WIDTH - 1)
		return (0);
	if (b_y < 0 || b_y > MAP_HEIGHT - 1)
		return (0);
}

int main (void)
{
	int degrees;

	degrees = 84;
	if (degrees != 0 && degrees != 180)
	{
		horizontal_check(degrees);
	}
	if (degrees != 90 && degrees != 270)
	{
		vertical_check(degrees);
	}
}
