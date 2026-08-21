-- Write your query below
select a.first_name, a.last_name, b.city, b.state 
from Person as a 
left join Address as b
on a.person_id = b.person_id;