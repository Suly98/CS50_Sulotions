-- Keep a log of any SQL queries you execute as you solve the mystery.

.schema

select * from interviews where month = 7 and day = 28;

select * from bakery_security_logs where month = 7 and day = 28;

select * from crime_scene_reports where day = 28 and month = 7 and street = 'Humphrey Street';

select * from bakery_security_logs where month = 7 and day = 28;

select * from atm_transactions where month = 7 and day = 28 and atm_location = 'Leggett Street';

select * from people where passport_number in
(select passport_number FROM passengers WHERE flight_id = 36);

select * from people where passport_number in
(select passport_number FROM passengers WHERE flight_id = 23);

select * from phone_calls where month = 7 and day = 28 and duration < 60;


select * from flights where month = 7 and day = 29 and origin_airport_id = 8;

select * from passengers where flight_id = 23;

select * from passengers where flight_id = 36;

select * from bank_accounts where person_id = 686048;

select passport_number FROM passengers WHERE flight_id = 36;

select * from flights where id = 36;

select * from airports where id =4;

select * from people where phone_number = '(375) 555-8161';
