select avg(rating) from ratings
JOIN movies ON movies.id = ratings.movie_id
where year = 2012;
