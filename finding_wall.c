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

typedef struct s_hitbox
{
	int	y;
	int	x;
	int	delta_y;
	int	delta_x;
} t_hitbox;

t_hitbox	next_hhitbox (int angle)
{
	t_hitbox	hitbox;
	int			correction;
	int			direction;

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
	hitbox.delta_y = BOX_SIZE * direction;
	hitbox.delta_x = BOX_SIZE / tan(radians(angle)); // add pre build table
	hitbox.y = floor(PLAYER_Y / BOX_SIZE) * BOX_SIZE + correction;
	hitbox.x = PLAYER_X + ((PLAYER_Y - hitbox.y) / tan(radians(angle)));
	return (hitbox);
}

int horizontal_hit(int angle)
{
	t_hitbox	hitbox;
	int			box_y;
	int			box_x;

	hitbox = next_hhitbox(angle);

	while (1)
	{
		box_y = hitbox.y / BOX_SIZE;
		box_x = hitbox.x / BOX_SIZE;
		if (box_x < 0 || box_x > MAP_WIDTH - 1)
			return (0);
		if (box_y < 0 || box_y > MAP_HEIGHT - 1)
			return (0);
		if (worldMap[box_x][box_y] == 1)
		{
			printf("A_x = %d\n", hitbox.x / 64);
			printf("A_y = %d\n", hitbox.y / 64);
			break ;
		}
		hitbox.y += hitbox.delta_y;
		hitbox.x += hitbox.delta_x;
	}
	return (0);
}

t_hitbox	next_vhitbox (int angle)
{
	t_hitbox	hitbox;
	int			correction;
	int			direction;

	if (angle < 90 || angle > 270) // ray facing right
	{
		correction = BOX_SIZE;
	}
	else // ray facing left
	{
		correction = -1;
	}
	hitbox.x = floor(PLAYER_X / BOX_SIZE) * (BOX_SIZE) + correction;
	return (0);
}

int vertical_hit(int angle)
{
	int b_x;

	if (angle < 90 || angle > 270)
		b_x = floor(PLAYER_X / BOX_SIZE) * (BOX_SIZE) + BOX_SIZE;
	else
		b_x = floor(PLAYER_X / BOX_SIZE) * (BOX_SIZE) - 1;
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
