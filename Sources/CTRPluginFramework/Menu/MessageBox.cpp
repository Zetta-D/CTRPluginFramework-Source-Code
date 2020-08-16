#include "CTRPluginFramework/Menu/MessageBox.hpp"

namespace CTRPluginFramework
{
    // text box = this + 16 = str
    // _messageBox = 0-1

    TextBox::~TextBox(void)
    {
    	// delete ptr; v1
    }

    TextBox::~TextBox(void)
    {
    	TextBox::~TextBox(this);
    	// operator delete
    }

    MessageBox(const std::string &title, const std::string &message, DialogType dialogType, ClearScreen clear);
    {
    	MessageBoxImpl::MessageBoxImpl(title, message, dialogType, clear);
    }

    MessageBox(const std::string &message, DialogType dialogType, ClearScreen clear);
    {
    	MessageBoxImpl::MessageBoxImpl(title, message, dialogType, clear);
    }

    MessageBox::~MessageBox(MessageBox *this)
    {
    	//delete _messageBox;
    }

    MessageBox& MessageBox::SetClear(ClearScreen screen)
    {
    	_messageBox.screen = screen;
    	return *this;
    }

    bool operator()(void) const
    {
    	return MessageBoxImpl::operator()();
    }
}