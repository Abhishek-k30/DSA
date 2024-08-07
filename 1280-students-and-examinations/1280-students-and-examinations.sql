# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.subject_name) AS attended_exams
from Students s
CROSS Join Subjects sub
LEFT JOIN Examinations e
on s.student_id = e.student_id and sub.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id ,s.student_name;