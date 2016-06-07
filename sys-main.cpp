
#include <iostream>
#include <DbInterface.h>

using namespace std;

int main(int argc, char *argv[])
{
    const char *db = getenv("CLINIC_DB");

    if (!db)
        db = "./default.db";

    DbInterface dbIf(db);
    return 0;
}
