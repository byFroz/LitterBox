/*
 * Copyright (c) 2019 M.I.T. License
 *
 * This header file is responsible
 * for LitterBox's file operation
 * class and methods.
 *
 * Reliant on the <fstream> library,
 * some of the following code uses 
 * C-style file stream flag checks,
 * such as checking if a file pointer
 * operation is true or false.
 *
 * All of the actual file operations
 * (excluding determining if the file
 * is on the disk) are written using
 * C++.
 *
 * Author(s):
 * + Froz
*/

#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <fstream>

using string = std::string;

namespace LitterBox
{
    class File
    {
    public:
        File(string path) : m_path("C:\\"); // Sets the default "m_path" member to "C:\\", if @path param is unprovided.
        ~File();
        bool IsReal();
        uintptr_t CreateFile(string path);
        uintptr_t EditFile(char mode, string content); /* Has the ability to rename; however, if @mode == 'r', content becomes 
                                                        * (this->m_path)'s new path. */
        uintptr_t ReadFile(string path);
        uintptr_t DeleteFile(string path);
    private:
        std::vector<string> paths;
        string m_path;
    };
    
    File::File(string path) : m_path("C:\\")
    {
        this->m_path = path;
        paths.push_back(this->path);
    }
    
    File::~File()
    {
        delete (this);
    }
    
    bool File::IsReal()
    {
        std::ifstream file;
        if (file.open((this->m_path).c_str(), std::ios::read))
            return true;
        else
            return false;
    }
    
    uintptr_t File::CreateFile()
    {
        if (this->IsReal())
        {
            std::ofstream file;
            file.open((this->m_path).c_str(), std::ios::write);
            if (file.is_open())
                file.close();
            if (FILE *fp = fopen((this->m_path).c_str(), "r")
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
    
    uintptr_t File::EditFile(char mode, string content)
    {
        if (this->IsReal())
        {
            std::ofstream file;
            switch (mode)
            {
            case 'a':
                file.open((this->m_path).c_str(), std::ios::app);
                if (file.is_open())
                {
                    file.write(content.c_str(), sizeof(content));
                    file.close();
                    return 0;
                }
                else
                    return 1;
            case 'w':
                file.open((this->m_path).c_str(), std::ios::write);
                if (file.is_open())
                {
                    file.write(content.c_str(), sizeof(content));
                    file.close();
                    return 0;
                }
                else
                    return 1;
            case 'r':
                std::rename(file.c_str(), content.c_str());
                this->m_label = content; // The object is renaming its target file, therefore changing its own name.
                return 0;
            }
        }
        else
            return 1;
    }
    
    uintptr_t File::ReadFile()
    {
        if (this->IsReal())
        {
            std::ifstream file;
            string line;
            file.open(this->m_path);
            if (file.is_open())
            {
                while (getline(file, line)
                    std::cout << line;
                file.close();
                return 0;
            }
            else
                return 1;
        }
        return 1;
    }
    
    uintptr_t File::DeleteFile()
    {
        if (this->IsReal())
        {
            system(("del " + (this->m_label)).c_str());
            if (this->IsReal())
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
} // namespace LitterBox

#endif // _FILE_HPP_
