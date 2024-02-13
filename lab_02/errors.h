#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <string>
#include <ctime>

#include "tree_errors.h"

class ObjNotExist: public TreeError
{
public:
    ObjNotExist(
            std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Work with deleted object!\n") noexcept :
            TreeError(filename, classname, line, time, info) {};
};

class ElemAlreadyExist: public TreeError
{
public:
    ElemAlreadyExist(
            std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "The item is already in tree!\n") noexcept :
            TreeError(filename, classname, line, time, info) {};
};

class DelElemNotFound: public TreeError
{
public:
    DelElemNotFound(
            std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "The item being deleted was not found!\n") noexcept :
            TreeError(filename, classname, line, time, info) {};
};

#endif
