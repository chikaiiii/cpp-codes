#include <iostream>
using namespace std;

/*仅提交以下代码*/
class GameCharacter {
	
public:
	int hp;
	int attack;
	GameCharacter(int a, int b) : hp(a), attack(b) {}
	// 实现
	bool isDeath() {
		if (hp <= 0) return true;
		else return false;
	}
	int getHp() { return hp; }
	int getAttack() { return attack; }
	void setHp(int h) { hp = h; }
	void setAttack(int a) { attack = a; }
};

class Monster : public GameCharacter {
public:
	Monster(int a, int b) : GameCharacter(a, b) {}
	Monster() :GameCharacter(0, 0) {}
	// 根据需要添加其他辅助数据成员或函数
		bool operator<(const Monster& other) const {
	}
};

class Scuter : public GameCharacter {
public:
	Scuter(int a, int b) : GameCharacter(a, b) {}
	// 计算HP的理论损失值，并更新角色存活状态。
	void quicksort(Monster* arr, int low, int high)
	{
		if (low >= high) return;

		int k = arr[low].attack, tmp;
		int lf = low, rh = high;
		while (lf < rh)
		{
			while (arr[rh].attack <= k && lf < rh) --rh;
			while (arr[lf].attack >= k && lf < rh) ++lf;
			if (lf < rh)
			{
				tmp = arr[rh].attack;
				arr[rh].attack = arr[lf].attack;
				arr[lf].attack = tmp;
			}
		}
		arr[low].attack = arr[lf].attack;
		arr[lf].attack = k;
		quicksort(arr, low, lf - 1);
		quicksort(arr, rh + 1, high);
	}
	int leastLossOfHp(Monster* monster, int num) {
		int losthp = 0,n=num;
		quicksort(monster,0, num);
		while (n)
		{
			monster[num - n].hp -= attack;
			for (int i = num - n; i < num; i++)
			{
				losthp += monster[i].attack;
				hp-= monster[i].attack;
			}
			if (monster[num - n].isDeath()) { n--; }
		}
		return losthp;
	}
};
/*仅提交以上代码*/

int main() {
	Monster* monster;
	int attack, hp, num;
	while (cin >> hp >> attack) {
		Scuter scuter(hp, attack);
		cin >> num;
		monster = new Monster[num];
		for (int i = 0; i < num; ++i) {
			cin >> hp >> attack;
			monster[i].setHp(hp);
			monster[i].setAttack(attack);
		}
		cout << scuter.leastLossOfHp(monster, num) << " ";
		if (scuter.isDeath()) {
			cout << "Dead" << endl;
		}
		else {
			cout << "Alive" << endl;
		}
		delete[] monster;
		monster = nullptr;
	}
}