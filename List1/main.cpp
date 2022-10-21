#include <iostream>
#include "CTable.h"

using namespace std;

namespace {
    const int INIT_VALUE_34 = 34;
}

void v_alloc_table_fill_34(int iSize) {
    if (iSize > 0) {
        int *p_table_to_allocate = new int[iSize];

        for (int i = 0; i < iSize; i++) {
            *(p_table_to_allocate + i) = INIT_VALUE_34;
        }

        for (int i = 0; i < iSize; i++) {
            cout << " [" << p_table_to_allocate[i] << "] ";
        }

        delete[] p_table_to_allocate;

    } else {
        cout << "\nInvalid Size\n";
    }
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX > 0 && iSizeY > 0) {
        *piTable = new int *[iSizeX];
        for (int i = 0; i < iSizeX; i++) {
            (*piTable)[i] = new int[iSizeY];
        }
        return true;
    }
    return false;
}

bool b_alloc_table_2_dim_ref(int **&piTable, int iSizeX, int iSizeY) {
    if (iSizeX > 0 && iSizeY > 0) {
        piTable = new int *[iSizeX];
        for (int i = 0; i < iSizeX; i++) {
            piTable[i] = new int[iSizeY];
        }
        return true;
    }
    return false;
}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX) {
    if (iSizeX > 0) {
        for (int i = 0; i < iSizeX; i++) {
            delete[] piTable[i];
        }
        delete[] piTable;
        return true;
    }
    return false;
}

int main() {
    cout << "=============ZADANIE 1=============\n" << endl;
    v_alloc_table_fill_34(10);
    v_alloc_table_fill_34(0);
    v_alloc_table_fill_34(-5);

    cout << "\n=============ZADANIE 2-3=============\n" << endl;
    int **table = NULL;
    cout << "Alokowanie tablicy (argument &table) -> " << b_alloc_table_2_dim(&table, 5, 3) << endl;
    cout << "table adres -> " << table << endl;
    cout << "Dealokowanie tablicy -> " << b_dealloc_table_2_dim(table, 5) << endl;

    cout << "\n=============ZADANIE 4=============\n" << endl;

    CTable cTableDefault;
    cTableDefault.showTable();

    cout<< endl;

    CTable cTableParameter("Table_1", 5);
    cTableParameter.showTable();

    cout<< endl;

    CTable cTableCopy(cTableParameter);
    cTableCopy.showTable();

    cout<< endl;

    cTableParameter.vSetName("Table_1_new_name");
    cTableParameter.showTable();

    cout<< endl;

    cTableCopy.bSetNewSize(15);
    cTableCopy.showTable();

    cout<< endl;

    CTable *pc_new_tab;
    pc_new_tab = cTableParameter.pcClone();
    pc_new_tab->showTable();
    delete pc_new_tab;

    cout<< endl;

    CTable cTableMod("Table_mod", 3);
    v_mod_tab(&cTableMod, 7);
    cTableMod.showTable();

    cout << endl;

}
