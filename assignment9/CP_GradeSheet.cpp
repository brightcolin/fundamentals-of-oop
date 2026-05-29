#include <iostream>
#include <fstream>
using namespace std;
#include "CP_GradeSheet.h"

int CP_GradeSheet::mb_find(const string &id) const
{
    int n=(int)m_data.size();
    int i;
    for(i=0;i<n;i++)
    {
        if(m_data[i].m_id==id)
            return i;
    }
    return -1;
}

bool CP_GradeSheet::mb_readFile(const char* filename)
{
    ifstream fileObject(filename);
    if(fileObject.fail())
    {
        cout<<"Error: cannot open file: "<<filename<<endl;
        return false;
    }

    string id;
    int grade;
    int count=0;
    while(fileObject>>id>>grade)
    {
        
        if(mb_find(id)<0)
        {
            m_data.push_back(CP_StudentRecord(id,grade));
            count++;
        }
    }
    fileObject.close();

    if(count<=0)
    {
        cout<<"Warning: no valid records read from file: "<<filename<<endl;
        return false;
    }
    cout<<"Read "<<count<<" record(s) from file: "<<filename<<endl;
    return true;
}

bool CP_GradeSheet::mb_add(const string &id,int grade)
{
    if(id.empty())
    {
        cout<<"Error: student ID cannot be empty."<<endl;
        return false;
    }
    if(mb_find(id)>=0)
    {
        cout<<"Error: student ID \""<<id<<"\" already exists."<<endl;
        return false;
    }
    m_data.push_back(CP_StudentRecord(id,grade));
    return true;
}

bool CP_GradeSheet::mb_remove(const string &id)
{
    int idx=mb_find(id);
    if(idx<0)
    {
        cout<<"Error: student ID \""<<id<<"\" not found."<<endl;
        return false;
    }
    m_data.erase(m_data.begin()+idx);
    return true;
}

void CP_GradeSheet::mb_clear()
{
    m_data.clear();
}

bool CP_GradeSheet::mb_modify(const string &id,int grade)
{
    int idx=mb_find(id);
    if(idx<0)
    {
        cout<<"Error: student ID \""<<id<<"\" not found."<<endl;
        return false;
    }
    m_data[idx].m_grade=grade;
    return true;
}

bool CP_GradeSheet::mb_query(const string &id,int &grade) const
{
    int idx=mb_find(id);
    if(idx<0)
    {
        cout<<"Error: student ID \""<<id<<"\" not found."<<endl;
        return false;
    }
    grade=m_data[idx].m_grade;
    return true;
}

void CP_GradeSheet::mb_show() const
{
    int n=(int)m_data.size();
    if(n<=0)
    {
        cout<<"  (empty)"<<endl;
        return;
    }
    int i;
    cout<<"  ID\tGrade"<<endl;
    cout<<"  ----\t-----"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"  "<<m_data[i].m_id<<"\t"<<m_data[i].m_grade<<endl;
    }
    cout<<"  Total: "<<n<<" record(s)"<<endl;
}

bool CP_GradeSheet::mb_writeFile(const char* filename) const
{
    ofstream fileObject(filename);
    if(fileObject.fail())
    {
        cout<<"Error: cannot open file: "<<filename<<endl;
        return false;
    }

    int n=(int)m_data.size();
    int i;
    for(i=0;i<n;i++)
    {
        fileObject<<m_data[i].m_id<<" "<<m_data[i].m_grade<<endl;
    }
    fileObject.close();
    cout<<"Wrote "<<n<<" record(s) to file: "<<filename<<endl;
    return true;
}
