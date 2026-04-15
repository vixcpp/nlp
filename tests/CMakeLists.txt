cmake_minimum_required(VERSION 3.20)

#  @file test/CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Tests for the vix_ai_nlp module.
#
#  Minimal assert-based tests for the NLP module.
#  Each test is built as a small executable and registered with CTest.

add_executable(vix_ai_nlp_test_tokenizer
  tokenizer_tests.cpp
)
target_link_libraries(vix_ai_nlp_test_tokenizer
  PRIVATE
    vix::ai::nlp
)
target_compile_features(vix_ai_nlp_test_tokenizer PRIVATE cxx_std_20)
add_test(NAME nlp_tokenizer COMMAND vix_ai_nlp_test_tokenizer)
set_tests_properties(nlp_tokenizer PROPERTIES LABELS "nlp;tokenizer")

add_executable(vix_ai_nlp_test_embedding
  embedding_tests.cpp
)
target_link_libraries(vix_ai_nlp_test_embedding
  PRIVATE
    vix::ai::nlp
)
target_compile_features(vix_ai_nlp_test_embedding PRIVATE cxx_std_20)
add_test(NAME nlp_embedding COMMAND vix_ai_nlp_test_embedding)
set_tests_properties(nlp_embedding PROPERTIES LABELS "nlp;embedding")

add_executable(vix_ai_nlp_test_pipeline
  pipeline_tests.cpp
)
target_link_libraries(vix_ai_nlp_test_pipeline
  PRIVATE
    vix::ai::nlp
)
target_compile_features(vix_ai_nlp_test_pipeline PRIVATE cxx_std_20)
add_test(NAME nlp_pipeline COMMAND vix_ai_nlp_test_pipeline)
set_tests_properties(nlp_pipeline PROPERTIES LABELS "nlp;pipeline")

add_executable(vix_ai_nlp_test_loader
  loader_tests.cpp
)
target_link_libraries(vix_ai_nlp_test_loader
  PRIVATE
    vix::ai::nlp
)
target_compile_features(vix_ai_nlp_test_loader PRIVATE cxx_std_20)
add_test(NAME nlp_loader COMMAND vix_ai_nlp_test_loader)
set_tests_properties(nlp_loader PROPERTIES LABELS "nlp;loader")
