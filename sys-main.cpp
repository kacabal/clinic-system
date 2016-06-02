
#include <iostream>
#include <DbInterface.h>

using namespace std;

int main()
{
    const char *db = getenv("CLINIC_DB");

    if (!db)
        db = "./tmp.db";

    cout << "Usin db: " << db << endl;
    DbInterface dbIf(db);
    return 0;
}
