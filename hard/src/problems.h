#pragma once

void problem2();
void problem4();
void problem6();
void problem9();
void problem12();
void problem13();
void problem17();
void problem18();
void problem25();
void problem32();
void problem35();

void (*problem_func[])(void) =
{
	 nullptr	// 0
	,nullptr	// 1
	,problem2	// 2
	,nullptr	// 3
	,problem4	// 4
	,nullptr	// 5
	,problem6	// 6
	,nullptr	// 7
	,nullptr	// 8
	,problem9	// 9
	,nullptr	// 10
	,nullptr	// 11
	,problem12	// 12
	,problem13	// 13
	,nullptr	// 14
	,nullptr	// 15
	,nullptr	// 16
	,problem17	// 17
	,problem18	// 18
	,nullptr	// 19
	,nullptr	// 20
	,nullptr	// 21
	,nullptr	// 22
	,nullptr	// 23
	,nullptr	// 24
	,problem25  // 25
	,nullptr    // 26
	,nullptr    // 27
	,nullptr    // 28
	,nullptr    // 29
	,nullptr    // 30
	,nullptr    // 31
	,problem32  // 32
	,nullptr	// 33
	,nullptr	// 34
	,problem35  // 35
};