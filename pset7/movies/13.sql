SELECT people.name FROM people
WHERE people.id in (SELECT person_id FROM stars WHERE stars.movie_id IN
(SELECT stars.movie_id FROM stars WHERE stars.person_id IN
(SELECT id FROM people WHERE people.name='Kevin Bacon' AND birth=1958)))
AND people.name NOT IN ('Kevin Bacon');