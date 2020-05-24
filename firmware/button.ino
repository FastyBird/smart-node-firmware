/*

BUTTON MODULE

Copyright (C) 2018 FastyBird Ltd. <info@fastybird.com>

*/

#if BUTTON_SUPPORT

#include <DebounceEvent.h>
#include <Vector.h>

typedef struct {
    DebounceEvent * button;
    uint8_t         register_address;      // Address in communication register to store state
} button_t;

Vector<button_t> _buttons;

// -----------------------------------------------------------------------------
// MODULE PRIVATE
// -----------------------------------------------------------------------------

uint8_t _buttonMapEvent(
    const uint8_t event,
    const uint8_t count,
    const uint16_t length
) {
    if (event == EVENT_PRESSED) {
        return BUTTON_EVENT_PRESSED;

    } else if (event == EVENT_CHANGED) {
        return BUTTON_EVENT_CLICK;

    } else if (event == EVENT_RELEASED) {
        if (count == 1) {
            if (length > BUTTON_LNGLNGCLICK_DELAY) {
                return BUTTON_EVENT_LNGLNGCLICK;

            } else if (length > BUTTON_LNGCLICK_DELAY) {
                return BUTTON_EVENT_LNGCLICK;
            }

            return BUTTON_EVENT_CLICK;

        } else if (count == 2) {
            return BUTTON_EVENT_DBLCLICK;

        } else if (count == 3) {
            return BUTTON_EVENT_TRIPLECLICK;
        }
    }

    return BUTTON_EVENT_NONE;
}

// -----------------------------------------------------------------------------

void _buttonEvent(
    const uint8_t id,
    const uint8_t event
) {
    if (id >= buttonCount() || event == 0) {
        return;
    }

    #if DEBUG_SUPPORT
        DPRINT(F("[BUTTON] Button #"));
        DPRINT(id);
        DPRINT(F(" event "));
        DPRINTLN(event);
    #endif

    // Store state into communication register
    communicationWriteEventInput(_buttons[id].register_address, (uint8_t) event);
}

// -----------------------------------------------------------------------------
// MODULE API
// -----------------------------------------------------------------------------

int buttonCount()
{
    return _buttons.size();
}

// -----------------------------------------------------------------------------
// MODULE CORE
// -----------------------------------------------------------------------------

void buttonSetup()
{
    uint8_t register_address;

    #if BUTTON1_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON1_PIN, BUTTON1_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON2_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON2_PIN, BUTTON2_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON3_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON3_PIN, BUTTON3_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON4_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON4_PIN, BUTTON4_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON5_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON5_PIN, BUTTON5_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON6_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON6_PIN, BUTTON6_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON7_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON7_PIN, BUTTON7_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON8_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON8_PIN, BUTTON8_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON9_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON9_PIN, BUTTON9_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON10_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON10_PIN, BUTTON10_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON11_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON11_PIN, BUTTON11_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON12_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON12_PIN, BUTTON12_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON13_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON13_PIN, BUTTON13_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON14_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON14_PIN, BUTTON14_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON15_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON15_PIN, BUTTON15_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif
    #if BUTTON16_PIN != GPIO_NONE
    {
        register_address = communicationRegisterEventInput();

        _buttons.push_back((button_t) {new DebounceEvent(BUTTON16_PIN, BUTTON16_MODE, BUTTON_DEBOUNCE_DELAY, BUTTON_DBLCLICK_DELAY), register_address});
    }
    #endif

    #if DEBUG_SUPPORT
        DPRINT(F("[BUTTON] Number of buttons: "));
        DPRINTLN(buttonCount());
    #endif
}

// -----------------------------------------------------------------------------

void buttonLoop()
{
    for (uint8_t i = 0; i < buttonCount(); i++) {
        if (uint8_t event = _buttons[i].button->loop()) {
            uint8_t count = _buttons[i].button->getEventCount();
            unsigned long length = _buttons[i].button->getEventLength();

            uint8_t mapped = _buttonMapEvent(event, count, length);

            _buttonEvent(i, mapped);
        }
    }
}

#endif // BUTTON_SUPPORT
