
#ifndef TEP_LIST1_CTABLE_H
#define TEP_LIST1_CTABLE_H

#include <string>
using namespace std;

class CTable {
public:
    static const string DEFAULT_NAME;
    static const int DEFAULT_SIZE;

    CTable();
    CTable(string sName, int iTableLen);
    CTable(const CTable &pcOther);
    ~CTable();

    void vSetName(string sName);
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();

    void showTable();

private:

    string s_name;
    int i_table_len;
    int *i_table;

};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);


#endif //TEP_LIST1_CTABLE_H
