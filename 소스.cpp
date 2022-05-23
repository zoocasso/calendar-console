#include <iostream>
#include <iomanip> //setw()�Լ��� �����Ű�� ���� ����Լ�

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

int main()
{
	choice();
}

void choice()
{
	int number = 0;
	cout << "1 = �޷����, 2 = �������Ȯ�� : ";
	cin >> number;
	if (number == 1)
	{
		space();
		calendar();
	}
	else if (number == 2)
	{
		space();
		showAll();
	}
	else
	{
		cout << "\n1�� 2 �� �ϳ��� �Է��ϼ���.\n\n";
		choice();
	}
}

void showAll()
{
	for (int i = 1; i < 5001; i++)
	{
		for (int j = 1; j < 13; j++)
		{
			for (int k = 1; k < 32; k++)
			{
				if (save[i][j][k] != "")
				{
					cout << i << "�� " << j << "�� " << k << "�� : " << save[i][j][k] << "\n";
				}
			}
		}
	}
	cout << "\n\n";
	choice();
}

void calendar()
{
	// ���� ����� �ʱ�ȭ
	int year = 0;
	int month = 0;
	cout << "����ϰ����� ������ ���� �Է����ּ��� : ";
	cin >> year >> month;

	// ���� �߸��Է��Ͽ��� ���� ���ǹ�
	if (month < 1 || month > 12)
	{
		cout << ">>1������ 12�����̸� �Է����ּ��� \n\n";
		calendar();
	}
	space();
	table(year, month);
}

void table(int year, int month)
{
	cout << "---------------------------------\n";
	cout << "            " << year << "�� " << month << "��\n";
	cout << "---------------------------------\n";
	cout << " ��   ȭ   ��   ��   ��   ��   ��\n";

	// 1���� ��µǾ���� ������ ���ϱ� ���� ���ǹ�
	for (int i = 0; i < weekDay(year, month, 1); i++)
	{
		cout << "     ";
	}

	// �� �޸��� ������ �ϱ��� ����� ����ϴ� ���ǹ�
	for (int i = 1; i < lastDay(year, month) + 1; i++)
	{
		cout << setw(3) << i << "  ";
		if (weekDay(year, month, i) == 6 && lastDay(year, month) != i)
		{
			cout << "\n";
		}
	}
	cout << "\n---------------------------------\n";
	commandCenter(year, month);
}

void commandCenter(int year, int month)
{
	//���� ����� �ʱ�ȭ
	int day = 0;
	int command = 0;
	char schedule[10] = {0};
	cout << "\n\n(�ʱ�ȭ������ ���ư����ʹٸ� 0�� �Է�)\n\n�۾��ϰ� ���� ���� �������� �Է����ּ��� : ";
	cin >> day;
	if (day == 0)
	{
		space();
		choice();
	}
	else
	{
		if (day > lastDay(year, month))
		{
			space();
			cout << ">>1�ϰ� " << lastDay(year, month) << "�� ���̸� �Է����ּ���\n\n";
			commandCenter(year, month);
		}
		space();
		cout << "\n\n-------------------------------------------\n";
		cout << " 1. ���� �Է� \n 2. ���� Ȯ�� \n 3. ���� ����";
		cout << "\n-------------------------------------------\n";
		cout << "���� �����߿� " << year << "�� " << month << "�� " << day << "�Ͽ� �Ͻ� �۾��� �Է����ּ��� : ";
		cin >> command;
		if (command == 1)
		{
			cout << "\n������ �Է��ϼ��� (���� ��� �����_ ����Ұ�): "; // input()
			cin >> schedule;
			input(schedule, year, month, day);
		}
		else if (command == 2)
		{
			space();
			cout << "\n"
				 << year << "�� " << month << "�� " << day << "���� ������ ������ �����ϴ�\n\n"; // check()
			check(year, month, day);
		}
		else if (command == 3)
		{
			space();
			cout << "\n"
				 << year << "�� " << month << "�� " << day << "���� ������ �����Ͽ����ϴ�."; // remove()
			remove(year, month, day);
		}
		else
		{
			cout << "���⿡ �ִ� ���ڸ� �Է��ϼ���";
			commandCenter(year, month);
		}
	}
}

void input(char *schedule, int year, int month, int day)
{
	space();
	cout << "\n"
		 << year << "�� " << month << "�� " << day << "���� ������ ������ �����ϴ�\n\n"
		 << schedule;
	save[year][month][day] = schedule;
	cout << "\n\n---------------------\n";
	cout << "�޷����� ���ư��ϴ�";
	cout << "\n---------------------\n\n\n\n";
	table(year, month);
}

void check(int year, int month, int day)
{
	cout << save[year][month][day];
	cout << "\n\n---------------------\n";
	cout << "�޷����� ���ư��ϴ�";
	cout << "\n---------------------\n\n\n\n";
	table(year, month);
}

void remove(int year, int month, int day)
{
	save[year][month][day] = "";
	cout << "\n\n---------------------\n";
	cout << "�޷����� ���ư��ϴ�";
	cout << "\n---------------------\n\n\n\n";
	table(year, month);
}

void space()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

bool isLeapYear(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int lastDay(int year, int month)
{
	int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	m[1] = isLeapYear(year) ? 29 : 28;
	return m[month - 1];
}

int totalDay(int year, int month, int day)
{
	int total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	for (int i = 1; i < month; i++)
	{
		total += lastDay(year, i);
	}
	return total + day;
}

int weekDay(int year, int month, int day)
{
	return totalDay(year, month, day) % 7;
}