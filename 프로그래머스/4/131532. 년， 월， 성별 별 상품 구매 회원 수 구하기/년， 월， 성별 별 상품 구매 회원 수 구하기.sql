-- 코드를 입력하세요
SELECT year(o.sales_date) as year, month(o.sales_date) as month, u.gender as gender, count(distinct u.user_id) as users
    from user_info as u
    join online_sale as o
        on o.user_id = u.user_id
    where gender is not null
    group by year, month, gender
    order by year, month, gender;