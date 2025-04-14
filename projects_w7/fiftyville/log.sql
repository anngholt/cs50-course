-- Keep a log of any SQL queries you execute as you solve the mystery.


SELECT activity, license_plate
 FROM bakery_security_logs
 WHERE year = 2024 AND month = 7 AND day = 28
  AND hour = 10;


SELECT name, license_plate
FROM people
WHERE license_plate IN (
  'R3G7486', '13FNH73', 'NRYN856', 'WD5M8I6', 'V47T75I',
  '5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7',
  'L93JTIZ', '322W7JE', '0NTHK55', '1106N58'
);

sqlite> SELECT name, transcript FROM interviews WHERE year = 2024 AND month = 7 AND day = 28;
RESULT: 


--Two people with name Eugene!

SELECT name
  FROM people
 WHERE name = 'Eugene';

--only one in database!

SELECT name, transcript  FROM interviews WHERE year = 2024   AND month = 7   AND day = 28   AND transcript LIKE '%bakery%' ORDER BY name;


SELECT people.name, people.license_plate, atm_transactions.account_number
 FROM atm_transactions
 JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
 JOIN people ON bank_accounts.person_id = people.id
 WHERE atm_transactions.year = 2024
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_transactions.atm_location = 'Leggett Street';



--5 potensial suspects!


-- Let's check who made a phone call!
SELECT caller, receiver
FROM phone_calls
WHERE year = 2024 AND month = 7 AND day = 28
  AND duration < 60;


SELECT name, phone_number
FROM people
WHERE phone_number IN (
  '(130) 555-0289', '(499) 555-9472', '(367) 555-5533',
  '(286) 555-6063', '(770) 555-1861', '(031) 555-6622',
  '(826) 555-1652', '(338) 555-6650'
);






-- Top 3 Final Suspects: Bruce	Diana Taylor	


SELECT id, origin_airport_id, destination_airport_id, hour, minute
FROM flights
WHERE year = 2024 AND month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 1;


--which airport is it?
sqlite> SELECT full_name FROM airports WHERE id = 4
   ...> ;
--LaGuardia Airport --- New York.

SELECT p.name, p.phone_number, p.passport_number, p.license_plate
FROM passengers AS ps
JOIN people AS p ON ps.passport_number = p.passport_number
WHERE ps.flight_id = 36;



--TWO SUSPECTS: Bruce and Taylor boarded the flight.

--Let's check who they called:
SELECT name, phone_number
FROM people
WHERE phone_number IN (
  '(676) 555-6554', '(375) 555-8161'
);


-- Ruth said: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. 
--Let's check it!

SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2024
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute >= 15
   AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;


--Bruce is the thief! Robin is an accomplice!

