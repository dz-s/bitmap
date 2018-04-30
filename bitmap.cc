#include <iostream>
#include <ft2build.h>
#include <nan.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
using namespace std;
using namespace v8;

void getCharBitmap(const FunctionCallbackInfo<Value>& args)
{
    FT_Library library;
    FT_Init_FreeType(&library);
    FT_Face face;
    FT_New_Face(library,
                "/usr/share/fonts/truetype/fonts-japanese-gothic.ttf",
                0,
                &face);
    FT_GlyphSlot g = face->glyph;
    Isolate * isolate = args.GetIsolate();

    v8::String::Utf8Value s1(args[0]);
    std::string str(*s1, s1.length());
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    FT_Set_Pixel_Sizes(face, 0, 36);
    FT_Load_Char(face, *cstr , FT_LOAD_RENDER);
   
    string s = " ";

    for (int y = 0; y < g->bitmap.rows; ++y)
    {
        for (int i = 0; i < g->bitmap.width; ++i)
        {
            unsigned char a = g->bitmap.buffer[y * g->bitmap.width + i];
            if (a == 0)
            {
                s += ' ';
            }
            else if (a < 128)
            {
                s += '+';
            }
            else
            {
                s += '#';
            }
        }
        s += '\n';
    }
    Local<String> hTextJS = String::NewFromUtf8(Isolate::GetCurrent(), s.c_str());
    args.GetReturnValue().Set(hTextJS);
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getCharBitmap", getCharBitmap);
}

NODE_MODULE(addon, Init)