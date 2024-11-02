# Write your MySQL query statement below
select ROUND (SUM(IF(order_date = customer_pref_delivery_date, 1, 0))*100/COUNT( DISTINCT customer_id), 2) as immediate_percentage
FROM Delivery
where(customer_id, order_date ) in
(select customer_id, MIN(order_date) as f
from Delivery
group by customer_id
 )