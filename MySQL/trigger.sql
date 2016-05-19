-- create table
CREATE TABLE employees_audit (
    id INT AUTO_INCREMENT PRIMARY KEY,
    employeeNumber INT NOT NULL,
    lastname VARCHAR(50) NOT NULL,
    changedat DATETIME DEFAULT NULL,
    action VARCHAR(50) DEFAULT NULL
);

-- create trigger
DELIMITER $$
CREATE TRIGGER before_employee_update 
    BEFORE UPDATE ON employees
    FOR EACH ROW 
BEGIN
    INSERT INTO employees_audit
    SET action = 'update',
     employeeNumber = OLD.employeeNumber,
        lastname = OLD.lastname,
        changedat = NOW(); 
END$$
DELIMITER ;

-- change last name
UPDATE employees 
SET 
    lastName = 'Phan'
WHERE
    employeeNumber = 1056;

-- will see the 'changedat' updated too    
SELECT 
    *
FROM
    employees_audit;
    
-- list trigger
SELECT 
    *
FROM
    information_schema.triggers
WHERE
    trigger_schema = 'database_name'
        AND trigger_name = 'trigger_name';