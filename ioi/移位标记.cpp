/**
* 游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，
任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。
初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；
并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，
如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。 
@1024 1024
@1
*/#include<iostream>  
using namespace std;

int main(int argc, char* argv[])
{
	int a, b;
	cin >> a >> b;
	unsigned int ids[32] = { 0 };
	if (a < 1 || a>1024 || b < 1 || b>1024)
	{
		cout << "-1" << endl;
		return 0;
	}
	ids[(a - 1) >> 5] = 1;
	int i = (a % 32 == 0 ? 32 : a % 32) - 1;
	ids[(a - 1) >> 5] = ids[(a - 1) >> 5] << i;
	int j = (b % 32 == 0 ? 32 : b % 32) - 1;
	if ((ids[(b - 1) >> 5] >> j) == 1)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	return 0;
}