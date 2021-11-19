/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

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
  YYSYMBOL_INNERJOIN = 25,                 /* INNERJOIN  */
  YYSYMBOL_SHOW = 26,                      /* SHOW  */
  YYSYMBOL_SYNC = 27,                      /* SYNC  */
  YYSYMBOL_INSERT = 28,                    /* INSERT  */
  YYSYMBOL_DELETE = 29,                    /* DELETE  */
  YYSYMBOL_UPDATE = 30,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 31,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 32,                    /* RBRACE  */
  YYSYMBOL_COMMA = 33,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 34,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 35,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 36,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 37,                     /* INT_T  */
  YYSYMBOL_STRING_T = 38,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 39,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 40,                    /* DATE_T  */
  YYSYMBOL_HELP = 41,                      /* HELP  */
  YYSYMBOL_EXIT = 42,                      /* EXIT  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_INTO = 44,                      /* INTO  */
  YYSYMBOL_VALUES = 45,                    /* VALUES  */
  YYSYMBOL_FROM = 46,                      /* FROM  */
  YYSYMBOL_WHERE = 47,                     /* WHERE  */
  YYSYMBOL_AND = 48,                       /* AND  */
  YYSYMBOL_SET = 49,                       /* SET  */
  YYSYMBOL_ON = 50,                        /* ON  */
  YYSYMBOL_IN = 51,                        /* IN  */
  YYSYMBOL_NOTIN = 52,                     /* NOTIN  */
  YYSYMBOL_LOAD = 53,                      /* LOAD  */
  YYSYMBOL_DATA = 54,                      /* DATA  */
  YYSYMBOL_INFILE = 55,                    /* INFILE  */
  YYSYMBOL_EQ = 56,                        /* EQ  */
  YYSYMBOL_LT = 57,                        /* LT  */
  YYSYMBOL_GT = 58,                        /* GT  */
  YYSYMBOL_LE = 59,                        /* LE  */
  YYSYMBOL_GE = 60,                        /* GE  */
  YYSYMBOL_NE = 61,                        /* NE  */
  YYSYMBOL_NUMBER = 62,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 63,                     /* FLOAT  */
  YYSYMBOL_DATE = 64,                      /* DATE  */
  YYSYMBOL_ID = 65,                        /* ID  */
  YYSYMBOL_PATH = 66,                      /* PATH  */
  YYSYMBOL_SSS = 67,                       /* SSS  */
  YYSYMBOL_STAR = 68,                      /* STAR  */
  YYSYMBOL_STRING_V = 69,                  /* STRING_V  */
  YYSYMBOL_AGGOP = 70,                     /* AGGOP  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_commands = 72,                  /* commands  */
  YYSYMBOL_command = 73,                   /* command  */
  YYSYMBOL_exit = 74,                      /* exit  */
  YYSYMBOL_help = 75,                      /* help  */
  YYSYMBOL_sync = 76,                      /* sync  */
  YYSYMBOL_begin = 77,                     /* begin  */
  YYSYMBOL_commit = 78,                    /* commit  */
  YYSYMBOL_rollback = 79,                  /* rollback  */
  YYSYMBOL_drop_table = 80,                /* drop_table  */
  YYSYMBOL_show_tables = 81,               /* show_tables  */
  YYSYMBOL_desc_table = 82,                /* desc_table  */
  YYSYMBOL_create_index = 83,              /* create_index  */
  YYSYMBOL_index_list = 84,                /* index_list  */
  YYSYMBOL_drop_index = 85,                /* drop_index  */
  YYSYMBOL_create_table = 86,              /* create_table  */
  YYSYMBOL_attr_def_list = 87,             /* attr_def_list  */
  YYSYMBOL_attr_def = 88,                  /* attr_def  */
  YYSYMBOL_is_nullable = 89,               /* is_nullable  */
  YYSYMBOL_number = 90,                    /* number  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_ID_get = 92,                    /* ID_get  */
  YYSYMBOL_insert = 93,                    /* insert  */
  YYSYMBOL_multi_values = 94,              /* multi_values  */
  YYSYMBOL_value_list = 95,                /* value_list  */
  YYSYMBOL_value = 96,                     /* value  */
  YYSYMBOL_delete = 97,                    /* delete  */
  YYSYMBOL_update = 98,                    /* update  */
  YYSYMBOL_select = 99,                    /* select  */
  YYSYMBOL_join = 100,                     /* join  */
  YYSYMBOL_aggregate_attr = 101,           /* aggregate_attr  */
  YYSYMBOL_aggregate_list = 102,           /* aggregate_list  */
  YYSYMBOL_count_attr = 103,               /* count_attr  */
  YYSYMBOL_select_attr = 104,              /* select_attr  */
  YYSYMBOL_attr_list = 105,                /* attr_list  */
  YYSYMBOL_rel_list = 106,                 /* rel_list  */
  YYSYMBOL_order = 107,                    /* order  */
  YYSYMBOL_order_list = 108,               /* order_list  */
  YYSYMBOL_orderby = 109,                  /* orderby  */
  YYSYMBOL_direction = 110,                /* direction  */
  YYSYMBOL_group = 111,                    /* group  */
  YYSYMBOL_groupby = 112,                  /* groupby  */
  YYSYMBOL_group_list = 113,               /* group_list  */
  YYSYMBOL_where = 114,                    /* where  */
  YYSYMBOL_condition_list = 115,           /* condition_list  */
  YYSYMBOL_condition = 116,                /* condition  */
  YYSYMBOL_subselect = 117,                /* subselect  */
  YYSYMBOL_subselect_attr = 118,           /* subselect_attr  */
  YYSYMBOL_subaggregate_attr = 119,        /* subaggregate_attr  */
  YYSYMBOL_subaggregate_list = 120,        /* subaggregate_list  */
  YYSYMBOL_subcount_attr = 121,            /* subcount_attr  */
  YYSYMBOL_subattr_list = 122,             /* subattr_list  */
  YYSYMBOL_subrel_list = 123,              /* subrel_list  */
  YYSYMBOL_comOp = 124,                    /* comOp  */
  YYSYMBOL_load_data = 125                 /* load_data  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   161,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   185,   190,   195,   201,   207,   213,   219,   225,   231,
     238,   244,   252,   254,   260,   267,   276,   278,   282,   293,
     306,   307,   308,   311,   314,   315,   316,   317,   318,   321,
     330,   347,   349,   355,   357,   362,   365,   368,   372,   376,
     382,   392,   402,   418,   420,   424,   430,   436,   442,   445,
     451,   457,   465,   467,   473,   479,   485,   488,   494,   500,
     508,   513,   518,   525,   530,   535,   540,   545,   548,   550,
     557,   564,   573,   575,   579,   581,   585,   587,   591,   593,
     598,   606,   609,   612,   616,   618,   622,   624,   629,   635,
     637,   642,   648,   650,   654,   656,   661,   682,   702,   722,
     744,   765,   786,   805,   813,   821,   829,   837,   845,   853,
     864,   877,   883,   889,   895,   901,   906,   913,   920,   927,
     931,   938,   945,   954,   956,   962,   968,   974,   977,   983,
     989,   997,  1002,  1007,  1012,  1017,  1019,  1024,  1029,  1036,
    1038,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1053
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
  "AVG", "DESC", "ASC", "ORDERBY", "GROUPBY", "INNERJOIN", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "IN", "NOTIN", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE",
  "GE", "NE", "NUMBER", "FLOAT", "DATE", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "AGGOP", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "desc_table", "create_index", "index_list", "drop_index", "create_table",
  "attr_def_list", "attr_def", "is_nullable", "number", "type", "ID_get",
  "insert", "multi_values", "value_list", "value", "delete", "update",
  "select", "join", "aggregate_attr", "aggregate_list", "count_attr",
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

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
#endif

#define YYPACT_NINF (-331)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -331,   200,  -331,    51,   104,   147,   -25,    33,    64,    27,
      39,    44,   132,   136,   153,   172,   181,    87,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,   126,   128,   191,   155,
     166,   183,   201,   202,   212,    26,  -331,  -331,   204,   244,
     253,  -331,   192,   193,   210,  -331,  -331,  -331,  -331,  -331,
     205,   230,   213,   197,   261,   262,   206,   207,   186,   208,
     209,   -26,  -331,   211,  -331,  -331,   221,   222,   214,   215,
     216,   218,   217,  -331,  -331,   -14,     0,  -331,  -331,  -331,
     236,     1,    59,   237,   237,   242,   246,    10,   275,   224,
     240,  -331,   252,   164,   255,   223,   254,   225,   254,   226,
     254,   254,   227,    49,  -331,  -331,  -331,   228,   264,    69,
    -331,   278,  -331,  -331,  -331,    94,  -331,   102,   247,   102,
    -331,    69,   284,   216,   265,  -331,  -331,  -331,  -331,  -331,
      22,   233,   268,   160,  -331,   269,  -331,   270,  -331,  -331,
     271,   237,   237,   242,   235,   222,   272,   154,  -331,  -331,
     239,   276,   276,  -331,  -331,  -331,  -331,  -331,  -331,    48,
      63,    10,  -331,   241,   222,   243,   252,   306,  -331,  -331,
     248,  -331,   279,   249,   280,   282,   285,   286,   254,   254,
     254,  -331,  -331,  -331,   273,   292,    69,   287,   289,   290,
     291,   293,   149,  -331,   281,  -331,   138,  -331,  -331,  -331,
    -331,  -331,   283,  -331,   247,  -331,   315,   322,  -331,  -331,
    -331,   296,   266,   297,   279,   267,   274,   186,   277,  -331,
    -331,  -331,    10,   288,   309,   272,   301,   294,   295,   187,
     298,   299,    75,  -331,   300,   276,   276,    57,   302,  -331,
    -331,  -331,   139,   279,   327,   303,     2,     5,   304,     6,
     247,    14,   305,   307,   334,  -331,   310,   337,    15,    58,
    -331,   308,  -331,   311,    91,   174,   312,   312,   313,  -331,
    -331,   314,  -331,  -331,  -331,  -331,  -331,  -331,   341,   254,
     316,   254,   317,   254,   254,   318,   264,  -331,  -331,   319,
    -331,   288,  -331,   175,  -331,  -331,    69,  -331,   321,   320,
     321,   323,   324,   321,   321,   325,   141,  -331,  -331,  -331,
     326,   222,   328,  -331,  -331,   329,  -331,   330,  -331,  -331,
     336,  -331,   203,   305,   331,   332,  -331,   272,   220,  -331,
     338,  -331,   339,  -331,  -331,  -331,   342,   312,   312,   313,
     309,  -331,   254,   254,   254,  -331,  -331,   180,   333,   343,
     345,   346,   347,   348,   321,   321,   321,  -331,  -331,  -331,
     354,  -331,  -331,  -331,   335,  -331,  -331,   301,   340,   344,
     187,   349,  -331,  -331,  -331,  -331,   333,  -331,   106,   125,
     355,   144,  -331,   321,   350,   321,   351,   321,   321,   352,
    -331,   360,  -331,   362,  -331,  -331,   363,   321,   321,   321,
    -331,  -331,  -331
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
       0,     0,     0,     0,     0,    88,    83,    87,     0,     0,
       0,    23,     0,     0,     0,    24,    25,    26,    22,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,    29,    28,     0,   112,     0,     0,
       0,     0,     0,    27,    34,     0,     0,    82,    80,    81,
       0,     0,    88,    88,    88,    92,     0,     0,     0,     0,
       0,    49,    36,     0,     0,     0,    72,     0,    72,     0,
      72,    72,     0,     0,    89,    86,    84,     0,    63,     0,
      59,     0,    55,    56,    58,     0,    57,     0,   114,     0,
      60,     0,     0,     0,     0,    48,    44,    45,    46,    47,
      40,     0,     0,     0,    65,     0,    66,     0,    68,    67,
       0,    88,    88,    92,     0,   112,    53,     0,   167,   168,
       0,     0,     0,   161,   162,   163,   164,   165,   166,     0,
       0,     0,   113,     0,   112,     0,    36,     0,    42,    41,
       0,    39,    32,     0,     0,     0,     0,     0,    72,    72,
      72,    90,    91,    93,     0,    94,     0,     0,     0,     0,
       0,     0,   155,   131,     0,   135,     0,   126,   128,   118,
     116,   123,   119,   117,   114,   124,     0,     0,    37,    35,
      43,     0,     0,     0,    32,     0,     0,     0,     0,    69,
      70,    71,     0,    98,   104,    53,    51,     0,     0,     0,
       0,     0,     0,   133,     0,     0,     0,     0,     0,   115,
      61,   169,    40,    32,     0,     0,     0,     0,     0,     0,
     114,   103,    96,   106,     0,    54,     0,     0,     0,     0,
     154,   151,   153,     0,     0,   155,   155,   155,   159,   127,
     129,     0,   120,   125,   121,    38,    33,    31,     0,    72,
       0,    72,     0,    72,    72,     0,    63,   102,   101,     0,
      99,    98,    95,   109,   105,    62,     0,    50,   143,     0,
     143,     0,     0,   143,   143,     0,     0,   156,   134,   132,
       0,   112,     0,    30,    73,     0,    74,     0,    76,    75,
       0,    64,   103,    96,     0,     0,   107,    53,     0,   136,
       0,   137,     0,   152,   139,   138,     0,   155,   155,   159,
     104,   122,    72,    72,    72,   100,    97,   109,   109,     0,
       0,     0,     0,     0,   143,   143,   143,   157,   158,   160,
       0,    77,    78,    79,     0,   110,   108,    51,     0,     0,
       0,     0,   140,   141,   142,   130,   109,    52,     0,     0,
       0,     0,   111,   143,     0,   143,     0,   143,   143,     0,
     144,     0,   145,     0,   147,   146,     0,   143,   143,   143,
     148,   149,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,  -203,  -331,  -331,   171,   219,    96,  -331,
    -331,  -331,  -331,   -28,  -230,  -118,  -331,  -331,  -331,    54,
    -331,  -108,   129,  -331,   -68,   245,  -331,    25,    68,    23,
      30,  -331,  -330,  -151,  -206,  -164,  -150,  -331,  -331,  -304,
      -7,  -261,    50,  -107,  -331
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   223,    29,    30,   134,   102,   181,   221,
     140,   103,    31,   267,   197,   127,    32,    33,    34,   155,
      47,   144,    90,    48,    72,   118,   234,   302,   262,   300,
     264,   304,   336,    98,   172,   128,   129,   204,   205,   339,
     273,   243,   321,   169,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,   156,   148,   149,   195,   265,   341,   214,   249,   344,
     345,   207,   208,   174,   317,   318,   319,   120,   106,   211,
     170,   255,   173,   216,   114,   115,   116,   375,   376,   107,
     178,   179,   108,   111,   289,   297,   298,   291,   294,    93,
      49,   121,    94,   109,   112,   290,    50,   308,   292,   295,
     286,   210,   213,   180,   296,   120,   392,   299,   309,    70,
     382,   383,   384,    36,   120,    37,    38,    51,   260,    71,
     120,    52,   122,   123,   124,   125,   120,   126,   235,   121,
     229,   230,   231,   191,   192,    53,   367,   368,   121,   400,
     310,   402,    70,   404,   405,   279,   280,   283,   158,   247,
     159,   311,   113,   410,   411,   412,   158,   359,   159,    54,
     122,   123,   124,   209,   151,   126,    39,   152,    40,   122,
     123,   124,   281,   314,   126,   122,   123,   124,   212,   282,
     126,   122,   123,   124,   315,    55,   126,   160,   393,    56,
     276,    60,   158,   277,   159,   161,   162,   178,   179,   394,
     163,   164,   165,   166,   167,   168,    57,   395,   163,   164,
     165,   166,   167,   168,    41,    42,    43,    44,   396,   135,
     350,   198,   199,   200,   201,    58,   398,   184,   185,   186,
     187,   324,   241,   326,    59,   328,   329,   399,   337,   245,
     246,    61,   242,    62,   163,   164,   165,   166,   167,   168,
       2,   136,   137,   138,   139,    63,   347,   241,   334,   348,
       3,     4,    45,   334,    66,    46,     5,   316,   335,   202,
      64,     6,   203,   374,   297,   298,     7,     8,     9,    10,
      11,    65,    67,    68,    12,    13,    14,   360,   361,   362,
     363,    15,    16,    69,   371,   372,   373,    74,    87,   270,
      73,    88,   271,    17,    89,   272,    75,    76,    77,    78,
      79,    80,    82,    81,    83,    84,    96,   105,   110,    97,
      70,    85,    86,    91,    92,   117,    95,   119,   130,    99,
     131,   101,   100,   104,   132,   133,   141,   143,   142,   154,
     145,   147,   150,   153,   157,   171,   175,   177,   182,   183,
     194,   188,   189,   190,   206,   196,   215,   121,   217,   219,
     220,   225,   222,   226,   224,   233,   227,   228,   250,   236,
     237,   238,   239,   232,   240,   251,   248,   244,   252,   254,
     287,   253,   256,   263,   266,   288,   293,   305,   301,   257,
     307,   306,   259,   313,   323,   241,   320,   218,   285,   387,
     331,   312,   176,   261,   338,   355,   258,   322,   356,   268,
     269,   352,   353,   274,   275,   278,   334,   284,   354,   333,
     364,   365,   303,   390,   366,   377,   378,   379,   380,   381,
     370,   325,   327,   330,   332,   340,   385,   397,   342,   343,
     346,   349,   407,   351,   408,   409,   357,   358,   193,   369,
     386,     0,     0,     0,     0,   388,     0,     0,     0,   389,
       0,     0,     0,     0,   391,   401,   403,   406
};

static const yytype_int16 yycheck[] =
{
     108,   119,   110,   111,   155,   235,   310,   171,   214,   313,
     314,   161,   162,   131,   275,   276,   277,     7,    32,   169,
     127,   224,   129,   174,    92,    93,    94,   357,   358,    43,
       8,     9,    32,    32,    32,    21,    22,    32,    32,    65,
      65,    31,    68,    43,    43,    43,    13,    32,    43,    43,
     253,   169,   170,    31,   260,     7,   386,    43,    43,    33,
     364,   365,   366,    12,     7,    14,    15,     3,   232,    43,
       7,    44,    62,    63,    64,    65,     7,    67,   196,    31,
     188,   189,   190,   151,   152,    46,   347,   348,    31,   393,
      32,   395,    33,   397,   398,   245,   246,   247,     4,   206,
       6,    43,    43,   407,   408,   409,     4,   337,     6,    65,
      62,    63,    64,    65,    65,    67,    12,    68,    14,    62,
      63,    64,    65,    32,    67,    62,    63,    64,    65,   247,
      67,    62,    63,    64,    43,     3,    67,    43,    32,     3,
      65,    54,     4,    68,     6,    51,    52,     8,     9,    43,
      56,    57,    58,    59,    60,    61,     3,    32,    56,    57,
      58,    59,    60,    61,    17,    18,    19,    20,    43,     5,
     321,    17,    18,    19,    20,     3,    32,    17,    18,    19,
      20,   289,    33,   291,     3,   293,   294,    43,   306,    51,
      52,    65,    43,    65,    56,    57,    58,    59,    60,    61,
       0,    37,    38,    39,    40,    14,    65,    33,    33,    68,
      10,    11,    65,    33,    31,    68,    16,    43,    43,    65,
      65,    21,    68,    43,    21,    22,    26,    27,    28,    29,
      30,    65,    31,    31,    34,    35,    36,    17,    18,    19,
      20,    41,    42,    31,   352,   353,   354,     3,    62,    62,
      46,    65,    65,    53,    68,    68,     3,    65,    65,    49,
      55,    31,    65,    50,     3,     3,    45,    50,    32,    47,
      33,    65,    65,    65,    65,    33,    65,    31,     3,    65,
      56,    65,    67,    65,    44,    33,    31,    33,    65,    25,
      65,    65,    65,    65,    16,    48,    12,    32,    65,    31,
      65,    32,    32,    32,    65,    33,    65,    31,    65,     3,
      62,    31,    33,    31,    65,    23,    31,    31,     3,    32,
      31,    31,    31,    50,    31,     3,    43,    46,    32,    32,
       3,    65,    65,    24,    33,    32,    32,     3,    33,    65,
       3,    31,    65,    32,     3,    33,    33,   176,   252,   377,
     296,    43,   133,    65,    33,   332,   227,    43,   333,    65,
      65,    32,    32,    65,    65,    65,    33,    65,    32,   301,
      32,    32,    65,   380,    32,    32,    31,    31,    31,    31,
     350,    65,    65,    65,    65,    65,    32,    32,    65,    65,
      65,    65,    32,    65,    32,    32,    65,    65,   153,   349,
      65,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    65,    65,    65,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,     0,    10,    11,    16,    21,    26,    27,    28,
      29,    30,    34,    35,    36,    41,    42,    53,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    85,
      86,    93,    97,    98,    99,   125,    12,    14,    15,    12,
      14,    17,    18,    19,    20,    65,    68,   101,   104,    65,
      13,     3,    44,    46,    65,     3,     3,     3,     3,     3,
      54,    65,    65,    14,    65,    65,    31,    31,    31,    31,
      33,    43,   105,    46,     3,     3,    65,    65,    49,    55,
      31,    50,    65,     3,     3,    65,    65,    62,    65,    68,
     103,    65,    65,    65,    68,    65,    45,    47,   114,    65,
      67,    65,    88,    92,    65,    50,    32,    43,    32,    43,
      32,    32,    43,    43,   105,   105,   105,    33,   106,    31,
       7,    31,    62,    63,    64,    65,    67,    96,   116,   117,
       3,    56,    44,    33,    87,     5,    37,    38,    39,    40,
      91,    31,    65,    33,   102,    65,   102,    65,   102,   102,
      65,    65,    68,    65,    25,   100,    96,    16,     4,     6,
      43,    51,    52,    56,    57,    58,    59,    60,    61,   124,
     124,    48,   115,   124,    96,    12,    88,    32,     8,     9,
      31,    89,    65,    31,    17,    18,    19,    20,    32,    32,
      32,   105,   105,   106,    65,   114,    33,    95,    17,    18,
      19,    20,    65,    68,   118,   119,    65,   117,   117,    65,
      96,   117,    65,    96,   116,    65,   114,    65,    87,     3,
      62,    90,    33,    84,    65,    31,    31,    31,    31,   102,
     102,   102,    50,    23,   107,    96,    32,    31,    31,    31,
      31,    33,    43,   122,    46,    51,    52,   124,    43,   115,
       3,     3,    32,    65,    32,    84,    65,    65,   103,    65,
     116,    65,   109,    24,   111,    95,    33,    94,    65,    65,
      62,    65,    68,   121,    65,    65,    65,    68,    65,   117,
     117,    65,    96,   117,    65,    89,    84,     3,    32,    32,
      43,    32,    43,    32,    32,    43,   115,    21,    22,    43,
     110,    33,   108,    65,   112,     3,    31,     3,    32,    43,
      32,    43,    43,    32,    32,    43,    43,   122,   122,   122,
      33,   123,    43,     3,   102,    65,   102,    65,   102,   102,
      65,   100,    65,   109,    33,    43,   113,    96,    33,   120,
      65,   120,    65,    65,   120,   120,    65,    65,    68,    65,
     114,    65,    32,    32,    32,   110,   108,    65,    65,    95,
      17,    18,    19,    20,    32,    32,    32,   122,   122,   123,
     111,   102,   102,   102,    43,   113,   113,    32,    31,    31,
      31,    31,   120,   120,   120,    32,    65,    94,    65,    65,
     121,    65,   113,    32,    43,    32,    43,    32,    32,    43,
     120,    65,   120,    65,   120,   120,    65,    32,    32,    32,
     120,   120,   120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    83,    84,    84,    85,    86,    87,    87,    88,    88,
      89,    89,    89,    90,    91,    91,    91,    91,    91,    92,
      93,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      97,    98,    99,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   110,   110,   110,   111,   111,   112,   112,   112,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   118,   118,   118,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   121,   121,   121,   121,   122,   122,   122,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
      11,    10,     0,     3,     4,     8,     0,     3,     6,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      10,     0,     6,     0,     3,     1,     1,     1,     1,     1,
       5,     8,    10,     0,     6,     5,     5,     5,     5,     7,
       7,     7,     0,     6,     6,     6,     6,     8,     8,     8,
       1,     1,     1,     1,     4,     2,     4,     1,     0,     3,
       5,     5,     0,     3,     0,     3,     0,     3,     0,     2,
       4,     1,     1,     0,     0,     2,     0,     2,     4,     0,
       3,     5,     0,     3,     0,     3,     3,     3,     3,     3,
       5,     5,     7,     3,     3,     5,     3,     5,     3,     5,
       9,     1,     4,     2,     4,     1,     5,     5,     5,     5,
       7,     7,     7,     0,     6,     6,     6,     6,     8,     8,
       8,     1,     3,     1,     1,     0,     3,     5,     5,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
#line 185 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1544 "yacc_sql.tab.c"
    break;

  case 22: /* help: HELP SEMICOLON  */
#line 190 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1552 "yacc_sql.tab.c"
    break;

  case 23: /* sync: SYNC SEMICOLON  */
#line 195 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1560 "yacc_sql.tab.c"
    break;

  case 24: /* begin: TRX_BEGIN SEMICOLON  */
#line 201 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1568 "yacc_sql.tab.c"
    break;

  case 25: /* commit: TRX_COMMIT SEMICOLON  */
#line 207 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1576 "yacc_sql.tab.c"
    break;

  case 26: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 213 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1584 "yacc_sql.tab.c"
    break;

  case 27: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 219 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1593 "yacc_sql.tab.c"
    break;

  case 28: /* show_tables: SHOW TABLES SEMICOLON  */
#line 225 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1601 "yacc_sql.tab.c"
    break;

  case 29: /* desc_table: DESC ID SEMICOLON  */
#line 231 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1610 "yacc_sql.tab.c"
    break;

  case 30: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID index_list RBRACE SEMICOLON  */
#line 239 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
			add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
		}
#line 1620 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_list RBRACE SEMICOLON  */
#line 245 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
			add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
		}
#line 1630 "yacc_sql.tab.c"
    break;

  case 33: /* index_list: COMMA ID index_list  */
#line 254 "yacc_sql.y"
                         {
  		add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
	}
#line 1638 "yacc_sql.tab.c"
    break;

  case 34: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 261 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1647 "yacc_sql.tab.c"
    break;

  case 35: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 268 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1659 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 278 "yacc_sql.y"
                                  {    }
#line 1665 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID_get type LBRACE number RBRACE is_nullable  */
#line 283 "yacc_sql.y"
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
#line 1680 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def: ID_get type is_nullable  */
#line 294 "yacc_sql.y"
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
#line 1695 "yacc_sql.tab.c"
    break;

  case 40: /* is_nullable: %empty  */
#line 306 "yacc_sql.y"
        {(yyval.number) = 0;}
#line 1701 "yacc_sql.tab.c"
    break;

  case 41: /* is_nullable: NOTNULL  */
#line 307 "yacc_sql.y"
                  {(yyval.number) = 0;}
#line 1707 "yacc_sql.tab.c"
    break;

  case 42: /* is_nullable: NULLABLE  */
#line 308 "yacc_sql.y"
                   {(yyval.number) = 1;}
#line 1713 "yacc_sql.tab.c"
    break;

  case 43: /* number: NUMBER  */
#line 311 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1719 "yacc_sql.tab.c"
    break;

  case 44: /* type: INT_T  */
#line 314 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1725 "yacc_sql.tab.c"
    break;

  case 45: /* type: STRING_T  */
#line 315 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1731 "yacc_sql.tab.c"
    break;

  case 46: /* type: FLOAT_T  */
#line 316 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1737 "yacc_sql.tab.c"
    break;

  case 47: /* type: DATE_T  */
#line 317 "yacc_sql.y"
                {(yyval.number)=DATES; }
#line 1743 "yacc_sql.tab.c"
    break;

  case 48: /* type: TEXT_T  */
#line 318 "yacc_sql.y"
                {(yyval.number)=TEXTS; }
#line 1749 "yacc_sql.tab.c"
    break;

  case 49: /* ID_get: ID  */
#line 322 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1758 "yacc_sql.tab.c"
    break;

  case 50: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE multi_values SEMICOLON  */
#line 331 "yacc_sql.y"
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
#line 1778 "yacc_sql.tab.c"
    break;

  case 52: /* multi_values: COMMA LBRACE value value_list RBRACE multi_values  */
#line 349 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$3;
  		CONTEXT->insert_num++;
	  }
#line 1787 "yacc_sql.tab.c"
    break;

  case 54: /* value_list: COMMA value value_list  */
#line 357 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1795 "yacc_sql.tab.c"
    break;

  case 55: /* value: NUMBER  */
#line 362 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1803 "yacc_sql.tab.c"
    break;

  case 56: /* value: FLOAT  */
#line 365 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1811 "yacc_sql.tab.c"
    break;

  case 57: /* value: SSS  */
#line 368 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1820 "yacc_sql.tab.c"
    break;

  case 58: /* value: DATE  */
#line 372 "yacc_sql.y"
          {
    			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1829 "yacc_sql.tab.c"
    break;

  case 59: /* value: ANULL  */
#line 376 "yacc_sql.y"
          {
    		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1837 "yacc_sql.tab.c"
    break;

  case 60: /* delete: DELETE FROM ID where SEMICOLON  */
#line 383 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1849 "yacc_sql.tab.c"
    break;

  case 61: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 393 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1861 "yacc_sql.tab.c"
    break;

  case 62: /* select: SELECT select_attr FROM ID rel_list join where order group SEMICOLON  */
#line 403 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-6].string));
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
#line 1881 "yacc_sql.tab.c"
    break;

  case 64: /* join: INNERJOIN ID ON condition condition_list join  */
#line 420 "yacc_sql.y"
                                                   {
    	selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
    }
#line 1889 "yacc_sql.tab.c"
    break;

  case 65: /* aggregate_attr: MAX LBRACE ID RBRACE aggregate_list  */
#line 424 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1900 "yacc_sql.tab.c"
    break;

  case 66: /* aggregate_attr: MIN LBRACE ID RBRACE aggregate_list  */
#line 430 "yacc_sql.y"
                                          {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1911 "yacc_sql.tab.c"
    break;

  case 67: /* aggregate_attr: AVG LBRACE ID RBRACE aggregate_list  */
#line 436 "yacc_sql.y"
                                          {
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1922 "yacc_sql.tab.c"
    break;

  case 68: /* aggregate_attr: COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 442 "yacc_sql.y"
                                                    {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1930 "yacc_sql.tab.c"
    break;

  case 69: /* aggregate_attr: MAX LBRACE ID DOT ID RBRACE aggregate_list  */
#line 445 "yacc_sql.y"
                                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1941 "yacc_sql.tab.c"
    break;

  case 70: /* aggregate_attr: MIN LBRACE ID DOT ID RBRACE aggregate_list  */
#line 451 "yacc_sql.y"
                                                 {
    			RelAttr attr;
    			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1952 "yacc_sql.tab.c"
    break;

  case 71: /* aggregate_attr: AVG LBRACE ID DOT ID RBRACE aggregate_list  */
#line 457 "yacc_sql.y"
                                                 {
        		RelAttr attr;
        		relation_attr_init(&attr,(yyvsp[-4].string), (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1963 "yacc_sql.tab.c"
    break;

  case 73: /* aggregate_list: COMMA MAX LBRACE ID RBRACE aggregate_list  */
#line 467 "yacc_sql.y"
                                                {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1974 "yacc_sql.tab.c"
    break;

  case 74: /* aggregate_list: COMMA MIN LBRACE ID RBRACE aggregate_list  */
#line 473 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1985 "yacc_sql.tab.c"
    break;

  case 75: /* aggregate_list: COMMA AVG LBRACE ID RBRACE aggregate_list  */
#line 479 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1996 "yacc_sql.tab.c"
    break;

  case 76: /* aggregate_list: COMMA COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 485 "yacc_sql.y"
                                                          {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 2004 "yacc_sql.tab.c"
    break;

  case 77: /* aggregate_list: COMMA MAX LBRACE ID DOT ID RBRACE aggregate_list  */
#line 488 "yacc_sql.y"
                                                       {
            		RelAttr attr;
            		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 2015 "yacc_sql.tab.c"
    break;

  case 78: /* aggregate_list: COMMA MIN LBRACE ID DOT ID RBRACE aggregate_list  */
#line 494 "yacc_sql.y"
                                                       {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 2026 "yacc_sql.tab.c"
    break;

  case 79: /* aggregate_list: COMMA AVG LBRACE ID DOT ID RBRACE aggregate_list  */
#line 500 "yacc_sql.y"
                                                       {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 2037 "yacc_sql.tab.c"
    break;

  case 80: /* count_attr: ID  */
#line 508 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2047 "yacc_sql.tab.c"
    break;

  case 81: /* count_attr: STAR  */
#line 513 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 2057 "yacc_sql.tab.c"
    break;

  case 82: /* count_attr: NUMBER  */
#line 518 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2067 "yacc_sql.tab.c"
    break;

  case 83: /* select_attr: STAR  */
#line 525 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2077 "yacc_sql.tab.c"
    break;

  case 84: /* select_attr: ID DOT STAR attr_list  */
#line 530 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2087 "yacc_sql.tab.c"
    break;

  case 85: /* select_attr: ID attr_list  */
#line 535 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2097 "yacc_sql.tab.c"
    break;

  case 86: /* select_attr: ID DOT ID attr_list  */
#line 540 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2107 "yacc_sql.tab.c"
    break;

  case 87: /* select_attr: aggregate_attr  */
#line 545 "yacc_sql.y"
                     {
    }
#line 2114 "yacc_sql.tab.c"
    break;

  case 89: /* attr_list: COMMA ID attr_list  */
#line 550 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2126 "yacc_sql.tab.c"
    break;

  case 90: /* attr_list: COMMA ID DOT ID attr_list  */
#line 557 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2138 "yacc_sql.tab.c"
    break;

  case 91: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 564 "yacc_sql.y"
                                  {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
    }
#line 2150 "yacc_sql.tab.c"
    break;

  case 93: /* rel_list: COMMA ID rel_list  */
#line 575 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2158 "yacc_sql.tab.c"
    break;

  case 95: /* order: ORDERBY orderby order_list  */
#line 581 "yacc_sql.y"
                                 {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2166 "yacc_sql.tab.c"
    break;

  case 97: /* order_list: COMMA orderby order_list  */
#line 587 "yacc_sql.y"
                              {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2174 "yacc_sql.tab.c"
    break;

  case 99: /* orderby: ID direction  */
#line 593 "yacc_sql.y"
              {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,NULL,(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2184 "yacc_sql.tab.c"
    break;

  case 100: /* orderby: ID DOT ID direction  */
#line 598 "yacc_sql.y"
                                     {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,(yyvsp[-3].string),(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2194 "yacc_sql.tab.c"
    break;

  case 101: /* direction: ASC  */
#line 606 "yacc_sql.y"
        {
    		CONTEXT->orderDirect = ORASC;
    			}
#line 2202 "yacc_sql.tab.c"
    break;

  case 102: /* direction: DESC  */
#line 609 "yacc_sql.y"
           {
		CONTEXT->orderDirect = ORDESC;
			}
#line 2210 "yacc_sql.tab.c"
    break;

  case 103: /* direction: %empty  */
#line 612 "yacc_sql.y"
      {
    		CONTEXT->orderDirect = ORASC;
    }
#line 2218 "yacc_sql.tab.c"
    break;

  case 105: /* group: GROUPBY groupby  */
#line 618 "yacc_sql.y"
                      {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
}
#line 2226 "yacc_sql.tab.c"
    break;

  case 107: /* groupby: ID group_list  */
#line 624 "yacc_sql.y"
               {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2236 "yacc_sql.tab.c"
    break;

  case 108: /* groupby: ID DOT ID group_list  */
#line 629 "yacc_sql.y"
                      {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2246 "yacc_sql.tab.c"
    break;

  case 110: /* group_list: COMMA ID group_list  */
#line 637 "yacc_sql.y"
                     {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2256 "yacc_sql.tab.c"
    break;

  case 111: /* group_list: COMMA ID DOT ID group_list  */
#line 642 "yacc_sql.y"
                            {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2266 "yacc_sql.tab.c"
    break;

  case 113: /* where: WHERE condition condition_list  */
#line 650 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2274 "yacc_sql.tab.c"
    break;

  case 115: /* condition_list: AND condition condition_list  */
#line 656 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2282 "yacc_sql.tab.c"
    break;

  case 116: /* condition: ID comOp value  */
#line 662 "yacc_sql.y"
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
#line 2307 "yacc_sql.tab.c"
    break;

  case 117: /* condition: value comOp value  */
#line 683 "yacc_sql.y"
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
#line 2331 "yacc_sql.tab.c"
    break;

  case 118: /* condition: ID comOp ID  */
#line 703 "yacc_sql.y"
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
#line 2355 "yacc_sql.tab.c"
    break;

  case 119: /* condition: value comOp ID  */
#line 723 "yacc_sql.y"
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
#line 2381 "yacc_sql.tab.c"
    break;

  case 120: /* condition: ID DOT ID comOp value  */
#line 745 "yacc_sql.y"
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
#line 2406 "yacc_sql.tab.c"
    break;

  case 121: /* condition: value comOp ID DOT ID  */
#line 766 "yacc_sql.y"
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
#line 2431 "yacc_sql.tab.c"
    break;

  case 122: /* condition: ID DOT ID comOp ID DOT ID  */
#line 787 "yacc_sql.y"
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
#line 2454 "yacc_sql.tab.c"
    break;

  case 123: /* condition: ID comOp subselect  */
#line 805 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2467 "yacc_sql.tab.c"
    break;

  case 124: /* condition: subselect comOp ID  */
#line 813 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2480 "yacc_sql.tab.c"
    break;

  case 125: /* condition: ID DOT ID comOp subselect  */
#line 821 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2493 "yacc_sql.tab.c"
    break;

  case 126: /* condition: ID IN subselect  */
#line 829 "yacc_sql.y"
                      {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2506 "yacc_sql.tab.c"
    break;

  case 127: /* condition: ID DOT ID IN subselect  */
#line 837 "yacc_sql.y"
                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2519 "yacc_sql.tab.c"
    break;

  case 128: /* condition: ID NOTIN subselect  */
#line 845 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2532 "yacc_sql.tab.c"
    break;

  case 129: /* condition: ID DOT ID NOTIN subselect  */
#line 853 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2545 "yacc_sql.tab.c"
    break;

  case 130: /* subselect: LBRACE SELECT subselect_attr FROM ID subrel_list where group RBRACE  */
#line 865 "yacc_sql.y"
                {

			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-4].string));
			selects_append_conditions(CONTEXT->ssql->sstr.selection.subSelect, CONTEXT->conditions, CONTEXT->condition_length);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2560 "yacc_sql.tab.c"
    break;

  case 131: /* subselect_attr: STAR  */
#line 877 "yacc_sql.y"
         {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2571 "yacc_sql.tab.c"
    break;

  case 132: /* subselect_attr: ID DOT STAR subattr_list  */
#line 883 "yacc_sql.y"
                               {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2582 "yacc_sql.tab.c"
    break;

  case 133: /* subselect_attr: ID subattr_list  */
#line 889 "yacc_sql.y"
                      {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2593 "yacc_sql.tab.c"
    break;

  case 134: /* subselect_attr: ID DOT ID subattr_list  */
#line 895 "yacc_sql.y"
                                 {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
	}
#line 2604 "yacc_sql.tab.c"
    break;

  case 135: /* subselect_attr: subaggregate_attr  */
#line 901 "yacc_sql.y"
                        {
    }
#line 2611 "yacc_sql.tab.c"
    break;

  case 136: /* subaggregate_attr: MAX LBRACE ID RBRACE subaggregate_list  */
#line 906 "yacc_sql.y"
                                           {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2623 "yacc_sql.tab.c"
    break;

  case 137: /* subaggregate_attr: MIN LBRACE ID RBRACE subaggregate_list  */
#line 913 "yacc_sql.y"
                                             {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2635 "yacc_sql.tab.c"
    break;

  case 138: /* subaggregate_attr: AVG LBRACE ID RBRACE subaggregate_list  */
#line 920 "yacc_sql.y"
                                             {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2647 "yacc_sql.tab.c"
    break;

  case 139: /* subaggregate_attr: COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 927 "yacc_sql.y"
                                                          {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2656 "yacc_sql.tab.c"
    break;

  case 140: /* subaggregate_attr: MAX LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 931 "yacc_sql.y"
                                                    {
          sub_selects_init(&CONTEXT->ssql->sstr.selection);
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
          			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
          }
#line 2668 "yacc_sql.tab.c"
    break;

  case 141: /* subaggregate_attr: MIN LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 938 "yacc_sql.y"
                                                    {
	  sub_selects_init(&CONTEXT->ssql->sstr.selection);
				RelAttr attr;
				relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
				selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
				selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
	  }
#line 2680 "yacc_sql.tab.c"
    break;

  case 142: /* subaggregate_attr: AVG LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 945 "yacc_sql.y"
                                                    {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
				selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
	}
#line 2692 "yacc_sql.tab.c"
    break;

  case 144: /* subaggregate_list: COMMA MAX LBRACE ID RBRACE subaggregate_list  */
#line 956 "yacc_sql.y"
                                                   {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2703 "yacc_sql.tab.c"
    break;

  case 145: /* subaggregate_list: COMMA MIN LBRACE ID RBRACE subaggregate_list  */
#line 962 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2714 "yacc_sql.tab.c"
    break;

  case 146: /* subaggregate_list: COMMA AVG LBRACE ID RBRACE subaggregate_list  */
#line 968 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2725 "yacc_sql.tab.c"
    break;

  case 147: /* subaggregate_list: COMMA COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 974 "yacc_sql.y"
                                                                {
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2733 "yacc_sql.tab.c"
    break;

  case 148: /* subaggregate_list: COMMA MAX LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 977 "yacc_sql.y"
                                                          {
            		RelAttr attr;
            		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2744 "yacc_sql.tab.c"
    break;

  case 149: /* subaggregate_list: COMMA MIN LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 983 "yacc_sql.y"
                                                          {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2755 "yacc_sql.tab.c"
    break;

  case 150: /* subaggregate_list: COMMA AVG LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 989 "yacc_sql.y"
                                                          {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2766 "yacc_sql.tab.c"
    break;

  case 151: /* subcount_attr: ID  */
#line 997 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2776 "yacc_sql.tab.c"
    break;

  case 152: /* subcount_attr: ID DOT ID  */
#line 1002 "yacc_sql.y"
               {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2786 "yacc_sql.tab.c"
    break;

  case 153: /* subcount_attr: STAR  */
#line 1007 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
        }
#line 2796 "yacc_sql.tab.c"
    break;

  case 154: /* subcount_attr: NUMBER  */
#line 1012 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2806 "yacc_sql.tab.c"
    break;

  case 156: /* subattr_list: COMMA ID subattr_list  */
#line 1019 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
      }
#line 2816 "yacc_sql.tab.c"
    break;

  case 157: /* subattr_list: COMMA ID DOT ID subattr_list  */
#line 1024 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
  	  }
#line 2826 "yacc_sql.tab.c"
    break;

  case 158: /* subattr_list: COMMA ID DOT STAR subattr_list  */
#line 1029 "yacc_sql.y"
                                     {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2836 "yacc_sql.tab.c"
    break;

  case 160: /* subrel_list: COMMA ID subrel_list  */
#line 1038 "yacc_sql.y"
                           {
			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-1].string));
}
#line 2844 "yacc_sql.tab.c"
    break;

  case 161: /* comOp: EQ  */
#line 1042 "yacc_sql.y"
         { CONTEXT->comp = EQUAL_TO; }
#line 2850 "yacc_sql.tab.c"
    break;

  case 162: /* comOp: LT  */
#line 1043 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2856 "yacc_sql.tab.c"
    break;

  case 163: /* comOp: GT  */
#line 1044 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2862 "yacc_sql.tab.c"
    break;

  case 164: /* comOp: LE  */
#line 1045 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2868 "yacc_sql.tab.c"
    break;

  case 165: /* comOp: GE  */
#line 1046 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2874 "yacc_sql.tab.c"
    break;

  case 166: /* comOp: NE  */
#line 1047 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2880 "yacc_sql.tab.c"
    break;

  case 167: /* comOp: IS  */
#line 1048 "yacc_sql.y"
         {CONTEXT->comp = EQUAL_IS;}
#line 2886 "yacc_sql.tab.c"
    break;

  case 168: /* comOp: ISNOT  */
#line 1049 "yacc_sql.y"
           {CONTEXT->comp = EQUAL_IS_NOT;}
#line 2892 "yacc_sql.tab.c"
    break;

  case 169: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1054 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2901 "yacc_sql.tab.c"
    break;


#line 2905 "yacc_sql.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 1059 "yacc_sql.y"

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
