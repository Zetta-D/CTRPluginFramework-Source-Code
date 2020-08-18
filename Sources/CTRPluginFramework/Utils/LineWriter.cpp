#include "CTRPluginFramework/Utils/LineWriter.hpp"

namespace CTRPluginFramework 
{
    char c_endl; // weak
    int	i_endl; // weak
    int dword_C; // weak
    char algn_10[16]; // weak

    LineWriter::LineWriter(File &output)
    {
    	_output = output;
    	_offsetInBuffer = 0;
    	Heap::Alloc(0x1000, _buffer);
    }

    void		LineWriter::Flush(void)
    {
    	if (_offsetInBuffer && _output.IsOpen())
    	{
    			_output.Flush();
    			_offsetInBuffer = 0;
    	}
    	return result;
    }

    void		LineWriter::Close(void)
    {
    	LineWriter::Flush();
    	_output.Close();
    	Heap::Free(_buffer);
    }

    LineWriter::~LineWriter(void)
    {
    	LineWriter::Close();
    	delete _buffer;
    }

    int ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(unsigned int a1)
    {
    	__mcr(15, 0, a1, 7, 10, 5);
    	if ( !(c_endl & 1)
    		&& _cxa_guard_acquire(&c_endl) )
    	{
    		i_endl = (int)algn_10;
    		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars();
    		dword_C = 2;
    		*(_BYTE *)(i_endl + 2) = 0;
    		_cxa_guard_release(&c_endl);
    		_aeabi_atexit(
    			&i_endl,
    			&std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string,
    			&_dso_handle);
    	}
    	return &i_endl;
    }

    LineWriter LineWriter::operator<<(LineWriter *this, int a2)
    {
    	int v2; // r2
    	LineWriter *v3; // r4
    	char *v4; // r5
    	_BYTE *v5; // r3
    	int v6; // r6
    	char v7; // r7
    	char v8; // t1

    	v2 = *(_DWORD *)(a2 + 4);
    	v3 = this;
    	if ( v2 )
    	{
    		v4 = *(char **)a2;
    		v5 = (_BYTE *)(*((_DWORD *)this + 2) + *((_DWORD *)this + 1));
    		v6 = *(_DWORD *)a2 + v2;
    		while ( v4 != (char *)v6 )
    		{
    			v8 = *v4++;
    			v7 = v8;
    			if ( *((_DWORD *)v3 + 1) > 0xFFFu )
    			{
    				LineWriter::Flush((int)v3);
    				v5 = (_BYTE *)*((_DWORD *)v3 + 2);
    			}
    			*v5++ = v7;
    			++*((_DWORD *)v3 + 1);
    		}
    	}
    	return v3;
    }
}
