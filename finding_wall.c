#include <math.h>
#include <stdio.h>

#define BOX_SIZE 64

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

int horizontal_hit(int angle)
{
	int	next_box_y;
	int	next_box_x;
	int	delta_y;
	int	delta_x;
	int	direction;
	int	correction;

	if (angle < 180) // ray facing up
	{
		correction = -1;
		direction = -1;
	}
	else // ray facing down
	{
		correction = BOX_SIZE;
		direction = 1;
	}
	delta_y = BOX_SIZE * direction;
	delta_x = BOX_SIZE / tan(radians(angle)); // add pre build table
	next_box_y = floor(PLAYER_Y / BOX_SIZE) * BOX_SIZE + correction;
	next_box_x = PLAYER_X + ((PLAYER_Y - next_box_y) / tan(radians(angle)));
	printf("A_x = %d\n", next_box_x);
	printf("A_y = %d\n", next_box_y);

	if (next_box_x / 64 < 0 || next_box_x / 64 > MAP_WIDTH - 1)
		return (0);
	if (next_box_y / 64 < 0 || next_box_y / 64 > MAP_HEIGHT - 1)
		return (0);
}

int vertical_hit(int angle)
{
	int b_x;

	if (angle < 90 || angle > 270)
		b_x = floor(PLAYER_X / BOX_SIZE) * (BOX_SIZE) + BOX_SIZE; // ray facing right
	else
		b_x = floor(PLAYER_X / BOX_SIZE) * (BOX_SIZE) - 1; // ray facing left
	printf("b_x = %d\n", b_x / BOX_SIZE);

	int b_y = PLAYER_Y + (PLAYER_X - b_x) * tan(radians(angle));
	printf("b_y = %d\n", b_y / BOX_SIZE);
	if (b_x < 0 || b_x > MAP_WIDTH - 1)
		return (0);
	if (b_y < 0 || b_y > MAP_HEIGHT - 1)
		return (0);
}

int main (void)
{
	int degrees;

	degrees = 60;
	if (degrees != 0 && degrees != 180)
		horizontal_hit(degrees);
	if (degrees != 90 && degrees != 270)
		vertical_hit(degrees);
}
