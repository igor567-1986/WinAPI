//Windows API
//API - Application Programming Interface
//		(���������� ��������� ������������)
//��� ����� ������� � ������ ������� ������������ ��� ���������� ����������.
#include<Windows.h>

//#define MSG_BOX

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//INT	 - ��� ������������ ��������
	//WINAPI - ���������� � ������ ������� (Calling convention)
	//Calling convention ���������� ����� ������� ������� ����, ����������, ��� ����������,
	//� ��� �� ����������, ��� ��������� ���������� � �������.
	//��� ������� C/C++ ����������, �� ��������� ����������� ��������� __cdecl,
	//� WinAPI ������ ����������� ��������� __stdcall
	//https://learn.microsoft.com/en-us/cpp/cpp/argument-passing-and-naming-conventions?view=msvc-170
	//caller - ���������� ������� (�������, ������� �������� ������ �������)
	//callee - ���������� ������� (�������, ������� ��������)
	/*
		-------------------------------------------------
			hInstance - *.exe-���� ���������
			hPrevInst - ���������� ��������� ���������
			lpCmdLine - ��������� ������, ������� ���������� �������� ��� �������.
						���� ��� ��������� ��������, �� � ���� ����� �������� ����������� ����,
						���� ��� �������, ��  ���� ����� �������� ����������� ��������, � �.�.
						��������� ������ ������������ ����� ������ �����, ������� ��������� ��������
						������ �������� ��� *.exe-�����.
						lp - LongPointer (���������� �������)
			nCmdShow -  ����� ����������� ���� ��� �������
						(���������� �� ���� �����, �������� � ����, �������� �� ������ �����.....)
						n - number (���������� ������)
		-------------------------------------------------
		*/
#ifdef MSG_BOX
	MessageBox(NULL,  //������������ ����
		"������! ��� ���� ������ ���������", "��������� ���� ���������",
		MB_YESNOCANCEL | MB_HELP // ����� ������
		| MB_ICONWARNING //������
		| MB_DEFBUTTON3  //������ �� ���������
		| MB_SYSTEMMODAL // WS_EX_TOPMOST - ������ ���� ����
		| MB_SETFOREGROUND
	);
#endif // MSG_

	
	return 0;
}