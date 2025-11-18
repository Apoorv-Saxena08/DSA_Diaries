CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare m int;
    set m = n-1;

  RETURN (
      # Write your MySQL query statement below.
      -- duplicate hta diye
        select distinct salary 
        from Employee
        -- descending m lgadi salary 
        order by salary desc 
        -- 1 choose kra and m skip kre
        limit 1 OFFSET m 
  );
END