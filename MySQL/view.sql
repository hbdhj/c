--  create view 
CREATE VIEW SalePerOrder AS
    SELECT 
        orderNumber, SUM(quantityOrdered * priceEach) total
    FROM
        orderDetails
    GROUP by orderNumber
    ORDER BY total DESC;

-- list view in tables
SHOW TABLES;

-- list view
SELECT 
    *
FROM
    salePerOrder;

-- 
CREATE VIEW BigSalesOrder AS
    SELECT 
        orderNumber, ROUND(total,2) as total
    FROM
        saleperorder
    WHERE
        total > 60000;
        
CREATE VIEW customerOrders AS
    SELECT 
        d.orderNumber,
        customerName,
        SUM(quantityOrdered * priceEach) total
    FROM
        orderDetails d
            INNER JOIN
        orders o ON o.orderNumber = d.orderNumber
            INNER JOIN
        customers c ON c.customerNumber = c.customerNumber
    GROUP BY d.orderNumber
    ORDER BY total DESC;
    
CREATE OR REPLACE VIEW vps AS
    SELECT 
        employeeNumber,
        lastname,
        firstname,
        jobtitle,
        extension,
        email,
        officeCode,
        reportsTo
    FROM
        employees
    WHERE
        jobTitle LIKE '%VP%';

INSERT INTO vps(employeeNumber,firstname,lastname,jobtitle,extension,email,officeCode,reportsTo)
values(1703,'Lily','Bush','IT Manager','x9111','lilybush@classicmodelcars.com',1,1002);

CREATE OR REPLACE VIEW vps AS
    SELECT 
        employeeNumber,
        lastname,
        firstname,
        jobtitle,
        extension,
        email,
        officeCode,
        reportsTo
    FROM
        employees
    WHERE
        jobTitle LIKE '%VP%' 
WITH CHECK OPTION;

-- will report error "CHECK OPTION failed 'classicmodels.vps'"
INSERT INTO vps(employeeNumber,firstname,lastname,jobtitle,extension,email,officeCode,reportsTo)
VALUES(1704,'John','Smith','IT Staff','x9112','johnsmith@classicmodelcars.com',1,1703);
