#pragma once


template <class T>
class StaticAllocator {
 public:
  StaticAllocator() = delete;
  StaticAllocator(T* static_storage) noexcept
  : static_storage_(static_storage) {}
  StaticAllocator(const StaticAllocator&) noexcept = default;
  StaticAllocator(StaticAllocator&&) noexcept = default;
  StaticAllocator& operator=(const StaticAllocator&) noexcept = default;
  StaticAllocator& operator=(StaticAllocator&&) noexcept = default;
  T* allocate() noexcept { return static_storage_; }
  void deallocate() {}
 private:
  T* static_storage_;
};