#pragma once

#include <queue>

#include "keyboard_event.hpp"

class Keyboard
{
public:
    Keyboard();

    // Key state
    bool isKeyPressed(unsigned char keycode) const;

    // Key event buffer
    bool isKeyBufferEmpty() const;
    KeyboardEvent readKey();

    // Character buffer
    bool isCharBufferEmpty() const;
    unsigned char readChar();

    // Input events
    void onKeyPressed(unsigned char key);
    void onKeyReleased(unsigned char key);
    void onChar(unsigned char character);

    // Key auto repeat
    void enableAutoRepeatKeys();
    void disableAutoRepeatKeys();
    bool isKeysAutoRepeat() const;

    // Character auto repeat
    void enableAutoRepeatChars();
    void disableAutoRepeatChars();
    bool isCharsAutoRepeat() const;

private:
    bool keyStates[256]{};

    bool autoRepeatKeys = false;
    bool autoRepeatChars = false;

    std::queue<KeyboardEvent> keyBuffer;
    std::queue<unsigned char> charBuffer;
};