WITH RepeatedPurchases AS (
    SELECT
        USER_ID,
        PRODUCT_ID,
        COUNT(*) AS PurchaseCount
    FROM
        ONLINE_SALE
    GROUP BY
        USER_ID,
        PRODUCT_ID
    HAVING
        COUNT(*) > 1
)

SELECT
    A.USER_ID,
    A.PRODUCT_ID
FROM
    ONLINE_SALE A
JOIN
    RepeatedPurchases B ON A.USER_ID = B.USER_ID AND A.PRODUCT_ID = B.PRODUCT_ID
ORDER BY
    A.USER_ID ASC,
    A.PRODUCT_ID DESC;