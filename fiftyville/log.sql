-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

SELECT name, transcript FROM interviews
WHERE month = 7 AND day = 28 AND transcript LIKE '%bakery%';

SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit';

SELECT account_number FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

SELECT caller, receiver FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60;

SELECT name FROM people
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit'
)
AND phone_number IN (
    SELECT caller FROM phone_calls
    WHERE month = 7 AND day = 28 AND duration < 60
)
AND id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
    )
);

SELECT flights.id, destination.city, flights.hour, flights.minute
FROM flights
JOIN airports origin ON flights.origin_airport_id = origin.id
JOIN airports destination ON flights.destination_airport_id = destination.id
WHERE origin.city = 'Fiftyville' AND flights.month = 7 AND flights.day = 29
ORDER BY flights.hour, flights.minute
LIMIT 1;

SELECT name FROM people
WHERE passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id = 36
);

SELECT name FROM people
WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE month = 7 AND day = 28 AND duration < 60
    AND caller = (SELECT phone_number FROM people WHERE name = 'Bruce')
);
