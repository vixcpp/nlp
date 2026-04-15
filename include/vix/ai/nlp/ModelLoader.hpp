/**
 *
 *  @file ModelLoader.hpp
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
#ifndef VIX_AI_NLP_MODEL_LOADER_HPP
#define VIX_AI_NLP_MODEL_LOADER_HPP

#include <string>

namespace vix::ai::nlp
{

  struct ModelLoader
  {
    bool load(const std::string & /*path*/) { return true; }
  };

} // namespace vix::ai::nlp

#endif
