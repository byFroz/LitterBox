/*
 * Copyright (c) 2019 M.I.T. License
 *
 * This is LitterBox's system resources
 * header file -- containing access to 
 * things such as system time, memory
 * allocation, and much more.
 *
 * Author(s):
 * + Froz
*/

#ifndef _RESOURCES_HPP_
#define _RESOURCES_HPP_

#include <cstdint>
#include <cstdib>
#include <cstdlib>

namespace LitterBox
{
    struct Heap
    {
    public:
        static void* Allocate(unsigned bytes) noexcept; // This function can throw many errors, but I told C++ to snooze them.
        static uintptr_t Deallocate(void &pointer) noexcept; // Likewise, here.
    };
    
    void* Heap::Allocate(unsigned bytes) noexcept
    {
        int *ptr = nullptr;
        ptr = static_cast<int*>(malloc(bytes));
        if (ptr != NULL)
            return ptr;
        else
            return nullptr;
    }
    
    uintptr_t Heap::Deallocate(void &pointer) noexcept
    {
        if (pointer == NULL)
            return pointer;
        else
        {
            free(pointer);
            return 0;
        }
    }
    
    struct Time
    {
    public:
        static auto GetCurrentTime() decltype(std::chrono::time_point<std::chrono::system_clock>);
    };
    
    auto Time::GetCurrentTime() decltype(std::chrono::time_point<std::chrono::system_clock>) ->
    {
        auto time = std::chrono::system_clock::now();
        return time;
    }
} // namespace LitterBox

#endif // _RESOURCES_HPP_
