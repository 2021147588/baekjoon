-- 코드를 작성해주세요
select id, email, first_name, last_name from developers
    where (skill_code & (select code from skillcodes where (name like 'C#') != 0))
           or (skill_code & (select code from skillcodes where (name like 'Python')!= 0))                   
    order by id;