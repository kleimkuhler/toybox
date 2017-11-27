#include <vector>
#include "extract_fails.h"
#include "grade.h"
#include "Student_info.h"

using std::vector;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}

// v1: separate passing and failing student records
vector<Student_info> extract_fails_v1(vector<Student_info>& students)
{
  vector<Student_info> pass, fail;

  for (vector<Student_info>::size_type i = 0;
       i != students.size(); ++i)
    if (fgrade(students[i]))
      fail.push_back(students[i]);
    else
      pass.push_back(students[i]);

  students = pass;
  return fail;
}

// v2
vector<Student_info> extract_fails_v2(vector<Student_info>& students)
{
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;

  while (i != students.size()) {
    if (fgrade(students[i])) {
      fail.push_back(students[i]);
      students.erase(students.begin() + i);
    } else
      ++i;
  }
  return fail;
}
