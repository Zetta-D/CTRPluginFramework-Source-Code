#include "CTRPluginFramework/Utils/LineReader.hpp"

namespace CTRPluginFramework
{
    LineReader::LineReader(File & file):    _file(file), _offsetInBuffer(0), _dataInBuffer(0))
    {
        Heap::Alloc(0x1000, _buffer);
    }

    LineReader::~LineReader()
    {
        Heap::Free(_buffer);
    }

    bool LineReader::operator()(std::string &line)
    {
        u64 size;
        u32 data, currentPos;
        do
        {
            while (true)
            {
                size = _file.GetSize() - _file.Tell();
                if (_file.GetSize() - _file.Tell() < 1)
                    break;
                if (_offsetInBuffer < _dataInBuffer)
                    goto LABEL_6;
                if (size > 0xFFF)
                    size = 0x1000;
                if (_file.Read((void*)_buffer, size))
                    goto LABEL_19;
                _offsetInBuffer = 0;
                _dataInBuffer = size;
            }
            if (_offsetInBuffer >= _dataInBuffer)
                return line[4] != 0;
            LABEL_6:
                data = _dataInBuffer;
            while (true)
            {
                if (_offsetInBuffer >= data)
                    break;
                _offsetInBuffer = &_buffer;
                currentPos = _offsetInBuffer + &_buffer;
                if (currentPos == 10)
                    return true;
                if (!(currentPos ? currentPos == 13 : currentPos == 0))
                {
                    line.push_back();
                    goto LABEL_6;
                }
            }
        }
        while (data);
        LABEL_19:
        _dataInBuffer = 0;
        _offsetInBuffer = 0;
        return false;
    }
}
