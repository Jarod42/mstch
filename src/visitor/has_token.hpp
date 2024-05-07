#pragma once

#if !__has_include(<variant>)
#include <boost/variant/static_visitor.hpp>
#endif

#include "mstch/mstch.hpp"

namespace mstch {

class has_token
#if !__has_include(<variant>)
    : public boost::static_visitor<bool>
#endif
{
 public:
  has_token(const std::string& token): m_token(token) {
  }

  template<class T>
  bool operator()(const T&) const {
    return m_token == ".";
  }

  bool operator()(const map& map) const {
    return map.count(m_token) == 1;
  }

  bool operator()(const std::shared_ptr<object>& object) const {
    return object->has(m_token);
  }

 private:
  const std::string& m_token;
};

}
