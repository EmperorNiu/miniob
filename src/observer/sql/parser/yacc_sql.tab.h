/* A Bison parser, made by GNU Bison 3.7.6.  */

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
    TEXT_T = 260,                  /* TEXT_T  */
    ISNOT = 261,                   /* ISNOT  */
    ANULL = 262,                   /* ANULL  */
    NULLABLE = 263,                /* NULLABLE  */
    NOTNULL = 264,                 /* NOTNULL  */
    CREATE = 265,                  /* CREATE  */
    DROP = 266,                    /* DROP  */
    TABLE = 267,                   /* TABLE  */
    TABLES = 268,                  /* TABLES  */
    INDEX = 269,                   /* INDEX  */
    UNIQUE = 270,                  /* UNIQUE  */
    SELECT = 271,                  /* SELECT  */
    MAX = 272,                     /* MAX  */
    MIN = 273,                     /* MIN  */
    COUNT = 274,                   /* COUNT  */
    AVG = 275,                     /* AVG  */
    DESC = 276,                    /* DESC  */
    ASC = 277,                     /* ASC  */
    ORDERBY = 278,                 /* ORDERBY  */
    GROUPBY = 279,                 /* GROUPBY  */
    INNERJOIN = 280,               /* INNERJOIN  */
    SHOW = 281,                    /* SHOW  */
    SYNC = 282,                    /* SYNC  */
    INSERT = 283,                  /* INSERT  */
    DELETE = 284,                  /* DELETE  */
    UPDATE = 285,                  /* UPDATE  */
    LBRACE = 286,                  /* LBRACE  */
    RBRACE = 287,                  /* RBRACE  */
    COMMA = 288,                   /* COMMA  */
    TRX_BEGIN = 289,               /* TRX_BEGIN  */
    TRX_COMMIT = 290,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 291,            /* TRX_ROLLBACK  */
    INT_T = 292,                   /* INT_T  */
    STRING_T = 293,                /* STRING_T  */
    FLOAT_T = 294,                 /* FLOAT_T  */
    DATE_T = 295,                  /* DATE_T  */
    HELP = 296,                    /* HELP  */
    EXIT = 297,                    /* EXIT  */
    DOT = 298,                     /* DOT  */
    INTO = 299,                    /* INTO  */
    VALUES = 300,                  /* VALUES  */
    FROM = 301,                    /* FROM  */
    WHERE = 302,                   /* WHERE  */
    AND = 303,                     /* AND  */
    SET = 304,                     /* SET  */
    ON = 305,                      /* ON  */
    IN = 306,                      /* IN  */
    NOTIN = 307,                   /* NOTIN  */
    LOAD = 308,                    /* LOAD  */
    DATA = 309,                    /* DATA  */
    INFILE = 310,                  /* INFILE  */
    EQ = 311,                      /* EQ  */
    LT = 312,                      /* LT  */
    GT = 313,                      /* GT  */
    LE = 314,                      /* LE  */
    GE = 315,                      /* GE  */
    NE = 316,                      /* NE  */
    NUMBER = 317,                  /* NUMBER  */
    FLOAT = 318,                   /* FLOAT  */
    DATE = 319,                    /* DATE  */
    ID = 320,                      /* ID  */
    PATH = 321,                    /* PATH  */
    SSS = 322,                     /* SSS  */
    STAR = 323,                    /* STAR  */
    STRING_V = 324,                /* STRING_V  */
    AGGOP = 325                    /* AGGOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 130 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 144 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
