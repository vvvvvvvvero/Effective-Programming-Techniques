
#include "CTable.h"
#include "iostream"
#include <string>

using namespace std;

const string CTable::DEFAULT_NAME = "DEFAULT";
const int CTable::DEFAULT_SIZE = 10;

CTable::CTable() : s_name(DEFAULT_NAME), i_table_len(DEFAULT_SIZE) {
    cout << "bezp: " << s_name << endl;

    i_table = new int[i_table_len];
}

CTable::CTable(string sName, int iTableLen) : s_name(sName) , i_table_len(iTableLen) {
    cout << "parametr: " << s_name << endl;

    i_table = new int[i_table_len];
}

CTable::CTable(const CTable &pcOther) : s_name(pcOther.s_name) , i_table_len(pcOther.i_table_len) {
    s_name += "_copy";

    i_table = new int[i_table_len];
    for (int i = 0; i < i_table_len; i++) {
        this->i_table[i] = pcOther.i_table[i];
    }

    cout << "kopiuj: " << s_name << endl;
}

CTable::~CTable() {
    cout << "usuwam: " << s_name << endl;
    delete [] i_table;
}

void CTable::vSetName(string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen <= 0) {
        return false;
    }

    int *i_new_table = new int[iTableLen];
    int i_min = min(iTableLen, i_table_len);
    for (int i = 0; i < i_min; i++) {
        i_new_table[i] = i_table[i];
    }

    delete[] i_table;

    i_table = i_new_table;
    i_table_len = iTableLen;

    return true;
}

CTable *CTable::pcClone() {
    CTable *tableClone;
    tableClone = new CTable(*this);
    return tableClone;
}

void CTable::showTable() {
    cout << "name: " << s_name << "  length: " << i_table_len << endl;
}

void v_mod_tab(CTable *pcTab, int iNewSize)
{
    pcTab->bSetNewSize(iNewSize);
}
void v_mod_tab(CTable cTab, int iNewSize)
{
    cTab.bSetNewSize(iNewSize);
}


