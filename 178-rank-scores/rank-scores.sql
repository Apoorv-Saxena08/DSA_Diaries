# Write your MySQL query statement below
# dense rank functionusecase -> ive rank to each row , used with OVER(condition) ,
#give consecutive rank values and give same rank to same values
# "rank" in quotes bcoz rank is a function
select score, dense_rank() over(order by score desc) as "rank" from Scores;