#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <filesystem>

#include "compare_files.hpp"
#include "capture_output.hpp"

void test_text_input(const std::filesystem::path &my_exe, const std::filesystem::path &my_input, const std::filesystem::path &my_actual, const std::filesystem::path &my_expected)
{
    const std::filesystem::path root = PROJECT_ROOT_DIR;

    const std::filesystem::path cmd = root / "build" / "tests" / my_exe;
    const std::filesystem::path input = root / "tests" / "IO" / my_input;
    const std::filesystem::path actual = root / "tests" / "IO" / my_actual;
    const std::filesystem::path expected = root / "tests" / "IO" / my_expected;

    REQUIRE_NOTHROW(capture_output(cmd.string(), input.string(), actual.string()));
    REQUIRE_NOTHROW(compare_files(actual.string(), expected.string()));
}

TEST_CASE("Check ex1 empty", "[compare_output]")
{
    test_text_input("test_ex1", "empty_input.txt", "empty_actual.txt", "empty_output.txt");
}

TEST_CASE("Check ex1 one line", "[compare_output]")
{
    test_text_input("test_ex1", "one_line_input.txt", "one_line_actual.txt", "one_line_output.txt");
}

TEST_CASE("Check ex1 multiple lines", "[compare_output]")
{
    test_text_input("test_ex1", "multiple_line_input.txt", "multiple_line_actual.txt", "multiple_line_output.txt");
}

TEST_CASE("Check ex1 spaces and tabs", "[compare_output]")
{
    test_text_input("test_ex1", "spaces_and_tabs_input.txt", "spaces_and_tabs_actual.txt", "spaces_and_tabs_output.txt");
}
