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
  YYSYMBOL_ISNOT = 5,                      /* ISNOT  */
  YYSYMBOL_ANULL = 6,                      /* ANULL  */
  YYSYMBOL_NULLABLE = 7,                   /* NULLABLE  */
  YYSYMBOL_NOTNULL = 8,                    /* NOTNULL  */
  YYSYMBOL_CREATE = 9,                     /* CREATE  */
  YYSYMBOL_DROP = 10,                      /* DROP  */
  YYSYMBOL_TABLE = 11,                     /* TABLE  */
  YYSYMBOL_TABLES = 12,                    /* TABLES  */
  YYSYMBOL_INDEX = 13,                     /* INDEX  */
  YYSYMBOL_UNIQUE = 14,                    /* UNIQUE  */
  YYSYMBOL_SELECT = 15,                    /* SELECT  */
  YYSYMBOL_MAX = 16,                       /* MAX  */
  YYSYMBOL_MIN = 17,                       /* MIN  */
  YYSYMBOL_COUNT = 18,                     /* COUNT  */
  YYSYMBOL_AVG = 19,                       /* AVG  */
  YYSYMBOL_DESC = 20,                      /* DESC  */
  YYSYMBOL_ASC = 21,                       /* ASC  */
  YYSYMBOL_ORDERBY = 22,                   /* ORDERBY  */
  YYSYMBOL_GROUPBY = 23,                   /* GROUPBY  */
  YYSYMBOL_SHOW = 24,                      /* SHOW  */
  YYSYMBOL_SYNC = 25,                      /* SYNC  */
  YYSYMBOL_INSERT = 26,                    /* INSERT  */
  YYSYMBOL_DELETE = 27,                    /* DELETE  */
  YYSYMBOL_UPDATE = 28,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 32,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 33,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 34,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 35,                     /* INT_T  */
  YYSYMBOL_STRING_T = 36,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 37,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 38,                    /* DATE_T  */
  YYSYMBOL_HELP = 39,                      /* HELP  */
  YYSYMBOL_EXIT = 40,                      /* EXIT  */
  YYSYMBOL_DOT = 41,                       /* DOT  */
  YYSYMBOL_INTO = 42,                      /* INTO  */
  YYSYMBOL_VALUES = 43,                    /* VALUES  */
  YYSYMBOL_FROM = 44,                      /* FROM  */
  YYSYMBOL_WHERE = 45,                     /* WHERE  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_SET = 47,                       /* SET  */
  YYSYMBOL_ON = 48,                        /* ON  */
  YYSYMBOL_IN = 49,                        /* IN  */
  YYSYMBOL_NOTIN = 50,                     /* NOTIN  */
  YYSYMBOL_LOAD = 51,                      /* LOAD  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_INFILE = 53,                    /* INFILE  */
  YYSYMBOL_EQ = 54,                        /* EQ  */
  YYSYMBOL_LT = 55,                        /* LT  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_LE = 57,                        /* LE  */
  YYSYMBOL_GE = 58,                        /* GE  */
  YYSYMBOL_NE = 59,                        /* NE  */
  YYSYMBOL_NUMBER = 60,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 61,                     /* FLOAT  */
  YYSYMBOL_DATE = 62,                      /* DATE  */
  YYSYMBOL_ID = 63,                        /* ID  */
  YYSYMBOL_PATH = 64,                      /* PATH  */
  YYSYMBOL_SSS = 65,                       /* SSS  */
  YYSYMBOL_STAR = 66,                      /* STAR  */
  YYSYMBOL_STRING_V = 67,                  /* STRING_V  */
  YYSYMBOL_AGGOP = 68,                     /* AGGOP  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_commands = 70,                  /* commands  */
  YYSYMBOL_command = 71,                   /* command  */
  YYSYMBOL_exit = 72,                      /* exit  */
  YYSYMBOL_help = 73,                      /* help  */
  YYSYMBOL_sync = 74,                      /* sync  */
  YYSYMBOL_begin = 75,                     /* begin  */
  YYSYMBOL_commit = 76,                    /* commit  */
  YYSYMBOL_rollback = 77,                  /* rollback  */
  YYSYMBOL_drop_table = 78,                /* drop_table  */
  YYSYMBOL_show_tables = 79,               /* show_tables  */
  YYSYMBOL_desc_table = 80,                /* desc_table  */
  YYSYMBOL_create_index = 81,              /* create_index  */
  YYSYMBOL_drop_index = 82,                /* drop_index  */
  YYSYMBOL_create_table = 83,              /* create_table  */
  YYSYMBOL_attr_def_list = 84,             /* attr_def_list  */
  YYSYMBOL_attr_def = 85,                  /* attr_def  */
  YYSYMBOL_is_nullable = 86,               /* is_nullable  */
  YYSYMBOL_number = 87,                    /* number  */
  YYSYMBOL_type = 88,                      /* type  */
  YYSYMBOL_ID_get = 89,                    /* ID_get  */
  YYSYMBOL_insert = 90,                    /* insert  */
  YYSYMBOL_multi_values = 91,              /* multi_values  */
  YYSYMBOL_value_list = 92,                /* value_list  */
  YYSYMBOL_value = 93,                     /* value  */
  YYSYMBOL_delete = 94,                    /* delete  */
  YYSYMBOL_update = 95,                    /* update  */
  YYSYMBOL_select = 96,                    /* select  */
  YYSYMBOL_aggregate_attr = 97,            /* aggregate_attr  */
  YYSYMBOL_aggregate_list = 98,            /* aggregate_list  */
  YYSYMBOL_count_attr = 99,                /* count_attr  */
  YYSYMBOL_select_attr = 100,              /* select_attr  */
  YYSYMBOL_attr_list = 101,                /* attr_list  */
  YYSYMBOL_rel_list = 102,                 /* rel_list  */
  YYSYMBOL_order = 103,                    /* order  */
  YYSYMBOL_order_list = 104,               /* order_list  */
  YYSYMBOL_orderby = 105,                  /* orderby  */
  YYSYMBOL_direction = 106,                /* direction  */
  YYSYMBOL_group = 107,                    /* group  */
  YYSYMBOL_groupby = 108,                  /* groupby  */
  YYSYMBOL_group_list = 109,               /* group_list  */
  YYSYMBOL_where = 110,                    /* where  */
  YYSYMBOL_condition_list = 111,           /* condition_list  */
  YYSYMBOL_condition = 112,                /* condition  */
  YYSYMBOL_subselect = 113,                /* subselect  */
  YYSYMBOL_subselect_attr = 114,           /* subselect_attr  */
  YYSYMBOL_subaggregate_attr = 115,        /* subaggregate_attr  */
  YYSYMBOL_subaggregate_list = 116,        /* subaggregate_list  */
  YYSYMBOL_subcount_attr = 117,            /* subcount_attr  */
  YYSYMBOL_subattr_list = 118,             /* subattr_list  */
  YYSYMBOL_subrel_list = 119,              /* subrel_list  */
  YYSYMBOL_comOp = 120,                    /* comOp  */
  YYSYMBOL_load_data = 121                 /* load_data  */
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
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  347

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   157,   157,   159,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   183,   188,   193,   199,   205,   211,   217,   223,   229,
     236,   241,   249,   256,   265,   267,   271,   282,   295,   296,
     297,   300,   303,   304,   305,   306,   309,   318,   335,   337,
     343,   345,   350,   353,   356,   360,   364,   370,   380,   390,
     408,   414,   420,   426,   431,   433,   439,   445,   451,   456,
     461,   466,   473,   478,   483,   488,   493,   496,   498,   505,
     512,   521,   523,   527,   529,   533,   535,   539,   541,   546,
     554,   557,   560,   564,   566,   570,   572,   577,   583,   585,
     590,   596,   598,   602,   604,   609,   630,   650,   670,   692,
     713,   734,   753,   761,   769,   777,   785,   793,   804,   817,
     823,   829,   835,   841,   846,   853,   860,   867,   873,   875,
     881,   887,   893,   898,   903,   908,   913,   915,   920,   925,
     932,   934,   938,   939,   940,   941,   942,   943,   944,   945,
     949
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
  "ISNOT", "ANULL", "NULLABLE", "NOTNULL", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "UNIQUE", "SELECT", "MAX", "MIN", "COUNT", "AVG",
  "DESC", "ASC", "ORDERBY", "GROUPBY", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "HELP", "EXIT",
  "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET", "ON", "IN",
  "NOTIN", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE",
  "NUMBER", "FLOAT", "DATE", "ID", "PATH", "SSS", "STAR", "STRING_V",
  "AGGOP", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "create_table", "attr_def_list",
  "attr_def", "is_nullable", "number", "type", "ID_get", "insert",
  "multi_values", "value_list", "value", "delete", "update", "select",
  "aggregate_attr", "aggregate_list", "count_attr", "select_attr",
  "attr_list", "rel_list", "order", "order_list", "orderby", "direction",
  "group", "groupby", "group_list", "where", "condition_list", "condition",
  "subselect", "subselect_attr", "subaggregate_attr", "subaggregate_list",
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
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
#endif

#define YYPACT_NINF (-267)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -267,   137,  -267,   145,    57,   123,   -35,    23,    53,    43,
      28,    34,    88,    99,   116,   117,   118,    84,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,    92,    97,   141,   103,
     104,   139,   146,   167,   177,   -21,  -267,  -267,   130,   204,
     205,  -267,   147,   148,   165,  -267,  -267,  -267,  -267,  -267,
     156,   184,   166,   152,   213,   214,   155,   157,   -26,   158,
     159,    44,  -267,   160,  -267,  -267,   176,   179,   163,   164,
     168,   169,   185,  -267,  -267,   197,   200,  -267,  -267,  -267,
     206,   207,   -20,   203,   203,   208,   209,    27,   232,   187,
     198,  -267,   211,    90,   215,   180,   216,   216,   216,   216,
      72,  -267,  -267,  -267,   183,   179,    39,  -267,  -267,  -267,
    -267,     3,  -267,    75,   199,  -267,    39,   237,   168,   219,
    -267,  -267,  -267,  -267,    17,   188,   221,   182,  -267,  -267,
    -267,  -267,   203,   203,   208,   230,   222,  -267,  -267,   191,
     226,   226,  -267,  -267,  -267,  -267,  -267,  -267,    13,    33,
      27,  -267,   179,   193,   211,   254,  -267,  -267,   201,  -267,
     228,   196,   231,   233,   234,   235,  -267,  -267,  -267,   202,
     243,    39,   238,    59,   252,  -267,  -267,  -267,  -267,  -267,
     229,  -267,   199,   266,   268,  -267,  -267,  -267,   242,   270,
     244,   212,   217,   -26,   218,    -3,   245,   220,   274,   222,
     247,   226,   226,    21,   162,   223,  -267,  -267,  -267,    98,
    -267,   276,   255,   257,   258,   259,  -267,  -267,   227,  -267,
     202,  -267,   -18,  -267,  -267,  -267,   253,   281,  -267,  -267,
     250,  -267,  -267,   263,   264,   265,   267,    -9,  -267,   251,
    -267,  -267,  -267,  -267,   216,   216,   216,   216,    91,   245,
     236,   239,  -267,    39,  -267,   240,   241,   246,   131,   248,
     249,   124,  -267,   256,  -267,  -267,  -267,  -267,  -267,  -267,
      -5,   269,   222,  -267,   271,   275,  -267,  -267,  -267,   277,
     278,    10,   279,   279,   282,   260,  -267,  -267,   284,   285,
     285,   285,   285,   129,  -267,  -267,  -267,   261,   179,   269,
     247,   186,  -267,  -267,  -267,  -267,   279,   279,   282,   243,
    -267,  -267,   286,   288,   289,   291,  -267,  -267,  -267,   292,
     262,   272,   131,   273,  -267,   296,   297,   298,   299,   285,
     285,   285,   285,  -267,  -267,  -267,  -267
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
       0,     0,     0,     0,     0,    77,    72,    76,     0,     0,
       0,    23,     0,     0,     0,    24,    25,    26,    22,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,    29,    28,     0,   101,     0,     0,
       0,     0,     0,    27,    32,     0,     0,    71,    69,    70,
       0,     0,    77,    77,    77,    81,     0,     0,     0,     0,
       0,    46,    34,     0,     0,     0,    64,    64,    64,    64,
       0,    78,    75,    73,     0,   101,     0,    56,    52,    53,
      55,     0,    54,     0,   103,    57,     0,     0,     0,     0,
      42,    43,    44,    45,    38,     0,     0,     0,    60,    61,
      63,    62,    77,    77,    81,    83,    50,   148,   149,     0,
       0,     0,   142,   143,   144,   145,   146,   147,     0,     0,
       0,   102,   101,     0,    34,     0,    40,    39,     0,    37,
       0,     0,     0,     0,     0,     0,    79,    80,    82,    87,
      93,     0,     0,     0,     0,   114,   116,   107,   105,   112,
     108,   106,   103,     0,     0,    35,    33,    41,     0,     0,
       0,     0,     0,     0,     0,    92,    85,    95,     0,    50,
      48,     0,     0,     0,     0,     0,   104,    58,   150,    38,
      31,     0,     0,     0,     0,     0,    91,    90,     0,    88,
      87,    84,    98,    94,    59,    51,     0,     0,   115,   117,
       0,   109,   113,     0,     0,     0,     0,   136,   119,     0,
     123,   110,    36,    30,    64,    64,    64,    64,    92,    85,
       0,     0,    96,     0,    47,     0,     0,     0,     0,     0,
       0,     0,   121,     0,    65,    66,    68,    67,    89,    86,
      98,    98,    50,   111,     0,     0,   135,   133,   134,     0,
       0,   136,   136,   136,   140,     0,    99,    97,     0,   128,
     128,   128,   128,     0,   137,   122,   120,     0,   101,    98,
      48,     0,   124,   125,   127,   126,   136,   136,   140,    93,
     100,    49,     0,     0,     0,     0,   138,   139,   141,     0,
       0,     0,     0,     0,   118,     0,     0,     0,     0,   128,
     128,   128,   128,   129,   130,   132,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,   133,   170,    87,  -267,  -267,
    -267,  -267,    11,  -205,  -110,  -267,  -267,  -267,  -267,  -106,
     127,  -267,    30,   189,  -267,    73,   101,    76,    18,  -267,
    -266,  -115,   149,   178,  -146,  -267,  -267,  -157,     7,  -262,
      22,  -114,  -267
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   129,   102,   169,   198,   134,
     103,    31,   237,   182,   123,    32,    33,    34,    47,   138,
      90,    48,    72,   115,   180,   231,   206,   229,   208,   233,
     262,    98,   161,   124,   185,   249,   250,   312,   289,   272,
     308,   158,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   139,   140,   141,   235,   186,   146,   147,   148,   159,
      70,    70,   189,   260,   296,   297,   162,   226,   227,   117,
      71,   110,   270,   261,   166,   167,   260,   117,    49,   304,
     305,   306,   271,   117,    87,    50,   295,    88,   228,   117,
      89,   270,   184,   320,   149,   117,   168,   193,   188,   191,
     184,   303,   150,   151,   326,   327,    51,   152,   153,   154,
     155,   156,   157,   147,   148,   238,   239,   242,    39,   213,
      40,   209,    53,   118,   119,   120,   187,   298,   122,   147,
     148,   118,   119,   120,   240,    52,   122,   118,   119,   120,
     121,    55,   122,   118,   119,   120,   190,    54,   122,   118,
     119,   120,    56,   241,   122,   166,   167,    93,   211,   212,
      94,   226,   227,   152,   153,   154,   155,   156,   157,    57,
      58,    59,   111,   112,   113,   130,   131,   132,   133,   152,
     153,   154,   155,   156,   157,   142,    60,     2,   143,    41,
      42,    43,    44,   313,   314,   315,     3,     4,   274,   275,
     276,   277,     5,   282,    63,    61,    36,     6,    37,    38,
      62,     7,     8,     9,    10,    11,    64,    65,    66,    12,
      13,    14,   176,   177,    73,    67,    15,    16,   243,   244,
     245,   246,   343,   344,   345,   346,    45,   292,    17,    46,
     293,   286,   316,   319,   287,   317,    68,   288,   172,   173,
     174,   175,   322,   323,   324,   325,    69,    74,    75,    79,
      76,    77,    78,    80,    81,    82,    83,    84,    85,    96,
      86,    91,    92,    95,    97,   247,    99,   106,   248,   100,
     107,   101,   104,   105,    70,   125,   108,   109,   116,   114,
     127,   126,   128,   136,   135,   160,   144,   137,   163,   165,
     171,   170,   179,   181,   183,   184,   194,   196,   199,   200,
     201,   197,   202,   203,   204,   205,   207,   214,   210,   217,
     215,   218,   219,   220,   221,   222,   230,   234,   236,   253,
     223,   225,   263,   232,   264,   254,   251,   255,   256,   257,
     258,   265,   266,   267,   268,   273,   269,   195,   164,   280,
     260,   299,   281,   283,   284,   300,   252,   301,   302,   285,
     270,   290,   291,   307,   310,   330,   311,   331,   332,   294,
     333,   321,   334,   309,   318,   335,   339,   340,   341,   342,
     224,   259,   279,   178,   278,   336,   338,   329,   192,   337,
     328,   216
};

static const yytype_int16 yycheck[] =
{
     115,   107,   108,   109,   209,   151,   116,     4,     5,   123,
      31,    31,   158,    31,   280,   281,   126,    20,    21,     6,
      41,    41,    31,    41,     7,     8,    31,     6,    63,   291,
     292,   293,    41,     6,    60,    12,    41,    63,    41,     6,
      66,    31,    29,   309,    41,     6,    29,   162,   158,   159,
      29,    41,    49,    50,   316,   317,     3,    54,    55,    56,
      57,    58,    59,     4,     5,   211,   212,   213,    11,   183,
      13,   181,    44,    60,    61,    62,    63,   282,    65,     4,
       5,    60,    61,    62,    63,    42,    65,    60,    61,    62,
      63,     3,    65,    60,    61,    62,    63,    63,    65,    60,
      61,    62,     3,   213,    65,     7,     8,    63,    49,    50,
      66,    20,    21,    54,    55,    56,    57,    58,    59,     3,
       3,     3,    92,    93,    94,    35,    36,    37,    38,    54,
      55,    56,    57,    58,    59,    63,    52,     0,    66,    16,
      17,    18,    19,   300,   301,   302,     9,    10,   254,   255,
     256,   257,    15,   263,    13,    63,    11,    20,    13,    14,
      63,    24,    25,    26,    27,    28,    63,    63,    29,    32,
      33,    34,   142,   143,    44,    29,    39,    40,    16,    17,
      18,    19,   339,   340,   341,   342,    63,    63,    51,    66,
      66,    60,    63,   308,    63,    66,    29,    66,    16,    17,
      18,    19,    16,    17,    18,    19,    29,     3,     3,    53,
      63,    63,    47,    29,    48,    63,     3,     3,    63,    43,
      63,    63,    63,    63,    45,    63,    63,    30,    66,    65,
      30,    63,    63,    48,    31,     3,    30,    30,    29,    31,
      42,    54,    31,    63,    29,    46,    63,    31,    11,    30,
      29,    63,    22,    31,    63,    29,    63,     3,    30,    63,
      29,    60,    29,    29,    29,    63,    23,    15,    30,     3,
      41,     3,    30,     3,    30,    63,    31,     3,    31,     3,
      63,    63,    29,    63,     3,    30,    63,    30,    30,    30,
      63,    41,    29,    29,    29,    44,    29,   164,   128,    63,
      31,    30,    63,    63,    63,    30,   219,    30,    30,    63,
      31,    63,    63,    31,    30,    29,    31,    29,    29,    63,
      29,   310,    30,    63,    63,    63,    30,    30,    30,    30,
     203,   230,   259,   144,   258,    63,    63,   319,   160,   332,
     318,   192
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,     0,     9,    10,    15,    20,    24,    25,    26,
      27,    28,    32,    33,    34,    39,    40,    51,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    90,    94,    95,    96,   121,    11,    13,    14,    11,
      13,    16,    17,    18,    19,    63,    66,    97,   100,    63,
      12,     3,    42,    44,    63,     3,     3,     3,     3,     3,
      52,    63,    63,    13,    63,    63,    29,    29,    29,    29,
      31,    41,   101,    44,     3,     3,    63,    63,    47,    53,
      29,    48,    63,     3,     3,    63,    63,    60,    63,    66,
      99,    63,    63,    63,    66,    63,    43,    45,   110,    63,
      65,    63,    85,    89,    63,    48,    30,    30,    30,    30,
      41,   101,   101,   101,    31,   102,    29,     6,    60,    61,
      62,    63,    65,    93,   112,     3,    54,    42,    31,    84,
      35,    36,    37,    38,    88,    29,    63,    31,    98,    98,
      98,    98,    63,    66,    63,   110,    93,     4,     5,    41,
      49,    50,    54,    55,    56,    57,    58,    59,   120,   120,
      46,   111,    93,    11,    85,    30,     7,     8,    29,    86,
      63,    29,    16,    17,    18,    19,   101,   101,   102,    22,
     103,    31,    92,    63,    29,   113,   113,    63,    93,   113,
      63,    93,   112,   110,    63,    84,     3,    60,    87,    30,
      63,    29,    29,    29,    29,    63,   105,    23,   107,    93,
      30,    49,    50,   120,    15,    41,   111,     3,     3,    30,
       3,    30,    63,    63,    99,    63,    20,    21,    41,   106,
      31,   104,    63,   108,     3,    92,    31,    91,   113,   113,
      63,    93,   113,    16,    17,    18,    19,    63,    66,   114,
     115,    63,    86,     3,    30,    30,    30,    30,    63,   105,
      31,    41,   109,    29,     3,    41,    29,    29,    29,    29,
      31,    41,   118,    44,    98,    98,    98,    98,   106,   104,
      63,    63,    93,    63,    63,    63,    60,    63,    66,   117,
      63,    63,    63,    66,    63,    41,   109,   109,    92,    30,
      30,    30,    30,    41,   118,   118,   118,    31,   119,    63,
      30,    31,   116,   116,   116,   116,    63,    66,    63,   110,
     109,    91,    16,    17,    18,    19,   118,   118,   119,   107,
      29,    29,    29,    29,    30,    63,    63,   117,    63,    30,
      30,    30,    30,   116,   116,   116,   116
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    81,    82,    83,    84,    84,    85,    85,    86,    86,
      86,    87,    88,    88,    88,    88,    89,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    93,    94,    95,    96,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   105,
     106,   106,   106,   107,   107,   108,   108,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   114,
     114,   114,   114,   114,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   117,   117,   117,   118,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
      10,     9,     4,     8,     0,     3,     6,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,    10,     0,     6,
       0,     3,     1,     1,     1,     1,     1,     5,     8,     9,
       5,     5,     5,     5,     0,     6,     6,     6,     6,     1,
       1,     1,     1,     4,     2,     4,     1,     0,     3,     5,
       5,     0,     3,     0,     3,     0,     3,     0,     2,     4,
       1,     1,     0,     0,     2,     0,     2,     4,     0,     3,
       5,     0,     3,     0,     3,     3,     3,     3,     3,     5,
       5,     7,     3,     5,     3,     5,     3,     5,     9,     1,
       4,     2,     4,     1,     5,     5,     5,     5,     0,     6,
       6,     6,     6,     1,     1,     1,     0,     3,     5,     5,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       8
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
#line 183 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1500 "yacc_sql.tab.c"
    break;

  case 22: /* help: HELP SEMICOLON  */
#line 188 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1508 "yacc_sql.tab.c"
    break;

  case 23: /* sync: SYNC SEMICOLON  */
#line 193 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1516 "yacc_sql.tab.c"
    break;

  case 24: /* begin: TRX_BEGIN SEMICOLON  */
#line 199 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1524 "yacc_sql.tab.c"
    break;

  case 25: /* commit: TRX_COMMIT SEMICOLON  */
#line 205 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1532 "yacc_sql.tab.c"
    break;

  case 26: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 211 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1540 "yacc_sql.tab.c"
    break;

  case 27: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 217 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1549 "yacc_sql.tab.c"
    break;

  case 28: /* show_tables: SHOW TABLES SEMICOLON  */
#line 223 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1557 "yacc_sql.tab.c"
    break;

  case 29: /* desc_table: DESC ID SEMICOLON  */
#line 229 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1566 "yacc_sql.tab.c"
    break;

  case 30: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 237 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 1);
		}
#line 1575 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 242 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1584 "yacc_sql.tab.c"
    break;

  case 32: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 250 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1593 "yacc_sql.tab.c"
    break;

  case 33: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 257 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1605 "yacc_sql.tab.c"
    break;

  case 35: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 267 "yacc_sql.y"
                                  {    }
#line 1611 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def: ID_get type LBRACE number RBRACE is_nullable  */
#line 272 "yacc_sql.y"
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
#line 1626 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type is_nullable  */
#line 283 "yacc_sql.y"
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
#line 1641 "yacc_sql.tab.c"
    break;

  case 38: /* is_nullable: %empty  */
#line 295 "yacc_sql.y"
        {(yyval.number) = 0;}
#line 1647 "yacc_sql.tab.c"
    break;

  case 39: /* is_nullable: NOTNULL  */
#line 296 "yacc_sql.y"
                  {(yyval.number) = 0;}
#line 1653 "yacc_sql.tab.c"
    break;

  case 40: /* is_nullable: NULLABLE  */
#line 297 "yacc_sql.y"
                   {(yyval.number) = 1;}
#line 1659 "yacc_sql.tab.c"
    break;

  case 41: /* number: NUMBER  */
#line 300 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1665 "yacc_sql.tab.c"
    break;

  case 42: /* type: INT_T  */
#line 303 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1671 "yacc_sql.tab.c"
    break;

  case 43: /* type: STRING_T  */
#line 304 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1677 "yacc_sql.tab.c"
    break;

  case 44: /* type: FLOAT_T  */
#line 305 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1683 "yacc_sql.tab.c"
    break;

  case 45: /* type: DATE_T  */
#line 306 "yacc_sql.y"
                {(yyval.number)=DATES; }
#line 1689 "yacc_sql.tab.c"
    break;

  case 46: /* ID_get: ID  */
#line 310 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1698 "yacc_sql.tab.c"
    break;

  case 47: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE multi_values SEMICOLON  */
#line 319 "yacc_sql.y"
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
#line 1718 "yacc_sql.tab.c"
    break;

  case 49: /* multi_values: COMMA LBRACE value value_list RBRACE multi_values  */
#line 337 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$3;
  		CONTEXT->insert_num++;
	  }
#line 1727 "yacc_sql.tab.c"
    break;

  case 51: /* value_list: COMMA value value_list  */
#line 345 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1735 "yacc_sql.tab.c"
    break;

  case 52: /* value: NUMBER  */
#line 350 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1743 "yacc_sql.tab.c"
    break;

  case 53: /* value: FLOAT  */
#line 353 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1751 "yacc_sql.tab.c"
    break;

  case 54: /* value: SSS  */
#line 356 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1760 "yacc_sql.tab.c"
    break;

  case 55: /* value: DATE  */
#line 360 "yacc_sql.y"
          {
    			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
    }
#line 1769 "yacc_sql.tab.c"
    break;

  case 56: /* value: ANULL  */
#line 364 "yacc_sql.y"
          {
    		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1777 "yacc_sql.tab.c"
    break;

  case 57: /* delete: DELETE FROM ID where SEMICOLON  */
#line 371 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1789 "yacc_sql.tab.c"
    break;

  case 58: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 381 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1801 "yacc_sql.tab.c"
    break;

  case 59: /* select: SELECT select_attr FROM ID rel_list where order group SEMICOLON  */
#line 391 "yacc_sql.y"
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
#line 1821 "yacc_sql.tab.c"
    break;

  case 60: /* aggregate_attr: MAX LBRACE ID RBRACE aggregate_list  */
#line 408 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1832 "yacc_sql.tab.c"
    break;

  case 61: /* aggregate_attr: MIN LBRACE ID RBRACE aggregate_list  */
#line 414 "yacc_sql.y"
                                          {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1843 "yacc_sql.tab.c"
    break;

  case 62: /* aggregate_attr: AVG LBRACE ID RBRACE aggregate_list  */
#line 420 "yacc_sql.y"
                                          {
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1854 "yacc_sql.tab.c"
    break;

  case 63: /* aggregate_attr: COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 426 "yacc_sql.y"
                                                    {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1862 "yacc_sql.tab.c"
    break;

  case 65: /* aggregate_list: COMMA MAX LBRACE ID RBRACE aggregate_list  */
#line 433 "yacc_sql.y"
                                                {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 1);
    }
#line 1873 "yacc_sql.tab.c"
    break;

  case 66: /* aggregate_list: COMMA MIN LBRACE ID RBRACE aggregate_list  */
#line 439 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 2);
    }
#line 1884 "yacc_sql.tab.c"
    break;

  case 67: /* aggregate_list: COMMA AVG LBRACE ID RBRACE aggregate_list  */
#line 445 "yacc_sql.y"
                                                {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 3);
    }
#line 1895 "yacc_sql.tab.c"
    break;

  case 68: /* aggregate_list: COMMA COUNT LBRACE count_attr RBRACE aggregate_list  */
#line 451 "yacc_sql.y"
                                                          {
    			selects_append_aggregation_op(&CONTEXT->ssql->sstr.selection, 4);
    }
#line 1903 "yacc_sql.tab.c"
    break;

  case 69: /* count_attr: ID  */
#line 456 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1913 "yacc_sql.tab.c"
    break;

  case 70: /* count_attr: STAR  */
#line 461 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        }
#line 1923 "yacc_sql.tab.c"
    break;

  case 71: /* count_attr: NUMBER  */
#line 466 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1933 "yacc_sql.tab.c"
    break;

  case 72: /* select_attr: STAR  */
#line 473 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1943 "yacc_sql.tab.c"
    break;

  case 73: /* select_attr: ID DOT STAR attr_list  */
#line 478 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 1953 "yacc_sql.tab.c"
    break;

  case 74: /* select_attr: ID attr_list  */
#line 483 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1963 "yacc_sql.tab.c"
    break;

  case 75: /* select_attr: ID DOT ID attr_list  */
#line 488 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1973 "yacc_sql.tab.c"
    break;

  case 76: /* select_attr: aggregate_attr  */
#line 493 "yacc_sql.y"
                     {
    }
#line 1980 "yacc_sql.tab.c"
    break;

  case 78: /* attr_list: COMMA ID attr_list  */
#line 498 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 1992 "yacc_sql.tab.c"
    break;

  case 79: /* attr_list: COMMA ID DOT ID attr_list  */
#line 505 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2004 "yacc_sql.tab.c"
    break;

  case 80: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 512 "yacc_sql.y"
                                  {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
              // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
    }
#line 2016 "yacc_sql.tab.c"
    break;

  case 82: /* rel_list: COMMA ID rel_list  */
#line 523 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2024 "yacc_sql.tab.c"
    break;

  case 84: /* order: ORDERBY orderby order_list  */
#line 529 "yacc_sql.y"
                                 {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2032 "yacc_sql.tab.c"
    break;

  case 86: /* order_list: COMMA orderby order_list  */
#line 535 "yacc_sql.y"
                              {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2040 "yacc_sql.tab.c"
    break;

  case 88: /* orderby: ID direction  */
#line 541 "yacc_sql.y"
              {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,NULL,(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2050 "yacc_sql.tab.c"
    break;

  case 89: /* orderby: ID DOT ID direction  */
#line 546 "yacc_sql.y"
                                     {
			OrderOp orderOp;
			order_init(&orderOp,CONTEXT->orderDirect,(yyvsp[-3].string),(yyvsp[-1].string));
			CONTEXT->orderOps[CONTEXT->order_num++]=orderOp;
		}
#line 2060 "yacc_sql.tab.c"
    break;

  case 90: /* direction: ASC  */
#line 554 "yacc_sql.y"
        {
    		CONTEXT->orderDirect = ORASC;
    			}
#line 2068 "yacc_sql.tab.c"
    break;

  case 91: /* direction: DESC  */
#line 557 "yacc_sql.y"
           {
		CONTEXT->orderDirect = ORDESC;
			}
#line 2076 "yacc_sql.tab.c"
    break;

  case 92: /* direction: %empty  */
#line 560 "yacc_sql.y"
      {
    		CONTEXT->orderDirect = ORASC;
    }
#line 2084 "yacc_sql.tab.c"
    break;

  case 94: /* group: GROUPBY groupby  */
#line 566 "yacc_sql.y"
                      {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
}
#line 2092 "yacc_sql.tab.c"
    break;

  case 96: /* groupby: ID group_list  */
#line 572 "yacc_sql.y"
               {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2102 "yacc_sql.tab.c"
    break;

  case 97: /* groupby: ID DOT ID group_list  */
#line 577 "yacc_sql.y"
                      {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2112 "yacc_sql.tab.c"
    break;

  case 99: /* group_list: COMMA ID group_list  */
#line 585 "yacc_sql.y"
                     {
	RelAttr attr;
	relation_attr_init(&attr, NULL, (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2122 "yacc_sql.tab.c"
    break;

  case 100: /* group_list: COMMA ID DOT ID group_list  */
#line 590 "yacc_sql.y"
                            {
	RelAttr attr;
	relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
	selects_append_groupBy_attribute(&CONTEXT->ssql->sstr.selection, &attr);
}
#line 2132 "yacc_sql.tab.c"
    break;

  case 102: /* where: WHERE condition condition_list  */
#line 598 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2140 "yacc_sql.tab.c"
    break;

  case 104: /* condition_list: AND condition condition_list  */
#line 604 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2148 "yacc_sql.tab.c"
    break;

  case 105: /* condition: ID comOp value  */
#line 610 "yacc_sql.y"
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
#line 2173 "yacc_sql.tab.c"
    break;

  case 106: /* condition: value comOp value  */
#line 631 "yacc_sql.y"
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
#line 2197 "yacc_sql.tab.c"
    break;

  case 107: /* condition: ID comOp ID  */
#line 651 "yacc_sql.y"
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
#line 2221 "yacc_sql.tab.c"
    break;

  case 108: /* condition: value comOp ID  */
#line 671 "yacc_sql.y"
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
#line 2247 "yacc_sql.tab.c"
    break;

  case 109: /* condition: ID DOT ID comOp value  */
#line 693 "yacc_sql.y"
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
#line 2272 "yacc_sql.tab.c"
    break;

  case 110: /* condition: value comOp ID DOT ID  */
#line 714 "yacc_sql.y"
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
#line 2297 "yacc_sql.tab.c"
    break;

  case 111: /* condition: ID DOT ID comOp ID DOT ID  */
#line 735 "yacc_sql.y"
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
#line 2320 "yacc_sql.tab.c"
    break;

  case 112: /* condition: ID comOp subselect  */
#line 753 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2333 "yacc_sql.tab.c"
    break;

  case 113: /* condition: ID DOT ID comOp subselect  */
#line 761 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2346 "yacc_sql.tab.c"
    break;

  case 114: /* condition: ID IN subselect  */
#line 769 "yacc_sql.y"
                      {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2359 "yacc_sql.tab.c"
    break;

  case 115: /* condition: ID DOT ID IN subselect  */
#line 777 "yacc_sql.y"
                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, EQUAL_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2372 "yacc_sql.tab.c"
    break;

  case 116: /* condition: ID NOTIN subselect  */
#line 785 "yacc_sql.y"
                         {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2385 "yacc_sql.tab.c"
    break;

  case 117: /* condition: ID DOT ID NOTIN subselect  */
#line 793 "yacc_sql.y"
                                {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
		Condition condition;
		condition_init2(&condition, NOT_IN, 1, &left_attr, NULL, 0, NULL, NULL,1);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		// sub_selects_init(&CONTEXT->ssql->sstr.selection);
    }
#line 2398 "yacc_sql.tab.c"
    break;

  case 118: /* subselect: LBRACE SELECT subselect_attr FROM ID subrel_list where group RBRACE  */
#line 805 "yacc_sql.y"
                {

			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-4].string));
			selects_append_conditions(CONTEXT->ssql->sstr.selection.subSelect, CONTEXT->conditions, CONTEXT->condition_length);
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2413 "yacc_sql.tab.c"
    break;

  case 119: /* subselect_attr: STAR  */
#line 817 "yacc_sql.y"
         {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2424 "yacc_sql.tab.c"
    break;

  case 120: /* subselect_attr: ID DOT STAR subattr_list  */
#line 823 "yacc_sql.y"
                               {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2435 "yacc_sql.tab.c"
    break;

  case 121: /* subselect_attr: ID subattr_list  */
#line 829 "yacc_sql.y"
                      {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
		}
#line 2446 "yacc_sql.tab.c"
    break;

  case 122: /* subselect_attr: ID DOT ID subattr_list  */
#line 835 "yacc_sql.y"
                                 {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
	}
#line 2457 "yacc_sql.tab.c"
    break;

  case 123: /* subselect_attr: subaggregate_attr  */
#line 841 "yacc_sql.y"
                        {
    }
#line 2464 "yacc_sql.tab.c"
    break;

  case 124: /* subaggregate_attr: MAX LBRACE ID RBRACE subaggregate_list  */
#line 846 "yacc_sql.y"
                                           {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2476 "yacc_sql.tab.c"
    break;

  case 125: /* subaggregate_attr: MIN LBRACE ID RBRACE subaggregate_list  */
#line 853 "yacc_sql.y"
                                             {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2488 "yacc_sql.tab.c"
    break;

  case 126: /* subaggregate_attr: AVG LBRACE ID RBRACE subaggregate_list  */
#line 860 "yacc_sql.y"
                                             {
	sub_selects_init(&CONTEXT->ssql->sstr.selection);
        		RelAttr attr;
        		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
        		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2500 "yacc_sql.tab.c"
    break;

  case 127: /* subaggregate_attr: COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 867 "yacc_sql.y"
                                                          {
    sub_selects_init(&CONTEXT->ssql->sstr.selection);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2509 "yacc_sql.tab.c"
    break;

  case 129: /* subaggregate_list: COMMA MAX LBRACE ID RBRACE subaggregate_list  */
#line 875 "yacc_sql.y"
                                                   {
            		RelAttr attr;
            		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
            		selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 1);
    }
#line 2520 "yacc_sql.tab.c"
    break;

  case 130: /* subaggregate_list: COMMA MIN LBRACE ID RBRACE subaggregate_list  */
#line 881 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 2);
    }
#line 2531 "yacc_sql.tab.c"
    break;

  case 131: /* subaggregate_list: COMMA AVG LBRACE ID RBRACE subaggregate_list  */
#line 887 "yacc_sql.y"
                                                   {
                	RelAttr attr;
                	relation_attr_init(&attr, NULL, (yyvsp[-2].string));
                	selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 3);
    }
#line 2542 "yacc_sql.tab.c"
    break;

  case 132: /* subaggregate_list: COMMA COUNT LBRACE subcount_attr RBRACE subaggregate_list  */
#line 893 "yacc_sql.y"
                                                                {
    			selects_append_aggregation_op(CONTEXT->ssql->sstr.selection.subSelect, 4);
    }
#line 2550 "yacc_sql.tab.c"
    break;

  case 133: /* subcount_attr: ID  */
#line 898 "yacc_sql.y"
       {
    	            	RelAttr attr;
                        relation_attr_init(&attr, NULL, (yyvsp[0].string));
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2560 "yacc_sql.tab.c"
    break;

  case 134: /* subcount_attr: STAR  */
#line 903 "yacc_sql.y"
           {
        	        RelAttr attr;
                        relation_attr_init(&attr, NULL, "*");
                        selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
        }
#line 2570 "yacc_sql.tab.c"
    break;

  case 135: /* subcount_attr: NUMBER  */
#line 908 "yacc_sql.y"
             {
    			RelAttr attr;
    			relation_attr_init(&attr, NULL, "*");
    			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2580 "yacc_sql.tab.c"
    break;

  case 137: /* subattr_list: COMMA ID subattr_list  */
#line 915 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
      }
#line 2590 "yacc_sql.tab.c"
    break;

  case 138: /* subattr_list: COMMA ID DOT ID subattr_list  */
#line 920 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
  	  }
#line 2600 "yacc_sql.tab.c"
    break;

  case 139: /* subattr_list: COMMA ID DOT STAR subattr_list  */
#line 925 "yacc_sql.y"
                                     {
      			RelAttr attr;
      			relation_attr_init(&attr, (yyvsp[-3].string), "*");
      			selects_append_attribute(CONTEXT->ssql->sstr.selection.subSelect, &attr);
    }
#line 2610 "yacc_sql.tab.c"
    break;

  case 141: /* subrel_list: COMMA ID subrel_list  */
#line 934 "yacc_sql.y"
                           {
			selects_append_relation(CONTEXT->ssql->sstr.selection.subSelect, (yyvsp[-1].string));
}
#line 2618 "yacc_sql.tab.c"
    break;

  case 142: /* comOp: EQ  */
#line 938 "yacc_sql.y"
         { CONTEXT->comp = EQUAL_TO; }
#line 2624 "yacc_sql.tab.c"
    break;

  case 143: /* comOp: LT  */
#line 939 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2630 "yacc_sql.tab.c"
    break;

  case 144: /* comOp: GT  */
#line 940 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2636 "yacc_sql.tab.c"
    break;

  case 145: /* comOp: LE  */
#line 941 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2642 "yacc_sql.tab.c"
    break;

  case 146: /* comOp: GE  */
#line 942 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2648 "yacc_sql.tab.c"
    break;

  case 147: /* comOp: NE  */
#line 943 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2654 "yacc_sql.tab.c"
    break;

  case 148: /* comOp: IS  */
#line 944 "yacc_sql.y"
         {CONTEXT->comp = EQUAL_IS;}
#line 2660 "yacc_sql.tab.c"
    break;

  case 149: /* comOp: ISNOT  */
#line 945 "yacc_sql.y"
           {CONTEXT->comp = EQUAL_IS_NOT;}
#line 2666 "yacc_sql.tab.c"
    break;

  case 150: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 950 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2675 "yacc_sql.tab.c"
    break;


#line 2679 "yacc_sql.tab.c"

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

#line 955 "yacc_sql.y"

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
