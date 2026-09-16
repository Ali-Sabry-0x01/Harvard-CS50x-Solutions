-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
SELECT DISTINCT title FROM movies JOIN stars
ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = 'Jennifer Lawrence'
INTERSECT
SELECT DISTINCT title FROM movies JOIN stars
ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = 'Bradley Cooper';
