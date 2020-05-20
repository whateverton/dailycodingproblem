/*
#23 - EASY
This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

Date: 21/04/2020
Dev Time: 18h50 - 
*/
#include <stack>

struct pos
{
	int x;
	int y;


	inline bool operator==(const pos& lhs) { return (lhs.x == this->x && lhs.y == this->y); }
	inline bool operator!=(const pos& lhs) { return (lhs.x != this->x || lhs.y != this->y); }
};

typedef struct node
{
	pos position;	// Posi��o desse n�
	int score;		// Custo de n� at� o destino
	bool consumed = false;	// J� foi 100% verificado?
	node* parent;			// N� pai ou  n� de origem
}node;

// Pega o n� com menor custo para ser verificado
int getBestNodeIndex(std::vector<node*>& nodes)
{
	int bestScoreIndex = -1;

	for (size_t i = 0; i < nodes.size(); i++)
	{
		// Se o n� j� foi usado continua no loop, sem fazer verifica��o, pois j� foi feita antes
		if (nodes[i]->consumed)
		{
			continue;
		}

		// Se n�o existe melhor pontua��o, guarda o indice do n� atual como o de melhor pontua��o
		if (bestScoreIndex == -1)
		{
			bestScoreIndex = i;
			continue;
		}

		// Caso j� exista alguma pontua��o, verifica se a pontua��o atual � menor que a definida anteriormente
		// Se for menor, substitui o indice
		if (nodes[i]->score < nodes[bestScoreIndex]->score)
		{
			bestScoreIndex = i;
		}
	}

	// Quando encontrado o n� de melhor pontua��o, marca como consumido
	nodes[bestScoreIndex]->consumed = true;
	return bestScoreIndex;
}

// Calcula a distancia manhatam entre n�s
int getDistanceFromNodes(pos start, pos end)
{
	int distance = 0;

	distance += std::abs(start.y - end.y); // Distancia em Y
	distance += std::abs(start.x - end.x); // Distancia em X

	return distance;
}

// Adiciona um n� a ser verificado
void addNode(std::vector<node*>& nodes, node* newNode, pos start)
{

	for (size_t i = 0; i < nodes.size(); i++)
	{
		// Se eu estou tentando adicionar um n� que j� existe
		if (nodes[i]->position == newNode->position)
		{
			// Verifico se a posi��o � diferente *
			if (nodes[i]->position != start)
			{
				// Caso o score seja menor, substitui o score e a n� de origem
				if (nodes[i]->score < newNode->score)
				{
					nodes[i]->score = newNode->score;
					nodes[i]->parent = newNode->parent;
				}
			}

			return;
		}
	}

	// S� adiciona na lista se n�o encontrar nenhum n� igual na lista
	nodes.push_back(newNode);
}

void calculateNodes(bool** matrix, int M, int N, std::vector<node*>& nodes, node* currNode, pos start, pos end)
{
	bool added = false;
	pos position = currNode->position;


	if (position.x > 0) {
		if (!matrix[position.y][position.x - 1]) {
			//Can go to left
			pos possiblePos = { position.y, position.x - 1 };
			int g = getDistanceFromNodes(possiblePos, start);
			int h = getDistanceFromNodes(possiblePos, end);

			addNode(nodes, new node({ possiblePos,  g + h, false, currNode }), start);
			added = true;

		}
	}

	if (position.x < M - 1) {
		if (!matrix[position.y][position.x + 1]) {
			//Can go to right
			pos possiblePos = { position.y, position.x + 1 };
			int g = getDistanceFromNodes(possiblePos, start);
			int h = getDistanceFromNodes(possiblePos, end);

			addNode(nodes, new node({ possiblePos,  g + h, false, currNode }), start);
			added = true;
		}
	}

	if (position.y > 0)
	{
		if (!matrix[position.y - 1][position.x])
		{
			//Can go up
			pos possiblePos = { position.y - 1, position.x };
			int g = getDistanceFromNodes(possiblePos, start);
			int h = getDistanceFromNodes(possiblePos, end);

			addNode(nodes, new node({ possiblePos,  g + h, false, currNode }), start);
			added = true;
		}
	}

	if (position.y < N - 1)
	{
		if (!matrix[position.y + 1][position.x])
		{
			//Can go down
			pos possiblePos = { position.y + 1, position.x };
			int g = getDistanceFromNodes(possiblePos, start);
			int h = getDistanceFromNodes(possiblePos, end);

			addNode(nodes, new node({ possiblePos,  g + h, false, currNode }), start);
			added = true;
		}
	}
}

// Verifica se j� encontrou o final
bool hasEnd(std::vector<node*>& allNodes, pos end)
{
	// Loop para verificar se dentro dos n�s conhecidos j� foi encontrado o final desejado
	for (size_t i = 0; i < allNodes.size(); i++)
	{
		if (allNodes[i]->position == end)
		{
			return true;
		}
	}

	return false;
}

// Verifica se ainda a algum n� que n�o foi consumido
bool hasOptions(std::vector<node*>& allNodes)
{
	for (size_t i = 0; i < allNodes.size(); i++)
	{
		if (!allNodes[i]->consumed)
		{
			return true;
		}
	}

	return false;
}

// Calcula quantos passos s�o necess�rios para ir do inicio at� o fim desejado
int calculateSteps(std::vector<node*>& allNodes, pos end)
{
	for (size_t i = 0; i < allNodes.size(); i++)
	{
		// Roda pela lista at� encontrar o n� final
		if (allNodes[i]->position == end)
		{
			int steps = 0;
			node* parent = allNodes[i]->parent;

			// Aqui volta de tr�s para frente, e conta quantos passos at� chegar no in�cio
			while (parent != nullptr)
			{
				parent = parent->parent;
				steps++;
			}
			return steps;
		}
	}

	return -1;
}

#ifdef _23_EASY_
void CurrentSolution()
{
	const int M = 4;
	const int N = 4;

	// Matriz dada no enunciado =========
	bool matrix[M][N] = {
		{false,	false,	false, false},
		{true,	true,	false, true},
		{false,	false,	false, false},
		{false,	false,	false, false}
	};
	// ==================================
	
	// Convertendo para facilitar a passagem de parametro ====
	bool* simpleMatrix[M];
	for (size_t i = 0; i < M; i++)
	{
		simpleMatrix[i] = matrix[i];
	}
	// =======================================================

	pos start = { 3, 0 }; // Posi��o inicial - dada no enunciado
	pos end = { 0, 0 };   // Posi��o final desejada - dada no enunciado
	std::vector<node*> allNodes;

	node* intial = new node({ start, 0, true, nullptr });	// O primeiro n� obrigat�riamente � na posi��o inicial
	addNode(allNodes, intial, start);	// Adiciona o n� inicial na lista de n�s
	
	calculateNodes(simpleMatrix, M, N, allNodes, intial, start, end);

	bool noEndOnList = false;
	while ((noEndOnList = (hasEnd(allNodes, end) == false)) && hasOptions(allNodes))
	{
		int nextIndex = getBestNodeIndex(allNodes);
		calculateNodes(simpleMatrix, M, N, allNodes, allNodes[nextIndex], start, end);
	}

	if (noEndOnList)
	{
		cout<< "No possible outcome!";
	}
	else
	{
		std::cout << "Steps: " << calculateSteps(allNodes, end);
	}
}
#endif