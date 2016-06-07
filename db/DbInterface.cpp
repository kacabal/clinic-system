/**********************************************************************************
* Wrapper class to sqlite database
**********************************************************************************/

#include "DbInterface.h"

#include <iostream>
#include <sstream>
#include <mutex>
#include <string.h>
#include <assert.h>

using namespace std;

mutex _versionMutex;

DbInterface::DbInterface(const char *dbPath):
    _db(0),
    _version(INVALID_DB_VERSION)
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

static int _getVersionCallback(void *ret, int resultCount, char **val, char **column)
{
    assert(resultCount == 1); // there can only be one user_version

    string valStr(val[0]), columnStr(column[0]);
    assert(!valStr.empty());
    assert(!columnStr.empty());

    int *version = static_cast<int*>(ret);
    *version = stoi(valStr);
    return SQLITE_OK;
}

int DbInterface::getVersion()
{
    if (_version != INVALID_DB_VERSION) return _version;

    const char *stmt = "pragma user_version";
    char *err = 0;

    _versionMutex.lock();
    int ret = sqlite3_exec(_db, stmt, _getVersionCallback, &_version, &err);
    _versionMutex.unlock();

    if (ret != SQLITE_OK)
    {
        // this shouldn't happen
        cout << "Failed to get user version; msg: " << sqlite3_errmsg(_db) << endl;
        sqlite3_free(err);
        err = 0;
        _version = INVALID_DB_VERSION;
    }

    return _version;
}

void DbInterface::setVersion(int version)
{
    stringstream stmt;
    stmt << "pragma user_version=" << version;
    char *err = 0;

    _versionMutex.lock();
    int ret = sqlite3_exec(_db, stmt.str().c_str(), 0, 0, &err);
    _versionMutex.unlock();

    if (ret != SQLITE_OK)
    {
        // this shouldn't happen
        cout << "Failed to set user version; msg: " << sqlite3_errmsg(_db) << endl;
        sqlite3_free(err);
        err = 0;
        assert(false);
    }

    _version = version;
}
