#include "CharBox.h"

CharBox::CharBox()
{
	m_boxSize	= 0;
	m_height	= 0;
	m_width		= 0;
	m_cbox		= NULL;
}

CharBox::CharBox(int width, int height)
{
	m_boxSize	= (width+1)*height;
	m_height	= height;
	m_width		= width;
	m_cbox		= (char*)malloc(sizeof(char)*m_boxSize);

	memset(m_cbox, '-', m_boxSize);

	for(int i=width; i<m_boxSize; i+=(width+1))
	{
		if (i == m_boxSize-1)
		{
			m_cbox[i] = '\0';
		}
		else
		{
			m_cbox[i] = '\n';
		}
	}
}

void CharBox::SetupCharBox(int width, int height)
{
	m_boxSize	= (width+1)*height;
	m_height	= height;
	m_width		= width;
	m_cbox		= (char*)malloc(sizeof(char)*m_boxSize);

	memset(m_cbox, '-', m_boxSize);

	for(int i=width; i<m_boxSize; i+=(width+1))
	{
		if (i == m_boxSize-1)
		{
			m_cbox[i] = '\0';
		}
		else
		{
			m_cbox[i] = '\n';
		}
	}
}


CharBox::~CharBox(void)
{
	free(m_cbox);
}

void CharBox::InsertChar(char c, int x, int y)
{
	if(!(x < m_width && y < m_height))
	{
		printf("ERROR: Trying to place char outside of box boundries!");
		exit(-1);
	}
	int numNewLines = (m_width*y+x)/m_width;
	m_cbox[m_width*y+x+numNewLines] = c;
}

void CharBox::InsertString(int x, int y, char * format, ...)
{
	char buffer[256];
#pragma warning( disable: 4996 )
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);

	int i=0;
	for (char* temp = buffer; *temp != '\0'; temp++)
	{
		this->InsertChar(*temp, x+i, y);
		i++;
	}
}

void CharBox::PrintCharBox()
{
	printf("%s", m_cbox);
}