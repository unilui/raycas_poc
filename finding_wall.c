#include <math.h>
#include <stdio.h>

#define PLAYER_Y 224
#define PLAYER_X 96

double radians(int nbr)
{
	return (nbr * (M_PI / 180));
}

int main (void)
{
	//If the ray is facing up
	int a_y = floor(PLAYER_Y / 64) * 64 - 1;
	printf("A_y = %d\n", a_y);
	// if the ray is facing down
	//int a_y = floor(PLAYER_Y/64) * 64 + 64;

	int a_x = 96 + ((PLAYER_Y - a_y) / tan(radians(57)));
	printf("A_x = %d\n", a_x);
}
