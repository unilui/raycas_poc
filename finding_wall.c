#include <math.h>
#include <stdio.h>

#define BOX_SIZE 64

#define PLAYER_Y 224
#define PLAYER_X 160

#define ALTURA 7
#define LARGURA 5

int worldMap[ALTURA][LARGURA]=
{
	{1,1,1,1,1},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,1,1,1,1}
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
	int			y_direction;
	int			x_direction;

	if (angle < 180) // ray facing up
	{
		correction = -1;
		y_direction = -1;
		x_direction = 1;
	}
	else // ray facing down
	{
		correction = BOX_SIZE;
		y_direction = 1;
		x_direction = -1;
	}
	hitbox.delta_y = BOX_SIZE * y_direction;
	hitbox.delta_x = BOX_SIZE / tan(radians(angle)) * x_direction;
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
		if (box_x < 0 || box_x > LARGURA - 1)
			return (0);
		if (box_y < 0 || box_y > ALTURA - 1)
			return (0);
		if (worldMap[box_y][box_x] == 1)
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
	int			x_direction;
	int			y_direction;

	if (angle < 90 || angle > 270) // ray facing right
	{
		correction = BOX_SIZE;
		x_direction = 1;
		y_direction = -1;
	}
	else // ray facing left
	{
		correction = -1;
		x_direction = -1;
		y_direction = 1;
	}
	hitbox.delta_x = BOX_SIZE * x_direction;
	hitbox.delta_y = BOX_SIZE * tan(radians(angle)) * y_direction;
	hitbox.x = floor(PLAYER_X / BOX_SIZE) * (BOX_SIZE) + correction;
	hitbox.y = PLAYER_Y + (PLAYER_X - hitbox.x) * tan(radians(angle));
	return (hitbox);
}

int vertical_hit(int angle)
{
	t_hitbox	hitbox;
	int			box_y;
	int			box_x;

	hitbox = next_vhitbox(angle);

	while (1)
	{
		box_y = hitbox.y / BOX_SIZE;
		box_x = hitbox.x / BOX_SIZE;
		if (box_x < 0 || box_x > LARGURA - 1)
			return (0);
		if (box_y < 0 || box_y > ALTURA - 1)
			return (0);
		if (worldMap[box_y][box_x] == 1)
		{
			printf("b_x = %d\n", hitbox.x / 64);
			printf("b_y = %d\n", hitbox.y / 64);
			break ;
		}
		hitbox.y += hitbox.delta_y;
		hitbox.x += hitbox.delta_x;
	}
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
