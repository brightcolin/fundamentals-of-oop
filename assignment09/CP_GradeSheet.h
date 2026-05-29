#ifndef CP_GRADESHEET_H
#define CP_GRADESHEET_H

#include <string>
#include <vector>
using namespace std;

struct CP_StudentRecord
{
    string m_id;
    int m_grade;
    CP_StudentRecord():m_grade(0){}
    CP_StudentRecord(const string &id,int grade):m_id(id),m_grade(grade){}
};

class CP_GradeSheet
{
private:
    vector<CP_StudentRecord> m_data;

public:
    CP_GradeSheet(){}
    ~CP_GradeSheet(){}

    bool mb_readFile(const char* filename);
    bool mb_add(const string &id,int grade)
    bool mb_remove(const string &id);
    void mb_clear();
    bool mb_modify(const string &id,int grade);
    bool mb_query(const string &id,int &grade) const;
    void mb_show() const;
    bool mb_writeFile(const char* filename) const;

    int mb_find(const string &id) const;
    int mb_size() const { return (int)m_data.size(); }
    string mb_getId(int index) const { return m_data[index].m_id; }
    int mb_getGrade(int index) const { return m_data[index].m_grade; }
};

#endif
