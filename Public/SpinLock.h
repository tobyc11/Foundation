#pragma once
#include <atomic>

namespace tc
{

class FSpinLock
{
public:
    void Lock()
    {
        while (LockFlag.test_and_set(std::memory_order_acquire))
        {
        }
    }

    void Unlock() { LockFlag.clear(std::memory_order_release); }

private:
    alignas(64) std::atomic_flag LockFlag = ATOMIC_FLAG_INIT;
};

}
