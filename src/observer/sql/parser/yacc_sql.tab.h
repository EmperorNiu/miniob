/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    IS = 259,                      /* IS  */
    ISNOT = 260,                   /* ISNOT  */
    ANULL = 261,                   /* ANULL  */
    NULLABLE = 262,                /* NULLABLE  */
    NOTNULL = 263,                 /* NOTNULL  */
    CREATE = 264,                  /* CREATE  */
    DROP = 265,                    /* DROP  */
    TABLE = 266,                   /* TABLE  */
    TABLES = 267,                  /* TABLES  */
    INDEX = 268,                   /* INDEX  */
    UNIQUE = 269,                  /* UNIQUE  */
    SELECT = 270,                  /* SELECT  */
    MAX = 271,                     /* MAX  */
    MIN = 272,                     /* MIN  */
    COUNT = 273,                   /* COUNT  */
    AVG = 274,                     /* AVG  */
    DESC = 275,                    /* DESC  */
    ASC = 276,                     /* ASC  */
    ORDERBY = 277,                 /* ORDERBY  */
    SHOW = 278,                    /* SHOW  */
    SYNC = 279,                    /* SYNC  */
    INSERT = 280,                  /* INSERT  */
    DELETE = 281,                  /* DELETE  */
    UPDATE = 282,                  /* UPDATE  */
    LBRACE = 283,                  /* LBRACE  */
    RBRACE = 284,                  /* RBRACE  */
    COMMA = 285,                   /* COMMA  */
    TRX_BEGIN = 286,               /* TRX_BEGIN  */
    TRX_COMMIT = 287,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 288,            /* TRX_ROLLBACK  */
    INT_T = 289,                   /* INT_T  */
    STRING_T = 290,                /* STRING_T  */
    FLOAT_T = 291,                 /* FLOAT_T  */
    DATE_T = 292,                  /* DATE_T  */
    HELP = 293,                    /* HELP  */
    EXIT = 294,                    /* EXIT  */
    DOT = 295,                     /* DOT  */
    INTO = 296,                    /* INTO  */
    VALUES = 297,                  /* VALUES  */
    FROM = 298,                    /* FROM  */
    WHERE = 299,                   /* WHERE  */
    AND = 300,                     /* AND  */
    SET = 301,                     /* SET  */
    ON = 302,                      /* ON  */
    LOAD = 303,                    /* LOAD  */
    DATA = 304,                    /* DATA  */
    INFILE = 305,                  /* INFILE  */
    EQ = 306,                      /* EQ  */
    LT = 307,                      /* LT  */
    GT = 308,                      /* GT  */
    LE = 309,                      /* LE  */
    GE = 310,                      /* GE  */
    NE = 311,                      /* NE  */
    NUMBER = 312,                  /* NUMBER  */
    FLOAT = 313,                   /* FLOAT  */
    DATE = 314,                    /* DATE  */
    ID = 315,                      /* ID  */
    PATH = 316,                    /* PATH  */
    SSS = 317,                     /* SSS  */
    STAR = 318,                    /* STAR  */
    STRING_V = 319,                /* STRING_V  */
    AGGOP = 320                    /* AGGOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 125 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 139 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *scanner);


#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
