/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  size_t insert_num;
  size_t order_num;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  OrderOp orderOps[MAX_NUM];
  OrderDirect orderDirect;
  CompOp comp;
	char id[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->insert_num = 0;
  context->order_num = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 134 "yacc_sql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_IS = 4,                         /* IS  */
  YYSYMBOL_TEXT_T = 5,                     /* TEXT_T  */
  YYSYMBOL_ISNOT = 6,                      /* ISNOT  */
  YYSYMBOL_ANULL = 7,                      /* ANULL  */
  YYSYMBOL_NULLABLE = 8,                   /* NULLABLE  */
  YYSYMBOL_NOTNULL = 9,                    /* NOTNULL  */
  YYSYMBOL_CREATE = 10,                    /* CREATE  */
  YYSYMBOL_DROP = 11,                      /* DROP  */
  YYSYMBOL_TABLE = 12,                     /* TABLE  */
  YYSYMBOL_TABLES = 13,                    /* TABLES  */
  YYSYMBOL_INDEX = 14,                     /* INDEX  */
  YYSYMBOL_UNIQUE = 15,                    /* UNIQUE  */
  YYSYMBOL_SELECT = 16,                    /* SELECT  */
  YYSYMBOL_MAX = 17,                       /* MAX  */
  YYSYMBOL_MIN = 18,                       /* MIN  */
  YYSYMBOL_COUNT = 19,                     /* COUNT  */
  YYSYMBOL_AVG = 20,                       /* AVG  */
  YYSYMBOL_DESC = 21,                      /* DESC  */
  YYSYMBOL_ASC = 22,                       /* ASC  */
  YYSYMBOL_ORDERBY = 23,                   /* ORDERBY  */
  YYSYMBOL_GROUPBY = 24,                   /* GROUPBY  */
  YYSYMBOL_SHOW = 25,                      /* SHOW  */
  YYSYMBOL_SYNC = 26,                      /* SYNC  */
  YYSYMBOL_INSERT = 27,                    /* INSERT  */
  YYSYMBOL_DELETE = 28,                    /* DELETE  */
  YYSYMBOL_UPDATE = 29,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 33,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 34,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 35,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 36,                     /* INT_T  */
  YYSYMBOL_STRING_T = 37,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 38,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 39,                    /* DATE_T  */
  YYSYMBOL_HELP = 40,                      /* HELP  */
  YYSYMBOL_EXIT = 41,                      /* EXIT  */
  YYSYMBOL_DOT = 42,                       /* DOT  */
  YYSYMBOL_INTO = 43,                      /* INTO  */
  YYSYMBOL_VALUES = 44,                    /* VALUES  */
  YYSYMBOL_FROM = 45,                      /* FROM  */
  YYSYMBOL_WHERE = 46,                     /* WHERE  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_SET = 48,                       /* SET  */
  YYSYMBOL_ON = 49,                        /* ON  */
  YYSYMBOL_IN = 50,                        /* IN  */
  YYSYMBOL_NOTIN = 51,                     /* NOTIN  */
  YYSYMBOL_LOAD = 52,                      /* LOAD  */
  YYSYMBOL_DATA = 53,                      /* DATA  */
  YYSYMBOL_INFILE = 54,                    /* INFILE  */
  YYSYMBOL_EQ = 55,                        /* EQ  */
  YYSYMBOL_LT = 56,                        /* LT  */
  YYSYMBOL_GT = 57,                        /* GT  */
  YYSYMBOL_LE = 58,                        /* LE  */
  YYSYMBOL_GE = 59,                        /* GE  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_NUMBER = 61,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 62,                     /* FLOAT  */
  YYSYMBOL_DATE = 63,                      /* DATE  */
  YYSYMBOL_ID = 64,                        /* ID  */
  YYSYMBOL_PATH = 65,                      /* PATH  */
  YYSYMBOL_SSS = 66,                       /* SSS  */
  YYSYMBOL_STAR = 67,                      /* STAR  */
  YYSYMBOL_STRING_V = 68,                  /* STRING_V  */
  YYSYMBOL_AGGOP = 69,                     /* AGGOP  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_commands = 71,                  /* commands  */
  YYSYMBOL_command = 72,                   /* command  */
  YYSYMBOL_exit = 73,                      /* exit  */
  YYSYMBOL_help = 74,                      /* help  */
  YYSYMBOL_sync = 75,                      /* sync  */
  YYSYMBOL_begin = 76,                     /* begin  */
  YYSYMBOL_commit = 77,                    /* commit  */
  YYSYMBOL_rollback = 78,                  /* rollback  */
  YYSYMBOL_drop_table = 79,                /* drop_table  */
  YYSYMBOL_show_tables = 80,               /* show_tables  */
  YYSYMBOL_desc_table = 81,                /* desc_table  */
  YYSYMBOL_create_index = 82,              /* create_index  */
  YYSYMBOL_drop_index = 83,                /* drop_index  */
  YYSYMBOL_create_table = 84,              /* create_table  */
  YYSYMBOL_attr_def_list = 85,             /* attr_def_list  */
  YYSYMBOL_attr_def = 86,                  /* attr_def  */
  YYSYMBOL_is_nullable = 87,               /* is_nullable  */
  YYSYMBOL_number = 88,                    /* number  */
  YYSYMBOL_type = 89,                      /* type  */
  YYSYMBOL_ID_get = 90,                    /* ID_get  */
  YYSYMBOL_insert = 91,                    /* insert  */
  YYSYMBOL_multi_values = 92,              /* multi_values  */
  YYSYMBOL_value_list = 93,                /* value_list  */
  YYSYMBOL_value = 94,                     /* value  */
  YYSYMBOL_delete = 95,                    /* delete  */
  YYSYMBOL_update = 96,                    /* update  */
  YYSYMBOL_select = 97,                    /* select  */
  YYSYMBOL_aggregate_attr = 98,            /* aggregate_attr  */
  YYSYMBOL_aggregate_list = 99,            /* aggregate_list  */
  YYSYMBOL_count_attr = 100,               /* count_attr  */
  YYSYMBOL_select_attr = 101,              /* select_attr  */
  YYSYMBOL_attr_list = 102,                /* attr_list  */
  YYSYMBOL_rel_list = 103,                 /* rel_list  */
  YYSYMBOL_order = 104,                    /* order  */
  YYSYMBOL_order_list = 105,               /* order_list  */
  YYSYMBOL_orderby = 106,                  /* orderby  */
  YYSYMBOL_direction = 107,                /* direction  */
  YYSYMBOL_group = 108,                    /* group  */
  YYSYMBOL_groupby = 109,                  /* groupby  */
  YYSYMBOL_group_list = 110,               /* group_list  */
  YYSYMBOL_where = 111,                    /* where  */
  YYSYMBOL_condition_list = 112,           /* condition_list  */
  YYSYMBOL_condition = 113,                /* condition  */
  YYSYMBOL_subselect = 114,                /* subselect  */
  YYSYMBOL_subselect_attr = 115,           /* subselect_attr  */
  YYSYMBOL_subaggregate_attr = 116,        /* subaggregate_attr  */
  YYSYMBOL_subaggregate_list = 117,        /* subaggregate_list  */
  YYSYMBOL_subcount_attr = 118,            /* subcount_attr  */
  YYSYMBOL_subattr_list = 119,             /* subattr_list  */
  YYSYMBOL_subrel_list = 120,              /* subrel_list  */
  YYSYMBOL_comOp = 121,                    /* comOp  */
  YYSYMBOL_load_data = 122                 /* load_data  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   344

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   160,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   184,   189,   194,   200,   206,   212,   218,   224,   230,
     237,   242,   250,   257,   266,   268,   272,   283,   296,   297,
     298,   301,   304,   305,   306,   307,   308,   311,   320,   337,
     339,   345,   347,   352,   355,   358,   362,   366,   372,   382,
     392,   410,   416,   422,   428,   433,   435,   441,   447,   453,
     458,   463,   468,   475,   480,   485,   490,   495,   498,   500,
     507,   514,   523,   525,   529,   531,   535,   537,   541,   543,
     548,   556,   559,   562,   566,   568,   572,   574,   579,   585,
     587,   592,   598,   600,   604,   606,   611,   632,   652,   672,
     694,   715,   736,   755,   763,   771,   779,   787,   795,   806,
     819,   825,   831,   837,   843,   848,   855,   862,   869,   875,
     877,   883,   889,   895,   900,   905,   910,   915,   917,   922,
     927,   934,   936,   940,   941,   942,   943,   944,   945,   946,
     947,   951
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "IS",
  "TEXT_T", "ISNOT", "ANULL", "NULLABLE", "NOTNULL", "CREATE", "DROP",
  "TABLE", "TABLES", "INDEX", "UNIQUE", "SELECT", "MAX", "MIN", "COUNT",
  "AVG", "DESC", "ASC", "ORDERBY", "GROUPBY", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "IN", "NOTIN", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE",
  "GE", "NE", "NUMBER", "FLOAT", "DATE", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "AGGOP", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "desc_table", "create_index", "drop_index", "create_table",
  "attr_def_list", "attr_def", "is_nullable", "number", "type", "ID_get",
  "insert", "multi_values", "value_list", "value", "delete", "update",
  "select", "aggregate_attr", "aggregate_list", "count_attr",
  "select_attr", "attr_list", "rel_list", "order", "order_list", "orderby",
  "direction", "group", "groupby", "group_list", "where", "condition_list",
  "condition", "subselect", "subselect_attr", "subaggregate_attr",
  "subaggregate_list", "subcount_attr", "subattr_list", "subrel_list",
  "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-268)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -268,   155,  -268,   132,    10,    -9,   -26,    32,    58,    16,
      18,    28,    83,   100,   114,   115,   119,    70,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,    64,    65,    66,    72,
      74,   118,   127,   128,   147,   -19,  -268,  -268,   133,   176,
     182,  -268,   122,   123,   143,  -268,  -268,  -268,  -268,  -268,
     138,   163,   156,   140,   203,   210,   152,   154,    76,   157,
     158,   -20,  -268,   159,  -268,  -268,   175,   174,   160,   161,
     162,   164,   180,  -268,  -268,   194,   199,  -268,  -268,  -268,
     200,   201,    -7,   202,   202,   208,   205,    27,   230,   186,
     204,  -268,   211,   136,   212,   181,   214,   214,   214,   214,
      60,  -268,  -268,  -268,   184,   174,    39,  -268,  -268,  -268,
    -268,    56,  -268,   104,   197,  -268,    39,   237,   162,   219,
    -268,  -268,  -268,  -268,  -268,     9,   187,   222,   183,  -268,
    -268,  -268,  -268,   202,   202,   208,   231,   221,  -268,  -268,
     192,   225,   225,  -268,  -268,  -268,  -268,  -268,  -268,    12,
      33,    27,  -268,   174,   193,   211,   255,  -268,  -268,   198,
    -268,   229,   206,   232,   233,   234,   235,  -268,  -268,  -268,
     207,   242,    39,   236,    75,   245,  -268,  -268,  -268,  -268,
    -268,   226,  -268,   197,   266,   269,  -268,  -268,  -268,   243,
     270,   244,   213,   215,    76,   216,    -1,   246,   217,   273,
     221,   250,   225,   225,    21,   150,   220,  -268,  -268,  -268,
      44,  -268,   280,   254,   256,   257,   258,  -268,  -268,   227,
    -268,   207,  -268,    -6,  -268,  -268,  -268,   260,   283,  -268,
    -268,   251,  -268,  -268,   262,   264,   265,   267,    -5,  -268,
     253,  -268,  -268,  -268,  -268,   214,   214,   214,   214,     8,
     246,   238,   239,  -268,    39,  -268,   240,   241,   247,    78,
     248,   249,    89,  -268,   252,  -268,  -268,  -268,  -268,  -268,
    -268,    22,   268,   221,  -268,   275,   276,  -268,  -268,  -268,
     277,   278,    77,   282,   282,   285,   259,  -268,  -268,   279,
     286,   286,   286,   286,   148,  -268,  -268,  -268,   261,   174,
     268,   250,   191,  -268,  -268,  -268,  -268,   282,   282,   285,
     242,  -268,  -268,   271,   289,   290,   291,  -268,  -268,  -268,
     284,   263,   272,    78,   274,  -268,   293,   295,   297,   298,
     286,   286,   286,   286,  -268,  -268,  -268,  -268
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    12,    13,
       8,     5,     7,     6,     4,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    73,    77,     0,     0,
       0,    23,     0,     0,     0,    24,    25,    26,    22,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,    29,    28,     0,   102,     0,     0,
       0,     0,     0,    27,    32,     0,     0,    72,    70,    71,
       0,     0,    78,    78,    78,    82,     0,     0,     0,     0,
       0,    47,    34,     0,     0,     0,    65,    65,    65,    65,
       0,    79,    76,    74,     0,   102,     0,    57,    53,    54,
      56,     0,    55,     0,   104,    58,     0,     0,     0,     0,
      46,    42,    43,    44,    45,    38,     0,     0,     0,    61,
      62,    64,    63,    78,    78,    82,    84,    51,   149,   150,
       0,     0,     0,   143,   144,   145,   146,   147,   148,     0,
       0,     0,   103,   102,     0,    34,     0,    40,    39,     0,
      37,     0,     0,     0,     0,     0,     0,    80,    81,    83,
      88,    94,     0,     0,     0,     0,   115,   117,   108,   106,
     113,   109,   107,   104,     0,     0,    35,    33,    41,     0,
       0,     0,     0,     0,     0,     0,    93,    86,    96,     0,
      51,    49,     0,     0,     0,     0,     0,   105,    59,   151,
      38,    31,     0,     0,     0,     0,     0,    92,    91,     0,
      89,    88,    85,    99,    95,    60,    52,     0,     0,   116,
     118,     0,   110,   114,     0,     0,     0,     0,   137,   120,
       0,   124,   111,    36,    30,    65,    65,    65,    65,    93,
      86,     0,     0,    97,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   122,     0,    66,    67,    69,    68,    90,
      87,    99,    99,    51,   112,     0,     0,   136,   134,   135,
       0,     0,   137,   137,   137,   141,     0,   100,    98,     0,
     129,   129,   129,   129,     0,   138,   123,   121,     0,   102,
      99,    49,     0,   125,   126,   128,   127,   137,   137,   141,
      94,   101,    50,     0,     0,     0,     0,   139,   140,   142,
       0,     0,     0,     0,     0,   119,     0,     0,     0,     0,
     129,   129,   129,   129,   130,   131,   133,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,   131,   171,   102,  -268,  -268,
    -268,  -268,    19,  -206,  -110,  -268,  -268,  -268,  -268,  -106,
     129,  -268,   -23,   189,  -268,    71,   101,    80,    15,  -268,
    -267,  -115,   144,   179,  -147,  -268,  -268,  -104,    11,  -261,
      23,  -116,  -268
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   129,   102,   170,   199,   135,
     103,    31,   238,   183,   123,    32,    33,    34,    47,   139,
      90,    48,    72,   115,   181,   232,   207,   230,   209,   234,
     263,    98,   162,   124,   186,   250,   251,   313,   290,   273,
     309,   159,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,   140,   141,   142,   236,   187,   147,   160,    41,    42,
      43,    44,   190,    70,   297,   298,   163,   167,   168,   117,
     227,   228,    39,    71,    40,    70,   261,   271,   117,   227,
     228,   305,   306,   307,   117,   110,   262,   272,    49,   169,
     117,   229,   185,   321,    93,    50,   117,    94,   194,   189,
     192,   185,   167,   168,   261,    45,   327,   328,    46,    52,
     148,    51,   149,    53,   296,   239,   240,   243,   214,   111,
     112,   113,   210,   118,   119,   120,   188,   299,   122,   148,
      63,   149,   118,   119,   120,   241,    55,   122,   118,   119,
     120,   121,    54,   122,   118,   119,   120,   191,   150,   122,
     118,   119,   120,    56,   242,   122,   151,   152,   148,   271,
     149,   153,   154,   155,   156,   157,   158,    57,    58,   304,
     177,   178,    59,    60,   143,   212,   213,   144,    61,    62,
     153,   154,   155,   156,   157,   158,    64,    87,    65,   287,
      88,   130,   288,    89,    36,   289,    37,    38,    66,   275,
     276,   277,   278,   293,   283,     2,   294,    67,    68,   153,
     154,   155,   156,   157,   158,     3,     4,   244,   245,   246,
     247,     5,   131,   132,   133,   134,     6,    69,    73,    74,
       7,     8,     9,    10,    11,    75,    76,    77,    12,    13,
      14,    78,    79,    80,   320,    15,    16,   314,   315,   316,
     173,   174,   175,   176,    82,    81,    83,    17,   323,   324,
     325,   326,   317,    84,   248,   318,    85,   249,    86,    96,
      97,    91,    92,    95,    99,   106,   101,   100,   104,   105,
     107,   108,   109,   125,    70,   116,   344,   345,   346,   347,
     114,   126,   136,   128,   161,   137,   138,   127,   145,   164,
     166,   171,   172,   182,   180,   185,   184,   195,   197,   198,
     200,   215,   202,   203,   204,   205,   208,   211,   216,   218,
     201,   206,   219,   221,   220,   222,   235,   223,   231,   224,
     226,   233,   237,   254,   252,   255,   265,   256,   257,   258,
     264,   259,   267,   266,   268,   269,   196,   270,   274,   165,
     261,   331,   281,   282,   284,   285,   300,   301,   302,   303,
     311,   286,   291,   292,   271,   335,   295,   308,   312,   332,
     333,   334,   253,   310,   340,   319,   341,   336,   342,   343,
     322,   280,   260,   225,   179,   330,   337,   217,   339,   279,
     193,     0,   329,     0,   338
};

static const yytype_int16 yycheck[] =
{
     115,   107,   108,   109,   210,   152,   116,   123,    17,    18,
      19,    20,   159,    32,   281,   282,   126,     8,     9,     7,
      21,    22,    12,    42,    14,    32,    32,    32,     7,    21,
      22,   292,   293,   294,     7,    42,    42,    42,    64,    30,
       7,    42,    30,   310,    64,    13,     7,    67,   163,   159,
     160,    30,     8,     9,    32,    64,   317,   318,    67,    43,
       4,     3,     6,    45,    42,   212,   213,   214,   184,    92,
      93,    94,   182,    61,    62,    63,    64,   283,    66,     4,
      14,     6,    61,    62,    63,    64,     3,    66,    61,    62,
      63,    64,    64,    66,    61,    62,    63,    64,    42,    66,
      61,    62,    63,     3,   214,    66,    50,    51,     4,    32,
       6,    55,    56,    57,    58,    59,    60,     3,     3,    42,
     143,   144,     3,    53,    64,    50,    51,    67,    64,    64,
      55,    56,    57,    58,    59,    60,    64,    61,    64,    61,
      64,     5,    64,    67,    12,    67,    14,    15,    30,   255,
     256,   257,   258,    64,   264,     0,    67,    30,    30,    55,
      56,    57,    58,    59,    60,    10,    11,    17,    18,    19,
      20,    16,    36,    37,    38,    39,    21,    30,    45,     3,
      25,    26,    27,    28,    29,     3,    64,    64,    33,    34,
      35,    48,    54,    30,   309,    40,    41,   301,   302,   303,
      17,    18,    19,    20,    64,    49,     3,    52,    17,    18,
      19,    20,    64,     3,    64,    67,    64,    67,    64,    44,
      46,    64,    64,    64,    64,    31,    64,    66,    64,    49,
      31,    31,    31,     3,    32,    30,   340,   341,   342,   343,
      32,    55,    30,    32,    47,    64,    32,    43,    64,    12,
      31,    64,    30,    32,    23,    30,    64,    64,     3,    61,
      31,    16,    30,    30,    30,    30,    24,    31,    42,     3,
      64,    64,     3,     3,    31,    31,     3,    64,    32,    64,
      64,    64,    32,     3,    64,    31,     3,    31,    31,    31,
      30,    64,    30,    42,    30,    30,   165,    30,    45,   128,
      32,    30,    64,    64,    64,    64,    31,    31,    31,    31,
      31,    64,    64,    64,    32,    31,    64,    32,    32,    30,
      30,    30,   220,    64,    31,    64,    31,    64,    31,    31,
     311,   260,   231,   204,   145,   320,    64,   193,    64,   259,
     161,    -1,   319,    -1,   333
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,     0,    10,    11,    16,    21,    25,    26,    27,
      28,    29,    33,    34,    35,    40,    41,    52,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    91,    95,    96,    97,   122,    12,    14,    15,    12,
      14,    17,    18,    19,    20,    64,    67,    98,   101,    64,
      13,     3,    43,    45,    64,     3,     3,     3,     3,     3,
      53,    64,    64,    14,    64,    64,    30,    30,    30,    30,
      32,    42,   102,    45,     3,     3,    64,    64,    48,    54,
      30,    49,    64,     3,     3,    64,    64,    61,    64,    67,
     100,    64,    64,    64,    67,    64,    44,    46,   111,    64,
      66,    64,    86,    90,    64,    49,    31,    31,    31,    31,
      42,   102,   102,   102,    32,   103,    30,     7,    61,    62,
      63,    64,    66,    94,   113,     3,    55,    43,    32,    85,
       5,    36,    37,    38,    39,    89,    30,    64,    32,    99,
      99,    99,    99,    64,    67,    64,   111,    94,     4,     6,
      42,    50,    51,    55,    56,    57,    58,    59,    60,   121,
     121,    47,   112,    94,    12,    86,    31,     8,     9,    30,
      87,    64,    30,    17,    18,    19,    20,   102,   102,   103,
      23,   104,    32,    93,    64,    30,   114,   114,    64,    94,
     114,    64,    94,   113,   111,    64,    85,     3,    61,    88,
      31,    64,    30,    30,    30,    30,    64,   106,    24,   108,
      94,    31,    50,    51,   121,    16,    42,   112,     3,     3,
      31,     3,    31,    64,    64,   100,    64,    21,    22,    42,
     107,    32,   105,    64,   109,     3,    93,    32,    92,   114,
     114,    64,    94,   114,    17,    18,    19,    20,    64,    67,
     115,   116,    64,    87,     3,    31,    31,    31,    31,    64,
     106,    32,    42,   110,    30,     3,    42,    30,    30,    30,
      30,    32,    42,   119,    45,    99,    99,    99,    99,   107,
     105,    64,    64,    94,    64,    64,    64,    61,    64,    67,
     118,    64,    64,    64,    67,    64,    42,   110,   110,    93,
      31,    31,    31,    31,    42,   119,   119,   119,    32,   120,
      64,    31,    32,   117,   117,   117,   117,    64,    67,    64,
     111,   110,    92,    17,    18,    19,    20,   119,   119,   120,
     108,    30,    30,    30,    30,    31,    64,    64,   118,    64,
      31,    31,    31,    31,   117,   117,   117,   117
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    89,    89,    89,    89,    89,    90,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    95,    96,
      97,    98,    98,    98,    98,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   109,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   117,
     117,   117,   117,   117,   118,   118,   118,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
      10,     9,     4,     8,     0,     3,     6,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    10,     0,
       6,     0,     3,     1,     1,     1,     1,     1,     5,     8,
       9,     5,     5,     5,     5,     0,     6,     6,     6,     6,
       1,     1,     1,     1,     4,     2,     4,     1,     0,     3,
       5,     5,     0,     3,     0,     3,     0,     3,     0,     2,
       4,     1,     1,     0,     0,     2,     0,     2,     4,     0,
       3,     5,     0,     3,     0,     3,     3,     3,     3,     3,
       5,     5,     7,     3,     5,     3,     5,     3,     5,     9,
       1,     4,     2,     4,     1,     5,     5,     5,     5,     0,
       6,     6,     6,     6,     1,     1,     1,     0,     3,     5,
       5,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 21: /* exit: EXIT SEMICOLON  */
#line 184 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1489 "yacc_sql.tab.c"
    break;

  case 22: /* help: HELP SEMICOLON  */
#line 189 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1497 "yacc_sql.tab.c"
    break;

  case 23: /* sync: SYNC SEMICOLON  */
#line 194 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1505 "yacc_sql.tab.c"
    break;

  case 24: /* begin: TRX_BEGIN SEMICOLON  */
#line 200 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1513 "yacc_sql.tab.c"
    break;

  case 25: /* commit: TRX_COMMIT SEMICOLON  */
#line 206 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1521 "yacc_sql.tab.c"
    break;

  case 26: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 212 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1529 "yacc_sql.tab.c"
    break;

  case 27: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 218 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1538 "yacc_sql.tab.c"
    break;

  case 28: /* show_tables: SHOW TABLES SEMICOLON  */
#line 224 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1546 "yacc_sql.tab.c"
    break;

  case 29: /* desc_table: DESC ID SEMICOLON  */
#line 230 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1555 "yacc_sql.tab.c"
    break;

  case 30: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 238 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 1);
		}
#line 1564 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 243 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1573 "yacc_sql.tab.c"
    break;

  case 32: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 251 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1582 "yacc_sql.tab.c"
    break;

  case 33: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 258 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1594 "yacc_sql.tab.c"
    break;

  case 35: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 268 "yacc_sql.y"
                                  {    }
#line 1600 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def: ID_get type LBRACE number RBRACE is_nullable  */
#line 273 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1615 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type is_nullable  */
#line 284 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4,(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1630 "yacc_sql.tab.c"
    break;

  case 38: /* is_nullable: %empty  */
#line 296 "yacc_sql.y"
        {(yyval.number) = 0;}
#line 1636 "yacc_sql.tab.c"
    break;

  case 39: /* is_nullable: NOTNULL  */
#line 297 "yacc_sql.y"
                  {(yyval.number) = 0;}
#line 1642 "yacc_sql.tab.c"
    break;

  case 40: /* is_nullable: NULLABLE  */
#line 298 "yacc_sql.y"
                   {(yyval.number) = 1;}
#line 1648 "yacc_sql.tab.c"
    break;

  case 41: /* number: NUMBER  */
#line 301 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1654 "yacc_sql.tab.c"
    break;

  case 42: /* type: INT_T  */
#line 304 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1660 "yacc_sql.tab.c"
    break;

  case 43: /* type: STRING_T  */
#line 305 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1666 "yacc_sql.tab.c"
    break;

  case 44: /* type: FLOAT_T  */
#line 306 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1672 "yacc_sql.tab.c"
    break;

  case 45: /* type: DATE_T  */
#line 307 "yacc_sql.y"
                {(yyval.number)=DATES; }
#line 1678 "yacc_sql.tab.c"
    break;

  case 46: /* type: TEXT_T  */
#line 308 "yacc_sql.y"
                {(yyval.number)=TEXTS; }
#line 1684 "yacc_sql.tab.c"
    break;

  case 47: /* ID_get: ID  */
#line 312 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1693 "yacc_sql.tab.c"
    break;

  case 48: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE multi_values SEMICOLON  */
#line 321 "yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-7].string), CONTEXT->values, CONTEXT->value_length, CONTEXT->insert_num);

      //临时变量清零
      CONTEXT->value_length=0;
      CONTEXT->insert_num=0;
    }
#line 1713 "yacc_sql.tab.c"
    break;

  case 50: /* multi_values: COMMA LBRACE value value_list RBRACE multi_values  */
#line 339 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$3;
  		CONTEXT->insert_num++;
	  }
#line 1722 "yacc_sql.tab.c"
    break;

  case 52: /* value_list: COMMA value value_list  */
#line 347 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1730 "yacc_sql.tab.c"
    break;

  case 53: /* value: NUMBER  */
#line 352 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1738 "yacc_sql.tab.c"
    break;

  case 54: /* value: FLOAT  */
#line 355 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1746 "yacc_sql.tab.c"
    break;

  case 55: /* value: SSS  */
#line 358 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1755 "yacc_sql.tab.c"
    break;

  case 56: /* value: DATE  */
#line 362 "yacc_sql.y"
          {
    			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1764 "yacc_sql.tab.c"
    break;

  case 57: /* value: ANULL  */
#line 366 "yacc_sql.y"
          {
    		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1772 "yacc_sql.tab.c"
    break;

  case 58: /* delete: DELETE FROM ID where SEMICOLON  */
#line 373 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1784 "yacc_sql.tab.c"
    break;

  case 59: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 383 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1796 "yacc_sql.tab.c"
    break;

  case 60: /* select: SELECT select_attr FROM ID rel_list where order group SEMICOLON  */
#line 393 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
			// selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 0);
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
			selects_append_orderOps(&CONTEXT->ssql->sstr.selection,CONTEXT->orderOps,CONTEXT->order_num);
			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			// sub_selects_init(&CONTEXT->ssql->sstr.selection);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 1816 "yacc_sql.tab.c"
    break;

  case 61: /* aggregate_attr: MAX LBRACE ID RBRACE aggregate_list  */
#line 410 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1827 "yacc_sql.tab.c"
    break;

  case 62: /* aggregate_attr: MIN LBRACE ID RBRACE aggregate_list  */
#line 416 "yacc_sql.y"
                                          {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1838 "yacc_sql.tab.c"
    break;

  case 63: /* aggregate_attr: AVG LBRACE ID RBRACE aggregate_list  */
#line 422 "yacc_sql.y"
                                          {
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1849 "yacc_sql.tab.c"
    break;

  case 64: /* aggregate_attr: COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 428 "yacc_sql.y"
                                                    {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1857 "yacc_sql.tab.c"
    break;

  case 66: /* aggregate_list: COMMA MAX LBRACE ID RBRACE aggregate_list  */
#line 435 "yacc_sql.y"
                                                {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1868 "yacc_sql.tab.c"
    break;

  case 67: /* aggregate_list: COMMA MIN LBRACE ID RBRACE aggregate_list  */
#line 441 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1879 "yacc_sql.tab.c"
    break;

  case 68: /* aggregate_list: COMMA AVG LBRACE ID RBRACE aggregate_list  */
#line 447 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1890 "yacc_sql.tab.c"
    break;

  case 69: /* aggregate_list: COMMA COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 453 "yacc_sql.y"
                                                          {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1898 "yacc_sql.tab.c"
    break;

  case 70: /* count_attr: ID  */
#line 458 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1908 "yacc_sql.tab.c"
    break;

  case 71: /* count_attr: STAR  */
#line 463 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 1918 "yacc_sql.tab.c"
    break;

  case 72: /* count_attr: NUMBER  */
#line 468 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1928 "yacc_sql.tab.c"
    break;

  case 73: /* select_attr: STAR  */
#line 475 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1938 "yacc_sql.tab.c"
    break;

  case 74: /* select_attr: ID DOT STAR attr_list  */
#line 480 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1948 "yacc_sql.tab.c"
    break;

  case 75: /* select_attr: ID attr_list  */
#line 485 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1958 "yacc_sql.tab.c"
    break;

  case 76: /* select_attr: ID DOT ID attr_list  */
#line 490 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1968 "yacc_sql.tab.c"
    break;

  case 77: /* select_attr: aggregate_attr  */
#line 495 "yacc_sql.y"
                     {
    }
#line 1975 "yacc_sql.tab.c"
    break;

  case 79: /* attr_list: COMMA ID attr_list  */
#line 500 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 1987 "yacc_sql.tab.c"
    break;

  case 80: /* attr_list: COMMA ID DOT ID attr_list  */
#line 507 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 1999 "yacc_sql.tab.c"
    break;

  case 81: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 514 "yacc_sql.y"
                                  {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
    }
#line 2011 "yacc_sql.tab.c"
    break;

  case 83: /* rel_list: COMMA ID rel_list  */
#line 525 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2019 "yacc_sql.tab.c"
    break;

  case 85: /* order: ORDERBY orderby order_list  */
#line 531 "yacc_sql.y"
                                 {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2027 "yacc_sql.tab.c"
    break;

  case 87: /* order_list: COMMA orderby order_list  */
#line 537 "yacc_sql.y"
                              {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2035 "yacc_sql.tab.c"
    break;

  case 89: /* orderby: ID direction  */
#line 543 "yacc_sql.y"
              {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,NULL,(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2045 "yacc_sql.tab.c"
    break;

  case 90: /* orderby: ID DOT ID direction  */
#line 548 "yacc_sql.y"
                                     {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,(yyvsp[-3].string),(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2055 "yacc_sql.tab.c"
    break;

  case 91: /* direction: ASC  */
#line 556 "yacc_sql.y"
        {
    		CONTEXT->orderDirect = ORASC;
    			}
#line 2063 "yacc_sql.tab.c"
    break;

  case 92: /* direction: DESC  */
#line 559 "yacc_sql.y"
           {
		CONTEXT->orderDirect = ORDESC;
			}
#line 2071 "yacc_sql.tab.c"
    break;

  case 93: /* direction: %empty  */
#line 562 "yacc_sql.y"
      {
    		CONTEXT->orderDirect = ORASC;
    }
#line 2079 "yacc_sql.tab.c"
    break;

  case 95: /* group: GROUPBY groupby  */
#line 568 "yacc_sql.y"
                      {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
}
#line 2087 "yacc_sql.tab.c"
    break;

  case 97: /* groupby: ID group_list  */
#line 574 "yacc_sql.y"
               {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2097 "yacc_sql.tab.c"
    break;

  case 98: /* groupby: ID DOT ID group_list  */
#line 579 "yacc_sql.y"
                      {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2107 "yacc_sql.tab.c"
    break;

  case 100: /* group_list: COMMA ID group_list  */
#line 587 "yacc_sql.y"
                     {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2117 "yacc_sql.tab.c"
    break;

  case 101: /* group_list: COMMA ID DOT ID group_list  */
#line 592 "yacc_sql.y"
                            {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2127 "yacc_sql.tab.c"
    break;

  case 103: /* where: WHERE condition condition_list  */
#line 600 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2135 "yacc_sql.tab.c"
    break;

  case 105: /* condition_list: AND condition condition_list  */
#line 606 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2143 "yacc_sql.tab.c"
    break;

  case 106: /* condition: ID comOp value  */
#line 612 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2168 "yacc_sql.tab.c"
    break;

  case 107: /* condition: value comOp value  */
#line 633 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2192 "yacc_sql.tab.c"
    break;

  case 108: /* condition: ID comOp ID  */
#line 653 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 2216 "yacc_sql.tab.c"
    break;

  case 109: /* condition: value comOp ID  */
#line 673 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
#line 2242 "yacc_sql.tab.c"
    break;

  case 110: /* condition: ID DOT ID comOp value  */
#line 695 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
#line 2267 "yacc_sql.tab.c"
    break;

  case 111: /* condition: value comOp ID DOT ID  */
#line 716 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
#line 2292 "yacc_sql.tab.c"
    break;

  case 112: /* condition: ID DOT ID comOp ID DOT ID  */
#line 737 "yacc_sql.y"
        {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
#line 2315 "yacc_sql.tab.c"
    break;

  case 113: /* condition: ID comOp subselect  */
#line 755 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2328 "yacc_sql.tab.c"
    break;

  case 114: /* condition: ID DOT ID comOp subselect  */
#line 763 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2341 "yacc_sql.tab.c"
    break;

  case 115: /* condition: ID IN subselect  */
#line 771 "yacc_sql.y"
                      {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2354 "yacc_sql.tab.c"
    break;

  case 116: /* condition: ID DOT ID IN subselect  */
#line 779 "yacc_sql.y"
                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2367 "yacc_sql.tab.c"
    break;

  case 117: /* condition: ID NOTIN subselect  */
#line 787 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2380 "yacc_sql.tab.c"
    break;

  case 118: /* condition: ID DOT ID NOTIN subselect  */
#line 795 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2393 "yacc_sql.tab.c"
    break;

  case 119: /* subselect: LBRACE SELECT subselect_attr FROM ID subrel_list where group RBRACE  */
#line 807 "yacc_sql.y"
                {

			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-4].string));
			selects_append_conditions(CONTEXT->ssql->sstr.selection.subSelect, CONTEXT->conditions, CONTEXT->condition_length);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2408 "yacc_sql.tab.c"
    break;

  case 120: /* subselect_attr: STAR  */
#line 819 "yacc_sql.y"
         {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2419 "yacc_sql.tab.c"
    break;

  case 121: /* subselect_attr: ID DOT STAR subattr_list  */
#line 825 "yacc_sql.y"
                               {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2430 "yacc_sql.tab.c"
    break;

  case 122: /* subselect_attr: ID subattr_list  */
#line 831 "yacc_sql.y"
                      {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2441 "yacc_sql.tab.c"
    break;

  case 123: /* subselect_attr: ID DOT ID subattr_list  */
#line 837 "yacc_sql.y"
                                 {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
	}
#line 2452 "yacc_sql.tab.c"
    break;

  case 124: /* subselect_attr: subaggregate_attr  */
#line 843 "yacc_sql.y"
                        {
    }
#line 2459 "yacc_sql.tab.c"
    break;

  case 125: /* subaggregate_attr: MAX LBRACE ID RBRACE subaggregate_list  */
#line 848 "yacc_sql.y"
                                           {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2471 "yacc_sql.tab.c"
    break;

  case 126: /* subaggregate_attr: MIN LBRACE ID RBRACE subaggregate_list  */
#line 855 "yacc_sql.y"
                                             {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2483 "yacc_sql.tab.c"
    break;

  case 127: /* subaggregate_attr: AVG LBRACE ID RBRACE subaggregate_list  */
#line 862 "yacc_sql.y"
                                             {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2495 "yacc_sql.tab.c"
    break;

  case 128: /* subaggregate_attr: COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 869 "yacc_sql.y"
                                                          {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2504 "yacc_sql.tab.c"
    break;

  case 130: /* subaggregate_list: COMMA MAX LBRACE ID RBRACE subaggregate_list  */
#line 877 "yacc_sql.y"
                                                   {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2515 "yacc_sql.tab.c"
    break;

  case 131: /* subaggregate_list: COMMA MIN LBRACE ID RBRACE subaggregate_list  */
#line 883 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2526 "yacc_sql.tab.c"
    break;

  case 132: /* subaggregate_list: COMMA AVG LBRACE ID RBRACE subaggregate_list  */
#line 889 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2537 "yacc_sql.tab.c"
    break;

  case 133: /* subaggregate_list: COMMA COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 895 "yacc_sql.y"
                                                                {
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2545 "yacc_sql.tab.c"
    break;

  case 134: /* subcount_attr: ID  */
#line 900 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2555 "yacc_sql.tab.c"
    break;

  case 135: /* subcount_attr: STAR  */
#line 905 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
        }
#line 2565 "yacc_sql.tab.c"
    break;

  case 136: /* subcount_attr: NUMBER  */
#line 910 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2575 "yacc_sql.tab.c"
    break;

  case 138: /* subattr_list: COMMA ID subattr_list  */
#line 917 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
      }
#line 2585 "yacc_sql.tab.c"
    break;

  case 139: /* subattr_list: COMMA ID DOT ID subattr_list  */
#line 922 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
  	  }
#line 2595 "yacc_sql.tab.c"
    break;

  case 140: /* subattr_list: COMMA ID DOT STAR subattr_list  */
#line 927 "yacc_sql.y"
                                     {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2605 "yacc_sql.tab.c"
    break;

  case 142: /* subrel_list: COMMA ID subrel_list  */
#line 936 "yacc_sql.y"
                           {
			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-1].string));
}
#line 2613 "yacc_sql.tab.c"
    break;

  case 143: /* comOp: EQ  */
#line 940 "yacc_sql.y"
         { CONTEXT->comp = EQUAL_TO; }
#line 2619 "yacc_sql.tab.c"
    break;

  case 144: /* comOp: LT  */
#line 941 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2625 "yacc_sql.tab.c"
    break;

  case 145: /* comOp: GT  */
#line 942 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2631 "yacc_sql.tab.c"
    break;

  case 146: /* comOp: LE  */
#line 943 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2637 "yacc_sql.tab.c"
    break;

  case 147: /* comOp: GE  */
#line 944 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2643 "yacc_sql.tab.c"
    break;

  case 148: /* comOp: NE  */
#line 945 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2649 "yacc_sql.tab.c"
    break;

  case 149: /* comOp: IS  */
#line 946 "yacc_sql.y"
         {CONTEXT->comp = EQUAL_IS;}
#line 2655 "yacc_sql.tab.c"
    break;

  case 150: /* comOp: ISNOT  */
#line 947 "yacc_sql.y"
           {CONTEXT->comp = EQUAL_IS_NOT;}
#line 2661 "yacc_sql.tab.c"
    break;

  case 151: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 952 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2670 "yacc_sql.tab.c"
    break;


#line 2674 "yacc_sql.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (scanner, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 957 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
