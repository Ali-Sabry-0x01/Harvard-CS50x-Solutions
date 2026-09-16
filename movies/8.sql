-- 8. Names of people who starred in Toy Story
SELECT name FROM people
JOIN stars on people.id = stars.person_id
join movies on movies.id = stars.movie_id
WHERE movies.title = 'Toy Story';
