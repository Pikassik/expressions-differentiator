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
  if (inversed_identifiers_.empty()) {
    InitReversed();
  }
  return inversed_identifiers_;
}

void NodesIdentifierSingleton::Init() {
  identifiers_["+"] = 2;
}

void NodesIdentifierSingleton::InitReversed() {
  inversed_identifiers_[2] = "+";
}

const int NodesIdentifierSingleton::kNumberId = 0;

std::unordered_map<std::string_view, int>
NodesIdentifierSingleton::identifiers_;

std::unordered_map<int, std::string_view>
NodesIdentifierSingleton::inversed_identifiers_;