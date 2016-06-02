/**********************************************************************************
* Wrapper class to sqlite database
**********************************************************************************/

#ifndef _DB_IF_H__
#define _DB_IF_H__

#include<sqlite3.h>

class DbInterface
{
public:
    DbInterface(const char *dbPath);

private:
    sqlite3 *_db;
};

#endif
