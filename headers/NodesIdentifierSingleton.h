#include <memory>
#include <unordered_map>

class NodesIdentifierSingleton {
 public:
  NodesIdentifierSingleton()  = delete;
  ~NodesIdentifierSingleton() = delete;
  NodesIdentifierSingleton(const NodesIdentifierSingleton&) = delete;
  NodesIdentifierSingleton& operator=(const NodesIdentifierSingleton&) = delete;
  NodesIdentifierSingleton(NodesIdentifierSingleton&&) = delete;
  NodesIdentifierSingleton& operator=(NodesIdentifierSingleton&&) = delete;
  static const std::unordered_map<std::string_view, int>& Instance();
  static const std::unordered_map<int, std::string_view>& InstanceReversed();
  static const int kNumberId;
 private:
  static void Init();
  static void InitReversed();
  static std::unordered_map<std::string_view, int> identifiers_;
  static std::unordered_map<int, std::string_view> inversed_identifiers_;
};
