select distinct(name) from people, movies, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND year = 2004
ORDER BY birth;
