#include <iostream>
using namespace std;

#include "CP_StudentSystem.h"

void CP_StudentSystem::mb_printMainMenu() const
{
    cout << "\n===== Student Management System (Factory Method) =====" << endl;
    cout << " 1. Add students       (ID Score, end with ID=0)" << endl;
    cout << " 2. Delete by ID       (first match)" << endl;
    cout << " 3. Delete by score    (all matches)" << endl;
    cout << " 4. Show score by ID   (first match)" << endl;
    cout << " 5. Show IDs by score  (all matches)" << endl;
    cout << " 6. Show all students" << endl;
    cout << "-1. Exit" << endl;
    cout << "Please input your choice: ";
}

void CP_StudentSystem::mb_printAllStudent() const
{
    if (m_product.mb_isEmpty())
    {
        cout << "No student in the system." << endl;
        return;
    }

    cout << "--- All students (sorted by ID) ---" << endl;
    CP_NodeDoubleLink *p = m_product.m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "] ID=" << p->m_data.m_ID
             << "  Score=" << p->m_data.m_score << endl;
        p = p->m_next;
        n++;
    } while (p != m_product.m_head);
    cout << "Total: " << (n - 1) << " student(s)." << endl;
}

void CP_StudentSystem::mb_run()
{
    int c = 0;
    int inputId    = 0;
    int inputScore = 0;
    CP_Student s;
    CP_NodeDoubleLink *p = NULL;

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

                if (m_product.mb_findNodeById(s.m_ID) != NULL)
                {
                    cout << "  ID " << s.m_ID
                         << " already exists. Skipped." << endl;
                    continue;
                }

                if (!m_product.mb_insertSorted(s, m_factory))
                    cout << "  Memory allocation failed." << endl;
                else
                    cout << "  Added: ID=" << s.m_ID
                         << "  Score=" << s.m_score
                         << "  (Factory spare=" << m_factory.mb_getSpareCount()
                         << ")" << endl;

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
            if (m_product.mb_deleteById(inputId, m_factory))
                cout << "Student ID=" << inputId << " deleted."
                     << "  (Factory spare=" << m_factory.mb_getSpareCount()
                     << ")" << endl;
            else
                cout << "Student ID=" << inputId << " not found." << endl;

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
                int removed = m_product.mb_deleteByScore(inputScore, m_factory);
                cout << removed << " student(s) with score="
                     << inputScore << " deleted."
                     << "  (Factory spare=" << m_factory.mb_getSpareCount()
                     << ")" << endl;
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
            p = m_product.mb_findNodeById(inputId);
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
            if (m_product.mb_isEmpty())
            {
                cout << "No student in the system." << endl;
                break;
            }
            {
                bool found = false;
                CP_NodeDoubleLink *q = m_product.m_head;
                cout << "Students with score=" << inputScore << ":" << endl;
                do
                {
                    if (q->m_data.m_score == inputScore)
                    {
                        cout << "  ID=" << q->m_data.m_ID << endl;
                        found = true;
                    }
                    q = q->m_next;
                } while (q != m_product.m_head);
                if (!found)
                    cout << "  None found." << endl;
            }
            break;

        case 6:
            mb_printAllStudent();
            cout << "Factory spare nodes: "
                 << m_factory.mb_getSpareCount() << endl;
            break;

        case -1:
            cout << "Exiting..." << endl;
            m_product.mb_deleteAll(m_factory);
            m_factory.mb_deleteAll();
            cout << "All memory released. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (c != -1);
}
