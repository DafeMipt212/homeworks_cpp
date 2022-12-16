#include <catch2/catch_test_macros.hpp>

#include "utils.hpp"

TEST_CASE("SplitString", "[simple]") {
  CHECK(SplitString("") == std::vector<std::string>{});
  CHECK(SplitString("aaa") == std::vector<std::string>{"aaa"});
  CHECK(SplitString("aaa aaa") == std::vector<std::string>{"aaa", "aaa"});
  CHECK(SplitString("aaa aaa ") == std::vector<std::string>{"aaa", "aaa"});
  CHECK(SplitString(" ") == std::vector<std::string>{});
  CHECK(SplitString("??? ??") == std::vector<std::string>{"???", "??"});
  CHECK(SplitString("a\na\ta a") == std::vector<std::string>{"a\na", "a", "a"});
  CHECK(SplitString("a (a a)") == std::vector<std::string>{"a", "(a a)"});
  CHECK(SplitString("a (a a) b (asd as)  ") == std::vector<std::string>{"a", "(a a)", "b", "(asd as)"});
  CHECK(SplitString("a (a a) b (asd as)  ") == std::vector<std::string>{"a", "(a a)", "b", "(asd as)"});
  CHECK(SplitString("yandex yandex yandex yep") == std::vector<std::string>{"yandex", "yandex", "yandex", "yep"});
  CHECK(
  SplitString(
    "Штирлиц играл в карты в компании и проигрался. "
    "Но он умел делать хорошую мину при плохой игре. "
    "Когда Штирлиц покинул компанию, мину взорвалась."
  ) == std::vector<std::string>{
    "Штирлиц", "играл", "в", "карты", "в", "компании", "и", "проигрался.", 
    "Но", "он", "умел", "делать", "хорошую", "мину", "при", "плохой", "игре.", 
    "Когда", "Штирлиц", "покинул", "компанию,", "мину", "взорвалась."
  });
  
  CHECK(SplitString("(awawa juju)") == std::vector<std::string>{"(awawa juju)"});

}

