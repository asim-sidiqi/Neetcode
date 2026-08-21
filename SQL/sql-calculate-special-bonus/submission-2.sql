-- Write your query below
select employee_id, 
    case 
        when employee_id%2 <> 0 AND NAME not like 'M%' 
            then salary
        else 0
    end as bonus
from employees 
order by employee_id;
