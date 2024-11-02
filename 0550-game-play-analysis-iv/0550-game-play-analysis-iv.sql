# Write your MySQL query statement below

select ROUND(count( DISTINCT player_id)/(select count(DISTINCT player_id) from Activity),2) as fraction
from Activity
where (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) in (
select player_id, min(event_date) as f
from Activity
group by player_id
)