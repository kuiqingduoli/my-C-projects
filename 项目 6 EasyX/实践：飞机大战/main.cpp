#include <stdio.h>
#include <easyx.h>
#include <time.h> 
#include <stdlib.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

enum MY
{
	WIDTH=590,//窗口宽度和高度 
	HEIGHT=800,
	playerWidth=117,//玩家图片尺寸
    playerHeight=120,
    bulletWidth=19,//炮弹图片尺寸 
    bulletHeight=24,
    bigEnemyWidth=104,//大敌机图片尺寸 
    bigEnemyHeight=148,
    smallEnemyWidth=52,//小敌机图片尺寸
    smallEnemyHeight=39,
    BIG,
    SMALL,
    BULLET_NUM=15,//玩家炮弹数量
    ENEMY_NUM=20//敌机数量 
};

struct Plance//飞机结构
{
	int x;//坐标 
	int y;
	int vx;
	int vy;
	int speed;
	int hp;
	int type; 
	bool life;//是否存活 
}player,bullet[BULLET_NUM],enemy[ENEMY_NUM];

IMAGE bk;//背景图片
IMAGE img_role[2];//玩家图片 
IMAGE img_bullet[2];//子弹图片 
IMAGE img_enemy[2][2];//敌机图片 

int lastFireTime = 0;  // 上次发射子弹的时间
int fireInterval = 300;  // 发射间隔(毫秒)
int lastEnemyTime = 0;  // 上次生成敌机的时间
int enemyInterval = 1000;  // 敌机生成间隔(毫秒)
bool gameOver = false;  // 游戏结束标志

// 播放音频文件
void playSound(const char* filename, bool repeat = false)
{
    char cmd[256];
    if (repeat) {
        // 循环播放（用于背景音乐）
        sprintf(cmd, "open \"%s\" alias mymusic", filename);
        mciSendString(cmd, NULL, 0, NULL);
        mciSendString("play mymusic repeat", NULL, 0, NULL);
    } else {
        // 播放一次（用于音效）
        sprintf(cmd, "play \"%s\"", filename);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

// 停止播放
void stopSound()
{
    mciSendString("close mymusic", NULL, 0, NULL);
}

void loadImg()
{
	loadimage(&bk,"图片音频/背景.jpg");//加载背景图片 
	loadimage(&img_role[0],"图片音频/我方1.jpg");//加载玩家图片 
	loadimage(&img_role[1],"图片音频/我方2.jpg");
	loadimage(&img_bullet[0],"图片音频/炮弹1.jpg");//加载炮弹图片
	loadimage(&img_bullet[1],"图片音频/炮弹2.jpg"); 
	loadimage(&img_enemy[0][0],"图片音频/敌机1.jpg"); //加载大敌机图片 
	loadimage(&img_enemy[0][1],"图片音频/敌机2.jpg"); 
	loadimage(&img_enemy[1][0],"图片音频/敌人1.jpg"); //加载小敌机图片 
	loadimage(&img_enemy[1][1],"图片音频/敌人2.jpg"); 
}

//设置敌机血量 
void enemyHp(int i)
{
	if(rand()%10==0||rand()%10==1||rand()%10==2)  //0-9
	{
		enemy[i].type=BIG;
		enemy[i].hp=3;
	}else
	{
		enemy[i].type=SMALL;
		enemy[i].hp=1;
	}
}

//初始数据 
void gameInit()
{
	srand(time(NULL));  // 初始化随机数种子
	
	loadImg();
	//初始化玩家 
	player.x=(WIDTH-playerWidth)/2;
	player.y=HEIGHT-playerHeight;
	player.life=true;
	player.vx=0;
	player.vy=0;
	player.speed=5;
	
	//初始化子弹 
	for(int i=0;i<BULLET_NUM;i++)
	{
		bullet[i].x=0;
        bullet[i].y=0;
		bullet[i].vx=0;
        bullet[i].vy=-1;  // 子弹向上移动
        bullet[i].speed=5;  // 设置子弹速度
		bullet[i].life=false;
	}
	
	//初始化敌机
	for(int i=0;i<ENEMY_NUM;i++) 
	{
		enemy[i].x=0;
        enemy[i].y=0;
		enemy[i].vx=0;
        enemy[i].vy=1;  //敌机向下移动
        enemy[i].speed=0;  //初始化速度
		enemy[i].life=false;
		enemyHp(i);
	}
}

//产生炮弹 
void bulletCreate()
{
	int currentTime = clock();  // 获取当前时间
	
	// 检查是否达到发射间隔
	if (currentTime - lastFireTime >= fireInterval)
	{
		for(int i=0;i<BULLET_NUM;i++)
		{
			// 找到空闲的子弹槽
			if(!bullet[i].life)
			{
				bullet[i].life=true;
				// 子弹从飞机中部发射
				bullet[i].x=player.x+playerWidth/2-bulletWidth/2;  // 减去子弹宽度的一半使其居中
				bullet[i].y=player.y;
				lastFireTime = currentTime;  // 更新上次发射时间
				// 播放发射子弹音效
                playSound("图片音频/发射.mp3"); 
				break;  // 一次只发射一颗子弹
			}
		}
	}
}

//产生敌机 
void enemyCreate()
{
	int currentTime = clock();  // 获取当前时间
	
	// 检查是否达到生成间隔
	if (currentTime - lastEnemyTime >= enemyInterval)
	{
		for(int i=0;i<ENEMY_NUM;i++) 
		{
			if(!enemy[i].life)
			{
				enemy[i].life=true;
				enemyHp(i);  // 重新设置敌机类型和血量
				
				// 根据敌机类型设置尺寸
				int enemyWidth, enemyHeight;
				if(enemy[i].type == BIG) {
					enemyWidth = bigEnemyWidth;
					enemyHeight = bigEnemyHeight;
				} else {
					enemyWidth = smallEnemyWidth;
					enemyHeight = smallEnemyHeight;
				}
				
				//不超出左右边界
				enemy[i].x = rand() % (WIDTH - enemyWidth);
				enemy[i].y = -enemyHeight;  // 从屏幕上方开始出现
				
				// 根据类型设置不同速度
				if(enemy[i].type == BIG) {
					enemy[i].speed = 1;  // 大敌机速度较慢
				} else {
					enemy[i].speed = 3;  // 小敌机速度较快
				}
				
				lastEnemyTime = currentTime;  // 更新上次生成时间
				break;  // 一次只生成一个敌机
			}
		}
	}
}

//绘制画面 
void gameDraw() 
{
	putimage(0,0,&bk);
	putimage(player.x,player.y,&img_role[0],NOTSRCERASE);
	putimage(player.x,player.y,&img_role[1],SRCINVERT);
	
	// 绘制所有激活的子弹
	for(int i=0;i<BULLET_NUM;i++)
	{
		if(bullet[i].life)
		{
			putimage(bullet[i].x,bullet[i].y,&img_bullet[0],NOTSRCERASE);
			putimage(bullet[i].x,bullet[i].y,&img_bullet[1],SRCINVERT);
		}
	}
	//绘制敌机
	for(int i=0;i<ENEMY_NUM;i++)
	{
		if(enemy[i].life)
		{
			if(enemy[i].type==BIG)//大敌机 
			{
				putimage(enemy[i].x,enemy[i].y,&img_enemy[0][0],NOTSRCERASE);
				putimage(enemy[i].x,enemy[i].y,&img_enemy[0][1],SRCINVERT);
			}else//小敌机 
			{
				putimage(enemy[i].x,enemy[i].y,&img_enemy[1][0],NOTSRCERASE);
				putimage(enemy[i].x,enemy[i].y,&img_enemy[1][1],SRCINVERT);
			}
		}
	}
	
	// 如果游戏结束，显示游戏结束文字
	if(gameOver)
	{
		setfillcolor(WHITE);
		int w1=200,h1=50;
		int x1=(WIDTH-w1)/2;
		int y1=(HEIGHT-h1)/2;
		fillrectangle(x1,y1,x1+w1,y1+h1);
		int w2=120,h2=40;
		int x2=(WIDTH-w2)/2;
		int y2=(HEIGHT-h2+100)/2;
		fillrectangle(x2,y2,x2+w2,y2+h2);
		settextcolor(RED);
		setbkmode(TRANSPARENT);
		char s1[10]="游戏结束";
		char s2[20]="按任意键退出";
		settextstyle(40, 0, ("宋体"));
		outtextxy(x1+(w1-textwidth(s1))/2,y1+(h1-textheight(s1))/2, s1);
		settextstyle(20, 0, ("宋体"));
		outtextxy(x2+(w2-textwidth(s2))/2,y2+(h2-textheight(s2))/2, s2); 
	}
	 
}
ExMessage msg={0};

//角色移动
void playerMove() 
{
	peekmessage(&msg, EX_KEY, true);  // 使用true参数，清空消息队列
    if (msg.message == WM_KEYDOWN)
    {
        switch(msg.vkcode)
        {
            case VK_UP:
            case 'W':
                player.vy = -1;
                break;
            case VK_DOWN:
            case 'S':
                player.vy = 1;
                break;
            case VK_LEFT:
            case 'A':
                player.vx = -1;
                break;
            case VK_RIGHT:
            case 'D':
                player.vx = 1;
                break;
        }
    }
    else if(msg.message == WM_KEYUP)
    {
        switch(msg.vkcode)
        {
            case VK_UP:
            case 'W':
            case VK_DOWN:
            case 'S':
                player.vy = 0;
                break;
            case VK_LEFT:
            case 'A':
            case VK_RIGHT:
            case 'D':
                player.vx = 0;
                break;
        }
    }
}
//子弹移动 
void bulletMove()
{
	for(int i=0;i<BULLET_NUM;i++)
	{
		if(bullet[i].life)
		{
			// 子弹向上移动
			bullet[i].y += bullet[i].vy * bullet[i].speed;
			
			// 如果子弹飞出屏幕，回收它
			if(bullet[i].y < -bulletHeight)  
			{
				bullet[i].life = false;
			}
		}
	}
} 

//敌机移动
void enemyMove()
{
	for(int i=0;i<ENEMY_NUM;i++)
	{
		if(enemy[i].life)
		{
			// 敌机向下移动
			enemy[i].y += enemy[i].vy * enemy[i].speed;
			
			// 如果敌机飞出屏幕，回收它
			if(enemy[i].y > HEIGHT)
			{
				enemy[i].life = false;
			}
		}
	}
}

//碰撞检测函数
void collisionCheck()
{
	// 1. 子弹和敌机的碰撞检测
	for(int i=0;i<ENEMY_NUM;i++)
	{
		if(!enemy[i].life)
			continue;
		for(int j=0;j<BULLET_NUM;j++)
		{
			if(!bullet[j].life)
				continue;
			
			// 根据敌机类型获取尺寸
			int enemyWidth, enemyHeight;
			if(enemy[i].type == BIG) {
				enemyWidth = bigEnemyWidth;
				enemyHeight = bigEnemyHeight;
			} else {
				enemyWidth = smallEnemyWidth;
				enemyHeight = smallEnemyHeight;
			}
			
			// 检测子弹是否击中敌机
			if(bullet[j].x > enemy[i].x && 
			   bullet[j].x < enemy[i].x + enemyWidth &&
			   bullet[j].y > enemy[i].y && 
			   bullet[j].y < enemy[i].y + enemyHeight)
			{
				// 子弹击中敌机
				bullet[j].life = false;  // 子弹消失
				enemy[i].hp--;  // 敌机减血
				
				// 如果敌机血量为0，敌机消失
				if(enemy[i].hp <= 0)
				{
					enemy[i].life = false;
					// 播放敌机爆炸音效
					playSound("图片音频/击败敌人.mp3");
				}
				break;  // 一颗子弹只能击中一个敌机
			}
		}
	}
	
	// 2. 玩家和敌机的碰撞检测
	for(int i=0;i<ENEMY_NUM;i++)
	{
		if(!enemy[i].life)
			continue;
		
		// 根据敌机类型获取尺寸
		int enemyWidth, enemyHeight;
		if(enemy[i].type == BIG) {
			enemyWidth = bigEnemyWidth;
			enemyHeight = bigEnemyHeight;
		} else {
			enemyWidth = smallEnemyWidth;
			enemyHeight = smallEnemyHeight;
		}
		
		// 检测玩家是否与敌机碰撞
		if(player.x < enemy[i].x + enemyWidth &&
		   player.x + playerWidth > enemy[i].x &&
		   player.y < enemy[i].y + enemyHeight &&
		   player.y + playerHeight > enemy[i].y)
		{
			// 玩家与敌机碰撞，游戏结束
			gameOver = true;
			player.life = false;
			// 播放玩家飞机爆炸音效
    		playSound("图片音频/爆炸.mp3");
    
    		// 停止背景音乐
    		stopSound();
			break;  // 一次碰撞就结束游戏
		}
	}
}

int main()
{
    initgraph(WIDTH, HEIGHT, EX_SHOWCONSOLE);
    gameInit();
     
    // 播放背景音乐（循环）
    playSound("图片音频/背景音乐.mp3", true);
    
    while(1)
    {
    	// 如果游戏结束，检测按键退出
    	if(gameOver)
    	{
    		if(peekmessage(&msg, EX_KEY))
    		{
    			if(msg.message == WM_KEYDOWN)
    			{
    				break;  // 按任意键退出
    			}
    		}
    	}
    	else
    	{
    		// 游戏正常进行
    		// 创建子弹(控制发射频率)
    		bulletCreate();
    		
    		// 创建敌机(控制生成频率)
    		enemyCreate();
    		
    		// 处理键盘输入
    		playerMove();
    		
    		// 更新玩家位置
            int nextX = player.x + player.speed * player.vx;
            int nextY = player.y + player.speed * player.vy;
            
            // 边界检查
            int halfWidth = playerWidth / 2;
            if (nextX >= -halfWidth && nextX <= WIDTH - halfWidth) {
                player.x = nextX;
            } else {
                if (nextX < -halfWidth) player.x = -halfWidth;
                if (nextX > WIDTH - halfWidth) player.x = WIDTH - halfWidth;
            }
            
            if (nextY >= 0 && nextY <= HEIGHT - playerHeight) {
                player.y = nextY;
            } else {
                if (nextY < 0) player.y = 0;
                if (nextY > HEIGHT - playerHeight) player.y = HEIGHT - playerHeight;
            }
            
            // 更新子弹位置
            bulletMove();
            
            // 更新敌机位置
            enemyMove();
            
            // 碰撞检测
            collisionCheck();
    	}
        
        // 绘制
        BeginBatchDraw();
        gameDraw();    
        EndBatchDraw();
        
        Sleep(10);  // 稍微增加延迟，让游戏运行更平稳
    }
    stopSound();
    return 0;
}

