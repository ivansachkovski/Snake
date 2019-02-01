#include "stdafx.h"

// Use this character to signalize about edn of the game
constexpr int g_exitCharacter = '.';

void Input(std::atomic_bool& bStop, std::atomic_int& code)
{
	int inputCharacter = 0;
	while (!bStop && inputCharacter != g_exitCharacter)
	{
		code = inputCharacter;
		inputCharacter = _getch();
	}

	bStop = true;

	return;
}


int main()
{
	// Create all necessary objects
	std::unique_ptr<ISnake> pSnake(new CSnake());
	std::unique_ptr<IField> pField(new CField(std::move(pSnake), 10, 10));
	
	// Use variable bStop to signalize about any end of the game
	std::atomic_bool bStop = false;
	std::atomic_int inputCode = 0;

	// Use separate thread to catch input
	std::thread inputThread(&Input, std::ref(bStop), std::ref(inputCode));

	// Main loop
	while (!bStop)
	{
		int actionCode = inputCode;
		
		bool bSuccess = pField->Tic(actionCode);
		
		pField->PrintToConsole();
		
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