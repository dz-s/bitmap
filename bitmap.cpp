#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
using namespace std;

int main()
{
    FT_Library  library;
    FT_Face     face;
    FT_GlyphSlot g = face->glyph;
    FT_Load_Char(face, 'A', FT_LOAD_RENDER);

    cout << g << endl;
    return 0;
}
