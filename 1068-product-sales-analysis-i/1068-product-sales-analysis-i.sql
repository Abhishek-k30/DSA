# Write your MySQL query statement below
select pro.product_name, sl.year, sl.price 
from Sales as sl 
left join 
Product as pro on
sl.product_id = pro.product_id;