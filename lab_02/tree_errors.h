#ifndef __TREE_ERRORS_H__
#define __TREE_ERRORS_H__   

#include <exception>
#include <string>
#include <cstring>

class TreeError : public std::exception
{
public:
    TreeError(
            std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Error") noexcept
    {
        err_info = "\nFile name: " + filename +
                     "\nClass: " + classname +
                     "\nLine: " + std::to_string(line) +
                     "\nTime: " + time +
                     "Info: " + info;
    }

    virtual const char* what() const noexcept override
    {
        return err_info.c_str();
    }

    virtual ~TreeError() noexcept = default;

protected:
    std::string err_info;
};

#endif
