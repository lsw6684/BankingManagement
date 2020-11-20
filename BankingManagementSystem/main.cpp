#include <iostream>
#include <cstring>

using namespace std;
const int MAX_LEN = 10;

//함수 먼저 선언
void Menu(void);		// 메뉴
void Register(void);	// 계좌 생성
void Input(void);		// 입금
void Output(void);		// 출금
void Management(void);	// Management

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int accIndex = 0;

typedef struct			// 구조체
{
	int id, balance;
	char name[MAX_LEN];
} Account;				// 구조체 별칭
Account accArr[100];	// 계좌 저장



void Menu(void)
{
	cout << "■■■■■■■■■  M E  N U  ■■■■■■■■" << endl;
	cout << "■ 1. 계좌  생성                            ■" << endl;
	cout << "■ 2. 입      금                            ■" << endl;
	cout << "■ 3. 출      금                            ■" << endl;
	cout << "■ 4. 관      리                            ■" << endl;
	cout << "■ 5. 종      료                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}

void Register(void)
{
	int id, balance;
	char name[MAX_LEN];

	cout << "■■■■■■■■■ 계좌  생성 ■■■■■■■■" << endl;
	cout << "■ 1. 아  이  디                            ■" << endl;
	cout << "■ 2. 이      름                            ■" << endl;
	cout << "■ 3. 입  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " 아이디를 입력하세요 : "; cin >> id; cout << endl;
	cout << " 이  름을 입력하세요 : "; cin >> name; cout << endl;
	cout << " 얼마를 입금 할까요? : "; cin >> balance; cout << endl;

	accArr[accIndex].id = id;
	accArr[accIndex].balance = balance;
	strcpy_s(accArr[accIndex].name, name);
}
//void loading(void)
//{
//	cout << endl;
//	float progress = 0.0;
//	while (progress < 1.0) {
//		int barWidth = 70;
//
//		std::cout << "[";
//		int pos = barWidth * progress;
//		for (int i = 0; i < barWidth; ++i) {
//			if (i < pos) std::cout << "=";
//			else if (i == pos) std::cout << ">";
//			else std::cout << " ";
//		}
//		std::cout << "] " << int(progress * 100.0) << " %\r";
//		std::cout.flush();
//
//		progress += 0.16; // for demonstration only
//	}
//	std::cout << std::endl;
//}
void Input(void)
{
	int id, money;
	cout << "■■■■■■■■■  입    금  ■■■■■■■■" << endl;
	cout << "■ 1. 계좌    ID                            ■" << endl;
	cout << "■ 2. 입  금  액                            ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■                                          ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " 아이디를 입력하세요 : "; cin >> id; cout << endl;
	for (int i = 0; i < accIndex; i++)			// ID 인증
	{
		if (accArr[i].id == id)
		{
		//	loading();
		}
	}
	cout << " 얼마를 입금 할까요? : "; cin >> money; cout << endl;

}

int main(void)
{
	int choice;

	while (true)
	{
		Menu();
		cout << "선택 : ";
		cin>>choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			system("cls");
			Register();
		case 2:
			system("cls");
			Input();
		}

	}

	system("pause");
	return 0;

}