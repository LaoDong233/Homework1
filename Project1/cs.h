#pragma once
#define M 16
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<string.h>
#include<time.h>
#include <graphics.h>
#define DEBUG true
#if DEBUG
#define BLOCK ".\\img\\block.png"
#define BLOCK_ ".\\img\\backblock.png"
#define A_ ".\\img\\2.png"
#define B_ ".\\img\\4.png"
#define C_ ".\\img\\8.png"
#define D_ ".\\img\\16.png"
#define E_ ".\\img\\32.png"
#define F_ ".\\img\\64.png"
#define G_ ".\\img\\128.png"
#define H_ ".\\img\\256.png"
#define I_ ".\\img\\512.png"
#define J_ ".\\img\\1024.png"
#define K_ ".\\img\\2048.png"
#else
#define BLOCK "D:\\2048\\img\\block.png"
#define BLOCK_ "D:\\2048\\img\\backblock.png"
#define A_ "D:\\2048\\img\\2.png"
#define B_ "D:\\2048\\img\\4.png"
#define C_ "D:\\2048\\img\\8.png"
#define D_ "D:\\2048\\img\\16.png"
#define E_ "D:\\2048\\img\\32.png"
#define F_ "D:\\2048\\img\\64.png"
#define G_ "D:\\2048\\img\\128.png"
#define H_ "D:\\2048\\img\\256.png"
#define I_ "D:\\2048\\img\\512.png"
#define J_ "D:\\2048\\img\\1024.png"
#define K_ "D:\\2048\\img\\2048.png"
#endif
#if false
#endif