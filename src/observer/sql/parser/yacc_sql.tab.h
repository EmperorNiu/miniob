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
    GROUPBY = 278,                 /* GROUPBY  */
    SHOW = 279,                    /* SHOW  */
    SYNC = 280,                    /* SYNC  */
    INSERT = 281,                  /* INSERT  */
    DELETE = 282,                  /* DELETE  */
    UPDATE = 283,                  /* UPDATE  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285,                  /* RBRACE  */
    COMMA = 286,                   /* COMMA  */
    TRX_BEGIN = 287,               /* TRX_BEGIN  */
    TRX_COMMIT = 288,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 289,            /* TRX_ROLLBACK  */
    INT_T = 290,                   /* INT_T  */
    STRING_T = 291,                /* STRING_T  */
    FLOAT_T = 292,                 /* FLOAT_T  */
    DATE_T = 293,                  /* DATE_T  */
    HELP = 294,                    /* HELP  */
    EXIT = 295,                    /* EXIT  */
    DOT = 296,                     /* DOT  */
    INTO = 297,                    /* INTO  */
    VALUES = 298,                  /* VALUES  */
    FROM = 299,                    /* FROM  */
    WHERE = 300,                   /* WHERE  */
    AND = 301,                     /* AND  */
    SET = 302,                     /* SET  */
    ON = 303,                      /* ON  */
    IN = 304,                      /* IN  */
    NOTIN = 305,                   /* NOTIN  */
    LOAD = 306,                    /* LOAD  */
    DATA = 307,                    /* DATA  */
    INFILE = 308,                  /* INFILE  */
    EQ = 309,                      /* EQ  */
    LT = 310,                      /* LT  */
    GT = 311,                      /* GT  */
    LE = 312,                      /* LE  */
    GE = 313,                      /* GE  */
    NE = 314,                      /* NE  */
    NUMBER = 315,                  /* NUMBER  */
    FLOAT = 316,                   /* FLOAT  */
    DATE = 317,                    /* DATE  */
    ID = 318,                      /* ID  */
    PATH = 319,                    /* PATH  */
    SSS = 320,                     /* SSS  */
    STAR = 321,                    /* STAR  */
    STRING_V = 322,                /* STRING_V  */
    AGGOP = 323                    /* AGGOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 128 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 142 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
