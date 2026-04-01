#include <iostream>
#include <new>
using namespace std;

#include "CP_StudentSystem.h"

void CP_StudentSystem::mb_printMainMenu() const
{
    cout << "\n===== Student Management System =====" << endl;
    cout << " 1. Add students    (ID Score, end with ID=0)" << endl;
    cout << " 2. Delete by ID" << endl;
    cout << " 3. Delete all by score" << endl;
    cout << " 4. Show score by ID" << endl;
    cout << " 5. Show all IDs by score" << endl;
    cout << " 6. Show all students" << endl;
    cout << "-1. Exit" << endl;
    cout << "Please input your choice: ";
}

void CP_StudentSystem::mb_printAllStudent() const
{
    if (m_head == NULL || m_head->m_previous == NULL)
    {
        cout << "No student in the system." << endl;
        return;
    }

    cout << "--- All students (sorted by ID) ---" << endl;
    CP_ChainDoubleLink *p = m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "] ID=" << p->m_data.m_ID
             << "  Score=" << p->m_data.m_score << endl;
        p = p->m_next;
        n++;
    } while (p != m_head);
    cout << "Total: " << m_head->mb_getNodeCount()
         << " student(s)." << endl;
}

void CP_StudentSystem::mb_run()
{
    m_head = new(nothrow) CP_ChainDoubleLink;
    if (m_head == NULL)
    {
        cout << "Failed to initialize. Exiting." << endl;
        return;
    }

    int c           = 0;   
    int inputId     = 0;   
    int inputScore  = 0;   
    CP_Student s;
    CP_ChainDoubleLink *p = NULL;

    do
    {
        mb_printMainMenu();
        cin >> c;

        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter an integer." << endl;
            continue;
        }

        
        if (c != -1 && (c < 1 || c > 6))
        {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        switch (c)
        {
        
        case 1:
            cout << "Enter students (ID Score), end with ID=0:" << endl;
            do
            {
                cout << "  ID: ";
                cin >> s.m_ID;
                if (s.m_ID == 0) break;  

                if (s.m_ID < 0)
                {
                    cout << "  Invalid ID (must be positive). Try again." << endl;
                    continue;
                }

                cout << "  Score: ";
                cin >> s.m_score;
                if (s.m_score < 0)
                {
                    cout << "  Invalid score (must be >= 0). Try again." << endl;
                    continue;
                }

                
                if (m_head->mb_findNodeById(s.m_ID) != NULL)
                {
                    cout << "  ID " << s.m_ID
                         << " already exists. Skipped." << endl;
                    continue;
                }

                
                if (!m_head->mb_insertSorted(s))
                    cout << "  Memory allocation failed." << endl;
                else
                    cout << "  Added: ID=" << s.m_ID
                         << "  Score=" << s.m_score << endl;

            } while (s.m_ID != 0);

            mb_printAllStudent();
            break;

        
        case 2:
            cout << "Enter student ID to delete: ";
            cin >> inputId;
            if (inputId <= 0)
            {
                cout << "Invalid ID." << endl;
                break;
            }
            p = m_head->mb_findNodeById(inputId);
            if (p != NULL)
            {
                m_head->mb_deleteNode(p);
                cout << "Student ID=" << inputId
                     << " deleted." << endl;
            }
            else
            {
                cout << "Student ID=" << inputId
                     << " not found." << endl;
            }
            mb_printAllStudent();
            break;

        
        case 3:
            cout << "Enter score to delete: ";
            cin >> inputScore;
            if (inputScore < 0)
            {
                cout << "Invalid score." << endl;
                break;
            }
            {
                int before = (m_head->m_previous != NULL)
                             ? m_head->mb_getNodeCount() : 0;
                m_head->mb_deleteByScore(inputScore);
                int after  = (m_head->m_previous != NULL)
                             ? m_head->mb_getNodeCount() : 0;
                cout << (before - after) << " student(s) with score="
                     << inputScore << " deleted." << endl;
            }
            mb_printAllStudent();
            break;

        
        case 4:
            cout << "Enter student ID: ";
            cin >> inputId;
            if (inputId <= 0)
            {
                cout << "Invalid ID." << endl;
                break;
            }
            p = m_head->mb_findNodeById(inputId);
            if (p != NULL)
                cout << "ID=" << p->m_data.m_ID
                     << "  Score=" << p->m_data.m_score << endl;
            else
                cout << "Student ID=" << inputId << " not found." << endl;
            break;

        
        case 5:
            cout << "Enter score to query: ";
            cin >> inputScore;
            if (inputScore < 0)
            {
                cout << "Invalid score." << endl;
                break;
            }
            if (m_head->m_previous == NULL)
            {
                cout << "No student in the system." << endl;
                break;
            }
            {
                bool found = false;
                CP_ChainDoubleLink *q = m_head;
                cout << "Students with score=" << inputScore << ":" << endl;
                do
                {
                    if (q->m_data.m_score == inputScore)
                    {
                        cout << "  ID=" << q->m_data.m_ID << endl;
                        found = true;
                    }
                    q = q->m_next;
                } while (q != m_head);
                if (!found)
                    cout << "  None found." << endl;
            }
            break;

        
        case 6:
            mb_printAllStudent();
            break;

        
        case -1:
            cout << "Exiting the student system. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (c != -1);

    delete m_head;
    m_head = NULL;
}
