select title from movies, people, stars, people as p1, stars as s1
WHERE movies.id = stars.movie_id
AND movies.id = s1.movie_id
AND people.id = stars.person_id
AND p1.id = s1.person_id
AND people.name = 'Bradley Cooper'
AND p1.name = 'Jennifer Lawrence';
