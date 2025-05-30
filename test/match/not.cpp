#include "test_matcher.hpp"

#include <match/ops.hpp>

#include <stdx/ct_format.hpp>

#include <catch2/catch_test_macros.hpp>

#include <type_traits>

TEST_CASE("NOT fulfils matcher concept", "[match not]") {
    using T = decltype(not test_matcher{});
    STATIC_REQUIRE(match::matcher<T>);
    STATIC_REQUIRE(match::matcher_for<T, int>);
}

TEST_CASE("NOT describes itself", "[match not]") {
    constexpr auto e = not test_matcher{};
    STATIC_REQUIRE(e.describe() ==
                   stdx::ct_format<"not ({})">(test_m<0>{}.describe()));
}

TEST_CASE("NOT describes a match", "[match not]") {
    constexpr auto e = not test_matcher{};
    STATIC_REQUIRE(
        e.describe_match(1) ==
        stdx::ct_format<"not ({})">(test_matcher{}.describe_match(1)));
}

TEST_CASE("NOT matches correctly", "[match not]") {
    STATIC_REQUIRE((not test_matcher{})(0));
    STATIC_REQUIRE(not(not test_matcher{})(1));
}

TEST_CASE("NOT simplifies correctly", "[match not]") {
    constexpr auto e = not not test_matcher{};
    STATIC_REQUIRE(std::is_same_v<decltype(e), test_matcher const>);
}
