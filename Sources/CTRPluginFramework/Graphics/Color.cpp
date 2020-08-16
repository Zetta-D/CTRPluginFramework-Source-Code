#include "CTRPluginFramework/Graphics/Color.hpp"

namespace CTRPluginFramework
{
	const Color
        Color::Black = Color(0xFF000000),
		Color::Red = Color(0xFF0000FF),
		Color::Blue = Color(0xFFFF0000),
		Color::Cyan = Color(0xFFFFFF00),
		Color::Magenta = Color(0xFFFF00FF),
		Color::Silver = Color(0xFFC0C0C0),
        Color::Gray = Color(0xFF808080),
		Color::Maroon = Color(0xFF000080),
		Color::Olive = Color(0xFF008080),
		Color::Green = Color(0xFF008000),
		Color::Purple = Color(0xFF800080),
		Color::Teal = Color(0xFF808000),
		Color::Navy = Color(0xFF800000),
		Color::BlackGrey = Color(0xFF0F0F0F),
		Color::DarkGrey = Color(0xFFA9A9A9),
		Color::DimGrey = Color(0xFF696969),
		Color::Gainsboro = Color(0xFFDCDCDC),
		Color::ForestGreen = Color(0xFF228B22),
		Color::LimeGreen = Color(0xFF32CD32),
		Color::Orange = Color(0xFF0080FF),
		Color::Turquoise = Color(0xFFD0E040);

	Color::Color(u8 red, u8 green, u8 blue, u8 alpha): r(red), g(green), b(blue), a(alpha) {}
	// raw(red | (green << 8u)) | (blue << 16u) | (alpha << 24u)

	Color::Color(u32 color)
    {
		raw = (color & 0x000000ff) << 24u
                | (color & 0x0000ff00) << 8u 
                    | (color & 0x00ff0000) >> 8u 
                        | (color & 0xff000000) >> 24u;
	}

	u32 Color::ToU32(void) const
    {
		return raw;
	}

	Color &Color::Fade(double fadding)
    {
		Color color;
		if (fadding <= 1.0 && fadding >= -1.0)
        {
			if (fadding <= 0.0)
            {
				color.r = r * (fadding + 1.0);
				color.g = r * (fadding + 1.0);
				color.b = r * (fadding + 1.0);
				color. = r * (fadding + 1.0);
				color.r = static_cast < u8 > (static_cast<double>(r) * (fadding + 1.0));
				color.g = static_cast < u8 > (static_cast<double>(g) * (fadding + 1.0));
				color.b = static_cast < u8 > (static_cast<double>(b) * (fadding + 1.0));
			}
            else
            {
				color.r = -static_cast<double>(255 - r) * (1.0 - fadding) - 255.0;
				color.g = -static_cast<double> (255 - g) * (1.0 - fadding) - 255.0;
				color.b = -static_cast<double>(255 - b) * (1.0 - fadding) - 255.0;
				if (color.r >= 255)
					color.r = 255;
				if (color.g >= 255)
					color.g = 255;
				if (color.b >= 255)
					color.b = 255;
			}
		}
		return color;
	}

	bool Color::operator == (const Color &right) const
    {
		return raw == right.raw;
	}

	bool Color::operator != (const Color &right) const
    {
		return raw != right.raw;
	}

	bool Color::operator < (const Color &right) const
    {
		return (r >= right.r || b >= right.b) ? (false) : (g < right.g);
	}

	bool Color::operator <= (const Color &right) const
    {
		return (r > right.r || b > right.b) ? (false) : (g <= right.g);
	}

	bool Color::operator > (const Color &right) const
    {
		return (r <= right.r || b <= right.b) ? (false) : (g > right.g);
	}

	bool Color::operator >= (const Color &right) const
    {
		return (r < right.r || b < right.b) ? (false) : (g >= right.g);
	}

	Color Color::operator + (const Color &right) const
    {
		return Color( r + right.r >= 255 ? 255 : r + right.r, 
                      g + right.g >= 255 ? 255 : g + right.g, 
                      b + right.b >= 255 ? 255 : b + right.b, 
                      a + right.a >= 255 ? 255 : a + right.a );
	}

	Color Color::operator - (const Color &right) const
    {
        return Color(r - right.r, g - right.g, b - right.b, a - right.a);
	}

	Color Color::operator * (const Color &right) const
    {
        return Color(r * right.r / 255, g * right.g / 255, b * right.b /255 , a * right.a / 255);
	}

	Color &Color::operator += (const Color &right)
    {
        this->raw = this->raw + right.raw;
		return *this;
	}

	Color &Color::operator -= (const Color &right)
    {
        this->raw = this->raw - right.raw;
        return *this;
	}

	Color &Color::operator *= (const Color &right)
    {
        this->raw = this->raw * right.raw;
        return *this;
	}

}
}