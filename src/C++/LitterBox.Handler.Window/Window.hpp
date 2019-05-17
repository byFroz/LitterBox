/*
 * Copyright (c) 2019 M.I.T. License
 *
 * This header file contains the source
 * code for LitterBox's window handler.
 *
 * An estimated 90% of the following source 
 * code is heavily reliant on Microsoft's C++ 
 * SDK library "Windows.h"; without it,
 * almost all of these instructions will
 * fail to operate.
 *
 * Author(s):
 * + Froz
*/

#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <cstdint>
#include <string>
#include <vector>
#include <Windows.h>

using string = std::string; // Saves typing "std::" before "string".

namespace LitterBox
{
    class Window
    {
    public:
        Window(string label) : m_label("Undefined"); // Sets the @label param to "Undefined", if nothing is passed.
        ~Window();
        void SetLabel(string label);
        string GetLabel();
        bool IsRunning();
        HWND GetWindow();
        DWORD GetWindowId();
        HANDLE GetWindowHandle();
        template<typename T>
        T WriteWindowMemory(DWORD addr, T newValue) decltype(newValue);
    private:
        std::vector<string> labels;
        string m_label;
    };
    
    Window::Window(string label) : m_label("Undefined")
    {
        this->m_label = label;
        labels.push_back(this->m_label);
    }
    
    Window::~Window()
    {
        delete (this);
    }
    
    void Window::SetLabel(string label)
    {
        this->m_label = label;
    }
    
    string Window::GetLabel()
    {
        return this->m_label;
    }
    
    bool Window::IsRunning()
    {
        HWND hWnd = FindWindowA(NULL, (this->m_label).c_str());
        if (hWnd)
            return true;
        else
            return false;
    }
    
    HWND Window::GetWindow()
    {
        if (this->IsRunning())
        {
            HWND hWnd = FindWindowA(NULL, (this->m_label).c_str());
            return hWnd;
        }
        else
            return nullptr;
    }
    
    DWORD Window::GetWindowId()
    {
        if (this->GetWindow() != nullptr)
        {
            DWORD procId;
            GetWindowThreadProcessId(this->GetWindow(), &procId);
            return &procId;
        }
        else
            return NULL;
    }
    
    HANDLE Window::GetWindowHandle()
    {
        if (this->GetWindowId() != NULL) 
        {
            HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->GetWindowId());
            if (handle)
                return handle;
            else
                return nullptr;
        }
        else
            return nullptr;
    }
    
    template<typename T>
    T Window::WriteWindowMemory(DWORD addr, T newValue) decltype(newValue) ->
    {
        if (this->GetWindowHandle() != nullptr)
        {
            WriteProcessMemory(this->GetWindowHandle(), (LPCVOID)addr, newValue, sizeof(newValue), 0);
            return newValue;
        }
        else
            return NULL;
    }
} // namespace LitterBox

#endif // _WINDOW_HPP_
