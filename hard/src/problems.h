#pragma once

void problem2();
void problem4();

void (*problem_func[])(void) =
{
	 nullptr	// 0
	,nullptr	// 1
	,problem2	// 2
	,nullptr	// 3
	,problem4	// 4
};