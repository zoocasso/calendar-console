#include <iostream>
#include <iomanip>//setw()함수를 실행시키기 위한 헤더함수

using namespace std;
bool isLeapYear(int year);
int lastDay(int year, int month);
int totalDay(int year, int month, int day);
int weekDay(int year, int month, int day);
void choice();
void calendar();
void showAll();
void table(int year, int month);
void commandCenter(int year, int month);
void input(char *schedule, int year, int month, int day);
void check(int year, int month, int day);
void remove(int year, int month, int day);
void space();
static string save[5000][12][31];

int main() {
	choice();
}

void choice() {
	int number = 0;
	cout << "1 = 달력출력, 2 = 모든일정확인 : ";
	cin >> number;
	if (number == 1) {
		space();
		calendar();
	}
	else if (number == 2) {
		space();
		showAll();
	}
	else {
		cout << "\n1과 2 중 하나를 입력하세요.\n\n";
		choice();
	}
}

void showAll() {
	for (int i = 1; i < 5001; i++) {
		for (int j = 1; j < 13; j++) {
			for (int k = 1; k < 32; k++) {
				if (save[i][j][k] != "") {
					cout << i << "년 " << j << "월 " << k << "일 : "<< save[i][j][k]<<"\n";
				}
			}
		}
	}
	cout << "\n\n";
	choice();
}

void calendar() {
	// 변수 선언과 초기화
	int year = 0;
	int month = 0;
	cout << "출력하고싶은 연도와 달을 입력해주세요 : ";
	cin >> year >> month;


	// 달을 잘못입력하였을 때의 조건문
	if (month < 1 || month>12) {
		cout << ">>1월에서 12월사이를 입력해주세요 \n\n";
		calendar();
	}
	space();
	table(year, month);
}

void table(int year, int month) {
	cout << "---------------------------------\n";
	cout << "            " << year << "년 " << month << "월\n";
	cout << "---------------------------------\n";
	cout << " 월   화   수   목   금   토   일\n";

	// 1일이 출력되어야할 요일을 정하기 위한 조건문
	for (int i = 0; i < weekDay(year, month, 1); i++) {
		cout << "     ";
	}

	// 각 달마다 마지막 일까지 출력을 담당하는 조건문
	for (int i = 1; i < lastDay(year, month) + 1; i++) {
		cout <<  setw(3)<< i << "  ";
		if (weekDay(year, month, i) == 6 && lastDay(year, month) != i) {
			cout << "\n";
		}
	}
	cout << "\n---------------------------------\n";
	commandCenter(year, month);
}

void commandCenter(int year, int month) {
	//변수 선언과 초기화
	int day = 0;
	int command = 0;
	char schedule[10] = {0};
	cout << "\n\n(초기화면으로 돌아가고싶다면 0을 입력)\n\n작업하고 싶은 날이 몇일인지 입력해주세요 : ";
	cin >> day;
	if (day == 0) {
		space();
		choice();
	}
	else {
		if (day > lastDay(year, month)) {
			space();
			cout << ">>1일과 " << lastDay(year, month) << "일 사이를 입력해주세요\n\n";
			commandCenter(year, month);
		}
		space();
		cout << "\n\n-------------------------------------------\n";
		cout << " 1. 일정 입력 \n 2. 일정 확인 \n 3. 일정 삭제";
		cout << "\n-------------------------------------------\n";
		cout << "위의 보기중에 " << year << "년 " << month << "월 " << day << "일에 하실 작업을 입력해주세요 : ";
		cin >> command;
		if (command == 1) {
			cout << "\n일정을 입력하세요 (띄어쓰기 대신 언더바_ 사용할것): ";//input()
			cin >> schedule;
			input(schedule, year, month, day);
		}
		else if (command == 2) {
			space();
			cout << "\n" << year << "년 " << month << "월 " << day << "일의 일정은 다음과 같습니다\n\n"; //check()
			check(year, month, day);
		}
		else if (command == 3) {
			space();
			cout << "\n" << year << "년 " << month << "월 " << day << "일의 일정을 삭제하였습니다.";//remove()
			remove(year, month, day);
		}
		else {
			cout << "보기에 있는 숫자를 입력하세요";
			commandCenter(year, month);
		}
	}
}

void input(char *schedule, int year, int month, int day) {
	space();
	cout << "\n" << year << "년 " << month << "월 " << day << "일의 일정은 다음과 같습니다\n\n" << schedule;
	save[year][month][day] = schedule;
	cout << "\n\n---------------------\n";
	cout << "달력으로 돌아갑니다";
	cout << "\n---------------------\n\n\n\n";
	table(year, month);
}

void check(int year, int month, int day) {
	cout << save[year][month][day];
	cout << "\n\n---------------------\n";
	cout << "달력으로 돌아갑니다";
	cout << "\n---------------------\n\n\n\n";
	table(year, month);
}

void remove(int year, int month, int day) {
	save[year][month][day] = "";
	cout << "\n\n---------------------\n";
	cout << "달력으로 돌아갑니다";
	cout << "\n---------------------\n\n\n\n";
	table(year, month);
}

void space() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

bool isLeapYear(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int lastDay(int year, int month) {
	int m[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	m[1] = isLeapYear(year) ? 29 : 28;
	return m[month - 1];
}

int totalDay(int year, int month, int day) {
	int total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	for (int i = 1; i < month; i++) {
		total += lastDay(year, i);
	}
	return total + day;
}

int weekDay(int year, int month, int day) {
	return totalDay(year, month, day) % 7;
}