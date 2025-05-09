-- 코드를 작성해주세요
select f.id, 
        n.fish_name, 
        f.length 
    from fish_info as f
    join fish_name_info as n
        on f.fish_type = n.fish_type
    where (n.fish_name, f.length) in (
        select n2.fish_name, max(i2.length)
        from fish_info as i2
        join fish_name_info as n2
            on i2.fish_type = n2.fish_type 
        group by n2.fish_name
    )
    order by f.id;
    
    
