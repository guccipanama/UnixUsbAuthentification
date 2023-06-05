#include "usb_info.h"
#include <vector>

static char Path[] = "//sys//bus//usb//devices";

using namespace std;
class List_usb{
public:
    vector<usb_info> VectorUsb;
    size_t size;

    List_usb()
    {
        size = 0;
    }
    void update()
    {
        VectorUsb.clear();
        size = 0;
        vector<string> tempVector;
        chdir(Path);
        DIR *dir;
        dir = opendir(Path);
        if(dir == nullptr)
            throw strerror(errno);
        struct dirent* f_cur;
        while((f_cur= readdir(dir))!=nullptr)
        {
            if(isdigit(f_cur->d_name[0]) & !f_cur->d_name[3]) {
                tempVector.push_back(f_cur->d_name);
                size++;
            }
        }
        closedir(dir);
        for(size_t i = 0; i < size; i++)
        {
            VectorUsb.push_back(usb_info(tempVector[i].c_str()));
        }
    }
    void lock_all()
    {
        update();
        for(size_t i = 0; i < size; i++)
            VectorUsb[i].unbind();
    }
    void unlock_all()
    {
        update();
        for(size_t i = 0; i < size; i++)
            VectorUsb[i].bind();
    }
    void lock(const char* id)
    {
        update();
        for(size_t i = 0; i < size; i++)
            if (!strcmp(id, VectorUsb[i].Name))
                VectorUsb[i].unbind();
    }
    void unlock(const char* id)
    {
        update();
        for(size_t i = 0; i < size; i++)
            if (!strcmp(id, VectorUsb[i].Name))
                VectorUsb[i].bind();
    }
};