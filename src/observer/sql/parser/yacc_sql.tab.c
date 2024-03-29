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
  YYSYMBOL_count_attr = 101,               /* count_attr  */
  YYSYMBOL_select_attr = 102,              /* select_attr  */
  YYSYMBOL_attr_list = 103,                /* attr_list  */
  YYSYMBOL_rel_list = 104,                 /* rel_list  */
  YYSYMBOL_order = 105,                    /* order  */
  YYSYMBOL_order_list = 106,               /* order_list  */
  YYSYMBOL_orderby = 107,                  /* orderby  */
  YYSYMBOL_direction = 108,                /* direction  */
  YYSYMBOL_group = 109,                    /* group  */
  YYSYMBOL_groupby = 110,                  /* groupby  */
  YYSYMBOL_group_list = 111,               /* group_list  */
  YYSYMBOL_where = 112,                    /* where  */
  YYSYMBOL_condition_list = 113,           /* condition_list  */
  YYSYMBOL_condition = 114,                /* condition  */
  YYSYMBOL_subselect = 115,                /* subselect  */
  YYSYMBOL_subselect_attr = 116,           /* subselect_attr  */
  YYSYMBOL_subaggregate_attr = 117,        /* subaggregate_attr  */
  YYSYMBOL_subaggregate_list = 118,        /* subaggregate_list  */
  YYSYMBOL_subcount_attr = 119,            /* subcount_attr  */
  YYSYMBOL_subattr_list = 120,             /* subattr_list  */
  YYSYMBOL_subrel_list = 121,              /* subrel_list  */
  YYSYMBOL_comOp = 122,                    /* comOp  */
  YYSYMBOL_load_data = 123                 /* load_data  */
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
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  411

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
     382,   392,   402,   419,   421,   426,   431,   436,   443,   448,
     453,   458,   463,   469,   475,   481,   484,   490,   496,   504,
     506,   513,   520,   527,   533,   539,   545,   548,   554,   560,
     568,   570,   574,   576,   580,   582,   586,   588,   593,   601,
     604,   607,   611,   613,   617,   619,   624,   630,   632,   637,
     643,   645,   649,   651,   656,   677,   697,   717,   739,   760,
     781,   800,   808,   816,   824,   832,   840,   848,   859,   872,
     878,   884,   890,   896,   901,   908,   915,   922,   926,   933,
     940,   949,   951,   957,   963,   969,   972,   978,   984,   992,
     997,  1002,  1007,  1012,  1014,  1019,  1024,  1031,  1033,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1048
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
  "select", "join", "count_attr", "select_attr", "attr_list", "rel_list",
  "order", "order_list", "orderby", "direction", "group", "groupby",
  "group_list", "where", "condition_list", "condition", "subselect",
  "subselect_attr", "subaggregate_attr", "subaggregate_list",
  "subcount_attr", "subattr_list", "subrel_list", "comOp", "load_data", YY_NULLPTR
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

#define YYPACT_NINF (-338)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -338,   212,  -338,   237,   115,    13,   -40,    26,    57,    21,
      65,    29,    73,   133,   140,   154,   180,    74,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,   100,   132,   171,   134,
     148,   190,   205,   214,   219,   149,  -338,   209,   253,   254,
    -338,   193,   194,   211,  -338,  -338,  -338,  -338,  -338,   206,
     231,   213,   199,   263,   264,   203,   204,   167,   207,    17,
      25,  -338,   208,  -338,  -338,   225,   224,   210,   215,   216,
     218,   226,  -338,  -338,   -14,    20,  -338,  -338,  -338,   242,
      23,   246,   247,   248,   249,   151,   251,   251,   252,   255,
       7,   284,   232,   245,  -338,   257,    11,   260,   227,   251,
     228,   251,   229,   251,   251,   230,   233,   234,   167,   235,
      41,  -338,  -338,  -338,   236,   271,    97,  -338,   281,  -338,
    -338,  -338,   144,  -338,   150,   256,   150,  -338,    97,   290,
     216,   273,  -338,  -338,  -338,  -338,  -338,    33,   238,   275,
    -338,   276,  -338,   277,  -338,  -338,   278,    30,    48,   279,
      91,   251,   251,   252,   250,   224,   274,   121,  -338,  -338,
     258,   282,   282,  -338,  -338,  -338,  -338,  -338,  -338,    68,
      54,     7,  -338,   259,   224,   261,   257,   309,  -338,  -338,
     265,  -338,   283,   266,   251,   251,   251,   251,   267,   251,
     268,   251,   251,   269,  -338,  -338,  -338,   270,   291,    97,
     285,   287,   288,   294,   297,   155,  -338,   289,  -338,   116,
    -338,  -338,  -338,  -338,  -338,   286,  -338,   256,  -338,   318,
     319,  -338,  -338,  -338,   298,   272,   304,   283,  -338,  -338,
    -338,  -338,   306,  -338,   307,  -338,  -338,   308,     7,   280,
     317,   274,   310,   292,   293,   169,   295,   296,   125,  -338,
     299,   282,   282,    82,   300,  -338,  -338,  -338,    37,   283,
     339,   312,   251,   251,   251,   256,    36,   313,   301,   344,
    -338,   320,   345,   110,   119,  -338,   311,  -338,   321,   120,
     181,   316,   316,   322,  -338,  -338,   324,  -338,  -338,  -338,
    -338,  -338,  -338,   347,  -338,  -338,  -338,   271,  -338,  -338,
     303,  -338,   280,  -338,   182,  -338,  -338,    97,  -338,   323,
     305,   323,   314,   315,   323,   323,   325,   162,  -338,  -338,
    -338,   326,   224,   327,  -338,  -338,   222,   313,   328,   329,
    -338,   274,   200,  -338,   330,  -338,   331,  -338,  -338,  -338,
     337,   316,   316,   322,   317,  -338,  -338,  -338,   183,   338,
     340,   342,   343,   346,   350,   323,   323,   323,  -338,  -338,
    -338,   351,   332,  -338,  -338,   310,   333,   334,   169,   335,
    -338,  -338,  -338,  -338,   338,  -338,   123,   126,   352,   138,
    -338,   323,   336,   323,   341,   323,   323,   348,  -338,   353,
    -338,   354,  -338,  -338,   355,   323,   323,   323,  -338,  -338,
    -338
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
       0,     0,     0,     0,     0,    79,    68,     0,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,    29,    28,     0,   110,     0,     0,     0,
       0,     0,    27,    34,     0,     0,    67,    65,    66,     0,
       0,     0,     0,     0,     0,    79,    79,    79,    90,     0,
       0,     0,     0,     0,    49,    36,     0,     0,     0,    79,
       0,    79,     0,    79,    79,     0,     0,     0,     0,     0,
       0,    80,    71,    69,     0,    63,     0,    59,     0,    55,
      56,    58,     0,    57,     0,   112,     0,    60,     0,     0,
       0,     0,    48,    44,    45,    46,    47,    40,     0,     0,
      72,     0,    73,     0,    75,    74,     0,     0,     0,     0,
       0,    79,    79,    90,     0,   110,    53,     0,   165,   166,
       0,     0,     0,   159,   160,   161,   162,   163,   164,     0,
       0,     0,   111,     0,   110,     0,    36,     0,    42,    41,
       0,    39,    32,     0,    79,    79,    79,    79,     0,    79,
       0,    79,    79,     0,    81,    82,    91,     0,    92,     0,
       0,     0,     0,     0,     0,   153,   129,     0,   133,     0,
     124,   126,   116,   114,   121,   117,   115,   112,   122,     0,
       0,    37,    35,    43,     0,     0,     0,    32,    76,    77,
      78,    83,     0,    84,     0,    86,    85,     0,     0,    96,
     102,    53,    51,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,     0,     0,   113,    61,   167,    40,    32,
       0,     0,    79,    79,    79,   112,   101,    94,   104,     0,
      54,     0,     0,     0,     0,   152,   149,   151,     0,     0,
     153,   153,   153,   157,   125,   127,     0,   118,   123,   119,
      38,    33,    31,     0,    87,    88,    89,    63,   100,    99,
       0,    97,    96,    93,   107,   103,    62,     0,    50,   141,
       0,   141,     0,     0,   141,   141,     0,     0,   154,   132,
     130,     0,   110,     0,    30,    64,   101,    94,     0,     0,
     105,    53,     0,   134,     0,   135,     0,   150,   137,   136,
       0,   153,   153,   157,   102,   120,    98,    95,   107,   107,
       0,     0,     0,     0,     0,   141,   141,   141,   155,   156,
     158,     0,     0,   108,   106,    51,     0,     0,     0,     0,
     138,   139,   140,   128,   107,    52,     0,     0,     0,     0,
     109,   141,     0,   141,     0,   141,   141,     0,   142,     0,
     143,     0,   145,   144,     0,   141,   141,   141,   146,   147,
     148
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -213,  -338,  -338,   166,   262,   107,  -338,
    -338,  -338,  -338,   -16,  -243,  -126,  -338,  -338,  -338,    69,
     302,  -338,   -94,   240,  -338,    45,    66,    52,    35,  -338,
    -337,  -161,  -216,  -171,  -166,  -338,  -338,  -281,    18,  -264,
      42,  -127,  -338
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   236,    29,    30,   141,   105,   191,   234,
     147,   106,    31,   282,   210,   134,    32,    33,    34,   165,
      89,    47,    71,   125,   250,   313,   277,   311,   279,   315,
     340,   101,   182,   135,   136,   217,   218,   343,   288,   259,
     332,   179,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     166,   121,   122,   123,   208,   220,   221,   180,   280,   183,
     227,   265,   184,   224,   127,   150,   142,   152,   109,   154,
     155,   373,   374,   229,   271,    48,   328,   329,   330,   110,
      41,    42,    43,    44,    91,    92,    93,    94,   128,    49,
     345,   188,   189,   348,   349,   188,   189,   390,   143,   144,
     145,   146,   111,   223,   226,   114,   301,   308,   309,   307,
      50,   127,   197,   112,   190,    51,   115,   204,   205,   129,
     130,   131,   132,   198,   133,   127,    54,   275,    45,   310,
     199,    46,    95,   251,   380,   381,   382,   368,   369,   127,
      96,   200,   263,    97,    53,   294,   295,   298,   360,   128,
     238,   239,   240,   241,   127,   243,   161,   245,   246,   162,
     398,    52,   400,   128,   402,   403,   129,   130,   131,   225,
     168,   133,   169,   202,   408,   409,   410,    39,    59,    40,
     129,   130,   131,   222,   203,   133,    55,   297,   211,   212,
     213,   214,   319,    56,   129,   130,   131,   296,   168,   133,
     169,   321,   325,   320,   168,   391,   169,    57,   393,   129,
     130,   131,   322,   326,   133,    60,   392,   261,   262,   394,
     396,   354,   173,   174,   175,   176,   177,   178,   304,   305,
     306,   397,    69,    58,    69,    62,   215,   170,   257,   216,
     291,   341,    70,   292,   120,   171,   172,    61,   258,    63,
     173,   174,   175,   176,   177,   178,   173,   174,   175,   176,
     177,   178,     2,    64,   257,   338,   338,   361,   362,   363,
     364,    65,     3,     4,   327,   339,   372,   351,     5,    86,
     352,   285,    87,     6,   286,    88,    66,   287,     7,     8,
       9,    10,    11,   308,   309,    67,    12,    13,    14,    36,
      68,    37,    38,    15,    16,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    17,    82,    83,    84,    85,
      99,   100,    90,    98,   113,   102,   108,   116,   117,   118,
     119,   104,   103,   107,    69,   124,   126,   137,   138,   139,
     140,   148,   149,   151,   153,   156,   164,   167,   157,   158,
     160,   163,   185,   192,   181,   187,   193,   209,   194,   195,
     196,   201,   232,   128,   249,   207,   235,   252,   253,   254,
     248,   266,   267,   219,   228,   255,   230,   233,   256,   264,
     268,   237,   242,   244,   247,   260,   270,   269,   272,   273,
     274,   278,   302,   281,   303,   276,   312,   316,   318,   257,
     334,   317,   231,   324,   323,   331,   342,   283,   284,   385,
     289,   290,   365,   366,   293,   299,   314,   333,   336,   367,
     344,   338,   375,   376,   377,   300,   335,   378,   337,   346,
     347,   379,   357,   383,   395,   405,   406,   407,   356,   371,
     350,   353,   355,   358,   359,   370,   388,   384,   386,   387,
     389,   399,   186,   206,     0,     0,   401,     0,     0,     0,
       0,     0,     0,   404,     0,     0,     0,     0,     0,     0,
     159
};

static const yytype_int16 yycheck[] =
{
     126,    95,    96,    97,   165,   171,   172,   134,   251,   136,
     181,   227,   138,   179,     7,   109,     5,   111,    32,   113,
     114,   358,   359,   184,   237,    65,   290,   291,   292,    43,
      17,    18,    19,    20,    17,    18,    19,    20,    31,    13,
     321,     8,     9,   324,   325,     8,     9,   384,    37,    38,
      39,    40,    32,   179,   180,    32,   269,    21,    22,   275,
       3,     7,    32,    43,    31,    44,    43,   161,   162,    62,
      63,    64,    65,    43,    67,     7,     3,   248,    65,    43,
      32,    68,    65,   209,   365,   366,   367,   351,   352,     7,
      65,    43,   219,    68,    65,   261,   262,   263,   341,    31,
     194,   195,   196,   197,     7,   199,    65,   201,   202,    68,
     391,    46,   393,    31,   395,   396,    62,    63,    64,    65,
       4,    67,     6,    32,   405,   406,   407,    12,    54,    14,
      62,    63,    64,    65,    43,    67,     3,   263,    17,    18,
      19,    20,    32,     3,    62,    63,    64,    65,     4,    67,
       6,    32,    32,    43,     4,    32,     6,     3,    32,    62,
      63,    64,    43,    43,    67,    65,    43,    51,    52,    43,
      32,   332,    56,    57,    58,    59,    60,    61,   272,   273,
     274,    43,    33,     3,    33,    14,    65,    43,    33,    68,
      65,   317,    43,    68,    43,    51,    52,    65,    43,    65,
      56,    57,    58,    59,    60,    61,    56,    57,    58,    59,
      60,    61,     0,    65,    33,    33,    33,    17,    18,    19,
      20,    31,    10,    11,    43,    43,    43,    65,    16,    62,
      68,    62,    65,    21,    65,    68,    31,    68,    26,    27,
      28,    29,    30,    21,    22,    31,    34,    35,    36,    12,
      31,    14,    15,    41,    42,    46,     3,     3,    65,    65,
      49,    55,    31,    50,    65,    53,     3,     3,    65,    65,
      45,    47,    65,    65,    32,    65,    50,    31,    31,    31,
      31,    65,    67,    65,    33,    33,    31,     3,    56,    44,
      33,    31,    65,    65,    65,    65,    25,    16,    65,    65,
      65,    65,    12,    65,    48,    32,    31,    33,    32,    32,
      32,    32,     3,    31,    23,    65,    33,    32,    31,    31,
      50,     3,     3,    65,    65,    31,    65,    62,    31,    43,
      32,    65,    65,    65,    65,    46,    32,    65,    32,    32,
      32,    24,     3,    33,    32,    65,    33,     3,     3,    33,
       3,    31,   186,    32,    43,    33,    33,    65,    65,   375,
      65,    65,    32,    32,    65,    65,    65,    43,    65,    32,
      65,    33,    32,    31,    31,   268,   307,    31,   312,    65,
      65,    31,   337,    32,    32,    32,    32,    32,   336,   354,
      65,    65,    65,    65,    65,   353,   378,    65,    65,    65,
      65,    65,   140,   163,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
     118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,     0,    10,    11,    16,    21,    26,    27,    28,
      29,    30,    34,    35,    36,    41,    42,    53,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    85,
      86,    93,    97,    98,    99,   123,    12,    14,    15,    12,
      14,    17,    18,    19,    20,    65,    68,   102,    65,    13,
       3,    44,    46,    65,     3,     3,     3,     3,     3,    54,
      65,    65,    14,    65,    65,    31,    31,    31,    31,    33,
      43,   103,    46,     3,     3,    65,    65,    49,    55,    31,
      50,    65,     3,     3,    65,    65,    62,    65,    68,   101,
      65,    17,    18,    19,    20,    65,    65,    68,    65,    45,
      47,   112,    65,    67,    65,    88,    92,    65,    50,    32,
      43,    32,    43,    32,    32,    43,    31,    31,    31,    31,
      43,   103,   103,   103,    33,   104,    31,     7,    31,    62,
      63,    64,    65,    67,    96,   114,   115,     3,    56,    44,
      33,    87,     5,    37,    38,    39,    40,    91,    31,    65,
     103,    65,   103,    65,   103,   103,    65,    65,    65,   101,
      65,    65,    68,    65,    25,   100,    96,    16,     4,     6,
      43,    51,    52,    56,    57,    58,    59,    60,    61,   122,
     122,    48,   113,   122,    96,    12,    88,    32,     8,     9,
      31,    89,    65,    31,    32,    32,    32,    32,    43,    32,
      43,    32,    32,    43,   103,   103,   104,    65,   112,    33,
      95,    17,    18,    19,    20,    65,    68,   116,   117,    65,
     115,   115,    65,    96,   115,    65,    96,   114,    65,   112,
      65,    87,     3,    62,    90,    33,    84,    65,   103,   103,
     103,   103,    65,   103,    65,   103,   103,    65,    50,    23,
     105,    96,    32,    31,    31,    31,    31,    33,    43,   120,
      46,    51,    52,   122,    43,   113,     3,     3,    32,    65,
      32,    84,    32,    32,    32,   114,    65,   107,    24,   109,
      95,    33,    94,    65,    65,    62,    65,    68,   119,    65,
      65,    65,    68,    65,   115,   115,    65,    96,   115,    65,
      89,    84,     3,    32,   103,   103,   103,   113,    21,    22,
      43,   108,    33,   106,    65,   110,     3,    31,     3,    32,
      43,    32,    43,    43,    32,    32,    43,    43,   120,   120,
     120,    33,   121,    43,     3,   100,    65,   107,    33,    43,
     111,    96,    33,   118,    65,   118,    65,    65,   118,   118,
      65,    65,    68,    65,   112,    65,   108,   106,    65,    65,
      95,    17,    18,    19,    20,    32,    32,    32,   120,   120,
     121,   109,    43,   111,   111,    32,    31,    31,    31,    31,
     118,   118,   118,    32,    65,    94,    65,    65,   119,    65,
     111,    32,    43,    32,    43,    32,    32,    43,   118,    65,
     118,    65,   118,   118,    65,    32,    32,    32,   118,   118,
     118
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
      97,    98,    99,   100,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   123
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
       5,     8,    10,     0,     6,     1,     1,     1,     1,     4,
       2,     4,     5,     5,     5,     5,     7,     7,     7,     0,
       3,     5,     5,     6,     6,     6,     6,     8,     8,     8,
       0,     3,     0,     3,     0,     3,     0,     2,     4,     1,
       1,     0,     0,     2,     0,     2,     4,     0,     3,     5,
       0,     3,     0,     3,     3,     3,     3,     3,     5,     5,
       7,     3,     3,     5,     3,     5,     3,     5,     9,     1,
       4,     2,     4,     1,     5,     5,     5,     5,     7,     7,
       7,     0,     6,     6,     6,     6,     8,     8,     8,     1,
       3,     1,     1,     0,     3,     5,     5,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     8
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
#line 1543 "yacc_sql.tab.c"
    break;

  case 22: /* help: HELP SEMICOLON  */
#line 190 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1551 "yacc_sql.tab.c"
    break;

  case 23: /* sync: SYNC SEMICOLON  */
#line 195 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1559 "yacc_sql.tab.c"
    break;

  case 24: /* begin: TRX_BEGIN SEMICOLON  */
#line 201 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1567 "yacc_sql.tab.c"
    break;

  case 25: /* commit: TRX_COMMIT SEMICOLON  */
#line 207 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1575 "yacc_sql.tab.c"
    break;

  case 26: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 213 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1583 "yacc_sql.tab.c"
    break;

  case 27: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 219 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1592 "yacc_sql.tab.c"
    break;

  case 28: /* show_tables: SHOW TABLES SEMICOLON  */
#line 225 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1600 "yacc_sql.tab.c"
    break;

  case 29: /* desc_table: DESC ID SEMICOLON  */
#line 231 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1609 "yacc_sql.tab.c"
    break;

  case 30: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID index_list RBRACE SEMICOLON  */
#line 239 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
			add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
		}
#line 1619 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID index_list RBRACE SEMICOLON  */
#line 245 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
			add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-3].string));
		}
#line 1629 "yacc_sql.tab.c"
    break;

  case 33: /* index_list: COMMA ID index_list  */
#line 254 "yacc_sql.y"
                         {
  		add_index_attr(&CONTEXT->ssql->sstr.create_index, (yyvsp[-1].string));
	}
#line 1637 "yacc_sql.tab.c"
    break;

  case 34: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 261 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1646 "yacc_sql.tab.c"
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
#line 1658 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 278 "yacc_sql.y"
                                  {    }
#line 1664 "yacc_sql.tab.c"
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
#line 1679 "yacc_sql.tab.c"
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
#line 1694 "yacc_sql.tab.c"
    break;

  case 40: /* is_nullable: %empty  */
#line 306 "yacc_sql.y"
        {(yyval.number) = 0;}
#line 1700 "yacc_sql.tab.c"
    break;

  case 41: /* is_nullable: NOTNULL  */
#line 307 "yacc_sql.y"
                  {(yyval.number) = 0;}
#line 1706 "yacc_sql.tab.c"
    break;

  case 42: /* is_nullable: NULLABLE  */
#line 308 "yacc_sql.y"
                   {(yyval.number) = 1;}
#line 1712 "yacc_sql.tab.c"
    break;

  case 43: /* number: NUMBER  */
#line 311 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1718 "yacc_sql.tab.c"
    break;

  case 44: /* type: INT_T  */
#line 314 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1724 "yacc_sql.tab.c"
    break;

  case 45: /* type: STRING_T  */
#line 315 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1730 "yacc_sql.tab.c"
    break;

  case 46: /* type: FLOAT_T  */
#line 316 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1736 "yacc_sql.tab.c"
    break;

  case 47: /* type: DATE_T  */
#line 317 "yacc_sql.y"
                {(yyval.number)=DATES; }
#line 1742 "yacc_sql.tab.c"
    break;

  case 48: /* type: TEXT_T  */
#line 318 "yacc_sql.y"
                {(yyval.number)=TEXTS; }
#line 1748 "yacc_sql.tab.c"
    break;

  case 49: /* ID_get: ID  */
#line 322 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1757 "yacc_sql.tab.c"
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
#line 1777 "yacc_sql.tab.c"
    break;

  case 52: /* multi_values: COMMA LBRACE value value_list RBRACE multi_values  */
#line 349 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$3;
  		CONTEXT->insert_num++;
	  }
#line 1786 "yacc_sql.tab.c"
    break;

  case 54: /* value_list: COMMA value value_list  */
#line 357 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1794 "yacc_sql.tab.c"
    break;

  case 55: /* value: NUMBER  */
#line 362 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1802 "yacc_sql.tab.c"
    break;

  case 56: /* value: FLOAT  */
#line 365 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1810 "yacc_sql.tab.c"
    break;

  case 57: /* value: SSS  */
#line 368 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1819 "yacc_sql.tab.c"
    break;

  case 58: /* value: DATE  */
#line 372 "yacc_sql.y"
          {
    			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1828 "yacc_sql.tab.c"
    break;

  case 59: /* value: ANULL  */
#line 376 "yacc_sql.y"
          {
    		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1836 "yacc_sql.tab.c"
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
#line 1848 "yacc_sql.tab.c"
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
#line 1860 "yacc_sql.tab.c"
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
#line 1880 "yacc_sql.tab.c"
    break;

  case 64: /* join: INNERJOIN ID ON condition condition_list join  */
#line 421 "yacc_sql.y"
                                                   {
    	selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
    }
#line 1888 "yacc_sql.tab.c"
    break;

  case 65: /* count_attr: ID  */
#line 426 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1898 "yacc_sql.tab.c"
    break;

  case 66: /* count_attr: STAR  */
#line 431 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 1908 "yacc_sql.tab.c"
    break;

  case 67: /* count_attr: NUMBER  */
#line 436 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1918 "yacc_sql.tab.c"
    break;

  case 68: /* select_attr: STAR  */
#line 443 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1928 "yacc_sql.tab.c"
    break;

  case 69: /* select_attr: ID DOT STAR attr_list  */
#line 448 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1938 "yacc_sql.tab.c"
    break;

  case 70: /* select_attr: ID attr_list  */
#line 453 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1948 "yacc_sql.tab.c"
    break;

  case 71: /* select_attr: ID DOT ID attr_list  */
#line 458 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1958 "yacc_sql.tab.c"
    break;

  case 72: /* select_attr: MAX LBRACE ID RBRACE attr_list  */
#line 463 "yacc_sql.y"
                                      {
      			RelAttr attr;
      			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
          }
#line 1969 "yacc_sql.tab.c"
    break;

  case 73: /* select_attr: MIN LBRACE ID RBRACE attr_list  */
#line 469 "yacc_sql.y"
                                          {
          			RelAttr attr;
          			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
          			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
          }
#line 1980 "yacc_sql.tab.c"
    break;

  case 74: /* select_attr: AVG LBRACE ID RBRACE attr_list  */
#line 475 "yacc_sql.y"
                                          {
              		RelAttr attr;
              		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
              		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
          }
#line 1991 "yacc_sql.tab.c"
    break;

  case 75: /* select_attr: COUNT LBRACE count_attr RBRACE attr_list  */
#line 481 "yacc_sql.y"
                                                    {
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
          }
#line 1999 "yacc_sql.tab.c"
    break;

  case 76: /* select_attr: MAX LBRACE ID DOT ID RBRACE attr_list  */
#line 484 "yacc_sql.y"
                                                 {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
          }
#line 2010 "yacc_sql.tab.c"
    break;

  case 77: /* select_attr: MIN LBRACE ID DOT ID RBRACE attr_list  */
#line 490 "yacc_sql.y"
                                                 {
          			RelAttr attr;
          			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
          			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
          }
#line 2021 "yacc_sql.tab.c"
    break;

  case 78: /* select_attr: AVG LBRACE ID DOT ID RBRACE attr_list  */
#line 496 "yacc_sql.y"
                                                 {
              		RelAttr attr;
              		relation_attr_init(&attr,(yyvsp[-4].string), (yyvsp[-2].string));
              		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
          			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
          }
#line 2032 "yacc_sql.tab.c"
    break;

  case 80: /* attr_list: COMMA ID attr_list  */
#line 506 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2044 "yacc_sql.tab.c"
    break;

  case 81: /* attr_list: COMMA ID DOT ID attr_list  */
#line 513 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2056 "yacc_sql.tab.c"
    break;

  case 82: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 520 "yacc_sql.y"
                                  {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
    }
#line 2068 "yacc_sql.tab.c"
    break;

  case 83: /* attr_list: COMMA MAX LBRACE ID RBRACE attr_list  */
#line 527 "yacc_sql.y"
                                           {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 2079 "yacc_sql.tab.c"
    break;

  case 84: /* attr_list: COMMA MIN LBRACE ID RBRACE attr_list  */
#line 533 "yacc_sql.y"
                                           {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 2090 "yacc_sql.tab.c"
    break;

  case 85: /* attr_list: COMMA AVG LBRACE ID RBRACE attr_list  */
#line 539 "yacc_sql.y"
                                           {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 2101 "yacc_sql.tab.c"
    break;

  case 86: /* attr_list: COMMA COUNT LBRACE count_attr RBRACE attr_list  */
#line 545 "yacc_sql.y"
                                                     {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 2109 "yacc_sql.tab.c"
    break;

  case 87: /* attr_list: COMMA MAX LBRACE ID DOT ID RBRACE attr_list  */
#line 548 "yacc_sql.y"
                                                  {
            		RelAttr attr;
            		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 2120 "yacc_sql.tab.c"
    break;

  case 88: /* attr_list: COMMA MIN LBRACE ID DOT ID RBRACE attr_list  */
#line 554 "yacc_sql.y"
                                                  {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 2131 "yacc_sql.tab.c"
    break;

  case 89: /* attr_list: COMMA AVG LBRACE ID DOT ID RBRACE attr_list  */
#line 560 "yacc_sql.y"
                                                  {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 2142 "yacc_sql.tab.c"
    break;

  case 91: /* rel_list: COMMA ID rel_list  */
#line 570 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2150 "yacc_sql.tab.c"
    break;

  case 93: /* order: ORDERBY orderby order_list  */
#line 576 "yacc_sql.y"
                                 {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2158 "yacc_sql.tab.c"
    break;

  case 95: /* order_list: COMMA orderby order_list  */
#line 582 "yacc_sql.y"
                              {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2166 "yacc_sql.tab.c"
    break;

  case 97: /* orderby: ID direction  */
#line 588 "yacc_sql.y"
              {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,NULL,(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2176 "yacc_sql.tab.c"
    break;

  case 98: /* orderby: ID DOT ID direction  */
#line 593 "yacc_sql.y"
                                     {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,(yyvsp[-3].string),(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2186 "yacc_sql.tab.c"
    break;

  case 99: /* direction: ASC  */
#line 601 "yacc_sql.y"
        {
    		CONTEXT->orderDirect = ORASC;
    			}
#line 2194 "yacc_sql.tab.c"
    break;

  case 100: /* direction: DESC  */
#line 604 "yacc_sql.y"
           {
		CONTEXT->orderDirect = ORDESC;
			}
#line 2202 "yacc_sql.tab.c"
    break;

  case 101: /* direction: %empty  */
#line 607 "yacc_sql.y"
      {
    		CONTEXT->orderDirect = ORASC;
    }
#line 2210 "yacc_sql.tab.c"
    break;

  case 103: /* group: GROUPBY groupby  */
#line 613 "yacc_sql.y"
                      {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
}
#line 2218 "yacc_sql.tab.c"
    break;

  case 105: /* groupby: ID group_list  */
#line 619 "yacc_sql.y"
               {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2228 "yacc_sql.tab.c"
    break;

  case 106: /* groupby: ID DOT ID group_list  */
#line 624 "yacc_sql.y"
                      {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2238 "yacc_sql.tab.c"
    break;

  case 108: /* group_list: COMMA ID group_list  */
#line 632 "yacc_sql.y"
                     {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2248 "yacc_sql.tab.c"
    break;

  case 109: /* group_list: COMMA ID DOT ID group_list  */
#line 637 "yacc_sql.y"
                            {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2258 "yacc_sql.tab.c"
    break;

  case 111: /* where: WHERE condition condition_list  */
#line 645 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2266 "yacc_sql.tab.c"
    break;

  case 113: /* condition_list: AND condition condition_list  */
#line 651 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2274 "yacc_sql.tab.c"
    break;

  case 114: /* condition: ID comOp value  */
#line 657 "yacc_sql.y"
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
#line 2299 "yacc_sql.tab.c"
    break;

  case 115: /* condition: value comOp value  */
#line 678 "yacc_sql.y"
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
#line 2323 "yacc_sql.tab.c"
    break;

  case 116: /* condition: ID comOp ID  */
#line 698 "yacc_sql.y"
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
#line 2347 "yacc_sql.tab.c"
    break;

  case 117: /* condition: value comOp ID  */
#line 718 "yacc_sql.y"
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
#line 2373 "yacc_sql.tab.c"
    break;

  case 118: /* condition: ID DOT ID comOp value  */
#line 740 "yacc_sql.y"
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
#line 2398 "yacc_sql.tab.c"
    break;

  case 119: /* condition: value comOp ID DOT ID  */
#line 761 "yacc_sql.y"
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
#line 2423 "yacc_sql.tab.c"
    break;

  case 120: /* condition: ID DOT ID comOp ID DOT ID  */
#line 782 "yacc_sql.y"
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
#line 2446 "yacc_sql.tab.c"
    break;

  case 121: /* condition: ID comOp subselect  */
#line 800 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2459 "yacc_sql.tab.c"
    break;

  case 122: /* condition: subselect comOp ID  */
#line 808 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2472 "yacc_sql.tab.c"
    break;

  case 123: /* condition: ID DOT ID comOp subselect  */
#line 816 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2485 "yacc_sql.tab.c"
    break;

  case 124: /* condition: ID IN subselect  */
#line 824 "yacc_sql.y"
                      {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2498 "yacc_sql.tab.c"
    break;

  case 125: /* condition: ID DOT ID IN subselect  */
#line 832 "yacc_sql.y"
                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2511 "yacc_sql.tab.c"
    break;

  case 126: /* condition: ID NOTIN subselect  */
#line 840 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2524 "yacc_sql.tab.c"
    break;

  case 127: /* condition: ID DOT ID NOTIN subselect  */
#line 848 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2537 "yacc_sql.tab.c"
    break;

  case 128: /* subselect: LBRACE SELECT subselect_attr FROM ID subrel_list where group RBRACE  */
#line 860 "yacc_sql.y"
                {

			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-4].string));
			selects_append_conditions(CONTEXT->ssql->sstr.selection.subSelect, CONTEXT->conditions, CONTEXT->condition_length);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2552 "yacc_sql.tab.c"
    break;

  case 129: /* subselect_attr: STAR  */
#line 872 "yacc_sql.y"
         {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2563 "yacc_sql.tab.c"
    break;

  case 130: /* subselect_attr: ID DOT STAR subattr_list  */
#line 878 "yacc_sql.y"
                               {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2574 "yacc_sql.tab.c"
    break;

  case 131: /* subselect_attr: ID subattr_list  */
#line 884 "yacc_sql.y"
                      {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2585 "yacc_sql.tab.c"
    break;

  case 132: /* subselect_attr: ID DOT ID subattr_list  */
#line 890 "yacc_sql.y"
                                 {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
	}
#line 2596 "yacc_sql.tab.c"
    break;

  case 133: /* subselect_attr: subaggregate_attr  */
#line 896 "yacc_sql.y"
                        {
    }
#line 2603 "yacc_sql.tab.c"
    break;

  case 134: /* subaggregate_attr: MAX LBRACE ID RBRACE subaggregate_list  */
#line 901 "yacc_sql.y"
                                           {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2615 "yacc_sql.tab.c"
    break;

  case 135: /* subaggregate_attr: MIN LBRACE ID RBRACE subaggregate_list  */
#line 908 "yacc_sql.y"
                                             {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2627 "yacc_sql.tab.c"
    break;

  case 136: /* subaggregate_attr: AVG LBRACE ID RBRACE subaggregate_list  */
#line 915 "yacc_sql.y"
                                             {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2639 "yacc_sql.tab.c"
    break;

  case 137: /* subaggregate_attr: COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 922 "yacc_sql.y"
                                                          {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2648 "yacc_sql.tab.c"
    break;

  case 138: /* subaggregate_attr: MAX LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 926 "yacc_sql.y"
                                                    {
          sub_selects_init(&CONTEXT->ssql->sstr.selection);
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
          			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
          }
#line 2660 "yacc_sql.tab.c"
    break;

  case 139: /* subaggregate_attr: MIN LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 933 "yacc_sql.y"
                                                    {
	  sub_selects_init(&CONTEXT->ssql->sstr.selection);
				RelAttr attr;
				relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
				selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
				selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
	  }
#line 2672 "yacc_sql.tab.c"
    break;

  case 140: /* subaggregate_attr: AVG LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 940 "yacc_sql.y"
                                                    {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
				selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
	}
#line 2684 "yacc_sql.tab.c"
    break;

  case 142: /* subaggregate_list: COMMA MAX LBRACE ID RBRACE subaggregate_list  */
#line 951 "yacc_sql.y"
                                                   {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2695 "yacc_sql.tab.c"
    break;

  case 143: /* subaggregate_list: COMMA MIN LBRACE ID RBRACE subaggregate_list  */
#line 957 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2706 "yacc_sql.tab.c"
    break;

  case 144: /* subaggregate_list: COMMA AVG LBRACE ID RBRACE subaggregate_list  */
#line 963 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2717 "yacc_sql.tab.c"
    break;

  case 145: /* subaggregate_list: COMMA COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 969 "yacc_sql.y"
                                                                {
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2725 "yacc_sql.tab.c"
    break;

  case 146: /* subaggregate_list: COMMA MAX LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 972 "yacc_sql.y"
                                                          {
            		RelAttr attr;
            		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2736 "yacc_sql.tab.c"
    break;

  case 147: /* subaggregate_list: COMMA MIN LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 978 "yacc_sql.y"
                                                          {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2747 "yacc_sql.tab.c"
    break;

  case 148: /* subaggregate_list: COMMA AVG LBRACE ID DOT ID RBRACE subaggregate_list  */
#line 984 "yacc_sql.y"
                                                          {
                	RelAttr attr;
                	relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2758 "yacc_sql.tab.c"
    break;

  case 149: /* subcount_attr: ID  */
#line 992 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2768 "yacc_sql.tab.c"
    break;

  case 150: /* subcount_attr: ID DOT ID  */
#line 997 "yacc_sql.y"
               {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2778 "yacc_sql.tab.c"
    break;

  case 151: /* subcount_attr: STAR  */
#line 1002 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
        }
#line 2788 "yacc_sql.tab.c"
    break;

  case 152: /* subcount_attr: NUMBER  */
#line 1007 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2798 "yacc_sql.tab.c"
    break;

  case 154: /* subattr_list: COMMA ID subattr_list  */
#line 1014 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
      }
#line 2808 "yacc_sql.tab.c"
    break;

  case 155: /* subattr_list: COMMA ID DOT ID subattr_list  */
#line 1019 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
  	  }
#line 2818 "yacc_sql.tab.c"
    break;

  case 156: /* subattr_list: COMMA ID DOT STAR subattr_list  */
#line 1024 "yacc_sql.y"
                                     {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2828 "yacc_sql.tab.c"
    break;

  case 158: /* subrel_list: COMMA ID subrel_list  */
#line 1033 "yacc_sql.y"
                           {
			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-1].string));
}
#line 2836 "yacc_sql.tab.c"
    break;

  case 159: /* comOp: EQ  */
#line 1037 "yacc_sql.y"
         { CONTEXT->comp = EQUAL_TO; }
#line 2842 "yacc_sql.tab.c"
    break;

  case 160: /* comOp: LT  */
#line 1038 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2848 "yacc_sql.tab.c"
    break;

  case 161: /* comOp: GT  */
#line 1039 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2854 "yacc_sql.tab.c"
    break;

  case 162: /* comOp: LE  */
#line 1040 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2860 "yacc_sql.tab.c"
    break;

  case 163: /* comOp: GE  */
#line 1041 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2866 "yacc_sql.tab.c"
    break;

  case 164: /* comOp: NE  */
#line 1042 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2872 "yacc_sql.tab.c"
    break;

  case 165: /* comOp: IS  */
#line 1043 "yacc_sql.y"
         {CONTEXT->comp = EQUAL_IS;}
#line 2878 "yacc_sql.tab.c"
    break;

  case 166: /* comOp: ISNOT  */
#line 1044 "yacc_sql.y"
           {CONTEXT->comp = EQUAL_IS_NOT;}
#line 2884 "yacc_sql.tab.c"
    break;

  case 167: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1049 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2893 "yacc_sql.tab.c"
    break;


#line 2897 "yacc_sql.tab.c"

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

#line 1054 "yacc_sql.y"

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
