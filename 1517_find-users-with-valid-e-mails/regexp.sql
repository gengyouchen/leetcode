SELECT *
  FROM users
 WHERE mail REGEXP '^[a-z][a-z0-9\_\.\-]*@leetcode.com$'
