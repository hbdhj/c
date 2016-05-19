-- Revoking Privileges is contrast to grant

SHOW GRANTS FOR 'rfc'@'localhost';
	
GRANT SELECT, UPDATE, DELETE ON 'classicmodels'.* TO 'rfc'@'localhost'

REVOKE UPDATE, DELETE ON classicmodels.*  FROM 'rfc'@'localhost';

REVOKE ALL PRIVILEGES, GRANT OPTION FROM 'rfc'@'localhost';

SHOW GRANTS FOR 'rfc'@'localhost';

-- USAGE privilege means no privileges in MySQL 
GRANT USAGE ON *.* TO 'rfc'@'localhost'
