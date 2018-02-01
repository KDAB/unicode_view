#include "unicode_view"

#include <algorithm>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("unicode_view")
{
    SECTION("simple comparison with a reference string") {
        const char     str8[]  = u8"€Hello𐐷7バイト以上の文字は規定されないため、0xFE、0xFF (BOM) に0xFEと0xFFを使用するUTF-16やUTF-32が、UTF-8と混同されることはない。UTF-16 is specified in the latest versions of both the international standard ISO/IEC 10646 and the Unicode Standard.";
        const char16_t str16[] = u"€Hello𐐷7バイト以上の文字は規定されないため、0xFE、0xFF (BOM) に0xFEと0xFFを使用するUTF-16やUTF-32が、UTF-8と混同されることはない。UTF-16 is specified in the latest versions of both the international standard ISO/IEC 10646 and the Unicode Standard.";
        const char32_t str32[] = U"€Hello𐐷7バイト以上の文字は規定されないため、0xFE、0xFF (BOM) に0xFEと0xFFを使用するUTF-16やUTF-32が、UTF-8と混同されることはない。UTF-16 is specified in the latest versions of both the international standard ISO/IEC 10646 and the Unicode Standard.";

        const auto view8 = kdab::make_unicode_view(std::begin(str8), std::end(str8));
        const auto view16 = kdab::make_unicode_view(std::begin(str16), std::end(str16));
        const auto view32 = kdab::make_unicode_view(std::begin(str32), std::end(str32));

        REQUIRE( std::equal(std::begin(view8),  std::end(view8),  std::begin(str32), std::end(str32)) );
        REQUIRE( std::equal(std::begin(view16), std::end(view16), std::begin(str32), std::end(str32)) );
        REQUIRE( std::equal(std::begin(view32), std::end(view32), std::begin(str32), std::end(str32)) );
    }

    SECTION("UTF-8 decoding") {
        SECTION("Valid UTF-8") {

        }

        SECTION("Illegal code units") {

        }

        SECTION("Overlong sequence") {

        }

        SECTION("Illegal code points") {

        }
    }

    SECTION("UTF-16 decoding") {
        SECTION("Valid UTF-16") {

        }

        SECTION("Illegal code units") {

        }

        SECTION("Illegal code points") {

        }
    }
}
