#ifndef __HANDLER__
#define __HANDLER__

//�ڵ鷯
class Handler
{
private:
	Total* accArr[100];
	int accIndex = 0;
public:
	Handler();
	void Menu(void) const;			// �޴�
	void Register(void);			// ���� ����
	void Input(void);				// �Ա�
	void Output(void);				// ���
	void Management(void) const;	// Management
	~Handler();
};

#endif