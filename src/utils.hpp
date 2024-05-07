#pragma once

#include <string>
#if __has_include(<variant>)
#include <variant>
#else
#include <boost/variant/apply_visitor.hpp>
#endif

namespace mstch {

using citer = std::string::const_iterator;
using criter = std::string::const_reverse_iterator;

citer first_not_ws(citer begin, citer end);
citer first_not_ws(criter begin, criter end);
std::string html_escape(const std::string& str);
criter reverse(citer it);

#if __has_include(<variant>)
template<class... Args>
auto visit(Args&&... args) -> decltype(std::visit(std::forward<Args>(args)...))
{
    return std::visit(std::forward<Args>(args)...);
}

#else
template<class... Args>
auto visit(Args&&... args) -> decltype(boost::apply_visitor(
    std::forward<Args>(args)...))
{
  return boost::apply_visitor(std::forward<Args>(args)...);
}
#endif

}
