#include "stdafx.h"
#include <conio.h>
#include <iostream>

constexpr char g_exitCharacter = '.';

void Input(std::atomic_bool& bStop)
{
	for (char inputCharacter = 0; inputCharacter != g_exitCharacter && !bStop; inputCharacter = _getch());
	
	bStop = true;

	return;
}


int main()
{
	std::unique_ptr<ISnake> pSnake(new CSnake());
	std::unique_ptr<IField> pField(new CField(std::move(pSnake), 10, 10));
	
	std::atomic_bool bStop = false;
	
	std::thread inputThread(&Input, std::ref(bStop));

	while (!bStop && pField->Tic())
	{
		pField->Print();
		Sleep(500);
	}

	bStop = true;

	if (inputThread.joinable())
	{
		inputThread.join();
	}

	// TODO::Result processing
	puts("Game over! Press anykey to continue...");
	
	_getch();

	return 0;
}