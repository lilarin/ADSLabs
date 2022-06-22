#include "HashTable_Separate_Chaining.h"
//#include "HashTable_Linear_Probing.h"
#include "ctime"
#include "cmath"
#include <unordered_map>

using namespace std;


unsigned long long generateRandLong()
{
    unsigned long long result = 0;
    int iters = rand() % 3 + 12;
    for (int i = 0; i < iters ; i++) {
        result += (rand() % 10) * pow(10, i);
    }
    result += ((rand() % 9 + 1) * pow(10, iters));
    return result;
}

bool testHashTable()
{
    const int iters = 500000;
    const int keysAmount = iters * 1;

    // generate random keys:
    auto* keys = new unsigned long long[keysAmount];

    auto* keysToInsert = new unsigned long long[iters];
    auto* keysToErase = new unsigned long long[iters];
    auto* keysToFind = new unsigned long long[iters];

    for (int i = 0; i < keysAmount; i++)
    {
        keys[i] = generateRandLong();
    }
    for (int i = 0; i < iters; i++)
    {
        keysToInsert[i] = keys[generateRandLong() % keysAmount];
        keysToErase[i] = keys[generateRandLong() % keysAmount];
        keysToFind[i] = keys[generateRandLong() % keysAmount];
    }

    // test my HashTable:


    // ---------------------------------------------------------------------
    // if user wants to use default HashTable, then he should use next code:

    HashTable_Separate_Chaining hashTable;

    // else

//    HashTable_Linear_Probing hashTable;

    // ---------------------------------------------------------------------


    clock_t myStart = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.insert(keysToInsert[i], Data());
    }
    int myInsertSize = hashTable.size();
    for (int i = 0; i < iters; i++)
    {
        hashTable.erase(keysToErase[i]);
    }
    int myEraseSize = hashTable.size();
    int myFoundAmount = 0;

    for (int i = 0; i < iters; i++) {
        if (hashTable.find(keysToFind[i])) {
            myFoundAmount++;
        }
    }

    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    // test STL hash table:
    unordered_map<long long, Data> unorderedMap;

    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.insert({keysToInsert[i], Data()});
    }
    size_t stlInsertSize = unorderedMap.size();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.erase(keysToErase[i]);
    }
    size_t stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
        {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ", found amount: " << myFoundAmount << endl;
    cout << "STL unordered_map:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize << ", found amount: " << stlFoundAmount << endl << endl;

    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;

    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount)
    {
        cout << "The lab is completed" << endl;
        return true;
    }

    cerr << ":(" << endl;
    return false;
}

int main() {
    srand(time(nullptr));
    testHashTable();
    return 0;
}

