/**
 *
 *  @file Pipeline.hpp
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
#ifndef VIX_AI_NLP_PIPELINE_HPP
#define VIX_AI_NLP_PIPELINE_HPP

#include <string>

namespace vix::ai::nlp
{
  class Pipeline
  {
  public:
    std::string summarize(const std::string &s) const { return s; }
  };

} // namespace vix::ai::nlp

#endif
