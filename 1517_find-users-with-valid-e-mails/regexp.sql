SELECT *
  FROM users
 WHERE mail REGEXP '^[a-z][a-z0-9\_\.\-]*@leetcode.com$'
/* REGEXP is not case sensitive, except for binary strings. */
