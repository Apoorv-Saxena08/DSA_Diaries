delete p from Person p
join Person p2 
on p.Email = p2.Email and p.Id > p2.Id;