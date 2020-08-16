namespace CTRPluginFramework {

  LineReader::LineReader(File & file):
    _file(file), _offsetInBuffer(0), _dataInBuffer(0), _buffer(Heap::Alloc((Heap * ) 0x1000, file)) {}

  LineReader::~LineReader() {
    Heap::Free(_buffer, _file);
  }

  bool operator()(std::string & line) {
    File ** v3; // r4
    int v4; // r5
    int v5; // r1
    __int64 v6; // r10
    __int64 v7; // r0
    signed __int64 v8; // r6
    __int64 v9; // r2
    _BOOL4 result; // r0
    File * v11; // r2
    File * v12; // r3
    File * v13; // r1
    int v14; // r1
    bool v15; // zf

    *(_DWORD * )(line + 4) = 0;
    v3 = _file;
    v4 = line;
    LODWORD(v6) = _file.GetSize();
    HIDWORD(v6) = v5;
    do {
      while (1) {
        ( * ((_DWORD * ) & (v7))) = File::Tell( * v3);
        v8 = v6 - v7;
        v9 = * (_QWORD * )(v3 + 1);
        if (v6 - v7 < 1)
          break;
        if ((unsigned int) v9 < HIDWORD(v9))
          goto LABEL_6;
        if (v8 > 4095)
          LODWORD(v8) = 4096;
        if (File::Read( * v3, (void * ) v3[3], v8))
          goto LABEL_19;
        v3[1] = 0;
        v3[2] = (File * ) v8;
      }
      if ((u32) v9 >= HIDWORD(v9))
        return *(_DWORD * )(v4 + 4) != 0;
      LABEL_6:
        v11 = v3[2];
      while (True) {
        v12 = v3[1];
        if (v12 >= v11)
          break;
        v13 = v3[3];
        v3[1] = (File * )((char * ) v12 + 1);
        v14 = * ((unsigned __int8 * ) v12 + (_DWORD) v13);
        if (v14 == 10)
          return 1;
        v15 = v14 == 0;
        if (v14)
          v15 = v14 == 13;
        if (!v15) {
          v4.push_back();
          goto LABEL_6;
        }
      }
    }
    while (v11);
    LABEL_19:
      result = 0;
    v3[2] = 0;
    v3[1] = 0;
    return result;
  }

}