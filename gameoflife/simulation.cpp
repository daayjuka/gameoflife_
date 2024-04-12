#include "simulation.h"
#include <vector>
#include <utility>

void Simulation::Draw()
{
	grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
	grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
	int liveNeighbors = 0;
	std::vector<std::pair<int, int>> NeighborOffSets = { {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}, };

	for(const auto& offset : NeighborOffSets)
	{
		int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
		int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
		liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
	}
	return liveNeighbors;

}

void Simulation::Update()
{
	if (IsRunning()){
		for (int i = 0; i < grid.GetRows(); i++)
		{
			for (int j = 0; j < grid.GetColumns(); j++)
			{
				int liveNeighbors = CountLiveNeighbors(i, j);
				int cellValue = grid.GetValue(i, j);
				if (cellValue == 1)
				{
					if (liveNeighbors > 3 || liveNeighbors < 2) {
						tempGrid.SetValue(i, j, 0);
					}
					else {
						tempGrid.SetValue(i, j, 1);
					}
				}
				else {
					if (liveNeighbors == 3) {
						tempGrid.SetValue(i, j, 1);
					}
					else {
						tempGrid.SetValue(i, j, 0);
				}
				}
			}
		}
		grid = tempGrid;
	}
}

void Simulation::ClearGrid()
{
	if (!IsRunning()) {
		grid.Clear();
	}
}

void Simulation::CreateRandomState()
{
	if (!IsRunning()) {
		grid.FillRandom();
	}
}

void Simulation::ToggleCell(int row, int column)
{
	if (!IsRunning()) {
		grid.ToggleCell(row, column);
	}
}
