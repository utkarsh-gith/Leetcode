-- Write your MySQL query statement below
SELECT w2.id
FROM Weather as w1
INNER JOIN Weather as w2
ON DATE_ADD(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate
WHERE w1.temperature < w2.temperature;