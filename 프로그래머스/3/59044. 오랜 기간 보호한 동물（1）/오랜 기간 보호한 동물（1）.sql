-- 코드를 입력하세요
SELECT i.name, i.datetime from animal_ins as i
    where i.animal_id not in (select animal_id from animal_outs)
    order by i.datetime
    limit 3;