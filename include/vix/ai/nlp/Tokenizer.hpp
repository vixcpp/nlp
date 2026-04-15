/**
 *
 *  @file Tokenizer.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/vixcpp/vix
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 */
#ifndef VIX_AI_NLP_TOKENIZER_HPP
#define VIX_AI_NLP_TOKENIZER_HPP

#include <string>
#include <vector>
#include <sstream>

namespace vix::ai::nlp
{
  struct Tokenizer
  {
    std::vector<std::string> tokenize(const std::string &s) const
    {
      std::vector<std::string> toks;
      std::istringstream iss(s);
      for (std::string t; iss >> t;)
        toks.push_back(std::move(t));
      return toks;
    }
  };

} // namespace vix::ai::nlp

#endif
