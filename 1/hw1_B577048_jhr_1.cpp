#include <iostream>
#include <string>
using namespace std;
int main()
{
	char str[100] = {};			//문자를 담는 배열
	char checkStr[100] = {};	//회문인지 확인할 때 쓰이는 문자의 배열
	int length = 0;				//문자열의 길이
	int checkLength = 0;		//checkStr 배열의 길이
	bool isPalindrome = true;	//회문 여부
	int cnt = 0;

	cout << "문자열을 입력하시오: ";
	cin.getline(str, 100);

	length = strlen(str);		//str 문자열의 길이 대입

	cout << "입력 받은 문자열: " << str << endl;

	for(int i = 0; i < length; i++)
	{
		if(str[i] >= 65 && str[i] <= 90)
		{
			checkStr[cnt] = str[i] + 32;	//대문자를 소문자로 변경
			cnt++;
		}
		else if(str[i] >= 97 && str[i] <= 122)
		{
			checkStr[cnt] = str[i];
			cnt++;
		}
	}

	checkLength = strlen(checkStr);

	//Check isPalindrome
	for (int i = 0; i < checkLength; i++)
	{
		if (checkStr[i] != checkStr[checkLength - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome)
		cout << "회문입니다." << endl;
	else
		cout << "회문이 아닙니다." << endl;

	return 0;
}