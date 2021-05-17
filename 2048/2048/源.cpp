#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int map[4][4] = { 0 };//整个2048游戏图
int cnt = 0;

//打印输出map
void printMap(void)
{
	printf("------------------\n");
	for (int i = 0; i < 4; i++)
	{
		printf("|");
		for (int j = 0; j < 4; j++)
		{
			
			printf("%3d", map[i][j]);
			printf("|");
		}
		printf("\n------------------\n");
	}
}

//用于初始化最开始的map
void initMap(void)
{
	int firstNum_i , firstNum_j, secondNum_i, secondNum_j;
	//产生两个初始坐标
	//第一个坐标
	firstNum_i = rand() % 4;//坐标数值大小为0 ~ 3
	firstNum_j = rand() % 4;
	//第二个坐标
	secondNum_i = rand() % 4;//坐标数值大小为0 ~ 3
	secondNum_j = rand() % 4;

	//如果两个坐标相同，第二个坐标重新生成
	while (firstNum_i == secondNum_i && firstNum_j == secondNum_j)
	{
		secondNum_i = rand() % 4;//坐标数值大小为0 ~ 3
		secondNum_j = rand() % 4;
	}

	map[firstNum_i][firstNum_j] = 2;
	map[secondNum_i][secondNum_j] = 2;
	cnt = 2;

}
//产生新的随机位置
void createNum(void)
{
	int i, j;

	i = rand() % 4;
	j = rand() % 4;

	while (map[i][j])
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	map[i][j] = 2;


}


//向上移动
void up(void)
{
	int cnt_last = 0;
	
	
	//按照规则移动每个格子
	for(int i = 0;i<4;i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向上移动操作
				for (int k = i; k > 0; k--)
				{
					
					if (map[k - 1][j] != 0)//判断与该坐标向上相邻的坐标值是否相等
						break;
					map[k-1][j] = map[k][j];
					map[k][j] = 0;
				}
				
			}
		}
	//合并相同的数字
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i + 1][j])
			{
				map[i][j] *= 2;
				map[i+1][j] = 0;
				cnt--;
			}

		}
	//按照规则移动每个格子
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向上移动操作
				for (int k = i; k > 0; k--)
				{

					if (map[k - 1][j] != 0)//判断与该坐标向上相邻的坐标值是否相等
						break;
					map[k - 1][j] = map[k][j];
					map[k][j] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}

}
//向下移动
void down(void)
{
	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向下移动操作
				for (int k = i; k < 3; k++)
				{

					if (map[k + 1][j] != 0)//判断与该坐标向下相邻的坐标值是否相等
						break;
					map[k + 1][j] = map[k][j];
					map[k][j] = 0;
				}

			}
		}
	//合并相同的数字
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i + 1][j])
			{
				map[i][j] *= 2;
				map[i+1][j] = 0;
				cnt--;
			}

		}

	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向下移动操作
				for (int k = i; k < 3; k++)
				{

					if (map[k + 1][j] != 0)//判断与该坐标向下相邻的坐标值是否相等
						break;
					map[k + 1][j] = map[k][j];
					map[k][j] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}
}
//向左移动
void left(void)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向右移动操作
				for (int k = j; k > 0 ;k--)
				{

					if (map[i][k-1] != 0)//判断与该坐标向下相邻的坐标值是否相等
						break;
					map[i][k - 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	//合并相同数字
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i ][j+1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
				cnt--;
			}

		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向右移动操作
				for (int k = j; k > 0; k--)
				{

					if (map[i][k - 1] != 0)//判断与该坐标向下相邻的坐标值是否相等
						break;
					map[i][k - 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}
}
//向右移动
void right(void)
{
	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向下移动操作
				for (int k = j; k < 3; k++)
				{

					if (map[i][k + 1] != 0)//判断与该坐标向下相邻的坐标值是否相等
						break;
					map[i][k + 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	//合并相同数字
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i][j + 1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
				cnt--;
			}

		}

	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//找到一个不为零的坐标
			{
				//向下移动操作
				for (int k = j; k < 3; k++)
				{

					if (map[i][k + 1] != 0)//判断与该坐标向下相邻的坐标值是否相等
						break;
					map[i][k + 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}

}
//true为游戏结束
//false游戏未结束
bool isOver(void)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == map[i][j + 1])return false;
			if (map[i][j] == map[i + 1][j])return false;

		}
	return true;
}
void move(char key)
{
	switch (key)
	{	
	case 'w':
	case 'W':up(); break;
	case 's':
	case 'S':down(); break;
	case 'a':
	case 'A':left(); break;
	case 'd':
	case 'D':right(); break;
	case 'q':
	case 'Q':exit(0);
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	char key = 0;
	initMap();
	while (1)
	{
		printMap();
		if (_kbhit)
		{
			key = _getch();
			
			system("cls");
		}
		if (true == isOver())
			break;
		move(key);
		cout << "key = " << key << endl;
		
		
	}
	cout << "游戏结束" << endl;
	
	return 0;
	
}