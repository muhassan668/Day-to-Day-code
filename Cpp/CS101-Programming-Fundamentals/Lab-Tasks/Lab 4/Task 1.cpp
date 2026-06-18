#include <iostream>
using namespace std;
int main(){
	char new_patrol;
	int overall=0;
	string overall_name;
	int all_total=0;
	
	cout<<"==== Wildlife Reserve Animal Tracking System ==="<<endl<<endl;
	do{
		int total_animals=0;
		int max=0;
		string today_top="";
		cout<<"Start New Patrol(y/n):"<<endl;
		cin>>new_patrol;
		
		if(new_patrol=='n' || new_patrol=='N')
		break;
		
		int species_sighted;
		cout<<"How many species were sighted today"<<endl;
		cin>>species_sighted;
		
		for(int i=1; i<=species_sighted; i++){
			
			string name;
			cout<<"Enter the name of specie"<<endl;
			cin>>name;
			int number;
			cout<<"Enter the number of species sighted"<<endl;
			cin>>number;
			total_animals+=number;
			if(number>max){
				max=number;
				today_top=name;
			}if(number>overall){
				overall=number;
				overall_name=name;
			}
		}
		
		all_total=+total_animals;
		cout <<"------Patrol Summary------"<<endl;
		cout<<"Total animals spotted : "<<total_animals<<endl;
		cout<<"Top species today : "<<today_top<<endl;
		
	}
	while(new_patrol=='y'|| new_patrol=='Y');
	cout<<"------Final Summary------"<<endl;
	cout<<"Overall animals spotted : "<<all_total<<endl;
	cout<<"Most sighted species overall : "<<overall_name<<endl;

	return 0;
} 
