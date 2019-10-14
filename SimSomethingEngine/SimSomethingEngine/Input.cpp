#include "Input.h"

bool Input::KeyIsPressed(unsigned char keycode) const noexcept
{
	return keystates[keycode];
}

std::optional<Input::Event> Input::ReadKey() noexcept
{
	if (keybuffer.size() > 0u)
	{
		Input::Event e = keybuffer.front();
		keybuffer.pop();
		return e;
	}
	return {};
}

bool Input::KeyIsEmpty() const noexcept
{
	return keybuffer.empty();
}

std::optional<char> Input::ReadChar() noexcept
{
	if (charbuffer.size() > 0u)
	{
		unsigned char charcode = charbuffer.front();
		charbuffer.pop();
		return charcode;
	}
	return {};
}

bool Input::CharIsEmpty() const noexcept
{
	return charbuffer.empty();
}

void Input::FlushKey() noexcept
{
	keybuffer = std::queue<Event>();
}

void Input::FlushChar() noexcept
{
	charbuffer = std::queue<char>();
}

void Input::Flush() noexcept
{
	FlushKey();
	FlushChar();
}

void Input::EnableAutorepeat() noexcept
{
	autorepeatEnabled = true;
}

void Input::DisableAutorepeat() noexcept
{
	autorepeatEnabled = false;
}

bool Input::AutorepeatIsEnabled() const noexcept
{
	return autorepeatEnabled;
}

void Input::OnKeyPressed(unsigned char keycode) noexcept
{
	keystates[keycode] = true;
	keybuffer.push(Input::Event(Input::Event::Type::Press, keycode));
	TrimBuffer(keybuffer);
}

void Input::OnKeyReleased(unsigned char keycode) noexcept
{
	keystates[keycode] = false;
	keybuffer.push(Input::Event(Input::Event::Type::Release, keycode));
	TrimBuffer(keybuffer);
}

void Input::OnChar(char character) noexcept
{
	charbuffer.push(character);
	TrimBuffer(charbuffer);
}

void Input::ClearState() noexcept
{
	keystates.reset();
}

template<typename T>
void Input::TrimBuffer(std::queue<T>& buffer) noexcept
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}