#ifndef MOD_INFO_H
#define MOD_INFO_H

#endif // MOD_INFO_H

#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>
#include <cstring>
#include <crypt.h>

#include <QMessageBox>

passwd* mod_info()
{
    struct passwd *p;

    uid_t uid = getuid();
    std::cout << "UID: " << uid << std::endl;

    if (geteuid() == 0) {
        std::cout << "Running as root!\n";
    } else {
        std::cout << "Not running as root.\n";
    }

    p = getpwuid(uid);
    std::cout << "Username: " << p->pw_name << std::endl;

    return p;
}

bool unlock_access(struct passwd *p, std::string user_pass)
{
    struct spwd password, root_user;
    root_user = *getspnam("root");
    password = *getspnam(p->pw_name); // user
    std::string root_password = root_user.sp_pwdp;

    if(user_pass == root_password)
    {
        /*
        std::cout << "Access granted!" << std::endl << std::endl;
        std::cout << "Root_pass = " << root_password << std::endl << std::endl;
        std::cout << "CRIPTED PASSWD: " << crypt(user_pass.c_str(),password.sp_pwdp) << std::endl;
        std::cout << strcmp(root_password.c_str(), crypt(user_pass.c_str(),password.sp_pwdp)) << std::endl;
        */
        return true;

    }
    else
    {
        /*
        std::cout << "Access denied.." << std::endl;
        std::cout << "Password: " << p->pw_passwd << " : " << password.sp_pwdp << std::endl;
        */
        return false;
    }


}


/*
int main() {
    struct passwd *p = mod_info();
    if(p->pw_uid == 0)
    {
        while(true)
        {
            unlock_access(p); //start application
        }
    }else
    {
        return -1; // permission denied
    }


}*/
