# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Unreleased]

### Added
- Basic tokenization and text preprocessing (lowercasing, punctuation removal, stemming).
- Vocabulary management and embedding support.
- Simple models: Bag-of-Words, TF-IDF, and basic sequence classifiers.
- Integration with Vix AI Tensor for tensor-based text representations.
- Unit tests for NLP pipelines and preprocessing functions.

### Changed
- N/A

### Fixed
- N/A

---

## [0.1.0] - 2026-03-13

### Added
- Initial release of Vix AI NLP library.
- Core classes:
  - `Tokenizer` for splitting text into tokens.
  - `Vocabulary` for managing unique tokens and embeddings.
  - `TextPreprocessor` for cleaning and normalizing text.
  - `SequenceModel` for simple NLP classification tasks.
- CMake build system with options for tests, warnings, and installation.
- Example programs demonstrating text preprocessing and simple model training.
- Fully compatible with Vix AI Tensor for embeddings and vectorized operations.

### Changed
- N/A

### Fixed
- N/A
