#include "keyboard.hpp"

Keyboard::Keyboard()
{
}

bool Keyboard::isKeyPressed(
    unsigned char keycode) const
{
    return keyStates[keycode];
}

bool Keyboard::isKeyBufferEmpty() const
{
    return keyBuffer.empty();
}

bool Keyboard::isCharBufferEmpty() const
{
    return charBuffer.empty();
}

KeyboardEvent Keyboard::readKey()
{
    if (keyBuffer.empty())
    {
        return KeyboardEvent();
    }

    KeyboardEvent event = keyBuffer.front();

    keyBuffer.pop();

    return event;
}

unsigned char Keyboard::readChar()
{
    if (charBuffer.empty())
    {
        return 0;
    }

    unsigned char character = charBuffer.front();

    charBuffer.pop();

    return character;
}

void Keyboard::onKeyPressed(unsigned char key)
{
    keyStates[key] = true;

    keyBuffer.push(
        KeyboardEvent(
            KeyboardEvent::EventType::Pressed,
            key
        )
    );
}

void Keyboard::onKeyReleased(unsigned char key)
{
    // IMPORTANTE: false, no true.
    keyStates[key] = false;

    keyBuffer.push(
        KeyboardEvent(
            KeyboardEvent::EventType::Released,
            key
        )
    );
}

void Keyboard::onChar(unsigned char character)
{
    charBuffer.push(character);
}

void Keyboard::enableAutoRepeatKeys()
{
    autoRepeatKeys = true;
}

void Keyboard::disableAutoRepeatKeys()
{
    autoRepeatKeys = false;
}

bool Keyboard::isKeysAutoRepeat() const
{
    return autoRepeatKeys;
}

void Keyboard::enableAutoRepeatChars()
{
    autoRepeatChars = true;
}

void Keyboard::disableAutoRepeatChars()
{
    autoRepeatChars = false;
}

bool Keyboard::isCharsAutoRepeat() const
{
    return autoRepeatChars;
}