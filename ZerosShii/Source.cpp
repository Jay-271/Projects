#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int ALLHEROS = 125;

const int MAXHEROS = 35;
const int MAXHEROSBANNED = 10;
const int MAXHERONAMESIZE = 20;

const int METAHEROS = 8;

string herosBanned[MAXHEROSBANNED];
string allHeros[ALLHEROS] = {
	"Aamon", "Akai", "Aldous", "Alice", "Alpha", "Alucard", "Angela", "Argus",
	"Arlott", "Aurora", "Badang", "Balmond", "Barats", "Baxia", "Beatrix", "Belerick",
	"Bruno", "Brody", "Carmilla", "Cecilion", "Chang'e", "Chou", "Claude", "Clint",
	"Cyclops", "Diggie", "Dyrroth", "Esmeralda", "Estes", "Eudora", "Fanny", "Faramis",
	"Franco", "Freya", "Gatotkaca", "Gloo", "Gord", "Grock", "Granger", "Guinevere",
	"Hanabi", "Hanzo", "Harith", "Harley", "Hayabusa", "Helcurt", "Hilda", "Hylos",
	"Irithel", "Jawhead", "Johnson", "Kadita", "Kagura", "Karina", "Karrie", "Khaleed",
	"Khufra", "Kimmy", "Lancelot", "Lapu-Lapu", "Layla", "Leomord", "Lesley", "Ling",
	"Lolita", "Luo Yi", "Lylia", "Masha", "Martis", "Mathilda", "Miya", "Minotaur",
	"Moskov", "Nana", "Natalia", "Odette", "Paquito", "Pharsa", "Phoveus", "Popol and Kupa",
	"Rafaela", "Roger", "Ruby", "Selena", "Minsitthar", "Silvanna", "Sun", "Terizla", "Thamuz",
	"Uranus", "Valentina", "Valir", "Vale", "Vexana", "Wan Wan", "X.Borg", "Yu Zhong",
	"Yi Sun-shin", "Yve", "Zhask", "Zilong", "Kaja", "Atlas", "Joy", "Benedetta",
	"Melissa", "Natan", "Xavier", "Lunox", "Fredrinn", "Julian", "Novaria"
};
bool herosBannedValue[ALLHEROS];

struct Meta {
	string metaRoam[METAHEROS] = { "Kaja", "Faramis", "Lolita", "Grock", "Chou", "Diggie", "Atlas", "Khufra" };
	string metaXP[METAHEROS] = { "Joy", "Gloo", "Edith", "Lapu-Lapu", "Yu Zhong", "Arlott", "Benedetta", "Grock" };
	string metaGold[METAHEROS] = { "Wan Wan", "Melissa", "Claude", "Moskov", "Brody", "Natan", "Beatrix", "Karrie" };
	string metaMid[METAHEROS] = { "Valentina", "Faramis", "Pharsa", "Yve", "Kagura", "Xavier", "Lylia", "Lunox" };
	string metaJungle[METAHEROS] = { "Fredrinn", "Martis", "Barats", "Fanny", "Ling", "Hayabusa", "Karina", "Julian" };
};

struct HeroByRole {
	string goldLaners[MAXHEROS] = {
	"Beatrix", "Bruno", "Brody", "Claude", "Clint", "Granger", "Hanabi", "Irithel",
	"Karrie", "Kimmy", "Layla", "Lesley", "Miya", "Moskov", "Popol and Kupa", "Wanwan", "Yi Sun-shin"
	};

	string midLaners[MAXHEROS] = {
		"Aamon", "Alice", "Aurora", "Cecilion", "Chang'e", "Cyclops", "Esmeralda", "Eudora",
		"Gord", "Harith", "Kadita", "Kagura", "Luo Yi", "Lylia", "Nana", "Odette", "Pharsa",
		"Valentina", "Valir", "Vale", "Vexana", "Yve", "Zhask"
	};

	string roamers[MAXHEROS] = {
		"Akai", "Angela", "Baxia", "Belerick", "Carmilla", "Diggie", "Estes", "Faramis",
		"Franco", "Hylos", "Johnson", "Khufra", "Lolita", "Mathilda", "Minotaur", "Rafaela"
	};

	string xpLaners[MAXHEROS] = {
		"Aldous", "Alpha", "Alucard", "Argus", "Badang", "Balmond", "Barats", "Chou",
		"Dyrroth", "Freya", "Gatotkaca", "Gloo", "Guinevere", "Hilda", "Jawhead", "Khaleed",
		"Lapu-Lapu", "Leomord", "Martis", "Masha", "Paquito", "Phoveus", "Roger", "Ruby",
		"Silvanna", "Sun", "Terizla", "Thamuz", "Uranus", "X.Borg", "Yu Zhong", "Zilong", "Arlott"
	};

	string junglers[MAXHEROS] = {
		"Fanny", "Hanzo", "Harley", "Hayabusa", "Helcurt", "Karina", "Lancelot", "Ling",
		"Natalia", "Selena"
	};
};

struct Team {
	string herosPicked[MAXHEROS];
	string herosBanned[MAXHEROSBANNED];
};

void blueBan(Team& Blue, char heroBanned[], int& heroBannedNumber, int& heroBannedNumberBlue);
void redBan(Team& Red, char heroBanned[], int& heroBannedNumber, int& heroBannedNumberRed);
void printMeta(Meta& bothTeams, Team& Blue, Team& Red);

void BanPhase1(Team& Blue, Team& Red, Meta& bothTeams);

void herosBannedPrint(Team& Blue, Team& Red);

void pickPhase1(Team& Blue, Team& Red, Meta& bothTeams);

void herosPickedPrint(Team& Blue, Team& Red);

void BanPhase2(Team& Blue, Team& Red, Meta& bothTeams);

void pickPhase2(Team& Blue, Team& Red, Meta& bothTeams);

int findheroID(string hero);
//void //deleteMeta(char heroBanned[], Meta& bothTeams);
void BluePick(Team& Blue, char heroPicked[], int& heroPickedNumber, int& heroPickedNumberBlue);
void RedPick(Team& Red, char heroPicked[], int& heroPickedNumber, int& heroPickedNumberRed);

int main() {
	Team Blue, Red;
	Meta bothTeams;
	int gameNumber = 1;
	bool Continue = false;

	do {

		for (int i = 0; i < ALLHEROS; i++) {
			herosBannedValue[i] = true;
		}
		Continue = false;
		char gameValue = 'N';
		cout << "Game " << gameNumber << endl << endl;

		printf("\t\t<----***Ban Phase 1***---->\n\n");
		printMeta(bothTeams, Blue, Red);
		BanPhase1(Blue, Red, bothTeams);
		
		printf("\t\t<----+++Pick Phase 1+++---->\n\n");
		printMeta(bothTeams, Blue, Red);
		pickPhase1(Blue, Red, bothTeams);

		printf("\t\t<----***Ban Phase 2***---->\n\n");
		printMeta(bothTeams, Blue, Red);
		herosBannedPrint(Blue, Red);
		herosPickedPrint(Blue, Red);
		BanPhase2(Blue, Red, bothTeams);

		printf("\t\t<----+++Pick Phase 2+++---->\n\n");
		printMeta(bothTeams, Blue, Red);
		herosPickedPrint(Blue, Red);
		pickPhase2(Blue, Red, bothTeams);

		printf("\t\t+++Would you like to start a new draft? [Yes = Y || No = N]+++\n\n");
		cin >> gameValue;

		while (cin.fail()) // checks for error
		{
			// WRONG type of data clear
			cin.clear();
			// to whipe keyboard buffer:
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//--> ignores next ONE character, can put an integer to ignore (x) amount of characters OR that stuff in the function rn which states:
				//ignore max OR up to '\n' (enter)
			cout << "Enter a correct variable [Yes = Y/No = N]: ";
			cin >> gameValue;
		}

		gameValue = toupper(gameValue);

			if (gameValue == 'Y') {
				Continue = true;
				gameNumber++;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if (gameValue == 'N') {
				Continue = false;
			}
		
	} while (Continue);


	return 0;
}

void BanPhase1(Team& Blue, Team& Red, Meta& bothTeams) {
	int heroBannedNumber = 0;
	int heroBannedNumberBlue = 0;
	int heroBannedNumberRed = 0;

	char heroBanned[MAXHERONAMESIZE];

	//Blue ban 1
	printf("Team Blue Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	blueBan(Blue, heroBanned, heroBannedNumber, heroBannedNumberBlue);

	//deleteMeta(heroBanned, bothTeams);


	// Red Ban 1
	printf("Team Red Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	redBan(Red, heroBanned, heroBannedNumber, heroBannedNumberRed);

	//deleteMeta(heroBanned, bothTeams);


	//Blue ban 2
	printf("Team Blue Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	blueBan(Blue, heroBanned, heroBannedNumber, heroBannedNumberBlue);

	//deleteMeta(heroBanned, bothTeams);


	//Red ban 2
	printf("Team Red Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	redBan(Red, heroBanned, heroBannedNumber, heroBannedNumberRed);

	//deleteMeta(heroBanned, bothTeams);


	//Blue ban 3
	printf("Team Blue Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	blueBan(Blue, heroBanned, heroBannedNumber, heroBannedNumberBlue);

	//deleteMeta(heroBanned, bothTeams);


	//Red ban 3
	printf("Team Red Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	redBan(Red, heroBanned, heroBannedNumber, heroBannedNumberRed);

	//deleteMeta(heroBanned, bothTeams);

}

void pickPhase1(Team& Blue, Team& Red, Meta& bothTeams) {
	herosBannedPrint(Blue, Red);

	int heroPickedNumber = 0;
	int heroPickedNumberBlue = 0;
	int heroPickedNumberRed = 0;

	char heroPicked[MAXHERONAMESIZE];

	//Blue pick 1
	printf("Team Blue pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	BluePick(Blue, heroPicked, heroPickedNumber, heroPickedNumberBlue);
	//deleteMeta(heroPicked, bothTeams);

	//Red pick 1

	printf("Team Red pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	RedPick(Red, heroPicked, heroPickedNumber, heroPickedNumberRed);
	//deleteMeta(heroPicked, bothTeams);


	//Red pick 2

	printf("Team Red pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	RedPick(Red, heroPicked, heroPickedNumber, heroPickedNumberRed);
	//deleteMeta(heroPicked, bothTeams);


	//Blue pick 2
	printf("Team Blue pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	BluePick(Blue, heroPicked, heroPickedNumber, heroPickedNumberBlue);
	//deleteMeta(heroPicked, bothTeams);


	//Blue pick 3
	printf("Team Blue pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	BluePick(Blue, heroPicked, heroPickedNumber, heroPickedNumberBlue);
	//deleteMeta(heroPicked, bothTeams);


	//Red pick 3

	printf("Team Red pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	RedPick(Red, heroPicked, heroPickedNumber, heroPickedNumberRed);
	//deleteMeta(heroPicked, bothTeams);
}

void BanPhase2(Team& Blue, Team& Red, Meta& bothTeams) {
	int heroBannedNumber = 6;
	int heroBannedNumberBlue = 3;
	int heroBannedNumberRed = 3;

	char heroBanned[MAXHERONAMESIZE];

	// Red Ban 4
	printf("Team Red Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	redBan(Red, heroBanned, heroBannedNumber, heroBannedNumberRed);

	//deleteMeta(heroBanned, bothTeams);

	//Blue ban 4
	printf("Team Blue Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	blueBan(Blue, heroBanned, heroBannedNumber, heroBannedNumberBlue);

	//deleteMeta(heroBanned, bothTeams);

	//Blue ban 5
	printf("Team Blue Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	blueBan(Blue, heroBanned, heroBannedNumber, heroBannedNumberBlue);

	//deleteMeta(heroBanned, bothTeams);

	// Red Ban 5
	printf("Team Red Ban\t\tEnter hero to ban: ");

	cin.getline(heroBanned, MAXHERONAMESIZE);

	herosBanned[heroBannedNumber] = (heroBanned);

	redBan(Red, heroBanned, heroBannedNumber, heroBannedNumberRed);

	//deleteMeta(heroBanned, bothTeams);
}

void pickPhase2(Team& Blue, Team& Red, Meta& bothTeams) {
	int heroPickedNumber = 5;
	int heroPickedNumberBlue = 3;
	int heroPickedNumberRed = 3;

	char heroPicked[MAXHERONAMESIZE];

	//Red pick 4

	printf("Team Red pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	RedPick(Red, heroPicked, heroPickedNumber, heroPickedNumberRed);
	//deleteMeta(heroPicked, bothTeams);

	//Blue pick 4
	printf("Team Blue pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	BluePick(Blue, heroPicked, heroPickedNumber, heroPickedNumberBlue);
	//deleteMeta(heroPicked, bothTeams);

	//Blue pick 5
	printf("Team Blue pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	BluePick(Blue, heroPicked, heroPickedNumber, heroPickedNumberBlue);
	//deleteMeta(heroPicked, bothTeams);

	//Red pick 5

	printf("Team Red pick\t\tEnter hero to pick: ");

	cin.getline(heroPicked, MAXHERONAMESIZE);

	herosBanned[heroPickedNumber] = heroPicked;

	RedPick(Red, heroPicked, heroPickedNumber, heroPickedNumberRed);
	//deleteMeta(heroPicked, bothTeams);

	printf("\t\tDraft Complete\n\n\t\tFinal Heros Picked:\n\n");

	herosBannedPrint(Blue, Red);
	herosPickedPrint(Blue, Red);
}
/*
void ////deleteMeta(char heroBanned[], Meta& bothTeams) {


	for (int x = 0; x < METAHEROS; x++) {
		if (heroBanned == bothTeams.metaGold[x])
			for (int y = x; y < METAHEROS - 1; y++) {
				bothTeams.metaGold[y] = bothTeams.metaGold[y + 1];
				counterBanGold++;
			}
		else if (heroBanned == bothTeams.metaJungle[x])
			for (int y = x; y < METAHEROS - 1; y++) {
				bothTeams.metaJungle[y] = bothTeams.metaJungle[y + 1];
				counterBanJungle++;
			}
		else if (heroBanned == bothTeams.metaXP[x])
			for (int y = x; y < METAHEROS - 1; y++) {
				bothTeams.metaXP[y] = bothTeams.metaXP[y + 1];
				counterBanXP++;
			}
		else if (heroBanned == bothTeams.metaMid[x])
			for (int y = x; y < METAHEROS - 1; y++) {
				bothTeams.metaMid[y] = bothTeams.metaMid[y + 1];
				counterBanMid++;
			}
		else if (heroBanned == bothTeams.metaRoam[x])
			for (int y = x; y < METAHEROS - 1; y++) {
				bothTeams.metaRoam[y] = bothTeams.metaRoam[y + 1];
				counterBanRoam++;
			}

	}
}
*/
void blueBan(Team& Blue, char heroBanned[], int& heroBannedNumber, int& heroBannedNumberBlue) {


	bool found = false;
	while (!found) {
		for (int i = 0; i < ALLHEROS; i++) {
			if (herosBanned[heroBannedNumber] == allHeros[i] && herosBannedValue[i] == true) {
				printf("Hero #%d Banned.\n\n", heroBannedNumber + 1);
				herosBannedValue[i] = false;
				found = true;
				Blue.herosBanned[heroBannedNumberBlue] = herosBanned[heroBannedNumber];
				heroBannedNumberBlue++;
				break;
			}
		}
		if (!found) {
			cout << "Hero not found or is already banned.\nPlease re-enter a hero name: ";
			cin.getline(heroBanned, MAXHERONAMESIZE);
			herosBanned[heroBannedNumber] = (heroBanned);
			cout << endl;
		}
	}

	heroBannedNumber++;
}
void redBan(Team& Red, char heroBanned[], int& heroBannedNumber, int& heroBannedNumberRed) {

	bool found = false;

	while (!found) {
		for (int i = 0; i < ALLHEROS; i++) {
			if (herosBanned[heroBannedNumber] == allHeros[i] && herosBannedValue[i] == true) {
				printf("Hero #%d Banned.\n\n", heroBannedNumber + 1);
				herosBannedValue[i] = false;
				found = true;
				Red.herosBanned[heroBannedNumberRed] = herosBanned[heroBannedNumber];
				heroBannedNumberRed++;
				break;
			}
		}
		if (!found) {
			cout << "Hero not found or is already banned.\nPlease re-enter a hero name: ";
			cin.getline(heroBanned, MAXHERONAMESIZE);
			herosBanned[heroBannedNumber] = (heroBanned);
			cout << endl;
		}
	}

	heroBannedNumber++;

}
void BluePick(Team& Blue, char heroPicked[], int& heroPickedNumber, int& heroPickedNumberBlue) {
	bool found = false;
	while (!found) {
		for (int i = 0; i < ALLHEROS; i++) {
			if (herosBanned[heroPickedNumber] == allHeros[i] && herosBannedValue[i] == true) {
				printf("Hero #%d Picked.\n\n", heroPickedNumber + 1);
				herosBannedValue[i] = false;
				found = true;
				Blue.herosPicked[heroPickedNumberBlue] = herosBanned[heroPickedNumber];
				heroPickedNumberBlue++;
				break;
			}
		}
		if (!found) {
			cout << "Hero not found or is already banned.\nPlease re-enter a hero name: ";
			cin.getline(heroPicked, MAXHERONAMESIZE);
			herosBanned[heroPickedNumber] = (heroPicked);
			cout << endl;
		}
	}
	heroPickedNumber++;

}
void RedPick(Team& Red, char heroPicked[], int& heroPickedNumber, int& heroPickedNumberRed) {
	bool found = false;
	while (!found) {
		for (int i = 0; i < ALLHEROS; i++) {
			if (herosBanned[heroPickedNumber] == allHeros[i] && herosBannedValue[i] == true) {
				printf("Hero #%d Picked.\n\n", heroPickedNumber + 1);
				herosBannedValue[i] = false;
				found = true;
				Red.herosPicked[heroPickedNumberRed] = herosBanned[heroPickedNumber];
				heroPickedNumberRed++;
				break;
			}
		}
		if (!found) {
			cout << "Hero not found or is already banned.\nPlease re-enter a hero name: ";
			cin.getline(heroPicked, MAXHERONAMESIZE);
			herosBanned[heroPickedNumber] = (heroPicked);
			cout << endl;
		}
	}
	heroPickedNumber++;

}

void printMeta(Meta& bothTeams, Team& Blue, Team& Red) {
	int x = 0;

	printf("\tHere is a reminder of the meta picks that are avialable\n\n");


	cout << "Gold Lane || ";
	for (int i = 0; i < METAHEROS; i++)
	{
		if (!herosBannedValue[findheroID(bothTeams.metaGold[i])]) {
			cout << "";
		}
		else
			cout << bothTeams.metaGold[i] << ", ";
	}

	cout << endl << endl;
	cout << "XP Lane || ";
	for (int i = 0; i < METAHEROS; i++)
	{
		if (!herosBannedValue[findheroID(bothTeams.metaXP[i])]) {
			cout << "";
		}
		else
			cout << bothTeams.metaXP[i] << ", ";
	}
	cout << endl << endl;
	cout << "Mid Lane || ";
	for (int i = 0; i < METAHEROS; i++)
	{
		if (!herosBannedValue[findheroID(bothTeams.metaMid[i])]) {
			cout << "";
		}
		else
			cout << bothTeams.metaMid[i] << ", ";
	}
	cout << endl << endl;
	cout << "Jungle || ";
	for (int i = 0; i < METAHEROS; i++)
	{
		if (!herosBannedValue[findheroID(bothTeams.metaJungle[i])]) {
			cout << "";
		}
		else
			cout << bothTeams.metaJungle[i] << ", ";
	}
	cout << endl << endl;
	cout << "Roam || ";
	for (int i = 0; i < METAHEROS; i++)
	{
		if (!herosBannedValue[findheroID(bothTeams.metaRoam[i])]) {
			cout << "";
		}
		else
			cout << bothTeams.metaRoam[i] << ", ";
	}
	cout << endl << endl;
}
void herosPickedPrint(Team& Blue, Team& Red) {
	cout << "--------------------" << "\nHeros picked thus far" << "\n--------------------";
	cout << "\n\nBlue team heros Picked: ";
	for (int i = 0; i < MAXHEROS; i++) {
		cout << Blue.herosPicked[i] << "    ";
	}
	cout << "\n\nRed Team Heros Picked: ";

	for (int i = 0; i < MAXHEROS; i++) {
		cout << Red.herosPicked[i] << "    ";
	}
	cout << endl << endl;
}
void herosBannedPrint(Team& Blue, Team& Red) {
	cout << "--------------------" << "\nHeros banned thus far" << "\n--------------------";

	cout << "\n\nBlue team heros banned: ";
	for (int i = 0; i < MAXHEROSBANNED; i++) {
		cout << Blue.herosBanned[i] << "    ";
	}
	cout << "\n\nRed Team Heros Banned: ";

	for (int i = 0; i < MAXHEROSBANNED; i++) {
		cout << Red.herosBanned[i] << "    ";
	}
	cout << endl << endl;
}

int findheroID(string hero) {
	for (int i = 0; i < ALLHEROS; i++) {
		if (hero == allHeros[i]) {
			return i;
		}
	}

	return -1;
}