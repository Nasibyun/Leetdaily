select e.name as Employee from Employee e join Employee m on e.managerId = m.Id and e.salary > m.salary;
