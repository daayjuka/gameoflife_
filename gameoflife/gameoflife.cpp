#include <iostream>
#include "raylib.h"
#include "simulation.h"

int main()
{
	const int W_WIDHT = 750;
	const int W_HEIGHT = 750;
	int FPS = 12;
	const int CELL_SIZE = 25;


	InitWindow(W_WIDHT, W_HEIGHT, "GAME OF LIFE");
	SetTargetFPS(FPS);
	Simulation simulation(W_WIDHT, W_HEIGHT, CELL_SIZE);


	while (WindowShouldClose() == false) {

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePosition = GetMousePosition();
			int row = mousePosition.y / CELL_SIZE;
			int column = mousePosition.x / CELL_SIZE;
			simulation.ToggleCell(row, column);

		}
		if (IsKeyPressed(KEY_ENTER)) {
			simulation.Start();
				SetWindowTitle("GAME OF LIFE RUNNING...");
		}
		else if (IsKeyPressed(KEY_SPACE)) {
			simulation.Stop();
			SetWindowTitle("GAME OF LIFE HAS STOPPED...");

		}
		else if (IsKeyPressed(KEY_F)) {
			FPS += 2;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_S)) {
			if (FPS > 5) {
				FPS -= 2;
				SetTargetFPS(FPS);
			}
		}
		else if (IsKeyPressed(KEY_R))
		{
			simulation.CreateRandomState();
		}
		else if (IsKeyPressed(KEY_C))
		{
			simulation.ClearGrid();
		}



		simulation.Update();


		BeginDrawing();
		ClearBackground(GRAY);
		simulation.Draw();
		EndDrawing();

	}

	CloseWindow();

}