SELECT people.name FROM people
WHERE people.id IN (SELECT DISTINCT stars.person_id FROM stars
WHERE stars.movie_id IN (SELECT DISTINCT movies.id FROM movies WHERE movies.year=2004))
ORDER BY people.birth;
