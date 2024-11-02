# Write your MySQL query statement below
select  r.contest_id, ROUND(((count(distinct r.user_id)*100))/(select count(u.user_id) from Users as u), 2) 
as percentage
from Register r
group by r.contest_id
order by percentage DESC , contest_id;