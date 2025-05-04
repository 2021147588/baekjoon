-- 코드를 작성해주세요

SELECT ID, EMAIL, FIRST_NAME, LAST_NAME FROM DEVELOPER_INFOS 
    WHERE SKILL_1 LIKE 'Python' OR SKILL_2 Like 'Python' or Skill_3 like 'Python'
    order by id;