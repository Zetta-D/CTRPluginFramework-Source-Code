#include "CTRPluginFramework/System/FwkSettings.hpp"

namespace CTRPluginFramework {

  FwkSettings & FwkSettings::Get(void) {
    return Preferences::Settings;
  }

  void FwkSettings::SetThemeDefault(void) {
    Color color;
    int v3;
    color = (((Color)(Color::Silver) << sizeof(Color::Silver) * 8) | Color::Black);
    Preferences::Settings[11] = 1045220557;
    Preferences::Settings[9] = Color::BlackGrey;
    Preferences::Settings[20] = v3;
    Preferences::Settings[4] = Color::White;
    Preferences::Settings[5] = Color::White;
    Preferences::Settings[10] = Color::White;
    Preferences::Settings[6] = Color::White;
    Preferences::Settings[7] = HIDWORD(color);
    Preferences::Settings[8] = color;
    Preferences::Settings[12] = color;
    *(u32 * ) & Preferences::Settings[13] = color;
    Preferences::Settings[15] = Color::White;
    Preferences::Settings[16] = Color::White;
    Preferences::Settings[17] = Color::White;
    Preferences::Settings[18] = Color::White;
    Preferences::Settings[19] = color;
    Preferences::Settings[21] = Color::White;
    Preferences::Settings[24] = Color::White;
    Preferences::Settings[22] = Color::Color(0x33 u, 0x33 u, 0x33 u, 0xFF u);
    *(Color * ) & Preferences::Settings[25] = color;
    Preferences::Settings[23] = Color::Gainsboro;
    Preferences::Settings[27] = Color::DimGrey;
  }
  
}


