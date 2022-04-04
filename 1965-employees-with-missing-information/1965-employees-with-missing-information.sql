# Write your MySQL query statement below

SELECT sub.employee_id from
(
select emp.employee_id from Employees emp,Salaries sal where emp.employee_id NOT IN (select emp.employee_id from Employees emp,Salaries sal where emp.employee_id = sal.employee_id) AND sal.employee_id NOT IN (select emp.employee_id from Employees emp,Salaries sal where emp.employee_id = sal.employee_id)
UNION
select sal.employee_id from Employees emp,Salaries sal where emp.employee_id NOT IN (select emp.employee_id from Employees emp,Salaries sal where emp.employee_id = sal.employee_id) AND sal.employee_id NOT IN (select emp.employee_id from Employees emp,Salaries sal where emp.employee_id = sal.employee_id)
) AS sub order by sub.employee_id
