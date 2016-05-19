--  select mysql database
USE mysql;

-- change password via update
UPDATE user 
SET password = PASSWORD('Secret1970')
WHERE user = 'mysqltutorial' AND 
      host = 'mysqltutorial.org';

-- flush it
FLUSH PRIVILEGES;

-- encrypt password
SELECT PASSWORD('Secret1970') AS encrypt_password;

-- change password via set
SET PASSWORD FOR 'mysqltutorail'@'mysqltutorial.org' = PASSWORD('Secret1970');

-- change password via grant
GRANT USAGE ON *.* TO mysqltutorial@mysqltutorial.org IDENTIFIED BY Secret1970;