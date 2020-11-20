#include <iostream>
#include <cstring>

using namespace std;
const int MAX_LEN = 10;

//�Լ� ���� ����
void Menu(void);		// �޴�
void Register(void);	// ���� ����
void Input(void);		// �Ա�
void Output(void);		// ���
void Management(void);	// Management

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int accIndex = 0;

typedef struct			// ����ü
{
	int id, balance;
	char name[MAX_LEN];
} Account;				// ����ü ��Ī
Account accArr[100];	// ���� ����



void Menu(void)
{
	cout << "����������  M E  N U  ���������" << endl;
	cout << "�� 1. ����  ����                            ��" << endl;
	cout << "�� 2. ��      ��                            ��" << endl;
	cout << "�� 3. ��      ��                            ��" << endl;
	cout << "�� 4. ��      ��                            ��" << endl;
	cout << "�� 5. ��      ��                            ��" << endl;
	cout << "������������������������" << endl;
}

void Register(void)
{
	int id, balance;
	char name[MAX_LEN];

	cout << "���������� ����  ���� ���������" << endl;
	cout << "�� 1. ��  ��  ��                            ��" << endl;
	cout << "�� 2. ��      ��                            ��" << endl;
	cout << "�� 3. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ���̵� �Է��ϼ��� : "; cin >> id; cout << endl;
	cout << " ��  ���� �Է��ϼ��� : "; cin >> name; cout << endl;
	cout << " �󸶸� �Ա� �ұ��? : "; cin >> balance; cout << endl;

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
	cout << "����������  ��    ��  ���������" << endl;
	cout << "�� 1. ����    ID                            ��" << endl;
	cout << "�� 2. ��  ��  ��                            ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "��                                          ��" << endl;
	cout << "������������������������" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ���̵� �Է��ϼ��� : "; cin >> id; cout << endl;
	for (int i = 0; i < accIndex; i++)			// ID ����
	{
		if (accArr[i].id == id)
		{
		//	loading();
		}
	}
	cout << " �󸶸� �Ա� �ұ��? : "; cin >> money; cout << endl;

}

int main(void)
{
	int choice;

	while (true)
	{
		Menu();
		cout << "���� : ";
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