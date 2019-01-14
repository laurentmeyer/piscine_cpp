#include "FramebufferClass.hpp"
#include <iostream>

size_t	Framebuffer::_size = 0;
chtype	*Framebuffer::_buffer = nullptr;

Framebuffer::Framebuffer(void)
{
	return;
}

Framebuffer::~Framebuffer(void)
{
	return;
}

void	Framebuffer::set(unsigned int i, chtype value)
{
	Framebuffer::_buffer[i] = value;
}

chtype Framebuffer::getCurse(size_t i)
{
	return Framebuffer::_buffer[i];
}

size_t Framebuffer::getSize(void)
{
	return Framebuffer::_size;
}

void Framebuffer::clear(void)
{
	for (size_t i = 0; i < Framebuffer::_size; i++)
		Framebuffer::_buffer[i] = 0;
	// Framebuffer::set(200, ACS_UARROW | A_ALTCHARSET | A_REVERSE);
}

void Framebuffer::init(int rows, int cols)
{
	Framebuffer::_size = rows * cols;
	Framebuffer::_buffer = new chtype[Framebuffer::_size];
}