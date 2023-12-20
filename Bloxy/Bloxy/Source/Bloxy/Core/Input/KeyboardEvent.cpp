#include "pchBloxy.h"
#include "KeyboardEvent.h"

#include "KeyCodes.h"


namespace Bloxy
{
    std::unordered_map<int, std::string> KeyboardEvent::s_KeyNames = {
        { BLOXY_KEY_UNKNOWN,           "Unknown"},
        { BLOXY_KEY_SPACE,             "Space"},
        { BLOXY_KEY_APOSTROPHE,        "'"},
        { BLOXY_KEY_COMMA,             ","},
        { BLOXY_KEY_MINUS,             "-"},
        { BLOXY_KEY_PERIOD,            "."},
        { BLOXY_KEY_SLASH,             "/"},
        { BLOXY_KEY_0,                 "0"},
        { BLOXY_KEY_1,                 "1"},
        { BLOXY_KEY_2,                 "2"},
        { BLOXY_KEY_3,                 "3"},
        { BLOXY_KEY_4,                 "4"},
        { BLOXY_KEY_5,                 "5"},
        { BLOXY_KEY_6,                 "6"},
        { BLOXY_KEY_7,                 "7"},
        { BLOXY_KEY_8,                 "8"},
        { BLOXY_KEY_9,                 "9"},
        { BLOXY_KEY_SEMICOLON,         ";"},
        { BLOXY_KEY_EQUAL,             "="},
        { BLOXY_KEY_A,                 "A"},
        { BLOXY_KEY_B,                 "B"},
        { BLOXY_KEY_C,                 "C"},
        { BLOXY_KEY_D,                 "D"},
        { BLOXY_KEY_E,                 "E"},
        { BLOXY_KEY_F,                 "F"},
        { BLOXY_KEY_G,                 "G"},
        { BLOXY_KEY_H,                 "H"},
        { BLOXY_KEY_I,                 "I"},
        { BLOXY_KEY_J,                 "J"},
        { BLOXY_KEY_K,                 "K"},
        { BLOXY_KEY_L,                 "L"},
        { BLOXY_KEY_M,                 "M"},
        { BLOXY_KEY_N,                 "N"},
        { BLOXY_KEY_O,                 "O"},
        { BLOXY_KEY_P,                 "P"},
        { BLOXY_KEY_Q,                 "Q"},
        { BLOXY_KEY_R,                 "R"},
        { BLOXY_KEY_S,                 "S"},
        { BLOXY_KEY_T,                 "T"},
        { BLOXY_KEY_U,                 "U"},
        { BLOXY_KEY_V,                 "V"},
        { BLOXY_KEY_W,                 "W"},
        { BLOXY_KEY_X,                 "X"},
        { BLOXY_KEY_Y,                 "Y"},
        { BLOXY_KEY_Z,                 "Z"},
        { BLOXY_KEY_LEFT_BRACKET,      "["},
        { BLOXY_KEY_BACKSLASH,         "\\"},
        { BLOXY_KEY_RIGHT_BRACKET,     "]"},
        { BLOXY_KEY_GRAVE_ACCENT,      "`"},
        { BLOXY_KEY_WORLD_1,           "Non-US #1"},
        { BLOXY_KEY_WORLD_2,           "Non-US #2"},
        { BLOXY_KEY_ESCAPE,            "Escape"},
        { BLOXY_KEY_ENTER,             "Enter"},
        { BLOXY_KEY_TAB,               "Tab"},
        { BLOXY_KEY_BACKSPACE,         "Backspace"},
        { BLOXY_KEY_INSERT,            "Insert"},
        { BLOXY_KEY_DELETE,            "Delete"},
        { BLOXY_KEY_RIGHT,             "Right Arrow"},
        { BLOXY_KEY_LEFT,              "Left Arrow"},
        { BLOXY_KEY_DOWN,              "Down Arrow"},
        { BLOXY_KEY_UP,                "Up Arrow"},
        { BLOXY_KEY_PAGE_UP,           "PgUp"},
        { BLOXY_KEY_PAGE_DOWN,         "PgDn"},
        { BLOXY_KEY_HOME,              "Home"},
        { BLOXY_KEY_END,               "End"},
        { BLOXY_KEY_CAPS_LOCK,         "CapsLock"},
        { BLOXY_KEY_SCROLL_LOCK,       "ScrollLock"},
        { BLOXY_KEY_NUM_LOCK,          "NumLock"},
        { BLOXY_KEY_PRINT_SCREEN,      "PrtSc"},
        { BLOXY_KEY_PAUSE,             "Pause"},
        { BLOXY_KEY_F1,                "F1"},
        { BLOXY_KEY_F2,                "F2"},
        { BLOXY_KEY_F3,                "F3"},
        { BLOXY_KEY_F4,                "F4"},
        { BLOXY_KEY_F5,                "F5"},
        { BLOXY_KEY_F6,                "F6"},
        { BLOXY_KEY_F7,                "F7"},
        { BLOXY_KEY_F8,                "F8"},
        { BLOXY_KEY_F9,                "F9"},
        { BLOXY_KEY_F10,               "F10"},
        { BLOXY_KEY_F11,               "F11"},
        { BLOXY_KEY_F12,               "F12"},
        { BLOXY_KEY_F13,               "F13"},
        { BLOXY_KEY_F14,               "F14"},
        { BLOXY_KEY_F15,               "F15"},
        { BLOXY_KEY_F16,               "F16"},
        { BLOXY_KEY_F17,               "F17"},
        { BLOXY_KEY_F18,               "F18"},
        { BLOXY_KEY_F19,               "F19"},
        { BLOXY_KEY_F20,               "F20"},
        { BLOXY_KEY_F21,               "F21"},
        { BLOXY_KEY_F22,               "F22"},
        { BLOXY_KEY_F23,               "F23"},
        { BLOXY_KEY_F24,               "F24"},
        { BLOXY_KEY_F25,               "F25"},
        { BLOXY_KEY_NUMPAD_0,          "Numpad 0"},
        { BLOXY_KEY_NUMPAD_1,          "Numpad 1"},
        { BLOXY_KEY_NUMPAD_2,          "Numpad 2"},
        { BLOXY_KEY_NUMPAD_3,          "Numpad 3"},
        { BLOXY_KEY_NUMPAD_4,          "Numpad 4"},
        { BLOXY_KEY_NUMPAD_5,          "Numpad 5"},
        { BLOXY_KEY_NUMPAD_6,          "Numpad 6"},
        { BLOXY_KEY_NUMPAD_7,          "Numpad 7"},
        { BLOXY_KEY_NUMPAD_8,          "Numpad 8"},
        { BLOXY_KEY_NUMPAD_9,          "Numpad 9"},
        { BLOXY_KEY_NUMPAD_DECIMAL,    "Numpad ." },
        { BLOXY_KEY_NUMPAD_DIVIDE,     "Numpad /" },
        { BLOXY_KEY_NUMPAD_MULTIPLY,   "Numpad *" },
        { BLOXY_KEY_NUMPAD_SUBTRACT,   "Numpad -" },
        { BLOXY_KEY_NUMPAD_ADD,        "Numpad +" },
        { BLOXY_KEY_NUMPAD_ENTER,      "Numpad Enter" },
        { BLOXY_KEY_NUMPAD_EQUAL,      "Numpad =" },
        { BLOXY_KEY_LEFT_SHIFT,        "Left Shift" },
        { BLOXY_KEY_RIGHT_SHIFT,       "Right Shift" },
        { BLOXY_KEY_SHIFT,             "Shift"},
        { BLOXY_KEY_LEFT_CONTROL,      "Left Control" },
        { BLOXY_KEY_RIGHT_CONTROL,     "Right Control" },
        { BLOXY_KEY_CONTROL,           "Control" },
        { BLOXY_KEY_LEFT_ALT,          "Left Alt" },
        { BLOXY_KEY_RIGHT_ALT,         "Right Alt" },
        { BLOXY_KEY_ALT,               "Alt" },
        { BLOXY_KEY_LEFT_SUPER,        "Left Super" },
        { BLOXY_KEY_RIGHT_SUPER,       "Right Super" },
        { BLOXY_KEY_SUPER,             "Super" },
        { BLOXY_KEY_MENU,              "Menu"},
    };
    bool operator==(const KeyboardEvent::Code& code, int scancode)
    {
        bool result;
        switch (scancode)
        {
        case BLOXY_KEY_SHIFT:
            result = (code.Value == BLOXY_KEY_LEFT_SHIFT) || (code.Value == BLOXY_KEY_RIGHT_SHIFT);
            break;
        case BLOXY_KEY_CONTROL:
            result = (code.Value == BLOXY_KEY_LEFT_CONTROL) || (code.Value == BLOXY_KEY_RIGHT_CONTROL);
            break;
        case BLOXY_KEY_ALT:
            result = (code.Value == BLOXY_KEY_LEFT_ALT) || (code.Value == BLOXY_KEY_RIGHT_ALT);
            break;
        case BLOXY_KEY_SUPER:
            result = (code.Value == BLOXY_KEY_LEFT_SUPER) || (code.Value == BLOXY_KEY_RIGHT_SUPER);
            break;
        default:
            result = (code.Value == scancode);
            break;
        }

        return result;
    }

    bool operator==(int scancode, const KeyboardEvent::Code& code)
    {
        return code == scancode;
    }

    bool operator!=(const KeyboardEvent::Code& code, int scancode)
    {
        return !(code == scancode); 
    }

    bool operator!=(int scancode, const KeyboardEvent::Code& code)
    {
        return code != scancode;
    }

    KeyboardEvent::Code::Code(int value)
        :Value(value)
    {
    }

    std::string KeyboardEvent::ToString() const
    {
        std::stringstream ss;
        ss << this->GetName() << ": ";
        if (s_KeyNames.find(m_Key.Value) == s_KeyNames.end())
            ss << m_Key.Value;
        else ss << s_KeyNames[m_Key.Value];
        return ss.str();
    }

    std::string CharEvent::ToString() const
    {
        std::stringstream ss;
        ss << this->GetName() << ": " << (char)m_Char;
        return ss.str();
    }
}


