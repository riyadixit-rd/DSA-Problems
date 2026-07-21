(
SELECT u.name AS results
FROM Users u
JOIN MovieRating mr
ON u.user_id = mr.user_id
GROUP BY u.user_id, u.name
ORDER BY COUNT(*) DESC, u.name
LIMIT 1
)

UNION ALL

(
SELECT m.title AS results
FROM Movies m
JOIN MovieRating mr
ON m.movie_id = mr.movie_id
WHERE YEAR(created_at) = 2020
  AND MONTH(created_at) = 2
GROUP BY m.movie_id, m.title
ORDER BY AVG(rating) DESC, m.title
LIMIT 1
);