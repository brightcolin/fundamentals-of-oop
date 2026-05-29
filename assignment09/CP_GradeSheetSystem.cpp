#include <iostream>
using namespace std;
#include "CP_GradeSheetSystem.h"

void CP_GradeSheetSystem::mb_run()
{
    int cmd;
    char filename[200];
    char idBuf[100];
    int grade;
    string id;

    cout<<"========================================"<<endl;
    cout<<"   Student Grade Sheet System"<<endl;
    cout<<"========================================"<<endl;
    cout<<"  Command 1: Read from file"<<endl;
    cout<<"  Command 2: Add student"<<endl;
    cout<<"  Command 3: Delete student"<<endl;
    cout<<"  Command 4: Clear all"<<endl;
    cout<<"  Command 5: Modify grade"<<endl;
    cout<<"  Command 6: Query grade"<<endl;
    cout<<"  Command 7: Show all"<<endl;
    cout<<"  Command 8: Save to file"<<endl;
    cout<<"  Command -1: Exit"<<endl;
    cout<<"========================================"<<endl;

    while(true)
    {
        cout<<"\nEnter command: ";
        cin>>cmd;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Error: invalid command, please enter an integer."<<endl;
            continue;
        }

        if(cmd==-1)
        {
            cout<<"Goodbye!"<<endl;
            break;
        }

        switch(cmd)
        {
            case 1:
            {
                cout<<"Enter filename: ";
                cin>>filename;
                m_sheet.mb_readFile(filename);
                break;
            }
            case 2:
            {
                cout<<"Enter student ID: ";
                cin>>idBuf;
                id=idBuf;
                cout<<"Enter grade: ";
                cin>>grade;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout<<"Error: grade must be an integer."<<endl;
                    break;
                }
                if(m_sheet.mb_add(id,grade))
                    cout<<"Added: "<<id<<" "<<grade<<endl;
                break;
            }
            case 3:
            {
                cout<<"Enter student ID to delete: ";
                cin>>idBuf;
                id=idBuf;
                if(m_sheet.mb_remove(id))
                    cout<<"Deleted: "<<id<<endl;
                break;
            }
            case 4:
            {
                m_sheet.mb_clear();
                cout<<"All records cleared."<<endl;
                break;
            }
            case 5:
            {
                cout<<"Enter student ID: ";
                cin>>idBuf;
                id=idBuf;
                cout<<"Enter new grade: ";
                cin>>grade;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout<<"Error: grade must be an integer."<<endl;
                    break;
                }
                if(m_sheet.mb_modify(id,grade))
                    cout<<"Modified: "<<id<<" -> "<<grade<<endl;
                break;
            }
            case 6:
            {
                cout<<"Enter student ID: ";
                cin>>idBuf;
                id=idBuf;
                if(m_sheet.mb_query(id,grade))
                    cout<<"Grade of "<<id<<": "<<grade<<endl;
                break;
            }
            case 7:
            {
                m_sheet.mb_show();
                break;
            }
            case 8:
            {
                cout<<"Enter filename: ";
                cin>>filename;
                m_sheet.mb_writeFile(filename);
                break;
            }
            default:
            {
                cout<<"Error: unknown command "<<cmd
                    <<". Valid: 1-8 or -1."<<endl;
                break;
            }
        }
    }
}
