# Write your MySQL query statement below
select * from Cinema 
where mod(Cinema.id,2)=1 and
Cinema.description != 'boring'
order by Cinema.rating DESC;