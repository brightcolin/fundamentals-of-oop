#ifndef CP_GRADESHEETSYSTEM_H
#define CP_GRADESHEETSYSTEM_H

#include "CP_GradeSheet.h"

class CP_GradeSheetSystem
{
private:
    CP_GradeSheet m_sheet;

public:
    CP_GradeSheetSystem(){}
    ~CP_GradeSheetSystem(){}
    void mb_run();
};

#endif
