select name from movies, ratings, directors, people
WHERE movies.id = directors.movie_id
AND movies.id = ratings.movie_id
AND people.id = directors.person_id
AND rating >= 9.0;
