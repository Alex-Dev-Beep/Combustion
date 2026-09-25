#pragma once

class KeyboardEvent
{
public:
    enum class EventType
    {
        Invalid,
        Pressed,
        Released
    };

public:
    KeyboardEvent();
    KeyboardEvent(EventType type, unsigned char keyCode);

    bool isPressed() const;
    bool isReleased() const;
    bool isValid() const;

    unsigned char getKeyCode() const;

private:
    EventType type;
    unsigned char keyCode;
};