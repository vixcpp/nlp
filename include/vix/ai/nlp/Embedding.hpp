/**
 *
 *  @file Embedding.hpp
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
#ifndef VIX_AI_NLP_EMBEDDING_HPP
#define VIX_AI_NLP_EMBEDDING_HPP

#include <string>
#include <vector>

namespace vix::ai::nlp
{
  struct Embedding
  {
    std::vector<float> encode(const std::string &s) const
    {
      return {static_cast<float>(s.size())};
    }
  };

} // namespace vix::ai::nlp

#endif
