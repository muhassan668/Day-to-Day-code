#include <iostream>
using namespace std;

class GameItem{
	protected:
		string name;
		int baseValue;
		static int totalItems;
	public:
		GameItem(string n, int bv): name(n), baseValue(bv){ totalItems++; }
		static int getTotalItems(){
			return totalItems;
		}	
		virtual void triggerEffect() = 0;
		virtual ~GameItem(){
			cout<<"Base Item Destroyed."<<endl;
		}
};

int GameItem::totalItems = 0;

class Weapon: public GameItem{
	private:
		int * damage;
	public:
		Weapon(string n, int bv, int d): GameItem(n,bv){
			damage = new int (d);
		}
		~Weapon(){
			cout<<"Weapon memory freed."<<endl;
			delete damage;
		}
		void triggerEffect() override {
			cout<<"Attacked."<<endl;
		}
		Weapon operator+(Weapon &w){
			string nn = name + w.name;
			int nd = *damage + *(w.damage);
			return Weapon(nn, baseValue + w.baseValue, nd);
		}
};
class Consumable: public GameItem{
	private:
		int duration;
	public:
		Consumable(string n, int bv, int d): GameItem(n,bv){
			duration = d;
		}
		void triggerEffect() override {
		cout<<"Consumed"<<endl;
		}
		~Consumable(){
			cout<<"Consumable destroyed."<<endl;
		}
};
int main(){
	
	cout<<"Initial Total count: "<<GameItem::getTotalItems()<<endl;
	Weapon obj1("Sword", 1, 100);
	Weapon obj2("Dagger", 2, 50);
	Weapon obj3 = obj1 + obj2;
	GameItem* inventory[2];
	
	inventory[0] = new Weapon("Gun", 5, 500);
	inventory[1] = new Consumable("Water", 0, 10);
	
	for(int i=0; i<2; i++){
		inventory[i]->triggerEffect();
	}	
	for(int i= 0; i<2; i++){
		delete inventory[i];
	}
	
	cout<<"Final Total count: "<<GameItem::getTotalItems()<<endl;
	
	
	
	
	return 0;
}










