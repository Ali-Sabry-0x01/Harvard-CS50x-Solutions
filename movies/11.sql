-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT DISTINCT title FROM movies JOIN ratings
ON movies.id = ratings.movie_id
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = 'Chadwick Boseman'
ORDER By rating DESC
LIMIT 5;
