#ifndef __HANDLER__
#define __HANDLER__

//핸들러
class Handler
{
private:
	Total* accArr[100];
	int accIndex = 0;
public:
	Handler();
	void Menu(void) const;			// 메뉴
	void Register(void);			// 계좌 생성
	void Input(void);				// 입금
	void Output(void);				// 출금
	void Management(void) const;	// Management
	~Handler();
};

#endif