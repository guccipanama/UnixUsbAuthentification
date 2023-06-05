#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <dirent.h>

using namespace std;
static char PathToInfo[] = "//sys//bus//usb//devices//";
static char PathToConection[] = "//sys//bus//usb//drivers//usb";

class usb_info {
public:
    char* Bus;
    char* Device;
    char* Id;
    char* Name;
    char* IdPath;
    char* Power;

    usb_info(const char* idPath)
    {
        IdPath = new char [strlen(idPath)];
        strcpy(IdPath,idPath);

        string temp(PathToInfo);
        temp += IdPath;
        //if(strcmp(temp.c_str(), get_current_dir_name()))
        if(chdir(temp.c_str())<0)
        {
            throw strerror(errno);
        }

        //Get the name(type) of usb-device
        int fdProduct = open("product", O_RDONLY);
        if(fdProduct<0)
        {
            throw strerror(errno);
        }
        Name = new char [20];
        read(fdProduct, Name, 20);
        close(fdProduct);

        //Get the id of usb port
        int fdId = open("idVendor", O_RDONLY);
        if(fdId<0)
        {
            throw strerror(errno);
        }
        Id = new char [20];
        read(fdId, Id, 20);
        close(fdId);

        //Get the id of usb devices
        int fdDevice = open("idProduct", O_RDONLY);
        if(fdDevice<0)
        {
            throw strerror(errno);
        }
        Device = new char [20];
        read(fdDevice, Device, 20);
        close(fdDevice);

        //Get the number of bus
        int fdBus = open("busnum", O_RDONLY);
        if(fdBus<0)
        {
            throw strerror(errno);
        }
        Bus = new char [20];
        read(fdBus, Bus, 20);
        close(fdBus);

        Power = new char [10];
        strcpy(Power, "Unlock");
        corrected_field();
    }

    void bind()
    {
        chdir(PathToConection);
        int fdPower = open("bind", O_WRONLY|O_TRUNC);
        if(fdPower<0)
        {
            throw strerror(errno);
        }
        write(fdPower, IdPath, sizeof(IdPath));

        delete Power;
        Power = new char [10];
        strcpy(Power, "Unlock");
    }
    void unbind()
    {
        chdir(PathToConection);
        int fdPower = open("unbind", O_WRONLY|O_TRUNC);
        if(fdPower<0)
        {
            throw strerror(errno);
        }
        write(fdPower, IdPath, sizeof(IdPath));

        delete Power;
        Power = new char [10];
        strcpy(Power, "Lock");
    }

private:
    void corrected_field()
    {
        bool flag = false;
        for (int i = 0; i < strlen(Name); i++)
        {
            if(Name[i] == '\n')
                flag = true;
            if(flag)
                Name[i] = 0;
            else
                continue;
        }
        flag = false;
        for (int i = 0; i < strlen(Id); i++)
        {
            if(Id[i] == '\n')
                flag = true;
            if(flag)
                Id[i] = 0;
            else
                continue;
        }
        flag = false;
        for (int i = 0; i < strlen(Device); i++)
        {
            if(Device[i] == '\n')
                flag = true;
            if(flag)
                Device[i] = 0;
            else
                continue;
        }
        flag = false;
        for (int i = 0; i < strlen(Bus); i++)
        {
            if(Bus[i] == '\n')
                flag = true;
            if(flag)
                Bus[i] = 0;
            else
                continue;
        }

    }
};