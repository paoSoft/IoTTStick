/*----------------------------------------------------------------------------/
  Lovyan GFX library - LCD graphics library .
  
  support platform:
    ESP32 (SPI/I2S) with Arduino/ESP-IDF
    ATSAMD51 (SPI) with Arduino
  
Original Source:  
 https://github.com/lovyan03/LovyanGFX/  

Licence:  
 [BSD](https://github.com/lovyan03/LovyanGFX/blob/master/license.txt)  

Author:  
 [lovyan03](https://twitter.com/lovyan03)  

Contributors:  
 [ciniml](https://github.com/ciniml)  
 [mongonta0716](https://github.com/mongonta0716)  
 [tobozo](https://github.com/tobozo)  
/----------------------------------------------------------------------------*/
#ifndef LGFX_COMMON_HPP_
#define LGFX_COMMON_HPP_

#include <type_traits>
#include <cstring>
#include <cstdint>
#include <algorithm>

namespace lgfx
{
  namespace boards
  {
    enum board_t
    { board_unknown
    , board_Non_Panel
    , board_M5Stack
    , board_M5StackCore2
    , board_M5StickC
    , board_M5StickCPlus
    , board_TTGO_TS
    , board_TTGO_TWatch
    , board_TTGO_TWristband
    , board_ODROID_GO
    , board_DDUINO32_XS
    , board_ESP_WROVER_KIT
    , board_LoLinD32
    , board_WioTerminal
    , board_WiFiBoy_Pro
    , board_WiFiBoy_Mini
    , board_Makerfabs_TouchCamera
    , board_Makerfabs_MakePython
    , board_M5Stack_CoreInk
    };
  }
  using namespace boards;

  namespace jpeg_div
  {
    enum jpeg_div_t
    {
      JPEG_DIV_NONE,
      JPEG_DIV_2,
      JPEG_DIV_4,
      JPEG_DIV_8,
      JPEG_DIV_MAX
    };
  }

  namespace colors  // Colour enumeration
  {
    #ifdef TFT_BLACK
    #undef TFT_BLACK
    #undef TFT_NAVY
    #undef TFT_DARKGREEN
    #undef TFT_DARKCYAN
    #undef TFT_MAROON
    #undef TFT_PURPLE
    #undef TFT_OLIVE
    #undef TFT_LIGHTGREY
    #undef TFT_DARKGREY
    #undef TFT_BLUE
    #undef TFT_GREEN
    #undef TFT_CYAN
    #undef TFT_RED
    #undef TFT_MAGENTA
    #undef TFT_YELLOW
    #undef TFT_WHITE
    #undef TFT_ORANGE
    #undef TFT_GREENYELLOW
    #undef TFT_PINK
    #undef TFT_BROWN
    #undef TFT_GOLD
    #undef TFT_SILVER
    #undef TFT_SKYBLUE
    #undef TFT_VIOLET
    #undef TFT_TRANSPARENT
    #endif

    static constexpr int TFT_BLACK       = 0x0000;      /*   0,   0,   0 */
    static constexpr int TFT_NAVY        = 0x000F;      /*   0,   0, 128 */
    static constexpr int TFT_DARKGREEN   = 0x03E0;      /*   0, 128,   0 */
    static constexpr int TFT_DARKCYAN    = 0x03EF;      /*   0, 128, 128 */
    static constexpr int TFT_MAROON      = 0x7800;      /* 128,   0,   0 */
    static constexpr int TFT_PURPLE      = 0x780F;      /* 128,   0, 128 */
    static constexpr int TFT_OLIVE       = 0x7BE0;      /* 128, 128,   0 */
    static constexpr int TFT_LIGHTGREY   = 0xD69A;      /* 211, 211, 211 */
    static constexpr int TFT_DARKGREY    = 0x7BEF;      /* 128, 128, 128 */
    static constexpr int TFT_BLUE        = 0x001F;      /*   0,   0, 255 */
    static constexpr int TFT_GREEN       = 0x07E0;      /*   0, 255,   0 */
    static constexpr int TFT_CYAN        = 0x07FF;      /*   0, 255, 255 */
    static constexpr int TFT_RED         = 0xF800;      /* 255,   0,   0 */
    static constexpr int TFT_MAGENTA     = 0xF81F;      /* 255,   0, 255 */
    static constexpr int TFT_YELLOW      = 0xFFE0;      /* 255, 255,   0 */
    static constexpr int TFT_WHITE       = 0xFFFF;      /* 255, 255, 255 */
    static constexpr int TFT_ORANGE      = 0xFDA0;      /* 255, 180,   0 */
    static constexpr int TFT_GREENYELLOW = 0xB7E0;      /* 180, 255,   0 */
    static constexpr int TFT_PINK        = 0xFE19;      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
    static constexpr int TFT_BROWN       = 0x9A60;      /* 150,  75,   0 */
    static constexpr int TFT_GOLD        = 0xFEA0;      /* 255, 215,   0 */
    static constexpr int TFT_SILVER      = 0xC618;      /* 192, 192, 192 */
    static constexpr int TFT_SKYBLUE     = 0x867D;      /* 135, 206, 235 */
    static constexpr int TFT_VIOLET      = 0x915C;      /* 180,  46, 226 */
    static constexpr int TFT_TRANSPARENT = 0x0120;
  }

  namespace textdatum
  {
    enum textdatum_t : std::uint8_t
    //  0:left   1:centre   2:right
    //  0:top    4:middle   8:bottom   16:baseline
    { top_left        =  0  // Top left (default)
    , top_center      =  1  // Top center
    , top_centre      =  1  // Top center
    , top_right       =  2  // Top right
    , middle_left     =  4  // Middle left
    , middle_center   =  5  // Middle center
    , middle_centre   =  5  // Middle center
    , middle_right    =  6  // Middle right
    , bottom_left     =  8  // Bottom left
    , bottom_center   =  9  // Bottom center
    , bottom_centre   =  9  // Bottom center
    , bottom_right    = 10  // Bottom right
    , baseline_left   = 16  // Baseline left (Line the 'A' character would sit on)
    , baseline_center = 17  // Baseline center
    , baseline_centre = 17  // Baseline center
    , baseline_right  = 18  // Baseline right
    };
  };
  using namespace textdatum;

  namespace attribute
  {
    enum attribute_t
    { cp437_switch = 1
    , utf8_switch  = 2
    };
  }
  using namespace attribute;

  enum color_depth_t : std::uint8_t
  { palette_1bit   =  1 //   2 color
  , palette_2bit   =  2 //   4 color
  , palette_4bit   =  4 //  16 color
  , rgb332_1Byte   =  8 // RRRGGGBB
  , rgb565_2Byte   = 16 // RRRRRGGG GGGBBBBB
  , rgb666_3Byte   = 18 // xxRRRRRR xxGGGGGG xxBBBBBB
  , rgb888_3Byte   = 24 // RRRRRRRR GGGGGGGG BBBBBBBB
  , argb8888_4Byte = 32 // AAAAAAAA RRRRRRRR GGGGGGGG BBBBBBBB
  };

  __attribute__ ((always_inline)) inline static std::uint8_t  color332(std::uint8_t r, std::uint8_t g, std::uint8_t b) { return (r >> 5) << 5 | (g >> 5) << 2 | b >> 6; }
  __attribute__ ((always_inline)) inline static std::uint16_t color565(std::uint8_t r, std::uint8_t g, std::uint8_t b) { return (r >> 3) <<11 | (g >> 2) << 5 | b >> 3; }
  __attribute__ ((always_inline)) inline static std::uint32_t color888(std::uint8_t r, std::uint8_t g, std::uint8_t b) { return  r << 16 | g << 8 | b; }
  __attribute__ ((always_inline)) inline static std::uint16_t swap565( std::uint8_t r, std::uint8_t g, std::uint8_t b) { r >>= 3; r = (r << 3) + (g >> 5); return r | (((g >> 2) << 5) | (b >> 3)) << 8; }
  __attribute__ ((always_inline)) inline static std::uint32_t swap888( std::uint8_t r, std::uint8_t g, std::uint8_t b) { return b << 16 | g << 8 | r; }

  __attribute__ ((always_inline)) inline static std::uint16_t getSwap16(std::uint16_t c) { return __builtin_bswap16(c); }
  __attribute__ ((always_inline)) inline static std::uint32_t getSwap24(std::uint32_t c) { return ((std::uint8_t)c)<<16 | ((std::uint8_t)(c>>8))<<8 | (std::uint8_t)(c>>16); }

  __attribute__((used))
  static std::uint32_t convert_bgr888_to_rgb888( std::uint32_t c) { return getSwap24(c);  }
  __attribute__((used))
  static std::uint32_t convert_bgr888_to_rgb565( std::uint32_t c) { return  (((std::uint8_t)c) >> 3) << 11 | (((std::uint16_t)c)>>10)<<5 | c>>19; }
  static std::uint32_t convert_bgr888_to_swap565(std::uint32_t c) { return  (((std::uint8_t)c) >> 3) << 3 |  ((std::uint16_t)c) >> 13 | (c & 0x1C00) << 3 | (c>>19) << 8; }
  static std::uint32_t convert_bgr888_to_bgr666 (std::uint32_t c) { return (c>>2) & 0x3F3F3F;  }
  static std::uint32_t convert_bgr888_to_rgb332 (std::uint32_t c) { return ((std::uint8_t)c >> 5) << 5 | (((std::uint16_t)c)>>13) << 2 | c>>22; }

  __attribute__((used))
  static std::uint32_t convert_rgb888_to_bgr666 (std::uint32_t c) { return ((c>>2) & 0x3F) << 16 | ((c >> 10) & 0x3F) << 8 | ((c>>18)&0x3F);  }
  __attribute__((used))
  static std::uint32_t convert_rgb888_to_rgb565 (std::uint32_t c) { return  (c>>19) << 11 | (((std::uint16_t)c)>>10)<<5 | ((std::uint8_t)c) >> 3;   }
  static std::uint32_t convert_rgb888_to_bgr888 (std::uint32_t c) { return getSwap24(c);  }
  static std::uint32_t convert_rgb888_to_swap565(std::uint32_t c) { return  (c>>19) << 3 |  ((std::uint16_t)c) >> 13 | (c & 0x1C00) << 3 | (((std::uint8_t)c) >> 3) << 8; }
  static std::uint32_t convert_rgb888_to_rgb332 (std::uint32_t c) { return ((c>>21) << 5) | ((((std::uint16_t)c)>>13) << 2) | ((c>>6) & 3); }

  __attribute__((used))
  static std::uint32_t convert_rgb565_to_rgb888( std::uint32_t c) { return ((((c>>11)*0x21)>>2)<<8 | ((((c>>5)&0x3F)*0x41)>>4))<<8 | (((c&0x1F)*0x21)>>2); }
  static std::uint32_t convert_rgb565_to_bgr888 (std::uint32_t c) { return ((((c&0x1F)*0x21)>>2)<<8 | ((((c>>5)&0x3F)*0x41)>>4))<<8 | (((c>>11)*0x21)>>2); }
  static std::uint32_t convert_rgb565_to_bgr666 (std::uint32_t c) { return ((c&0x1F)<<17) | ((c&0x10)<<12) | ((c&0x7E0)<<3) | ((c>>10)&0xF8) | (c>>15); }
  static std::uint32_t convert_rgb565_to_swap565(std::uint32_t c) { return (0xFF & c)<<8|c>>8; }
  static std::uint32_t convert_rgb565_to_rgb332 (std::uint32_t c) { return ((c>>13) <<5) | ((c>>6) & 0x1C) | ((c>>3) & 3); }

  __attribute__((used))
  static std::uint32_t convert_rgb332_to_rgb888 (std::uint32_t c) { return ((((c>>5)*0x49) >> 1)<<8 | ((c&0x1C)*0x49)>>3)<<8 | ((c&3)*0x55); }
  static std::uint32_t convert_rgb332_to_bgr888 (std::uint32_t c) { return (((c&3)*0x55)<<8 | ((c&0x1C)*0x49)>>3)<<8 | (((c>>5)*0x49) >> 1); }
  static std::uint32_t convert_rgb332_to_bgr666 (std::uint32_t c) { return (((c&0xE0)*9)>>5) | ((c&0x1C)*0x240) | ((c&3)*0x15)<<16; }
  static std::uint32_t convert_rgb332_to_swap565(std::uint32_t c) { return (((c&3)*0x15)>>1)<<8 | ((c&0x1C)<<11) | ((c&0x1C)>>2) | (((c>>5)*0x24)&0xF8); }

  static std::uint32_t convert_uint32_to_palette8(std::uint32_t c) { return  c&0xFF; }
  static std::uint32_t convert_uint32_to_palette4(std::uint32_t c) { return (c&0x0F) * 0x11; }
  static std::uint32_t convert_uint32_to_palette2(std::uint32_t c) { return (c&0x03) * 0x55; }
  static std::uint32_t convert_uint32_to_palette1(std::uint32_t c) { return (c&1)?0xFF:0; }
  static std::uint32_t no_convert(std::uint32_t c)                 { return c; }

#pragma pack(push)
#pragma pack(1)
  struct rgb332_t;    //  8bpp
  struct rgb565_t;    // 16bpp
  struct rgb888_t;    // 24bpp
  struct argb8888_t;  // 32bpp
  struct swap565_t;   // 16bpp
  struct bgr666_t;    // 18bpp (24bpp xxRRRRRRxxGGGGGGxxBBBBBB (for OLED SSD1351)
  struct bgr888_t;    // 24bpp

  struct rgb332_t {
    union {
      struct {
        std::uint8_t b: 2;
        std::uint8_t g: 3;
        std::uint8_t r: 3;
      };
      std::uint8_t raw;
    };
    static constexpr std::uint8_t bits = 8;
    static constexpr bool swapped = false;
    static constexpr color_depth_t depth = rgb332_1Byte;
    rgb332_t() : raw(0) {}
    rgb332_t(const rgb332_t&) = default;
    rgb332_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : raw(color332(r8,g8,b8)) {}
    rgb332_t(std::uint8_t rgb332) : raw(rgb332) {}
    inline rgb332_t& operator=(const rgb565_t&);
    inline rgb332_t& operator=(const rgb888_t&);
    inline rgb332_t& operator=(const argb8888_t&);
    inline rgb332_t& operator=(const swap565_t&);
    inline rgb332_t& operator=(const bgr666_t&);
    inline rgb332_t& operator=(const bgr888_t&);
    inline rgb332_t& operator=(std::uint8_t rgb332) { *reinterpret_cast<std::uint8_t*>(this) = rgb332; return *this; }
    explicit inline operator std::uint8_t() const { return raw; }
//  explicit inline operator std::uint32_t() const { return raw; }
    explicit inline operator bool() const { return raw; }
//  inline operator rgb565_t() const;
//  inline operator rgb888_t() const;
//  inline operator argb8888_t() const;
//  inline operator swap565_t() const;
//  inline operator bgr888_t() const;
    static constexpr std::uint8_t A8() { return 255; }
    inline std::uint8_t R8() const { return (r * 0x49) >> 1; } // (r<<5)|(r<<2)|(r>>1);
    inline std::uint8_t G8() const { return (g * 0x49) >> 1; } // (g<<5)|(g<<2)|(g>>1);
    inline std::uint8_t B8() const { return  b * 0x55; }       // (b<<6)|(b<<4)|(b<<2)|b;
    inline std::uint8_t R6() const { return  r | r<<3; }
    inline std::uint8_t G6() const { return  g | g<<3; }
    inline std::uint8_t B6() const { return  b * 0x15; }
    inline void R8(std::uint8_t r8) { r = r8 >> 5; }
    inline void G8(std::uint8_t g8) { g = g8 >> 5; }
    inline void B8(std::uint8_t b8) { b = b8 >> 6; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { *reinterpret_cast<std::uint8_t*>(this) = color332(r8,g8,b8); }
  };

  struct rgb565_t {
    union {
      struct {
        std::uint16_t b: 5;
        std::uint16_t g: 6;
        std::uint16_t r: 5;
      };
      std::uint16_t raw;
    };
    static constexpr std::uint8_t bits = 16;
    static constexpr bool swapped = false;
    static constexpr color_depth_t depth = rgb565_2Byte;
    rgb565_t() : raw(0) {}
    rgb565_t(const rgb565_t&) = default;
    rgb565_t(std::uint16_t rgb565) : raw(rgb565) {}
    rgb565_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : raw(color565(r8,g8,b8)) {} // b(b8>>3),g(g8>>2),r(r8>>3) {}
    inline rgb565_t& operator=(const rgb332_t&);
    inline rgb565_t& operator=(const rgb888_t&);
    inline rgb565_t& operator=(const argb8888_t&);
    inline rgb565_t& operator=(const swap565_t&);
    inline rgb565_t& operator=(const bgr666_t&);
    inline rgb565_t& operator=(const bgr888_t&);
    inline rgb565_t& operator=(std::uint16_t rgb565) { *reinterpret_cast<std::uint16_t*>(this) = rgb565; return *this; }
    explicit inline operator std::uint16_t() const { return raw; }
    explicit inline operator bool() const { return raw; }
    //inline operator rgb332_t() const { return rgb332_t(r<<3,g<<2,b<<3); }
    //inline operator rgb888_t() const;
    //inline operator argb8888_t() const;
    //inline operator swap565_t() const;
    //inline operator bgr888_t() const;
    static constexpr std::uint8_t A8() { return 255; }
    inline std::uint8_t R8() const { return (r * 0x21) >> 2; } // (r << 3) | (r >> 2);
    inline std::uint8_t G8() const { return (g * 0x41) >> 4; } // (g << 2) | (g >> 4);
    inline std::uint8_t B8() const { return (b * 0x21) >> 2; } // (b << 3) | (b >> 2);
    inline std::uint8_t R6() const { return (r * 0x21) >> 4; }
    inline std::uint8_t G6() const { return  g; }
    inline std::uint8_t B6() const { return (b * 0x21) >> 4; }
    inline void R8(std::uint8_t r8) { r = r8 >> 3; }
    inline void G8(std::uint8_t g8) { g = g8 >> 2; }
    inline void B8(std::uint8_t b8) { b = b8 >> 3; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { *reinterpret_cast<std::uint16_t*>(this) = color565(r8,g8,b8); }
  };

  struct rgb888_t {
    union {
      struct {
        std::uint8_t b;
        std::uint8_t g;
        std::uint8_t r;
      };
    };
    static constexpr std::uint8_t bits = 24;
    static constexpr bool swapped = false;
    static constexpr color_depth_t depth = rgb888_3Byte;
    rgb888_t() : b(0), g(0), r(0) {}
    rgb888_t(const rgb888_t&) = default;
    rgb888_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : b(b8),g(g8),r(r8) {}
    rgb888_t(std::uint32_t rgb888) : b(rgb888), g(rgb888>>8), r(rgb888>>16) {}
    inline rgb888_t& operator=(const rgb332_t&);
    inline rgb888_t& operator=(const rgb565_t&);
    inline rgb888_t& operator=(const argb8888_t&);
    inline rgb888_t& operator=(const swap565_t&);
    inline rgb888_t& operator=(const bgr666_t&);
    inline rgb888_t& operator=(const bgr888_t&);
    inline rgb888_t& operator=(std::uint32_t rgb888) { r = rgb888>>16; g = rgb888>>8; b = rgb888; return *this; }
//  explicit inline operator std::uint32_t() const { return *(std::uint32_t*)this & ((1<<24)-1); }
    explicit inline operator bool() const { return r||g||b; }
    //inline operator rgb332_t() const { return rgb332_t(r,g,b); }
    //inline operator rgb565_t() const { return rgb565_t(r,g,b); }
    //inline operator argb8888_t() const;
    //inline operator swap565_t() const;
    //inline operator bgr888_t() const;
    static constexpr std::uint8_t A8() { return 255; }
    inline std::uint8_t R8() const { return r; }
    inline std::uint8_t G8() const { return g; }
    inline std::uint8_t B8() const { return b; }
    inline std::uint8_t R6() const { return r>>2; }
    inline std::uint8_t G6() const { return g>>2; }
    inline std::uint8_t B6() const { return b>>2; }
    inline void R8(std::uint8_t r8) { r = r8; }
    inline void G8(std::uint8_t g8) { g = g8; }
    inline void B8(std::uint8_t b8) { b = b8; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { r = r8; g = g8; b = b8; }
  };

  struct argb8888_t {
    union {
      struct {
        std::uint8_t b;
        std::uint8_t g;
        std::uint8_t r;
        std::uint8_t a;
      };
      std::uint32_t raw;
    };
    static constexpr std::uint8_t bits = 32;
    static constexpr bool swapped = false;
    static constexpr color_depth_t depth = argb8888_4Byte;
    argb8888_t() : raw(0) {}
    argb8888_t(const argb8888_t&) = default;
    argb8888_t(std::uint8_t r, std::uint8_t g, std::uint8_t b) : b(b),g(g),r(r),a(255) {}
    argb8888_t(std::uint32_t argb8888) : raw(argb8888) {}
    inline argb8888_t& operator=(const rgb332_t&);
    inline argb8888_t& operator=(const rgb565_t&);
    inline argb8888_t& operator=(const rgb888_t&);
    inline argb8888_t& operator=(const swap565_t&);
    inline argb8888_t& operator=(const bgr666_t&);
    inline argb8888_t& operator=(const bgr888_t&);
    inline argb8888_t& operator=(std::uint32_t argb8888) { *reinterpret_cast<std::uint32_t*>(this) = argb8888; return *this; }
//  explicit inline operator std::uint32_t() const { return raw; }
    explicit inline operator bool() const { return raw; }
    //inline operator rgb332_t() const { return rgb332_t(r,g,b); }
    //inline operator rgb565_t() const { return rgb565_t(r,g,b); }
    //inline operator rgb888_t() const { return operator std::uint32_t(); }
    //inline operator swap565_t() const;
    //inline operator bgr888_t() const;
    inline std::uint8_t A8() const { return a; }
    inline std::uint8_t R8() const { return r; }
    inline std::uint8_t G8() const { return g; }
    inline std::uint8_t B8() const { return b; }
    inline std::uint8_t R6() const { return r>>2; }
    inline std::uint8_t G6() const { return g>>2; }
    inline std::uint8_t B6() const { return b>>2; }
    inline void A8(std::uint8_t a8) { a = a8; }
    inline void R8(std::uint8_t r8) { r = r8; }
    inline void G8(std::uint8_t g8) { g = g8; }
    inline void B8(std::uint8_t b8) { b = b8; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { a = 255; r = r8; g = g8; b = b8; }
    inline void set(std::uint8_t a8, std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { a = a8; r = r8; g = g8; b = b8; }
  };

  struct swap565_t {
    union {
      struct {
        std::uint16_t gh:3;
        std::uint16_t r:5;
        std::uint16_t b:5;
        std::uint16_t gl:3;
      };
      std::uint16_t raw;
    };
    static constexpr std::uint8_t bits = 16;
    static constexpr bool swapped = true;
    static constexpr color_depth_t depth = rgb565_2Byte;
    swap565_t() : raw(0) {}
    swap565_t(const swap565_t&) = default;
    swap565_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : raw(swap565(r8,g8,b8)) {}
    //swap565_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : gh(g8>>5),r(r8>>3),b(b8>>3),gl(g8>>2) {}
//    swap565_t(std::uint16_t raw) : raw(raw) {}
    inline swap565_t& operator=(std::uint16_t rhs) { *reinterpret_cast<std::uint16_t*>(this) = rhs << 8 | rhs >> 8; return *this; }
    inline swap565_t& operator=(const rgb332_t& rhs);
    inline swap565_t& operator=(const rgb565_t& rhs);
    inline swap565_t& operator=(const rgb888_t& rhs);
    inline swap565_t& operator=(const argb8888_t& rhs);
    inline swap565_t& operator=(const bgr666_t& rhs);
    inline swap565_t& operator=(const bgr888_t& rhs);
    //explicit inline operator std::uint16_t() const { return raw; }
//  explicit inline operator std::uint32_t() const { return raw; }
    explicit inline operator bool() const { return raw; }
    //inline operator rgb565_t() const { return rgb565_t(raw<<8 | raw>>8); }
    //inline operator bgr888_t() const;
    static constexpr std::uint8_t A8() { return 255; }
    inline std::uint8_t R8() const { return ( r * 0x21) >> 2; }
    inline std::uint8_t G8() const { return ((gh* 0x41) >> 1)|(gl << 2); }
    inline std::uint8_t B8() const { return ( b * 0x21) >> 2; }
    inline std::uint8_t R6() const { return ( r * 0x21) >> 4; }
    inline std::uint8_t G6() const { return  gh << 3 | gl; }
    inline std::uint8_t B6() const { return ( b * 0x21) >> 4; }
    inline void R8(std::uint8_t r8) { r = r8 >> 3; }
    inline void G8(std::uint8_t g8) { gh = g8 >> 5; gl = g8 >> 2;}
    inline void B8(std::uint8_t b8) { b = b8 >> 3; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { *reinterpret_cast<std::uint16_t*>(this) = swap565(r8,g8,b8); }
  };

  struct bgr666_t {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    static constexpr std::uint8_t bits = 24;
    static constexpr bool swapped = true;
    static constexpr color_depth_t depth = rgb666_3Byte;
    bgr666_t() : r(0), g(0), b(0) {};
    bgr666_t(const bgr666_t&) = default;
    bgr666_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : r(r8>>2),g(g8>>2),b(b8>>2) {}
    inline bgr666_t& operator=(std::uint32_t rhs) { r = rhs; g = rhs>>8 ; b = rhs>>16; return *this; }
    inline bgr666_t& operator=(const rgb332_t&);
    inline bgr666_t& operator=(const rgb565_t&);
    inline bgr666_t& operator=(const rgb888_t&);
    inline bgr666_t& operator=(const argb8888_t&);
    inline bgr666_t& operator=(const swap565_t&);
    inline bgr666_t& operator=(const bgr888_t&);
//  explicit inline operator std::uint32_t() const { return *(std::uint32_t*)this & ((1<<24)-1); }
    explicit inline operator bool() const { return r||g||b; }
    //inline operator std::uint32_t() const { return (b<<16)|(g<<8)|r; }
    //inline operator rgb332_t() const { return rgb332_t(r,g,b); }
    //explicit inline operator rgb565_t() const { return rgb565_t(r,g,b); }
    //inline operator rgb888_t() const { return rgb888_t(r,g,b); }
    //inline operator swap565_t() const { return swap565_t(r,g,b); }
    static constexpr std::uint8_t A8() { return 255; }
    inline std::uint8_t R8() const { return r<<2; }
    inline std::uint8_t G8() const { return g<<2; }
    inline std::uint8_t B8() const { return b<<2; }
    inline std::uint8_t R6() const { return r; }
    inline std::uint8_t G6() const { return g; }
    inline std::uint8_t B6() const { return b; }
    inline void R8(std::uint8_t r8) { r = r8>>2; }
    inline void G8(std::uint8_t g8) { g = g8>>2; }
    inline void B8(std::uint8_t b8) { b = b8>>2; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { r = r8>>2; g = g8>>2; b = b8>>2; }
  };

  struct bgr888_t {
    union {
      struct {
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
      };
      std::uint16_t rg;
    };
    static constexpr std::uint8_t bits = 24;
    static constexpr bool swapped = true;
    static constexpr color_depth_t depth = rgb888_3Byte;
    bgr888_t() : r{0}, g{0}, b{0} {};
    bgr888_t(const bgr888_t&) = default;
    bgr888_t(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) : r(r8),g(g8),b(b8) {}
//    bgr888_t(std::uint32_t bgr888) : r(bgr888), g(bgr888>>8), b(bgr888>>16) {}
    inline bgr888_t& operator=(std::uint32_t rhs) { r = rhs; g = rhs>>8 ; b = rhs>>16; return *this; }
    inline bgr888_t& operator=(const rgb332_t&);
    inline bgr888_t& operator=(const rgb565_t&);
    inline bgr888_t& operator=(const rgb888_t&);
    inline bgr888_t& operator=(const argb8888_t&);
    inline bgr888_t& operator=(const swap565_t&);
    inline bgr888_t& operator=(const bgr666_t&);
    explicit inline operator bool() const { return rg||b; }
    explicit inline operator std::uint32_t() const { return *(std::uint32_t*)this & ((1<<24)-1); }
    //inline operator rgb332_t() const { return rgb332_t(r,g,b); }
    //explicit inline operator rgb565_t() const { return rgb565_t(r,g,b); }
    //inline operator rgb888_t() const { return rgb888_t(r,g,b); }
    //inline operator swap565_t() const { return swap565_t(r,g,b); }
    static constexpr std::uint8_t A8() { return 255; }
    inline std::uint8_t R8() const { return r; }
    inline std::uint8_t G8() const { return g; }
    inline std::uint8_t B8() const { return b; }
    inline std::uint8_t R6() const { return r>>2; }
    inline std::uint8_t G6() const { return g>>2; }
    inline std::uint8_t B6() const { return b>>2; }
    inline void R8(std::uint8_t r8) { r = r8; }
    inline void G8(std::uint8_t g8) { g = g8; }
    inline void B8(std::uint8_t b8) { b = b8; }
    inline void set(std::uint8_t r8, std::uint8_t g8, std::uint8_t b8) { r = r8; g = g8; b = b8; }
  };

  struct raw_color_t
  {
    union {
      struct {
        std::uint8_t raw0;
        std::uint8_t raw1;
        std::uint8_t raw2;
        std::uint8_t raw3;
      };
      struct {
        std::uint16_t rawL;
        std::uint16_t rawH;
      };
      std::uint32_t raw;
    };
    raw_color_t() : raw(0) {}
    raw_color_t(const raw_color_t&) = default;
    raw_color_t(const std::uint32_t& rhs) : raw(rhs) {}
    inline operator bool() const { return raw & ((1<<24)-1); }
  };

  struct get_depth_impl {
  template<typename T> static constexpr std::integral_constant<color_depth_t, T::depth> check(decltype(T::depth)*);
  template<typename T> static constexpr std::integral_constant<color_depth_t, (color_depth_t)(sizeof(T) << 3) > check(...);
  };
  template<typename T> class get_depth : public decltype(get_depth_impl::check<T>(nullptr)) {};

  template <typename TSrc>
  static auto get_fp_convert_src(color_depth_t dst_depth, bool has_palette) -> std::uint32_t(*)(std::uint32_t)
  {
    if (std::is_same<TSrc, rgb332_t>::value || std::is_same<TSrc, std::uint8_t>::value) {
      switch (dst_depth) {
      case rgb888_3Byte: return convert_rgb332_to_bgr888;
      case rgb666_3Byte: return convert_rgb332_to_bgr666;
      case rgb565_2Byte: return convert_rgb332_to_swap565;
      case rgb332_1Byte: return has_palette
                              ? convert_uint32_to_palette8
                              : no_convert;
      default: break;
      }
    } else if (std::is_same<TSrc, rgb888_t>::value || std::is_same<TSrc, std::uint32_t>::value) {
      switch (dst_depth) {
      case rgb888_3Byte: return convert_rgb888_to_bgr888;
      case rgb666_3Byte: return convert_rgb888_to_bgr666;
      case rgb565_2Byte: return convert_rgb888_to_swap565;
      case rgb332_1Byte: return has_palette
                              ? convert_uint32_to_palette8
                              : convert_rgb888_to_rgb332;
      default: break;
      }
    } else if (std::is_same<TSrc, bgr888_t>::value) {
      switch (dst_depth) {
      case rgb888_3Byte: return no_convert;
      case rgb666_3Byte: return convert_bgr888_to_bgr666;
      case rgb565_2Byte: return convert_bgr888_to_swap565;
      case rgb332_1Byte: return has_palette
                              ? convert_uint32_to_palette8
                              : convert_bgr888_to_rgb332;
      default: break;
      }
    } else { // if (std::is_same<TSrc, rgb565_t>::value || std::is_same<TSrc, std::uint16_t>::value || std::is_same<TSrc, int>::value)
      switch (dst_depth) {
      case rgb888_3Byte: return convert_rgb565_to_bgr888;
      case rgb666_3Byte: return convert_rgb565_to_bgr666;
      case rgb565_2Byte: return convert_rgb565_to_swap565;
      case rgb332_1Byte: return has_palette
                              ? convert_uint32_to_palette8
                              : convert_rgb565_to_rgb332;
      default: break;
      }
    }

    switch (dst_depth) {
    case palette_4bit: return convert_uint32_to_palette4;
    case palette_2bit: return convert_uint32_to_palette2;
    case palette_1bit: return convert_uint32_to_palette1;
    default:           return no_convert;
    }
  }


  struct color_conv_t
  {
    std::uint32_t (*convert_bgr888)(std::uint32_t) = convert_bgr888_to_swap565;
    std::uint32_t (*convert_rgb888)(std::uint32_t) = convert_rgb888_to_swap565;
    std::uint32_t (*convert_rgb565)(std::uint32_t) = convert_rgb565_to_swap565;
    std::uint32_t (*convert_rgb332)(std::uint32_t) = convert_rgb332_to_swap565;
    color_depth_t depth = rgb565_2Byte;
    std::uint32_t colormask = 0xFFFF;
    std::uint8_t bytes  = 2;
    std::uint8_t bits   = 16;
    std::uint8_t x_mask = 0;

    color_conv_t() = default;
    color_conv_t(const color_conv_t&) = default;

    void setColorDepth(color_depth_t bpp, bool has_palette = false)
    {
      x_mask = 0;
      if (     bpp > 18) { bpp = rgb888_3Byte; bits = 24; }
      else if (bpp > 16) { bpp = rgb666_3Byte; bits = 24; }
      else if (bpp >  8) { bpp = rgb565_2Byte; bits = 16; }
      else if (bpp >  4) { bpp = rgb332_1Byte; bits =  8; }
      else if (bpp == 4) { bpp = palette_4bit; bits =  4; x_mask = 0b0001; }
      else if (bpp == 2) { bpp = palette_2bit; bits =  2; x_mask = 0b0011; }
      else               { bpp = palette_1bit; bits =  1; x_mask = 0b0111; }
      depth = bpp;
      bytes = bits >> 3;
      colormask = (1 << bits) - 1;

      convert_rgb888 = get_fp_convert_src<rgb888_t>(bpp, has_palette);
      convert_rgb565 = get_fp_convert_src<rgb565_t>(bpp, has_palette);
      convert_rgb332 = get_fp_convert_src<rgb332_t>(bpp, has_palette);
      convert_bgr888 = get_fp_convert_src<bgr888_t>(bpp, has_palette);
    }

#define TYPECHECK(dType) template < typename T, typename std::enable_if < (sizeof(T) == sizeof(dType)) && (std::is_signed<T>::value == std::is_signed<dType>::value), std::nullptr_t >::type=nullptr >
    TYPECHECK(std::uint8_t ) __attribute__ ((always_inline)) inline std::uint32_t convert(T c) { return convert_rgb332(c); }
    TYPECHECK(std::uint16_t) __attribute__ ((always_inline)) inline std::uint32_t convert(T c) { return convert_rgb565(c); }
    TYPECHECK(std::int16_t ) __attribute__ ((always_inline)) inline std::uint32_t convert(T c) { return convert_rgb565(c); }
    TYPECHECK(std::int32_t ) __attribute__ ((always_inline)) inline std::uint32_t convert(T c) { return convert_rgb565(c); }
    TYPECHECK(std::uint32_t) __attribute__ ((always_inline)) inline std::uint32_t convert(T c) { return convert_rgb888(c); }

    __attribute__ ((always_inline)) inline std::uint32_t convert(const argb8888_t& c) { return convert_rgb888(c.raw); }
    __attribute__ ((always_inline)) inline std::uint32_t convert(const rgb888_t&   c) { return convert_rgb888(*(std::uint32_t*)&c); }
    __attribute__ ((always_inline)) inline std::uint32_t convert(const rgb565_t&   c) { return convert_rgb565(c.raw); }
    __attribute__ ((always_inline)) inline std::uint32_t convert(const rgb332_t&   c) { return convert_rgb332(c.raw); }
    __attribute__ ((always_inline)) inline std::uint32_t convert(const bgr888_t&   c) { return convert_bgr888(*(std::uint32_t*)&c); }

//  template<typename T> __attribute__ ((always_inline)) inline void setColor(T c) { raw = convert(c); }
  };

  TYPECHECK(std::uint8_t ) __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(T c) { return convert_rgb332_to_rgb888(c); }
  TYPECHECK(std::uint16_t) __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(T c) { return convert_rgb565_to_rgb888(c); }
  TYPECHECK(std::int16_t ) __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(T c) { return convert_rgb565_to_rgb888(c); }
  TYPECHECK(std::int32_t ) __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(T c) { return convert_rgb565_to_rgb888(c); }
  TYPECHECK(std::uint32_t) __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(T c) { return c; }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const argb8888_t& c) { return c.r   <<16|c.g   <<8|c.b;    }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const rgb888_t&   c) { return c.r   <<16|c.g   <<8|c.b;    }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const rgb565_t&   c) { return c.R8()<<16|c.G8()<<8|c.B8(); }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const rgb332_t&   c) { return c.R8()<<16|c.G8()<<8|c.B8(); }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const bgr888_t&   c) { return c.r   <<16|c.g   <<8|c.b;    }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const bgr666_t&   c) { return c.R8()<<16|c.G8()<<8|c.B8(); }
  __attribute__ ((always_inline)) inline std::uint32_t convert_to_rgb888(const swap565_t&  c) { return c.R8()<<16|c.G8()<<8|c.B8(); }

#undef TYPECHECK

#pragma pack(pop)

  //inline rgb332_t::operator rgb565_t() const   { return rgb565_t(((r*0x2400) & 0xF800) | (g*0x0120) | ((b*0x15)>>1)); }
  //inline rgb332_t::operator rgb888_t() const   { return rgb888_t(R8(),G8(),B8()); }
  //inline rgb332_t::operator argb8888_t() const { return argb8888_t(R8(),G8(),B8()); }
  //inline rgb332_t::operator swap565_t() const  { return operator rgb565_t(); }
  //inline rgb332_t::operator bgr888_t() const  { return bgr888_t(R8(),G8(),B8()); }
  //inline rgb565_t::operator rgb888_t() const   { return rgb888_t(R8(),G8(),B8()); }
  //inline rgb565_t::operator argb8888_t() const { return argb8888_t(R8(),G8(),B8()); }
  //inline rgb565_t::operator swap565_t() const  { return swap565_t(raw<<8 | raw>>8); }
  //inline rgb565_t::operator bgr888_t() const  { return bgr888_t(R8(),G8(),B8()); }
  //inline rgb888_t::operator argb8888_t() const { return argb8888_t(r,g,b); }
  //inline rgb888_t::operator swap565_t() const  { return operator rgb565_t(); }
  //inline rgb888_t::operator bgr888_t() const  { return bgr888_t(r,g,b); }
  //inline argb8888_t::operator swap565_t() const { return operator rgb565_t(); }
  //inline argb8888_t::operator bgr888_t() const { return bgr888_t(r,g,b); }
  //inline swap565_t::operator bgr888_t() const { return operator rgb565_t(); }

  inline rgb332_t& rgb332_t::operator=(const rgb565_t&   rhs) { raw = ((rhs.r<<3)&0xE0) | ((rhs.g>>1)&0x1C) | (rhs.b>>3); return *this; }
  inline rgb332_t& rgb332_t::operator=(const swap565_t&  rhs) { raw = ((rhs.r<<3)&0xE0) | ((rhs.gh<<2) + (rhs.b>>3)); return *this; }
  inline rgb332_t& rgb332_t::operator=(const bgr666_t&   rhs) { raw = ((rhs.r<<2)&0xE0) | ((rhs.g>>1)&0x1C) | (rhs.b>>4); return *this; }
  inline rgb332_t& rgb332_t::operator=(const rgb888_t&   rhs) { raw = color332(rhs.r, rhs.g, rhs.b); return *this; }
  inline rgb332_t& rgb332_t::operator=(const bgr888_t&   rhs) { raw = color332(rhs.r, rhs.g, rhs.b); return *this; }
  inline rgb332_t& rgb332_t::operator=(const argb8888_t& rhs) { raw = color332(rhs.r, rhs.g, rhs.b); return *this; }

  inline rgb565_t& rgb565_t::operator=(const rgb332_t&   rhs) { raw = color565(rhs.R8(), rhs.G8(), rhs.B8()); return *this; }
  inline rgb565_t& rgb565_t::operator=(const swap565_t&  rhs) { raw = __builtin_bswap16(rhs.raw);   return *this; }
  inline rgb565_t& rgb565_t::operator=(const rgb888_t&   rhs) { raw = color565(rhs.r, rhs.g, rhs.b); return *this; }
  inline rgb565_t& rgb565_t::operator=(const bgr888_t&   rhs) { raw = color565(rhs.r, rhs.g, rhs.b); return *this; }
  inline rgb565_t& rgb565_t::operator=(const bgr666_t&   rhs) { raw = color565(rhs.R8(), rhs.G8(), rhs.B8()); return *this; }
  inline rgb565_t& rgb565_t::operator=(const argb8888_t& rhs) { raw = color565(rhs.r, rhs.g, rhs.b); return *this; }

  inline rgb888_t& rgb888_t::operator=(const rgb332_t&   rhs) { r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline rgb888_t& rgb888_t::operator=(const rgb565_t&   rhs) { r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline rgb888_t& rgb888_t::operator=(const swap565_t&  rhs) { r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline rgb888_t& rgb888_t::operator=(const bgr666_t&   rhs) { r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline rgb888_t& rgb888_t::operator=(const bgr888_t&   rhs) { r = rhs.r;    g = rhs.g;    b = rhs.b;    return *this; }
  inline rgb888_t& rgb888_t::operator=(const argb8888_t& rhs) { r = rhs.r;    g = rhs.g;    b = rhs.b;    return *this; }

  inline swap565_t& swap565_t::operator=(const rgb332_t&   rhs) { *reinterpret_cast<std::uint16_t*>(this) = ((rhs.b * 0x15)>>1)<<8 | rhs.g << 13 | rhs.g | ((rhs.r * 0x09) >> 1) << 3; return *this; }
  inline swap565_t& swap565_t::operator=(const rgb565_t&   rhs) { raw = __builtin_bswap16(rhs.raw);            return *this; }
  inline swap565_t& swap565_t::operator=(const rgb888_t&   rhs) { raw = swap565(rhs.r,    rhs.g,    rhs.b);    return *this; }
  inline swap565_t& swap565_t::operator=(const bgr666_t&   rhs) { raw = (rhs.b>>1)<<8 | rhs.g << 13 | rhs.g >> 3 | (rhs.r >> 1) << 3; return *this; }
  inline swap565_t& swap565_t::operator=(const bgr888_t&   rhs) { *reinterpret_cast<std::uint16_t*>(this) = swap565(rhs.r, rhs.g, rhs.b);   return *this; }
  inline swap565_t& swap565_t::operator=(const argb8888_t& rhs) { *reinterpret_cast<std::uint16_t*>(this) = swap565(rhs.r, rhs.g, rhs.b);   return *this; }


  inline bgr666_t& bgr666_t::operator=(const rgb332_t&   rhs) { r = rhs.R6(); g = rhs.G6(); b = rhs.B6(); return *this; }
  inline bgr666_t& bgr666_t::operator=(const rgb565_t&   rhs) { r = rhs.R6(); g = rhs.G6(); b = rhs.B6(); return *this; }
  inline bgr666_t& bgr666_t::operator=(const swap565_t&  rhs) { r = rhs.R6(); g = rhs.G6(); b = rhs.B6(); return *this; }
  inline bgr666_t& bgr666_t::operator=(const bgr888_t&   rhs) { r = rhs.R6(); g = rhs.G6(); b = rhs.B6(); return *this; }
  inline bgr666_t& bgr666_t::operator=(const rgb888_t&   rhs) { r = rhs.R6(); g = rhs.G6(); b = rhs.B6(); return *this; }
  inline bgr666_t& bgr666_t::operator=(const argb8888_t& rhs) { r = rhs.R6(); g = rhs.G6(); b = rhs.B6(); return *this; }

  inline bgr888_t& bgr888_t::operator=(const rgb332_t&   rhs) { r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline bgr888_t& bgr888_t::operator=(const rgb565_t&   rhs) { rg = rhs.R8() | rhs.G8()<<8; b = rhs.B8(); return *this; }
  inline bgr888_t& bgr888_t::operator=(const swap565_t&  rhs) { rg = rhs.R8() | rhs.G8()<<8; b = rhs.B8(); return *this; }
  inline bgr888_t& bgr888_t::operator=(const bgr666_t&   rhs) { r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline bgr888_t& bgr888_t::operator=(const rgb888_t&   rhs) { r = rhs.r   ; g = rhs.g   ; b = rhs.b   ; return *this; }
  inline bgr888_t& bgr888_t::operator=(const argb8888_t& rhs) { r = rhs.r   ; g = rhs.g   ; b = rhs.b   ; return *this; }

  inline argb8888_t& argb8888_t::operator=(const rgb332_t&  rhs) { a = 255; r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline argb8888_t& argb8888_t::operator=(const rgb565_t&  rhs) { a = 255; r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline argb8888_t& argb8888_t::operator=(const swap565_t& rhs) { a = 255; r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline argb8888_t& argb8888_t::operator=(const bgr666_t&  rhs) { a = 255; r = rhs.R8(); g = rhs.G8(); b = rhs.B8(); return *this; }
  inline argb8888_t& argb8888_t::operator=(const rgb888_t&  rhs) { a = 255; r = rhs.r   ; g = rhs.g   ; b = rhs.b   ; return *this; }
  inline argb8888_t& argb8888_t::operator=(const bgr888_t&  rhs) { a = 255; r = rhs.r   ; g = rhs.g   ; b = rhs.b   ; return *this; }

  inline bool operator==(const rgb332_t&   lhs, const rgb332_t&   rhs) { return lhs.raw == rhs.raw; }
  inline bool operator==(const rgb565_t&   lhs, const rgb565_t&   rhs) { return lhs.raw == rhs.raw; }
  inline bool operator==(const swap565_t&  lhs, const swap565_t&  rhs) { return lhs.raw == rhs.raw; }
  inline bool operator==(const bgr666_t&   lhs, const bgr666_t&   rhs) { return (*reinterpret_cast<const std::uint32_t*>(&lhs) << 8) == (*reinterpret_cast<const std::uint32_t*>(&rhs) << 8); }
  inline bool operator==(const rgb888_t&   lhs, const rgb888_t&   rhs) { return (*reinterpret_cast<const std::uint32_t*>(&lhs) << 8) == (*reinterpret_cast<const std::uint32_t*>(&rhs) << 8); }
  inline bool operator==(const bgr888_t&   lhs, const bgr888_t&   rhs) { return (*reinterpret_cast<const std::uint32_t*>(&lhs) << 8) == (*reinterpret_cast<const std::uint32_t*>(&rhs) << 8); }
  inline bool operator==(const argb8888_t& lhs, const argb8888_t& rhs) { return lhs.raw == rhs.raw; }

  // for compare transparent color.
  inline bool operator==(const rgb332_t&   lhs, std::uint32_t rhs) { return  *reinterpret_cast<const std::uint8_t* >(&lhs) == rhs; }
  inline bool operator==(const rgb565_t&   lhs, std::uint32_t rhs) { return  *reinterpret_cast<const std::uint16_t*>(&lhs) == rhs; }
  inline bool operator==(const swap565_t&  lhs, std::uint32_t rhs) { return  *reinterpret_cast<const std::uint16_t*>(&lhs) == rhs; }
  inline bool operator==(const bgr666_t&   lhs, std::uint32_t rhs) { return (*reinterpret_cast<const std::uint32_t*>(&lhs) << 8) >> 8 == rhs; }
  inline bool operator==(const rgb888_t&   lhs, std::uint32_t rhs) { return (*reinterpret_cast<const std::uint32_t*>(&lhs) << 8) >> 8 == rhs; }
  inline bool operator==(const bgr888_t&   lhs, std::uint32_t rhs) { return (*reinterpret_cast<const std::uint32_t*>(&lhs) << 8) >> 8 == rhs; }
  inline bool operator==(const argb8888_t& lhs, std::uint32_t rhs) { return  *reinterpret_cast<const std::uint32_t*>(&lhs) == rhs; }
//*/
  inline bool operator==(const raw_color_t& lhs, const raw_color_t& rhs) { return *reinterpret_cast<const std::uint32_t*>(&lhs) == *reinterpret_cast<const std::uint32_t*>(&rhs); }
  inline bool operator!=(const raw_color_t& lhs, const raw_color_t& rhs) { return *reinterpret_cast<const std::uint32_t*>(&lhs) != *reinterpret_cast<const std::uint32_t*>(&rhs); }



//----------------------------------------------------------------------------
  static constexpr std::uint32_t FP_SCALE = 16;

  struct pixelcopy_t
  {
    union {
      std::uint32_t positions[4] = {0};
      struct {
        std::uint32_t src_x32;
        std::uint32_t src_y32;
        std::uint32_t src_xe32;
        std::uint32_t src_ye32;
      };
      struct {
        std::uint16_t src_x_lo;
        std:: int16_t src_x;
        std::uint16_t src_y_lo;
        std:: int16_t src_y;
        std::uint16_t src_xe_lo;
        std:: int16_t src_xe;
        std::uint16_t src_ye_lo;
        std:: int16_t src_ye;
      };
    };

    std::uint32_t src_x32_add = 1 << FP_SCALE;
    std::uint32_t src_y32_add = 0;
    std::uint32_t src_bitwidth = 0;
    std::uint32_t src_width = 0;
    std::uint32_t src_height = 0;
    std::uint32_t transp   = ~0u;
    std::uint32_t src_bits = 8;
    std::uint32_t dst_bits = 8;
    const void* src_data = nullptr;
    const void* palette = nullptr;
    std::int32_t (*fp_copy)(void*, std::int32_t, std::int32_t, pixelcopy_t*) = nullptr;
    std::int32_t (*fp_skip)(       std::int32_t, std::int32_t, pixelcopy_t*) = nullptr;
    std::uint8_t src_mask  = ~0;
    std::uint8_t dst_mask  = ~0;
    bool no_convert = false;

    pixelcopy_t(void) = default;

    pixelcopy_t( const void* src_data
               , color_depth_t dst_depth
               , color_depth_t src_depth
               , bool dst_palette = false
               , const void* src_palette = nullptr
               , std::uint32_t src_transp = ~0u
               ) 
    : transp    ( src_transp )
    , src_bits  ( src_depth > 8 ? (src_depth + 7) & ~7 : src_depth)
    , dst_bits  ( dst_depth > 8 ? (dst_depth + 7) & ~7 : dst_depth)
    , src_data  ( src_data   )
    , palette   ( src_palette)
    , src_mask  ( (1 << src_bits) - 1 )
    , dst_mask  ( (1 << dst_bits) - 1 )
    , no_convert( src_depth == dst_depth )
    {
      if (dst_palette || dst_depth < 8) {
        if (src_palette && (dst_depth == 8) && (src_depth == 8)) {
          fp_copy = pixelcopy_t::copy_rgb_affine<rgb332_t, rgb332_t>;
          fp_skip = pixelcopy_t::skip_rgb_affine<rgb332_t>;
        } else {
          fp_copy = pixelcopy_t::copy_bit_affine;
          fp_skip = pixelcopy_t::skip_bit_affine;
        }
      } else 
      if (src_palette || src_depth < 8) {
        fp_copy = pixelcopy_t::get_fp_copy_palette_affine<bgr888_t>(dst_depth);
        fp_skip = pixelcopy_t::skip_bit_affine;
      } else {
        if (src_depth > rgb565_2Byte) {
          fp_skip = pixelcopy_t::skip_rgb_affine<bgr888_t>;
          if (src_depth == rgb888_3Byte) {
            fp_copy = pixelcopy_t::get_fp_copy_rgb_affine<bgr888_t>(dst_depth);
          } else if (src_depth == rgb666_3Byte) {
            fp_copy = pixelcopy_t::get_fp_copy_rgb_affine<bgr666_t>(dst_depth);
          }
        } else {
          if (src_depth == rgb565_2Byte) {
            fp_copy = pixelcopy_t::get_fp_copy_rgb_affine<swap565_t>(dst_depth);
            fp_skip = pixelcopy_t::skip_rgb_affine<swap565_t>;
          } else { // src_depth == rgb332_1Byte:
            fp_copy = pixelcopy_t::get_fp_copy_rgb_affine<rgb332_t >(dst_depth);
            fp_skip = pixelcopy_t::skip_rgb_affine<rgb332_t>;
          }
        }
      }
    }

    template<typename TSrc>
    static auto get_fp_copy_rgb_affine(color_depth_t dst_depth) -> std::int32_t(*)(void*, std::int32_t, std::int32_t, pixelcopy_t*)
    {
      return (dst_depth == rgb565_2Byte) ? copy_rgb_affine<swap565_t, TSrc>
           : (dst_depth == rgb332_1Byte) ? copy_rgb_affine<rgb332_t , TSrc>
           : (dst_depth == rgb888_3Byte) ? copy_rgb_affine<bgr888_t, TSrc>
           : (dst_depth == rgb666_3Byte) ? (std::is_same<bgr666_t, TSrc>::value
                                           ? copy_rgb_affine<bgr888_t, bgr888_t>
                                           : copy_rgb_affine<bgr666_t, TSrc>)
           : nullptr;
    }

    template<typename TDst>
    static auto get_fp_copy_rgb_affine_dst(color_depth_t src_depth) -> std::int32_t(*)(void*, std::int32_t, std::int32_t, pixelcopy_t*)
    {
      return (src_depth == rgb565_2Byte) ? copy_rgb_affine<TDst, swap565_t>
           : (src_depth == rgb332_1Byte) ? copy_rgb_affine<TDst, rgb332_t >
           : (src_depth == rgb888_3Byte) ? copy_rgb_affine<TDst, bgr888_t >
                                         : (std::is_same<bgr666_t, TDst>::value)
                                           ? copy_rgb_affine<bgr888_t, bgr888_t>
                                           : copy_rgb_affine<TDst, bgr666_t>;
    }

    template<typename TPalette>
    static auto get_fp_copy_palette_affine(color_depth_t dst_depth) -> std::int32_t(*)(void*, std::int32_t, std::int32_t, pixelcopy_t*)
    {
      return (dst_depth == rgb565_2Byte) ? copy_palette_affine<swap565_t, TPalette>
           : (dst_depth == rgb332_1Byte) ? copy_palette_affine<rgb332_t , TPalette>
           : (dst_depth == rgb888_3Byte) ? copy_palette_affine<bgr888_t, TPalette>
           : (dst_depth == rgb666_3Byte) ? copy_palette_affine<bgr666_t, TPalette>
           : nullptr;
    }

    static std::int32_t copy_bit_fast(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto dst_bits = param->dst_bits;
      auto shift = ((~index) * dst_bits) & 7;
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto d = &(static_cast<std::uint8_t*>(dst)[(index * dst_bits) >> 3]);

      std::uint32_t i = param->positions[0] * param->src_bits;
      param->positions[0] += last - index;
      do {
        std::uint32_t raw = s[i >> 3];
        i += param->src_bits;
        raw = (raw >> (-i & 7)) & param->src_mask;
        *d = (*d & ~(param->dst_mask << shift)) | ((param->dst_mask & raw) << shift);
        if (!shift) ++d;
        shift = (shift - dst_bits) & 7;
      } while (++index != last);
      return last;
    }

    template <typename TDst, typename TPalette>
    static std::int32_t copy_palette_fast(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto d = static_cast<TDst*>(dst);
      auto pal = static_cast<const TPalette*>(param->palette);
      std::uint32_t i = param->positions[0] * param->src_bits;
      param->positions[0] += last - index;
      do {
        std::uint32_t raw = s[i >> 3];
        i += param->src_bits;
        raw = (raw >> (-i & 7)) & param->src_mask;
        d[index] = pal[raw];
      } while (++index != last);
      return index;
    }

    template <typename TDst, typename TSrc>
    static std::int32_t copy_rgb_fast(void* dst, std::int32_t index, std::int32_t last, pixelcopy_t* param)
    {
      auto s = &static_cast<const TSrc*>(param->src_data)[param->positions[0] - index];
      auto d = static_cast<TDst*>(dst);
      param->positions[0] += last - index;
      if (std::is_same<TDst, TSrc>::value)
      {
        memcpy(&d[index], &s[index], (last - index) * sizeof(TSrc));
      }
      else
      {
        do {
          d[index] = s[index];
        } while (++index != last);
      }
      return last;
    }

    static std::int32_t copy_bit_affine(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto d = static_cast<std::uint8_t*>(dst);

      do {
        std::uint32_t i = (param->src_x + param->src_y * param->src_bitwidth) * param->src_bits;
        param->src_x32 += param->src_x32_add;
        param->src_y32 += param->src_y32_add;
        std::uint32_t raw = (s[i >> 3] >> (-(i + param->src_bits) & 7)) & param->src_mask;
        if (raw != param->transp) {
          auto dstidx = index * param->dst_bits;
          auto shift = (-(dstidx + param->dst_bits)) & 7;
          auto tmp = &d[dstidx >> 3];
          *tmp = (*tmp & ~(param->dst_mask << shift)) | ((param->dst_mask & raw) << shift);
        }
      } while (++index != last);
      return index;
    }

    template <typename TDst, typename TPalette>
    static std::int32_t copy_palette_affine(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto d = static_cast<TDst*>(dst);
      auto pal = static_cast<const TPalette*>(param->palette);
      auto transp     = param->transp;
      do {
        std::uint32_t i = (param->src_x + param->src_y * param->src_bitwidth) * param->src_bits;
        std::uint32_t raw = (s[i >> 3] >> (-(i + param->src_bits) & 7)) & param->src_mask;
        if (raw == transp) break;
        d[index] = pal[raw];
        param->src_x32 += param->src_x32_add;
        param->src_y32 += param->src_y32_add;
      } while (++index != last);
      return index;
    }

    template <typename TDst, typename TSrc>
    static std::int32_t copy_rgb_affine(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const TSrc*>(param->src_data);
      auto d = static_cast<TDst*>(dst);
      auto src_x32_add = param->src_x32_add;
      auto src_y32_add = param->src_y32_add;
      do {
        std::uint32_t i = param->src_x + param->src_y * param->src_bitwidth;
        if (s[i] == param->transp) break;
        d[index] = s[i];
        param->src_x32 += src_x32_add;
        param->src_y32 += src_y32_add;
      } while (++index != last);
      return index;
    }

    template <typename TPalette>
    static std::int32_t copy_palette_antialias(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto d = static_cast<argb8888_t*>(dst);
      auto pal = static_cast<const TPalette*>(param->palette);
      auto src_bitwidth= param->src_bitwidth;
      auto src_width   = param->src_width;
      auto src_height  = param->src_height;
      auto transp      = param->transp;
      auto src_bits    = param->src_bits;
      auto src_mask    = param->src_mask;

      param->src_x32 -= param->src_x32_add;
      param->src_xe32 -= param->src_x32_add;
      param->src_y32 -= param->src_y32_add;
      param->src_ye32 -= param->src_y32_add;
      do
      {
        param->src_x32 += param->src_x32_add;
        param->src_xe32 += param->src_x32_add;
        param->src_y32 += param->src_y32_add;
        param->src_ye32 += param->src_y32_add;

        std::int32_t x = param->src_x;
        std::int32_t y = param->src_y;
        if (param->src_x == param->src_xe && param->src_y == param->src_ye)
        {
          std::uint32_t i = (x + y * src_bitwidth) * src_bits;
          std::uint32_t raw = (s[i >> 3] >> (-(i + src_bits) & 7)) & src_mask;
          if (!(raw == transp))
          {
            d[index].set(pal[raw].R8(), pal[raw].G8(), pal[raw].B8());
          }
          else
          {
            d[index] = 0u;
          }
        }
        else
        {
          std::uint32_t argb[5] = {0};
          {
            std::uint32_t rate_x = 256u - (param->src_x_lo >> 8);
            std::uint32_t rate_y = 256u - (param->src_y_lo >> 8);
            std::uint32_t i = y * src_bitwidth;
            for (;;)
            {
              std::uint32_t rate = rate_x * rate_y;
              argb[4] += rate;
              if (static_cast<std::uint32_t>(y) < src_height
               && static_cast<std::uint32_t>(x) < src_width)
              {
                std::uint32_t k = (i + x) * src_bits;
                std::uint32_t raw = (s[k >> 3] >> (-(k + src_bits) & 7)) & src_mask;
                if (!(raw == transp))
                {
                  if (std::is_same<TPalette, argb8888_t>::value) { rate *= pal[raw].A8(); }
                  argb[3] += rate;
                  argb[2] += pal[raw].R8() * rate;
                  argb[1] += pal[raw].G8() * rate;
                  argb[0] += pal[raw].B8() * rate;
                }
              }
              if (++x <= param->src_xe)
              {
                rate_x = (x == param->src_xe) ? (param->src_xe_lo >> 8) + 1 : 256u;
              }
              else
              {
                if (++y > param->src_ye) break;
                rate_y = (y == param->src_ye) ? (param->src_ye_lo >> 8) + 1 : 256u;
                x = param->src_x;
                i += src_bitwidth;
                rate_x = 256u - (param->src_x_lo >> 8);
              }
            }
          }
          std::uint32_t a = argb[3];
          if (!a)
          {
            d[index] = 0u;
          }
          else
          {
            d[index].set( (std::is_same<TPalette, argb8888_t>::value ? a : (a * 255)) / argb[4]
                        , argb[2] / a
                        , argb[1] / a
                        , argb[0] / a
                        );
          }
        }
      } while (++index != last);
      return last;
    }

    template <typename TSrc>
    static std::int32_t copy_rgb_antialias(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const TSrc*>(param->src_data);
      auto d = static_cast<argb8888_t*>(dst);
      auto src_width   = param->src_width;
      auto src_height  = param->src_height;

      param->src_x32 -= param->src_x32_add;
      param->src_xe32 -= param->src_x32_add;
      param->src_y32 -= param->src_y32_add;
      param->src_ye32 -= param->src_y32_add;
      do
      {
        param->src_x32 += param->src_x32_add;
        param->src_xe32 += param->src_x32_add;
        param->src_y32 += param->src_y32_add;
        param->src_ye32 += param->src_y32_add;

        std::int32_t x = param->src_x;
        std::int32_t y = param->src_y;
        auto color = &s[x + y * src_width];
        if (param->src_x == param->src_xe && param->src_y == param->src_ye)
        {
          if (!(*color == param->transp))
          {
            d[index].set(color->R8(), color->G8(), color->B8());
          }
          else
          {
            d[index] = 0u;
          }
        }
        else
        {
          std::uint32_t argb[5] = {0};
          {
            std::uint32_t rate_y = 256u - (param->src_y_lo >> 8);
            std::uint32_t rate_x = 256u - (param->src_x_lo >> 8);
            for (;;)
            {
              std::uint32_t rate = rate_x * rate_y;
              argb[4] += rate;
              if (static_cast<std::uint32_t>(y) < src_height
               && static_cast<std::uint32_t>(x) < src_width
               && !(*color == param->transp))
              {
                if (std::is_same<TSrc, argb8888_t>::value) { rate *= color->A8(); }
                argb[3] += rate;
                argb[2] += color->R8() * rate;
                argb[1] += color->G8() * rate;
                argb[0] += color->B8() * rate;
              }
              if (x != param->src_xe)
              {
                ++color;
                rate_x = (++x == param->src_xe) ? (param->src_xe_lo >> 8) + 1 : 256u;
              }
              else
              {
                if (++y > param->src_ye) break;
                rate_y = (y == param->src_ye) ? (param->src_ye_lo >> 8) + 1 : 256u;
                x = param->src_x;
                color += x + src_width - param->src_xe;
                rate_x = 256u - (param->src_x_lo >> 8);
              }
            }
          }
          std::uint32_t a = argb[3];
          if (!a)
          {
            d[index] = 0u;
          }
          else
          {
            d[index].set( (std::is_same<TSrc, argb8888_t>::value ? a : (a * 255)) / argb[4]
                        , argb[2] / a
                        , argb[1] / a
                        , argb[0] / a
                        );
          }
        }
//d[index].a = 255;
//d[index].b = 255;
      } while (++index != last);
      return last;
    }


    static std::int32_t blend_palette_fast(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = &(static_cast<const argb8888_t*>(param->src_data)[param->src_x + param->src_y * param->src_bitwidth - index]);
      auto dst_bits = param->dst_bits;
      auto dst_mask = param->dst_mask;
      std::uint32_t k = (dst_bits == 1) ? 0xFF
                      : (dst_bits == 2) ? 0x55
                      : (dst_bits == 4) ? 0x11
                                        : 0x01
                                        ;
      auto shift = ((~index) * dst_bits) & 7;
      auto d = &(static_cast<std::uint8_t*>(dst)[(index * dst_bits) >> 3]);
      do {
        std::uint_fast16_t a = s[index].a;
        if (a)
        {
          std::uint32_t raw = (s[index].R8() + (s[index].G8()<<1) + s[index].B8()) >> 2;
          if (a != 255)
          {
            std::uint_fast16_t inv = (256 - a) * k;
            raw = (((*d >> shift) & dst_mask) * inv + raw * ++a) >> 8;
          }
          *d = (*d & ~(dst_mask << shift)) | (dst_mask & (raw >> (8 - dst_bits))) << shift;
        }
        if (!shift) ++d;
        shift = (shift - dst_bits) & 7;
      } while (++index != last);
      return last;
    }

    template <typename TDst>
    static std::int32_t blend_rgb_fast(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = &(static_cast<const argb8888_t*>(param->src_data)[param->src_x + param->src_y * param->src_bitwidth - index]);
      auto d = static_cast<TDst*>(dst);
      for (;;) {
        std::uint_fast16_t a = s[index].a;
        if (a)
        {
          if (a == 255)
          {
            d[index].set(s[index].r, s[index].g, s[index].b);
            if (++index == last) return last;
            continue;
          }

          std::uint_fast16_t inv = 256 - a;
          ++a;
          d[index].set( (d[index].R8() * inv + s[index].R8() * a) >> 8
                      , (d[index].G8() * inv + s[index].G8() * a) >> 8
                      , (d[index].B8() * inv + s[index].B8() * a) >> 8
                      );
        }
        if (++index == last) return last;
      }
    }

    static std::int32_t skip_bit_affine(std::int32_t index, std::int32_t last, pixelcopy_t* param)
    {
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto src_x32     = param->src_x32;
      auto src_y32     = param->src_y32;
      auto src_x32_add = param->src_x32_add;
      auto src_y32_add = param->src_y32_add;
      auto src_bitwidth= param->src_bitwidth;
      auto transp      = param->transp;
      auto src_bits    = param->src_bits;
      auto src_mask    = param->src_mask;
      do {
        std::uint32_t i = ((src_x32 >> FP_SCALE) + (src_y32 >> FP_SCALE) * src_bitwidth) * src_bits;
        std::uint32_t raw = (s[i >> 3] >> (-(i + src_bits) & 7)) & src_mask;
        if (raw != transp) break;
        src_x32 += src_x32_add;
        src_y32 += src_y32_add;
      } while (++index != last);
      param->src_x32 = src_x32;
      param->src_y32 = src_y32;
      return index;
    }

    template <typename TSrc>
    static std::int32_t skip_rgb_affine(std::int32_t index, std::int32_t last, pixelcopy_t* param)
    {
      auto s = static_cast<const TSrc*>(param->src_data);
      auto src_x32     = param->src_x32;
      auto src_y32     = param->src_y32;
      auto src_x32_add = param->src_x32_add;
      auto src_y32_add = param->src_y32_add;
      auto src_bitwidth= param->src_bitwidth;
      auto transp      = param->transp;
      do {
        std::uint32_t i = (src_x32 >> FP_SCALE) + (src_y32 >> FP_SCALE) * src_bitwidth;
        if (!(s[i] == transp)) break;
        src_x32 += src_x32_add;
        src_y32 += src_y32_add;
      } while (++index != last);
      param->src_x32 = src_x32;
      param->src_y32 = src_y32;
      return index;
    }

    template <typename TSrc>
    static std::int32_t compare_rgb_fast(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const TSrc*>(param->src_data);
      auto d = static_cast<bool*>(dst);
      auto transp = param->transp;
      std::uint32_t i = param->src_x + param->src_y * param->src_bitwidth - 1;
      do {
        d[index] = s[++i] == transp;
      } while (++index != last);
      return index;
    }

    static std::int32_t compare_bit_fast(void* __restrict__ dst, std::int32_t index, std::int32_t last, pixelcopy_t* __restrict__ param)
    {
      auto s = static_cast<const std::uint8_t*>(param->src_data);
      auto d = static_cast<bool*>(dst);
      auto transp      = param->transp;
      auto src_bits    = param->src_bits;
      auto src_mask    = param->src_mask;
      std::uint32_t i = (param->src_x + param->src_y * param->src_bitwidth) * src_bits;
      do {
        d[index] = transp == ((s[i >> 3] >> (-(i + src_bits) & 7)) & src_mask);
        i += src_bits;
      } while (++index != last);
      return index;
    }
  };

//----------------------------------------------------------------------------
  struct DataWrapper
  {
    bool need_transaction = false;

    std::uint16_t read16(void) {
      std::uint16_t result;
      read(reinterpret_cast<std::uint8_t*>(&result), 2);
      return result;
    }

    std::uint32_t read32(void) {
      std::uint32_t result;
      read(reinterpret_cast<std::uint8_t*>(&result), 4);
      return result;
    }

    __attribute__ ((always_inline)) inline std::uint16_t read16swap(void) { return __builtin_bswap16(read16()); }
    __attribute__ ((always_inline)) inline std::uint32_t read32swap(void) { return __builtin_bswap32(read32()); }

    virtual int read(std::uint8_t *buf, std::uint32_t len) = 0;
    virtual void skip(std::int32_t offset) = 0;
    virtual bool seek(std::uint32_t offset) = 0;
    virtual void close(void) = 0;

    __attribute__ ((always_inline)) inline void preRead(void) { if (fp_pre_read) fp_pre_read(parent); }
    __attribute__ ((always_inline)) inline void postRead(void) { if (fp_post_read) fp_post_read(parent); }
    __attribute__ ((always_inline)) inline bool hasParent(void) const { return parent; }
    void* parent = nullptr;
    void (*fp_pre_read)(void*) = nullptr;
    void (*fp_post_read)(void*) = nullptr;
  };
//----------------------------------------------------------------------------
  struct PointerWrapper : public DataWrapper
  {
    void set(const std::uint8_t* src, std::uint32_t length = ~0) { _ptr = src; _length = length; _index = 0; }
    int read(std::uint8_t *buf, std::uint32_t len) override {
      if (len > _length - _index) { len = _length - _index; }
      memcpy(buf, &_ptr[_index], len);
      _index += len;
      return len;
    }
    void skip(std::int32_t offset) override { _index += offset; }
    bool seek(std::uint32_t offset) override { _index = offset; return true; }
    void close(void) override { }

  private:
    const std::uint8_t* _ptr;
    std::uint32_t _index = 0;
    std::uint32_t _length = 0;
  };

//----------------------------------------------------------------------------

  struct bitmap_header_t
  {
    union
    {
      std::uint8_t raw[54];
      struct {
        std::uint16_t bfType;
        std::uint32_t bfSize;
        std::uint16_t bfReserved1;
        std::uint16_t bfReserved2;
        std::uint32_t bfOffBits;

        std::uint32_t biSize;
        std::int32_t  biWidth;
        std::int32_t  biHeight;
        std::uint16_t biPlanes; 
        std::uint16_t biBitCount;
        std::uint32_t biCompression;
        std::uint32_t biSizeImage;
        std::int32_t  biXPelsPerMeter;
        std::int32_t  biYPelsPerMeter;
        std::uint32_t biClrUsed;
        std::uint32_t biClrImportant;
      } __attribute__((packed));
    };

    bool load_bmp_header(DataWrapper* data)
    {
      data->read((std::uint8_t*)this, sizeof(bitmap_header_t));
      return ( (bfType == 0x4D42)   // bmp header "BM"
            && (biPlanes == 1)  // bcPlanes always 1
            && (biWidth > 0)
            && (biHeight != 0)
            && (biBitCount <= 32)
            && (biBitCount != 0));
    }

    static bool load_bmp_rle8(DataWrapper* data, std::uint8_t* linebuf, uint_fast16_t width)
    {
      width = (width + 3) & ~3;
      std::uint8_t code[2];
      uint_fast16_t xidx = 0;
      bool eol = false;
      do {
        data->read(code, 2);
        if (code[0] == 0) {
          switch (code[1]) {
          case 0x00: // EOL
          case 0x01: // EOB
            eol = true;
            break;

          case 0x02: // move info  (not support)
            return false;

          default:
            data->read(&linebuf[xidx], (code[1] + 1) & ~1); // word align
            xidx += code[1];
            break;
          }
        } else if (xidx + code[0] <= width) {
          memset(&linebuf[xidx], code[1], code[0]);
          xidx += code[0];
        } else {
          return false;
        }
      } while (!eol);
      return true;
    }

    static bool load_bmp_rle4(DataWrapper* data, std::uint8_t* linebuf, uint_fast16_t width)
    {
      width = (width + 3) & ~3;
      std::uint8_t code[2];
      uint_fast16_t xidx = 0;
      bool eol = false;
      do {
        data->read(code, 2);
        if (code[0] == 0) {
          switch (code[1]) {
          case 0x00: // EOL
          case 0x01: // EOB
            eol = true;
            break;

          case 0x02: // move info  (not support)
            return false;

          default:  // 絶対モードデータ
            {
              int_fast16_t len = code[1];
              int_fast16_t dbyte = ((int_fast16_t)code[1] + 1) >> 1;

              data->read(&linebuf[(xidx + 1) >> 1], (dbyte + 1) & ~1); // word align
              if (xidx & 1) {
                linebuf[xidx >> 1] |= linebuf[(xidx >> 1) + 1] >> 4;
                for (long i = 1; i < dbyte; ++i) {
                  linebuf[((xidx + i) >> 1)] = (linebuf[((xidx + i) >> 1)    ] << 4)
                                              |  linebuf[((xidx + i) >> 1) + 1] >> 4;
                }
              }
              xidx += len;
            }
            break;
          }
        } else if (xidx + code[0] <= width) {
          if (xidx & 1) {
            linebuf[xidx >> 1] |= code[1] >> 4;
            code[1] = (code[1] >> 4) | (code[1] << 4);
          }
          memset(&linebuf[(xidx + 1) >> 1], code[1], (code[0] + 1) >> 1);
          xidx += code[0];
          if (xidx & 1) linebuf[xidx >> 1] &= 0xF0;
        } else {
          return false;
        }
      } while (!eol);
      return true;
    }
  };

//----------------------------------------------------------------------------

  struct TextStyle
  {
    std::uint32_t fore_rgb888 = 0xFFFFFFU;
    std::uint32_t back_rgb888 = 0;
    float size_x = 1;
    float size_y = 1;
    textdatum_t datum = textdatum_t::top_left;
    bool utf8 = true;
    bool cp437 = false;
  };

//----------------------------------------------------------------------------

  namespace spi
  {
    void init(int spi_host, int spi_sclk, int spi_miso, int spi_mosi);
    void release(int spi_host);
    void beginTransaction(int spi_host, int spi_cs, int freq, int spi_mode = 0);
    void beginTransaction(int spi_host);
    void endTransaction(int spi_host, int spi_cs);
    void writeData(int spi_host, const std::uint8_t* data, std::uint32_t len);
    void readData(int spi_host, std::uint8_t* data, std::uint32_t len);
  }

  namespace i2c
  {
    void init(int i2c_port, int pin_sda, int pin_scl, int freq);
    bool writeBytes(int i2c_port, std::uint16_t addr, std::uint8_t *data, std::uint8_t len);
    bool readRegister(int i2c_port, std::uint16_t addr, std::uint8_t reg, std::uint8_t *data, std::uint8_t len);
    bool writeRegister8(int i2c_port, std::uint16_t addr, std::uint8_t reg, std::uint8_t data, std::uint8_t mask = 0);
    inline bool bitOn(int i2c_port, std::uint16_t addr, std::uint8_t reg, std::uint8_t bit)  { return writeRegister8(i2c_port, addr, reg, bit, ~0); }
    inline bool bitOff(int i2c_port, std::uint16_t addr, std::uint8_t reg, std::uint8_t bit) { return writeRegister8(i2c_port, addr, reg, 0, ~bit); }
  }

//----------------------------------------------------------------------------
}

using namespace lgfx::jpeg_div;
using namespace lgfx::colors;
using namespace lgfx::textdatum;
using namespace lgfx::attribute;


typedef lgfx::bgr888_t RGBColor;

#if defined (ESP32) || defined (CONFIG_IDF_TARGET_ESP32) || defined (ESP_PLATFORM)

  #include "platforms/esp32_common.hpp"

#elif defined (__SAMD51__)

  #include "platforms/samd51_common.hpp"

#endif



#endif
