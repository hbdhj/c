SET GLOBAL event_scheduler = ON;

SHOW PROCESSLIST;

SET GLOBAL event_scheduler = OFF;

CREATE TABLE IF NOT EXISTS messages (
    id INT PRIMARY KEY AUTO_INCREMENT,
    message VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL
);

CREATE EVENT IF NOT EXISTS test_event_01
ON SCHEDULE AT CURRENT_TIMESTAMP
DO
  INSERT INTO messages(message,created_at)
  VALUES('Test MySQL Event 1',NOW());
  
SHOW EVENTS FROM classicmodels;

CREATE EVENT test_event_02
ON SCHEDULE AT CURRENT_TIMESTAMP + INTERVAL 1 MINUTE
ON COMPLETION PRESERVE
DO
   INSERT INTO messages(message,created_at)
   VALUES('Test MySQL Event 2',NOW());
   
SELECT * FROM messages;

SHOW EVENTS FROM classicmodels;