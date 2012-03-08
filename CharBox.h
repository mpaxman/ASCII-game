// CharBox.h
#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

class CharBox
{
public:
	CharBox();
	CharBox(int width, int height);
	~CharBox(void);

	void SetupCharBox(int width, int height);
	void InsertChar(char c, int x, int y);
	void InsertString(int x, int y, char * format, ...);
	void PrintCharBox();

private:
	int		m_width;
	int		m_height;

	char	*m_cbox;
	int		m_boxSize;
};

