/**********************************************************************************
* Wrapper class to sqlite database
**********************************************************************************/

#ifndef _DB_IF_H__
#define _DB_IF_H__

#include<sqlite3.h>

#define INVALID_DB_VERSION -1

class DbInterface
{
public:
    DbInterface(const char *dbPath);
    ~DbInterface();

    int getVersion();
    void setVersion(int version);

private:
    sqlite3 *_db;
    int _version;
};

#endif
