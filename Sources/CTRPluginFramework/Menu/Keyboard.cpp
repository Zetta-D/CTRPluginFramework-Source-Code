#include "CTRPluginFramework/Menu/Keyboard.hpp"

namespace CTRPluginFramework
{
    /*
        ***To do***
        ConvertToU64
        ConvertToU32
        ConvertToU16
        ConvertToU8
        ConvertToFloat
        ConvertToDouble
    */

    enum class Layout
	{
		Qwerty,
		Decimal,
		Hexadecimal
	};

    Keyboard::Keyboard(const std::string &text)
    {
    	_keyboard = std::make_unique<KeyboardImpl>(new KeyboardImpl(text));
    	_hexadecimal = true;
    }

    Keyboard::Keyboard(const std::string &text, const std::vector<std::string> &options)
    {
    	_keyboard = std::make_unique<KeyboardImpl>(new KeyboardImpl(text));
    	_keyboard->Populate(options);
    	_hexadecimal = false;
    	_isPopulated = !options.empty() ? true : false;
    }

    Keyboard::Keyboard(const std::vector<std::string> &options)
    {
    	_keyboard = std::make_unique<KeyboardImpl>(new KeyboardImpl(""));
    	_keyboard->Populate(options);
    	_hexadecimal = false;
    	_isPopulated = !options.empty() ? true : false;
    }

    Keyboard::~Keyboard(void)
    {
    	_keyboard->~KeyboardImpl();
    	// delete _keyboard;
    }

    void Keyboard::IsHexadecimal(bool isHex)
    {
    	_hexadecimal = isHex;
    }

    void Keyboard::SetMaxLength(u32 maxValue) const
    {
    	_keyboard->SetMaxInput(maxValue);
    }

    void Keyboard::SetCompareCallback(CompareCallback callback) const
    {
    	_keyboard->SetCompareCallback(callback);
    }

    void Keyboard::Populate(const std::vector<std::string> &input)
    {
    	_keyboard->Populate(input);
    	_isPopulated = true;
    }

    int Keyboard::Open(void) const
    {
    	return _isPopulated ? _keyboard->Run() : -1;
    }

    int Keyboard::Open(u64 &output) const
    {
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(16);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU64);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU64(_keyboard->GetInput(), _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(u64 &output, u64 start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(16);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU64);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU64(isEmpty ? Utils::Format(_hexadecimal ? "%X" : "%d", start) : _keyboard->GetInput()
    			, _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(float &output) const
    {
    	_keyboard->SetLayout(Layout::Decimal)
    	_keyboard->SetConvertCallback(ConvertToFloat);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToFloat(_keyboard->GetInput(), _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(float &output, float start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(Layout::Decimal)
    	_keyboard->SetConvertCallback(ConvertToFloat);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToFloat(isEmpty ? Utils::ToString(start, 4) : _keyboard->GetInput(),
    		_keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(double &output) const
    {
    	_keyboard->SetLayout(Layout::Decimal)
    	_keyboard->SetConvertCallback(ConvertToDouble);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToDouble(_keyboard->GetInput(), _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(double &output, double start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(Layout::Decimal)
    	_keyboard->SetConvertCallback(ConvertToDouble);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToDouble(isEmpty ? Utils::Format("%.4lf", start) : _keyboard->GetInput(), 
    			_keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(std::string &output) const
    {
    	_keyboard->SetLayout(Layout::Qwerty)
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = _keyboard->GetInput();
    	return res;
    }

    int Keyboard::Open(std::string &output, const std::string &start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(Layout::Qwerty)
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = isEmpty ? start : _keyboard->GetInput();
    	return res;
    }

    std::string &Keyboard::GetInput(void) const
    {
    	return _keyboard->GetInput();
    }

    std::string &Keyboard::GetMessage(void) const
    {
    	return _keyboard->GetMessage();
    }

    void Keyboard::SetError(std::string error) const
    {
    	_keyboard->GetMessage(error);
    }

    void Keyboard::CanAbort(bool canAbort) const
    {
    	_keyboard->GetMessage(canAbort);
    }

    void Keyboard::Close(void) const
    {
    	_keyboard->Close();
    }

    void Keyboard::OnInputChange(OnInputChangeCallback callback) const
    {
    	_keyboard->OnInputChange(callback);
    }

    int Keyboard::Open(u32 &output) const
    {
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(8);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU32);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU32(_keyboard->GetInput(), _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(u32 &output, u32 start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(8);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU32);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU32(isEmpty ? Utils::Format(_hexadecimal ? "%X" : "%d", start) : _keyboard->GetInput()
    			, _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(u16 &output) const
    {
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(4);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU16);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU16(_keyboard->GetInput(), _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(u16 &output, u16 start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(4);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU16);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU16(isEmpty ? Utils::Format(_hexadecimal ? "%X" : "%d", start) : _keyboard->GetInput()
    			, _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(u8 &output) const
    {
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(2);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU8);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU8(_keyboard->GetInput(), _keyboard->IsHexadecimal());
    	return res;
    }

    int Keyboard::Open(u8 &output, u8 start) const
    {
    	bool isEmpty = _keyboard->GetInput().empty();
    	_keyboard->SetLayout(_hexadecimal ? Layout::Hexadecimal : Layout::Decimal)
    	if (_hexadecimal)
    		_keyboard->SetMaxInput(2);
    	_keyboard->CanChangeLayout(true);
    	_keyboard->SetConvertCallback(ConvertToU8);
    	int res = _keyboard->Run();
    	if ( res != -1 )
    		output = ConvertToU8(isEmpty ? Utils::Format(_hexadecimal ? "%X" : "%d", start) : _keyboard->GetInput()
    			, _keyboard->IsHexadecimal());
    	return res;
    }
}
