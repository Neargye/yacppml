// cpp_attributes example
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// Copyright (c) 2018 Daniil Goncharov <neargye@gmail.com>.
//
// Permission is hereby  granted, free of charge, to any  person obtaining a copy
// of this software and associated  documentation files (the "Software"), to deal
// in the Software  without restriction, including without  limitation the rights
// to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
// copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
// IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
// FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
// AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cpp_attributes.hpp>
#include <exception>

CPP_ATTRIBUTE_MAYBE_UNUSED float foo1(CPP_ATTRIBUTE_MAYBE_UNUSED int i) {  // No warning: unused parameter 'i'.
  return 42.0f;
}

CPP_ATTRIBUTE_NORETURN void foo2() { std::terminate(); }

CPP_ATTRIBUTE_DEPRECATED void foo3() {}

// TODO: CPP_ATTRIBUTE_DEPRECATED("deprecated") void foo4() {}

CPP_ATTRIBUTE_NODISCARD int foo5() { return 42; }

int main() {
  CPP_ATTRIBUTE_MAYBE_UNUSED int a = foo5();  // No warning: unused variable 'a'.

  switch (a) {
    case 1:
      CPP_ATTRIBUTE_FALLTHROUGH
    default:
      break;
  }

  return 0;
}