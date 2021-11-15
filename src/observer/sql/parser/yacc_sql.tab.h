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
    ANULL = 260,                   /* ANULL  */
    NULLABLE = 261,                /* NULLABLE  */
    NOTNULL = 262,                 /* NOTNULL  */
    CREATE = 263,                  /* CREATE  */
    DROP = 264,                    /* DROP  */
    TABLE = 265,                   /* TABLE  */
    TABLES = 266,                  /* TABLES  */
    INDEX = 267,                   /* INDEX  */
    UNIQUE = 268,                  /* UNIQUE  */
    SELECT = 269,                  /* SELECT  */
    MAX = 270,                     /* MAX  */
    MIN = 271,                     /* MIN  */
    COUNT = 272,                   /* COUNT  */
    AVG = 273,                     /* AVG  */
    DESC = 274,                    /* DESC  */
    ASC = 275,                     /* ASC  */
    ORDERBY = 276,                 /* ORDERBY  */
    SHOW = 277,                    /* SHOW  */
    SYNC = 278,                    /* SYNC  */
    INSERT = 279,                  /* INSERT  */
    DELETE = 280,                  /* DELETE  */
    UPDATE = 281,                  /* UPDATE  */
    LBRACE = 282,                  /* LBRACE  */
    RBRACE = 283,                  /* RBRACE  */
    COMMA = 284,                   /* COMMA  */
    TRX_BEGIN = 285,               /* TRX_BEGIN  */
    TRX_COMMIT = 286,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 287,            /* TRX_ROLLBACK  */
    INT_T = 288,                   /* INT_T  */
    STRING_T = 289,                /* STRING_T  */
    FLOAT_T = 290,                 /* FLOAT_T  */
    DATE_T = 291,                  /* DATE_T  */
    HELP = 292,                    /* HELP  */
    EXIT = 293,                    /* EXIT  */
    DOT = 294,                     /* DOT  */
    INTO = 295,                    /* INTO  */
    VALUES = 296,                  /* VALUES  */
    FROM = 297,                    /* FROM  */
    WHERE = 298,                   /* WHERE  */
    AND = 299,                     /* AND  */
    SET = 300,                     /* SET  */
    ON = 301,                      /* ON  */
    LOAD = 302,                    /* LOAD  */
    DATA = 303,                    /* DATA  */
    INFILE = 304,                  /* INFILE  */
    EQ = 305,                      /* EQ  */
    LT = 306,                      /* LT  */
    GT = 307,                      /* GT  */
    LE = 308,                      /* LE  */
    GE = 309,                      /* GE  */
    NE = 310,                      /* NE  */
    NUMBER = 311,                  /* NUMBER  */
    FLOAT = 312,                   /* FLOAT  */
    DATE = 313,                    /* DATE  */
    ID = 314,                      /* ID  */
    PATH = 315,                    /* PATH  */
    SSS = 316,                     /* SSS  */
    STAR = 317,                    /* STAR  */
    STRING_V = 318,                /* STRING_V  */
    AGGOP = 319                    /* AGGOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 124 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 138 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *scanner);


#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
