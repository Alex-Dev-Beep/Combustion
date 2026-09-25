#include "keyboard_event.hpp"

KeyboardEvent::KeyboardEvent()
    : type(EventType::Invalid),
      keyCode(0)
{
}

KeyboardEvent::KeyboardEvent(
    EventType type,
    unsigned char keyCode)
    : type(type),
      keyCode(keyCode)
{
}

bool KeyboardEvent::isPressed() const
{
    return type == EventType::Pressed;
}

bool KeyboardEvent::isReleased() const
{
    return type == EventType::Released;
}

bool KeyboardEvent::isValid() const
{
    return type != EventType::Invalid;
}

unsigned char KeyboardEvent::getKeyCode() const
{
    return keyCode;
}