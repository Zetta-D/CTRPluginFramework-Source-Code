#include "CTRPluginFramework/Menu/MessageBox.hpp"

namespace CTRPluginFramework
{
    MessageBox::~MessageBox(void)
    {
        // delete _messageBox;
    }

    MessageBox::MessageBox(const std::string &title, const std::string &message, DialogType dialogType, ClearScreen clear);
    {
        _messageBox = std::make_unique<MessageBox>(new MessageBox(title, message, dialogType, clear));
    }

    MessageBox::MessageBox(const std::string &message, DialogType dialogType, ClearScreen clear);
    {
        _messageBox = std::make_unique<MessageBox>(new MessageBox("", message, dialogType, clear));
    }

    MessageBox& MessageBox::SetClear(ClearScreen screen)
    {
    	_messageBox->screen = screen;
    	return *this;
    }

    bool MessageBox::operator()(void) const
    {
    	return _messageBox->operator()();
    }
}
