/**********************************************************************************
* Wrapper class to sqlite database
**********************************************************************************/

#include "DbInterface.h"

#include <iostream>
#include <assert.h>

using namespace std;

DbInterface::DbInterface(const char *dbPath)
{
    int ret = sqlite3_open(dbPath, &_db);
    if (ret != SQLITE_OK)
    {
        cout << "Failed to open db; msg: " << sqlite3_errmsg(_db) << endl;
        assert(false);
    }
}

DbInterface::~DbInterface()
{
    int ret = sqlite3_close_v2(_db);
    if (ret != SQLITE_OK)
    {
        cout << "Unable to close db right now; code: " << ret << endl;
    }
}
