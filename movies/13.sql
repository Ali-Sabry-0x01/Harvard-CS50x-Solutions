-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred
SELECT DISTINCT name FROM people JOIN stars
ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN (
SELECT DISTINCT movies.id FROM movies JOIN stars
ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = 'Kevin Bacon' AND birth = 1958
)
AND people.id != (
    SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958
);
