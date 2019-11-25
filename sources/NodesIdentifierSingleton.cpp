#include <NodesIdentifierSingleton.h>

const std::unordered_map<std::string_view, int>&
NodesIdentifierSingleton::Instance() {
  if (identifiers_.empty()) {
    Init();
  }
  return identifiers_;
}

const std::unordered_map<int, std::string_view>&
NodesIdentifierSingleton::InstanceReversed() {
  if (inverse_identifiers_.empty()) {
    InitReversed();
  }
  return inverse_identifiers_;
}

void NodesIdentifierSingleton::Init() {
  identifiers_["+"] = 2;
  identifiers_["sin"] = 3;
  identifiers_["x"] = 1;
  identifiers_["*"] = 4;
}

void NodesIdentifierSingleton::InitReversed() {
  inverse_identifiers_[2] = "+";
  inverse_identifiers_[3] = "sin";
  inverse_identifiers_[1] = "x";
  inverse_identifiers_[4] = "*";
}

const int NodesIdentifierSingleton::kNumberId = 0;

std::unordered_map<std::string_view, int>
NodesIdentifierSingleton::identifiers_;

std::unordered_map<int, std::string_view>
NodesIdentifierSingleton::inverse_identifiers_;