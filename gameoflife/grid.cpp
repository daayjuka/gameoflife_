#include "grid.h"
#include "raylib.h"

void Grid::Draw()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Color color = cells[i][j] ? Color{ 0, 255, 0, 255 } : Color{55, 55, 55, 255};
			DrawRectangle(j * cellSize, i * cellSize, cellSize-1, cellSize-1, color);
		}
	}
}

void Grid::SetValue(int row, int column, int value)
{
	if (IsWithinBounds(row, column)) {
		cells[row][column] = value;
	}
}

int Grid::GetValue(int row, int column)
{
	if (IsWithinBounds(row, column)) {
		return cells[row][column];
	}
	return 0;

}

bool Grid::IsWithinBounds(int row, int column)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns) {
		return true;
	}
	return false;
}

void Grid::Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cells[i][j] = 0;
		}
	}
}

void Grid::ToggleCell(int row, int column)
{
	if (IsWithinBounds(row, column)) {
		cells[row][column] = !cells[row][column];
	}
}

void Grid::FillRandom()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int randomValue = GetRandomValue(0, 4);
			cells[i][j] = (randomValue == 4) ? 1 : 0;
		}
	}
}

