 -- create procedure
 DELIMITER //
 CREATE PROCEDURE GetAllProducts()
    BEGIN
    SELECT *  FROM products;
    END //
 DELIMITER ;
 
-- call precedure 	
CALL GetAllProducts();

-- 
DELIMITER //
CREATE PROCEDURE CountProducts()
    BEGIN
    DECLARE total_products INT DEFAULT 0
 
    SELECT COUNT(*) INTO total_products
    FROM products;
    RETURN total_products;
    END //
 DELIMITER ;