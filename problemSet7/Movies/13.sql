SELECT DISTINCT p.name
FROM stars s
JOIN people p ON s.person_id = p.id
WHERE s.movie_id IN (
    SELECT s2.movie_id
    FROM stars s2
    JOIN people p2 ON s2.person_id = p2.id
    WHERE p2.name = 'Kevin Bacon' AND p2.birth = 1958
)
AND p.name <> 'Kevin Bacon';
