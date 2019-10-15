#include "KingException.h"
#include <sstream>


KingException::KingException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* KingException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* KingException::GetType() const noexcept
{
	return "King Exception";
}

int KingException::GetLine() const noexcept
{
	return line;
}

const std::string& KingException::GetFile() const noexcept
{
	return file;
}

std::string KingException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}