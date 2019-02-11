#include "stdafx.h"

int main()
{
	GameModel model(10, 10);
	
	GameController controller(&model);
	
	GameView view(&model);
	
	model.AddObserver(&view);

	controller.Start();

	// TODO::Result processing
	puts("Game over! Press anykey to continue...");
	
	_getch();

	return 0;
}